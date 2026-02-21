.code

; must be provided in assembly, or link time optimization will fail
; must probe stack MANUALLY - or crash - use stack reserve = stack commit

__chkstk PROC
ret
__chkstk ENDP

END