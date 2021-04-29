/*
 * Scheduler.h
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Types.h"

class Scheduler {
public:
	typedef enum ModeList{
		ModeManual,
		ModeDaily,
		ModeWeekly
	} scheduler_mode_t;

	Scheduler();

	void setMode(scheduler_mode_t mode){};

	scheduler_mode_t getMode(){return ModeList::ModeManual;};

	void addNewDailySetpoint(uint16_t value){};

	void addWeeklyDailySetpoint(uint16_t value){};

	void removeDailySetpoint(uint16_t value){};

	void removeWeeklyDailySetpoint(uint16_t value){};

	void setSetpoint(uint16_t value){};

	uint16_t getSetpoint(){return 0;};

};

#endif /* SCHEDULER_H_ */
