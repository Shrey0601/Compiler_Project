	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
SyntaxCheck : 
	pushq %rbp
	movq %rsp, %rbp
	movq %r14, %r9
	movq $0, %r8
	addq %r8, %r9
	movq $0, (%r9)
	movq $0, %rax
	leave 
	ret 
	pushq %rbp
	movq %rsp, %rbp
	movq $0, %rax
	leave 
	ret 
SyntaxCheck.printFunc : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	subq $64, %rsp
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
main : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq $32, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $128, %rsp
	movq $5, -16(%rbp)
	movq $10, -24(%rbp)
	movq -16(%rbp), %rax
	movq %rax, -40(%rbp)
	movq -40(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -16(%rbp)
	movq -16(%rbp), %rax
	movq -24(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -48(%rbp)
	pushq -48(%rbp)
	movq %r14, -56(%rbp)
	call SyntaxCheck.printFunc
	movq -56(%rbp), %r14
	movq %rax, -64(%rbp)
	movq $0, %rax
	leave 
	ret 
