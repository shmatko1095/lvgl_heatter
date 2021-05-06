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

class SchedulerApp : public StaticBaseTask<4096> {
public:
	enum {
		SetpointUnknown = 0xFFFF,
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

	SchedulerApp();

	void run() override;

	void setMode(scheduler_mode_t mode);

	scheduler_mode_t getMode();

	void addDailySetpoint(uint16_t value){};

	void addWeeklySetpoint(uint16_t value){};

	void removeDailySetpoint(uint16_t value){};

	void removeWeeklySetpoint(uint16_t value){};

	void setSetpoint(uint16_t value) {
		mSetpoint = value;
	};

	uint16_t getSetpoint() {
		return mSetpoint;
	};

	static scheduler_mode_t incMode(scheduler_mode_t mode) {
		scheduler_mode_t result = (SchedulerApp::scheduler_mode_t)((uint8_t)mode + 1);
		if (result >= SchedulerApp::scheduler_mode_t::ModeAmount) {
			result = SchedulerApp::scheduler_mode_t::ModeOff;
		}
		return result;
	};

private:
	void handleModeQueue();

	void setModeUnsafe(scheduler_mode_t mode);
	scheduler_mode_t getModeFromFile();

	uint16_t mSetpoint;
	scheduler_mode_t mMode;
	Queue* mModeQueue;
	Mutex mMtx;
};

#endif /* SCHEDULERAPP_H_ */
