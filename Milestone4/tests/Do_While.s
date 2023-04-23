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
	movq $16, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $64, %rsp
	movq $0, -16(%rbp)
L1 : 
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq -16(%rbp), %rax
	movq %rax, -24(%rbp)
	movq -24(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -16(%rbp)
	movq -16(%rbp), %rax
	movq $10, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -32(%rbp)
	movq -32(%rbp), %rax
	cmp $0, %rax
	je L2
	jmp L1
L2 : 
	movq $0, %rax
	leave 
	ret 
