	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
GFG : 
main : 
	pushq %rbp
	movq %rsp, %rbp
	subq $256, %rsp
	movq $160, -16(%rbp)
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
	movq $12, -64(%rbp)
	movq -32(%rbp), %rax
	movq %rax, -56(%rbp)
	movq -56(%rbp), %r12
	movq $100, (%r12)
	movq $60, -80(%rbp)
	movq -24(%rbp), %rax
	movq -80(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -88(%rbp)
	movq -88(%rbp), %rax
	movq %rax, -72(%rbp)
	movq $8, -104(%rbp)
	movq -72(%rbp), %rax
	movq %rax, -96(%rbp)
	movq -96(%rbp), %r12
	movq $1000, (%r12)
	movq $40, -120(%rbp)
	movq -24(%rbp), %rax
	movq -120(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -128(%rbp)
	movq -128(%rbp), %rax
	movq %rax, -112(%rbp)
	movq $12, -144(%rbp)
	movq -112(%rbp), %rax
	movq %rax, -136(%rbp)
	movq $60, -160(%rbp)
	movq -24(%rbp), %rax
	movq -160(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -168(%rbp)
	movq -168(%rbp), %rax
	movq %rax, -152(%rbp)
	movq $8, -184(%rbp)
	movq -152(%rbp), %rax
	movq %rax, -176(%rbp)
	movq -176(%rbp), %r12
	movq -136(%rbp), %r12
	movq (%r12), %rax
	movq %rax, (%r12)
	movq $40, -200(%rbp)
	movq -24(%rbp), %rax
	movq -200(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -208(%rbp)
	movq -208(%rbp), %rax
	movq %rax, -192(%rbp)
	movq $12, -224(%rbp)
	movq -192(%rbp), %rax
	movq %rax, -216(%rbp)
	movq -216(%rbp), %r12
	movq (%r12), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
