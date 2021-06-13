/*
 * exampleGuiTask.h
 *
 *  Created on: Apr 12, 2021
 *      Author: f73377
 */

#include "../Common/Types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include "MainScreen.h"
#include "InfoScreen.h"
#include "SettingsScreen.h"
#include "../Core/BaseTask.hpp"
#include "../SchedulerApp.h"

#ifndef MAIN_GUIAPP_GUIAPP_H_
#define MAIN_GUIAPP_GUIAPP_H_

class GuiApp : public StaticBaseTask<4096*3> {
public:
	enum {
		InvalidValue = -1
	};
	enum {
		MainScreenId,
		InfoScreenId,
		SettingsScreenId,
		ScreenIdAmount
	};

	GuiApp(SchedulerApp* scheduler);
	virtual ~GuiApp(){};

	void init();

	void run() override;

	static int16_t getSetpoint(){
		return mSchedulerPtr != nullptr ? mSchedulerPtr->getSetpoint() : -1;
	}

	static int16_t getActual(){
		return mSchedulerPtr != nullptr ? mSchedulerPtr->getSetpoint() : -1;
	}

	static void changeSetpoint(uint16_t setpoint, bool goToManual);

	static void changeScreen(uint8_t currentScreenId);

	static SchedulerApp::scheduler_mode_t getMode() {
		return mSchedulerPtr != nullptr ? mSchedulerPtr->getMode() : SchedulerApp::scheduler_mode_t::ModeUnknown;
	}

	static void setMode(SchedulerApp::scheduler_mode_t mode) {
		if (mSchedulerPtr != nullptr) {
			mSchedulerPtr->setMode(mode);
		}
	}

	static void incMode() {
		SchedulerApp::scheduler_mode_t currentMode = getMode();
		SchedulerApp::scheduler_mode_t newMode = SchedulerApp::incMode(currentMode);
		setMode(newMode);
	}

private:
	static MainScreen mMainScreen;
	static InfoScreen mInfoScreen;
	static SettingsScreen mSettingsScreen;
	static BaseScreen* mCurrentScreen;

	static SchedulerApp* mSchedulerPtr;
};
#endif /* MAIN_GUIAPP_GUIAPP_H_ */

