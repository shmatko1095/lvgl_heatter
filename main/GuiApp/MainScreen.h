/*
 * MainScreen.h
 *
 *  Created on: Apr 20, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_MAINSCREEN_H_
#define GUIAPP_MAINSCREEN_H_

#include "lvgl.h"
#include "../Types.h"

class MainScreen {
public:
	MainScreen();

	virtual ~MainScreen(){};

	void init();

    void load();

    void run();

private:
    lv_obj_t* createBase();
    lv_obj_t* createLinemeterSetpoint(lv_obj_t *par);
    lv_obj_t* createLinemeterActual(lv_obj_t *par);
    static lv_obj_t* createIconBase(lv_obj_t *par, const lv_img_dsc_t* img, lv_event_cb_t cb);
    static void iconModeCb(lv_obj_t *obj, lv_event_t event);
    static void handleCurrentModeCd(lv_obj_t *obj, uint8_t mode);

    void changeMode();



    lv_obj_t* mLinemeterSetpoint;
    lv_obj_t* mLinemeterActual;
    static lv_obj_t* mBase;
    static lv_obj_t* mIconMode;
    static uint8_t currentMode;


};

#endif /* GUIAPP_MAINSCREEN_H_ */
