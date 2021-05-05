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
#include "../Core/BaseTask.hpp"
#include "../SchedulerUl.h"

#ifndef MAIN_GUIAPP_GUIAPP_H_
#define MAIN_GUIAPP_GUIAPP_H_

class GuiApp : public StaticBaseTask<4096*3> {
public:
	enum {
		MainScreenId,
		ExtandedScreenId,
		SettingsScreenId,
		ScreenIdAmount
	};

	GuiApp(SchedulerUl* scheduler);
	virtual ~GuiApp(){};

	void init();

	void run() override;

	static void changeScreen(uint8_t currentScreenId);

	static void changeMode();

	static void saveMode(void* scr);

private:
	static MainScreen mMainScreen;
	static SchedulerUl::scheduler_mode_t mCurrentMode;
	static SchedulerUl* mSchedulerPtr;
};
#endif /* MAIN_GUIAPP_GUIAPP_H_ */

