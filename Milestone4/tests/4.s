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
Student.insertRecord : 
	pushq %rbp
	movq %rsp, %rbp
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
Student.displayInformation : 
	pushq %rbp
	movq %rsp, %rbp
	subq $128, %rsp
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
TestStudent4 : 
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
	movq $8, -56(%rbp)
	movq -56(%rbp), %rdi
	call malloc@PLT
	movq %rax, -64(%rbp)
	movq %r14, -72(%rbp)
	movq -64(%rbp), %r14
	call Student
	movq -72(%rbp), %r14
	movq -64(%rbp), %rax
	movq %rax, -24(%rbp)
	pushq $111
	movq %r14, -80(%rbp)
	movq -16(%rbp), %r14
	call Student.insertRecord
	movq -80(%rbp), %r14
	movq %rax, -88(%rbp)
	pushq $222
	movq %r14, -96(%rbp)
	movq -24(%rbp), %r14
	call Student.insertRecord
	movq -96(%rbp), %r14
	movq %rax, -104(%rbp)
	movq %r14, -112(%rbp)
	movq -16(%rbp), %r14
	call Student.displayInformation
	movq -112(%rbp), %r14
	movq %rax, -120(%rbp)
	movq %r14, -128(%rbp)
	movq -24(%rbp), %r14
	call Student.displayInformation
	movq -128(%rbp), %r14
	movq %rax, -136(%rbp)
	movq $0, %rax
	leave 
	ret 
