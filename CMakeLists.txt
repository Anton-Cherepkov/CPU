cmake_minimum_required(VERSION 3.9)
project(CPU)

set(CMAKE_CXX_STANDARD 11)

add_executable(CPU main.cpp assembler.cpp assembler.h utils.cpp utils.h processor.cpp processor.h config.h config.cpp disassembler.cpp disassembler.h)