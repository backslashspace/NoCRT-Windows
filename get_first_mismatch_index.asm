.code

MemoryGetFirstByteMatchIndexX86 PROC; (void const *buffer, uint8_t const value, uint64_t count)
    ; RCX = buffer
    ; RDX = value
    ; R8  = count
    ; ------------------
    ; R9  = intermediate
    ; R10 = rdi storage

    mov     r10, rdi        ; preserve rdi
    mov     r9, r8          ; intermediate - store count

    mov     rdi, rcx        ; rdi = buffer
    mov     rcx, r8         ; rcx = count
    mov     al, dl          ; al  = value
    repne   scasb           ; scan for al in [rdi]

    dec     rcx
    lea     rax, [r9 - 2]
    sub     rax, rcx

    cmp     rcx, -1
    cmove   rax, rcx         ; -1 if not found

    mov     rdi, r10        ; restore rdi
    ret

MemoryGetFirstByteMatchIndexX86 ENDP

MemoryGetFirstWordMatchIndexX86 PROC; (void const *buffer, uint16_t const value, uint64_t count)
    ; RCX = buffer
    ; RDX = value
    ; R8  = count
    ; ------------------
    ; R9  = intermediate
    ; R10 = rdi storage

    mov     r10, rdi        ; preserve rdi
    mov     r9, r8          ; intermediate - store count

    mov     rdi, rcx        ; rdi = buffer
    mov     rcx, r8         ; rcx = count
    mov     ax, dx          ; ax  = value
    repne   scasw           ; scan for ax in [rdi]

    dec     rcx
    lea     rax, [r9 - 2]
    sub     rax, rcx

    cmp     rcx, -1
    cmove   rax, rcx         ; -1 if not found

    mov     rdi, r10        ; restore rdi
    ret

MemoryGetFirstWordMatchIndexX86 ENDP

END