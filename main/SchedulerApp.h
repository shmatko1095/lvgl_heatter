/*
 * Scheduler.h
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#ifndef SCHEDULERAPP_H_
#define SCHEDULERAPP_H_

#include <stdio.h>
#include <stdlib.h>
#include "Common/Types.h"
#include "Connection/MqttApp.h"
#include "Connection/MqttEventReceiver.hpp"
#include "Core/BaseTask.hpp"
#include "Core/Mutex.hpp"
#include "Core/Queue.hpp"

#define KEY_DAILY "KEY_DAILY"
#define KEY_WEEKLY "KEY_WEEKLY"

class SchedulerApp : public StaticBaseTask<4096*2>, public MqttEventReceiver {
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

	void onReceive(char* topic, size_t topicLen, char* data, size_t dataLen);

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

	void setSetpoint(int16_t value) {
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
	void mqttModeHandler(char* data, size_t dataLen) {
		if (dataLen == 1) {
			int mode = atoi(data);
			setMode((scheduler_mode_t)mode);
		}
	}

	void mqttSetpointHandler(char* data, size_t dataLen) {
		if (dataLen > 0 && dataLen < 4) {
			int16_t value = atoi(data);
			setSetpoint(value);
		}
	}

	void handleModeQueue() {
		char mode;
		mMtx.lock();
		while (mModeQueue->getCount()){
			mModeQueue->receive(&mode, 0);
			setModeUnsafe((scheduler_mode_t)mode);
			MqttApp::publishMessage(mModeDesc, mode);
		}
		mMtx.unlock();
	}

	void handleDailyQueue() {
		scheduler_setpoint_t value;
		mMtx.lock();
		while (mDailyQueue->receive(&value, 0)){
			addSetpointToFileUnsafe(KEY_DAILY, value);
		}
		mMtx.unlock();
	}

	void handleWeeklyQueue() {
		scheduler_setpoint_t value;
		mMtx.lock();
		while (mWeeklyQueue->receive(&value, 0)){
			addSetpointToFileUnsafe(getWeeklyKey(value.day), value);
		}
		mMtx.unlock();
	}

	void handleSetpointQueue() {
		int16_t value;
		mMtx.lock();
		while (mSetpointQueue->receive(&value, 0)){
			setSetpointUnsafe(value);
		}
		mMtx.unlock();
	}

	void addSetpointToFileUnsafe(const char* key, scheduler_setpoint_t value);

	scheduler_setpoint_t getSetpointFromFileUnsafe(const char* key, uint8_t hour, uint8_t min);

	void setSetpointUnsafe(int16_t value);

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

	static MqttEventReceiver::MqttTopicDesc mModeDesc;
	static MqttEventReceiver::MqttTopicDesc mSetpointDesc;
};

#endif /* SCHEDULERAPP_H_ */
