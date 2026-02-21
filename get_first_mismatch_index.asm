.code

MemoryGetFirstByteMatchIndexX86 PROC; (const void* buffer, uint8_t value, uint64_t count)
    ; RCX = buffer
    ; RDX = value
    ; R8  = count
    ; ------------------
    ; R9  = intermediate
    ; R10 = OK

    mov     r11, rdi        ; preserve RDI

    mov     rdi, rcx        ; buffer -> RDI
    mov     rcx, r8         ; count  -> RCX
    mov     al, dl          ; value  -> AL
    mov     r9, r8          ; count  -> R9
    mov     r10, -1         

    repne   scasb           ; scan for AL in [RDI]

    dec     rcx
    sub     r9, 2
    sub     r9, rcx
    cmp     rcx, -1
    cmove   r9, r10

    mov     rax, r9
    mov     rdi, r11

    ret

MemoryGetFirstByteMatchIndexX86 ENDP

MemoryGetFirstWordMatchIndexX86 PROC; (const void* buffer, uint16_t value, uint64_t count)
    ; RCX = buffer
    ; RDX = value
    ; R8  = count
    ; ------------------
    ; R9  = intermediate
    ; R10 = OK

    mov     r11, rdi        ; preserve RDI

    mov     rdi, rcx        ; buffer -> RDI
    mov     rcx, r8         ; count  -> RCX
    mov     ax, dx          ; value  -> AL
    mov     r9, r8          ; count  -> R9
    mov     r10, -1         

    repne   scasw           ; scan for AL in [RDI]

    dec     rcx
    sub     r9, 2
    sub     r9, rcx
    cmp     rcx, -1
    cmove   r9, r10

    mov     rax, r9
    mov     rdi, r11

    ret

MemoryGetFirstWordMatchIndexX86 ENDP

END