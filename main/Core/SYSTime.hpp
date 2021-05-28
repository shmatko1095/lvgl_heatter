/**@file    SYSTime.hpp
 * @author  msn@ektos.net (EKTOS A/S)
 * @date    created on Dec 9, 2015
 * @version 1.0
 * @brief   Helper for time measuring
 * @note    Belongs to ESB project
 */

#ifndef __E_TIME_HPP__
#define __E_TIME_HPP__

#include "../Common/Types.h"

/**@brief Time measuring helper
 * @ingroup common_helpers
 */
class SYSTime
{
public:

  /**@brief Class constructor, saves inside system time while creating*/
  SYSTime():lastTime(current()){}

  /**@brief Checks if time interval passed from saved time
   * @param [in] time - time interval to check in milliseconds
   * @return @b true if time is passed, otherwise @b false
   */
  bool isPassed(uint32_t time)const{
    return passed() >= time;
  }

  /**@brief Returns count of milliseconds passed from saved time
   * @return count of milliseconds passed from saved time
   */
  uint32_t passed()const{
    return current() - lastTime;
  }

  /**@brief Saves inside current system time*/
  void take(){
    lastTime = current();
  }

  /**@brief returns current system time in milliseconds
   * @return current system time in milliseconds
   */
  static uint32_t current();

protected:
  uint32_t lastTime; //!< saved system time in milliseconds
};

#endif /* __E_TIME_HPP__ */
