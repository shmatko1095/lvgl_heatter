/*
 * MainScreen.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: f73377
 */

#include "MainScreen.h"
#include "Colors.hpp"

MainScreen::MainScreen() : mLinemeter(nullptr), mBase(nullptr) {
}

void MainScreen::init(){
	mBase = baseCreate();
	mLinemeter = linemeterCreate(mBase);
}

void MainScreen::load(){
	lv_scr_load(mBase);
}

void MainScreen::update(){

}

lv_obj_t* MainScreen::linemeterCreate(lv_obj_t *par) {
	lv_obj_t *linemeter = lv_linemeter_create(par, NULL);
	static lv_style_t style_box;

	lv_style_init(&style_box);
	lv_style_set_line_width(&style_box, LV_STATE_DEFAULT, 2);
	lv_style_set_scale_end_line_width(&style_box, LV_STATE_DEFAULT, 2);

	lv_style_set_line_color		 (&style_box, LV_STATE_DEFAULT, lv_color_hex((uint32_t)Colors::linemeter_start_color)); //start lines
	lv_style_set_scale_grad_color(&style_box, LV_STATE_DEFAULT, lv_color_hex((uint32_t)Colors::linemeter_end_color)); //last active lines
	lv_style_set_scale_end_color (&style_box, LV_STATE_DEFAULT, lv_color_hex((uint32_t)Colors::default_color)); //inactive lines
//	lv_style_set_bg_opa			 (&style_box, LV_STATE_DEFAULT, LV_OPA_TRANSP);
	lv_style_set_bg_color		 (&style_box, LV_STATE_DEFAULT, lv_color_hex((uint32_t)Colors::bg_color));

	lv_linemeter_set_range(linemeter, 0, 100); /*Set the range*/
	lv_linemeter_set_value(linemeter, 80); /*Set the current value*/
	lv_linemeter_set_scale(linemeter, 240, 60); /*Set the angle and number of lines*/

	lv_obj_set_size(linemeter, LV_HOR_RES, LV_VER_RES);
	lv_obj_align(linemeter, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_style(linemeter, LV_LINEMETER_PART_MAIN, &style_box);
	lv_obj_set_style_local_value_str(linemeter, LV_LINEMETER_PART_MAIN,
			LV_STATE_DEFAULT, "Line meter");

	return linemeter;
}

lv_obj_t* MainScreen::baseCreate() {
	return lv_obj_create(NULL, NULL);
}
