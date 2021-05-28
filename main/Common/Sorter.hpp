/**@file     Sorter.hpp
 * @author   ako@ektos.net (EKTOS A/S)
 * @date     created on Oct 20, 2017
 * @version  1.0
 * @brief    Array sorting related implementations
 * @note     Belongs to ESB project
 */

#ifndef SORTER_HPP_
#define SORTER_HPP_

#include "Common.hpp"
#include "Types.h"

/**@brief Heap sorting implementation
 * @ingroup common_helpers
 * @tparam T - Type of items in array to sort
 * @tparam Handler - Type of comparison handler class
 */
template<class T, class Handler>
class Sorter
{
public:
  /**@brief Class constructor
   * @param [in] buff    - pointer to array to be sorted
   * @param [in] size    - size of array to be sorted
   * @param [in] h_c     - pointer to comparison handler instance
   * @param [in] compare - pointer to compare method of comparison handler
   */
  Sorter(T *buff, size_t size, Handler *h_c, bool (Handler::* compare)(const T&,const T&)const):
    buff(buff), size(size), h_c(h_c), compare(compare){}

  /**@brief Returns size of array to sort
   * @return size of array to sort
   */
  size_t getSize(){return size;}

  /**@brief Balancing the heap according to heap sorting rules*/
  void heapify(){
    for(ssize_t i = (size / 2)-1; i > -1; i--){
      shiftDown(i, size);
    }
  }

  /**@brief Creates sorted array from heapified array*/
  void build(){
    for(size_t i = size - 1; i > 0; i--){
      exchange(buff[0], buff[i]);
      shiftDown(0, i);
    }
  }

  /**@brief Adds new node into @b heapified array
   * @param [in] node - reference to new node
   */
  void add(const T &node){
    size_t id = size++;
    buff[id] = node;
    while(parentId(id)>=0){
      if((h_c->*compare)(buff[id], buff[parentId(id)])){
        exchange(buff[id], buff[parentId(id)]);
        id = parentId(id);
      }else{
        break;
      }
    }
  }

  /**@brief Removes items from tail of array, so they will not be sorted
   * @param [in] count - count of items to remove
   */
  inline void removeLast(size_t count){
    size -= minimum(size, count);
  }

  /**@brief Sorts the array*/
  inline void sort(){
    heapify();
    build();
  }

private:
  inline ssize_t child1Id(ssize_t parent){return parent*2+1;}
  inline ssize_t child2Id(ssize_t parent){return parent*2+2;}
  inline ssize_t parentId(ssize_t child){return (child-1)>>1;}

  void shiftDown(size_t id, ssize_t size){
    while(child1Id(id) < size){
      size_t maxItemId = ((child2Id(id) >= size) || (h_c->*compare)(buff[child1Id(id)], buff[child2Id(id)]))?
          child1Id(id):child2Id(id);
      if((h_c->*compare)(buff[maxItemId], buff[id])){
        exchange(buff[id], buff[maxItemId]);
        id = maxItemId;
      }else{
        break;
      }
    }
  }

  T *buff;
  size_t size;
  Handler *h_c;
  bool (Handler::* compare)(const T&,const T&)const;
};


/**@brief Helper to check if array is sorted
 * @ingroup common_helpers
 * @tparam T - Type of items in array to sort
 * @tparam Handler - Type of comparison handler class
 */
template<class T, class Handler>
class SortChecker
{
public:
  /**@brief Class constructor
   * @param [in] buff    - pointer to array to be checked
   * @param [in] size    - size of array to be checked
   * @param [in] h_c     - pointer to comparison handler instance
   * @param [in] compare - pointer to compare method of comparison handler
   */
  SortChecker(const T *buff, size_t size, const Handler *h_c, bool (Handler::* compare)(const T&,const T&)const):
    buff(buff), size(size), h_c(h_c), compare(compare){}

  /**@brief Checks if array is sorted
   * @return @b true if array is sorted, otherwise @b false
   */
  bool check(){
    bool result = true;
    for(size_t i = 1; result && (i < size); i++){
      result = (h_c->*compare)(buff[i], buff[i-1]);
    }
    return result;
  }

private:
  const T * const buff;
  const size_t size;
  const Handler *const h_c;
  bool (Handler::* const compare)(const T&,const T&)const;
};

#endif /* SORTER_HPP_ */
