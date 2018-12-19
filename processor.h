//
// Created by anton on 19.12.18.
//

#ifndef CPU_PROCESSOR_H
#define CPU_PROCESSOR_H

#include "config.h"

struct Processor {
  // Stack
  ProcessorStack stack_;

  // Registers
  StackElement   rax_{DefaultRegisterValue};
  StackElement   rbx_{DefaultRegisterValue};
  StackElement   rcx_{DefaultRegisterValue};
  StackElement   rdx_{DefaultRegisterValue};

  // Instructions
  Instructions instructions_;

  // Labels
  LabelPositions label_pos_;

  void load_instructions(const char*);

  void detect_labels();

  void load_program(const char*);

  void run_program();
};

#endif //CPU_PROCESSOR_H
