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

#include "Connection/WifiManager.h"
#include "Connection/CoAPApp.h"
#include "Connection/MqttApp.h"
#include "SchedulerApp.h"
#include "GuiApp/GuiApp.h"
#include "EventController.h"
#include "Model.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#define ESP_WIFI_SSID   "OSH_2GHz"
#define ESP_WIFI_PASS	"9b2fb11587358d3"

void app_main(void) {
    vTaskDelay(pdMS_TO_TICKS(100));

    Model::preinit();
    Model::init();

    static CredentialsDesc cred(ESP_WIFI_SSID, ESP_WIFI_PASS, WIFI_AUTH_WPA2_PSK);
    WifiManager::getInstance()->init();
    WifiManager::getInstance()->enable();
    WifiManager::getInstance()->setConfig(cred);
    WifiManager::getInstance()->connect();
    static MqttApp mqtt = MqttApp();

    static SchedulerApp schedulerUl = SchedulerApp();
    static GuiApp guiApp = GuiApp(&schedulerUl);
}


#ifdef __cplusplus
}
#endif

