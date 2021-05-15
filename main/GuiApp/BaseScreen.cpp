/*
 * BaseScreen.cpp
 *
 *  Created on: May 15, 2021
 *      Author: f73377
 */

#include "BaseScreen.h"

LV_IMG_DECLARE(more);

lv_obj_t* BaseScreen::createBase() {
	lv_obj_t* base = lv_obj_create(NULL, NULL);
	lv_style_init(&mBaseStyleBox);
	lv_style_set_bg_color(&mBaseStyleBox, LV_STATE_DEFAULT, LV_COLOR_BLACK);
	lv_obj_add_style(base, LV_OBJ_PART_MAIN, &mBaseStyleBox);
	return base;
}

lv_obj_t* BaseScreen::createNextScreenButton(lv_obj_t *par, lv_event_cb_t cb) {
    lv_obj_t* btn = lv_btn_create(par, NULL);
    lv_obj_set_event_cb(btn, cb);
    lv_obj_set_size(btn, button_w, button_h);
    lv_obj_align(btn, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);

    lv_style_init(&mNextScreenButtonStyleBox);
    lv_style_set_bg_opa(&mNextScreenButtonStyleBox, LV_STATE_DEFAULT, 0);
    lv_style_set_bg_opa(&mNextScreenButtonStyleBox, LV_STATE_PRESSED, LV_OPA_80);
    lv_style_set_bg_color(&mNextScreenButtonStyleBox, LV_STATE_PRESSED, PRESSED_BTN_COLOR);
    lv_style_set_border_width(&mNextScreenButtonStyleBox, LV_STATE_DEFAULT, 0);
    lv_style_set_outline_width(&mNextScreenButtonStyleBox, LV_STATE_DEFAULT, 0);
    lv_obj_add_style(btn, LV_BTN_PART_MAIN, &mNextScreenButtonStyleBox);

    mNextScreenButtonImg = lv_img_create(btn, NULL);
    lv_img_set_src(mNextScreenButtonImg, &more);
    lv_obj_set_style_local_image_opa(mNextScreenButtonImg, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_40);
	return btn;
}
