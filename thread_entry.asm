EXTERN TestThreadMain:PROC

THREAD_START_PARAMETER STRUCT
	NtTerminateThread QWORD ?					
	StackBase QWORD ?							; base is bottom of buffer - stack grows down - StackBase = buffer + bufferSize - must be 16 byte aligned
	Argument QWORD ?
	Flag QWORD ?								; will turn non 0 when entry is done
THREAD_START_PARAMETER ENDS

.code

	ThreadEntry PROC ; NtStatus (THREAD_START_PARAMETER *threadStartParameter)
	; rcx = argument
		
		rdtscp
		lfence
		shl rdx, 32												; shift high bits up
		or  rax, rdx											; combine to one register

		mov rbx, rcx											; free rcx for call argument
		mov rcx, [rbx].THREAD_START_PARAMETER.Argument			; set argument for callee
		mov rsp, [rbx].THREAD_START_PARAMETER.StackBase			; set new stack base
		mov rsi, [rbx].THREAD_START_PARAMETER.NtTerminateThread	; preserve NtTerminateThread in register
		mov [rbx].THREAD_START_PARAMETER.Flag, rax				; store counter and signal done

		sub rsp, 32												; shadow space for both calls
		call TestThreadMain										; retuns NtStatus
		mov rcx, -2												; -2 is current thread handle
		mov edx, eax											; NtStatus
		call rsi

		ud2

	ThreadEntry ENDP

END