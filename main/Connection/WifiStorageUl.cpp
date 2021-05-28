/*
 * WifiStorageUl.cpp
 *
 *  Created on: May 27, 2021
 *      Author: f73377
 */

#include "nvs.h"
#include "nvs_flash.h"
#include "WifiStorageUl.h"

#define STORAGE_NAMESPACE "WIFI_DATA"
#define KEY_WIFI_ENABLE   "ENABLE"
#define KEY_WIFI_AUTH 	  "AUTH"
#define KEY_WIFI_SSID 	  "SSID"
#define KEY_WIFI_PASSWORD "PASSWORD"

void WifiStorageUl::getSavedState(CredentialsDesc& cred, bool& enable){
	size_t size;
	nvs_handle_t handle;
	uint8_t auth;
	static char ssid[SsidLen];
	static char password[PasswordLen];
	nvs_open(STORAGE_NAMESPACE, NVS_READONLY, &handle);
	nvs_get_u8(handle, KEY_WIFI_ENABLE, (uint8_t*)&enable);
	nvs_get_u8(handle, KEY_WIFI_AUTH, &auth);
	nvs_get_str(handle, KEY_WIFI_SSID, ssid, &size);
	nvs_get_str(handle, KEY_WIFI_PASSWORD, password, &size);
	nvs_close(handle);

	cred.set(ssid, password, (wifi_auth_mode_t)auth);
}

void WifiStorageUl::setSavedState(CredentialsDesc& cred, bool enable){
	nvs_handle_t handle;
	nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handle);
	nvs_set_u8(handle, KEY_WIFI_ENABLE, enable);
	nvs_set_u8(handle, KEY_WIFI_AUTH, cred.getAuth());
	nvs_set_str(handle, KEY_WIFI_SSID, cred.getSsid());
	nvs_set_str(handle, KEY_WIFI_PASSWORD, cred.getPassword());
	nvs_commit(handle);
	nvs_close(handle);
}


