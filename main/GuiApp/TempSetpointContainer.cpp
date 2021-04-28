/*
 * TempSetpointContainer.cpp
 *
 *  Created on: Apr 28, 2021
 *      Author: f73377
 */

#include "esp_system.h"
#include "TempSetpointContainer.h"

lv_obj_t* TempSetpointContainer::mContainerBase = nullptr;

static const char *tempRollerOptions =
		" 10\n10.5\n 11\n11.5\n 12\n12.5\n 13\n13.5\n 14\n14.5\n 15\n15.5\n 16\n16.5\n 17\n17.5\n 18\n18.5\n 19\n19.5\n 20\n20.5\n 21\n21.5\n 22\n22.5\n 23\n23.5\n 24\n24.5\n 25\n25.5\n 26\n26.5\n 27\n27.5\n 28\n28.5\n 29\n29.5\n 30\n30.5\n 31\n31.5\n 32\n32.5\n 33\n33.5\n 34\n34.5\n 35\n35.5\n 36\n36.5\n 37\n37.5\n 38\n38.5\n 39\n39.5";

static void rollerHandler(lv_obj_t * obj, lv_event_t event);
static void autoBtnHandler(lv_obj_t * obj, lv_event_t event);
static void manualBtnHandler(lv_obj_t * obj, lv_event_t event);
static void cancelBtnHandler(lv_obj_t * obj, lv_event_t event);

static lv_obj_t* createTempSetpointContainer(lv_obj_t* par);
static lv_obj_t* createAutoButton(lv_obj_t* par, lv_event_cb_t event_cb);
static lv_obj_t* createManualButton(lv_obj_t* par, lv_event_cb_t event_cb);
static lv_obj_t* createCancelButton(lv_obj_t* par, lv_event_cb_t event_cb);
static lv_obj_t* openRoller(lv_obj_t* par);
static lv_obj_t* openRollerLabel(lv_obj_t* par);

void TempSetpointContainer::create(lv_obj_t* par) {
	mContainerBase = createTempSetpointContainer(par);
	openRollerLabel(mContainerBase);
	openRoller(mContainerBase);
	createAutoButton(mContainerBase, autoBtnHandler);
	createManualButton(mContainerBase, manualBtnHandler);
	createCancelButton(mContainerBase, cancelBtnHandler);
}

lv_obj_t* createTempSetpointContainer(lv_obj_t* par) {
    lv_obj_t * cont = lv_cont_create(par, NULL);
    lv_obj_set_size(cont, 200, 150);
    lv_obj_align(cont, NULL, LV_ALIGN_CENTER, 0, 0);
    return cont;
}

static void rollerHandler(lv_obj_t * obj, lv_event_t event){
}

static void autoBtnHandler(lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
    	//Do something
    	lv_obj_del(TempSetpointContainer::mContainerBase);
    }
}

static void manualBtnHandler(lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
    	//Do something
    	lv_obj_del(TempSetpointContainer::mContainerBase);
    }
}

static void cancelBtnHandler(lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
    	lv_obj_del(TempSetpointContainer::mContainerBase);
    }
}

static lv_obj_t* createAutoButton(lv_obj_t* par, lv_event_cb_t event_cb) {
    lv_obj_t * btn = lv_btn_create(par, NULL);
    lv_obj_set_event_cb(btn, event_cb);
    lv_obj_set_size(btn, 80, 30);
    lv_obj_align(btn, par, LV_ALIGN_IN_BOTTOM_LEFT, 15, -10);

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, LV_STATE_DEFAULT, OK_BTN_COLOR);
    lv_style_set_bg_color(&style, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
    lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_width(&style, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style);

    lv_obj_t * label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Ok");
    return btn;
}

static lv_obj_t* createManualButton(lv_obj_t* par, lv_event_cb_t event_cb) {
    lv_obj_t * btn = lv_btn_create(par, NULL);
    lv_obj_set_event_cb(btn, event_cb);
    lv_obj_set_size(btn, 80, 30);
    lv_obj_align(btn, par, LV_ALIGN_IN_BOTTOM_RIGHT, -15, -10);

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, LV_STATE_DEFAULT, CANCEL_BTN_COLOR);
    lv_style_set_bg_color(&style, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
    lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_width(&style, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style);

    lv_obj_t * label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "Cancel");
    return btn;
}

static lv_obj_t* createCancelButton(lv_obj_t* par, lv_event_cb_t event_cb) {
    lv_obj_t * btn = lv_btn_create(par, NULL);
    lv_obj_set_event_cb(btn, event_cb);
    lv_obj_set_size(btn, 40, 40);
    lv_obj_align(btn, par, LV_ALIGN_IN_TOP_RIGHT, 0, 0);

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
    lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    lv_style_set_border_width(&style, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style);

    lv_obj_t * label = lv_label_create(btn, NULL);
    lv_label_set_text(label, LV_SYMBOL_CLOSE);
    return btn;
}

static lv_obj_t* openRoller(lv_obj_t* par) {
    lv_obj_t *roller = lv_roller_create(par, NULL);
    lv_roller_set_options(roller, tempRollerOptions, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller, 3);
    lv_roller_set_fix_width(roller, 80);
    lv_obj_align(roller, par, LV_ALIGN_CENTER, -30, -20);
    lv_obj_set_event_cb(roller, rollerHandler);

	static lv_style_t selectedDtyle;
	lv_style_init(&selectedDtyle);
	lv_style_set_text_font(&selectedDtyle, LV_STATE_DEFAULT, &lv_font_montserrat_36);
	lv_style_set_text_color(&selectedDtyle, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_bg_color(&selectedDtyle, LV_STATE_DEFAULT, LV_COLOR_WHITE);
	lv_obj_add_style(roller, LV_ROLLER_PART_SELECTED, &selectedDtyle);

	static lv_style_t bgStyle;
	lv_style_init(&bgStyle);
	lv_style_set_text_color(&bgStyle, LV_STATE_DEFAULT, LV_COLOR_GRAY);
	lv_style_set_border_width(&bgStyle, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(roller, LV_ROLLER_PART_BG, &bgStyle);

    return roller;
}

static lv_obj_t* openRollerLabel(lv_obj_t* par) {
	static lv_style_t style;
	lv_style_init(&style);
	lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_style_set_text_font(&style, LV_STATE_DEFAULT, &lv_font_montserrat_36);

    lv_obj_t* label = lv_label_create(par, NULL);
    lv_label_set_text(label, "°C");
    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(label, par, LV_ALIGN_CENTER, 20, -37);
    lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style);

    return label;
}

