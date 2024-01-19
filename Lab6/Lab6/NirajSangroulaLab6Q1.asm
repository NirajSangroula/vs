COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 6, Part 1
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
	message byte "Music is a part off my life", 0
.code

;Assumes EDX points to a text address
;Prints a text in all text background and forground combinations provided by SetTextColor Procedure
colors PROC
	PUSHAD
	PUSHFD
	MOV EAX, 0
		MOV ECX, 256
		L1:
			CALL SetTextColor
			CALL WriteString
			CALL CRLF
			INC EAX
			;Preserve the value for Delay operation
			PUSH EAX
			;Reset text color for now
			MOV EAX, 0
			CALL SetTextColor
			;Delay
			MOV EAX, 50
			Call Delay
			;Regain color value
			POP EAX
			LOOP L1
		;To reset defaults colors 'Gray text on Black'
		MOV EAX, 07h
		CALL SetTextColor
		;Regain registers as they were before
		POPFD
		POPAD
		ret
colors ENDP
main PROC
	MOV EDX, OFFSET message
	CALL colors
	EXIT
main ENDP
END main