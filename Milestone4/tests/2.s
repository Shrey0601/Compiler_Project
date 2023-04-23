	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
TypeCheck1 : 
	pushq %rbp
	movq %rsp, %rbp
	movq %r14, %r9
	movq $0, %r8
	addq %r8, %r9
	movq $5, (%r9)
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	subq $128, %rsp
	movq %r14, %r11
	addq $0, %r11
	movq -8(%rbp), %rax
	movq %rax, (%r11)
	movq %r14, %r8
	addq $0, %r8
	movq $100, (%r8)
	movq %r14, %r12
	addq $8, %r12
	movq -16(%rbp), %rax
	movq %rax, (%r12)
	movq $0, %rax
	leave 
	ret 
TypeCheck1.getA : 
	pushq %rbp
	movq %rsp, %rbp
	subq $128, %rsp
	movq %r14, %r13
	addq $0, %r13
	movq (%r13), %rax
	leave 
	ret 
	leave 
	ret 
TypeCheck1.getB : 
	pushq %rbp
	movq %rsp, %rbp
	subq $128, %rsp
	movq %r14, %r11
	addq $8, %r11
	movq (%r11), %rax
	leave 
	ret 
	leave 
	ret 
TypeCheck1.setA : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	subq $128, %rsp
	movq %r14, %r12
	addq $0, %r12
	movq -8(%rbp), %rax
	movq %rax, (%r12)
	movq $0, %rax
	leave 
	ret 
TypeCheck1.setB : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	subq $128, %rsp
	movq %r14, %r13
	addq $8, %r13
	movq -8(%rbp), %rax
	movq %rax, (%r13)
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
	subq $256, %rsp
	movq $16, -104(%rbp)
	movq -104(%rbp), %rdi
	call malloc@PLT
	movq %rax, -112(%rbp)
	pushq $2
	pushq $1
	movq %r14, -120(%rbp)
	movq -112(%rbp), %r14
	call TypeCheck1
	movq -120(%rbp), %r14
	movq -112(%rbp), %rax
	movq %rax, -16(%rbp)
	movq -16(%rbp), %r9
	addq $0, %r9
	movq (%r9), %rax
	movq %rax, -24(%rbp)
	movq -16(%rbp), %r10
	addq $8, %r10
	movq (%r10), %rax
	movq %rax, -32(%rbp)
	movq -112(%rbp), %rax
	movq %rax, -128(%rbp)
	movq -128(%rbp), %r8
	addq $0, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq -32(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
