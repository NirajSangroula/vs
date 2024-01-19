INCLUDE Irvine32.inc
Student STRUCT
	namet byte 20 dup(?)
	align dword
	id dword ?
	align byte
	class byte ?
Student ENDS
.data
; declare variables here
niraj Student <"Niraj Sangroula", 433, 14>
.code

main PROC
	mov edx, offset niraj.namet
	call WriteString
	EXIT
main ENDP
END main