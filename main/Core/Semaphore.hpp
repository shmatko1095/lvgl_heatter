/*
 * Semaphore.hpp
 *
 *  Created on: Apr 30, 2021
 *      Author: f73377
 */

#ifndef CORE_SEMAPHORE_HPP_
#define CORE_SEMAPHORE_HPP_

#include "../Types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

class Semaphore {
public:
	Semaphore() {
		xSema = xSemaphoreCreateBinaryStatic(&xSemaControlBlock);
	}

	BaseType_t give() {
		return xSemaphoreGive(xSema);
	}

	BaseType_t take(TickType_t xTicksToWait = portMAX_DELAY) {
		return xSemaphoreTake(xSema, xTicksToWait);
	}

private:
	SemaphoreHandle_t xSema;
	StaticSemaphore_t xSemaControlBlock;
};

#endif /* CORE_SEMAPHORE_HPP_ */
