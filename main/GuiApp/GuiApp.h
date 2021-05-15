/*
 * exampleGuiTask.h
 *
 *  Created on: Apr 12, 2021
 *      Author: f73377
 */

#include "../Types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include "MainScreen.h"
#include "InfoScreen.h"
#include "../Core/BaseTask.hpp"
#include "../SchedulerApp.h"

#ifndef MAIN_GUIAPP_GUIAPP_H_
#define MAIN_GUIAPP_GUIAPP_H_

class GuiApp : public StaticBaseTask<4096*2> {
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

	static uint16_t getSetpoint(){
		return mSchedulerPtr->getSetpoint();
	}

	static uint16_t getActual(){
		return mSchedulerPtr->getSetpoint();
	}

	static void changeSetpoint(uint16_t setpoint, bool goToManual);

	static void changeScreen(uint8_t currentScreenId);

	static void changeMode(SchedulerApp::scheduler_mode_t mode);

	static void incMode();

	static SchedulerApp::scheduler_mode_t getMode() {
		return mCurrentMode;
	}

private:
	static MainScreen mMainScreen;
	static InfoScreen mInfoScreen;
	static BaseScreen* mCurrentScreen;

	static SchedulerApp::scheduler_mode_t mCurrentMode;
	static SchedulerApp* mSchedulerPtr;
};
#endif /* MAIN_GUIAPP_GUIAPP_H_ */

