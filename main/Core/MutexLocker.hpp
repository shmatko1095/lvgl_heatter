/*
 * MutexLocker.hpp
 *
 *  Created on: Apr 30, 2021
 *      Author: f73377
 */

#ifndef CORE_MUTEXLOCKER_HPP_
#define CORE_MUTEXLOCKER_HPP_

#include "Mutex.hpp"

class MutexLocker {
public:
	MutexLocker(Mutex &mutex) :	mtx(mutex) {
		mtx.lock();
	}

	~MutexLocker() {
		mtx.unlock();
	}

private:
	Mutex &mtx;
};

#endif /* CORE_MUTEXLOCKER_HPP_ */
