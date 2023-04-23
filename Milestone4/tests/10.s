	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
Singleton : 
	pushq %rbp
	movq %rsp, %rbp
	movq %r14, %r9
	movq $0, %r8
	addq %r8, %r9
	movq $3, (%r9)
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	subq $64, %rsp
	movq %r14, %r8
	addq $8, %r8
	movq -16(%rbp), %rax
	movq %rax, (%r8)
	movq $0, %rax
	leave 
	ret 
Singleton.yo : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	subq $128, %rsp
	movq -8(%rbp), %rax
	movq -16(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -40(%rbp)
	movq -40(%rbp), %rax
	leave 
	ret 
	leave 
	ret 
main : 
	pushq %rbp
	movq %rsp, %rbp
	movq $24, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $128, %rsp
	movq $16, -40(%rbp)
	movq -40(%rbp), %rdi
	call malloc@PLT
	movq %rax, -48(%rbp)
	pushq $1
	pushq $5
	movq %r14, -56(%rbp)
	movq -48(%rbp), %r14
	call Singleton
	movq -56(%rbp), %r14
	movq -48(%rbp), %rax
	movq %rax, -8(%rbp)
	movq -48(%rbp), %rax
	movq %rax, -64(%rbp)
	movq -64(%rbp), %r8
	addq $0, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
Singleton.a : 
	pushq %rbp
	movq %rsp, %rbp
	subq $128, %rsp
	movq $3, -8(%rbp)
	movq $4, -16(%rbp)
	movq -8(%rbp), %rax
	movq -16(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -88(%rbp)
	movq -88(%rbp), %rax
	movq %rax, -24(%rbp)
	movq $0, %rax
	leave 
	ret 
