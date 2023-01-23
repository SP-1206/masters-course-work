movl $42, %r10d
movl %r10d, %esi
movq S1(%rip), %rdi
movl $0, %eax
call printf
