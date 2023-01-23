	.text
	.comm a,40
	.text
   .globl setup
  .type   setup, @function
setup:
	// callee save
	pushq %rbx
	pushq %rbp
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $128, %rsp
	movl $0, %r10d
	movl %r10d, 4(%rsp)
LABEL1:
	movl 4(%rsp), %r10d
	movl %edi, %r11d
	cmpl %r11d, %r10d
	setl	%al
	movzbl %al, %r10d
	cmpl $0, %r10d
	je	LABEL2
	movl 4(%rsp), %r11d
	//input
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	call minlisp_input
	// caller restore
	movq 64(%rsp), %rdi
	movq 72(%rsp), %rsi
	movq 80(%rsp), %rdx
	movq 88(%rsp), %rcx
	movq 96(%rsp), %r8
	movq 104(%rsp), %r9
	movq 112(%rsp), %r10
	movq 120(%rsp), %r11
	movl %eax, %ebx
	movl %ebx, a(,%r11,4)
	movl 4(%rsp), %ebx
	movl $1, %ebp
	addl %ebp, %ebx
	movl %ebx, 4(%rsp)
	jmp LABEL1
LABEL2:
	// end of function
	movl %ebx, %eax
	addq $128, %rsp
	// callee restore
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	ret
	.size   setup, .-setup
	.text
   .globl findsmallest
  .type   findsmallest, @function
findsmallest:
	// callee save
	pushq %rbx
	pushq %rbp
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $128, %rsp
	movl $1, %r10d
	movl %edi, %r11d
	addl %r11d, %r10d
	movl %r10d, 4(%rsp)
	movl %edi, %r10d
	movl %r10d, 8(%rsp)
LABEL3:
	movl 4(%rsp), %r10d
	movl %esi, %r11d
	cmpl %r11d, %r10d
	setl	%al
	movzbl %al, %r10d
	cmpl $0, %r10d
	je	LABEL4
	movl 4(%rsp), %r11d
	movl a(,%r11,4), %ebx
	movl 8(%rsp), %ebp
	movl a(,%ebp,4), %r12d
	cmpl %r12d, %ebx
	setl	%al
	movzbl %al, %ebx
	cmpl $0, %ebx
	je	LABEL5
	movl 4(%rsp), %r12d
	jmp	LABEL6
LABEL5:
	movl 8(%rsp), %r13d
	movl %r13d,%r12d
LABEL6:
	movl %r12d, 8(%rsp)
	movl 4(%rsp), %r13d
	movl $1, %ebx
	addl %ebx, %r13d
	movl %r13d, 4(%rsp)
	jmp LABEL3
LABEL4:
	movl 8(%rsp), %r10d
	// end of function
	movl %r10d, %eax
	addq $128, %rsp
	// callee restore
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	ret
	.size   findsmallest, .-findsmallest
	.text
   .globl outputarray
  .type   outputarray, @function
outputarray:
	// callee save
	pushq %rbx
	pushq %rbp
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $128, %rsp
	movl $0, %r10d
	movl %r10d, 4(%rsp)
LABEL7:
	movl 4(%rsp), %r10d
	movl %edi, %r11d
	cmpl %r11d, %r10d
	setl	%al
	movzbl %al, %r10d
	cmpl $0, %r10d
	je	LABEL8
	movl 4(%rsp), %r11d
	movl a(,%r11,4), %ebx
	//printf
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	movl %ebx, %esi
	movq S1(%rip), %rdi
	movl $0, %eax
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
	movl 4(%rsp), %ebp
	movl $1, %r12d
	addl %r12d, %ebp
	movl %ebp, 4(%rsp)
	jmp LABEL7
LABEL8:
	// end of function
	movl %ebp, %eax
	addq $128, %rsp
	// callee restore
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	ret
	.size   outputarray, .-outputarray
	.text
   .globl swaparray
  .type   swaparray, @function
swaparray:
	// callee save
	pushq %rbx
	pushq %rbp
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $128, %rsp
	movl $0, %r10d
	movl %r10d, 4(%rsp)
	movl %edi, %r10d
	movl a(,%r10,4), %r11d
	movl %r11d, 4(%rsp)
	movl %edi, %ebx
	movl %esi, %ebp
	movl a(,%ebp,4), %r12d
	movl %r12d, a(,%ebx,4)
	movl %esi, %r12d
	movl 4(%rsp), %r13d
	movl %r13d, a(,%r12,4)
	// end of function
	movl %r12d, %eax
	addq $128, %rsp
	// callee restore
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	ret
	.size   swaparray, .-swaparray
	.text
   .globl insertsort
  .type   insertsort, @function
insertsort:
	// callee save
	pushq %rbx
	pushq %rbp
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $128, %rsp
	movl $0, %r10d
	movl %r10d, 4(%rsp)
	movl %edi, %r10d
	movl $1, %r11d
	subl %r11d, %r10d
	movl %r10d, 8(%rsp)
	movl $0, %r10d
	movl %r10d, 12(%rsp)
LABEL9:
	movl 4(%rsp), %r10d
	movl 8(%rsp), %r11d
	cmpl %r11d, %r10d
	setl	%al
	movzbl %al, %r10d
	cmpl $0, %r10d
	je	LABEL10
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	//parameter
	movl 4(%rsp), %r11d
	movl %r11d, %edi
	movl 8(%rsp), %r11d
	movl $1, %ebx
	addl %ebx, %r11d
	movl %r11d, %esi
	call findsmallest
	// caller restore
	movq 64(%rsp), %rdi
	movq 72(%rsp), %rsi
	movq 80(%rsp), %rdx
	movq 88(%rsp), %rcx
	movq 96(%rsp), %r8
	movq 104(%rsp), %r9
	movq 112(%rsp), %r10
	movq 120(%rsp), %r11
	movl %eax, %r11d
	movl %r11d, 12(%rsp)
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	//parameter
	movl 12(%rsp), %ebx
	movl %ebx, %edi
	movl 4(%rsp), %ebx
	movl %ebx, %esi
	call swaparray
	// caller restore
	movq 64(%rsp), %rdi
	movq 72(%rsp), %rsi
	movq 80(%rsp), %rdx
	movq 88(%rsp), %rcx
	movq 96(%rsp), %r8
	movq 104(%rsp), %r9
	movq 112(%rsp), %r10
	movq 120(%rsp), %r11
	movl %eax, %ebx
	movl 4(%rsp), %ebp
	movl $1, %r12d
	addl %r12d, %ebp
	movl %ebp, 4(%rsp)
	jmp LABEL9
LABEL10:
	// end of function
	movl %ebp, %eax
	addq $128, %rsp
	// callee restore
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	ret
	.size   insertsort, .-insertsort
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
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	//parameter
	movl $10, %r10d
	movl %r10d, %edi
	call setup
	// caller restore
	movq 64(%rsp), %rdi
	movq 72(%rsp), %rsi
	movq 80(%rsp), %rdx
	movq 88(%rsp), %rcx
	movq 96(%rsp), %r8
	movq 104(%rsp), %r9
	movq 112(%rsp), %r10
	movq 120(%rsp), %r11
	movl %eax, %r10d
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	//parameter
	movl $10, %r11d
	movl %r11d, %edi
	call outputarray
	// caller restore
	movq 64(%rsp), %rdi
	movq 72(%rsp), %rsi
	movq 80(%rsp), %rdx
	movq 88(%rsp), %rcx
	movq 96(%rsp), %r8
	movq 104(%rsp), %r9
	movq 112(%rsp), %r10
	movq 120(%rsp), %r11
	movl %eax, %r11d
	movl $9999999, %ebx
	//printf
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	movl %ebx, %esi
	movq S1(%rip), %rdi
	movl $0, %eax
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
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	//parameter
	movl $10, %ebp
	movl %ebp, %edi
	call insertsort
	// caller restore
	movq 64(%rsp), %rdi
	movq 72(%rsp), %rsi
	movq 80(%rsp), %rdx
	movq 88(%rsp), %rcx
	movq 96(%rsp), %r8
	movq 104(%rsp), %r9
	movq 112(%rsp), %r10
	movq 120(%rsp), %r11
	movl %eax, %ebp
	// caller save
	movq %rdi, 64(%rsp)
	movq %rsi, 72(%rsp)
	movq %rdx, 80(%rsp)
	movq %rcx, 88(%rsp)
	movq %r8, 96(%rsp)
	movq %r9, 104(%rsp)
	movq %r10, 112(%rsp)
	movq %r11, 120(%rsp)
	//parameter
	movl $10, %r12d
	movl %r12d, %edi
	call outputarray
	// caller restore
	movq 64(%rsp), %rdi
	movq 72(%rsp), %rsi
	movq 80(%rsp), %rdx
	movq 88(%rsp), %rcx
	movq 96(%rsp), %r8
	movq 104(%rsp), %r9
	movq 112(%rsp), %r10
	movq 120(%rsp), %r11
	movl %eax, %r12d
	// end of function
	movl %r12d, %eax
	addq $128, %rsp
	// callee restore
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbp
	popq %rbx
	ret
	.size   minlisp_main, .-minlisp_main
	.section        .note.GNU-stack,"",@progbits
