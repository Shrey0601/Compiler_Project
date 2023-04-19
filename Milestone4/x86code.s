	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
Main : 
	pushq %rbp
	movq %rsp, %rbp
	movq $0, %rax
	leave 
	ret 
sum : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	movq 32(%rbp), %rdx
	movq %rdx, -24(%rbp)
	subq $64, %rsp
	movq -8(%rbp), %rax
	movq -16(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -32(%rbp)
	movq -32(%rbp), %rax
	movq -24(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -40(%rbp)
	movq -40(%rbp), %rax
	leave 
	ret 
main : 
	pushq %rbp
	movq %rsp, %rbp
	movq $32, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $128, %rsp
	movq $1, -8(%rbp)
	movq $2, -16(%rbp)
	movq $3, -24(%rbp)
	movq -16(%rbp), %rax
	movq -24(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -56(%rbp)
	pushq -24(%rbp)
	pushq -56(%rbp)
	pushq -8(%rbp)
	call sum
	movq %rax, -64(%rbp)
	movq -64(%rbp), %rax
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
