/**
* @file    Pair.hpp
* @author  msn@ektos.net (EKTOS A/S)
* @date    created on Apr 17, 2018
* @version 1.0
* @brief   Pair helper for merging two objects
* @note    Belongs to ESB project
*/

#ifndef SOURCE_COMMON_PAIR_HPP_
#define SOURCE_COMMON_PAIR_HPP_

/**@brief Pair helper for merging two objects
 * @tparam First - Type of first object to merge
 * @tparam Second - Type of second object to merge
 * @note Comparison operators will work only for first field
 */
template <class First, class Second>
struct Pair
{
  First first;   //!< first object to merge
  Second second; //!< second object to merge

  /**@brief Comparison operators will compare only first fields
   * @param [in] value - other pair for comparison
   * @return @b true if current first more then other first, otherwise @b false
   */
  bool operator> (const Pair& value)const{
    return first > value.first;
  }
  /**@brief Comparison operators will compare only first fields
   * @param [in] value - other pair for comparison
   * @return @b true if current first less then other first, otherwise @b false
   */
  bool operator< (const Pair& value)const{
    return first < value.first;
  }
  /**@brief Comparison operators will compare only first fields
   * @param [in] value - other pair for comparison
   * @return @b true if current first not less then other first, otherwise @b false
   */
  bool operator>= (const Pair& value)const{
    return first >= value.first;
  }
  /**@brief Comparison operators will compare only first fields
   * @param [in] value - other pair for comparison
   * @return @b true if current first not more then other first, otherwise @b false
   */
  bool operator<= (const Pair& value)const{
    return first <= value.first;
  }
  /**@brief Comparison operators will compare only first fields
   * @param [in] value - other pair for comparison
   * @return @b true if current first equal to other first, otherwise @b false
   */
  bool operator== (const Pair& value)const{
    return first == value.first;
  }
};

#endif /* SOURCE_COMMON_PAIR_HPP_ */
