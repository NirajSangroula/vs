;Sample program
.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO,dwExitCode:DWORD
.data
myCourse Byte "Assembly Language", 0
.code
main PROC
mov eax, 1234FFFFh

mov dx, 4Ah

inc ax                                               

dec dh                                             

add ax, dx
	INVOKE ExitProcess,0
	main ENDP
END main