/*
 * Queue.hpp
 *
 *  Created on: Apr 30, 2021
 *      Author: f73377
 */

#ifndef CORE_QUEUE_HPP_
#define CORE_QUEUE_HPP_

#include "../Types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

template<class T, size_t size>
class Queue {
public:
	/**
	 *Queue<int, 1000> xQueue;
	 */
	Queue() {
		xHandle = xQueueCreateStatic(size, sizeof(T),
				reinterpret_cast<uint8_t*>(xStorage), &xQueueDefinition);
	}

	/**
	 *int value;
	 *xQueue.receive(&value);
	 */
	bool receive(T *val, TickType_t xTicksToWait = portMAX_DELAY) {
		return xQueueReceive(xHandle, val, xTicksToWait);
	}

	/**
	 *xQueue.send(value);
	 */
	bool send(const T &val, TickType_t xTicksToWait = portMAX_DELAY) {
		return xQueueSend(xHandle, &val, xTicksToWait);
	}

private:
	QueueHandle_t xHandle;
	StaticQueue_t xQueueDefinition;
	T xStorage[size];
};

#endif /* CORE_QUEUE_HPP_ */
