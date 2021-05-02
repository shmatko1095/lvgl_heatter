/*
 * TaskExample.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: f73377
 */

#include "TaskExample.hpp"

TaskExample::TaskExample() {
	create("TaskExample", 1);
}

void TaskExample::run() {
	static uint32_t i = 0;
    while (true) {
	  i++;
	  vTaskDelay(pdMS_TO_TICKS(100));
    }
}
