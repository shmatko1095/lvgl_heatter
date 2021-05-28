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

class MqttApp : public IEventReceiver, public StaticBaseTask<1024>{
public:
	MqttApp();

	void run() override;

	void onReceive(IEventReceiver::EventId event, void* params) override;
};

#endif /* MQTTAPP_H_ */
