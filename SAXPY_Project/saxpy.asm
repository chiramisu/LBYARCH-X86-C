.code

saxpy_asm PROC


    ; SAXPY: Z[i] = A * X[i] + Y[i]
    ;
    ; @params
    ; XMM0 = A
    ; RDX = address of X
    ; R8 = address of Y
    ; R9 = address of Z
    ; n = [RSP + 40]
    ;
    ; R10D = n
    ; R11D = i
    ; XMM1 = temp float calculation


    mov     r10d, DWORD PTR [rsp + 40]
    xor     r11d, r11d

loop_start:

    ; if (i >= n)
    ;     stop
    cmp r11d, r10d
    jge loop_end

    ; XMM1 = X[i]
    movss xmm1, DWORD PTR [rdx + r11*4]

    ; XMM1 = A * X[i]
    mulss xmm1, xmm0

    ; XMM1 = A * X[i] + Y[i]
    addss xmm1, DWORD PTR [r8 + r11*4]

    ; Z[i] = XMM1
    movss DWORD PTR [r9 + r11*4], xmm1

    ; i++
    inc r11d

    ; repeat loop
    jmp loop_start

loop_end:
    ret


saxpy_asm ENDP

END