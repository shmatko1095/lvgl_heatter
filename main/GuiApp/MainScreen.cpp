/*
 * MainScreen.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: f73377
 */

#include "GuiApp.h"
#include "MainScreen.h"
#include "Colors.hpp"
#include "esp_system.h"

LV_IMG_DECLARE(calendar);
LV_IMG_DECLARE(clock);
LV_IMG_DECLARE(shutdown);
LV_IMG_DECLARE(snowflake);
LV_IMG_DECLARE(more);

enum {
	button_w = 80,
	button_h = 40,
};

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
lv_obj_t* MainScreen::mModeButton = nullptr;
lv_obj_t* MainScreen::mModeIcon = nullptr;
lv_obj_t* MainScreen::mNextScreenButton = nullptr;

MainScreen::MainScreen() {
}

void MainScreen::init(){
	mBase = createBase();

	mLinemeterSetpoint = createLinemeterSetpoint(mBase);
	mLinemeterActual = createLinemeterActual(mLinemeterSetpoint);
	mModeButton = MainScreen::createModeButton(mBase, MainScreen::iconModeCb);
	mModeIcon = MainScreen::createModeIcon(mModeButton, &calendar);
	mNextScreenButton = MainScreen::createNextScreenButton(mBase, MainScreen::nextScreenButtonCb);
}

void MainScreen::load(){
	lv_scr_load(mBase);
//	lv_ex_cont_1();
}

void MainScreen::run(){
	static uint8_t cntSetpoint = 50;
	static uint8_t cntActual = 0;
	lv_linemeter_set_value(mLinemeterSetpoint, cntSetpoint);
	lv_linemeter_set_value(mLinemeterActual, cntActual);
	cntSetpoint+=2;
	cntActual+=2;
}

void lv_ex_cont_1(void)
{
    lv_obj_t * cont;
    cont = lv_cont_create(lv_scr_act(), NULL);
    lv_obj_set_auto_realign(cont, true);                    /*Auto realign when the size changes*/

    lv_obj_align_origo(cont, NULL, LV_ALIGN_CENTER, 0, 0);  /*This parametrs will be sued when realigned*/
    lv_cont_set_fit(cont, LV_FIT_TIGHT);
    lv_cont_set_layout(cont, LV_LAYOUT_COLUMN_MID);

    lv_obj_t * label;
    label = lv_label_create(cont, NULL);
    lv_label_set_text(label, "Short text");

    /*Refresh and pause here for a while to see how `fit` works*/
    uint32_t t;
    lv_refr_now(NULL);
    t = lv_tick_get();
    while(lv_tick_elaps(t) < 500);

    label = lv_label_create(cont, NULL);
    lv_label_set_text(label, "It is a long text");

    /*Wait here too*/
    lv_refr_now(NULL);
    t = lv_tick_get();
    while(lv_tick_elaps(t) < 500);

    label = lv_label_create(cont, NULL);
    lv_label_set_text(label, "Here is an even longer text");
}


void MainScreen::handleCurrentModeCd(lv_obj_t *obj, uint8_t mode)	{
	switch (mode) {
	case Off:
		lv_obj_set_style_local_image_recolor(obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);
		lv_img_set_src(mModeIcon, &shutdown);
		break;
	case On:
		lv_obj_set_style_local_image_recolor(obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
		lv_img_set_src(mModeIcon, &clock);
		break;
	case Day:
		lv_img_set_src(mModeIcon, &calendar);
		break;
	case Week:
		lv_img_set_src(mModeIcon, &snowflake);
		break;
	case Deicing:
		lv_obj_set_style_local_image_recolor(obj, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
		lv_img_set_src(mModeIcon, &shutdown);
		break;
	default:
		break;
	}
}

void MainScreen::iconModeCb(lv_obj_t *obj, lv_event_t event) {
	if (event == LV_EVENT_CLICKED) {
		MainScreen::handleCurrentModeCd(obj, currentMode);
		currentMode++;
		currentMode >= ModeAmont ? currentMode = Off : 0;
		printf("Clicked\n");
	}
}

lv_obj_t* MainScreen::createModeButton(lv_obj_t *par, lv_event_cb_t cb) {
    static lv_anim_path_t path_ease_out;
    lv_anim_path_init(&path_ease_out);
    lv_anim_path_set_cb(&path_ease_out, lv_anim_path_ease_out);

	static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_transition_time(&style, LV_STATE_PRESSED, 300);
    lv_style_set_transition_time(&style, LV_STATE_DEFAULT, 0);
    lv_style_set_transition_delay(&style, LV_STATE_DEFAULT, 300);
    lv_style_set_bg_opa(&style, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_opa(&style, LV_STATE_PRESSED, LV_OPA_80);
    lv_style_set_border_width(&style, LV_STATE_DEFAULT, 0);
    lv_style_set_outline_width(&style, LV_STATE_DEFAULT, 0);
    lv_style_set_transform_width(&style, LV_STATE_DEFAULT, -20);
    lv_style_set_transform_height(&style, LV_STATE_DEFAULT, -20);
    lv_style_set_transform_width(&style, LV_STATE_PRESSED, 0);
    lv_style_set_transform_height(&style, LV_STATE_PRESSED, 0);

    lv_style_set_transition_path(&style, LV_STATE_DEFAULT, &path_ease_out);
    lv_style_set_transition_prop_1(&style, LV_STATE_DEFAULT, LV_STYLE_BG_OPA);
    lv_style_set_transition_prop_2(&style, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_WIDTH);
    lv_style_set_transition_prop_3(&style, LV_STATE_DEFAULT, LV_STYLE_TRANSFORM_HEIGHT);

    lv_obj_t* btn = lv_btn_create(par, NULL);
	lv_obj_set_event_cb(btn, cb);
    lv_obj_set_size(btn, button_w, button_h);
    lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -button_h);
	lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style);

    return btn;
}

lv_obj_t* MainScreen::createModeIcon(lv_obj_t *par, const lv_img_dsc_t* img) {
	lv_obj_t* icon= lv_img_create(par, NULL);
	lv_img_set_src(icon, img);
	lv_obj_set_style_local_image_opa(icon, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_40);
	lv_obj_set_style_local_image_recolor_opa(icon, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
	return icon;
}

void MainScreen::nextScreenButtonCb(lv_obj_t *obj, lv_event_t event) {
	if (event == LV_EVENT_CLICKED){
		printf("change screen\n");
		GuiApp::changeScreen(GuiApp::MainScreenId);
	}
}

lv_obj_t* MainScreen::createNextScreenButton(lv_obj_t *par, lv_event_cb_t cb) {
    lv_obj_t* btn = lv_btn_create(par, NULL);
    lv_obj_set_event_cb(btn, cb);
    lv_obj_set_size(btn, button_w, button_h);
    lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);

	static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_opa(&style, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_opa(&style, LV_STATE_PRESSED, LV_OPA_80);
    lv_style_set_bg_color(&style, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
    lv_style_set_border_width(&style, LV_STATE_DEFAULT, 0);
    lv_style_set_outline_width(&style, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style);

    static lv_obj_t* img = lv_img_create(btn, NULL);
    lv_img_set_src(img, &more);
    lv_obj_set_style_local_image_opa(img, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_40);
	return btn;
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

