/*
 * Mutex.hpp
 *
 *  Created on: Apr 30, 2021
 *      Author: f73377
 */

#ifndef CORE_MUTEX_HPP_
#define CORE_MUTEX_HPP_

#include "../Types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

/**@brief RTOS recursive guard object for serialization
 * @ingroup kernel_objects
 */
class Mutex
{
public:

  /**@brief Class constructor*/
  Mutex(){
    xSemaphore = xSemaphoreCreateRecursiveMutexStatic(&xMutexBuffer);
    configASSERT(xSemaphore);
  }

  /**@brief checks if mutex already locked and if not then locks it
   * @return @b true if mutex have been unlocked and was locked by this call, @b false if mutex was locked before
   */
  bool tryLock(){
    return lock(0);
  }

  /**@brief locks mutex if it is unlocked and block execution,
   * if mutex already locked, until it will be unlocked or timeout reached
   * @param [in] time - timeout to wait unlocking in milliseconds
   * @return @b true if mutex was locked by this call, @b false if timeout reached
   * @note @b false will never be returned if timeout set to SysTimeInfinite
   */
  bool lock(uint32_t time = portMAX_DELAY){
    return (xSemaphoreTakeRecursive(xSemaphore, time) != pdFALSE);
  }

  /**@brief unlocks the mutex which was locked by current task
   * @note mutex should be unlocked by the same task which has locked the mutex.
   * To fully unlock the mutex, unlock method should be called as many times as lock method was called before
   */
  void unlock(){
    xSemaphoreGiveRecursive(xSemaphore);
  }

private:
  SemaphoreHandle_t xSemaphore;
  StaticSemaphore_t xMutexBuffer;
};

#endif /* CORE_MUTEX_HPP_ */
