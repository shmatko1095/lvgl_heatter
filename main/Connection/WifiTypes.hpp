/*
 * WifiTypes.hpp
 *
 *  Created on: May 30, 2021
 *      Author: f73377
 */

#include <esp_wifi_types.h>
#include <string.h>

#ifndef CONNECTION_WIFITYPES_HPP_
#define CONNECTION_WIFITYPES_HPP_

enum {
	SsidLen = 32,
	PasswordLen = 64,
};

struct CredentialsDesc {
public:
	CredentialsDesc(char *ssid, char *password, wifi_auth_mode_t auth) :
		mSsid(ssid), mPassword(password), mAuth(auth) {};

	void set(char *ssid, char *password, wifi_auth_mode_t auth) {
		mSsid  = ssid;
		mPassword = password;
		mAuth = auth;
	}

	char* getSsid() {
		return mSsid;
	}
	char* getPassword() {
		return mPassword;
	}

	wifi_auth_mode_t getAuth() {
		return mAuth;
	}

private:
	char* mSsid;
	char* mPassword;
	wifi_auth_mode_t mAuth;
};

struct AccessPointDesc {
public:
	AccessPointDesc() {
		mRssi = 0xFF;
		mAuth = (wifi_auth_mode_t)-1;
	}

	AccessPointDesc(const char *ssid, int8_t rssi, wifi_auth_mode_t auth) {
		set(ssid, rssi,auth);
	}

	void set(const char *ssid, int8_t rssi, wifi_auth_mode_t auth) {
		strcpy(mSsid, ssid);
		mRssi = rssi;
		mAuth = auth;
	}

	char* getSsid() {
		return mSsid;
	}
	int8_t getRssi() {
		return mRssi;
	}
	wifi_auth_mode_t getAuth() {
		return mAuth;
	}

private:
	char mSsid[SsidLen];
	int8_t mRssi;
	wifi_auth_mode_t mAuth;
};

#endif /* CONNECTION_WIFITYPES_HPP_ */
