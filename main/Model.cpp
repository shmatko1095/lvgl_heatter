/*
 * Model.cpp
 *
 *  Created on: Apr 16, 2021
 *      Author: f73377
 */

#include "Model.hpp"
#include "nvs_flash.h"
#include "esp_system.h"

void Model::preinit() {
}

void Model::init() {
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
	  ESP_ERROR_CHECK(nvs_flash_erase());
	  ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	//	nvs_flash_erase();
}

//------------------------------------------------------------------------------
Model::Model() {
	//---------------------BSP----------------------------------
	BSPTree tree = {
//    {&bldrInfo, &appInfo},
//    &heartBitPin,
//    {&com1Rx, &com1Tx, &com1Ctrl},
//    {&com2Rx, &com2Tx, &com2Ctrl},
//    {&com3Rx, &com3Tx, &com3Ctrl},
//    {&com4Rx, &com4Tx, &com4Ctrl},
//    {&com5Rx, &com5Tx, &com5Ctrl},
			};

	bspTree = tree;
}

//------------------------------------------------------------------------------
