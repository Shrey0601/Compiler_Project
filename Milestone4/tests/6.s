	.section    .rodata
.LC0:
	.string    "%ld\n"
	.text
	.globl    main
MatrixAdditionExample : 
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
	subq $2048, %rsp
	movq $72, -56(%rbp)
	movq -56(%rbp), %rdi
	call malloc@PLT
	movq %rax, -64(%rbp)
	movq -64(%rbp), %rax
	movq %rax, -16(%rbp)
	movq $72, -72(%rbp)
	movq -72(%rbp), %rdi
	call malloc@PLT
	movq %rax, -80(%rbp)
	movq -80(%rbp), %rax
	movq %rax, -24(%rbp)
	movq $72, -88(%rbp)
	movq -88(%rbp), %rdi
	call malloc@PLT
	movq %rax, -96(%rbp)
	movq -96(%rbp), %rax
	movq %rax, -32(%rbp)
	movq $24, %rax
	movq $0, %rdx
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
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -152(%rbp)
	movq -152(%rbp), %rax
	movq %rax, -144(%rbp)
	movq -104(%rbp), %rax
	movq -144(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -160(%rbp)
	movq -160(%rbp), %rax
	movq %rax, -136(%rbp)
	movq -136(%rbp), %r13
	movq $1, (%r13)
	movq $24, %rax
	movq $0, %rdx
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
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -216(%rbp)
	movq -216(%rbp), %rax
	movq %rax, -208(%rbp)
	movq -168(%rbp), %rax
	movq -208(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -224(%rbp)
	movq -224(%rbp), %rax
	movq %rax, -200(%rbp)
	movq -200(%rbp), %r12
	movq $2, (%r12)
	movq $24, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -248(%rbp)
	movq -248(%rbp), %rax
	movq %rax, -240(%rbp)
	movq -64(%rbp), %rax
	movq -240(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -256(%rbp)
	movq -256(%rbp), %rax
	movq %rax, -232(%rbp)
	movq $8, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -280(%rbp)
	movq -280(%rbp), %rax
	movq %rax, -272(%rbp)
	movq -232(%rbp), %rax
	movq -272(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -288(%rbp)
	movq -288(%rbp), %rax
	movq %rax, -264(%rbp)
	movq -264(%rbp), %r13
	movq $3, (%r13)
	movq $24, %rax
	movq $1, %rdx
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
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -344(%rbp)
	movq -344(%rbp), %rax
	movq %rax, -336(%rbp)
	movq -296(%rbp), %rax
	movq -336(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -352(%rbp)
	movq -352(%rbp), %rax
	movq %rax, -328(%rbp)
	movq -328(%rbp), %r12
	movq $4, (%r12)
	movq $24, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -376(%rbp)
	movq -376(%rbp), %rax
	movq %rax, -368(%rbp)
	movq -64(%rbp), %rax
	movq -368(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -384(%rbp)
	movq -384(%rbp), %rax
	movq %rax, -360(%rbp)
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -408(%rbp)
	movq -408(%rbp), %rax
	movq %rax, -400(%rbp)
	movq -360(%rbp), %rax
	movq -400(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -416(%rbp)
	movq -416(%rbp), %rax
	movq %rax, -392(%rbp)
	movq -392(%rbp), %r13
	movq $5, (%r13)
	movq $24, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -440(%rbp)
	movq -440(%rbp), %rax
	movq %rax, -432(%rbp)
	movq -64(%rbp), %rax
	movq -432(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -448(%rbp)
	movq -448(%rbp), %rax
	movq %rax, -424(%rbp)
	movq $8, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -472(%rbp)
	movq -472(%rbp), %rax
	movq %rax, -464(%rbp)
	movq -424(%rbp), %rax
	movq -464(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -480(%rbp)
	movq -480(%rbp), %rax
	movq %rax, -456(%rbp)
	movq -456(%rbp), %r12
	movq $6, (%r12)
	movq $24, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -504(%rbp)
	movq -504(%rbp), %rax
	movq %rax, -496(%rbp)
	movq -64(%rbp), %rax
	movq -496(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -512(%rbp)
	movq -512(%rbp), %rax
	movq %rax, -488(%rbp)
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -536(%rbp)
	movq -536(%rbp), %rax
	movq %rax, -528(%rbp)
	movq -488(%rbp), %rax
	movq -528(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -544(%rbp)
	movq -544(%rbp), %rax
	movq %rax, -520(%rbp)
	movq -520(%rbp), %r13
	movq $7, (%r13)
	movq $24, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -568(%rbp)
	movq -568(%rbp), %rax
	movq %rax, -560(%rbp)
	movq -64(%rbp), %rax
	movq -560(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -576(%rbp)
	movq -576(%rbp), %rax
	movq %rax, -552(%rbp)
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -600(%rbp)
	movq -600(%rbp), %rax
	movq %rax, -592(%rbp)
	movq -552(%rbp), %rax
	movq -592(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -608(%rbp)
	movq -608(%rbp), %rax
	movq %rax, -584(%rbp)
	movq -584(%rbp), %r12
	movq $8, (%r12)
	movq $24, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -632(%rbp)
	movq -632(%rbp), %rax
	movq %rax, -624(%rbp)
	movq -64(%rbp), %rax
	movq -624(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -640(%rbp)
	movq -640(%rbp), %rax
	movq %rax, -616(%rbp)
	movq $8, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -664(%rbp)
	movq -664(%rbp), %rax
	movq %rax, -656(%rbp)
	movq -616(%rbp), %rax
	movq -656(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -672(%rbp)
	movq -672(%rbp), %rax
	movq %rax, -648(%rbp)
	movq -648(%rbp), %r13
	movq $9, (%r13)
	movq $24, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -696(%rbp)
	movq -696(%rbp), %rax
	movq %rax, -688(%rbp)
	movq -80(%rbp), %rax
	movq -688(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -704(%rbp)
	movq -704(%rbp), %rax
	movq %rax, -680(%rbp)
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -728(%rbp)
	movq -728(%rbp), %rax
	movq %rax, -720(%rbp)
	movq -680(%rbp), %rax
	movq -720(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -736(%rbp)
	movq -736(%rbp), %rax
	movq %rax, -712(%rbp)
	movq -712(%rbp), %r12
	movq $1, (%r12)
	movq $24, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -760(%rbp)
	movq -760(%rbp), %rax
	movq %rax, -752(%rbp)
	movq -80(%rbp), %rax
	movq -752(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -768(%rbp)
	movq -768(%rbp), %rax
	movq %rax, -744(%rbp)
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -792(%rbp)
	movq -792(%rbp), %rax
	movq %rax, -784(%rbp)
	movq -744(%rbp), %rax
	movq -784(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -800(%rbp)
	movq -800(%rbp), %rax
	movq %rax, -776(%rbp)
	movq -776(%rbp), %r13
	movq $1, (%r13)
	movq $24, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -824(%rbp)
	movq -824(%rbp), %rax
	movq %rax, -816(%rbp)
	movq -80(%rbp), %rax
	movq -816(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -832(%rbp)
	movq -832(%rbp), %rax
	movq %rax, -808(%rbp)
	movq $8, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -856(%rbp)
	movq -856(%rbp), %rax
	movq %rax, -848(%rbp)
	movq -808(%rbp), %rax
	movq -848(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -864(%rbp)
	movq -864(%rbp), %rax
	movq %rax, -840(%rbp)
	movq -840(%rbp), %r12
	movq $1, (%r12)
	movq $24, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -888(%rbp)
	movq -888(%rbp), %rax
	movq %rax, -880(%rbp)
	movq -80(%rbp), %rax
	movq -880(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -896(%rbp)
	movq -896(%rbp), %rax
	movq %rax, -872(%rbp)
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -920(%rbp)
	movq -920(%rbp), %rax
	movq %rax, -912(%rbp)
	movq -872(%rbp), %rax
	movq -912(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -928(%rbp)
	movq -928(%rbp), %rax
	movq %rax, -904(%rbp)
	movq -904(%rbp), %r13
	movq $1, (%r13)
	movq $24, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -952(%rbp)
	movq -952(%rbp), %rax
	movq %rax, -944(%rbp)
	movq -80(%rbp), %rax
	movq -944(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -960(%rbp)
	movq -960(%rbp), %rax
	movq %rax, -936(%rbp)
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -984(%rbp)
	movq -984(%rbp), %rax
	movq %rax, -976(%rbp)
	movq -936(%rbp), %rax
	movq -976(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -992(%rbp)
	movq -992(%rbp), %rax
	movq %rax, -968(%rbp)
	movq -968(%rbp), %r12
	movq $1, (%r12)
	movq $24, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1016(%rbp)
	movq -1016(%rbp), %rax
	movq %rax, -1008(%rbp)
	movq -80(%rbp), %rax
	movq -1008(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1024(%rbp)
	movq -1024(%rbp), %rax
	movq %rax, -1000(%rbp)
	movq $8, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -1048(%rbp)
	movq -1048(%rbp), %rax
	movq %rax, -1040(%rbp)
	movq -1000(%rbp), %rax
	movq -1040(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1056(%rbp)
	movq -1056(%rbp), %rax
	movq %rax, -1032(%rbp)
	movq -1032(%rbp), %r13
	movq $1, (%r13)
	movq $24, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -1080(%rbp)
	movq -1080(%rbp), %rax
	movq %rax, -1072(%rbp)
	movq -80(%rbp), %rax
	movq -1072(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1088(%rbp)
	movq -1088(%rbp), %rax
	movq %rax, -1064(%rbp)
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1112(%rbp)
	movq -1112(%rbp), %rax
	movq %rax, -1104(%rbp)
	movq -1064(%rbp), %rax
	movq -1104(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1120(%rbp)
	movq -1120(%rbp), %rax
	movq %rax, -1096(%rbp)
	movq -1096(%rbp), %r12
	movq $1, (%r12)
	movq $24, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -1144(%rbp)
	movq -1144(%rbp), %rax
	movq %rax, -1136(%rbp)
	movq -80(%rbp), %rax
	movq -1136(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1152(%rbp)
	movq -1152(%rbp), %rax
	movq %rax, -1128(%rbp)
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1176(%rbp)
	movq -1176(%rbp), %rax
	movq %rax, -1168(%rbp)
	movq -1128(%rbp), %rax
	movq -1168(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1184(%rbp)
	movq -1184(%rbp), %rax
	movq %rax, -1160(%rbp)
	movq -1160(%rbp), %r13
	movq $1, (%r13)
	movq $24, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -1208(%rbp)
	movq -1208(%rbp), %rax
	movq %rax, -1200(%rbp)
	movq -80(%rbp), %rax
	movq -1200(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1216(%rbp)
	movq -1216(%rbp), %rax
	movq %rax, -1192(%rbp)
	movq $8, %rax
	movq $2, %rdx
	imulq %rax, %rdx
	movq %rdx, -1240(%rbp)
	movq -1240(%rbp), %rax
	movq %rax, -1232(%rbp)
	movq -1192(%rbp), %rax
	movq -1232(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1248(%rbp)
	movq -1248(%rbp), %rax
	movq %rax, -1224(%rbp)
	movq -1224(%rbp), %r12
	movq $1, (%r12)
	movq $0, -40(%rbp)
L1 : 
	movq -40(%rbp), %rax
	movq $3, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -1256(%rbp)
	movq -1256(%rbp), %rax
	cmp $0, %rax
	je L2
	jmp L3
L4 : 
	movq -40(%rbp), %rax
	movq %rax, -1264(%rbp)
	movq -1264(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -40(%rbp)
	jmp L1
L3 : 
	movq $0, -48(%rbp)
L5 : 
	movq -48(%rbp), %rax
	movq $3, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -1272(%rbp)
	movq -1272(%rbp), %rax
	cmp $0, %rax
	je L6
	jmp L7
L8 : 
	movq -48(%rbp), %rax
	movq %rax, -1280(%rbp)
	movq -1280(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -48(%rbp)
	jmp L5
L7 : 
	movq $24, %rax
	movq -40(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -1304(%rbp)
	movq -1304(%rbp), %rax
	movq %rax, -1296(%rbp)
	movq -96(%rbp), %rax
	movq -1296(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1312(%rbp)
	movq -1312(%rbp), %rax
	movq %rax, -1288(%rbp)
	movq $8, %rax
	movq -48(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -1336(%rbp)
	movq -1336(%rbp), %rax
	movq %rax, -1328(%rbp)
	movq -1288(%rbp), %rax
	movq -1328(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1344(%rbp)
	movq -1344(%rbp), %rax
	movq %rax, -1320(%rbp)
	movq $24, %rax
	movq -40(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -1368(%rbp)
	movq -1368(%rbp), %rax
	movq %rax, -1360(%rbp)
	movq -64(%rbp), %rax
	movq -1360(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1376(%rbp)
	movq -1376(%rbp), %rax
	movq %rax, -1352(%rbp)
	movq $8, %rax
	movq -48(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -1400(%rbp)
	movq -1400(%rbp), %rax
	movq %rax, -1392(%rbp)
	movq -1352(%rbp), %rax
	movq -1392(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1408(%rbp)
	movq -1408(%rbp), %rax
	movq %rax, -1384(%rbp)
	movq $24, %rax
	movq -40(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -1432(%rbp)
	movq -1432(%rbp), %rax
	movq %rax, -1424(%rbp)
	movq -80(%rbp), %rax
	movq -1424(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1440(%rbp)
	movq -1440(%rbp), %rax
	movq %rax, -1416(%rbp)
	movq $8, %rax
	movq -48(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -1464(%rbp)
	movq -1464(%rbp), %rax
	movq %rax, -1456(%rbp)
	movq -1416(%rbp), %rax
	movq -1456(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1472(%rbp)
	movq -1472(%rbp), %rax
	movq %rax, -1448(%rbp)
	movq -1384(%rbp), %r13
	movq -1448(%rbp), %r12
	movq (%r13), %rax
	movq (%r12), %rdx
	subq %rax, %rdx
	neg %rdx
	movq %rdx, -1480(%rbp)
	movq -1320(%rbp), %r13
	movq -1480(%rbp), %rax
	movq %rax, (%r13)
	movq $24, %rax
	movq -40(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -1504(%rbp)
	movq -1504(%rbp), %rax
	movq %rax, -1496(%rbp)
	movq -96(%rbp), %rax
	movq -1496(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1512(%rbp)
	movq -1512(%rbp), %rax
	movq %rax, -1488(%rbp)
	movq $8, %rax
	movq -48(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -1536(%rbp)
	movq -1536(%rbp), %rax
	movq %rax, -1528(%rbp)
	movq -1488(%rbp), %rax
	movq -1528(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1544(%rbp)
	movq -1544(%rbp), %rax
	movq %rax, -1520(%rbp)
	movq -1520(%rbp), %r12
	movq (%r12), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	jmp L8
L6 : 
	jmp L4
L2 : 
	movq $0, %rax
	leave 
	ret 
