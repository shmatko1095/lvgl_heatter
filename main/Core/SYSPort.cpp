/**@file SYSPort.cpp
 * @author msn@ektos.net (EKTOS A/S)
 * @date created on Dec 9, 2015
 * @version 1.0
 * @brief All common methods implementations
 * @note Belongs to ESB project
 */

#include "SYSPort.hpp"
#include "SYSDelay.hpp"
#include "SYSTime.hpp"
#include "../Common/Common.hpp"

uint32_t SYSTime::current(){
  return xTaskGetTickCount();
}

void SYSDelay::sleep(uint32_t time){
  vTaskDelay(pdMS_TO_TICKS(time));
}

void SYSDelay::sleepUntil(uint32_t time){
  vTaskDelayUntil(&lastTime, pdMS_TO_TICKS(time));
}
