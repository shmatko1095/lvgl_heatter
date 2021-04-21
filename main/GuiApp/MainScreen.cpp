/*
 * MainScreen.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: f73377
 */

#include "MainScreen.h"
#include "Colors.hpp"

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

MainScreen::MainScreen() : mBase(nullptr), mLinemeterSetpoint(nullptr), mLinemeterActual(nullptr) {
}

void MainScreen::init(){
	mBase = baseCreate();

	mLinemeterSetpoint = linemeterSetpointCreate(mBase);
	mLinemeterActual = linemeterActualCreate(mLinemeterSetpoint);
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

lv_obj_t* MainScreen::linemeterActualCreate(lv_obj_t *par) {
	lv_obj_t *linemeter = lv_linemeter_create(par, NULL);
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

	lv_linemeter_set_range(linemeter, linemeter_min, linemeter_max); /*Set the range*/
	lv_linemeter_set_scale(linemeter, linemeter_angle, linemeter_lines); /*Set the angle and number of lines*/

	lv_obj_set_size(linemeter, LV_HOR_RES, LV_VER_RES);
	lv_obj_align(linemeter, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_set_style_local_value_str(linemeter, LV_LINEMETER_PART_MAIN, LV_STATE_DEFAULT, "Line meter");
	lv_obj_add_style(linemeter, LV_LINEMETER_PART_MAIN, &style_box);

	return linemeter;
}

lv_obj_t* MainScreen::linemeterSetpointCreate(lv_obj_t *par) {
	lv_obj_t *linemeter = lv_linemeter_create(par, NULL);
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

	lv_linemeter_set_range(linemeter, linemeter_min, linemeter_max); /*Set the range*/
	lv_linemeter_set_scale(linemeter, linemeter_angle, linemeter_lines); /*Set the angle and number of lines*/

	lv_obj_set_size(linemeter, LV_HOR_RES, LV_VER_RES);
	lv_obj_align(linemeter, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_add_style(linemeter, LV_LINEMETER_PART_MAIN, &style_box);

	return linemeter;
}

lv_obj_t* MainScreen::baseCreate() {
	lv_obj_t* base = lv_obj_create(NULL, NULL);
	static lv_style_t style_box;
	lv_style_init(&style_box);
	lv_style_set_bg_color(&style_box, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_obj_add_style(base, LV_LINEMETER_PART_MAIN, &style_box);
	return base;
}
