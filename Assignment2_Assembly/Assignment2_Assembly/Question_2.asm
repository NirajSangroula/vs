COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
!

INCLUDE Irvine32.inc
.data
	val1 sdword ?
	val2 sdword ?
	val3 sdword ?
	result1 sdword ?
	prompt1 byte "Enter three values ", 0
	message byte "(3val1 + val2) - 2val3 = ", 0
.code
main PROC
	;Read three values
	MOV EDX, OFFSET prompt1
	CALL WriteString
	CALL CRLF

	CALL ReadInt
	MOV val1, EAX
	CALL ReadInt
	MOV val2, EAX
	CALL ReadInt
	MOV val3, EAX

	;At this point we have all 3 values in the memory

	;evaluate 3val1
	MOV ECX, 3
	MOV EAX, 0
	L1:
	ADD EAX, val1
	LOOP L1

	;evaluate 3val1 + val2 = EAX
	ADD EAX, val2

	;evaluate 2val3 = EBX
	MOV ECX, 2
	MOV EBX, 0
	L2:
	ADD EBX, val3
	LOOP L2

	;evaluate EAX - EBX = (3val1 + val2) - 2val3
	SUB EAX, EBX

	MOV result1, EAX ; Move result to memory 
	;Display output
	MOV EDX, OFFSET message
	CALL WriteString
	CALL WriteInt
	EXIT
main ENDP
END main