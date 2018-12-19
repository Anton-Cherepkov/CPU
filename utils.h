//
// Created by anton on 19.12.18.
//

#ifndef CPU_UTILS_H
#define CPU_UTILS_H

#include <vector>
#include <string>
#include <sstream>
#include <bitset>
#include <iostream>

std::vector<std::string> split_string_by_whitespaces(const std::string&);

int binary_to_integer(std::string);

template <std::size_t N>
std::string integer_to_binary(int number) {
  bool is_negative = number < 0;
  std::string res = std::bitset<N>(is_negative ? -number : number).to_string();
  res[0] = '0' + is_negative;
  return res;
}

#endif //CPU_UTILS_H
