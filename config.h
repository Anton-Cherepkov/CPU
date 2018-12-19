//
// Created by anton on 19.12.18.
//
#ifndef CPU_CONFIG_H
#define CPU_CONFIG_H

#include <stack>
#include <vector>
#include <unordered_map>

#define CMD_BYTES 32

#define DefaultRegisterValue 0

extern std::string cmd_names[];
extern const int cmd_arg_num[];

#define DEF_CMD(enum_name, name, arg_num, code) enum_name,
enum {
#include "commands.asm"
  CMD_COUNT
};
#undef DEF_CMD

typedef double StackElement;

typedef std::stack<StackElement> ProcessorStack;

typedef int Instruction;

typedef std::vector<Instruction> Instructions;

typedef std::unordered_map<int, size_t> LabelPositions;

#endif //CPU_CONFIG_H
