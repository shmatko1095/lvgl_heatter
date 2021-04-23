/*
 * MainScreen.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: f73377
 */

#include "MainScreen.h"
#include "Colors.hpp"
#include "esp_system.h"

LV_IMG_DECLARE(calendar);
LV_IMG_DECLARE(clock);
LV_IMG_DECLARE(shutdown);
LV_IMG_DECLARE(snowflake);

enum {
	linemeter_min = 0,
	linemeter_max = 255,
	linemeter_angle = 240,
	linemeter_lines = 60,
	linemeter_lines_width = 3,
	linemeter_end_lines_width = 1,
	linemeter_actual_scale_width = 7,
	linemeter_setpoint_scale_width = 14
};

enum ModeList {
	Off,
	On,
	Day,
	Week,
	Deicing,
	ModeAmont
};

uint8_t MainScreen::currentMode = Day;
lv_obj_t* MainScreen::mBase = nullptr;
lv_obj_t* MainScreen::mIconMode = nullptr;

MainScreen::MainScreen() {
}

void MainScreen::init(){
	mBase = createBase();

	mLinemeterSetpoint = createLinemeterSetpoint(mBase);
	mLinemeterActual = createLinemeterActual(mLinemeterSetpoint);
	mIconMode = MainScreen::createIconBase(mBase, &clock, MainScreen::iconModeCb);
}

void MainScreen::load(){
	lv_scr_load(mBase);
}

void MainScreen::run(){
	static uint8_t cntSetpoint = 50;
	static uint8_t cntActual = 0;
	lv_linemeter_set_value(mLinemeterSetpoint, cntSetpoint);
	lv_linemeter_set_value(mLinemeterActual, cntActual);
	cntSetpoint+=2;
	cntActual+=2;
}

void MainScreen::handleCurrentModeCd(lv_obj_t *obj, uint8_t mode)	{
	switch (mode) {
	case Off:
		lv_obj_set_style_local_image_recolor(obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);
		lv_img_set_src(obj, &shutdown);
		break;
	case On:
		lv_obj_set_style_local_image_recolor(obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
		lv_img_set_src(obj, &clock);
		break;
	case Day:
		lv_img_set_src(obj, &calendar);
		break;
	case Week:
		lv_img_set_src(obj, &snowflake);
		break;
	case Deicing:
		lv_obj_set_style_local_image_recolor(obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
		lv_img_set_src(obj, &shutdown);
		break;
	default:
		break;
	}
}

void MainScreen::iconModeCb(lv_obj_t *obj, lv_event_t event) {
	if ((event == LV_EVENT_CLICKED) || (event == LV_EVENT_SHORT_CLICKED) || (event == LV_EVENT_RELEASED)) {
		MainScreen::handleCurrentModeCd(obj, currentMode);
		currentMode++;
		currentMode >= ModeAmont ? currentMode = Off : 0;
		printf("Clicked\n");
	}
}

lv_obj_t* MainScreen::createIconBase(lv_obj_t *par, const lv_img_dsc_t* img, lv_event_cb_t cb) {
    lv_obj_t* obj = lv_img_create(par, NULL);
    lv_img_set_src(obj, img);
//    lv_obj_set_style_local_image_opa(obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_40);
//    lv_obj_set_style_local_image_recolor_opa(obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_100);
    lv_obj_align(obj, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);

    lv_obj_set_click(obj, true);
    lv_obj_set_event_cb(obj, cb);
    return obj;
}

lv_obj_t* MainScreen::createLinemeterActual(lv_obj_t *par) {
	static lv_style_t style_box;
	lv_style_init(&style_box);

	lv_style_set_line_opa(&style_box, LV_STATE_DEFAULT, LV_OPA_90);
	lv_style_set_line_width(&style_box, LV_STATE_DEFAULT, linemeter_lines_width);
	lv_style_set_line_color(&style_box, LV_STATE_DEFAULT, LINEMETER_START_COLOR); //start lines

	lv_style_set_scale_grad_color(&style_box, LV_STATE_DEFAULT, LINEMETER_END_COLOR); //last active lines
	lv_style_set_scale_end_line_width(&style_box, LV_STATE_DEFAULT, 0);
	lv_style_set_scale_width(&style_box, LV_STATE_DEFAULT, linemeter_actual_scale_width);
	lv_style_set_border_width(&style_box, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_opa(&style_box, LV_STATE_DEFAULT, LV_OPA_TRANSP);

	lv_obj_t *linemeter = lv_linemeter_create(par, NULL);
	lv_linemeter_set_range(linemeter, linemeter_min, linemeter_max); /*Set the range*/
	lv_linemeter_set_scale(linemeter, linemeter_angle, linemeter_lines); /*Set the angle and number of lines*/

	lv_obj_set_size(linemeter, LV_HOR_RES, LV_VER_RES);
	lv_obj_align(linemeter, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_set_style_local_value_str(linemeter, LV_LINEMETER_PART_MAIN, LV_STATE_DEFAULT, "Line meter");
	lv_obj_add_style(linemeter, LV_LINEMETER_PART_MAIN, &style_box);

	return linemeter;
}

lv_obj_t* MainScreen::createLinemeterSetpoint(lv_obj_t *par) {
	static lv_style_t style_box;
	lv_style_init(&style_box);

	lv_style_set_line_opa(&style_box, LV_STATE_DEFAULT, LV_OPA_40);
	lv_style_set_line_width(&style_box, LV_STATE_DEFAULT, linemeter_lines_width);
	lv_style_set_line_color(&style_box, LV_STATE_DEFAULT, LINEMETER_START_COLOR); //start lines

	lv_style_set_scale_grad_color(&style_box, LV_STATE_DEFAULT, LINEMETER_END_COLOR); //last active lines
	lv_style_set_scale_end_color(&style_box, LV_STATE_DEFAULT, DEFAULT_COLOR); //inactive lines
	lv_style_set_scale_end_line_width(&style_box, LV_STATE_DEFAULT, linemeter_end_lines_width);
	lv_style_set_scale_width(&style_box, LV_STATE_DEFAULT, linemeter_setpoint_scale_width);
	lv_style_set_border_width(&style_box, LV_STATE_DEFAULT, 0);

	lv_style_set_bg_color(&style_box, LV_STATE_DEFAULT, BG_COLOR);

	lv_obj_t *linemeter = lv_linemeter_create(par, NULL);
	lv_linemeter_set_range(linemeter, linemeter_min, linemeter_max); /*Set the range*/
	lv_linemeter_set_scale(linemeter, linemeter_angle, linemeter_lines); /*Set the angle and number of lines*/

	lv_obj_set_size(linemeter, LV_HOR_RES, LV_VER_RES);
	lv_obj_align(linemeter, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_add_style(linemeter, LV_LINEMETER_PART_MAIN, &style_box);

	return linemeter;
}

lv_obj_t* MainScreen::createBase() {
	lv_obj_t* base = lv_obj_create(NULL, NULL);
	static lv_style_t style_box;
	lv_style_init(&style_box);
	lv_style_set_bg_color(&style_box, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_obj_add_style(base, LV_LINEMETER_PART_MAIN, &style_box);
	return base;
}

