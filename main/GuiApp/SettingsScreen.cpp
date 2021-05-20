/*
 * SettingsScreen.cpp
 *
 *  Created on: May 20, 2021
 *      Author: f73377
 */

#include "GuiApp.h"
#include "SettingsScreen.h"
#include "Colors.hpp"

lv_obj_t* SettingsScreen::mBase = nullptr;

const static lv_coord_t ACTIVE_HOR = 160;
const static lv_coord_t ACTIVE_VER = 160;

void SettingsScreen::nextScreenButtonCb(lv_obj_t *obj, lv_event_t event) {
   	if (event == LV_EVENT_CLICKED){
   		GuiApp::changeScreen(GuiApp::SettingsScreenId);
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

void lv_ex_tileview_1(lv_obj_t * par) {
    static lv_point_t valid_pos[] = {{0,0},
    								 {0,1}, {1,1}};
    lv_obj_t* tileview = lv_tileview_create(par, NULL);
    lv_obj_set_size(tileview, ACTIVE_HOR, ACTIVE_VER);
    lv_obj_align(tileview, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_tileview_set_valid_positions(tileview, valid_pos, 3);
    lv_tileview_set_edge_flash(tileview, true);
    lv_obj_set_style_local_bg_opa(tileview, LV_TILEVIEW_PART_SCROLLBAR,
    		LV_STATE_DEFAULT, LV_OPA_20);

    lv_obj_t* tile1 = lv_obj_create(tileview, NULL);
    lv_obj_set_size(tile1, ACTIVE_HOR, ACTIVE_VER);
    lv_tileview_add_element(tileview, tile1);

    /*Tile1: just a label*/
    lv_obj_t* label = lv_label_create(tile1, NULL);
    lv_label_set_text(label, "Scroll down");
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

    /*Tile2: a list*/
    lv_obj_t* list = lv_list_create(tileview, NULL);
    lv_obj_set_size(list, ACTIVE_HOR, ACTIVE_VER);
    lv_obj_set_pos(list, 0, ACTIVE_VER);
    lv_list_set_scroll_propagation(list, true);
    lv_list_set_scrollbar_mode(list, LV_SCROLLBAR_MODE_OFF);

    lv_list_add_btn(list, NULL, "One");
    lv_list_add_btn(list, NULL, "Two");
    lv_list_add_btn(list, NULL, "Three");
    lv_list_add_btn(list, NULL, "Four");
    lv_list_add_btn(list, NULL, "Five");
    lv_list_add_btn(list, NULL, "Six");
    lv_list_add_btn(list, NULL, "Seven");
    lv_list_add_btn(list, NULL, "Eight");

    /*Tile3: a button*/
    lv_obj_t* tile3 = lv_obj_create(tileview, tile1);
    lv_obj_set_pos(tile3, ACTIVE_HOR, ACTIVE_VER);
    lv_tileview_add_element(tileview, tile3);

    lv_obj_t* btn = lv_btn_create(tile3, NULL);
    lv_obj_align(btn, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_tileview_add_element(tileview, btn);
    label = lv_label_create(btn, NULL);
    lv_label_set_text(label, "No scroll up");
}


void SettingsScreen::init(){
	mBase = createBase();
	mBase = createLinemeterSetpoint(mBase);
	mNextScreenButton = createNextScreenButton(mBase, nextScreenButtonCb);
//	mContainer = createMeterContainer(mBase);
//	lv_ex_tileview_1(mBase);

}

void SettingsScreen::run(){
//	uint16_t actual = GuiApp::getActual();
//	if (actual == GuiApp::InvalidValue) {
//		lv_label_set_text_fmt(mActualTempLabel, "--°C");
//	} else {
//		lv_label_set_text_fmt(mActualTempLabel, "%d.%d°C", actual/10, actual%10);
//	}
	static bool init = false;
	if (!init){
	lv_ex_tileview_1(mBase);
	init = true;
	}
}

lv_obj_t* SettingsScreen::createMeterContainer(lv_obj_t* par) {
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



