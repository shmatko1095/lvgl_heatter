/*
 * InfoScreen.h
 *
 *  Created on: May 15, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_INFOSCREEN_H_
#define GUIAPP_INFOSCREEN_H_

#include "lvgl.h"

#include "BaseScreen.h"
#include "../SchedulerApp.h"
#include "../Types.h"

class InfoScreen : public BaseScreen {
public:
	InfoScreen(){
	}

	virtual ~InfoScreen(){};

	void init() override;

    void load() override {
    	lv_scr_load(mBase);
    }

    void run() override;

private:
    static void nextScreenButtonCb(lv_obj_t *obj, lv_event_t event);

    static lv_obj_t* mBase;

};

#endif /* GUIAPP_INFOSCREEN_H_ */
