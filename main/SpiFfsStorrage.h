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

class SpiFfsStorrage : public StaticBaseTask<1800> {
public:

	SpiFfsStorrage();
	virtual ~SpiFfsStorrage(){};

	void run() override;

	void init();

private:
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
