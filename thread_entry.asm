EXTERN TestThreadMain:PROC

EXTERN NtTerminateThreadFunctionPointer:QWORD	; defined in ntdll.h

THREAD_START_PARAMETER STRUCT
	StackBase QWORD ?							; // base is bottom of buffer - stack grows down - StackBase = buffer + bufferSize - must be 16 byte aligned
	Argument QWORD ?
THREAD_START_PARAMETER ENDS

.code

	ThreadEntry PROC ; NtStatus (THREAD_START_PARAMETER *threadStartParameter)
	; rcx = argument
		
		mov rsp, [rcx].THREAD_START_PARAMETER.StackBase		; set new stack base
		mov rcx, [rcx].THREAD_START_PARAMETER.Argument		; set actuall argument for callee

		sub rsp, 32											; shadow space for both calls
		call TestThreadMain

		mov rcx, -2											; -2 is thread handle
		mov edx, eax										; NtStatus
		call NtTerminateThreadFunctionPointer
		ud2

	ThreadEntry ENDP
END

; -----------------------------------------------------------------------
; dont use own NtTerminateThread
; -----------------------------------------------------------------------
;
;ThreadEntry PROC ; NtStatus (THREAD_START_PARAMETER *threadStartParameter)
;	 ; rcx = argument
;	 	
;	 	 mov rdi, rsp										; preserve original stack pointer
;	 	 
;	 	 mov rsp, [rcx].THREAD_START_PARAMETER.StackBase	; set new stack base
		mov rcx, [rcx].THREAD_START_PARAMETER.Argument		; set actuall argument for callee
;	 	 
;	 	 sub rsp, 32										; shadow space
;	 	 call TestThreadMain
;	 	 add rsp, 32	
;	 	 
;	 	 mov rsp, rdi										; restore old stack
;	 	 
;	 	 ret												; use eax from call
;	 
;	 ThreadEntry ENDP