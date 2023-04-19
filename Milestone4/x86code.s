	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
GFG : 
	pushq %rbp
	movq %rsp, %rbp
	movq $0, %rax
	leave 
	ret 
Main : 
	pushq %rbp
	movq %rsp, %rbp
	movq $0, %rax
	leave 
	ret 
main : 
	pushq %rbp
	movq %rsp, %rbp
	subq $64, %rsp
	movq $16, -24(%rbp)
	movq -24(%rbp), %rdi
	call malloc@PLT
	movq %rax, -32(%rbp)
	pushq -32(%rbp)
	call GFG
	movq -32(%rbp), %rax
	movq %rax, -8(%rbp)
	movq -8(%rbp), %r14
	movq -8(%rbp), %r15
	movq -8(%rbp), %rcx
	addq $0, %rcx
	movq (%rcx), %rax
	movq %rax, -16(%rbp)
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
