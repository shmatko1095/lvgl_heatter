/*
 * TempSetpointContainer.cpp
 *
 *  Created on: Apr 28, 2021
 *      Author: f73377
 */

#include "esp_system.h"
#include "TempSetpointContainer.h"
#include "GuiApp.h"
#include <string>

lv_obj_t* TempSetpointContainer::mContainerBase = nullptr;
static uint16_t rollerSetpoint = 0;

static const char *tempRollerOptions =
		" 10\n10.5\n 11\n11.5\n 12\n12.5\n 13\n13.5\n 14\n14.5\n 15\n15.5\n 16\n16.5\n 17\n17.5\n 18\n18.5\n 19\n19.5\n 20\n20.5\n 21\n21.5\n 22\n22.5\n 23\n23.5\n 24\n24.5\n 25\n25.5\n 26\n26.5\n 27\n27.5\n 28\n28.5\n 29\n29.5\n 30\n30.5\n 31\n31.5\n 32\n32.5\n 33\n33.5\n 34\n34.5\n 35\n35.5\n 36\n36.5\n 37\n37.5\n 38\n38.5\n 39\n39.5\n40";
static const int16_t intRollerOptions[] =
		{100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195, 200, 205, 210, 215, 220, 225, 230, 235, 240, 245, 250, 255, 260,	265, 270, 275, 280, 285, 290, 295, 300,	305, 310, 315, 320,	325, 330, 335, 340,	345, 350, 355, 360,	365, 370, 375, 380,	385, 390, 395, 400};


static void rollerHandler(lv_obj_t* obj, lv_event_t event);
static void keepModeBtnHandler(lv_obj_t* obj, lv_event_t event);
static void goToManualBtnHandler(lv_obj_t* obj, lv_event_t event);
static void cancelBtnHandler(lv_obj_t* obj, lv_event_t event);

static lv_obj_t* createTempSetpointContainer(lv_obj_t* par);
static lv_obj_t* createButtonKeepCurrent(lv_obj_t* par);
static lv_obj_t* createButtonGoToManual(lv_obj_t* par);
static lv_obj_t* createCancelButton(lv_obj_t* par, lv_event_cb_t event_cb);
static lv_obj_t* openRoller(lv_obj_t* par);
static lv_obj_t* openRollerLabel(lv_obj_t* par);

void TempSetpointContainer::create(lv_obj_t* par) {
	mContainerBase = createTempSetpointContainer(par);
	openRollerLabel(mContainerBase);
	openRoller(mContainerBase);
	createButtonKeepCurrent(mContainerBase);
	createButtonGoToManual(mContainerBase);
	createCancelButton(mContainerBase, cancelBtnHandler);
}

static void rollerHandler(lv_obj_t* obj, lv_event_t event) {
	if(event == LV_EVENT_VALUE_CHANGED) {
		char buf[10];
	    lv_roller_get_selected_str(obj, buf, sizeof(buf));
	    float tmp = std::stof(buf);
	    rollerSetpoint = tmp*10;
	}
}

static void keepModeBtnHandler(lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
    	GuiApp::changeSetpoint(rollerSetpoint, false);
    	lv_obj_del(TempSetpointContainer::mContainerBase);
    }
}

static void goToManualBtnHandler(lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
    	GuiApp::changeSetpoint(rollerSetpoint, true);
    	lv_obj_del(TempSetpointContainer::mContainerBase);
    }
}

static void cancelBtnHandler(lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
    	lv_obj_del(TempSetpointContainer::mContainerBase);
    }
}

static lv_obj_t* createTempSetpointContainer(lv_obj_t* par) {
    lv_obj_t * cont = lv_cont_create(par, NULL);
    lv_obj_set_size(cont, 200, 150);
    lv_obj_align(cont, NULL, LV_ALIGN_CENTER, 0, 0);
    return cont;
}

static lv_obj_t* createButtonKeepCurrent(lv_obj_t* par) {
    lv_obj_t* btn = lv_btn_create(par, NULL);
    lv_obj_set_event_cb(btn, keepModeBtnHandler);
    lv_obj_set_size(btn, 85, 30);
    lv_obj_align(btn, par, LV_ALIGN_IN_BOTTOM_MID, 50, -10);

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, LV_STATE_DEFAULT, GREEN_BTN_COLOR);
    lv_style_set_bg_color(&style, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
    lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_width(&style, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style);

    lv_obj_t* label = lv_label_create(par, NULL);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SROLL_CIRC);
    lv_label_set_anim_speed(label, 15);
    lv_obj_set_width(label, 75);
    lv_obj_align(label, par, LV_ALIGN_IN_BOTTOM_MID, 50, -16);
    lv_label_set_text(label, "Keep current");
    return btn;
}

static lv_obj_t* createButtonGoToManual(lv_obj_t* par) {
    lv_obj_t* btn = lv_btn_create(par, NULL);
    lv_obj_set_event_cb(btn, goToManualBtnHandler);
    lv_obj_set_size(btn, 85, 30);
    lv_obj_align(btn, par, LV_ALIGN_IN_BOTTOM_MID, -50, -10);

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, LV_STATE_DEFAULT, BLUE_BTN_COLOR);
    lv_style_set_bg_color(&style, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
    lv_style_set_text_color(&style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_border_width(&style, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &style);

    lv_obj_t* label = lv_label_create(par, NULL);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SROLL_CIRC);
    lv_label_set_anim_speed(label, 15);
    lv_obj_set_width(label, 75);
    lv_obj_align(label, par, LV_ALIGN_IN_BOTTOM_MID, -50, -16);
    lv_label_set_text(label, "Go to manual");
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
    lv_roller_set_selected(roller, 10, LV_ANIM_ON);
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


	uint16_t optNum = 0;
	int16_t setpoint = GuiApp::getSetpoint();
	for (int16_t option : intRollerOptions){
		int16_t oldOption = 0;
		if (setpoint >= oldOption && setpoint <= option) {
			break;
		}
		oldOption = option;
		optNum++;
	}
	lv_roller_set_selected(roller, optNum, LV_ANIM_OFF);


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

