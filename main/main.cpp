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

#include "GuiApp/GuiApp.h"
#include "Model.hpp"
#include "SdStorrage.h"

#define GUI_TASK_STACK_SIZE 2*4096
#define GUI_TASK_PRIORITY 1
#define GUI_TASK_CORE 0

#ifdef __cplusplus
extern "C" {
#endif

void app_main() {
	Model::preinit();
	Model::init();

	GuiApp::init();
	SdStorrage::init();

	GuiApp::start(GUI_TASK_STACK_SIZE, GUI_TASK_PRIORITY, GUI_TASK_CORE);
	SdStorrage::start();
}

#ifdef __cplusplus
}
#endif

