	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
Rectangle : 
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
Rectangle.insert : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	subq $256, %rsp
	movq %r14, %r8
	addq $0, %r8
	movq -8(%rbp), %rax
	movq %rax, (%r8)
	movq %r14, %r10
	addq $8, %r10
	movq -16(%rbp), %rax
	movq %rax, (%r10)
	movq $0, %rax
	leave 
	ret 
Rectangle.calculateArea : 
	pushq %rbp
	movq %rsp, %rbp
	subq $256, %rsp
	movq %r14, %r9
	addq $0, %r9
	movq %r14, %r8
	addq $8, %r8
	movq (%r9), %rax
	movq (%r8), %rdx
	imulq %rax, %rdx
	movq %rdx, -32(%rbp)
	movq -32(%rbp), %rax
	movq %rax, -8(%rbp)
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
TestRectangle1 : 
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
	movq $24, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $256, %rsp
	movq $16, -40(%rbp)
	movq -40(%rbp), %rdi
	call malloc@PLT
	movq %rax, -48(%rbp)
	movq %r14, -56(%rbp)
	movq -48(%rbp), %r14
	call Rectangle
	movq -56(%rbp), %r14
	movq -48(%rbp), %rax
	movq %rax, -16(%rbp)
	movq $16, -64(%rbp)
	movq -64(%rbp), %rdi
	call malloc@PLT
	movq %rax, -72(%rbp)
	movq %r14, -80(%rbp)
	movq -72(%rbp), %r14
	call Rectangle
	movq -80(%rbp), %r14
	movq -72(%rbp), %rax
	movq %rax, -24(%rbp)
	pushq $5
	pushq $11
	movq %r14, -88(%rbp)
	movq -16(%rbp), %r14
	call Rectangle.insert
	movq -88(%rbp), %r14
	movq %rax, -96(%rbp)
	pushq $15
	pushq $3
	movq %r14, -104(%rbp)
	movq -24(%rbp), %r14
	call Rectangle.insert
	movq -104(%rbp), %r14
	movq %rax, -112(%rbp)
	movq %r14, -120(%rbp)
	movq -16(%rbp), %r14
	call Rectangle.calculateArea
	movq -120(%rbp), %r14
	movq %rax, -128(%rbp)
	movq %r14, -136(%rbp)
	movq -24(%rbp), %r14
	call Rectangle.calculateArea
	movq -136(%rbp), %r14
	movq %rax, -144(%rbp)
	movq $0, %rax
	leave 
	ret 
