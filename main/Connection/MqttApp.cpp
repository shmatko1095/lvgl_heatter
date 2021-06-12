/*
 * MqttApp.cpp
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#include "../Core/Mutex.hpp"
#include "../Connection/MqttApp.h"
#include "../EventController.h"
#include "MqttEventController.h"
#include "esp_log.h"
#include "esp_task_wdt.h"

bool MqttApp::mIsConnected = false;
esp_mqtt_client_handle_t MqttApp::mClient;

static const char *TAG = "MqttApp";
static const char *CLIENT_ID = "osh_heatters01";
static const char *BROKER_URL = "mqtt://192.168.88.239:1883";
static void log_error_if_nonzero(const char *message, int error_code);

MqttApp::MqttApp() {
//	create("MqttApp", 0, 1);
	EventController::registerReceiver(*this);
}

static bool isReady = false;

//void MqttApp::run() {
//	while (1) {
//		vTaskDelay(pdMS_TO_TICKS(1000));
//		if(isReady == true){
//		}
//	}
//}

void MqttApp::start() {
//	mMtx.lock();
    static esp_mqtt_client_config_t config;
    config.uri = BROKER_URL;
    config.client_id = CLIENT_ID;
	config.event_handle = MqttApp::eventHandler;
    mClient = esp_mqtt_client_init(&config);
    esp_mqtt_client_start(mClient);
//    mMtx.unlock();
}

void MqttApp::stop() {
	esp_mqtt_client_destroy(mClient);
}

int MqttApp::publishMessage(const char *topic,
		const char *data, int len, int qos, int retain){
	int result = -1;
	if (mIsConnected) {
		result = esp_mqtt_client_publish(mClient, topic, data, len, qos, retain);
	}
	return result;
}

void MqttApp::onReceive(IEventReceiver::EventId event, void* params) {
	if (event == WifiGotIp) {
		start();
	}
}

void MqttApp::subscribeHandlers() {
	List::Itterator handlerItt = MqttEventController::getHandlers().getItterator();
	while(handlerItt) {
	   	MqttEventReceiver* receiver = &containerOf(*(handlerItt++), &MqttEventReceiver::mItem);
	   	List::Itterator topicItt = receiver->getTopicList().getItterator();
	   	while(topicItt) {
	   		MqttEventReceiver::MqttTopicDesc* desc =
	   				&containerOf(*(topicItt++), &MqttEventReceiver::MqttTopicDesc::mItem);
	   		esp_mqtt_client_subscribe(mClient, desc->getTopicIn(), desc->getQos());
	   	}
	}
}

esp_err_t MqttApp::eventHandler(esp_mqtt_event_handle_t event) {
    esp_mqtt_client_handle_t client = event->client;
    int msg_id;
    switch (event->event_id) {
    case MQTT_EVENT_CONNECTED:
    	mIsConnected = true;
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        EventController::pushEvent(EventId::MqttConnected, &event);
        subscribeHandlers();
        break;
    case MQTT_EVENT_DISCONNECTED:
    	mIsConnected = false;
    	EventController::pushEvent(EventId::MqttDisconnected, &event);
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        break;
    case MQTT_EVENT_SUBSCRIBED:
    	EventController::pushEvent(EventId::MqttSubscribes, &event);

        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        msg_id = esp_mqtt_client_publish(client, "/topic/qos0", "data", 0, 0, 0);
        ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
        isReady = true;
        break;
    case MQTT_EVENT_UNSUBSCRIBED:
    	EventController::pushEvent(EventId::MqttUnsubscribes, &event);
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_PUBLISHED:
    	EventController::pushEvent(EventId::MqttPublished, &event);
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_DATA:
    	EventController::pushEvent(EventId::MqttData, &event);
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");
        MqttEventController::pushEvent(event->topic, event->topic_len,
        		event->data, event->data_len);
        printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
        printf("DATA=%.*s\r\n", event->data_len, event->data);
        break;
    case MQTT_EVENT_ERROR:
    	EventController::pushEvent(EventId::MqttError, &event);
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
    return ESP_OK;
}

static void log_error_if_nonzero(const char *message, int error_code) {
    if (error_code != 0) {
        ESP_LOGE(TAG, "Last error %s: 0x%x", message, error_code);
    }
}
