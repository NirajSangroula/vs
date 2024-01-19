COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 5, Part 1
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
	array DWORD 10 DUP(?) ;Create 10 uninitialized arrays
	comma BYTE ", ", 0
	promptValue BYTE "Enter 10 values", 0
	openBraces BYTE "[", 0
	closeBraces BYTE "]", 0
.code
main PROC
	MOV EDX, OFFSET promptValue ; For displaying message
	CALL WriteString
	MOV ECX, 10	;Loop counter
	MOV EBX, 0 ;Memory index counter for array
	CALL CRLF
	Input:	;Label for pointing to the loop address
		;Read a number and increase memory index counter by 4
		CALL ReadDec 
		MOV array[EBX], EAX
		ADD EBX, 4
	LOOP Input

	;For displaying the contents,
	
	CALL CRLF
	MOV EDX, OFFSET openBraces ; For displaying open braces
	CALL WriteString
	MOV ECX, 9 ;For loop counter (Arrays - 1st element)
	MOV EBX, 4 ;For index for an array (Starting with second element -- to adjust comma)
	MOV EAX, array[0] ; Write first element 
	CALL WriteDec
	Display: 
	;Display the comma, number and then increase the index pointer
		MOV EDX, OFFSET comma
		CALL WriteString

		MOV EAX, array[EBX]
		CALL WriteDec

		ADD EBX, 4
	LOOP Display
	MOV EDX, OFFSET closeBraces ; For displaying closing braces
	CALL WriteString
	CALL CRLF

	MOV ECX, 10 
	MOV EBX, 0 ;For array index
	MOV EAX, 0 ; For storing sum, initialize to 0
	SUM:
		ADD EAX, array[EBX] ;Add current array value to EAX each time
		ADD EBX, 4 ; Increase index of array
	LOOP SUM

	call WriteDec
	CALL CRLF
	EXIT
main ENDP
END main