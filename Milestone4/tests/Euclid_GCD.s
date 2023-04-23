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
GFG.gcdExtended : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	movq 32(%rbp), %rdx
	movq %rdx, -24(%rbp)
	movq 40(%rbp), %rdx
	movq %rdx, -32(%rbp)
	subq $256, %rsp
	movq -8(%rbp), %rax
	movq $0, %rcx
	cmp %rax, %rcx
	sete %al
	movzbq %al, %rbx
	movq %rbx, -64(%rbp)
	movq -64(%rbp), %rax
	cmp $0, %rax
	je L1
	movq $0, -24(%rbp)
	movq $1, -32(%rbp)
	movq -16(%rbp), %rax
	leave 
	ret 
	jmp L2
	jmp L2
L1 : 
L2 : 
	movq $1, -40(%rbp)
	movq $1, -48(%rbp)
	movq -16(%rbp), %rax
	cltd 
	idivq -8(%rbp)
	movq %rdx, -72(%rbp)
	pushq -48(%rbp)
	pushq -40(%rbp)
	pushq -8(%rbp)
	pushq -72(%rbp)
	movq %r14, -80(%rbp)
	call GFG.gcdExtended
	movq -80(%rbp), %r14
	movq %rax, -88(%rbp)
	movq -88(%rbp), %rax
	movq %rax, -56(%rbp)
	movq -16(%rbp), %rax
	cltd 
	idivq -8(%rbp)
	movq %rax, -96(%rbp)
	movq -96(%rbp), %rax
	movq -40(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -104(%rbp)
	movq -48(%rbp), %rax
	movq -104(%rbp), %rdx
	subq %rax, %rdx
	neg %rdx
	movq %rdx, -112(%rbp)
	movq -112(%rbp), %rax
	movq %rax, -24(%rbp)
	movq -40(%rbp), %rax
	movq %rax, -32(%rbp)
	movq -56(%rbp), %rax
	leave 
	ret 
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
	subq $128, %rsp
	movq $1, -16(%rbp)
	movq $1, -24(%rbp)
	movq $35, -32(%rbp)
	movq $15, -40(%rbp)
	pushq -24(%rbp)
	pushq -16(%rbp)
	pushq -40(%rbp)
	pushq -32(%rbp)
	movq %r14, -112(%rbp)
	call GFG.gcdExtended
	movq -112(%rbp), %r14
	movq %rax, -120(%rbp)
	movq -120(%rbp), %rax
	movq %rax, -48(%rbp)
	movq -48(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
