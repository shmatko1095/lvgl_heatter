/*
 * InfoScreen.cpp
 *
 *  Created on: May 15, 2021
 *      Author: f73377
 */

#include "GuiApp.h"
#include "InfoScreen.h"
#include "Colors.hpp"
#include "TempSetpointContainer.h"

lv_obj_t* InfoScreen::mBase = nullptr;

void InfoScreen::tempSettingOpen(void* scr){
	TempSetpointContainer::create(InfoScreen::getBase());
}

void InfoScreen::actualTempLabelCb(lv_obj_t *obj, lv_event_t event) {
	if (event == LV_EVENT_CLICKED) {
		lv_async_call(InfoScreen::tempSettingOpen, NULL);
	}
}

void InfoScreen::nextScreenButtonCb(lv_obj_t *obj, lv_event_t event) {
   	if (event == LV_EVENT_CLICKED){
   		GuiApp::changeScreen(GuiApp::InfoScreenId);
   	}
}

///TMP void to show circle display;
/// should be removed in production display
static lv_obj_t* createLinemeterSetpoint(lv_obj_t *par) {
	static lv_style_t style_box;
	lv_style_init(&style_box);
	lv_style_set_bg_color(&style_box, LV_STATE_DEFAULT, BG_COLOR/*LV_COLOR_BLACK*/);
	lv_style_set_line_opa(&style_box, LV_STATE_DEFAULT, LV_OPA_0);

	lv_obj_t *linemeter = lv_linemeter_create(par, NULL);
	lv_obj_set_size(linemeter, LV_HOR_RES, LV_VER_RES);
	lv_obj_align(linemeter, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_style(linemeter, LV_LINEMETER_PART_MAIN, &style_box);
	return linemeter;
}


void InfoScreen::init(){
	mBase = createBase();
	mBase = createLinemeterSetpoint(mBase);

	mActualTempLabel = createActualTempLabel(mBase);
	mNextScreenButton = createNextScreenButton(mBase, nextScreenButtonCb);
	mContainer = createMeterContainer(mBase);


	Meter inTemp(mContainer);
	Meter outTemp(mContainer);
	Meter loadTemp(mContainer);
	Meter pressureTemp(mContainer);

    mInTemp = &inTemp;
    mOutTemp = &outTemp;
    mLoadMeter = &loadTemp;
    mPressure = &pressureTemp;

    mInTemp->setValue(28.3);
    mOutTemp->setValue(30.2);
    mLoadMeter->setValue(75);
    mPressure->setValue(1.3);
}

void InfoScreen::run(){
	uint16_t actual = GuiApp::getActual();
	if (actual == GuiApp::InvalidValue) {
		lv_label_set_text_fmt(mActualTempLabel, "--°C");
	} else {
		lv_label_set_text_fmt(mActualTempLabel, "%d.%d°C", actual/10, actual%10);
	}
}

lv_obj_t* InfoScreen::createActualTempLabel(lv_obj_t *par) {
    lv_obj_t* btn = lv_btn_create(par, NULL);
    lv_obj_set_event_cb(btn, InfoScreen::actualTempLabelCb);
    lv_obj_set_size(btn, 90, 30);
    lv_obj_set_style_local_border_width(btn, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(btn, LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_bg_color(btn, LV_BTN_PART_MAIN, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
	lv_obj_align(btn, NULL, LV_ALIGN_IN_TOP_MID, 0, 15);

	lv_obj_t* label = lv_label_create(btn, NULL);
	lv_obj_set_style_local_text_font(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_montserrat_20);
    lv_label_set_text(label, LV_SYMBOL_REFRESH);

	return label;
}

lv_obj_t* InfoScreen::createMeterContainer(lv_obj_t* par) {
    lv_obj_t* cont = lv_cont_create(par, NULL);
    lv_obj_set_size(cont, 240, 160);
    lv_obj_align(cont, NULL, LV_ALIGN_CENTER, 10, 0);
    lv_obj_set_style_local_bg_opa(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_0);
    lv_obj_set_style_local_border_opa(cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_0);
    lv_obj_set_auto_realign(cont, false);                    /*Auto realign when the size changes*/
//    lv_obj_align_origo(cont, NULL, LV_ALIGN_CENTER, 0, 0);  /*This parametrs will be sued when realigned*/
//    lv_cont_set_fit(cont, LV_FIT_TIGHT);
    lv_cont_set_layout(cont, LV_LAYOUT_GRID);

    return cont;
}

lv_obj_t* InfoScreen::createChart(lv_obj_t* par) {
	 lv_obj_t * chart = lv_chart_create(par, NULL);
	 lv_obj_set_size(chart, 180, 150);
	 lv_obj_align(chart, NULL, LV_ALIGN_CENTER, 0, 0);
	 lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
	 lv_chart_set_point_count(chart, 10);
	 lv_chart_set_range(chart, 0, 100);

	 lv_obj_set_style_local_text_font(chart, LV_CHART_PART_SERIES_BG, LV_STATE_DEFAULT, lv_theme_get_font_small());
	 lv_obj_set_style_local_value_str(chart, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Line chart");
	 lv_chart_set_div_line_count(chart, 3, 12);

	 lv_obj_set_style_local_pad_left(chart,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 1 * (LV_DPI / 10));
	 lv_obj_set_style_local_pad_bottom(chart,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 3 * (LV_DPI / 10));
	 lv_obj_set_style_local_pad_right(chart,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 1 * (LV_DPI / 10));
	 lv_obj_set_style_local_pad_top(chart,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 1 * (LV_DPI / 10));
	 lv_chart_set_x_tick_length(chart, 0, 0);
     lv_chart_set_x_tick_texts(chart, "0\n1\n2\n3\n4\n5\n6\n6\n7\n8\n9\n10\n11\n12\n", 0, LV_CHART_AXIS_DRAW_LAST_TICK);


//	lv_obj_set_style_local_bg_opa(chart, LV_CHART_PART_BG, LV_STATE_DEFAULT, LV_OPA_10);
//	lv_obj_set_style_local_bg_opa(chart, LV_CHART_PART_SERIES_BG, LV_STATE_DEFAULT, LV_OPA_100);
//	lv_obj_set_style_local_pad_inner(chart, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, 0);
	lv_obj_set_style_local_bg_opa(chart, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, LV_OPA_80);
	lv_obj_set_style_local_bg_grad_dir(chart, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_obj_set_style_local_bg_main_stop(chart, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, 255);
	lv_obj_set_style_local_bg_grad_stop(chart, LV_CHART_PART_SERIES, LV_STATE_DEFAULT, 50);

//    lv_chart_series_t * ser1 = lv_chart_add_series(chart, LV_COLOR_RED);
    lv_chart_series_t * ser2 = lv_chart_add_series(chart, LV_COLOR_ORANGE);
//
//    /*Set the next points on 'ser1'*/
//    lv_chart_set_next(chart, ser1, 10);
//    lv_chart_set_next(chart, ser1, 10);
//    lv_chart_set_next(chart, ser1, 10);
//    lv_chart_set_next(chart, ser1, 10);
//    lv_chart_set_next(chart, ser1, 10);
//    lv_chart_set_next(chart, ser1, 10);
//    lv_chart_set_next(chart, ser1, 10);
//    lv_chart_set_next(chart, ser1, 30);
//    lv_chart_set_next(chart, ser1, 70);
//    lv_chart_set_next(chart, ser1, 90);

    ser2->points[0] = 90;
    ser2->points[1] = 90;
    ser2->points[2] = 0;
    ser2->points[3] = 0;
    ser2->points[4] = 60;
    ser2->points[5] = 60;
    ser2->points[6] = 0;
    ser2->points[7] = 0;
    ser2->points[8] = 30;
    ser2->points[9] = 30;

    lv_chart_refresh(chart);
    return chart;
}
