COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 8, Part 3
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
	MAX = 100
	message byte MAX + 1 DUP(0)
	prompt byte "Enter a string [MAX 100 characters]", 0
	messageEncrypted byte "Encrypted : ", 0
	messageDecrypted byte "Decrypted : ", 0
.code

;Receives offset in EDX
;Changes contents pointed by EDX
rotateCharactersRight PROC USES EDX
	MOV ECX, 100 ;Set loop counter to 100
	L1:
		ROR BYTE PTR [EDX], 1
		ADD EDX, TYPE BYTE
	LOOP L1
	ret
rotateCharactersRight ENDP


;Receives offset in EDX
;Changes the contents pointed by EDX
rotateCharactersLeft PROC USES EDX
	MOV ECX, 100 ;Set loop counter to 100
	L1:
		ROL BYTE PTR [EDX], 1
		ADD EDX, TYPE BYTE
	LOOP L1
	ret
rotateCharactersLeft ENDP
main PROC
	;Read a message MAX 100
	MOV EDX, OFFSET prompt
	CALL WriteString
	CALL CRLF

	MOV EDX, OFFSET message
	MOV ECX, MAX
	CALL ReadString
	CALL CRLF

	MOV EDX, OFFSET messageEncrypted ;Encrypted :
	CALL WriteString

	MOV EDX, OFFSET message ;Evaluate and display encrypted text
	CALL rotateCharactersRight
	CALL WriteString
	CALL CRLF

	MOV EDX, OFFSET messageDecrypted ;Decrypted : 
	CALL WriteString

	MOV EDX, OFfset message ;Evaluate and display original string
	CALL rotateCharactersLeft
	CALL WriteString
	CALL CRLF
	EXIT
main ENDP
END main