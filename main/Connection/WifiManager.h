/*
 * WifiManager.h
 *
 *  Created on: May 27, 2021
 *      Author: f73377
 */

#ifndef WIFIMANAGER_H_
#define WIFIMANAGER_H_

#include "../Common/Types.h"
#include "../Core/Mutex.hpp"
#include "WifiTypes.hpp"
#include <esp_wifi_types.h>

class WifiManager {
public:
	static WifiManager* getInstance() {
		static WifiManager wifiManager = WifiManager();
		return &wifiManager;
	}

	void init();

	esp_err_t enable();

	esp_err_t disable();

	esp_err_t startScan();

	void connect(CredentialsDesc& cred);

	size_t getWirelessListSize();

	size_t getWirelessList(AccessPointDesc* data, size_t len);

	bool isStarted() {
		return started;
	}

	bool isConnected() {
		return connected;
	}

private:
	WifiManager();

	static void wifiEventHandler(void* arg, esp_event_base_t event_base,
	                                int32_t event_id, void* event_data);
	static void ipEventHandler(void* arg, esp_event_base_t event_base,
	                                int32_t event_id, void* event_data);

	static Mutex mMtx;
	bool started;
	bool connected;
};

#endif /* WIFIMANAGER_H_ */
