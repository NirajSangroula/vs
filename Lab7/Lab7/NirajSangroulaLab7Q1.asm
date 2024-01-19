COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 7, Part 1
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
	numbers SDWORD 20 DUP(?)
	range SDWORD 2 DUP(?)
	positiveM byte "Positives are : ", 0
	negativeM byte "Negatives are : ", 0
	space byte " ", 0
.code

;Generates random number between specified range (Both included)
;INPUT in ESI register
;Receives offset of sdword type array, in ESI rergister. The array must have high value and the low value
;Returns a random number in EAX register
randomNumber PROC
	;Save flags in the stack
	PUSHFD
	;Calculate the difference in range in EAX
	MOV EAX, [ESI]
	SUB EAX, [ESI + 1 * TYPE SDWORD]
	;Generate random number between 0 and difference (Difference included) (Add 1 to EAX to include max value to generate)
	;So for 5 to 10 (difference will be 5, and the range generated will be 0 to 5
	;Min = 5, so min + diff, gives range (min + 0 to min + 5) (5 to 10) Both included
	INC EAX
	CALL Randomize
	CALL RandomRange
	;We have random num between 0 and difference in EAX
	;Perform min + (Random num between 0 and difference) (Generate number between min and max both included)
	ADD EAX, [ESI + 1 * TYPE SDWORD]
	;Reset flags
	POPFD
	ret
randomNumber ENDP

;Receives an array offset in ESI
;Receives no of items in array in ECX
;Displays only the positive items in array
printPositive PROC
	PUSHFD
	PUSHAD

	lp:
		;To compare, we put 0 in EBX
		MOV EBX, 0
		CMP EBX, [ESI]
		;if value is negative, i.e 0 - -x will be positive so, if CMP result is positive or 0, we jump
		JGE lend
		MOV EAX, [ESI]
		CALL WriteInt
		;Display space after number
		MOV EDX, OFFSET space
		CALL WriteString
		lend:
		;Increase ESI pointer address
		ADD ESI, TYPE SDWORD
		LOOP lp
	POPAD
	POPFD
	ret
printPositive ENDP

;Receives an array offset in ESI
;Receives no of items in array in ECX
;Displays only the negative items in array
printNegative PROC
	PUSHFD
	PUSHAD

	ln:
		;To compare, we put 0 in EBX
		MOV EBX, 0
		CMP EBX, [ESI]
		;if value is positive, i.e 0 - x will be negative so, if CMP result is negative, we jump
		JS lendn
		MOV EAX, [ESI]
		CALL WriteInt
		;Display space after number
		MOV EDX, OFFSET space
		CALL WriteString
		lendn:
		;Increase ESI pointer address
		ADD ESI, TYPE SDWORD
		LOOP ln
	POPAD
	POPFD
	ret
printNegative ENDP
main PROC
	MOV ECX, 20
	;Index for array numbers
	MOV EDI, OFFSET numbers
	;Setup range parameter for randomNumber procedure
	MOV range, 1000
	MOV [range + TYPE SDWORD], -1000
	MOV ESI, OFFSET range
	l1:
		CALL randomNumber
		;Move the random number in index specified by EDI
		MOV [EDI], EAX
		;EDI point to next address -- which is pointer to an index of array numbers
		ADD EDI, TYPE SDWORD
		;We delay so that different random numbers are generated
		MOV EAX, 10
		CALL DELAY
		LOOP l1
	;Simply setup parameters, ESI for array index and ECX for no of elements to call printPositive and printNegative procedures
	MOV ESI, OFFSET numbers
	MOV ECX, LENGTHOF numbers
	;Display data using appropriate message
	MOV EDX, OFFSET positiveM
	CALL WriteString
	CALL printPositive
	CALL CRLF

	MOV EDX, OFFSET negativeM
	CALL WriteString
	CALL printNegative


	EXIT
main ENDP
END main