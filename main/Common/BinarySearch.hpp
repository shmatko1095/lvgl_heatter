/**
 * @file       BinarySearch.hpp
 * @author     ako@ektos.net (EKTOS A/S)
 * @date       created on Oct 20, 2017
 * @version    1.0
 * @brief      Binary search algorithm implementation
 * @note       Belongs to ESB project
 */

#ifndef SOURCE_COMMON_BINARYSEARCH_HPP_
#define SOURCE_COMMON_BINARYSEARCH_HPP_

/**@brief Binary search algorithm implementation
 * @ingroup common_helpers
 * @tparam Key_T - Type of compared value
 * @tparam Handler - Type of object with compare method for handling comparison
 * @note compare method should have next prototype: @n
 * @code ssize_t Handler::compare(const Key_T&, size_t index)const @endcode
 * where first argument is the desired value, and second is the index in array to compare with@n
 * Result of compare method should be like: @code return key - array[index];@endcode
 * i.e. less then zero means index too high, more then zero means index too low, and zero means value is found
 */
template <class Key_T, class Handler>
class BinarySearch
{
public:
  /**@brief Class contructor
   * @param [in] buff_size - element count in sorted array
   * @param [in] h_c - Pointer to comparison handler instance
   * @param [in] compare - pointer to compare method of handler class
   */
  BinarySearch(size_t buff_size, Handler *h_c, ssize_t (Handler::* compare)(const Key_T&, size_t index)const):
    buff_size(buff_size), h_c(h_c), compare(compare)
  {}

  /**@brief Searches key value in array using compare method of Handler class
   * @param [in] key - value to be found
   * @param [out] getFirst - if not null and there no equal element, then will contain lower index of nearest element
   * @return index of found element, if element wasn't found then result is -1
   * and lower index of nearest element may be got via getFirst argument
   */
  ssize_t search(Key_T key, ssize_t *getFirst = 0){
      ssize_t result = -1;
      ssize_t first = 0;

      if (buff_size > 0){
        ssize_t last = buff_size - 1;
        while (first <= last){
          ssize_t middle = (first+last)/2;
          ssize_t cmp_result = get_difference(key, middle);
          if(cmp_result > 0){
            first = middle + 1;
          }else if(cmp_result < 0){
            last = middle - 1;
          }else{
            result = middle;
            break;
          }
        }
      }
      getFirst?*getFirst=(first?first-1:0):0;
      return result;
  }

private:
  ssize_t get_difference(Key_T key, size_t index){
    return (h_c->*compare)(key, index);
  }

  size_t buff_size;
  Handler *h_c;
  ssize_t (Handler::* compare)(const Key_T&, size_t index)const;
};

#endif /* SOURCE_COMMON_BINARYSEARCH_HPP_ */
