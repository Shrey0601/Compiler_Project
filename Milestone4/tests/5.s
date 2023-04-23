	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
Student : 
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
Student.square : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	subq $128, %rsp
	movq -8(%rbp), %rax
	movq -8(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -24(%rbp)
	movq -24(%rbp), %rax
	leave 
	ret 
	leave 
	ret 
TestStudent2 : 
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
	subq $128, %rsp
	movq $8, -32(%rbp)
	movq -32(%rbp), %rdi
	call malloc@PLT
	movq %rax, -40(%rbp)
	movq %r14, -48(%rbp)
	movq -40(%rbp), %r14
	call Student
	movq -48(%rbp), %r14
	movq -40(%rbp), %rax
	movq %rax, -16(%rbp)
	movq -40(%rbp), %rax
	movq $0, %rdx
	addq %rax, %rdx
	movq %rdx, -56(%rbp)
	movq -56(%rbp), %r13
	movq $101, (%r13)
	movq -40(%rbp), %rax
	movq %rax, -72(%rbp)
	movq -72(%rbp), %r8
	addq $0, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	pushq $10
	movq %r14, -80(%rbp)
	movq -16(%rbp), %r14
	call Student.square
	movq -80(%rbp), %r14
	movq %rax, -88(%rbp)
	movq -88(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
