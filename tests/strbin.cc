#include "strbin.hpp"

#include <iostream>
#include <cassert>
#include <ctime>

#define BINSTR16  "1111000011110000"
#define BINSTRV16 0xF0F0

#define BINSTR32  "11110000111100001111111100000000"
#define BINSTRV32 0xF0F0FF00

int main()
{
  std::cout << "[+] Testing string to int conversion..." << std::endl;

  std::clock_t start = clock();
  assert(binstr::ParseBinaryString16(BINSTR16) == BINSTRV16);
  assert(binstr::ParseBinaryString32(BINSTR32) == BINSTRV32);
  std::cout << "Done in: " << (clock() - start) << " ticks." << std::endl;

  std::cout << "[+] Testing int to string conversion..." << std::endl;

  start = clock();
  assert(binstr::Int16ToBinString(BINSTRV16) == BINSTR16);
  assert(binstr::Int32ToBinString(BINSTRV32) == BINSTR32);
  std::cout << "Done in: " << (clock() - start) << " ticks." << std::endl;

  return 0;
}
