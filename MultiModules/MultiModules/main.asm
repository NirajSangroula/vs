COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 1, Part 1
Any and all work in this file is my own.
!

INCLUDE sum.inc

;EXTERN display@0:PROC
;display EQU display@0
.data
; declare variables here
.code
main PROC
	;your code here
	;call ClrScr
	call display
	EXIT
main ENDP
END main