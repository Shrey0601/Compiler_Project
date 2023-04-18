	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
GFG : 
main : 
	pushq %rbp
	movq %rsp, %rbp
	subq $64, %rsp
	movq $2, -8(%rbp)
	movq $0, -16(%rbp)
L1 : 
	movq -16(%rbp), %rax
	movq $10, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -32(%rbp)
	movq -32(%rbp), %rax
	cmp $0, %rax
	je L2
	jmp L3
L4 : 
	movq -16(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -40(%rbp)
	movq -40(%rbp), %rax
	movq %rax, -16(%rbp)
	jmp L1
L3 : 
	movq -16(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	jmp L4
L2 : 
	movq $0, -24(%rbp)
L5 : 
	movq -24(%rbp), %rax
	movq $10, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -48(%rbp)
	movq -48(%rbp), %rax
	cmp $0, %rax
	je L6
	jmp L7
L8 : 
	movq -24(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -56(%rbp)
	movq -56(%rbp), %rax
	movq %rax, -24(%rbp)
	jmp L5
L7 : 
	movq -24(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	jmp L8
L6 : 
	movq -8(%rbp), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	movq $0, %rax
	leave 
	ret 
