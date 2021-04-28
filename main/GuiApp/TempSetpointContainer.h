/*
 * TempSetpointContainer.h
 *
 *  Created on: Apr 28, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_TEMPSETPOINTCONTAINER_H_
#define GUIAPP_TEMPSETPOINTCONTAINER_H_

#include "lvgl.h"
#include "Colors.hpp"
#include "../Types.h"

class TempSetpointContainer {
public:
	static void create(lv_obj_t* par);

	static lv_obj_t* mContainerBase;
private:
//	static lv_obj_t* createTempSetpointContainer(lv_obj_t* par);
//
//	static lv_obj_t* openRollerLabel(lv_obj_t* par);
//
//	static lv_obj_t* openRoller(lv_obj_t* par, lv_event_cb_t event_cb, lv_coord_t x_ofs, lv_coord_t y_ofs);
//	static lv_obj_t* createCancelButton(lv_obj_t* par, lv_event_cb_t event_cb);
//	static lv_obj_t* createOkButton(lv_obj_t* par, lv_event_cb_t event_cb);
//
//	static lv_obj_t* mRoller;
//	static lv_obj_t* mDecRoller;

};

#endif /* GUIAPP_TEMPSETPOINTCONTAINER_H_ */
