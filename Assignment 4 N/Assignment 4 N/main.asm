INCLUDE Irvine32.inc

.data
    radius real8 ?
    promptRadius byte "Enter radius or 0 to exit : ", 0
    zero real8 0.0
    four real8 4.0
    three real8 3.0
    displayTSA byte "Total surface area of sphere : ", 0
    displayVolume byte "Volume of sphere: ", 0
.code
main PROC
    l1:
    finit
    ;Ask radius to user
    mov edx, offset promptRadius
    call WriteString
    call ReadFloat
    fcom zero
    FNSTSW ax
    SAHF
    je lexit
    jb l1
    ;radius is positive
    FST radius
    
    ;To find total surface area, 4Pi R squared
    FMUL radius ;(r^2)
    fldpi
    FMUL ;pi r ^ 2
    FMUL four;(4 pi r^2)

    ;Display TSA
    mov edx, offset displayTSA
    CALL WriteString
    CALL WriteFloat
    CALL CRLF

    ;Calculate volume = 4/3 pi r^3
    FLD radius
    FMUL radius
    FMUL radius ;r^3
    FLDPI
    FMUL ;pi r^3
    FMUL four ;4 pi r^3
    FDIV three ;4/3 pi r^3
    
    ;Display Volume
    mov edx, offset displayVolume
    CALL WriteString
    CALL WriteFloat
    CALL CRLF

    jmp l1
    lexit:
    EXIT
main endp
end main