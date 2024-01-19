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
main PROC
	;your code here
	mov bx, 1000h

     mov ax, 368h

     mul bx 
	call dumpregs
	EXIT
main ENDP
END main