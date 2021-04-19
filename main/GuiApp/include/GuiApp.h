/*
 * exampleGuiTask.h
 *
 *  Created on: Apr 12, 2021
 *      Author: f73377
 */

#include "../../Types.h"
#include "freertos/FreeRTOS.h"

#ifndef MAIN_GUIAPP_GUIAPP_H_
#define MAIN_GUIAPP_GUIAPP_H_

#ifdef __cplusplus
extern "C" {
#endif

void guiApp_init();

void guiApp_start(const uint32_t usStackDepth, UBaseType_t uxPriority,
		const BaseType_t xCoreID);

#ifdef __cplusplus
}
#endif

#endif /* MAIN_GUIAPP_GUIAPP_H_ */
