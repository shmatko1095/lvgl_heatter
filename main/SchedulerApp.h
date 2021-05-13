/*
 * Scheduler.h
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#ifndef SCHEDULERAPP_H_
#define SCHEDULERAPP_H_

#include "Types.h"
#include "SpiFfsStorrage.h"
#include "Core/Mutex.hpp"
#include "Core/Queue.hpp"

#define KEY_DAILY "KEY_DAILY"
#define KEY_WEEKLY "KEY_WEEKLY"

class SchedulerApp : public StaticBaseTask<4096*3> {
public:
	enum {
		SetpointUnknown = -1,
	};

	typedef enum ModeList{
		ModeOff,
		ModeManual,
		ModeDaily,
		ModeWeekly,
		ModeDeicing,
		ModeUnknown,
		ModeAmount = ModeUnknown,
	} scheduler_mode_t;

	typedef struct {
		int16_t day;
		int16_t hour;
		int16_t min;
		int16_t value;
	} scheduler_setpoint_t;

	SchedulerApp();

	void run() override;

	void setMode(scheduler_mode_t mode){
		mModeQueue->send((char*)&mode);
	}

	scheduler_mode_t getMode() {
		if (mMode == scheduler_mode_t::ModeUnknown) {
			mMode = getModeFromFile();
		}
		return mMode;
	}

	void setDeicingSetpoint(int16_t value);

	void addDailySetpoint(scheduler_setpoint_t* value) {
		mDailyQueue->send(value);
	}

	void addWeeklySetpoint(scheduler_setpoint_t* value) {
		mWeeklyQueue->send(value);
	}

	void removeDailySetpoint(scheduler_setpoint_t value){};

	void removeWeeklySetpoint(scheduler_setpoint_t value){};

	void setManualSetpoint(int16_t value) {
		mSetpointQueue->send(&value);

		static bool isSchedulerInited = false;
		if (!isSchedulerInited) {
		   for (uint8_t cnt = 0; cnt < 60; cnt++){
		      scheduler_setpoint_t setpoint;
		      setpoint.hour  = 0;
		      setpoint.min   = cnt;
		      setpoint.value = cnt*10;
		      addDailySetpoint(&setpoint);
		   }
		   isSchedulerInited = true;
		}
	}

	int16_t getSetpoint() {
		return mSetpoint.value;
	}

	static scheduler_mode_t incMode(scheduler_mode_t mode) {
		scheduler_mode_t result = (SchedulerApp::scheduler_mode_t)((uint8_t)mode + 1);
		if (result >= SchedulerApp::scheduler_mode_t::ModeAmount) {
			result = SchedulerApp::scheduler_mode_t::ModeOff;
		}
		return result;
	};

private:
	void handleModeQueue() {
		char mode;
		while (mModeQueue->receive(&mode, 0)){
			mMtx.lock();
			setModeUnsafe((scheduler_mode_t)mode);
			mMtx.unlock();
		}
	}

	void handleDailyQueue() {
		scheduler_setpoint_t value;
		while (mDailyQueue->receive(&value, 0)){
			mMtx.lock();
			addSetpointToFileUnsafe(KEY_DAILY, value);
			mMtx.unlock();
		}
	}

	void handleWeeklyQueue() {
		scheduler_setpoint_t value;
		while (mWeeklyQueue->receive(&value, 0)){
			mMtx.lock();
			addSetpointToFileUnsafe(getWeeklyKey(value.day), value);
			mMtx.unlock();
		}
	}

	void handleManualSetpointQueue() {
		int16_t value;
		while (mSetpointQueue->receive(&value, 0)){
			mMtx.lock();
			setManualSetpointUnsafe(value);
			mMtx.unlock();
		}
	}

	void addSetpointToFileUnsafe(const char* key, scheduler_setpoint_t value);

	scheduler_setpoint_t getSetpointFromFileUnsafe(const char* key, uint8_t hour, uint8_t min);

	void setManualSetpointUnsafe(int16_t value);

	scheduler_setpoint_t getManualSetpointFromFile();

	int16_t getDeicingSetpointFromFile();

	void setModeUnsafe(scheduler_mode_t mode);

	scheduler_mode_t getModeFromFile();

	scheduler_setpoint_t getSetpointForCurrentMode();

	void updateSetpoint();

	static char* getWeeklyKey(uint8_t day) {
		static char key[19];
		sprintf(key, "%s%d\n", KEY_WEEKLY, day);
		return key;
	}

	uint8_t mModifiedDay, mModifiedHours, mModifiedMin;
	scheduler_setpoint_t mSetpoint;
	scheduler_mode_t mMode;
	Queue* mModeQueue;
	Queue* mDailyQueue;
	Queue* mWeeklyQueue;
	Queue* mSetpointQueue;
	Mutex mMtx;
};

#endif /* SCHEDULERAPP_H_ */
