/*
 * SdStorrage.h
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#ifndef SPIFFSSTORRAGE_H_
#define SPIFFSSTORRAGE_H_

#include "Types.h"
#include "Core/BaseTask.hpp"
#include "wear_levelling.h"

class SpiFfsStorrage {
public:
	SpiFfsStorrage();
	virtual ~SpiFfsStorrage(){};

	void init();

	void deinit();
};


/**********************************/
#ifdef __cplusplus
extern "C" {
#endif

void vfsExample(void);

#ifdef __cplusplus
}
#endif

#endif /* SPIFFSSTORRAGE_H_ */
