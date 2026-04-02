.code

MemoryGetFirstByteMatchIndexX86 PROC ; int64_t MemoryGetFirstByteMatchIndexX86(uint64_t count, uint8_t const value, void const *const buffer)
    ; rcx = count
    ; rdx = value
    ; r8  = buffer
    ; ------------------
    ; r9  = intermediate
    ; r10 = rdi storage

    mov     r10, rdi        ; preserve rdi
    mov     r9, rcx         ; intermediate - store count

    mov     al, dl          ; value → al
    mov     rdi, r8         ; buffer → rdi
    repne   scasb           ; scan for al in [rdi]

    dec     rcx
    lea     rax, [r9 - 2]
    sub     rax, rcx
    cmp     rcx, -1
    cmove   rax, rcx        ; -1 if not found

    mov     rdi, r10        ; restore rdi
    ret

MemoryGetFirstByteMatchIndexX86 ENDP

MemoryGetFirstWordMatchIndexX86 PROC ; int64_t MemoryGetFirstWordMatchIndexX86(uint64_t count, uint16_t const value, void const *const buffer)
    ; rcx = count
    ; rdx = value
    ; r8  = buffer
    ; ------------------
    ; r9  = intermediate
    ; r10 = rdi storage

    mov     r10, rdi        ; preserve rdi
    mov     r9, rcx         ; intermediate - store count

    mov     ax, dx          ; value → ax
    mov     rdi, r8         ; buffer → rdi
    repne   scasw           ; scan for ax in [rdi]

    dec     rcx
    lea     rax, [r9 - 2]
    sub     rax, rcx
    cmp     rcx, -1
    cmove   rax, rcx        ; -1 if not found

    mov     rdi, r10        ; restore rdi
    ret

MemoryGetFirstWordMatchIndexX86 ENDP

END