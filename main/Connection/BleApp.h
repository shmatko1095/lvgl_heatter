/*
 * BleApp.h
 *
 *  Created on: May 22, 2021
 *      Author: f73377
 */

#ifndef CONNECTION_BLEAPP_H_
#define CONNECTION_BLEAPP_H_

#include "../Core/BaseTask.hpp"

class BleApp : public StaticBaseTask<1024> {
public:
	BleApp();

	virtual ~BleApp(){};

	void run() override;
};

#endif /* CONNECTION_BLEAPP_H_ */
