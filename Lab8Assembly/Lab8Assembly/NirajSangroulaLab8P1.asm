COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 8, Part 1
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
	set1 DWORD 2 DUP(?)
	set2 DWORD 2 DUP(?)
	set3 DWORD 2 DUP(?)
	results DWORD 3 DUP(?)

	prompt BYTE "Enter three sets of numbers: ", 0
	product BYTE " * ", 0
	division BYTE " / ", 0
	modulus BYTE " MOD ", 0
	equals BYTE " = ", 0

.code
main PROC
	;Display message
	MOV EDX, OFFSET prompt
	CALL WriteString
	CALL CRLF
	;Read 3 pair of values
	CALL ReadDec
	MOV set1, EAX
	CALL ReadDec
	MOV set1 + TYPE DWORD, EAX
	
	CALL ReadDec
	MOV set2, EAX
	CALL ReadDec
	MOV set2 + TYPE DWORD, EAX
	
	CALL ReadDec
	MOV set3, EAX
	CALL ReadDec
	MOV set3 + TYPE DWORD, EAX

	;Multiply the first set
	MOV EAX, set1 + TYPE DWORD
	MUL set1
	JC E1 ;If the EDX has content too (EDX:EAX)
	;Store the results (We only take EAX part for simplicity here)
	MOV results, EAX

	;Divide the second set
	MOV EDX, 0 ;Clear EDX that can be used in division for storing upper bytes
	MOV EAX, set2 ;Move dividend to EAX
	DIV set2 + TYPE DWORD ;Divide by next value
	;Store the quotient
	MOV results + TYPE DWORD, EAX

	;Divide the third set
	MOV EDX, 0 ;Clear EDX that can be used in division
	MOV EAX, set3 ;Move dividend to EAX
	DIV set3 + TYPE DWORD ;Divide by next value
	;Store the remainder
	MOV results + 2 * (TYPE DWORD), EDX

	;Display all the results now
	;Display product
	MOV EAX, set1
	CALL WriteDec ;num1
	MOV EDX, OFFSET product
	CALL WriteString ;*
	MOV EAX, set1 + TYPE DWORD
	CALL WriteDec ;num2
	MOV EDX, OFFSET equals
	CALL WriteString ;=
	MOV EAX, results
	CALL WriteDec ;result
	CALL CRLF
	E1: ;Label to jump if product result exceed EAX size

	;Display quotient
	MOV EAX, set2
	CALL WriteDec ;num1
	MOV EDX, OFFSET division
	CALL WriteString ;/
	MOV EAX, set2 + TYPE DWORD
	CALL WriteDec ;num2
	MOV EDX, OFFSET equals
	CALL WriteString ;=
	MOV EAX, results + TYPE DWORD
	CALL WriteDec ;result
	CALL CRLF

	;Display remainder
	MOV EAX, set3
	CALL WriteDec ;num1
	MOV EDX, OFFSET modulus
	CALL WriteString ;MOD
	MOV EAX, set3 + TYPE DWORD
	CALL WriteDec ;num2
	MOV EDX, OFFSET equals
	CALL WriteString ;=
	MOV EAX, results + 2 * (TYPE DWORD)
	CALL WriteDec ;result
	CALL CRLF

	EXIT
main ENDP
END main