	.section    .rodata
.LC0:
	.string    "%d\n"
	.text
	.globl    main
GFG : 
sum : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	subq $64, %rsp
	movq -8(%rbp), %rax
	movq -16(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -32(%rbp)
	movq -32(%rbp), %rax
	movq %rax, -24(%rbp)
	movq -24(%rbp), %rax
	leave 
	ret 
main : 
	pushq %rbp
	movq %rsp, %rbp
	subq $64, %rsp
	movq $1, -8(%rbp)
	movq $5, -16(%rbp)
	movq $4, -24(%rbp)
	movq -16(%rbp), %rax
	movq $2, %rcx
	xorq %rcx, %rax
	movq %rax, -48(%rbp)
	movq -48(%rbp), %rax
	movq %rax, -32(%rbp)
	movq -32(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
