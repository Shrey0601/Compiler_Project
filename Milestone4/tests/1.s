	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
Employee : 
	pushq %rbp
	movq %rsp, %rbp
	subq $256, %rsp
	movq %r14, %r8
	addq $0, %r8
	movq $0, (%r8)
	movq $0, %rax
	leave 
	ret 
Employee.insert : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	subq $256, %rsp
	movq %r14, %r10
	addq $0, %r10
	movq -8(%rbp), %rax
	movq %rax, (%r10)
	movq $0, %rax
	leave 
	ret 
Employee.display : 
	pushq %rbp
	movq %rsp, %rbp
	subq $256, %rsp
	movq %r14, %rbx
	addq $0, %rbx
	movq (%rbx), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
TestEmployee : 
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
	movq $32, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $256, %rsp
	movq $8, -40(%rbp)
	movq -40(%rbp), %rdi
	call malloc@PLT
	movq %rax, -48(%rbp)
	movq %r14, -56(%rbp)
	movq -48(%rbp), %r14
	call Employee
	movq -56(%rbp), %r14
	movq -48(%rbp), %rax
	movq %rax, -16(%rbp)
	movq $8, -64(%rbp)
	movq -64(%rbp), %rdi
	call malloc@PLT
	movq %rax, -72(%rbp)
	movq %r14, -80(%rbp)
	movq -72(%rbp), %r14
	call Employee
	movq -80(%rbp), %r14
	movq -72(%rbp), %rax
	movq %rax, -24(%rbp)
	movq $8, -88(%rbp)
	movq -88(%rbp), %rdi
	call malloc@PLT
	movq %rax, -96(%rbp)
	movq %r14, -104(%rbp)
	movq -96(%rbp), %r14
	call Employee
	movq -104(%rbp), %r14
	movq -96(%rbp), %rax
	movq %rax, -32(%rbp)
	pushq $101
	movq %r14, -112(%rbp)
	movq -16(%rbp), %r14
	call Employee.insert
	movq -112(%rbp), %r14
	movq %rax, -120(%rbp)
	pushq $102
	movq %r14, -128(%rbp)
	movq -24(%rbp), %r14
	call Employee.insert
	movq -128(%rbp), %r14
	movq %rax, -136(%rbp)
	pushq $103
	movq %r14, -144(%rbp)
	movq -32(%rbp), %r14
	call Employee.insert
	movq -144(%rbp), %r14
	movq %rax, -152(%rbp)
	movq %r14, -160(%rbp)
	movq -16(%rbp), %r14
	call Employee.display
	movq -160(%rbp), %r14
	movq %rax, -168(%rbp)
	movq %r14, -176(%rbp)
	movq -24(%rbp), %r14
	call Employee.display
	movq -176(%rbp), %r14
	movq %rax, -184(%rbp)
	movq %r14, -192(%rbp)
	movq -32(%rbp), %r14
	call Employee.display
	movq -192(%rbp), %r14
	movq %rax, -200(%rbp)
	movq $0, %rax
	leave 
	ret 
