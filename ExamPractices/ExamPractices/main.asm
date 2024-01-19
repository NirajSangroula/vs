INCLUDE Irvine32.inc
.data
	 st1 byte "niraj", 0
	 st2 byte "niraj", 0
	 n dword 43
.code

summaker proc uses eax, nums: dword
	local nepal: dword
	mov ebx, nums
	mov nepal, ebx
	mov eax, nepal
	call WriteDec
	ret
summaker endp
main proc
	mov esi, offset st1
	mov edi, offset st2
	invoke str_compare, addr st1, addr st2
	call dumpregs
	invoke summaker, n
	exit
main endp
end main
