/*
 * Scheduler.cpp
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#include <string.h>
#include "SchedulerUl.h"
#include "Core/MutexLocker.hpp"

static const char * const writeMode = "wb";
static const char * const modeFilePath = "/spiflash/mode";

void SchedulerUl::setMode(scheduler_mode_t mode){
	if (mMode != mode) {
		mMtx.lock();
		setModeUnsafe(mode);
		mMtx.unlock();
	}
}

void SchedulerUl::setModeUnsafe(scheduler_mode_t mode){
	if (mMode != mode) {
		FILE* f = fopen(modeFilePath, writeMode);
		if (f == NULL) {
			printf("Failed to open mode file for writing\n");
		}
		fprintf(f, (char*)&mode);
		fseek(f, 0, SEEK_END);
		int size = ftell(f);
		fclose(f);
		printf("Mode file updated, size: %d\n", size);
		mMode = mode;
	}
}

SchedulerUl::scheduler_mode_t SchedulerUl::getMode() {
	if (mMode == scheduler_mode_t::ModeUnknown) {
		mMode = getModeFromFile();
	}
	return mMode;
}

SchedulerUl::scheduler_mode_t SchedulerUl::getModeFromFile() {
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
