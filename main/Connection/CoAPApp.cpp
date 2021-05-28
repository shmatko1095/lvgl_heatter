/*
 * CoAPApp.cpp
 *
 *  Created on: May 22, 2021
 *      Author: f73377
 */

#include "../Connection/CoAPApp.h"

#include <string.h>
#include <sys/socket.h>
#include <sys/param.h>
#include <netdb.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "mqtt_client.h"

#define ESP_WIFI_SSID      		"OSH_2GHz"		// Please insert your SSID
#define ESP_WIFI_PASS      		"9b2fb11587358d3"		// Please insert your password
#define ESP_WIFI_AUTH_MODE		WIFI_AUTH_WPA2_PSK // See esp_wifi_types.h


static const char *TAG = "example";
//static const char *CONFIG_BROKER_URL = "tcp://192.168.88.239:1883";
static const char *CONFIG_BROKER_URL = "tcp://192.168.88.239";

/* FreeRTOS event group to signal when we are connected*/
static EventGroupHandle_t s_wifi_event_group;

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

static ip_event_got_ip_t* event = NULL;
static uint8_t u8RetryCounter = 0U;
static void mqtt_app_start(void);

static void WIFI_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        esp_wifi_connect();
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));

        mqtt_app_start();
    }
}


void wifi_init_sta(void)
{

	wifi_init_config_t sWifiInitCfg = WIFI_INIT_CONFIG_DEFAULT();
	esp_event_handler_instance_t instance_any_id;
	esp_event_handler_instance_t instance_got_ip;

	EventBits_t WifiEventBits = 0U;

    s_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    ESP_ERROR_CHECK(esp_wifi_init(&sWifiInitCfg));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &WIFI_event_handler,
                                                        NULL,
                                                        &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &WIFI_event_handler,
                                                        NULL,
                                                        &instance_got_ip));

    wifi_sta_config_t staConfig;
    strcpy((char*)staConfig.ssid, (char*)ESP_WIFI_SSID);
    strcpy((char*)staConfig.password, (char*)ESP_WIFI_PASS);
    staConfig.threshold.authmode = ESP_WIFI_AUTH_MODE;

    wifi_pmf_config_t pmfConfig;
    pmfConfig.capable = true;
	pmfConfig.required = false;
	staConfig.pmf_cfg = pmfConfig;

	wifi_config_t sWifiConfig;
	sWifiConfig.sta = staConfig;

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &sWifiConfig));
    ESP_ERROR_CHECK(esp_wifi_start());

//    ESP_LOGI(TAG, "Wi-Fi initializated");
//
//    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
//     * number of re-tries (WIFI_FAIL_BIT). The bits are set by wifi_event_handler() (see above) */
//    WifiEventBits = xEventGroupWaitBits(s_wifi_event_group, WIFI_CONNECTED_BIT | WIFI_FAIL_BIT, pdFALSE, pdFALSE, portMAX_DELAY);
//
//    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
//     * happened. */
//    if (WifiEventBits & WIFI_CONNECTED_BIT) {
//        ESP_LOGI(TAG, "Connected to access point SSID: %s, Password: %s", ESP_WIFI_SSID, ESP_WIFI_PASS);
//    } else if (WifiEventBits & WIFI_FAIL_BIT) {
//        ESP_LOGI(TAG, "Failed to connect to SSID: %s, Password: %s", ESP_WIFI_SSID, ESP_WIFI_PASS);
//    } else {
//        ESP_LOGE(TAG, "UNEXPECTED EVENT");
//    }
//
//    /* The event will not be processed after unregister */
//    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, instance_got_ip));
//    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, instance_any_id));
//
//    vEventGroupDelete(s_wifi_event_group);

}

static void log_error_if_nonzero(const char *message, int error_code)
{
    if (error_code != 0) {
        ESP_LOGE(TAG, "Last error %s: 0x%x", message, error_code);
    }
}

/*
 * @brief Event handler registered to receive MQTT events
 *
 *  This function is called by the MQTT client event loop.
 *
 * @param handler_args user data registered to the event.
 * @param base Event base for the handler(always MQTT Base in this example).
 * @param event_id The id for the received event.
 * @param event_data The data for the event, esp_mqtt_event_handle_t.
 */
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%d", base, event_id);
    esp_mqtt_event_handle_t event = (esp_mqtt_event_handle_t)event_data;
    esp_mqtt_client_handle_t client = event->client;
    int msg_id;
    switch ((esp_mqtt_event_id_t)event_id) {
    case MQTT_EVENT_CONNECTED:
    	msg_id = esp_mqtt_client_subscribe(client, "btn", 0);
    	msg_id = esp_mqtt_client_subscribe(client, "/btn", 0);

        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        msg_id = esp_mqtt_client_publish(client, "/topic/qos1", "data_3", 0, 1, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);

        msg_id = esp_mqtt_client_subscribe(client, "/topic/qos0", 0);
        ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);

        msg_id = esp_mqtt_client_subscribe(client, "/topic/qos1", 1);
        ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);

        msg_id = esp_mqtt_client_unsubscribe(client, "/topic/qos1");
        ESP_LOGI(TAG, "sent unsubscribe successful, msg_id=%d", msg_id);
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        break;

    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        msg_id = esp_mqtt_client_publish(client, "/topic/qos0", "data", 0, 0, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
        break;
    case MQTT_EVENT_UNSUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_DATA:
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");
        printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
        printf("DATA=%.*s\r\n", event->data_len, event->data);
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
        if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT) {
            log_error_if_nonzero("reported from esp-tls", event->error_handle->esp_tls_last_esp_err);
            log_error_if_nonzero("reported from tls stack", event->error_handle->esp_tls_stack_err);
            log_error_if_nonzero("captured as transport's socket errno",  event->error_handle->esp_transport_sock_errno);
            ESP_LOGI(TAG, "Last errno string (%s)", strerror(event->error_handle->esp_transport_sock_errno));

        }
        break;
    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}

static void mqtt_app_start(void)
{
    static esp_mqtt_client_config_t mqtt_cfg;
    mqtt_cfg.uri = CONFIG_BROKER_URL;

    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    /* The last argument may be used to pass data to the event handler, in this example mqtt_event_handler */
    esp_mqtt_client_register_event(client, (esp_mqtt_event_id_t)ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    esp_mqtt_client_start(client);
//    esp_mqtt_client_subscribe(client, "btn", 0);
}

void CoAPApp::CoAPAppMain(void){
//	ESP_ERROR_CHECK(esp_event_loop_create_default());
	wifi_init_sta();
//	mqtt_app_start();
}
