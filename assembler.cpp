//
// Created by anton on 19.12.18.
//

#include "assembler.h"
#include "utils.h"
#include "config.h"

#include <iostream>
#include <fstream>
#include <bitset>

int find_cmd_index(const std::string& name) {
  for (int cmd_index = 0; cmd_index < CMD_COUNT; ++cmd_index) {
    if (cmd_names[cmd_index] == name) {
      return cmd_index;
    }
  }
  return -1;
}

void assembler(const char* input, const char* output) {
  std::ifstream input_file(input);
  std::ofstream bytecode(output, std::ios::binary);

  if (!input_file.is_open()) {
    std::cerr << "Assembler failed to open input file.\n";
    throw std::runtime_error("Assembler failed to open input file");
  }

  if (!bytecode.is_open()) {
    std::cerr << "Assembler failed to open output file.\n";
    throw std::runtime_error("Assembler failed to open output file");
  }

  int line_index = 0;
  for (std::string line; getline(input_file, line); ++line_index) {
    // Tokenize line
    auto tokens = split_string_by_whitespaces(line);
    if (tokens.empty()) {
      continue;
    }

    // Detect cmd
    int cmd_index = find_cmd_index(tokens[0]);
    if (cmd_index == -1) {
      std::cerr << "Unknown command at line " << line_index << "\n";
      throw std::runtime_error("Unknown command");
    }

    // Check number of arguments
    if (tokens.size() - 1 != cmd_arg_num[cmd_index]) {
      std::cerr << "Assembler failed! Wrong number of arguments at line ";
      std::cerr << line_index << ". Arguments expected: " << cmd_arg_num[cmd_index] << "\n";
      throw std::runtime_error("Wrong number of arguments");
    }

    // Cmd index -> bytecode
    bytecode << integer_to_binary<CMD_BYTES>(cmd_index);

    // Args -> bytecode
    for (size_t arg_num = 1; arg_num < tokens.size(); ++arg_num) {
      bytecode << integer_to_binary<CMD_BYTES>(std::stoi(tokens[arg_num]));
    }
  }

  input_file.close();
  bytecode.close();
}