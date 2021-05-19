/*
 * InfoScreen.h
 *
 *  Created on: May 15, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_INFOSCREEN_H_
#define GUIAPP_INFOSCREEN_H_

#include "lvgl.h"

#include "Meter.h"
#include "BaseScreen.h"
#include "../SchedulerApp.h"
#include "../Types.h"

class InfoScreen : public BaseScreen {
public:
	InfoScreen() {
		mInTemp = nullptr;
		mOutTemp = nullptr;
		mLoadMeter = nullptr;
		mPressure = nullptr;
		mBase = nullptr;
		mContainer = nullptr;
	}

	virtual ~InfoScreen(){};

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

    lv_obj_t* createActualTempLabel(lv_obj_t *par);
    static void actualTempLabelCb(lv_obj_t *obj, lv_event_t event);
    static void tempSettingOpen(void* scr);

    lv_obj_t* createChart(lv_obj_t* par);

    static void nextScreenButtonCb(lv_obj_t *obj, lv_event_t event);

    Meter *mInTemp;
    Meter *mOutTemp;
    Meter *mLoadMeter;
    Meter *mPressure;

    static lv_obj_t* mBase;
    lv_obj_t* mContainer;

};

#endif /* GUIAPP_INFOSCREEN_H_ */
