COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 1, Part 1
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
; declare variables here
.code
testss PROC
	ENTER 0,0
	mov eax, [ebp+8] ;a (latest one)
	sub eax, [ebp+12] ;b (older one)
	LEAVE
	ret 8
testss ENDP
main PROC
	push 29 ;b
	push 30 ;a
	call testss
	call dumpregs
	EXIT
main ENDP
END main