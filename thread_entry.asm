EXTERN TestThreadMain:PROC

THREAD_START_PARAMETER STRUCT
	NtTerminateThread QWORD ?					
	StackBase QWORD ?							; base is bottom of buffer - stack grows down - StackBase = buffer + bufferSize - must be 16 byte aligned
	StackLimit QWORD ?							; base is bottom of buffer - stack grows down - StackBase = buffer + bufferSize - must be 16 byte aligned
	Argument QWORD ?
	Flag QWORD ?								; will turn non 0 when entry is done
THREAD_START_PARAMETER ENDS

.code

	ThreadEntry PROC FRAME; NtStatus (THREAD_START_PARAMETER *threadStartParameter)
	; RCX = *threadStartParameter

		lfence
		rdtsc
		lfence
		shl RDX, 32												; shift high bits up
		or  RAX, RDX											; combine to RAX register

		mov RDX, RCX											; save own argument (free for callee)
		mov RCX, [RDX].THREAD_START_PARAMETER.Argument			; set argument for callee
		mov RSP, [RDX].THREAD_START_PARAMETER.StackBase			; set new stack
		mov GS:[8], RSP											; set NT_TIB.StackBase to RSP
		mov R8, [RDX].THREAD_START_PARAMETER.StackLimit			; load stack limit
		mov GS:[16], R8											; set NT_TIB.StackLimit to stack limit

		sub RSP, 8												; unwind return address slot
		mov qword ptr [RSP], 0									; simulate return address 0

		sub RSP, 40												; shadow space for both calls plus 8 bytes padding
		.allocstack 40											; only 40 -> unwind lands on RSP value null and stops
		.endprolog

		mov R8, [RDX].THREAD_START_PARAMETER.NtTerminateThread
		mov [RSP+32], R8										; store in padding space

		mov [RDX].THREAD_START_PARAMETER.Flag, rax				; store counter and signal done

		call TestThreadMain										; retuns NtStatus
		mov RCX, -2												; -2 is current thread handle
		mov EDX, EAX											; NtStatus
		call qword ptr [RSP+32]

		ud2														; shouldn't be reachable

	ThreadEntry ENDP

END