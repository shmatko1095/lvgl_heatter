/**
* @file    Map.hpp
* @author  ako@ektos.net (EKTOS A/S)
* @date    created on Oct 23, 2017
* @version 1.0
* @brief   Map helper for object arrays
* @note    Belongs to ESB project
*/

#ifndef SOURCE_COMMON_MAP_HPP_
#define SOURCE_COMMON_MAP_HPP_

#include "BinarySearch.hpp"
#include "Sorter.hpp"
#include "Common.hpp"
#include "Types.h"
#include "Pair.hpp"
#include <string.h>

/**@brief Map helper for object arrays
 * @ingroup common_helpers
 * @tparam Key - type of key field for comparison
 * @tparam Value - type of value field
 */
template <class Key, class Value>
class Map
{
public:
  /**@brief Iterator for map
   * @ingroup common_helpers
   */
  class Iterator{
  public:
    /**@brief operator * will return reference to current item*/
    Pair<Key, Value>&  operator* () const {
      Assert(!isEob());
      return buff[offset];
    }
    /**@brief operator post increment will move iterator to next item and return pointer to current one*/
    Pair<Key, Value>* operator++ (int){
      Assert(!isEob());
      Pair<Key, Value>* result = &buff[offset++];
      return result;
    }
    /**@brief operator pre increment will move iterator to next item and return pointer to it*/
    Pair<Key, Value>* operator++ (){
      Assert(!isEob());
      Pair<Key, Value>* result = &buff[++offset];
      return result;
    }
    /**@brief operator post decrement will move iterator to previous item and return pointer to current one*/
    Pair<Key, Value>* operator-- (int){
      Assert(!isSob());
      Pair<Key, Value>* result = &buff[offset--];
      return result;
    }
    /**@brief operator pre decrement will move iterator to previous item and return pointer to it*/
    Pair<Key, Value>* operator-- (){
      Assert(!isSob());
      Pair<Key, Value>* result = &buff[--offset];
      return result;
    }
    /**@brief operator equal checks if two iterators pointing to the same item*/
    bool operator== (const Iterator& value)const {
      return (&buff[offset] == &value.buff[value.offset]);
    }
    /**@brief operator not equal checks if two iterators pointing to different items*/
    bool operator!= (const Iterator& value)const {
      return !(*this == value);
    }
    /**@brief Checks if iterator is reached the end of list and doesn't point to any object*/
    bool isEob (void) const {
      return (offset >= count);
    }
    /**@brief Checks if iterator is pointing to the first object*/
    bool isSob (void) const {
      return offset == 0;
    }
  private:
    friend class Map;
    /**@brief Class constructor. Instance may be created only inside Map class
     * @param [in] buff   - pointer to array of objects
     * @param [in] count  - count of objects in the array
     * @param [in] offset - current position in the array
     */
    Iterator(Pair <Key, Value> *buff, size_t count, size_t offset = 0): buff(buff), count(count), offset(offset){ }
    Pair<Key, Value> *buff;  //!<pointer to array of objects
    size_t   count;          //!<count of objects in the array
    size_t   offset;         //!<current position in the array
  };

  /**@brief Class constructor
   * @param [in] buff - pointer to array of objects, will be automatically sorted
   * @param [in] max_map_size - size of array including already added objects and free space (in objects)
   * @param [in] map_size - count of objects prepared in the the array
   */
  Map(Pair <Key, Value> *buff, size_t max_map_size, size_t map_size = 0):
    buff(buff), map_size(map_size), max_map_size(max_map_size)
  {
    sort();
  }

  bool insert(Key key, Value value){
	  return insert(Pair<Key, Value>(key, value));
  }
  /**@brief Inserts new element to the map sorted by key values
   * @param [in] newItem - reference to new item for adding
   * @return @b true if item correctly added, @b false if there now space for new item
   */
  bool insert(Pair <Key, Value> &newItem){
    bool returnValue = false;
    ssize_t place = -1;
    ssize_t index = find(newItem.first, &place);
    if(index != -1){
      buff[index] = newItem;
      returnValue = true;
    }else if(map_size < max_map_size){
      Assert(place>=0);
      if(map_size){
        place++;
        memmove(buff + place + 1, buff + place, (map_size - place) * sizeof(buff[0]));
      }
      buff[place] = newItem;
      map_size++;
      returnValue = true;
    }
    return returnValue;
  }

  /**@brief Searches item by key value and returns index of found item
   * @param [in] keyElement - key value to search the item
   * @param [out] getFirst - if not null and there no equal element, then will contain lower index of nearest element
   * @return index of found item
   */
  ssize_t find(Key keyElement, ssize_t *getFirst = 0)const{
    BinarySearch<Key, const Map>searcher(map_size, this, &Map::compare_for_search);
    return searcher.search(keyElement, getFirst);
  }

  /**@brief Searches item by key value
   * @param [in] keyElement - key value to search the item
   * @return pointer to the value field if item was found, otherwise zero
   */
  Value *get_value(Key keyElement)const{
    ssize_t index = find(keyElement);
    Value *returnValue = 0;
    if(index != -1){
      returnValue = &buff[index]->second;
    }
    return returnValue;
  }

  /**@brief Searches element by key value and removes it from the Map
   * @param [in] keyElement - key value to find element for removing
   * @return @b true if element was found and @b false otherwise
   */
  bool remove(Key keyElement){
    bool returnValue = false;
    ssize_t index = find(keyElement);
    if(index != -1){
      ssize_t nextIndex = index + 1;
      memmove(buff + index, buff + nextIndex, (map_size - nextIndex) * sizeof(buff[0]));
      map_size--;
      returnValue = true;
    }
    return returnValue;
  }

  /**@brief Returns iterator pointing to the first item
   * @return iterator pointing to the first item
   */
  Iterator begin (void)const {
    return Iterator(buff, map_size);
  }

  /**@brief Returns iterator pointing to the last item
   * @return iterator pointing to the last item
   */
  Iterator end (void)const {
    return Iterator(buff, map_size, map_size);
  }

  /**@brief Returns count of items in the map
   * @return count of items in the map
   */
  size_t get_size (void)const{
    return map_size;
  }

  /**@brief Returns count of items in the map
  * @return count of items in the map
  */
  void clean (void)const{
    map_size = 0;
  }

private:
  void sort(){
    if(map_size > 0){
      Sorter<Pair <Key, Value>, Map>(buff, map_size, this, &Map::compare_for_sort).sort();
    }
  }

  Pair<Key, Value> *buff;
  size_t map_size;
  const size_t max_map_size;

  //Handler function
  ssize_t compare_for_search(const Key &value1, size_t value2)const{
        return value1 - buff[value2].first;
      }
  bool compare_for_sort(const Pair<Key, Value>& value1,const Pair<Key, Value>& value2)const{
    return value1 > value2;
  }
};


#endif /* SOURCE_COMMON_MAP_HPP_ */
