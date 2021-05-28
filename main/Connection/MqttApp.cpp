/*
 * MqttApp.cpp
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#include "../Connection/MqttApp.h"

#include "../EventController.h"

static int cnt = 0;

MqttApp::MqttApp() {
	create("MqttApp", 0, 1);
	EventController::registerReceiver(*this);
}

void MqttApp::run() {
	while (1) {
		cnt++;
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void MqttApp::onReceive(IEventReceiver::EventId event, void* params) {
	if (event == WifiGotIp) {

	}
}
