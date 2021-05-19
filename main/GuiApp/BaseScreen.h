/*
 * BaseScreen.h
 *
 *  Created on: May 15, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_BASESCREEN_H_
#define GUIAPP_BASESCREEN_H_

#include "lvgl.h"
#include "Colors.hpp"
#include "../Types.h"

class BaseScreen {
public:
	enum {
		button_w = 80,
		button_h = 40,
	};

	BaseScreen(){
		mNextScreenButton = nullptr;
		mNextScreenButtonImg = nullptr;
	}

	virtual ~BaseScreen(){};

	virtual void init() = 0;

	virtual void load() = 0;

	virtual void run() = 0;

protected:
	lv_obj_t* createBase();
	lv_obj_t* createNextScreenButton(lv_obj_t *par, lv_event_cb_t cb);

	lv_obj_t* mActualTempLabel;
	lv_obj_t* mNextScreenButton;
	lv_obj_t* mNextScreenButtonImg;

	lv_style_t mBaseStyleBox;
	lv_style_t mNextScreenButtonStyleBox;

};

#endif /* GUIAPP_BASESCREEN_H_ */
