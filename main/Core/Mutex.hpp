/*
 * Mutex.hpp
 *
 *  Created on: Apr 30, 2021
 *      Author: f73377
 */

#ifndef CORE_MUTEX_HPP_
#define CORE_MUTEX_HPP_

#include "../Types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

class Mutex {
public:
	Mutex() {
		xMutex = xSemaphoreCreateMutexStatic(&xMutexControlBlock);
	}

	BaseType_t lock(TickType_t xTicksToWait = portMAX_DELAY) {
		return xSemaphoreTake(xMutex, xTicksToWait);
	}

	BaseType_t unlock() {
		return xSemaphoreGive(xMutex);
	}

private:
	SemaphoreHandle_t xMutex;
	StaticSemaphore_t xMutexControlBlock;
};

#endif /* CORE_MUTEX_HPP_ */
