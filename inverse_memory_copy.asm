.code

MemoryInverseCopyX86 PROC ; void MemoryInverseCopyX86(uint64_t count, void *const source, void *const destination)
    ; rcx = count
    ; rdx = source
    ; r8  = destination
    ; ------------------
    ; r9  = rsi storage
    ; r10 = rdi storage

    mov r9, rsi         ; preserve rsi
    mov r10, rdi        ; preserve rdi

    std
    lea rsi, [rdx + rcx - 1]    ; source → rsi
    lea rdi, [r8 + rcx - 1]     ; destination → rdi
    rep movsb
    cld

    mov rsi, r9         ; restore rsi
    mov rdi, r10        ; restore rdi

    ret

MemoryInverseCopyX86 ENDP

END