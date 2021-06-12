/*
 * MainScreen.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: f73377
 */

#include "GuiApp.h"
#include "MainScreen.h"
#include "esp_system.h"
#include "TempSetpointContainer.h"

LV_IMG_DECLARE(calendar);
LV_IMG_DECLARE(clockicon);
LV_IMG_DECLARE(shutdown);
LV_IMG_DECLARE(snowflake);

enum {
	linemeter_min = 100, //10 * 10°C
	linemeter_max = 400, //40 * 10°C
	linemeter_angle = 240,
	linemeter_lines = 60,
	linemeter_lines_width = 3,
	linemeter_end_lines_width = 1,
	linemeter_actual_scale_width = 7,
	linemeter_setpoint_scale_width = 14
};

lv_obj_t* MainScreen::mBase = nullptr;
lv_obj_t* MainScreen::mActualTempLabel = nullptr;
lv_obj_t* MainScreen::mModeButton = nullptr;
lv_obj_t* MainScreen::mModeIcon = nullptr;

void MainScreen::init(){
	mBase = createBase();

	mLinemeterSetpoint = createLinemeterSetpoint(mBase);
	mLinemeterActual = createLinemeterActual(mLinemeterSetpoint);
	mActualTempLabel = createActualTempLabel(mBase);
	mModeButton = MainScreen::createModeButton(mBase, MainScreen::modeIconCb);
	mModeIcon = MainScreen::createModeIcon(mModeButton, &calendar);
	mNextScreenButton = createNextScreenButton(mBase, MainScreen::nextScreenButtonCb);
}

void MainScreen::run(){
	uint16_t actual = GuiApp::getActual();
	lv_linemeter_set_value(mLinemeterActual, GuiApp::getActual());
	lv_linemeter_set_value(mLinemeterSetpoint, GuiApp::getSetpoint());
	if (actual == (uint16_t)GuiApp::InvalidValue) {
		lv_label_set_text_fmt(mActualTempLabel, "--°C");
	} else {
		lv_label_set_text_fmt(mActualTempLabel, "%d.%d°C", actual/10, actual%10);
	}


	setModeIcon(GuiApp::getMode());
}

void tempSettingOpen(void * scr){
	TempSetpointContainer::create(MainScreen::getBase());
}

void MainScreen::actualTempLabelCb(lv_obj_t *obj, lv_event_t event){
	if (event == LV_EVENT_CLICKED) {
		lv_async_call(tempSettingOpen, NULL);
		printf("Temperature setting container created\n");
	}
}

void MainScreen::setModeIcon(SchedulerApp::scheduler_mode_t mode) {
	switch (mode) {
	case SchedulerApp::scheduler_mode_t::ModeOff:
	     lv_obj_set_style_local_image_recolor(mModeIcon, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_GRAY);
	     lv_img_set_src(mModeIcon, &shutdown);
	     break;
	case SchedulerApp::scheduler_mode_t::ModeManual:
		lv_obj_set_style_local_image_recolor(mModeIcon, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);
		lv_img_set_src(mModeIcon, &shutdown);
		break;
	case SchedulerApp::scheduler_mode_t::ModeDaily:
		lv_obj_set_style_local_image_recolor(mModeIcon, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
		lv_img_set_src(mModeIcon, &clockicon);
		break;
	case SchedulerApp::scheduler_mode_t::ModeWeekly:
		lv_obj_set_style_local_image_recolor(mModeIcon, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
		lv_img_set_src(mModeIcon, &calendar);
		break;
	case SchedulerApp::scheduler_mode_t::ModeDeicing:
		lv_obj_set_style_local_image_recolor(mModeIcon, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, SNOWFLAKE_COLOR);
		lv_img_set_src(mModeIcon, &snowflake);
		break;
	default:
		printf("MainScreen::changeModeIcon Unknown mode\n");
		break;
	}
}

void MainScreen::modeIconCb(lv_obj_t *obj, lv_event_t event) {
	if (event == LV_EVENT_CLICKED) {
		GuiApp::incMode();
	}
}

void MainScreen::nextScreenButtonCb(lv_obj_t *obj, lv_event_t event) {
	if (event == LV_EVENT_CLICKED){
		GuiApp::changeScreen(GuiApp::MainScreenId);
	}
}

lv_obj_t* MainScreen::createActualTempLabel(lv_obj_t *par) {
    lv_obj_t* label = lv_label_create(par, NULL);
    lv_label_set_text(label, LV_SYMBOL_REFRESH);
    lv_obj_set_auto_realign(label, true);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_click(label, true);
    lv_obj_set_event_cb(label, MainScreen::actualTempLabelCb);

    lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_36);
    lv_obj_set_style_local_text_color(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);

	return label;
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
    lv_style_set_bg_color(&style, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
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
	lv_obj_t* icon = lv_img_create(par, NULL);
	lv_img_set_src(icon, img);
	lv_obj_set_style_local_image_recolor_opa(icon, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
	return icon;
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

