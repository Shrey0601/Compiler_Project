	.file	"a.c"
	.text
	.comm	id,4,4
	.comm	salary,4,4
	.globl	insert
	.type	insert, @function
insert:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movss	%xmm0, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, id(%rip)
	movss	-8(%rbp), %xmm0
	movss	%xmm0, salary(%rip)
	nop
	popq	%rbp
	ret
	.size	insert, .-insert
	.globl	main
	.type	main, @function
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, -12(%rbp)
	movl	$10, -8(%rbp)
	movl	$100, -4(%rbp)
	movl	$0, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
