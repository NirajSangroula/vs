COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Finds GCD
!

INCLUDE Irvine32.inc
.data
prompt byte "Enter two numbers" , 0
message byte "Greatest Common Divisor: " , 0
.code
;Finds absolute value of EAX
;Returns result in EAX
absoluteValue proc
	CMP EAX, 0
	JGE l1
	MOV EBX, 0
	SUB EBX, EAX ;Perform 0 - EAX , if it is negative
	MOV EAX, EBX ;Get the absolute value in EAX
	L1:
	ret
absoluteValue endp

;Finds gcd between eax and ebx
;Result stored in eax
gcd proc
	;Finds and stores absolute value of eax
	CALL absoluteValue
	;Retain EAX and find absolute value of ebx and store in ebx
	PUSH EAX
	;Parameter for absolute value
	MOV EAX, EBX
	CALL absoluteValue
	;Store absolute value back in ebx
	MOV EBX, EAX
	;Retain eax
	POP EAX

	L2: 
	MOV EDX, 0 ;Clear edx that might be used for division
	DIV EBX ;EDX has remainder now after EAX/EBX
	MOV EAX, EBX ; Mov x = y
	MOV EBX, EDX ;Mov y = n( remainder)

	CMP EBX, 0
	JG L2
	ret
gcd endp
main PROC
	;Call the function 5 times
	MOV ECX, 5
	L4:
		;Display prompt message and read 2 numbers
		MOV EDX, OFFSET prompt
		CALL WriteString
		CALL CRLF
		CALL ReadInt
		;Store in stack for now
		PUSH EAX
		CALL ReadInt
		;Move 2nd number in ebx
		MOV EBX, EAX
		;Store back to eax, the 1st number
		POP EAX

		;Call gcd as two numbers are in eax and ebx
		;Result will be in eax
		CALL gcd

		;Display gcd message
		MOV EDX, OFFSET message
		CALL WriteString
		;Display gcd
		CALL WriteInt
		CALL CRLF
		CALL CRLF
	LOOP L4
	EXIT
main ENDP
END main