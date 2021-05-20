/*
 * SettingsScreen.h
 *
 *  Created on: May 20, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_SETTINGSSCREEN_H_
#define GUIAPP_SETTINGSSCREEN_H_

#include "lvgl.h"
#include "BaseScreen.h"
#include "../Types.h"

class SettingsScreen : public BaseScreen {
public:
	SettingsScreen() {
	}

	virtual ~SettingsScreen(){};

	void init() override;

    void load() override {
    	lv_scr_load(mBase);
    }

    void run() override;

    static lv_obj_t* getBase() {
    	return mBase;
    }

private:
    lv_obj_t* createMeterContainer(lv_obj_t* par);
    static void nextScreenButtonCb(lv_obj_t *obj, lv_event_t event);

    static lv_obj_t* mBase;
    lv_obj_t* mContainer;
};

#endif /* GUIAPP_SETTINGSSCREEN_H_ */
