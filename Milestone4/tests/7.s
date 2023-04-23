	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
FibonacciExample1 : 
	pushq %rbp
	movq %rsp, %rbp
	movq $0, %rax
	leave 
	ret 
	pushq %rbp
	movq %rsp, %rbp
	movq $0, %rax
	leave 
	ret 
main : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq $48, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $128, %rsp
	movq $0, -16(%rbp)
	movq $1, -24(%rbp)
	movq $10, -48(%rbp)
	movq $2, -40(%rbp)
L1 : 
	movq -40(%rbp), %rax
	movq -48(%rbp), %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -56(%rbp)
	movq -56(%rbp), %rax
	cmp $0, %rax
	je L2
	jmp L3
L4 : 
	movq -40(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -64(%rbp)
	movq -64(%rbp), %rax
	movq %rax, -40(%rbp)
	jmp L1
L3 : 
	movq -16(%rbp), %rax
	movq -24(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -72(%rbp)
	movq -72(%rbp), %rax
	movq %rax, -32(%rbp)
	movq -24(%rbp), %rax
	movq %rax, -16(%rbp)
	movq -32(%rbp), %rax
	movq %rax, -24(%rbp)
	movq -32(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	jmp L4
L2 : 
	movq $0, %rax
	leave 
	ret 
