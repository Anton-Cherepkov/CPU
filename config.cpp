//
// Created by anton on 19.12.18.
//

#include "config.h"

#define DEF_CMD(enum_name, name, arg_num, code) name,
std::string cmd_names[] = {
  #include "commands.asm"
};
#undef DEF_CMD

#define DEF_CMD(enum_name, name, arg_num, code) arg_num,
const int cmd_arg_num[] = {
  #include "commands.asm"
};
#undef DEF_CMD