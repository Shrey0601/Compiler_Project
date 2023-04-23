	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
CatalnNumber : 
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
CatalnNumber.catalan : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	subq $256, %rsp
	movq $0, -16(%rbp)
	movq -8(%rbp), %rax
	movq $1, %rcx
	cmp %rax, %rcx
	setge %al
	movzbq %al, %rbx
	movq %rbx, -32(%rbp)
	movq -32(%rbp), %rax
	cmp $0, %rax
	je L1
	movq $1, %rax
	leave 
	ret 
	jmp L2
	jmp L2
L1 : 
L2 : 
	movq $0, -24(%rbp)
L3 : 
	movq -24(%rbp), %rax
	movq -8(%rbp), %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -40(%rbp)
	movq -40(%rbp), %rax
	cmp $0, %rax
	je L4
	jmp L5
L6 : 
	movq -24(%rbp), %rax
	movq %rax, -48(%rbp)
	movq -48(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -24(%rbp)
	jmp L3
L5 : 
	pushq -24(%rbp)
	movq %r14, -56(%rbp)
	call CatalnNumber.catalan
	movq -56(%rbp), %r14
	movq %rax, -64(%rbp)
	movq -8(%rbp), %rax
	movq -24(%rbp), %rdx
	subq %rax, %rdx
	neg %rdx
	movq %rdx, -72(%rbp)
	movq -72(%rbp), %rax
	movq $1, %rdx
	subq %rax, %rdx
	neg %rdx
	movq %rdx, -80(%rbp)
	pushq -80(%rbp)
	movq %r14, -88(%rbp)
	call CatalnNumber.catalan
	movq -88(%rbp), %r14
	movq %rax, -96(%rbp)
	movq -64(%rbp), %rax
	movq -96(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -104(%rbp)
	movq -16(%rbp), %rax
	movq -104(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -112(%rbp)
	movq -112(%rbp), %rax
	movq %rax, -16(%rbp)
	jmp L6
L4 : 
	movq -16(%rbp), %rax
	leave 
	ret 
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
	movq $0, -120(%rbp)
	movq -120(%rbp), %rdi
	call malloc@PLT
	movq %rax, -128(%rbp)
	movq %r14, -136(%rbp)
	movq -128(%rbp), %r14
	call CatalnNumber
	movq -136(%rbp), %r14
	movq -128(%rbp), %rax
	movq %rax, -16(%rbp)
	movq $0, -24(%rbp)
L7 : 
	movq -24(%rbp), %rax
	movq $10, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -144(%rbp)
	movq -144(%rbp), %rax
	cmp $0, %rax
	je L8
	jmp L9
L10 : 
	movq -24(%rbp), %rax
	movq %rax, -152(%rbp)
	movq -152(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -24(%rbp)
	jmp L7
L9 : 
	pushq -24(%rbp)
	movq %r14, -160(%rbp)
	movq -16(%rbp), %r14
	call CatalnNumber.catalan
	movq -160(%rbp), %r14
	movq %rax, -168(%rbp)
	movq -168(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	jmp L10
L8 : 
	movq $0, %rax
	leave 
	ret 
