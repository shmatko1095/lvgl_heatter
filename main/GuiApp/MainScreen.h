/*
 * MainScreen.h
 *
 *  Created on: Apr 20, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_MAINSCREEN_H_
#define GUIAPP_MAINSCREEN_H_

#include "lvgl.h"

#include "BaseScreen.h"
#include "../SchedulerApp.h"
#include "../Types.h"

class MainScreen : public BaseScreen {
public:
	MainScreen() {
		mLinemeterActual = nullptr;
	    mLinemeterSetpoint = nullptr;
	}

	virtual ~MainScreen(){};

	void init() override;

	void load() override {
		lv_scr_load(mBase);
	}

    void run() override;

    static lv_obj_t* getBase() {
    	return mBase;
    }

    static void changeModeIcon(SchedulerApp::scheduler_mode_t mode);

private:
    lv_obj_t* createLinemeterSetpoint(lv_obj_t *par);
    lv_obj_t* createLinemeterActual(lv_obj_t *par);

    static lv_obj_t* createActualTempLabel(lv_obj_t *par);
    static void actualTempLabelCb(lv_obj_t *obj, lv_event_t event);

    static lv_obj_t* createModeButton(lv_obj_t *par, lv_event_cb_t cb);
    static lv_obj_t* createModeIcon(lv_obj_t *par, const lv_img_dsc_t* img);
    static void modeIconCb(lv_obj_t *obj, lv_event_t event);
    static void handleCurrentModeCd(lv_obj_t *obj, uint8_t mode);

    static void nextScreenButtonCb(lv_obj_t *obj, lv_event_t event);

    lv_obj_t* mLinemeterSetpoint;
    lv_obj_t* mLinemeterActual;
    static lv_obj_t* mBase;
    static lv_obj_t* mActualTempLabel;

    static lv_obj_t* mModeButton;
    static lv_obj_t* mModeIcon;

};

#endif /* GUIAPP_MAINSCREEN_H_ */
