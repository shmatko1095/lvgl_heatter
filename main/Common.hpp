/**
 * @file    Common.hpp
 * @author  msn@ektos.net (EKTOS A/S)
 * @date    created on Jul 12, 2017
 * @version 1.0
 * @brief   Common definitions header file
 * @note    Belongs to ESB project
 */

#ifndef COMMON_HPP_
#define COMMON_HPP_

//#include "Core.hpp"
#include "Types.h"
//#include "Compiler.hpp"

#define SIZE_OF_ARRAY(arr) (sizeof(arr)/sizeof(arr[0]))
#define ALIGN_SIZE(size, alignVal) ((size) + ((alignVal)-((size)%(alignVal))))

/**
 * @ingroup common_helpers
 * @brief Checks bool expression in runtime and if something went wrong stops program.
 * @param [in] condition true: all works as expected
 *                       false: something went wrong
 */
inline void Assert(bool condition) {
  assert(condition);
}

/**
 * @ingroup common_helpers
 * @brief Returns offset in bytes from start of structure or class to a member.
 * @tparam T Any structure or class
 * @param [in] member Member of structure or class to which offset will be calculated
 * @return Offset in bytes from start of structure or class to a member.
 */
template<typename T, typename M>
static inline size_t offsetOf(const M T::*member) {
  return (size_t) &(reinterpret_cast<T*>(0)->*member);
}

/**
 * @ingroup common_helpers
 * @brief Returns a reference to the object to which the member belongs.
 * @tparam T Type of member of structure or class of M type
 * @tparam M Type of any structure or class that contain members
 * @param [in] ptr Pointer to the member of structure or class
 * @param [in] member Reference to the member of structure or class
 * @return Reference to the object to which the member belongs.
 */
template<typename T, typename M>
static inline T &containerOf(M &ptr, M T::*member) {
  return *(T*) ((char*) &ptr - offsetOf(member));
}

/**
 * @ingroup common_helpers
 * @brief Returns a pointer to the object to which the member belongs.
 * @tparam T Type of member of structure or class of M type
 * @tparam M Type of any structure or class that contain members
 * @param [in] ptr Pointer to the member of structure or class
 * @param [in] member Pointer to the member of structure or class
 * @return Pointer to the object to which the member belongs or null.
 */
template<typename T, typename M>
static inline T *containerOfPtr(M *ptr, M T::*member) {
  return (ptr) ? &containerOf(*ptr, member) : 0;
}

/**
 * @ingroup common_helpers
 * @brief Compares two objects and return biggest.
 * @tparam T Any type that supports > operator
 * @param [in] a,b Values to compare.
 * @return The biggest of a and b. If both are equivalent, b is returned.
 */
template<typename T>
static inline T maximum(T a, T b) {
  return a > b ? a : b;
}

/**
 * @ingroup common_helpers
 * @brief Compares two objects and return smallest.
 * @tparam T Any type that supports < operator
 * @param [in] a,b Values to compare.
 * @return The smallest of a and b. If both are equivalent, b is returned.
 */
template<typename T>
static inline T minimum(T a, T b) {
  return a < b ? a : b;
}

/**
 * @ingroup common_helpers
 * @brief Calculates the absolute value of parameter.
 * @tparam T Any type that supports < and unary - operators
 * @param [in] a Absolute value will be calculated for this parameter.
 * @return The absolute value of parameter.
 */
template<typename T>
static inline T absolute(T a) {
  return a < 0 ? -a : a;
}

/**
 * @ingroup common_helpers
 * @brief Checks that difference between a and b is in the range of threshold value
 * @tparam T Any type that supports <, >, unary- and binary- operators
 * @param [in] a,b Operands for which difference will be calculated
 * @param [in] threshold The threshold value
 * @return true: The difference is more than the threshold value
 *         false: The difference is less than the threshold value
 */
template<typename T>
static inline bool checkOffset(T a, T b, T threshold) {
  return (absolute(a - b) > threshold);
}

/**
 * @ingroup common_helpers
 * @brief Calculates new tail index for circular sequence when subtracting items
 * @tparam T Any type that supports + and % operators
 * @param [in] tail Index of tail
 * @param [in] amount Number of items that will be subtracted
 * @param [in] size Size of circular sequence
 * @return New tail index
 */
template<typename T>
static inline T ringdelta(T tail, T amount, T size) {
  return (tail + size - amount) % size;
}

/**
 * @ingroup common_helpers
 * @brief Calculates new tail index for circular sequence when adding items
 * @tparam T Any type that supports + and % operators
 * @param [in] tail Index of tail
 * @param [in] amount Number of items that will be added
 * @param [in] size Size of circular sequence
 * @return New tail index
 */
template<typename T>
static inline T ringsum(T tail, T amount, T size) {
  return (tail + amount) % size;
}

/**
 * @ingroup common_helpers
 * @brief Exchanges the values of a and b.
 * @tparam T Any type that supports = operator and copy constructor.
 * @param [in] a,b Two objects, whose contents are swapped.
 */
template<typename T>
static inline void exchange(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

/**
 * @ingroup common_helpers
 * @brief Returns aligned size according to parameters.
 * @param [in] size is the number that will be checked for alignment requirements.
 * @param [in] alignVal is the "evenly divisible by" number that each instance needs to be at.
 * @return Aligned size according to parameters.
 */
static inline size_t alignSize(size_t size, size_t alignVal) {
  return size + (alignVal - (size % alignVal));
}

/**
 * @ingroup common_helpers
 * @brief Returns numbers of elements in array
 * @tparam T array type
 * @tparam array size
 * @return Numbers of elements in array
 */
template<typename T, size_t size>
static inline size_t sizeOfArray(const T (&)[size]) {
  return size;
}

/**
 * @ingroup common_helpers
 * @brief Checks whether the type is signed or not.
 * @tparam T Any numeric type
 * @param [in] val Param for checking.
 * @return true: If parameter is signed arithmetic type.
 *         false: If parameter is not signed arithmetic type.
 */
template<typename T>
static inline bool isSigned(T val = 0) {
  return ((T) -1) < 0;
}

/**
 * @ingroup common_helpers
 * @brief Returns the maximum finite value representable by the numeric type T.
 * @tparam T Any numeric type
 * @param [in] val Max value will be calculated for this parameter.
 * @return The maximum finite value representable by the numeric type T.
 */
template<typename T>
static inline T maxValue(T val = 0) {
  return -1LLU >> (isSigned(val) ? (sizeof(uint64_t) - sizeof(val)) * 8 + 1 : 0);
}

/**
 * @ingroup common_helpers
 * @brief Returns the minimum finite value representable by the numeric type T.
 * @tparam T Any numeric type
 * @param [in] val Min value will be calculated for this parameter.
 * @return The minimum finite value representable by the numeric type T.
 */
template<typename T>
static inline T minValue(T val = 0) {
  return maxValue(val) + 1;
}

/**
 * @ingroup common_helpers
 * @brief Returns mask with a size of a numeric type where all bits are setted
 * @tparam T Any numeric type
 * @param [in] val Any value, only type is matter
 * @return Mask with a size of a numeric type where all bits are setted
 */
template<typename T>
static inline T maskValue(T val = 0) {
  return ((T) -1);
}

/**
 * @ingroup common_helpers
 * @brief Returns the number of bits in the parameter type.
 * @tparam T Any type
 * @param [in] val The number of bits will be calculated for this parameter.
 * @return The number of bits in the parameter type.
 */
template<typename T>
static inline T bitCount(T val = 0) {
  return (sizeof(T) * 8);
}

/**
 * @ingroup common_helpers
 * @brief Returns bit mask with size of parameter value, where all bits installed in 1
 * @tparam T Any numeric type
 * @param [in] count The number of bits which will be set to 1
 * @return Bit mask
 */
template<typename T>
static inline T bitCountToMask(uint8_t count = 0) {
  return ((1UL << count) - 1);
}

/**
 * @ingroup common_helpers
 * @brief Constrains a number to be within a range.
 * @tparam T Any type that supports > and < operators
 * @param [in] a  The number to constrain
 * @param [in] min The lower end of the range
 * @param [in] max The upper end of the range
 * @return a: if x is between a and b
 *         min: if x is less than min
 *         max: if x is greater than max
 */
template<typename T>
static inline T corrected(T a, T min, T max) {
  return a > max ? max : a < min ? min : a;
}

/**
 * @ingroup common_helpers
 * @brief Sets (writes a 1 to) a bit of a numeric variable.
 * @tparam T Any numeric type
 * @param [in] var The numeric variable whose bit to set
 * @param [in] bit Which bit to set, starting at 0 for the least-significant (rightmost) bit
 */
template<typename T>
static inline void setBit(T var[], size_t bit) {
  var[bit / (sizeof(var[0]) * 8)] |= (1ul << (bit % (sizeof(var[0]) * 8)));
}

/**
 * @ingroup common_helpers
 * @brief Writes a 1 into bit of a numeric variable and clears other bits.
 * @tparam T Any numeric type
 * @param [in] var The numeric variable whose bit to set
 * @param [in] bit Which bit to set, starting at 0 for the least-significant (rightmost) bit
 */
template<typename T>
static inline void writeBit(T var[], size_t bit) {
  var[bit / (sizeof(var[0]) * 8)] = (1ul << (bit % (sizeof(var[0]) * 8)));
}

/**
 * @ingroup common_helpers
 * @brief Clears (writes a 0 to) a bit of a numeric variable.
 * @tparam T Any numeric type
 * @param [in] var The numeric variable whose bit to clear
 * @param [in] bit Which bit to clear, starting at 0 for the least-significant (rightmost) bit
 */
template<typename T>
static inline void resetBit(T var[], size_t bit) {
  var[bit / (sizeof(var[0]) * 8)] &= ~(1ul << (bit % (sizeof(var[0]) * 8)));
}

/**
 * @ingroup common_helpers
 * @brief Reads a bit of a number.
 * @tparam T Any numeric type
 * @param [in] var The number from which to read
 * @param [in] bit Which bit to read, starting at 0 for the least-significant (rightmost) bit
 * @return The value of the bit (0 or 1)(false or true).
 */
template<typename T>
static inline bool getBit(T var[], size_t bit) {
  return var[bit / (sizeof(var[0]) * 8)] & (1ul << (bit % (sizeof(var[0]) * 8)));
}

/**
 * @ingroup common_helpers
 * @brief Reads a bits of a number.
 * @tparam T Any numeric type
 * @param [in] var The number from which to read
 * @param [in] bitPosition From which bit to read, starting at 0 for the least-significant (rightmost) bit
 * @param [in] bitCount The number of bits to read
 * @return The value of the bits.
 */
template<typename T>
static inline T getBits(T &var, size_t bitPosition, size_t bitCount) {
  return (var >> bitPosition) & bitCountToMask<T>(bitCount);
}

/**
 * @ingroup common_helpers
 * @brief Sets (writes a 1 to) a bits of a numeric variable.
 * @tparam T Any numeric type
 * @param [in] var The numeric variable whose bits to set
 * @param [in] bitPosition From which bit to start, starting at 0 for the least-significant (rightmost) bit
 * @param [in] bitCount The number of bits to set
 * @param [in] val The value to be written
 * @return The number with wrote bits
 */
template<typename T>
static inline T &setBits(T &var, size_t bitPosition, size_t bitCount, const T &val) {
  T mask = bitCountToMask<T>(bitCount) << bitPosition;
  var &= ~mask;
  return var |= (val << bitPosition) & mask;
}

/**
 * @ingroup common_helpers
 * @brief Writes a 1 into bits of a numeric variable and clears other bits.
 * @tparam T Any numeric type
 * @param [in] var The numeric variable whose bits to set
 * @param [in] bitPosition From which bit to start, starting at 0 for the least-significant (rightmost) bit
 * @param [in] bitCount The number of bits to set
 * @param [in] val The value to be written
 * @return The number with wrote bits
 */
template<typename T>
static inline T &writeBits(T &var, size_t bitPosition, size_t bitCount, const T &val) {
  T mask = bitCountToMask<T>(bitCount) << bitPosition;
  return var = (val << bitPosition) & mask;
}

/**
 * @ingroup common_helpers
 * @brief Checks endianness of current CPU
 * @return true: if target CPU is BigEndia
 *         false: if target CPU has another endianness
 */
static inline bool isBigEndian() {
  uint32_t tst = 0x12345678;
  return ((uint8_t*) &tst)[0] == 0x12;
}

/**
 * @ingroup common_helpers
 * @brief Changes order of bytes from LittleEndian to BigEndian and vice versa
 * @tparam T Any numeric type
 * @param [in] val The value to be reordered
 * @return Reordered value
 */
template<typename T>
static inline T byteReverse(const T &val) {
  T result = 0;
  switch (sizeof(T)) {
    case 1:
      result = val;
      break;
    case 2:
      result = reverse16(val);
      break;
    case 4:
      result = reverse32(val);
      break;
    case 8:
      result = reverse64(val);
      break;
    default:
      Assert(0);
      break;
  }
  return result;
}

/**
 * @ingroup common_helpers
 * @brief Converts value to BigEndian if current CPU has another endianness
 * @tparam T Any numeric type
 * @param [in] val The value to be converted
 * @return Converted value
 */
template<typename T>
static inline T toBigEndian(T val) {
  return isBigEndian() ? val : byteReverse(val);
}

/**
 * @ingroup common_helpers
 * @brief Converts value to LittleEndian if current CPU has another endianness
 * @tparam T Any numeric type
 * @param [in] val The value to be converted
 * @return Converted value
 */
template<typename T>
static inline T toLittleEndian(const T &val) {
  return isBigEndian() ? byteReverse(val) : val;
}

/**
 * @ingroup common_helpers
 * @brief Converts value from BigEndian to current CPU endianness
 * @tparam T Any numeric type
 * @param [in] val The value to be converted
 * @return Converted value
 */
template<typename T>
static inline T fromBigEndian(const T &val) {
  return toBigEndian(val);
}

/**
 * @ingroup common_helpers
 * @brief Converts value from LittleEndian to current CPU endianness
 * @tparam T Any numeric type
 * @param [in] val The value to be converted
 * @return Converted value
 */
template<typename T>
static inline T fromLittleEndian(const T &val) {
  return toLittleEndian(val);
}

#endif /* SOURCE_COMMON_COMMON_HPP_ */
