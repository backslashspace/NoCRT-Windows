.code

MWaitXSpinWait PROC ; void MWaitXSpinWait(boolean_t *flag)

	cmp			BYTE PTR [RCX], 0
	jne			EXIT				; early exit

	mov			R8, RCX				; save address

	xor			ECX, ECX			; extensions for monitorx and mwaitx
	xor			EDX, EDX			; hints for monitorx

AGAIN:
	mov			RAX, R8				; address to monitor
	DB			0Fh, 01h, 0FAh		; monitorx
	xor			EAX, EAX			; hints (0 = C1 State)
	DB			0Fh, 01h, 0FBh		; mwaitx

	cmp			BYTE PTR [R8], 0
	je			AGAIN

EXIT:
	ret

MWaitXSpinWait ENDP

END