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
#include "../Common/Types.h"

class TempSetpointContainer {
public:
	static void create(lv_obj_t* par);

	static lv_obj_t* mContainerBase;

};

#endif /* GUIAPP_TEMPSETPOINTCONTAINER_H_ */
