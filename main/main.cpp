/* LVGL Example project
 *
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */

#include "GuiApp/include/GuiApp.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>
#include "Model.hpp"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#define TAG "demo"

#ifdef __cplusplus
extern "C" {
#endif

void app_main() {
	Model::preinit();
	Model::init();

//	    xPortStartScheduler()

	/* If you want to use a task to create the graphic, you NEED to create a Pinned task
	 * Otherwise there can be problem such as memory corruption and so on.
	 * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */
	xTaskCreatePinnedToCore(guiApp, "gui", 4096 * 2, NULL, 0, NULL, 1);

}
#ifdef __cplusplus
}
#endif

