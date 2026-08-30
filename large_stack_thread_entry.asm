LARGE_STACK_THREAD_START_PARAMETER STRUCT
	StackSize QWORD ?
	StackMemory QWORD ?
	Argument QWORD ?
	Procedure QWORD ?
	Flag QWORD ?														; set to non zero when done reading this structure
	NtTerminateThread QWORD ?
LARGE_STACK_THREAD_START_PARAMETER ENDS

.code

LargeStackThreadEntry PROC FRAME ; NtStatus (LARGE_STACK_THREAD_START_PARAMETER *threadStartParameter)

	lfence
	rdtsc
	lfence
	shl			RDX, 32													; shift high bits up
	or			RAX, RDX												; combine to RAX

	mov			RDX, RCX												; save own argument (free for callee)
	mov			RCX, [RDX].LARGE_STACK_THREAD_START_PARAMETER.Argument	; set argument for callee

	mov			R8, [RDX].LARGE_STACK_THREAD_START_PARAMETER.StackMemory
	mov			GS:[16], R8												; set NT_TIB.StackLimit
	add			R8, [RDX].LARGE_STACK_THREAD_START_PARAMETER.StackSize
	mov			GS:[8], R8												; set NT_TIB.StackBase
	mov			RSP, R8													; new stack

	sub			RSP, 48													; 8 bytes return address | 8 bytes padding | 32 bytes shadow space for calls
	.allocstack 40														; only 40 -> unwind lands on [RSP] = null and stops
	.endprolog

	mov			R8, [RDX].LARGE_STACK_THREAD_START_PARAMETER.Procedure
	mov			R12, [RDX].LARGE_STACK_THREAD_START_PARAMETER.NtTerminateThread ; original value not preserved - safe because we don't return

	mov			[RDX].LARGE_STACK_THREAD_START_PARAMETER.Flag, RAX		; store counter and signal done - [RDX] now invalid

	call		R8

	mov			RCX, -2													; -2 is current thread handle
	mov			EDX, EAX												; NtStatus
	call		R12														; NtTerminateThread

	ud2																	; shouldn't be reachable

	LargeStackThreadEntry ENDP

END