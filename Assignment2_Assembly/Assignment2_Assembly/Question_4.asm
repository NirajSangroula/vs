COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
!

INCLUDE Irvine32.inc
.data
	;Name must be of ODD number of length eg. 1, 3, 5, 7, 9 due to instruction limitations
	nameStr BYTE "Niraj Sangroula", 0
	message BYTE "My name is ", 0
	rMessage BYTE "Reverse my name is ", 0
.code
main PROC
	;Display name
	MOV EDX, OFFSET message
	CALL WriteString
	MOV EDX, OFFSET nameStr
	CALL WriteString
	CALL CRLF

	;Setup for loop
	MOV ECX, LENGTHOF nameStr ;Gives total length including of null character (length + 1)
	SUB ECX, 2 ;(To remove null character length and decrease one to match the last index offset)
	MOV ESI, 0 ; (Stores left most index to exchange with destination)
	MOV EDI, ECX ; (Stores Right most index to exchange with destination)

	COMMENT !
		Every time, it exchanges left character with right, until it reaches the middle
		eg. 
		0, 1, 2, 3, 4
		Exchange 0 and 4,
		Exchange 1 and 3
		**************************
		ECX = 4 --OK 1st loop (Exchange 0 and 4)
		ECX = 2 --OK 2nd loop (Exchange 1 and 3)
		ECX = 0 -- ENDS program
		(So we add DEC ECX to decrease ECX by 2 each time)

	!

	L1:
		MOV AL, nameStr[ESI] ; Copy left hand value to AL
		XCHG AL, nameStr[EDI] ; right hand value in AL, left hand in Destination
		MOV nameStr[ESI], AL ; right hand value to Source

		SUB EDI, TYPE nameStr ;Change destination index
		ADD ESI, TYPE nameStr ;Change source index
		DEC ECX ; So that it runs only half times
	LOOP L1
	MOV EDX, OFFSET rMessage
	CALL WriteString
	MOV EDX, OFFSET nameStr ; Print the reversed string
	CALL WriteString
	EXIT
main ENDP
END main