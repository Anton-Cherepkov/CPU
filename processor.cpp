//
// Created by anton on 19.12.18.
//

#include <fstream>
#include <iostream>
#include <cmath>
#include "processor.h"
#include "utils.h"

void Processor::load_instructions(const char* bytecode_path) {
  std::ifstream bytecode(bytecode_path, std::ios::binary);
  if (!bytecode.is_open()) {
    std::cerr << "Failed to open bytecode.\n";
    throw std::runtime_error("Failed to open bytecode");
  }

  while (true) {
    std::string instr_str(CMD_BYTES, '0');
    bytecode.read(&instr_str[0], CMD_BYTES);
    if (bytecode.fail()) {
      break;
    }
    Instruction instruction = binary_to_integer(instr_str);
    instructions_.push_back(instruction);
  }
}

void Processor::detect_labels() {
  for (size_t ip = 0; ip < instructions_.size(); ip += cmd_arg_num[instructions_[ip]] + 1) {
    if (instructions_[ip] == CMD_LABEL) {
      auto label_name = instructions_[ip + 1];
      label_pos_[label_name] = ip;
    }
  }
}

void Processor::load_program(const char* bytecode_path) {
  load_instructions(bytecode_path);
  detect_labels();
}


#define DEF_CMD(enum_name, name, arg_num, code) \
    case enum_name:                             \
    {                                           \
        code                                    \
        break;                                  \
    }                                           \

void Processor::run_program() {
  int ip = 0;
  while (ip < instructions_.size()) {
    bool jump_was_made = false;

    switch (instructions_[ip]) {
      #include "commands.asm"
      default:
        throw std::runtime_error("Unknown instruction found");
    }

    if (!jump_was_made) {
      ip += cmd_arg_num[instructions_[ip]] + 1;
    }
  }
}

#undef DEF_CMD