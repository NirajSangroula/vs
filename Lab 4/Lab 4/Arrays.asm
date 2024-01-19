INCLUDE Irvine32.inc
.data
	arr SDWORD 5 DUP(?)
	prompt BYTE "Enter five numbers: ", 0
	comma BYTE ",", 0
.code
main PROC
	MOV EDX, OFFSET prompt
	CALL WriteString
	CALL CRLF

	CALL ReadInt ; Read five numbers and store in array
	MOV arr, EAX

	CALL ReadInt
	MOV arr + 4, EAX

	CALL ReadInt
	MOV arr + 8, EAX

	CALL ReadInt
	MOV arr + 12, EAX

	CALL ReadInt
	MOV arr + 16, EAX

	CALL CRLF

	MOV EAX, arr
	CALL WriteInt
	MOV EDX, OFFSET comma
	CALL WriteString

	MOV EAX, arr[4]
	CALL WriteInt
	MOV EDX, OFFSET comma
	CALL WriteString

	MOV EAX, arr[8]
	CALL WriteInt
	MOV EDX, OFFSET comma
	CALL WriteString

	MOV EAX, arr[12]
	CALL WriteInt
	MOV EDX, OFFSET comma
	CALL WriteString

	MOV EAX, arr[16]
	CALL WriteInt
	EXIT
main ENDP
END main
