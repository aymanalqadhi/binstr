#ifndef LIB_BINSTR_H
#define LIB_BITSTR_H

#include <cstddef>
#include <cassert>

#include <string>

namespace binstr
{
  /**
   * A Generic fucntion to convert binary strings to T integer
   *
   * @param str   The binary string to convert
   * @return The parsed value
   */
  template<class T>
  const T ParseBinaryString(const std::string& str) noexcept
  {
    assert(str.length() <= sizeof(T) * 8);
    T ret = 0;

    for (int i = str.length() - 1; i >= 0; --i) {
      assert(str[i] == '1' || str[i] == '0');
      ret |= (str[i] == '1') << (str.length() - 1 - i);
    }
    return ret;
  }

  /**
   * A wrapper function for `ParseBinaryString` for 16bit integers.
   */
  inline const std::uint16_t ParseBinaryString16(const std::string& str) noexcept
  {
    return ParseBinaryString<std::uint16_t>(str);
  }

  /**
   * A wrapper function for `ParseBinaryString` for 32bit integers.
   */
  inline const std::uint32_t ParseBinaryString32(const std::string& str) noexcept
  {
    return ParseBinaryString<std::uint32_t>(str);
  }

  /**
   * A wrapper function for `ParseBinaryString` for 64bit integers.
   */
  inline const std::uint64_t ParseBinaryString64(const std::string& str) noexcept
  {
    return ParseBinaryString<std::uint64_t>(str);
  }

  /**
   * A Generic function to convert integer values into binary strings
   *
   * @param n   The integer value
   * @return The converted binary string
   */
  template<class T>
  const std::string IntToBinString(T n) noexcept
  {
    std::string ret;
    ret.reserve(sizeof(n) * 8);

    for (int i = (sizeof(n) * 8) - 1; i >= 0; --i) {
      ret += n & (1 << i) ? '1' : '0';
    }

    return ret;
  }
  
  /**
   * A wrapper function for `IntToBinString` for 16bit integers.
   */
  inline const std::string Int16ToBinString(std::uint16_t n) noexcept {
    return IntToBinString<std::uint16_t>(n);
  }

  /**
   * A wrapper function for `IntToBinString` for 32bit integers.
   */
  inline const std::string Int32ToBinString(std::uint32_t n) noexcept {
    return IntToBinString<std::uint32_t>(n);
  }

  /**
   * A wrapper function for `IntToBinString` for 64bit integers.
   */
  inline const std::string Int64ToBinString(std::uint64_t n) noexcept {
    return IntToBinString<std::uint64_t>(n);
  }
}

#endif
