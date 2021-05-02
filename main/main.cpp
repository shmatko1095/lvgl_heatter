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

#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_err.h"

#include "GuiApp/GuiApp.h"
#include "Model.hpp"
#include "SdStorrage.h"
#include "TaskExample.hpp"

#define GUI_TASK_STACK_SIZE 2*4096
#define GUI_TASK_PRIORITY 1
#define GUI_TASK_CORE 0
//
#ifdef __cplusplus
extern "C" {
#endif

void app_main(void)
{
    vTaskDelay(pdMS_TO_TICKS(100));

    Model::preinit();
    Model::init();

    static TaskExample example = TaskExample();
    static TaskExample example2 = TaskExample();

    static GuiApp guiApp = GuiApp();

//	SdStorrage::init();
//	SdStorrage::start();

}


#ifdef __cplusplus
}
#endif

