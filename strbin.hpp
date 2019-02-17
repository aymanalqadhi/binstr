#ifndef LIB_STRBIN_H
#define LIB_STRBIN_H

#include <iostream>
#include <string>
#include <cassert>

namespace binstr
{
  /**
   * A Generic fucntion to convert binary strings to T integer
   *
   * @param str   The binary string to convert
   * @return The parsed value
   */
  template<class T>
  T ParseBinaryString(const std::string& str) 
  {
    assert(str.length() < sizeof(T) * 8);
    T ret = 0;

    for (int i = str.length() - 1; i >= 0; --i) {
      assert(str[i] == '1' || str[i] == '0');
      ret <<= 1;
      ret |= str[i] == '1';
    }
    return ret;
  }

  /**
   * A wrapper lambda for `ParseBinaryString` for 16bit integers.
   */
  auto ParseBinaryString16 = [](const std::string& str) -> std::uint16_t {
    return ParseBinaryString<std::uint16_t>(str);
  };

  /**
   * A wrapper lambda for `ParseBinaryString` for 32bit integers.
   */
  auto ParseBinaryString32 = [](const std::string& str) -> std::uint32_t {
    return ParseBinaryString<std::uint32_t>(str);
  };

  /**
   * A wrapper lambda for `ParseBinaryString` for 64bit integers.
   */
  auto ParseBinaryString64 = [](const std::string& str) -> std::uint64_t {
    return ParseBinaryString<std::uint64_t>(str);
  };

  /**
   * A Generic function to convert integer values into binary strings
   *
   * @param n   The integer value
   * @return The converted binary string
   */
  template<class T>
  std::string IntToBinString(T n)
  {
    const static auto len = sizeof(n) * 8;
    char ret[len];

    for (int i = len - 1; i >= 0; --i) {
      ret[len - 1 - i] = n & (1 << i) ? '1' : '0';
    }

    return std::string(std::move(ret));
  }
  
  /**
   * A wrapper lambda for `IntToBinString` for 16bit integers.
   */
  auto Int16ToBinString = [](std::uint16_t n) -> std::string {
    return IntToBinString<std::uint16_t>(n);
  };

  /**
   * A wrapper lambda for `IntToBinString` for 32bit integers.
   */
  auto Int32ToBinString = [](std::uint32_t n) -> std::string {
    return IntToBinString<std::uint32_t>(n);
  };

  /**
   * A wrapper lambda for `IntToBinString` for 64bit integers.
   */
  auto Int64ToBinString = [](std::uint64_t n) -> std::string {
    return IntToBinString<std::uint64_t>(n);
  };
}

#endif
