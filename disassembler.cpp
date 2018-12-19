//
// Created by anton on 19.12.18.
//

#include <fstream>
#include <iostream>

#include "disassembler.h"
#include "config.h"
#include "utils.h"
#include "assembler.h"

void disassembler(const char* bytecode_path, const char* output_path) {
  std::ifstream bytecode(bytecode_path, std::ios::binary);
  std::ofstream output(output_path);

  if (!bytecode.is_open()) {
    std::cerr << "Failed to open bytecode.\n";
    throw std::runtime_error("Failed to open bytecode");
  }

  if (!output.is_open()) {
    std::cerr << "Disassembler failed to open output file.\n";
    throw std::runtime_error("Disassembler failed to open output file");
  }



  while (true) {
    std::string instr_str(CMD_BYTES, '0');
    bytecode.read(&instr_str[0], CMD_BYTES);
    if (bytecode.fail()) {
      break;
    }

    int cmd_index = binary_to_integer(instr_str);

    output << cmd_names[cmd_index] << ' ';

    auto arg_num = cmd_arg_num[cmd_index];
    for (int i = 0; i < arg_num; ++i) {
      std::string arg(CMD_BYTES, '0');
      bytecode.read(&arg[0], CMD_BYTES);
      if (bytecode.fail()) {
        throw std::runtime_error("Disassembler failed");
      }
      output << binary_to_integer(arg);
      if (i < arg_num - 1) {
        output << ' ';
      }
    }
    output << '\n';
  }

  bytecode.close();
  output.close();
}