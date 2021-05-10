/*
 * Scheduler.cpp
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#include "SchedulerApp.h"

#include <time.h>
#include <string.h>
#include "Core/MutexLocker.hpp"
#include "nvs_flash.h"
#include "nvs.h"

#define STORAGE_NAMESPACE "SCHEDULER_DATA"
#define KEY_MANUAL_SETPOINT "KEY_MANUAL"
#define KEY_DEICING "KEY_DEICING"
#define KEY_WEEKLY "KEY_WEEKLY"
#define KEY_DAILY "KEY_DAILY"
#define KEY_MODE "KEY_MODE"

static uint8_t setpointBlobBfr[1024];
static const size_t setpointSize = sizeof(SchedulerApp::scheduler_setpoint_t);

enum {
	secInMin = 60,
	minInHour = 60,
	hourInDay = 24,
	minDaySecond = 0,
	maxDaySecond = hourInDay*minInHour*secInMin //24h*60m*60s
};

enum {
	dailyRowLen = 11,
	queueLen = 5
};

SchedulerApp::SchedulerApp(){
	create("SchedulerApp", 0, 1);
	mMode = ModeUnknown;
	mSetpoint = SetpointUnknown;

	static uint8_t queueModeStorageArea[queueLen * sizeof(char)];
	static Queue modeQueue = Queue(queueModeStorageArea, queueLen, sizeof(char));
	mModeQueue = &modeQueue;

	static uint8_t dailyQueueStorageArea[queueLen * setpointSize];
    static Queue dailyQueue = Queue(dailyQueueStorageArea, queueLen, setpointSize);
    mDailyQueue = &dailyQueue;

    static uint8_t weeklyQueueStorageArea[queueLen * setpointSize];
    static Queue weeklyQueue = Queue(weeklyQueueStorageArea, queueLen, setpointSize);
    mWeeklyQueue = &weeklyQueue;

    static uint8_t queueSetpointStorageArea[queueLen * sizeof(int16_t)];
    static Queue setpointQueue = Queue(queueSetpointStorageArea, queueLen, sizeof(int16_t));
    mSetpointQueue = &setpointQueue;
};

void SchedulerApp::run() {
	setenv("TZ", "CST-8", 1);
	tzset();

//	nvs_flash_erase();

	while (1) {
		handleModeQueue();
		handleDailyQueue();
		handleWeeklyQueue();
		handleManualSetpointQueue();
		updateSetpoint();

		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void SchedulerApp::handleModeQueue() {
	char mode;
	while (mModeQueue->receive(&mode, 0)){
		setModeUnsafe((scheduler_mode_t)mode);
	}
}

void SchedulerApp::handleDailyQueue() {
	scheduler_setpoint_t value;
	while (mDailyQueue->receive(&value, 0)){
		addSetpointToFileUnsafe(KEY_DAILY, value);
	}
}

void SchedulerApp::handleWeeklyQueue() {
	scheduler_setpoint_t value;
	while (mWeeklyQueue->receive(&value, 0)){
		addSetpointToFileUnsafe(getWeeklyKey(value.day), value);
	}
}

void SchedulerApp::handleManualSetpointQueue() {
	int16_t value;
	while (mSetpointQueue->receive(&value, 0)){
		setManualSetpointUnsafe(value);
	}
}

void SchedulerApp::setMode(scheduler_mode_t mode) {
	mModeQueue->send((char*)&mode);
}

void SchedulerApp::setManualSetpoint(int16_t value) {
	mSetpointQueue->send(&value);

	static bool isSchedulerInited = false;
	if (!isSchedulerInited) {
	   for (uint8_t cnt = 0; cnt < 24; cnt++){
	      scheduler_setpoint_t setpoint;
	      setpoint.hour  = cnt;
	      setpoint.min   = cnt;
	      setpoint.value = cnt*10;
	      addDailySetpoint(&setpoint);
	   }
	   isSchedulerInited = true;
	}
}

void SchedulerApp::setModeUnsafe(scheduler_mode_t mode) {
	if (mMode != mode) {
		nvs_handle_t handle;
		nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handle);
		nvs_set_u32(handle, KEY_MODE, mode);
		nvs_commit(handle);
		nvs_close(handle);
		mMode = mode;
	}
}

void SchedulerApp::setManualSetpointUnsafe(int16_t value) {
	if (mSetpoint != value) {
		nvs_handle_t handle;
		nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handle);
		nvs_set_i16(handle, KEY_MANUAL_SETPOINT, value);
		nvs_commit(handle);
		nvs_close(handle);
		mSetpoint = value;
	}
}

int16_t SchedulerApp::getManualSetpointFromFile() {
	mMtx.lock();
	nvs_handle_t handle;
	int16_t result = 0;
	nvs_open(STORAGE_NAMESPACE, NVS_READONLY, &handle);
	nvs_get_i16(handle, KEY_MANUAL_SETPOINT, &result);
	nvs_close(handle);
	mMtx.unlock();
	return result;
}

SchedulerApp::scheduler_mode_t SchedulerApp::getMode() {
	if (mMode == scheduler_mode_t::ModeUnknown) {
		mMode = getModeFromFile();
	}
	return mMode;
}

SchedulerApp::scheduler_mode_t SchedulerApp::getModeFromFile() {
	mMtx.lock();
	nvs_handle_t handle;
	scheduler_mode_t result = ModeManual;
	nvs_open(STORAGE_NAMESPACE, NVS_READONLY, &handle);
	nvs_get_u32(handle, KEY_MODE, (uint32_t*) &result);
	nvs_close(handle);
	mMtx.unlock();
	return result;
}

void SchedulerApp::addDailySetpoint(scheduler_setpoint_t* value) {
	mDailyQueue->send(value);
}

void SchedulerApp::addWeeklySetpoint(scheduler_setpoint_t* value) {
	mWeeklyQueue->send(value);
}

void SchedulerApp::addSetpointToFileUnsafe(const char* key, scheduler_setpoint_t value) {
	mMtx.lock();
	size_t size = 0;
	nvs_handle_t handle;

	nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handle);
	nvs_get_blob(handle, key, NULL, &size);
    printf("Original file size: %d\n", size);

    int pos = 0;
    bool isReplaseExistRow = false;
    if (size != 0) {
    	nvs_get_blob(handle, key, setpointBlobBfr, &size);
    	while (pos < size) {
    		if (memcmp(&setpointBlobBfr[pos], &value, 6) == 0) {
    			printf("Found, pos: %d \n", pos);
    			isReplaseExistRow = true;
    			break;
    		}
    		pos = pos + setpointSize;
    	};
    	if (pos + setpointSize >= sizeof(setpointBlobBfr)) {
    		printf("Scheduler file is too big \n");
    		pos = 0;
    	}
    }

    memcpy(&setpointBlobBfr[pos], &value, setpointSize);
    size = isReplaseExistRow ? size : size + setpointSize;
    nvs_set_blob(handle, key, setpointBlobBfr, size);
    nvs_commit(handle);
    nvs_close(handle);
    mMtx.unlock();
}

void SchedulerApp::setDeicingSetpoint(int16_t value){
	mMtx.lock();
	nvs_handle_t handle;
	nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handle);
	nvs_set_u16(handle, KEY_DEICING, value);
	nvs_commit(handle);
	nvs_close(handle);
	mMtx.unlock();
}

int16_t SchedulerApp::getDeicingSetpointFromFile(){
	mMtx.lock();
	nvs_handle_t handle;
	uint16_t result = 0;
	nvs_open(STORAGE_NAMESPACE, NVS_READONLY, &handle);
	nvs_get_u16(handle, KEY_DEICING, &result);
	nvs_close(handle);
	mMtx.unlock();
	return result;
}

int16_t SchedulerApp::getSetpointFromFileUnsafe(const char* key, uint8_t hour, uint8_t min) {
	size_t size = 0;
	int16_t result = SetpointUnknown;
	nvs_handle_t handle;

	memset(setpointBlobBfr, 0, sizeof(setpointBlobBfr));
	nvs_open(STORAGE_NAMESPACE, NVS_READONLY, &handle);
	nvs_get_blob(handle, key, NULL, &size);

	if (size > 0) {
		int pos = 0;
		bool found = false;
		scheduler_setpoint_t valueFrom, valueTo;
		uint32_t seconsInput = (hour+1)*minInHour*secInMin + (min+1)*secInMin;
		nvs_get_blob(handle, key, setpointBlobBfr, &size);
		while (pos <= size-setpointSize) {
			memcpy(&valueFrom, &setpointBlobBfr[pos], setpointSize);
			memcpy(&valueTo, &setpointBlobBfr[pos+setpointSize], setpointSize);
			uint32_t seconsFrom = (valueFrom.hour+1)*minInHour*secInMin + (valueFrom.min+1)*secInMin;
			uint32_t seconsTo =   (valueTo.hour  +1)*minInHour*secInMin + (valueTo.min  +1)*secInMin;

			if ((seconsInput >= seconsFrom) && (seconsInput < seconsTo)){
				result = valueFrom.value;
				found = true;
				break;
			}
			pos = pos + setpointSize;
		};

		//Find between last point<->midnight and midnight<->first point
		if (!found) {
			memcpy(&valueFrom, &setpointBlobBfr[0], setpointSize);
			memcpy(&valueTo, &setpointBlobBfr[size-setpointSize], setpointSize);
			uint32_t seconsFirst = (valueFrom.hour+1)*minInHour*secInMin + (valueFrom.min+1)*secInMin;
			uint32_t seconsLast =  (valueTo.hour  +1)*minInHour*secInMin + (valueTo.min  +1)*secInMin;
			bool isFromMidnightToFirstPoint = seconsInput < seconsFirst;
			bool isFromLastPointToMidnight = (seconsInput >= seconsLast) && (seconsInput < (hourInDay+1)*minInHour*secInMin);
			if (isFromMidnightToFirstPoint || isFromLastPointToMidnight){
				result = valueTo.value;
			}
		}
	}
    nvs_close(handle);
	return result;
}

void SchedulerApp::updateSetpoint() {
	time_t now;
	time(&now);
	struct tm timeinfo;
	localtime_r(&now, &timeinfo);

//	char strftime_buf[64];
//	strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
//	printf("%s\n", strftime_buf);

	scheduler_mode_t mode = getMode();
	switch (mode) {
	case SchedulerApp::ModeOff:
		mSetpoint = 0;
		break;
	case SchedulerApp::ModeDaily:
		mSetpoint = getSetpointFromFileUnsafe(KEY_DAILY, timeinfo.tm_hour, timeinfo.tm_min);
		break;
	case SchedulerApp::ModeWeekly:
		mSetpoint = getSetpointFromFileUnsafe(getWeeklyKey(timeinfo.tm_wday), timeinfo.tm_hour, timeinfo.tm_min);
		break;
	case SchedulerApp::ModeDeicing:
		mSetpoint = getDeicingSetpointFromFile();
		break;
	case SchedulerApp::ModeManual:
		mSetpoint = getManualSetpointFromFile();
		break;
	default:
		break;
	}
}

char* SchedulerApp::getWeeklyKey(uint8_t day) {
	static char key[19];
	sprintf(key, "%s%d\n", KEY_WEEKLY, day);
	return key;
}
