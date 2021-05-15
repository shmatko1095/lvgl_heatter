/*
 * InfoScreen.cpp
 *
 *  Created on: May 15, 2021
 *      Author: f73377
 */

#include "GuiApp.h"
#include "InfoScreen.h"

lv_obj_t* InfoScreen::mBase = nullptr;


void InfoScreen::init(){
	mBase = createBase();
	mNextScreenButton = createNextScreenButton(mBase, nextScreenButtonCb);
}

void InfoScreen::run(){

}

void InfoScreen::nextScreenButtonCb(lv_obj_t *obj, lv_event_t event) {
   	if (event == LV_EVENT_CLICKED){
   		GuiApp::changeScreen(GuiApp::InfoScreenId);
   	}
}

