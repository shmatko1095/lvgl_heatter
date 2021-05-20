/*
 * Meter.h
 *
 *  Created on: May 16, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_METER_H_
#define GUIAPP_METER_H_

#include "Colors.hpp"
#include "../Types.h"
#include "lvgl.h"

class Meter {
public:
	Meter(lv_obj_t* par) {
		mBase = createBase(par);
		mLabel = createLabel(mBase);
	}

	void setValue(float value) {
		lv_label_set_text_fmt(mLabel, "%3.1f", value);
	}

	lv_obj_t* getBase() {
		return mBase;
	}

private:
	enum {
		BaseWidth = 90,
		BaseHeight = 60
	};

	lv_obj_t* createLabel(lv_obj_t* par) {
	    lv_obj_t* label = lv_label_create(par, NULL);
	    lv_obj_set_auto_realign(label, true);
	    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
	    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
	    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_36);
	    lv_obj_set_style_local_text_color(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
		return label;
	}

	lv_obj_t* createBase(lv_obj_t* par) {
	    lv_obj_t* cont = lv_cont_create(par, NULL);
	    lv_obj_set_size(cont, BaseWidth, BaseHeight);
	    lv_obj_set_style_local_bg_color(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, DARK_GRAY);
	    lv_obj_set_style_local_border_width(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 0);
	    return cont;
	}

	lv_obj_t* mBase;
	lv_obj_t* mLabel;
};

#endif /* GUIAPP_METER_H_ */
