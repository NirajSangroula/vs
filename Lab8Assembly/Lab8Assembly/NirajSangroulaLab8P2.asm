COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 8, Part 2
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
	num1 dword ?
	num2 dword ?
	productBy2 dword ?
	divisionBy2 dword ?
	prompt byte "Enter two numbers : ", 0
	mul2 byte " * 2 = ", 0
	div2 byte " / 2 = ", 0

.code
;Parameter should be in EAX
;Returns the left shift in EAX
multiplyBy2 PROC
	SHL EAX, 1
	ret
multiplyBy2 ENDP

;Parameter should be in EAX
;Returns the right shift in EAX
divideBy2 PROC
	SHR EAX, 1
	ret
divideBy2 ENDP

main PROC
	;Read two numbers
	MOV EDX, OFFSET prompt
	CALL WriteString
	CALL CRLF

	CALL ReadDec
	MOV num1, EAX
	CALL ReadDec
	MOV num2, EAX

	;Multiply first number by 2 and store results
	MOV EAX, num1

	CALL multiplyBy2

	MOV productBy2, EAX
	;Display results
	MOV EAX, num1 ; num1
	CALL WriteDec
	MOV EDX, OFFSET mul2 ; * 2 =
	CALL WriteString
	MOV EAX, productBy2
	CALL WriteDec ; result
	CALL CRLF


	;Divide second number by 2 and store results
	MOV EAX, num2

	CALL divideBy2

	MOV divisionBy2, EAX
	;Display results
	MOV EAX, num2 ; num1
	CALL WriteDec
	MOV EDX, OFFSET div2 ; / 2 =
	CALL WriteString
	MOV EAX, divisionBy2
	CALL WriteDec ; result


	EXIT
main ENDP
END main