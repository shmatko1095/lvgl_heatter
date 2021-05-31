/*
 * MqttEventController.h
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#ifndef MQTTEVENTCONTROLLER_H_
#define MQTTEVENTCONTROLLER_H_

#include "IMqttEventReceiver.hpp"
#include "../Common/Pair.hpp"
#include "../Common/List.hpp"
#include "../Common/Types.h"
#include "../Common/Map.hpp"

class MqttEventController {
public:
	static void registerReceiver(IMqttEventReceiver &receiver) {
		MqttEventController &controller = MqttEventController::getInstance();
		controller.handlers.addLast(receiver.mItem);
	}

	static void pushEvent(char* topic, size_t topicLen, char* data, size_t dataLen) {
		MqttEventController &controller = MqttEventController::getInstance();
		List::Itterator itt = controller.handlers.getItterator();
		while(itt) {
			IMqttEventReceiver* receiver = &containerOf(*(itt++), &IMqttEventReceiver::mItem);
			if (receiver->isSubscribed(topic, topicLen)) {
				receiver->onReceive(topic, topicLen, data, dataLen);
			}
		}
	}

	static List getHandlers() {
		return MqttEventController::getInstance().handlers;
	}

private:
	static MqttEventController &getInstance(){
	    static MqttEventController controller;
	    return controller;
	}

	List handlers;
};

#endif /* EVENTCONTROLLER_H_ */
