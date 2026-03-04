.code

MemoryCompareX86 PROC ; boolean_t MemoryCompareX86(uint64_t count, void const *buffer, void const *compare)
    ; rcx = count
    ; rdx = buffer
    ; r8  = compare
    ; ------------------
    ; r9  = rsi storage
    ; r10 = rdi storage

    mov r9, rsi         ; preserve rsi
    mov r10, rdi        ; preserve rdi

    mov rsi, rdx        ; buffer → rsi
    mov rdi, r8         ; compare → rdi

    repe cmpsb
    setz al

    mov rsi, r9         ; restore rsi
    mov rdi, r10        ; restore rdi

    ret

MemoryCompareX86 ENDP

END