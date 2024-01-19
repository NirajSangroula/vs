COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 9
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
SubTwo3 PROTO,
	nOne: DWORD, nTwo: DWORD
	
.data
	num1 dword ?
	num2 dword ?
	prompt byte "Enter two numbers: ", 0
	output byte "Difference = ", 0
.code



main PROC
	;Read two numbers and store in memory
	MOV EDX, OFFSET prompt
	CALL WriteString
	CALL CRLF
	CALL ReadInt
	MOV num1, EAX
	CALL ReadInt
	MOV num2, EAX

	;Test first procedure and display output
	MOV EAX, num1
	MOV EBX, num2
	CALL SubTwo
	;Display formatted results
	CALL DisplayDifference

	;Test second procedure and display output
	PUSH num1
	PUSH num2
	CALL SubTwo2

	;Display formatted results (We already have result in EAX)
	CALL DisplayDifference

	;Test the third procedure and display output
	INVOKE SubTwo3, num1, num2
	;We already have result in EAX now
	CALL DisplayDifference
	EXIT
main ENDP
	;Receives input in EAX and EBX
	;Outputs difference in EAX
SubTwo PROC
	SUB EAX, EBX
	ret
SubTwo ENDP

	;Receives input from stack,
	;Returns difference in EAX
SubTwo2 PROC
	PUSH EBP
	MOV EBP, ESP
	;Mov first number pushed to EAX
	MOV EAX, [EBP + 12]
	;Subtract EAX with next number
	SUB EAX, [EBP + 8]
	POP EBP
	ret 8
SubTwo2 ENDP

	;Displays content in EAX as "Difference = " EAX
	;Receives EAX
	;Prints Difference = EAX
DisplayDifference PROC
	;Display message	
	MOV EDX, OFFSET output
	CALL WriteString
	;Display content in EAX
	CALL WriteInt
	CALL CRLF
	ret
DisplayDifference ENDP

	;Receives two numbers as parameters
	;Returns result in EAX
SubTwo3 PROC,
	nOne: DWORD, nTwo: DWORD
	MOV EAX, nOne
	SUB EAX, nTwo
	ret
SubTwo3 ENDP
END main