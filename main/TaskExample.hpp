/*
 * TaskExample.h
 *
 *  Created on: Apr 30, 2021
 *      Author: f73377
 */

#ifndef TASKEXAMPLE_HPP_
#define TASKEXAMPLE_HPP_

#include "Core/BaseTask.hpp"

class TaskExample : public StaticBaseTask<128> {
public:
	TaskExample();

	void run() override;
};

#endif /* TASKEXAMPLE_HPP_ */
