COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 7, Part 2
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
	message byte "Enter Month Number [1-12] : 0 to exit: ", 0
	winter byte "It's WINTER!", 0
	summer byte "It's SUMMER!", 0
	spring byte "It's SPRING!", 0
	fall byte "It's FALL!", 0
.code

showSeason PROC
	PUSHFD
	PUSHAD
	;Test each numbers and move to specific label
	CMP EAX, 12
	JE printWinter
	CMP EAX, 1
	JE printWinter
	CMP EAX, 2
	JE printWinter
	CMP EAX, 3
	JE printSpring
	CMP EAX, 4
	JE printSpring
	CMP EAX, 5
	JE printSpring
	CMP EAX, 6
	JE printSummer
	CMP EAX, 7
	JE printSummer
	CMP EAX, 8
	JE printSummer
	CMP EAX, 9
	JE printFall
	CMP EAX, 10
	JE printFall
	CMP EAX, 11
	JE printFall

	;Set correct string offset and color, then return to endlabel
	printWinter:
	MOV EAX, 0Fh
	CALL SetTextColor
	MOV EDX, OFFSET winter
	jmp endlabel

	printSpring:
	MOV EAX, 09h
	CALL SetTextColor
	MOV EDX, OFFSET spring
	jmp endlabel

	printSummer:
	MOV EAX, 0Eh
	CALL SetTextColor
	MOV EDX, OFFSET summer
	jmp endlabel

	printFall:
	MOV EAX, 06h
	CALL SetTextColor
	MOV EDX, OFFSET fall
	jmp endlabel
	;Start printing
	endlabel:
	CALL WriteString

	;Reset colors
	MOV EAX, 07h
	CALL SetTextColor
	;Retain all registers
	POPAD
	POPFD
	ret
showSeason ENDP

main PROC
	
	reloop:
	;Ask for number
		MOV EDX, OFFSET message
		CALL WriteString
		CALL ReadDec
		;If number is equal, jump out of unconditional loop
		CMP EAX, 0
		JE exitlabel
		;Call procedure and continue
		CALL showSeason
		CALL CRLF
		;Jump unconditionally
		JMP reloop
	exitlabel:
	EXIT
main ENDP
END main