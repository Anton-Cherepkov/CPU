#include <iostream>

#include "assembler.h"
#include "processor.h"
#include "disassembler.h"

int main() {
  /*assembler("fib.asm", "fib.bin");

  Processor processor;
  processor.load_program("fib.bin");
  processor.run_program();

  disassembler("fib.bin", "fib_disassembler.asm");*/

  assembler("discriminant.asm", "discriminant.bin");

  Processor processor;
  processor.load_program("discriminant.bin");
  processor.run_program();

  disassembler("discriminant.bin", "discriminant_disassembler.bin");

  return 0;
}