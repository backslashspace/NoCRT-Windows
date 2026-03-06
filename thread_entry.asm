EXTERN TestThreadMain:PROC

EXTERN NtTerminateThreadFunctionPointer:QWORD

; typedef struct ThreadStartParameter
; {
;	  void *StackBase; // base is bottom of buffer - stack grows down - StackBase = buffer + bufferSize - must be 16 byte aligned
; 	  uint64_t Argument;
; } ThreadStartParameter;

.code

	ThreadEntry PROC ; NtStatus (ThreadStartParameter *threadStartParameter)
	; rcx = argument
		
		mov rsp, [rcx]			; set new stack base
		mov rcx, [rcx + 8]		; set actuall argument for callee

		sub rsp, 32				; shadow space for both calls
		call TestThreadMain

		mov rcx, -2			    ; -2 is thread handle
		mov edx, eax			; NtStatus
		call NtTerminateThreadFunctionPointer
		ud2

	ThreadEntry ENDP
END

; -----------------------------------------------------------------------
; dont use own NtTerminateThread
;ThreadEntry PROC ; NtStatus (ThreadStartParameter *threadStartParameter)
;	 ; rcx = argument
;	 	
;	 	 mov rdi, rsp			  ; preserve original stack pointer
;	 	 
;	 	 mov rsp, [rcx]			  ; set new stack base
;	 	 mov rcx, [rcx + 8]		  ; set actuall argument for callee
;	 	 
;	 	 sub rsp, 32			  ; shadow space
;	 	 call TestThreadMain
;	 	 add rsp, 32	
;	 	 
;	 	 mov rsp, rdi			  ; restore old stack
;	 	 
;	 	 ret				      ; use eax from call
;	 
;	 ThreadEntry ENDP