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

#ifndef MAIN_GUIAPP_GUIAPP_H_
#define MAIN_GUIAPP_GUIAPP_H_

class GuiApp : public StaticBaseTask<2*4096> {
public:
	enum {
		MainScreenId,
		ExtandedScreenId,
		SettingsScreenId,
		ScreenIdAmount
	};

	GuiApp();
	virtual ~GuiApp(){};

	void init();

	void run() override;

	static void changeScreen(uint8_t currentScreenId);

private:

	static MainScreen mMainScreen;
};
#endif /* MAIN_GUIAPP_GUIAPP_H_ */

