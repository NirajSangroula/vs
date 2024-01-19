COMMENT ->
Author: Niraj Sangroula
Student ID: 219586770
Lab 1, Part 1
Any and all work in this file is my own.
->

INCLUDE Irvine32.inc


PBYTE TYPEDEF PTR BYTE

.data
; declare variables here
	vara byte 10101111b
	varb byte 01101010b
	var1 dword 12
	var2 dword 2
	pmessage byte "First greater", 0
	nmessage byte "Second greater", 0
	zeromessage byte 'zero', 0
.code

COMMENT !
	Multiplies contents of EAX and EBX and stores the results back in EAX
!
multiply PROC USES EBX
MOV ECX, EBX
MOV EBX, 0
l1:
	ADD EBX, EAX
	LOOP l1
MOV EAX, EBX
ret
multiply ENDP
main PROC
	mov eax, 0
	mov al, 127
	add al, 75h
	call dumpregs
	EXIT
main ENDP
END main