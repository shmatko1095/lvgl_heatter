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
    lv_obj_t* baseCreate();
    lv_obj_t* linemeterSetpointCreate(lv_obj_t *par);
    lv_obj_t* linemeterActualCreate(lv_obj_t *par);

    lv_obj_t * mBase;
    lv_obj_t * mLinemeterSetpoint;
    lv_obj_t * mLinemeterActual;
};

#endif /* GUIAPP_MAINSCREEN_H_ */
