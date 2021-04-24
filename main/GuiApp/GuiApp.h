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

#ifndef MAIN_GUIAPP_GUIAPP_H_
#define MAIN_GUIAPP_GUIAPP_H_

class GuiApp {
public:
	enum {
		MainScreenId,
		ExtandedScreenId,
		SettingsScreenId,
		ScreenIdAmount
	};

	GuiApp();
	virtual ~GuiApp(){};

	static void init();

	static void start(uint32_t stackSize, uint8_t priority, uint8_t coreId);

	static void run();

	static void changeScreen(uint8_t currentScreenId);

private:

	static MainScreen mMainScreen;
};
#endif /* MAIN_GUIAPP_GUIAPP_H_ */

