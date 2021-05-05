/*
 * Scheduler.h
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#ifndef SCHEDULERUL_H_
#define SCHEDULERUL_H_

#include "Types.h"
#include "SpiFfsStorrage.h"
#include "Core/Mutex.hpp"

class SchedulerUl {
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

	SchedulerUl(){
		mMode = ModeUnknown;
		mCurrntSetpoint = SetpointUnknown;
	};

	void setMode(scheduler_mode_t mode);

	scheduler_mode_t getMode();

	void addDailySetpoint(uint16_t value){};

	void addWeeklySetpoint(uint16_t value){};

	void removeDailySetpoint(uint16_t value){};

	void removeWeeklySetpoint(uint16_t value){};

	void setSetpoint(uint16_t value){mCurrntSetpoint = value;};

	uint16_t getSetpoint(){return mCurrntSetpoint;};

private:
	void setModeUnsafe(scheduler_mode_t mode);
	scheduler_mode_t getModeFromFile();

	scheduler_mode_t mMode;
	uint16_t mCurrntSetpoint;

	Mutex mMtx;
};

#endif /* SCHEDULERUL_H_ */
