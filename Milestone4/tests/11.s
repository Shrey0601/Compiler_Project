	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
Test : 
	pushq %rbp
	movq %rsp, %rbp
	movq %r14, %r9
	movq $0, %r8
	addq %r8, %r9
	movq $1, (%r9)
	movq %r14, %r9
	movq $8, %r8
	addq %r8, %r9
	movq $2, (%r9)
	movq %r14, %r9
	movq $16, %r8
	addq %r8, %r9
	movq $3, (%r9)
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	subq $256, %rsp
	movq %r14, %r8
	addq $0, %r8
	movq -8(%rbp), %rax
	movq %rax, (%r8)
	movq $0, %rax
	leave 
	ret 
Test.yo1 : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	movq 32(%rbp), %rdx
	movq %rdx, -24(%rbp)
	subq $512, %rsp
	movq $24, -64(%rbp)
	movq -64(%rbp), %rdi
	call malloc@PLT
	movq %rax, -72(%rbp)
	pushq $550
	movq %r14, -80(%rbp)
	movq -72(%rbp), %r14
	call Test
	movq -80(%rbp), %r14
	movq -72(%rbp), %rax
	movq %rax, -32(%rbp)
	movq -72(%rbp), %rax
	movq %rax, -88(%rbp)
	movq -88(%rbp), %r8
	addq $0, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq -72(%rbp), %rax
	movq %rax, -96(%rbp)
	movq -96(%rbp), %r8
	addq $8, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq -72(%rbp), %rax
	movq %rax, -104(%rbp)
	movq -104(%rbp), %r8
	addq $16, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq %r14, %r11
	addq $0, %r11
	movq -8(%rbp), %rax
	movq %rax, (%r11)
	movq %r14, %r12
	addq $8, %r12
	movq -16(%rbp), %rax
	movq %rax, (%r12)
	movq %r14, %r13
	addq $16, %r13
	movq -24(%rbp), %rax
	movq %rax, (%r13)
	movq $0, %rax
	leave 
	ret 
	leave 
	ret 
Test.yo : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq 24(%rbp), %rdx
	movq %rdx, -16(%rbp)
	movq 32(%rbp), %rdx
	movq %rdx, -24(%rbp)
	subq $512, %rsp
	movq $24, -136(%rbp)
	movq -136(%rbp), %rdi
	call malloc@PLT
	movq %rax, -144(%rbp)
	pushq $1000
	movq %r14, -152(%rbp)
	movq -144(%rbp), %r14
	call Test
	movq -152(%rbp), %r14
	movq -144(%rbp), %rax
	movq %rax, -32(%rbp)
	pushq $30
	pushq $20
	pushq $10
	movq %r14, -160(%rbp)
	movq -32(%rbp), %r14
	call Test.yo1
	movq -160(%rbp), %r14
	movq %rax, -168(%rbp)
	movq -144(%rbp), %rax
	movq %rax, -176(%rbp)
	movq -176(%rbp), %r8
	addq $0, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq -144(%rbp), %rax
	movq %rax, -184(%rbp)
	movq -184(%rbp), %r8
	addq $8, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq -144(%rbp), %rax
	movq %rax, -192(%rbp)
	movq -192(%rbp), %r8
	addq $16, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq %r14, %r11
	addq $0, %r11
	movq -8(%rbp), %rax
	movq %rax, (%r11)
	movq %r14, %r12
	addq $8, %r12
	movq -16(%rbp), %rax
	movq %rax, (%r12)
	movq %r14, %r13
	addq $16, %r13
	movq -24(%rbp), %rax
	movq %rax, (%r13)
	movq $0, %rax
	leave 
	ret 
	leave 
	ret 
main : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq $40, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $512, %rsp
	movq $24, -208(%rbp)
	movq -208(%rbp), %rdi
	call malloc@PLT
	movq %rax, -216(%rbp)
	pushq $3
	movq %r14, -224(%rbp)
	movq -216(%rbp), %r14
	call Test
	movq -224(%rbp), %r14
	movq -216(%rbp), %rax
	movq %rax, -16(%rbp)
	pushq $100
	pushq $10
	pushq $50
	movq %r14, -232(%rbp)
	movq -16(%rbp), %r14
	call Test.yo
	movq -232(%rbp), %r14
	movq %rax, -240(%rbp)
	movq -216(%rbp), %rax
	movq %rax, -248(%rbp)
	movq -248(%rbp), %r8
	addq $0, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq -216(%rbp), %rax
	movq %rax, -256(%rbp)
	movq -256(%rbp), %r8
	addq $8, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq -216(%rbp), %rax
	movq %rax, -264(%rbp)
	movq -264(%rbp), %r8
	addq $16, %r8
	movq (%r8), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
