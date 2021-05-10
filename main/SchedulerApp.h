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
		uint16_t day;
		uint16_t hour;
		uint16_t min;
		uint16_t value;
	} scheduler_setpoint_t;

	SchedulerApp();

	void run() override;

	void setMode(scheduler_mode_t mode);

	scheduler_mode_t getMode();

	void setDeicingSetpoint(int16_t value);

	void addDailySetpoint(scheduler_setpoint_t* value);

	void addWeeklySetpoint(scheduler_setpoint_t* value);

	void removeDailySetpoint(scheduler_setpoint_t value){};

	void removeWeeklySetpoint(scheduler_setpoint_t value){};

	void setManualSetpoint(int16_t value);

	int16_t getSetpoint() {
		return mSetpoint;
	}

	static scheduler_mode_t incMode(scheduler_mode_t mode) {
		scheduler_mode_t result = (SchedulerApp::scheduler_mode_t)((uint8_t)mode + 1);
		if (result >= SchedulerApp::scheduler_mode_t::ModeAmount) {
			result = SchedulerApp::scheduler_mode_t::ModeOff;
		}
		return result;
	};

private:
	void handleModeQueue();
	void handleDailyQueue();
	void handleWeeklyQueue();
	void handleManualSetpointQueue();

	void addSetpointToFileUnsafe(const char* key, scheduler_setpoint_t value);
	int16_t getSetpointFromFileUnsafe(const char* key, uint8_t hour, uint8_t min);

	void setManualSetpointUnsafe(int16_t value);
	int16_t getManualSetpointFromFile();

	int16_t getDeicingSetpointFromFile();

	void setModeUnsafe(scheduler_mode_t mode);
	scheduler_mode_t getModeFromFile();

	void updateSetpoint();

	static char* getWeeklyKey(uint8_t day);

	int16_t mSetpoint;
	scheduler_mode_t mMode;
	Queue* mModeQueue;
	Queue* mDailyQueue;
	Queue* mWeeklyQueue;
	Queue* mSetpointQueue;
	Mutex mMtx;
};

#endif /* SCHEDULERAPP_H_ */
