/*
 * Scheduler.cpp
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#include "SchedulerApp.h"

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
	mCurrntSetpoint = SetpointUnknown;

	static uint8_t ucQueueModeStorageArea[QueueModeLen * QueueModeItemSize];
	static Queue modeQueue = Queue(ucQueueModeStorageArea, QueueModeLen, QueueModeItemSize);
	mModeQueue = &modeQueue;
};

void SchedulerApp::run() {
	while (1) {
		handleModeQueue();
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void SchedulerApp::handleModeQueue() {
	scheduler_mode_t mode;
	while (mModeQueue->receive((uint8_t*)&mode, 0)){
		setModeUnsafe(mode);
	}
}

void SchedulerApp::setMode(scheduler_mode_t mode){
	mModeQueue->send((uint8_t*)&mode);
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
