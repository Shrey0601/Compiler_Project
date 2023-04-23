	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
InsertionSort : 
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
	movq $48, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $512, %rsp
	movq $40, -56(%rbp)
	movq -56(%rbp), %rdi
	call malloc@PLT
	movq %rax, -64(%rbp)
	movq -64(%rbp), %rax
	movq %rax, -16(%rbp)
	movq $0, %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -88(%rbp)
	movq -88(%rbp), %rax
	movq %rax, -80(%rbp)
	movq -64(%rbp), %rax
	movq -80(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -96(%rbp)
	movq -96(%rbp), %rax
	movq %rax, -72(%rbp)
	movq -72(%rbp), %r13
	movq $9, (%r13)
	movq $1, %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -120(%rbp)
	movq -120(%rbp), %rax
	movq %rax, -112(%rbp)
	movq -64(%rbp), %rax
	movq -112(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -128(%rbp)
	movq -128(%rbp), %rax
	movq %rax, -104(%rbp)
	movq -104(%rbp), %r12
	movq $2, (%r12)
	movq $2, %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -152(%rbp)
	movq -152(%rbp), %rax
	movq %rax, -144(%rbp)
	movq -64(%rbp), %rax
	movq -144(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -160(%rbp)
	movq -160(%rbp), %rax
	movq %rax, -136(%rbp)
	movq -136(%rbp), %r13
	movq $8, (%r13)
	movq $3, %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -184(%rbp)
	movq -184(%rbp), %rax
	movq %rax, -176(%rbp)
	movq -64(%rbp), %rax
	movq -176(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -192(%rbp)
	movq -192(%rbp), %rax
	movq %rax, -168(%rbp)
	movq -168(%rbp), %r12
	movq $4, (%r12)
	movq $4, %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -216(%rbp)
	movq -216(%rbp), %rax
	movq %rax, -208(%rbp)
	movq -64(%rbp), %rax
	movq -208(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -224(%rbp)
	movq -224(%rbp), %rax
	movq %rax, -200(%rbp)
	movq -200(%rbp), %r13
	movq $5, (%r13)
	movq $1, -24(%rbp)
L1 : 
	movq -24(%rbp), %rax
	movq $5, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -232(%rbp)
	movq -232(%rbp), %rax
	cmp $0, %rax
	je L2
	jmp L3
L4 : 
	movq -24(%rbp), %rax
	movq %rax, -240(%rbp)
	movq -240(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -24(%rbp)
	jmp L1
L3 : 
	movq -24(%rbp), %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -264(%rbp)
	movq -264(%rbp), %rax
	movq %rax, -256(%rbp)
	movq -64(%rbp), %rax
	movq -256(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -272(%rbp)
	movq -272(%rbp), %rax
	movq %rax, -248(%rbp)
	movq -248(%rbp), %r12
	movq (%r12), %rax
	movq %rax, -32(%rbp)
	movq -24(%rbp), %rax
	movq $1, %rdx
	subq %rax, %rdx
	neg %rdx
	movq %rdx, -280(%rbp)
	movq -280(%rbp), %rax
	movq %rax, -40(%rbp)
L5 : 
	movq -40(%rbp), %rax
	movq $0, %rcx
	cmp %rax, %rcx
	setle %al
	movzbq %al, %rbx
	movq %rbx, -288(%rbp)
	movq -40(%rbp), %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -312(%rbp)
	movq -312(%rbp), %rax
	movq %rax, -304(%rbp)
	movq -64(%rbp), %rax
	movq -304(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -320(%rbp)
	movq -320(%rbp), %rax
	movq %rax, -296(%rbp)
	movq -296(%rbp), %r13
	movq -32(%rbp), %rax
	movq (%r13), %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -328(%rbp)
	movq -288(%rbp), %rax
	movq -328(%rbp), %rcx
	cmp %rax, %rcx
	sete %al
	movzbq %al, %rbx
	movq %rbx, -336(%rbp)
	movq -336(%rbp), %rax
	cmp $0, %rax
	je L6
	movq -40(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -344(%rbp)
	movq -344(%rbp), %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -368(%rbp)
	movq -368(%rbp), %rax
	movq %rax, -360(%rbp)
	movq -64(%rbp), %rax
	movq -360(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -376(%rbp)
	movq -376(%rbp), %rax
	movq %rax, -352(%rbp)
	movq -40(%rbp), %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -400(%rbp)
	movq -400(%rbp), %rax
	movq %rax, -392(%rbp)
	movq -64(%rbp), %rax
	movq -392(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -408(%rbp)
	movq -408(%rbp), %rax
	movq %rax, -384(%rbp)
	movq -384(%rbp), %r12
	movq -352(%rbp), %r13
	movq (%r12), %rax
	movq %rax, (%r13)
	movq -40(%rbp), %rax
	movq $1, %rdx
	subq %rax, %rdx
	neg %rdx
	movq %rdx, -416(%rbp)
	movq -416(%rbp), %rax
	movq %rax, -40(%rbp)
	jmp L5
L6 : 
	movq -40(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -424(%rbp)
	movq -424(%rbp), %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -448(%rbp)
	movq -448(%rbp), %rax
	movq %rax, -440(%rbp)
	movq -64(%rbp), %rax
	movq -440(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -456(%rbp)
	movq -456(%rbp), %rax
	movq %rax, -432(%rbp)
	movq -432(%rbp), %r12
	movq -32(%rbp), %rax
	movq %rax, (%r12)
	jmp L4
L2 : 
	movq $0, -48(%rbp)
L7 : 
	movq -48(%rbp), %rax
	movq $5, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -464(%rbp)
	movq -464(%rbp), %rax
	cmp $0, %rax
	je L8
	jmp L9
L10 : 
	movq -48(%rbp), %rax
	movq %rax, -472(%rbp)
	movq -472(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -48(%rbp)
	jmp L7
L9 : 
	movq -48(%rbp), %rax
	movq $8, %rdx
	imulq %rax, %rdx
	movq %rdx, -496(%rbp)
	movq -496(%rbp), %rax
	movq %rax, -488(%rbp)
	movq -64(%rbp), %rax
	movq -488(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -504(%rbp)
	movq -504(%rbp), %rax
	movq %rax, -480(%rbp)
	movq -480(%rbp), %r13
	movq (%r13), %rax
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
