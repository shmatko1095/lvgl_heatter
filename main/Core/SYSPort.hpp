/**@file SYSPort.hpp
 * @author msn@ektos.net (EKTOS A/S)
 * @date created on Aug 2, 2017
 * @version 1.0
 * @brief All common constants related to FreeRTOS objects
 * @note Belongs to Blocks project
 */
#ifndef SOURCE_KERNEL_RTOS_SYSPORT_HPP_
#define SOURCE_KERNEL_RTOS_SYSPORT_HPP_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class SYSPort {
public:
	static void suspend();

	static int resume();
};


#endif /* SOURCE_KERNEL_RTOS_SYSPORT_HPP_ */
