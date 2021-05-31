/*
 * WifiManager.cpp
 *
 *  Created on: May 27, 2021
 *      Author: f73377
 */

#include "../Connection/WifiManager.h"
#include "../EventController.h"
#include "WifiStorageUl.h"
#include "esp_wifi.h"
#include <string.h>

static void printScanResults(AccessPointDesc* data, size_t &len);
Mutex WifiManager::mMtx = Mutex();

WifiManager::WifiManager() {
	connected = false;
	started = false;
}

void WifiManager::init(){
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta(); 	//??
    assert(sta_netif);											  	//??

	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	ESP_ERROR_CHECK(esp_wifi_init(&cfg));

	ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID,
			&WifiManager::wifiEventHandler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP,
    		&WifiManager::ipEventHandler, NULL));

	ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
	ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
}

esp_err_t WifiManager::enable(){
	mMtx.lock();
	Assert(!started);
	esp_err_t result = esp_wifi_start();
	ESP_ERROR_CHECK(result);
	if (result == ESP_OK) {
		started = true;
	} else {
		printf("WifiManager::enable result: %s", esp_err_to_name(result));
		mMtx.unlock();
	}
	return result;
}

esp_err_t WifiManager::disable(){
	mMtx.lock();
	esp_err_t result = esp_wifi_stop();
	ESP_ERROR_CHECK(result);
	if (result == ESP_OK) {
		started = false;
	} else {
		printf("WifiManager::disable result: %s", esp_err_to_name(result));
		mMtx.unlock();
	}
	return result;
}

esp_err_t WifiManager::startScan(){
	static const wifi_active_scan_time_t activaScanTime = {
			.min = 50,
			.max = 1000,
	};

	static const wifi_scan_time_t scanTime = {
			.active = activaScanTime,
		    .passive = 1200,
	};

	static const wifi_scan_config_t scanConf = {
			.ssid = NULL,
			.bssid = NULL,
			.channel = 0,
			.show_hidden = true,
			.scan_type = WIFI_SCAN_TYPE_ACTIVE,
			.scan_time = scanTime,
	};

	mMtx.lock();
	esp_err_t result = esp_wifi_scan_start(&scanConf, false);
	ESP_ERROR_CHECK(result);
	if (result == ESP_OK) {
		started = false;
	} else {
		printf("WifiManager::startScan result: %s", esp_err_to_name(result));
		mMtx.unlock();
	}
	return result;
}

void WifiManager::connect(CredentialsDesc& cred) {
	mMtx.lock();
    wifi_sta_config_t staConfig;
    strcpy((char*)staConfig.ssid, cred.getSsid());
    strcpy((char*)staConfig.password, cred.getPassword());
    staConfig.threshold.authmode = cred.getAuth();

    wifi_pmf_config_t pmfConfig;
    pmfConfig.capable = true;
	pmfConfig.required = false;
	staConfig.pmf_cfg = pmfConfig;

	wifi_config_t sWifiConfig;
	sWifiConfig.sta = staConfig;

	esp_wifi_disconnect();
	esp_wifi_set_config(WIFI_IF_STA, &sWifiConfig);
	esp_err_t result = esp_wifi_connect();
    if (result != ESP_OK) {
    	printf("WifiManager::connect result: %s", esp_err_to_name(result));
    	mMtx.unlock();
    }
}

size_t WifiManager::getWirelessListSize(){
	uint16_t result;
	esp_wifi_scan_get_ap_num(&result);
	return result;
}

size_t WifiManager::getWirelessList(AccessPointDesc* data, size_t len) {
	assert(data != nullptr);
	size_t actualSize = getWirelessListSize();
	len = len > actualSize ? actualSize : len;

	wifi_ap_record_t* list = (wifi_ap_record_t*)malloc(sizeof(wifi_ap_record_t) * len);
	ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records((uint16_t*)&len, list));
	for (uint16_t i = 0; i < len; i++) {
		data[i].set((const char*)list[i].ssid, list[i].rssi, list[i].authmode);
	}
	free(list);
	return len;
}

void WifiManager::wifiEventHandler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data) {
	mMtx.unlock();
	switch (event_id) {
	case SYSTEM_EVENT_WIFI_READY:
		EventController::pushEvent(IEventReceiver::WifiReady, nullptr);
		break;
	case SYSTEM_EVENT_SCAN_DONE:
		EventController::pushEvent(IEventReceiver::WifiScanDone, nullptr);
		break;
	case SYSTEM_EVENT_STA_START:
		EventController::pushEvent(IEventReceiver::WifiStart, nullptr);
		break;
	case SYSTEM_EVENT_STA_STOP:
		EventController::pushEvent(IEventReceiver::WifiStop, nullptr);
		break;
	case SYSTEM_EVENT_STA_CONNECTED:
		EventController::pushEvent(IEventReceiver::WifiConnected, nullptr);
		break;
	case SYSTEM_EVENT_STA_DISCONNECTED:
		EventController::pushEvent(IEventReceiver::WifiDisconnected, nullptr);
		esp_wifi_connect();
		break;
	default:
		break;
	}
}

void WifiManager::ipEventHandler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data) {
	if (event_id == IP_EVENT_STA_GOT_IP) {
		EventController::pushEvent(IEventReceiver::WifiGotIp, event_data);
//        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
	} else if (event_id == IP_EVENT_STA_LOST_IP) {
		EventController::pushEvent(IEventReceiver::WifiLostIp, event_data);
	}
}

static void printScanResults(AccessPointDesc* data, size_t &len) {
	printf("======================================================================\n");
	printf("             SSID             |    RSSI    |           AUTH           \n");
	printf("======================================================================\n");
	for (uint16_t i=0; i<len; i++) {
	   char *authmode;
	   switch(data->getAuth()) {
		  case WIFI_AUTH_OPEN: 			authmode = "WIFI_AUTH_OPEN";		 break;
		  case WIFI_AUTH_WEP:			authmode = "WIFI_AUTH_WEP";			 break;
		  case WIFI_AUTH_WPA_PSK:		authmode = "WIFI_AUTH_WPA_PSK";		 break;
		  case WIFI_AUTH_WPA2_PSK:		authmode = "WIFI_AUTH_WPA2_PSK";	 break;
		  case WIFI_AUTH_WPA_WPA2_PSK:	authmode = "WIFI_AUTH_WPA_WPA2_PSK"; break;
		  default:              		authmode = "Unknown";				 break;
	   }
	   printf("%26.26s    |    % 4d    |    %22.22s\n",data[i].getSsid(), data[i].getRssi(), authmode);
	}
	printf("\n\n");
}

///The scan example was found here:
///https://github.com/VALERE91/ESP32_WifiScan/
