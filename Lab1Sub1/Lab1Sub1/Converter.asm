INCLUDE Irvine32.inc
.data
	prompt1 BYTE "Enter the first number: ",0
.code
main PROC
	MOV EDX, OFFSET prompt1 ;Prompt for the number
	CALL WriteString
	CALL ReadInt
	CALL WriteBin ;Write the value in EAX as binary
	CALL CRLF ;Carriage Return, Line feed
	CALL WriteHex ;Write the value in EAX as hexadecimal
	EXIT
main ENDP
end main
