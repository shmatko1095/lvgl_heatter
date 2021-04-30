/*
 * SdStorrage.h
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#ifndef SDSTORRAGE_H_
#define SDSTORRAGE_H_

#include "Types.h"
#include "sdmmc_cmd.h"

class SdStorrage {
public:

	SdStorrage();
	virtual ~SdStorrage(){};

	static bool init();

	static void start();

	static void run();

private:
	static const char mount_point[];
	static sdmmc_card_t* card;
};


/**********************************/
#ifdef __cplusplus
extern "C" {
#endif

void sdStorrageExample(void);

#ifdef __cplusplus
}
#endif

#endif /* SDSTORRAGE_H_ */
