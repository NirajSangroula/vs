COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Reads a text and a key and then encrypts and decrypts it
!

INCLUDE Irvine32.inc
.data
MAX = 50
text byte MAX DUP(?)
key byte MAX DUP(?)
loopkey byte MAX DUP(?)
enResult byte MAX DUP(?)
deResult byte MAX DUP(?)

promptMessage byte "Enter text and key (MAX 50 characters)", 0
loopMessage byte "Loopkey used ", 0
encryptedMessage byte "Encrypted message ", 0
decryptedMessage byte "Decrypted message", 0
.code

;XOR the content of ESI and EBX (ESI has text and EBX has key)
;ECX has count
;result in address pointed by EDI,

xorKey proc
;Retain used registers
	PUSH ECX
	PUSH ESI
	PUSH EDI
	PUSH EBX
	l1:
		MOV AL, BYTE PTR [ESI] ; MOV source text character to al
		XOR AL, BYTE PTR [EBX] ;xor al and key
		MOV byte ptr [EDI], AL ;move result to destination
		INC ESI ;change offsets of source, Key and Destination
		INC EBX
		INC EDI
	LOOP l1
	MOV byte ptr [EDI], 0 ;Add null pointer to the end
	;Retain used registers
	POP EBX
	POP EDI
	POP ESI
	POP ECX
	ret
xorKey endp

;Loop key in address pointed by ESI, EDX no of characters in the key (excluding null character)
;Will loop ECX (excluding null character) no of characters in address pointed by EDI
;Eg. dog becomes dogdogdogdog ... 
setLoopKey proc
;Retain registers
	PUSH ECX
	PUSH EDX
	PUSH ESI
	PUSH EDI
	;Initialize incrementer to 0
	MOV EBX, 0
	l1:
		;Move the key from (source + incrementer) to destination
		MOV AL, BYTE PTR [ESI + EBX]
		MOV BYTE PTR [EDI], AL
		;Increase destination and incrementer
		INC EDI
		INC EBX
		;(IF EDX = 3) EBX can be 0-1-2
		;If next EBX value is less than EDX, let it continue, otherwise reset count of EBX to 0 ; So that the characters repeats from start again
		CMP EBX, EDX
		JB L2
		MOV EBX, 0
		L2:
	LOOP l1
	;Retain registers
	POP EDI
	POP ESI
	POP EDX
	POP ECX
	ret
setLoopKey endp

main PROC
	;Display prompt message
	MOV EDX, OFFSET promptMessage
	CALL WriteString
	CALL CRLF

	;Read text
	MOV EDX, OFFSET text
	MOV ECX, MAX ;Max no of characters to read
	CALL ReadString
	PUSH EAX ;Store the no of characters entered in text in stack

	;Read key
	MOV ECX, MAX ;Max of characters allowed
	MOV EDX, OFFSET key
	CALL ReadString
	PUSH EAX ;Store no of characters in key in stack

	;Set parameters to set loopKey variable
	;if user entered man, loopKey will be manmanman.. based on size of text
	MOV ESI, OFFSET key 
	MOV EDI, OFFSET loopkey
	POP EDX ; Store no of characters in key in EDX
	POP ECX ; Store no of characters in the text in ECX
	;Call setloopkey to set loopkey variable
	CALL setLoopKey

	;Display loopkey
	MOV EDX, OFFSET loopMessage
	CALL CRLF
	CALL WriteString
	CALL CRLF
	MOV EDX, OFFSET loopkey
	CALL WriteString
	CALL CRLF
	CALL CRLF

	;Set parameters to encrypt
	MOV ESI, OFFSET text
	MOV EDI, OFFSET enResult ;Result stored in enResult
	MOV EBX, OFFSET loopkey
	;We already have ECX, no of characters of text set
	;Performing encryption
	CALL xorKey

	;Display Encrypted Message
	MOV EDX, OFFSET encryptedMessage
	CALL WriteString
	CALL CRLF

	MOV EDX, OFFSET enResult
	CALL WriteString
	CALL CRLF
	CALL CRLF

	;Set parameters to decrypt
	MOV ESI, OFFSET enResult
	MOV EDI, OFFSET deResult ;Result stored in deResult
	MOV EBX, OFFSET loopkey
	;We already have ECX, no of characters of text set
	;Performing decryption
	CALL xorKey

	;Display Decrypted Message
	MOV EDX, OFFSET decryptedMessage
	CALL WriteString
	CALL CRLF
	MOV EDX, OFFSET deResult
	CALL WriteString
	EXIT
main ENDP
END main