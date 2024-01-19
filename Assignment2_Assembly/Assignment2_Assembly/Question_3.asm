COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
!

INCLUDE Irvine32.inc
.data
	;Variables to store first 2 numbers, and fibonacci numbers
	fib1 dword 1
	fib2 dword 1
	fibonacciNumber dword 20 dup(?)
.code
main PROC
	;EAX, EBX, EDX will be used so that EDX = EAX + EBX in each loop
	;First initialize EAX and EBX with initial values
	MOV EAX, fib1
	MOV EBX, fib2
	MOV ECX, 20 ; For loop counter
	MOV EDI, 0 ; For destination index counting
	L1:
	MOV fibonacciNumber[EDI], EAX ; Write first variable value to memory
	MOV EDX, 0 ; EDX = EAX + EBX
	ADD EDX, EAX
	ADD EDX, EBX
	
	MOV EAX, EBX ; EAX = EBX (Like a = b)
	MOV EBX, EDX ; EBX = EDX (Like b = c)
	;So that the next time, a will have current value of b and 
	; b will have current value of c and the process continues to create next fibonacci number a + b
	ADD EDI, 4 ; Increase next storage address index
	LOOP L1
	EXIT
main ENDP
END main