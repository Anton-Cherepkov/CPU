#define GET_ARG(n) instructions_[ip + n]

#define MOVE_IP(destination) ip = destination; jump_was_made = true; break;
#define TO_LABEL(name) MOVE_IP(label_pos_[name])
#define PERFORM_JMP TO_LABEL(GET_ARG(1));

#define FRONT_POP(var) var = stack_.top(); stack_.pop();
#define GET_1_FRONT_ELEMENT  StackElement s1; FRONT_POP(s1);
#define GET_2_FRONT_ELEMENTS StackElement s1, s2; FRONT_POP(s1); FRONT_POP(s2);

#define GET_INPUT_ELEMENT StackElement s1; std::cin >> s1;

// General commands

DEF_CMD(CMD_LABEL, "label", 1, {})
DEF_CMD(CMD_HLT, "hlt", 0, { return; })

DEF_CMD(CMD_SHOW,     "shw",     0, { std::cout << stack_.top() << '\n'; })
DEF_CMD(CMD_SHOW_RAX, "shw_rax", 0, { std::cout << rax_ << '\n'; })
DEF_CMD(CMD_SHOW_RBX, "shw_rbx", 0, { std::cout << rbx_ << '\n'; })
DEF_CMD(CMD_SHOW_RCX, "shw_rcx", 0, { std::cout << rcx_ << '\n'; })
DEF_CMD(CMD_SHOW_RDX, "shw_rdx", 0, { std::cout << rdx_ << '\n'; })

DEF_CMD(CMD_READ,     "rd",     0, { GET_INPUT_ELEMENT; stack_.push(s1); })
DEF_CMD(CMD_READ_RAX, "rd_rax", 0, { GET_INPUT_ELEMENT; rax_ = s1; })
DEF_CMD(CMD_READ_RBX, "rd_rbx", 0, { GET_INPUT_ELEMENT; rbx_ = s1; })
DEF_CMD(CMD_READ_RCX, "rd_rcx", 0, { GET_INPUT_ELEMENT; rcx_ = s1; })
DEF_CMD(CMD_READ_RDX, "rd_rdx", 0, { GET_INPUT_ELEMENT; rdx_ = s1; })

// Arithmetics

DEF_CMD(CMD_SQRT, "sqrt", 0, { GET_1_FRONT_ELEMENT; s1 = sqrt(s1); stack_.push(s1); })
DEF_CMD(CMD_ADD,  "add",  0, { GET_2_FRONT_ELEMENTS; stack_.push(s1 + s2); })
DEF_CMD(CMD_SUB,  "sub",  0, { GET_2_FRONT_ELEMENTS; stack_.push(s1 - s2); })
DEF_CMD(CMD_MUL,  "mul",  0, { GET_2_FRONT_ELEMENTS; stack_.push(s1 * s2); })
DEF_CMD(CMD_DIV,  "div",  0, { GET_2_FRONT_ELEMENTS; stack_.push(s1 / s2); })

// Stack commands

DEF_CMD(CMD_PUSH, "push", 1, { stack_.push(GET_ARG(1)); })
DEF_CMD(CMD_POP,  "pop",  0, { stack_.pop(); })

// Jump commands

DEF_CMD(CMD_JMP, "jmp", 1, { PERFORM_JMP; })
DEF_CMD(CMD_JE,  "je",  1, { GET_2_FRONT_ELEMENTS; if (s1 == s2) {PERFORM_JMP;} })
DEF_CMD(CMD_JNE, "jne", 1, { GET_2_FRONT_ELEMENTS; if (s1 != s2) {PERFORM_JMP;} })
DEF_CMD(CMD_JG,  "jg",  1, { GET_2_FRONT_ELEMENTS; if (s1 > s2)  {PERFORM_JMP;} })
DEF_CMD(CMD_JGE, "jge", 1, { GET_2_FRONT_ELEMENTS; if (s1 >= s2) {PERFORM_JMP;} })
DEF_CMD(CMD_JL,  "jl",  1, { GET_2_FRONT_ELEMENTS; if (s1 < s2)  {PERFORM_JMP;} })
DEF_CMD(CMD_JLE, "jle", 1, { GET_2_FRONT_ELEMENTS; if (s1 <= s2) {PERFORM_JMP;} })

// Register commands

DEF_CMD(CMD_PUSH_RAX, "push_rax", 0, { stack_.push(rax_); })
DEF_CMD(CMD_PUSH_RBX, "push_rbx", 0, { stack_.push(rbx_); })
DEF_CMD(CMD_PUSH_RCX, "push_rcx", 0, { stack_.push(rcx_); })
DEF_CMD(CMD_PUSH_RDX, "push_rdx", 0, { stack_.push(rdx_); })

DEF_CMD(CMD_POP_RAX, "pop_rax", 0, { FRONT_POP(rax_); })
DEF_CMD(CMD_POP_RBX, "pop_rbx", 0, { FRONT_POP(rbx_); })
DEF_CMD(CMD_POP_RCX, "pop_rcx", 0, { FRONT_POP(rcx_); })
DEF_CMD(CMD_POP_RDX, "pop_rdx", 0, { FRONT_POP(rdx_); })

// Custom commands

DEF_CMD(CMD_NO_SOLUTIONS, "nsl", 0, { std::cout << "No solutions\n"; })