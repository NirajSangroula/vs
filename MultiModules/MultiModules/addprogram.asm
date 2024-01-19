include sum.inc
.code
display proc
	mov eax, 4
	CALL WriteInt
	ret
display endp
END