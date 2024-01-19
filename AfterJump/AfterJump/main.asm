COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 1, Part 1
Any and all work in this file is my own.
!

INCLUDE Irvine32.inc
.data
; declare variables here
message BYTE "Niraj Sangroula", 0
result BYTE 20 DUP(?)
decrypted BYTE 20 DUP(?)
key BYTE 12
;KEY = 30
encrypted BYTE ?
.code
;XOR the content of ESI, ECX has count and key, result in address pointed by EDI, 
xorKey proc
	l1:
		MOV AL, BYTE PTR [ESI] ; MOV source to al
		XOR AL, key ;xor al result too
		MOV byte ptr [EDI], AL ;move result to destination
		INC ESI ;change offsets
		INC EDI
	LOOP l1
	ret
xorKey endp
main PROC
	;your code here
	MOV ECX, LENGTHOF message
	MOV ESI, OFFSET message
	MOV EDI, OFFSET result
	call xorKey
	;Display encrypted
	MOV EDX, OFFSET result
	call WriteString
	call CRLF
	;Decrypt
	MOV ECX, LENGTHOF result
	MOV ESI, OFFSET result
	MOV EDI, OFFSET decrypted
	call xorKey
	;Display decrypted
	MOV EDX, OFFSET decrypted
	call WriteString
	EXIT
main ENDP
END main