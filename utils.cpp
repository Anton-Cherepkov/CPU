//
// Created by anton on 19.12.18.
//

#include "utils.h"

#include <vector>
#include <string>
#include <sstream>
#include <bitset>
#include <cassert>

std::vector<std::string> split_string_by_whitespaces(const std::string& str) {
  std::vector<std::string> result;
  std::string buffer;
  std::stringstream ss(str);
  while (ss >> buffer) result.push_back(buffer);
  return result;
}

int binary_to_integer(std::string str) {
  bool is_negative = str[0] - '0';
  str[0] = '0';
  int result = std::stoi(str, nullptr, 2);
  if (is_negative) {
    result *= -1;
  }
  return result;
}