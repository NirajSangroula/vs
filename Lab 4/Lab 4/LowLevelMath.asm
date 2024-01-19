INCLUDE Irvine32.inc
.data
	promptA byte "Enter value of a : ", 0
	promptB byte "Enter value of b : ", 0
	promptC byte "Enter value of c : ", 0
	promptD byte "Enter value of d : ", 0
	promptE byte "Enter value of e : ", 0

	resultEquation1 byte "A + B - (C - D) + E = ", 0
	resultEquation2 byte "(A - B) + (C + D) - E = ", 0
	resultEquation3 byte "A + (B - C) + (D + E) = ", 0
	varA SDWORD ?
	varB SDWORD ?
	varC SDWORD ?
	varD SDWORD ?
	varE SDWORD ?
	varResult SDWORD ?
.code
main PROC
	MOV EDX, OFFSET promptA ;Read a
	CALL WriteString
	CALL ReadInt
	MOV varA, EAX

	MOV EDX, OFFSET promptB ;Read b
	CALL WriteString
	CALL ReadInt
	MOV varB, EAX

	MOV EDX, OFFSET promptC ;Read c
	CALL WriteString
	CALL ReadInt
	MOV varC, EAX

	MOV EDX, OFFSET promptD ;Read d
	CALL WriteString
	CALL ReadInt
	MOV varD, EAX

	MOV EDX, OFFSET promptE ;Read e
	CALL WriteString
	CALL ReadInt
	MOV varE, EAX

	MOV EAX, varC ;Do operation, (C - D) in EAX
	SUB EAX, varD
	MOV EBX, varA ; Do EBX =  A + B - EAX + E
	ADD EBX, varB
	SUB EBX, EAX
	ADD EBX, varE ;Result stored in EBX
	MOV EDX, OFFSET resultEquation1 ;Display results
	CALL WriteString
	MOV EAX, EBX
	CALL WriteInt
	CALL CRLF

	MOV EBX, varA
	SUB EBX, varB ; EBX = A - B
	MOV ECX, varC
	ADD ECX, varD ; ECX = C + D
	MOV EAX, EBX
	ADD EAX, ECX
	SUB EAX, varE ; EAX = EBX + ECX - E
	MOV EDX, OFFSET resultEquation2 ;Display results
	CALL WriteString
	CALL WriteInt
	CALL CRLF

	MOV EBX, varB
	SUB EBX, varC ; EBX = B - C
	MOV ECX, varD
	ADD ECX, varE ; ECX = D + E

	MOV EAX, varA
	ADD EAX, EBX
	ADD EAX, ECX ; EAX = A + EBX + ECX
	MOV EDX, OFFSET resultEquation3 ; Display results
	CALL WriteString
	CALL WriteInt
	CALL CRLF

	EXIT
main ENDP
END main