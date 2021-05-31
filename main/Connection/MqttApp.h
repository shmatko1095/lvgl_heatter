/*
 * MqttApp.h
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#ifndef MQTTAPP_H_
#define MQTTAPP_H_

#include "../Core/BaseTask.hpp"
#include "../IEventReceiver.hpp"
#include "mqtt_client.h"

class MqttApp : public IEventReceiver, public StaticBaseTask<2048>{
public:
	MqttApp();

	void run() override;

	void start();

	void stop();

	void onReceive(IEventReceiver::EventId event, void* params) override;

	static int publishMessage(const char *topic,
			const char *data, int len, int qos, int retain);

private:
	static esp_err_t eventHandler(esp_mqtt_event_handle_t event);
	static void subscribeHandlers();

	static esp_mqtt_client_handle_t mClient;
	Mutex mMtx;
};

#endif /* MQTTAPP_H_ */
