COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 1, Part 1
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc

.data
alpha BYTE "Malai maaf garideu mera lovi najar kai kashai maa dube chha vane",0
.data
; declare variables here

.code
main PROC
	invoke Str_ucase, OFFSET alpha
	invoke Str_length, OFFSET alpha
	mov EDX, OFFSET alpha
	CALL WriteString
	CALL WriteInt
	EXIT
main ENDP
END main