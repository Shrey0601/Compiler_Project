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
main : 
	pushq %rbp
	movq %rsp, %rbp
	subq $256, %rsp
	movq $200, -16(%rbp)
	movq -16(%rbp), %rdi
	call malloc@PLT
	movq %rax, -24(%rbp)
	movq -24(%rbp), %rax
	movq %rax, -8(%rbp)
	movq $40, -40(%rbp)
	movq -24(%rbp), %rax
	movq -40(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -48(%rbp)
	movq -48(%rbp), %rax
	movq %rax, -32(%rbp)
	movq $16, -64(%rbp)
	movq -32(%rbp), %rax
	movq -64(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -72(%rbp)
	movq -72(%rbp), %rax
	movq %rax, -56(%rbp)
	movq -56(%rbp), %r13
	movq $5, (%r13)
	movq $40, -88(%rbp)
	movq -24(%rbp), %rax
	movq -88(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -96(%rbp)
	movq -96(%rbp), %rax
	movq %rax, -80(%rbp)
	movq $24, -112(%rbp)
	movq -80(%rbp), %rax
	movq -112(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -120(%rbp)
	movq -120(%rbp), %rax
	movq %rax, -104(%rbp)
	movq -104(%rbp), %r12
	movq $10, (%r12)
	movq $40, -136(%rbp)
	movq -24(%rbp), %rax
	movq -136(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -144(%rbp)
	movq -144(%rbp), %rax
	movq %rax, -128(%rbp)
	movq $16, -160(%rbp)
	movq -128(%rbp), %rax
	movq -160(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -168(%rbp)
	movq -168(%rbp), %rax
	movq %rax, -152(%rbp)
	movq -152(%rbp), %r13
	movq (%r13), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $40, -184(%rbp)
	movq -24(%rbp), %rax
	movq -184(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -192(%rbp)
	movq -192(%rbp), %rax
	movq %rax, -176(%rbp)
	movq $24, -208(%rbp)
	movq -176(%rbp), %rax
	movq -208(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -216(%rbp)
	movq -216(%rbp), %rax
	movq %rax, -200(%rbp)
	movq -200(%rbp), %r12
	movq (%r12), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
