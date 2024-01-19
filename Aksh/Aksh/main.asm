include Irvine32.inc

.data
key db '12', 0   ; multi-character key
message db 'akshat', 0   ; message to encrypt and decrypt
encrypted db 16 dup(?)  ; buffer to hold encrypted message
decrypted db 16 dup(?)  ; buffer to hold decrypted message

.code
main proc
    ; Encrypt the message
    mov esi, offset message ; set source pointer to message
    mov edi, offset encrypted ; set destination pointer to encrypted buffer
    mov ecx, 0              ; initialize key index to 0
encrypt_loop:
    mov al, byte ptr [esi]       ; load next message character
    mov bl, byte ptr [key+ecx]   ; load next key character
    xor al, bl          ; XOR with key character
    mov byte ptr [edi], al       ; store encrypted character
    inc esi             ; increment source pointer
    inc edi             ; increment destination pointer
    inc ecx             ; increment key index
    cmp byte ptr [key+ecx], 0 ; check for end of key
    jne $+3             ; skip next instruction if not end of key
    mov ecx, 0          ; reset key index to 0 if end of key
    cmp byte ptr [esi], 0 ; check for end of message
    jne encrypt_loop    ; loop until end of message

    mov byte ptr [edi], 0 ; add 0 to the last of encrypted message
    ; Display the encrypted message
    mov edx, offset encrypted ; set source pointer to encrypted buffer
    call WriteString        ; write the message to the console
    call CRLF
    ; Decrypt the message
    mov esi, offset encrypted ; set source pointer to encrypted buffer
    mov edi, offset decrypted ; set destination pointer to decrypted buffer
    mov ecx, 0               ; initialize key index to 0
decrypt_loop:
    mov al, byte ptr [esi]       ; load next encrypted character
    mov bl, byte ptr [key+ecx]   ; load next key character
    xor al, bl          ; XOR with key character
    mov byte ptr [edi], al       ; store decrypted character
    inc esi             ; increment source pointer
    inc edi             ; increment destination pointer
    inc ecx             ; increment key index
    cmp byte ptr [key+ecx], 0 ; check for end of key
    jne $+3             ; skip next instruction if not end of key
    mov ecx, 0          ; reset key index to 0 if end of key
    cmp byte ptr [esi], 0 ; check for end of message
    jne decrypt_loop    ; loop until end of message

    mov byte ptr [edi], 0
    ; Display the decrypted message
    mov edx, offset decrypted ; set source pointer to decrypted buffer
    call WriteString        ; write the message to the console

    ; Exit program
    call Crlf           ; move the cursor to the next line
    xor eax, eax        ; set return value to 0
    ret                 ; return from program
main endp
end main