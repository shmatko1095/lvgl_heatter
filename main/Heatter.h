/*
 * Heatter.h
 *
 *  Created on: May 16, 2021
 *      Author: f73377
 */

#ifndef GUIAPP_HEATTER_H_
#define GUIAPP_HEATTER_H_

#include "Common/Types.h"

class HeatterApp {
public:
	HeatterApp();

	static int16_t getInputTemp() {
		return 281;
	}

	static int16_t getOutputTemp() {
		return 324;
	}

	static int16_t getPressure() {
		return 12;
	}

	static int16_t getLoadLevel() {
		return 75;
	}

};

#endif /* GUIAPP_HEATTER_H_ */
