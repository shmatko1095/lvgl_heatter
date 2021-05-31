/**@file    List.hpp
 * @author  msn@ektos.net (EKTOS A/S)
 * @date    created on Jul 18, 2017
 * @version 1.0
 * @brief   Single linked list implementation
 * @note    Belongs to ESB project
 */
#ifndef SOURCE_COMMON_LIST_HPP_
#define SOURCE_COMMON_LIST_HPP_

#include "Common.hpp"
/**@brief Single linked list implementation
 * @ingroup common_helpers
 */
class List
{
public:
  /**@brief Single linked list item
   * @ingroup common_helpers
   */
  class Item
  {
  public:
	Item():next(0){}
//	Item(Item&):next(0){};
  private:
    void operator = (Item&);
    friend class List;
    friend class Itterator;
    Item *next;  //!< pointer to next item in the list
  };

  /**@brief Single linked list iterator
   * @ingroup common_helpers
   */
  class Itterator
  {
  public:
    /**@brief Casting to Item pointer type returns pointer to current item pointed by iterator*/
    operator Item*() { return current; }
    /**@brief Casting to const Item pointer type returns pointer to constant current item pointed by iterator*/
    operator const Item*() const { return current; }

    /**@brief Pre increment operator switches iterator to point to next item
     * @return Pointer to next item
     */
    Item* operator ++ () {
      eol() ? 0 : current = current->next;
      return current;
    }

    /**@brief Post increment operator switches iterator to point to next item
     * @return Pointer to current item
     */
    Item* operator ++ (int) {
      Item* i = current;
      eol() ? 0 : current = current->next;
      return i;
    }

    /**@brief End Of List checks if iterator reached the end of list
     * @return @b true if iterator is pointing to null, otherwise @b false
     */
    bool eol()const { return !current; }

    /**@brief If iterator ended then the iterator will point to defined item
     * @param [in] i - list item reference to point to, if iterator ended
     */
    void update(Item &i) { eol() ? current = &i : 0; }

  private:
    friend class List;
    Itterator(Item *current): current(current){}
    Item *current;
  };

  /**@brief Class constructor*/
  List() : first(0), last(0){}

  /**@brief Returns iterator pointing to first item in the list
   * @return iterator pointing to first item in the list
   */
  Itterator getItterator()const{return Itterator(first);}

  /**@brief Adds new item to the end of list
   * @param [in] i - reference to the item to be added
   */
  void addLast(Item &i) {
    Assert(!i.next && (&i != last));
    last ? last->next = &i : 0;
    last = &i;
    first ? 0 : first = &i;
  }

  /**@brief Adds new item to the start of list
   * @param [in] i - reference to the item to be added
   */
  void addFirst(Item &i) {
    Assert(!i.next && (&i != last));
    i.next = first;
    last ? 0 : last = &i;
    first = &i;
  }

  /**@brief Removes first item from list and returns pointer to it
   * @return pointer to first item in the list if it was there, otherwise null
   */
  Item *takeFirst(){
    Item *result = first;
    first ? first = first->next : 0;
    first ? 0: last = first;
    result? result->next = 0 : 0;
    return result;
  }

  /**@brief Checks if defined list item is first in the list
   * @param [in] pItem - List item pointer
   * @return @b true if item is first, otherwise @b false
   */
  bool isFirst(Item *pItem) const {return first == pItem;}

  /**@brief Checks if iterator pointing to the first item of list
   * @param [in] itt - iterator pointing to the item inside current list
   * @return @b true if item is first, otherwise @b false
   */
  bool isFirst(Itterator &itt) const {return first == itt.current;}

  /**@brief Checks if defined list item is last in the list
   * @param [in] pItem - List item pointer
   * @return @b true if item is last, otherwise @b false
   */
  bool isLast(Item *pItem) const {return last == pItem;}

  /**@brief Checks if iterator pointing to the last item of list
   * @param [in] itt - iterator pointing to the item inside current list
   * @return @b true if item is last, otherwise @b false
   */
  bool isLast(Itterator &itt) const {return last == itt.current;}

private:
  Item *first;  //!< pointer to first item in the list
  Item *last;   //!< pointer to last item in the list
};

#endif /* SOURCE_COMMON_LIST_HPP_ */
