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
main : 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rdx
	movq %rdx, -8(%rbp)
	movq $48, %rdi
	call malloc@PLT
	movq %rax, %r15
	movq %rax, %r14
	subq $4096, %rsp
	movq $128, -56(%rbp)
	movq -56(%rbp), %rdi
	call malloc@PLT
	movq %rax, -64(%rbp)
	movq -64(%rbp), %rax
	movq %rax, -16(%rbp)
	movq $64, %rax
	movq $0, %rdx
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
	movq $32, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -120(%rbp)
	movq -120(%rbp), %rax
	movq %rax, -112(%rbp)
	movq -72(%rbp), %rax
	movq -112(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -128(%rbp)
	movq -128(%rbp), %rax
	movq %rax, -104(%rbp)
	movq $16, %rax
	movq $0, %rdx
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
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -184(%rbp)
	movq -184(%rbp), %rax
	movq %rax, -176(%rbp)
	movq -136(%rbp), %rax
	movq -176(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -192(%rbp)
	movq -192(%rbp), %rax
	movq %rax, -168(%rbp)
	movq -168(%rbp), %r13
	movq $1, (%r13)
	movq $64, %rax
	movq $0, %rdx
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
	movq $32, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -248(%rbp)
	movq -248(%rbp), %rax
	movq %rax, -240(%rbp)
	movq -200(%rbp), %rax
	movq -240(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -256(%rbp)
	movq -256(%rbp), %rax
	movq %rax, -232(%rbp)
	movq $16, %rax
	movq $0, %rdx
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
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -312(%rbp)
	movq -312(%rbp), %rax
	movq %rax, -304(%rbp)
	movq -264(%rbp), %rax
	movq -304(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -320(%rbp)
	movq -320(%rbp), %rax
	movq %rax, -296(%rbp)
	movq -296(%rbp), %r12
	movq $2, (%r12)
	movq $64, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -344(%rbp)
	movq -344(%rbp), %rax
	movq %rax, -336(%rbp)
	movq -64(%rbp), %rax
	movq -336(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -352(%rbp)
	movq -352(%rbp), %rax
	movq %rax, -328(%rbp)
	movq $32, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -376(%rbp)
	movq -376(%rbp), %rax
	movq %rax, -368(%rbp)
	movq -328(%rbp), %rax
	movq -368(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -384(%rbp)
	movq -384(%rbp), %rax
	movq %rax, -360(%rbp)
	movq $16, %rax
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
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -440(%rbp)
	movq -440(%rbp), %rax
	movq %rax, -432(%rbp)
	movq -392(%rbp), %rax
	movq -432(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -448(%rbp)
	movq -448(%rbp), %rax
	movq %rax, -424(%rbp)
	movq -424(%rbp), %r13
	movq $3, (%r13)
	movq $64, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -472(%rbp)
	movq -472(%rbp), %rax
	movq %rax, -464(%rbp)
	movq -64(%rbp), %rax
	movq -464(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -480(%rbp)
	movq -480(%rbp), %rax
	movq %rax, -456(%rbp)
	movq $32, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -504(%rbp)
	movq -504(%rbp), %rax
	movq %rax, -496(%rbp)
	movq -456(%rbp), %rax
	movq -496(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -512(%rbp)
	movq -512(%rbp), %rax
	movq %rax, -488(%rbp)
	movq $16, %rax
	movq $1, %rdx
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
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -568(%rbp)
	movq -568(%rbp), %rax
	movq %rax, -560(%rbp)
	movq -520(%rbp), %rax
	movq -560(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -576(%rbp)
	movq -576(%rbp), %rax
	movq %rax, -552(%rbp)
	movq -552(%rbp), %r12
	movq $4, (%r12)
	movq $64, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -600(%rbp)
	movq -600(%rbp), %rax
	movq %rax, -592(%rbp)
	movq -64(%rbp), %rax
	movq -592(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -608(%rbp)
	movq -608(%rbp), %rax
	movq %rax, -584(%rbp)
	movq $32, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -632(%rbp)
	movq -632(%rbp), %rax
	movq %rax, -624(%rbp)
	movq -584(%rbp), %rax
	movq -624(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -640(%rbp)
	movq -640(%rbp), %rax
	movq %rax, -616(%rbp)
	movq $16, %rax
	movq $0, %rdx
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
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -696(%rbp)
	movq -696(%rbp), %rax
	movq %rax, -688(%rbp)
	movq -648(%rbp), %rax
	movq -688(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -704(%rbp)
	movq -704(%rbp), %rax
	movq %rax, -680(%rbp)
	movq -680(%rbp), %r13
	movq $5, (%r13)
	movq $64, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -728(%rbp)
	movq -728(%rbp), %rax
	movq %rax, -720(%rbp)
	movq -64(%rbp), %rax
	movq -720(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -736(%rbp)
	movq -736(%rbp), %rax
	movq %rax, -712(%rbp)
	movq $32, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -760(%rbp)
	movq -760(%rbp), %rax
	movq %rax, -752(%rbp)
	movq -712(%rbp), %rax
	movq -752(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -768(%rbp)
	movq -768(%rbp), %rax
	movq %rax, -744(%rbp)
	movq $16, %rax
	movq $0, %rdx
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
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -824(%rbp)
	movq -824(%rbp), %rax
	movq %rax, -816(%rbp)
	movq -776(%rbp), %rax
	movq -816(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -832(%rbp)
	movq -832(%rbp), %rax
	movq %rax, -808(%rbp)
	movq -808(%rbp), %r12
	movq $6, (%r12)
	movq $64, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -856(%rbp)
	movq -856(%rbp), %rax
	movq %rax, -848(%rbp)
	movq -64(%rbp), %rax
	movq -848(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -864(%rbp)
	movq -864(%rbp), %rax
	movq %rax, -840(%rbp)
	movq $32, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -888(%rbp)
	movq -888(%rbp), %rax
	movq %rax, -880(%rbp)
	movq -840(%rbp), %rax
	movq -880(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -896(%rbp)
	movq -896(%rbp), %rax
	movq %rax, -872(%rbp)
	movq $16, %rax
	movq $1, %rdx
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
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -952(%rbp)
	movq -952(%rbp), %rax
	movq %rax, -944(%rbp)
	movq -904(%rbp), %rax
	movq -944(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -960(%rbp)
	movq -960(%rbp), %rax
	movq %rax, -936(%rbp)
	movq -936(%rbp), %r13
	movq $7, (%r13)
	movq $64, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -984(%rbp)
	movq -984(%rbp), %rax
	movq %rax, -976(%rbp)
	movq -64(%rbp), %rax
	movq -976(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -992(%rbp)
	movq -992(%rbp), %rax
	movq %rax, -968(%rbp)
	movq $32, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1016(%rbp)
	movq -1016(%rbp), %rax
	movq %rax, -1008(%rbp)
	movq -968(%rbp), %rax
	movq -1008(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1024(%rbp)
	movq -1024(%rbp), %rax
	movq %rax, -1000(%rbp)
	movq $16, %rax
	movq $1, %rdx
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
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1080(%rbp)
	movq -1080(%rbp), %rax
	movq %rax, -1072(%rbp)
	movq -1032(%rbp), %rax
	movq -1072(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1088(%rbp)
	movq -1088(%rbp), %rax
	movq %rax, -1064(%rbp)
	movq -1064(%rbp), %r12
	movq $8, (%r12)
	movq $64, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1112(%rbp)
	movq -1112(%rbp), %rax
	movq %rax, -1104(%rbp)
	movq -64(%rbp), %rax
	movq -1104(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1120(%rbp)
	movq -1120(%rbp), %rax
	movq %rax, -1096(%rbp)
	movq $32, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1144(%rbp)
	movq -1144(%rbp), %rax
	movq %rax, -1136(%rbp)
	movq -1096(%rbp), %rax
	movq -1136(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1152(%rbp)
	movq -1152(%rbp), %rax
	movq %rax, -1128(%rbp)
	movq $16, %rax
	movq $0, %rdx
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
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1208(%rbp)
	movq -1208(%rbp), %rax
	movq %rax, -1200(%rbp)
	movq -1160(%rbp), %rax
	movq -1200(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1216(%rbp)
	movq -1216(%rbp), %rax
	movq %rax, -1192(%rbp)
	movq -1192(%rbp), %r13
	movq $9, (%r13)
	movq $64, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1240(%rbp)
	movq -1240(%rbp), %rax
	movq %rax, -1232(%rbp)
	movq -64(%rbp), %rax
	movq -1232(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1248(%rbp)
	movq -1248(%rbp), %rax
	movq %rax, -1224(%rbp)
	movq $32, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1272(%rbp)
	movq -1272(%rbp), %rax
	movq %rax, -1264(%rbp)
	movq -1224(%rbp), %rax
	movq -1264(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1280(%rbp)
	movq -1280(%rbp), %rax
	movq %rax, -1256(%rbp)
	movq $16, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1304(%rbp)
	movq -1304(%rbp), %rax
	movq %rax, -1296(%rbp)
	movq -1256(%rbp), %rax
	movq -1296(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1312(%rbp)
	movq -1312(%rbp), %rax
	movq %rax, -1288(%rbp)
	movq $8, %rax
	movq $1, %rdx
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
	movq -1320(%rbp), %r12
	movq $10, (%r12)
	movq $64, %rax
	movq $1, %rdx
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
	movq $32, %rax
	movq $0, %rdx
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
	movq $16, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1432(%rbp)
	movq -1432(%rbp), %rax
	movq %rax, -1424(%rbp)
	movq -1384(%rbp), %rax
	movq -1424(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1440(%rbp)
	movq -1440(%rbp), %rax
	movq %rax, -1416(%rbp)
	movq $8, %rax
	movq $0, %rdx
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
	movq -1448(%rbp), %r13
	movq $11, (%r13)
	movq $64, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1496(%rbp)
	movq -1496(%rbp), %rax
	movq %rax, -1488(%rbp)
	movq -64(%rbp), %rax
	movq -1488(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1504(%rbp)
	movq -1504(%rbp), %rax
	movq %rax, -1480(%rbp)
	movq $32, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1528(%rbp)
	movq -1528(%rbp), %rax
	movq %rax, -1520(%rbp)
	movq -1480(%rbp), %rax
	movq -1520(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1536(%rbp)
	movq -1536(%rbp), %rax
	movq %rax, -1512(%rbp)
	movq $16, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1560(%rbp)
	movq -1560(%rbp), %rax
	movq %rax, -1552(%rbp)
	movq -1512(%rbp), %rax
	movq -1552(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1568(%rbp)
	movq -1568(%rbp), %rax
	movq %rax, -1544(%rbp)
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1592(%rbp)
	movq -1592(%rbp), %rax
	movq %rax, -1584(%rbp)
	movq -1544(%rbp), %rax
	movq -1584(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1600(%rbp)
	movq -1600(%rbp), %rax
	movq %rax, -1576(%rbp)
	movq -1576(%rbp), %r12
	movq $12, (%r12)
	movq $64, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1624(%rbp)
	movq -1624(%rbp), %rax
	movq %rax, -1616(%rbp)
	movq -64(%rbp), %rax
	movq -1616(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1632(%rbp)
	movq -1632(%rbp), %rax
	movq %rax, -1608(%rbp)
	movq $32, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1656(%rbp)
	movq -1656(%rbp), %rax
	movq %rax, -1648(%rbp)
	movq -1608(%rbp), %rax
	movq -1648(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1664(%rbp)
	movq -1664(%rbp), %rax
	movq %rax, -1640(%rbp)
	movq $16, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1688(%rbp)
	movq -1688(%rbp), %rax
	movq %rax, -1680(%rbp)
	movq -1640(%rbp), %rax
	movq -1680(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1696(%rbp)
	movq -1696(%rbp), %rax
	movq %rax, -1672(%rbp)
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1720(%rbp)
	movq -1720(%rbp), %rax
	movq %rax, -1712(%rbp)
	movq -1672(%rbp), %rax
	movq -1712(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1728(%rbp)
	movq -1728(%rbp), %rax
	movq %rax, -1704(%rbp)
	movq -1704(%rbp), %r13
	movq $13, (%r13)
	movq $64, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1752(%rbp)
	movq -1752(%rbp), %rax
	movq %rax, -1744(%rbp)
	movq -64(%rbp), %rax
	movq -1744(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1760(%rbp)
	movq -1760(%rbp), %rax
	movq %rax, -1736(%rbp)
	movq $32, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1784(%rbp)
	movq -1784(%rbp), %rax
	movq %rax, -1776(%rbp)
	movq -1736(%rbp), %rax
	movq -1776(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1792(%rbp)
	movq -1792(%rbp), %rax
	movq %rax, -1768(%rbp)
	movq $16, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1816(%rbp)
	movq -1816(%rbp), %rax
	movq %rax, -1808(%rbp)
	movq -1768(%rbp), %rax
	movq -1808(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1824(%rbp)
	movq -1824(%rbp), %rax
	movq %rax, -1800(%rbp)
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1848(%rbp)
	movq -1848(%rbp), %rax
	movq %rax, -1840(%rbp)
	movq -1800(%rbp), %rax
	movq -1840(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1856(%rbp)
	movq -1856(%rbp), %rax
	movq %rax, -1832(%rbp)
	movq -1832(%rbp), %r12
	movq $14, (%r12)
	movq $64, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1880(%rbp)
	movq -1880(%rbp), %rax
	movq %rax, -1872(%rbp)
	movq -64(%rbp), %rax
	movq -1872(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1888(%rbp)
	movq -1888(%rbp), %rax
	movq %rax, -1864(%rbp)
	movq $32, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1912(%rbp)
	movq -1912(%rbp), %rax
	movq %rax, -1904(%rbp)
	movq -1864(%rbp), %rax
	movq -1904(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1920(%rbp)
	movq -1920(%rbp), %rax
	movq %rax, -1896(%rbp)
	movq $16, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -1944(%rbp)
	movq -1944(%rbp), %rax
	movq %rax, -1936(%rbp)
	movq -1896(%rbp), %rax
	movq -1936(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1952(%rbp)
	movq -1952(%rbp), %rax
	movq %rax, -1928(%rbp)
	movq $8, %rax
	movq $0, %rdx
	imulq %rax, %rdx
	movq %rdx, -1976(%rbp)
	movq -1976(%rbp), %rax
	movq %rax, -1968(%rbp)
	movq -1928(%rbp), %rax
	movq -1968(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -1984(%rbp)
	movq -1984(%rbp), %rax
	movq %rax, -1960(%rbp)
	movq -1960(%rbp), %r13
	movq $15, (%r13)
	movq $64, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -2008(%rbp)
	movq -2008(%rbp), %rax
	movq %rax, -2000(%rbp)
	movq -64(%rbp), %rax
	movq -2000(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -2016(%rbp)
	movq -2016(%rbp), %rax
	movq %rax, -1992(%rbp)
	movq $32, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -2040(%rbp)
	movq -2040(%rbp), %rax
	movq %rax, -2032(%rbp)
	movq -1992(%rbp), %rax
	movq -2032(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -2048(%rbp)
	movq -2048(%rbp), %rax
	movq %rax, -2024(%rbp)
	movq $16, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -2072(%rbp)
	movq -2072(%rbp), %rax
	movq %rax, -2064(%rbp)
	movq -2024(%rbp), %rax
	movq -2064(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -2080(%rbp)
	movq -2080(%rbp), %rax
	movq %rax, -2056(%rbp)
	movq $8, %rax
	movq $1, %rdx
	imulq %rax, %rdx
	movq %rdx, -2104(%rbp)
	movq -2104(%rbp), %rax
	movq %rax, -2096(%rbp)
	movq -2056(%rbp), %rax
	movq -2096(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -2112(%rbp)
	movq -2112(%rbp), %rax
	movq %rax, -2088(%rbp)
	movq -2088(%rbp), %r12
	movq $16, (%r12)
	movq $0, -24(%rbp)
L1 : 
	movq -24(%rbp), %rax
	movq $2, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -2120(%rbp)
	movq -2120(%rbp), %rax
	cmp $0, %rax
	je L2
	jmp L3
L4 : 
	movq -24(%rbp), %rax
	movq %rax, -2128(%rbp)
	movq -2128(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -24(%rbp)
	jmp L1
L3 : 
	movq $0, -32(%rbp)
L5 : 
	movq -32(%rbp), %rax
	movq $2, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -2136(%rbp)
	movq -2136(%rbp), %rax
	cmp $0, %rax
	je L6
	jmp L7
L8 : 
	movq -32(%rbp), %rax
	movq %rax, -2144(%rbp)
	movq -2144(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -32(%rbp)
	jmp L5
L7 : 
	movq $0, -40(%rbp)
L9 : 
	movq -40(%rbp), %rax
	movq $2, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -2152(%rbp)
	movq -2152(%rbp), %rax
	cmp $0, %rax
	je L10
	jmp L11
L12 : 
	movq -40(%rbp), %rax
	movq %rax, -2160(%rbp)
	movq -2160(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -40(%rbp)
	jmp L9
L11 : 
	movq $0, -48(%rbp)
L13 : 
	movq -48(%rbp), %rax
	movq $2, %rcx
	cmp %rax, %rcx
	setg %al
	movzbq %al, %rbx
	movq %rbx, -2168(%rbp)
	movq -2168(%rbp), %rax
	cmp $0, %rax
	je L14
	jmp L15
L16 : 
	movq -48(%rbp), %rax
	movq %rax, -2176(%rbp)
	movq -2176(%rbp), %rax
	movq $1, %rdx
	addq %rax, %rdx
	movq %rdx, -48(%rbp)
	jmp L13
L15 : 
	movq $64, %rax
	movq -24(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -2200(%rbp)
	movq -2200(%rbp), %rax
	movq %rax, -2192(%rbp)
	movq -64(%rbp), %rax
	movq -2192(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -2208(%rbp)
	movq -2208(%rbp), %rax
	movq %rax, -2184(%rbp)
	movq $32, %rax
	movq -32(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -2232(%rbp)
	movq -2232(%rbp), %rax
	movq %rax, -2224(%rbp)
	movq -2184(%rbp), %rax
	movq -2224(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -2240(%rbp)
	movq -2240(%rbp), %rax
	movq %rax, -2216(%rbp)
	movq $16, %rax
	movq -40(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -2264(%rbp)
	movq -2264(%rbp), %rax
	movq %rax, -2256(%rbp)
	movq -2216(%rbp), %rax
	movq -2256(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -2272(%rbp)
	movq -2272(%rbp), %rax
	movq %rax, -2248(%rbp)
	movq $8, %rax
	movq -48(%rbp), %rdx
	imulq %rax, %rdx
	movq %rdx, -2296(%rbp)
	movq -2296(%rbp), %rax
	movq %rax, -2288(%rbp)
	movq -2248(%rbp), %rax
	movq -2288(%rbp), %rdx
	addq %rax, %rdx
	movq %rdx, -2304(%rbp)
	movq -2304(%rbp), %rax
	movq %rax, -2280(%rbp)
	movq -2280(%rbp), %r13
	movq (%r13), %rax
	movq %rax, %rsi
	leaq .LC0(%rip), %rax
	movq %rax, %rdi
	movq $0, %rax
	call printf@PLT
	jmp L16
L14 : 
	jmp L12
L10 : 
	jmp L8
L6 : 
	jmp L4
L2 : 
	movq $0, %rax
	leave 
	ret 
