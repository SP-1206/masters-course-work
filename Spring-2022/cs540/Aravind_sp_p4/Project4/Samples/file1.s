	.text
.globl minlisp_main
	.type   minlisp_main, @function
minlisp_main:
// callee save 
	pushq %rbx
	pushq %rbp
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $128, %rsp
	movl $22, %r10d
	movl $20, %r11d
	addl %r11d, %r10d
	movl $5, %r11d
	movl $2, %ebx
	negl %ebx
	imull %ebx, %r11d
	subl %r11d, %r10d
// printf
	movl %r10d, %esi
	movq S1(%rip), %rdi
	movl $0, %eax
// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	call printf
// caller restore 
	movq 64(%rsp), %rdi
	movq 72(%rsp), %rsi
	movq 80(%rsp), %rdx
	movq 88(%rsp), %rcx
	movq 96(%rsp), %r8
	movq 104(%rsp), %r9
	movq 112(%rsp), %r10
	movq 120(%rsp), %r11
// saving main with 0 vars
// end of function
	movl %r10d, %eax
	addq    $128, %rsp
// callee restore 
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	ret
	.size   minlisp_main, .-minlisp_main
// saving global with 0 vars
// name: main ctr: 0
	.section        .note.GNU-stack,"",@progbits
