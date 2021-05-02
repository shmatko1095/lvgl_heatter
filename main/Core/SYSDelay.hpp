/**@file    SYSDelay.hpp
 * @author  msn@ektos.net (EKTOS A/S)
 * @date    created on Jul 12, 2017
 * @version 1.0
 * @brief   Delay object for suspending context
 * @note    Belongs to ESB project
 */
#ifndef SOURCE_RTOS_SYSDELAY_HPP_
#define SOURCE_RTOS_SYSDELAY_HPP_

#include "SYSTime.hpp"

/**@brief Delay object for suspending context
 * @ingroup common_helpers
 */
class SYSDelay : public SYSTime
{
public:
  /**@brief Suspends current context for defined time
   * @param [in] time - time in milliseconds
   */
  static void sleep(uint32_t time);

  /**@brief Suspends current context until system time reaches defined time
   * @param [in] time - time in milliseconds
   */
  void sleepUntil(uint32_t time);

};

#endif /* SOURCE_RTOS_SYSDELAY_HPP_ */
