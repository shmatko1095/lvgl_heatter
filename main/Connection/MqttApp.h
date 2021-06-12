/*
 * MqttApp.h
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#ifndef MQTTAPP_H_
#define MQTTAPP_H_

#include "../Core/Mutex.hpp"
#include "../Core/BaseTask.hpp"
#include "../IEventReceiver.hpp"
#include "MqttEventReceiver.hpp"
#include "mqtt_client.h"

//class MqttApp : public IEventReceiver, public StaticBaseTask<2048>{
class MqttApp : public IEventReceiver{
public:
	MqttApp();

//	void run() override;

	void start();

	void stop();

	void onReceive(IEventReceiver::EventId event, void* params) override;

	static int publishMessage(const char *topic,
			const char *data, int len, int qos, int retain);

	static int publishMessage(MqttEventReceiver::MqttTopicDesc desc, int val) {
		static char data[11];
		int len = sprintf(data, "%d", val);
		return publishMessage(desc.getTopicOut(), data, len, desc.getQos(), 0);
	}

private:
	static esp_err_t eventHandler(esp_mqtt_event_handle_t event);
	static void subscribeHandlers();

	static bool mIsConnected;
	static esp_mqtt_client_handle_t mClient;
//	Mutex mMtx;
};

#endif /* MQTTAPP_H_ */
