rd_rax

push_rax

push_rax
pop_rbx

label 1

push_rax
push 1
je 2

push_rbx
push 1
push_rax
sub
mul
pop_rbx

push 1
push_rax
sub
pop_rax
jmp 1

label 2

shw_rbx
hlt