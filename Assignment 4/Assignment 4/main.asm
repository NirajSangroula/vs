INCLUDE Irvine32.inc

.data
	prompt1 db "Enter the radius of a sphere (positive number only, 0 to exit): ", 0
    prompt2 db "The total surface area of the sphere is: ", 0
    prompt3 db "The volume of the sphere is: ", 0
    radius REAL8 ?
    four DWORD 4

.code
main PROC

    call Clrscr
	finit 
	mov edx,OFFSET prompt1
	call WriteString
	call ReadFloat         ;ST(0) = r

    ; Exponentiation has the highest precedence in this expression.
    
    fmul ST(0), ST(0)    ; ST(0) = radius * radius
    fldpi               ; ST(0) = PI, ST(1) = radius * radius
    fmul                ; multiply ST(1) by ST(0), 
    fild four
    fmul
    

    mov edx,OFFSET prompt2
    call WriteString
    call WriteFloat ; display ST(0): total surface area of sphere
    call Crlf
    EXIT
main endp
end main