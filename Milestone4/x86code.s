	.section    .rodata
.LC0:
	.string    "%d\n"
	.text
	.globl    main
GFG : 
main : 
	pushq %rbp
	movq %rsp, %rbp
	movq $4, -8(%rbp)
	movq $3, -16(%rbp)
	movq $8, -24(%rbp)
	movq $7, -32(%rbp)
	movq -8(%rbp), %rcx
	movq $8, %rax
	movq $3, -8(%rbp)
	cltd 
	idivq -8(%rbp)
	movq %rdx, -48(%rbp)
	movq %rcx, -8(%rbp)
	movq -48(%rbp), %rax
	movq %rax, -40(%rbp)
	movq -40(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
