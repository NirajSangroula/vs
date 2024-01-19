COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 6, Part 2
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
	promptMessage byte "Enter two numbers (high value and low value)", 0
	outputMessage byte "The random number between specified range is ", 0

	;Array that stores high value first, then low value
	rangeArr dword 2 DUP(?)
.code

;Generates random number between specified range (Both included)
;INPUT in ESI register
;Receives offset of dword type array, in ESI rergister. The array must have high value and the low value
;Returns a random number in EAX register
randomNumber PROC
	;Save flags in the stack
	PUSHFD
	;Calculate the difference in range in EAX
	MOV EAX, [ESI]
	SUB EAX, [ESI + 1 * TYPE DWORD]
	;Generate random number between 0 and difference (Difference included) (Add 1 to EAX to include max value to generate)
	;So for 5 to 10 (difference will be 5, and the range generated will be 0 to 5
	;Min = 5, so min + diff, gives range (min + 0 to min + 5) (5 to 10) Both included
	INC EAX
	CALL Randomize
	CALL RandomRange
	;We have random num between 0 and difference in EAX
	;Perform min + (Random num between 0 and difference) (Generate number between min and max both included)
	ADD EAX, [ESI + 1 * TYPE DWORD]
	;Reset flags
	POPFD
	ret
randomNumber ENDP
main PROC
	;Take the input and store in array
	MOV EDX, OFFSET promptMessage
	CALL WriteString
	CALL CRLF
	CALL ReadInt
	MOV rangeArr, EAX
	CALL ReadInt
	CALL CRLF
	MOV rangeArr[1 * TYPE DWORD], EAX
	;Call the procedure and display the number
	;Move offset of the array to ESI (Required parameter)
	MOV ESI, OFFSET rangeArr
	call randomNumber
	;Display output
	MOV EDX, OFFSET outputMessage
	CALL WriteString
	CALL WriteInt
	EXIT
main ENDP
END main