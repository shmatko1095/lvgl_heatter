/*
 * WifiStorageUl.h
 *
 *  Created on: May 27, 2021
 *      Author: f73377
 */

#ifndef WIFI_STORAGE_UL_H_
#define WIFI_STORAGE_UL_H_

#include "../Common/Types.h"
#include "WifiTypes.hpp"
#include <esp_wifi_types.h>

class WifiStorageUl {
public:

	static void getSavedState(CredentialsDesc& cred, bool& enable);

	static void setSavedState(CredentialsDesc& cred, bool enable);

private:
};

#endif /* WIFI_STORAGE_UL_H_ */
