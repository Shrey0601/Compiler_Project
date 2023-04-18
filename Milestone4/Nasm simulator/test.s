global _start
section .text

add:
	push ebp ;	BeginFunc 4
	mov ebp, esp
	sub esp, 4
	mov eax, [ebp+12] ;	_t0 = a + b
	mov ebx, [ebp+16]
	add eax, ebx
	mov [ebp-4], eax
	mov eax, [ebp-4] ;	Return _t0
	mov [ebp+20], eax
	mov esp, ebp
	pop ebp
	ret
 ;	EndFunc

_start:
	push ebp ;	BeginFunc 8
	mov ebp, esp
	sub esp, 8
	add esp, -4 ;	SetStack -4
	mov eax, 5 ;	PushParam 2
	push eax
	mov eax, 6 ;	PushParam 1
	push eax
	mov eax, [ebp+8] ;	PushParam this
	push eax
	call add ;	Call add
	add esp, 12 ;	SetStack 12
	pop eax ;	_t1 = PopParam -4
	mov [ebp-8], eax

	mov eax, [ebp-8]
	mov [ebp-4], eax

	push eax
	call printInt
	mov esp, ebp ;	Return
	pop ebp

	mov eax,1
	mov ebx,1
	int 80h
 ;	EndFunc


printInt:
        mov eax, [esp+8]
        xor esi, esi
        cmp eax, 0
        jge loop
        neg eax
        push eax
        mov eax, 45
        push eax
        mov eax, 4 ; Print "-" 
        mov edx, 1 
        mov ecx, esp
        mov ebx, 1
        int 0x80
        pop eax
        pop eax
        
loop:
        mov edx, 0
        mov ebx, 10
        div ebx
        add edx, 48
        push edx
        inc esi
        cmp eax, 0
        jz  next
        jmp loop
        
next:
        cmp  esi, 0
        jz   exit
        dec  esi
        mov  eax, 4
        mov  ecx, esp
        mov  ebx, 1
        mov  edx, 1
        int  0x80
        add  esp, 4
        jmp  next
        
exit:
        ret

section .data