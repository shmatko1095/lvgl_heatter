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

static const char * const writeMode = "wb";
static const char * const modeFilePath = "/spiflash/mode";

enum {
	QueueModeLen = 5,
	QueueModeItemSize = 1
};

SchedulerApp::SchedulerApp(){
	create("SchedulerApp", 0, 1);
	mMode = ModeUnknown;
	mSetpoint = SetpointUnknown;

	static uint8_t ucQueueModeStorageArea[QueueModeLen * QueueModeItemSize];
	static Queue modeQueue = Queue(ucQueueModeStorageArea, QueueModeLen, QueueModeItemSize);
	mModeQueue = &modeQueue;
};

void SchedulerApp::run() {
//	remove(modeFilePath);

	setenv("TZ", "CST-8", 1);
	tzset();

	while (1) {
		handleModeQueue();

		time_t now;
		char strftime_buf[64];
		struct tm timeinfo;
		time(&now);
		localtime_r(&now, &timeinfo);
		strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
		printf("%s\n", strftime_buf);

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void SchedulerApp::handleModeQueue() {
	char mode;
	while (mModeQueue->receive(&mode, 0)){
		setModeUnsafe((scheduler_mode_t)mode);
	}
}

void SchedulerApp::setMode(scheduler_mode_t mode){
	mModeQueue->send((char*)&mode);
}

void SchedulerApp::setModeUnsafe(scheduler_mode_t mode){
	if (mMode != mode) {
		FILE* f = fopen(modeFilePath, writeMode);
		if (f == NULL) {
			printf("Failed to open mode file for writing\n");
		}
		fprintf(f, (char*)&mode);
		fclose(f);
		mMode = mode;
	}
}

SchedulerApp::scheduler_mode_t SchedulerApp::getMode() {
	if (mMode == scheduler_mode_t::ModeUnknown) {
		mMode = getModeFromFile();
	}
	return mMode;
}

SchedulerApp::scheduler_mode_t SchedulerApp::getModeFromFile() {
	mMtx.lock();
	scheduler_mode_t result;
	printf("Reading file\n");
	FILE* f = fopen(modeFilePath, "rb");
	if (f == NULL) {
	   	printf("Failed to open mode file for reading. \"ModeManual\" as default will be used\n");
	   	setModeUnsafe(ModeManual);
	}
	fgets((char*)&result, sizeof(result), f);
	printf("Read mode num:%d\n", result);
	fclose(f);
	mMtx.unlock();
	return result;
}
