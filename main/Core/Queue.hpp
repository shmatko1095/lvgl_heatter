/*
 * Queue.hpp
 *
 *  Created on: Apr 30, 2021
 *      Author: f73377
 */

#ifndef CORE_QUEUE_HPP_
#define CORE_QUEUE_HPP_

#include "../Common/Types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

//template<class T, size_t size>
class Queue {
public:

  /**@brief class constructor
   * @param [in] storageArea - buffer for storing all messages, should be of size length*itemSize
   * @param [in] length - message count
   * @param [in] itemSize - message size
   */
	Queue(uint8_t *storageArea, size_t length, size_t itemSize){
    xQueue = xQueueCreateStatic(length, itemSize, storageArea, &xStaticQueue);
    configASSERT(xQueue);
  }

  /**@brief Sends message to queue, and blocks on time when there no space in the queue
   * @param [in] buf  - pointer to message
   * @param [in] time - timeout value in milliseconds
   * @return @b true if success and @b false if timeout reached
   */
  bool send(const void *buf, uint32_t time = portMAX_DELAY){
    return xQueueSend(xQueue, buf, time);
  }

  /**@brief Sends message to front of queue (will be received first),
   * and blocks on time when there no space in the queue
   * @param [in] buf  - pointer to message
   * @param [in] time - timeout value in milliseconds
   * @return @b true if success and @b false if timeout reached
   */
  bool sendToFront(const void *buf, uint32_t time = portMAX_DELAY){
    return xQueueSendToFront(xQueue, buf, time);
  }

  /**@brief Reads message from queue but leaves message in the queue,
   * and blocks on time when there no messages in the queue
   * @param [in] buf  - pointer to message
   * @param [in] time - timeout value in milliseconds
   * @return @b true if success and @b false if timeout reached
   */
  bool peek(void *buf, uint32_t time = portMAX_DELAY){
    return xQueuePeek(xQueue, buf, time);
  }

  /**@brief Reads and removes message from queue,
   * and blocks on time when there no messages in the queue
   * @param [in] buf  - pointer to message
   * @param [in] time - timeout value in milliseconds
   * @return @b true if success and @b false if timeout reached
   */
  bool receive(void *buf, uint32_t time = portMAX_DELAY){
    return xQueueReceive( xQueue, buf, time);
  }

  /**@brief Returns count of messages waiting in the queue
   * @return count of messages waiting in the queue
   */
  size_t getCount()const{
    return uxQueueMessagesWaiting(xQueue);
  }

  /**@brief Returns free slots count in queue for messages
   * @return free slots count in queue for messages
   */
  size_t getFree()const{
    return uxQueueSpacesAvailable(xQueue);
  }

private:
  QueueHandle_t xQueue;
  StaticQueue_t xStaticQueue;
};

#endif /* CORE_QUEUE_HPP_ */
