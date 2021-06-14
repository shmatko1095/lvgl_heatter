/*
 * Scheduler.cpp
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#include "SchedulerApp.h"
#include "Connection/MqttEventController.h"

#include <time.h>
#include <string.h>
#include "nvs_flash.h"
#include "nvs.h"

#define STORAGE_NAMESPACE "SCHEDULER_DATA"
#define KEY_MANUAL_SETPOINT "KEY_MANUAL"
#define KEY_DEICING "KEY_DEICING"
#define KEY_MODE "KEY_MODE"

enum {
	secInMin = 60,
	minInHour = 60,
	hourInDay = 24,
	minDaySecond = 0,
	maxDaySecond = hourInDay*minInHour*secInMin //24h*60m*60s
};

enum {
	dailyRowLen = 11,
	queueLen = 10
};

static uint8_t setpointBlobBfr[1024];
static const size_t setpointSize = sizeof(SchedulerApp::scheduler_setpoint_t);

MqttEventReceiver::MqttTopicDesc SchedulerApp::mModeDesc("/ModeIn", "/ModeOut", 0);
MqttEventReceiver::MqttTopicDesc SchedulerApp::mSetpointDesc("/SetpointIn", "/SetpointOut", 0);
MqttEventReceiver::MqttTopicDesc SchedulerApp::mDeicingSetpointDesc("/DeiceStpIn", "/DeiceStpOut", 0);

static uint8_t queueModeStorageArea[queueLen * sizeof(char)];
static uint8_t dailyQueueStorageArea[queueLen * setpointSize];
static uint8_t weeklyQueueStorageArea[queueLen * setpointSize];
static uint8_t manualQueueStorageArea[queueLen * sizeof(int16_t)];
static uint8_t deicingQueueStorageArea[queueLen * sizeof(int16_t)];

static Queue modeQueue = Queue(queueModeStorageArea, queueLen, sizeof(char));
static Queue dailyQueue = Queue(dailyQueueStorageArea, queueLen, setpointSize);
static Queue weeklyQueue = Queue(weeklyQueueStorageArea, queueLen, setpointSize);
static Queue manualQueue = Queue(manualQueueStorageArea, queueLen, sizeof(int16_t));
static Queue deicingQueue = Queue(deicingQueueStorageArea, queueLen, sizeof(int16_t));

SchedulerApp::SchedulerApp() {
	create("SchedulerApp", 0, 1);
	addTopic(mModeDesc);
	addTopic(mSetpointDesc);
	MqttEventController::registerReceiver(*this);

	mManualSetpoint = SetpointUnknown;
	mDeicingSetpoint = SetpointUnknown;

	mMode = ModeUnknown;
	mSetpoint = {-1, -1, -1, -1};
	mModifiedSetpoint = {-1, -1, -1, -1};

	mModeQueue = &modeQueue;
    mDailyQueue = &dailyQueue;
    mWeeklyQueue = &weeklyQueue;
    mManualQueue = &manualQueue;
    mDeicingQueue = &deicingQueue;
};

void SchedulerApp::run() {
	setenv("TZ", "CST-8", 1);
	tzset();

	while (1) {
		handleDailyQueue();
		handleWeeklyQueue();
		handleModeQueue();
		handleManualQueue();
		handleDeicingQueue();

		updateSetpoint();

		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void SchedulerApp::onReceive(char* topic, size_t topicLen, char* data, size_t dataLen) {
	if (memcmp(topic, mModeDesc.getTopicIn(), topicLen) == 0) {
		mqttModeHandler(data, dataLen);
	} else if (memcmp(topic, mSetpointDesc.getTopicIn(), topicLen) == 0){
		mqttSetpointHandler(data, dataLen);
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

void SchedulerApp::setManualSetpointToFile(int16_t value) {
	if (mManualSetpoint != value || mManualSetpoint == SetpointUnknown) {
		nvs_handle_t handle;
		nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handle);
		nvs_set_i16(handle, KEY_MANUAL_SETPOINT, value);
		nvs_commit(handle);
		nvs_close(handle);
		mManualSetpoint = value;
	}
}

SchedulerApp::scheduler_setpoint_t SchedulerApp::getManualSetpointFromFile() {
	mMtx.lock();
	scheduler_setpoint_t setpoint = {-1, -1, -1, -1};
	if (mManualSetpoint == SetpointUnknown) {
		int16_t val = 0;
		nvs_handle_t handle;
		nvs_open(STORAGE_NAMESPACE, NVS_READONLY, &handle);
		nvs_get_i16(handle, KEY_MANUAL_SETPOINT, &val);
		nvs_close(handle);
		setpoint.value = val;
	} else {
		setpoint.value = mManualSetpoint;
	}
	mMtx.unlock();
	return setpoint;
}

void SchedulerApp::setDeicingSetpointToFile(int16_t value) {
	if (mDeicingSetpoint != value || mDeicingSetpoint == SetpointUnknown) {
		nvs_handle_t handle;
		nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handle);
		nvs_set_i16(handle, KEY_DEICING, value);
		nvs_commit(handle);
		nvs_close(handle);
		mDeicingSetpoint = value;
	}
}

SchedulerApp::scheduler_setpoint_t SchedulerApp::getDeicingSetpointFromFile() {
	mMtx.lock();
	scheduler_setpoint_t setpoint = {-1, -1, -1, -1};
	if (mDeicingSetpoint == SetpointUnknown) {
		int16_t val = 0;
		nvs_handle_t handle;
		nvs_open(STORAGE_NAMESPACE, NVS_READONLY, &handle);
		nvs_get_i16(handle, KEY_DEICING, &val);
		nvs_close(handle);
		setpoint.value = val;
	} else {
		setpoint.value = mDeicingSetpoint;
	}
	mMtx.unlock();
	return setpoint;
}

SchedulerApp::scheduler_setpoint_t SchedulerApp::getDailySetpoint(tm timeinfo) {
	scheduler_setpoint_t result =
			getSetpointFromFileUnsafe(KEY_DAILY, timeinfo.tm_hour, timeinfo.tm_min);
	if (result.isEqTime(mModifiedSetpoint)) {
		result = mModifiedSetpoint;
	} else {
		mModifiedSetpoint.reset();
	}
	return result;
}

SchedulerApp::scheduler_setpoint_t SchedulerApp::getWeeklySetpoint(tm timeinfo) {
	scheduler_setpoint_t result =
			getSetpointFromFileUnsafe(getWeeklyKey(timeinfo.tm_wday), timeinfo.tm_hour, timeinfo.tm_min);
	if (result.isEqTime(mModifiedSetpoint)) {
		result = mModifiedSetpoint;
	} else {
		mModifiedSetpoint.reset();
	}
	return result;
}

void SchedulerApp::addSetpointToFileUnsafe(const char* key, scheduler_setpoint_t value) {
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
}

SchedulerApp::scheduler_setpoint_t SchedulerApp::getSetpointFromFileUnsafe
(const char* key, uint8_t hour, uint8_t min) {
	mMtx.lock();
	size_t size = 0;
	scheduler_setpoint_t result = {-1, -1, -1, -1};
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
				result = valueFrom;
				found = true;
				break;
			}
			pos = pos + setpointSize;
		};

		///Find between last point<->midnight and midnight<->first point
		if (!found) {
			memcpy(&valueFrom, &setpointBlobBfr[0], setpointSize);
			memcpy(&valueTo, &setpointBlobBfr[size-setpointSize], setpointSize);
			uint32_t seconsFirst = (valueFrom.hour+1)*minInHour*secInMin + (valueFrom.min+1)*secInMin;
			uint32_t seconsLast =  (valueTo.hour  +1)*minInHour*secInMin + (valueTo.min  +1)*secInMin;
			bool isFromMidnightToFirstPoint = seconsInput < seconsFirst;
			bool isFromLastPointToMidnight = (seconsInput >= seconsLast) && (seconsInput < (hourInDay+1)*minInHour*secInMin);
			if (isFromMidnightToFirstPoint || isFromLastPointToMidnight){
				result = valueTo;//looks like bug here
			}
		}
	}
    nvs_close(handle);
    mMtx.unlock();
	return result;
}

SchedulerApp::scheduler_setpoint_t SchedulerApp::getSetpointForTimeAndMode(tm timeinfo, scheduler_mode_t mode) {
	scheduler_setpoint_t result;

	/**Tmp for debug and test*/
	timeinfo.tm_hour = 0;
	timeinfo.tm_min = timeinfo.tm_sec;
	/***/

	switch (mode) {
	case SchedulerApp::ModeOff:
		result = {-1, -1, -1, 0};
		break;
	case SchedulerApp::ModeDaily:
		result = getDailySetpoint(timeinfo);
		break;
	case SchedulerApp::ModeWeekly:
		result = getWeeklySetpoint(timeinfo);
		break;
	case SchedulerApp::ModeDeicing:
		result = getDeicingSetpointFromFile();
		break;
	case SchedulerApp::ModeManual:
		result = getManualSetpointFromFile();
		break;
	default:
		break;
	}
	return result;
}

SchedulerApp::scheduler_setpoint_t SchedulerApp::getSetpointForCurrentTimeAndMode(){
	time_t now;
	time(&now);
	struct tm timeinfo;
	localtime_r(&now, &timeinfo);
	return getSetpointForTimeAndMode(timeinfo, getMode());
}

void SchedulerApp::updateSetpoint(){
	mSetpoint = getSetpointForCurrentTimeAndMode();

	static int16_t oldSetpoint = 0;
	if (oldSetpoint != mSetpoint.value) {
		oldSetpoint = mSetpoint.value;
		MqttApp::publishMessage(mSetpointDesc, mSetpoint.value);
	}
}


