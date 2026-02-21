#pragma once
#include "types.h"
#include "intrinsics.h"

// ░░░ String ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

/// <summary>
/// Written back to front - front bytes might be empty for small numbers
/// </summary>
/// <remarks>
/// To get the actually start use buffer + 20 - length | 20 is internal max length <br/>Version of <see href="https://gist.githubusercontent.com/lpereira/c0bf3ca3148321395037/raw/97aac8794c4c79321f1a102fc2c82d2b05c32878/gistfile1.cpp">facebook_fixed_test</see>
/// </remarks>
/// <param name="value">Input</param>
/// <param name="buffer">Buffer of length 20</param>
/// <returns>Length in visual digits</returns>
uint16_t UInt64ToWChar(uint64_t value, wchar_t* buffer);

/// <summary>
/// Written back to front - front bytes might be empty for small numbers
/// </summary>
/// <remarks>
/// To get the actually start use buffer + 20 - length | 20 is internal max length <br/>Version of <see href="https://gist.githubusercontent.com/lpereira/c0bf3ca3148321395037/raw/97aac8794c4c79321f1a102fc2c82d2b05c32878/gistfile1.cpp">facebook_fixed_test</see>
/// </remarks>
/// <param name="value">Input</param>
/// <param name="buffer">Buffer of length 20</param>
/// <returns>Length in visual digits</returns>
uint16_t UInt64ToChar(uint64_t value, char_t* buffer);

// ░░░ K42 ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

/*
A worker comes by and wants to acquire the lock:
	it creates a node on the stack (next = NULL, locked = 1)
	it atomically swaps the global tail pointer to point to its node, remembering the previous tail as its predecessor
	if the predecessor is NULL, it immediately owns the lock
	otherwise, it stores itself in predecessor->next
	it waits until its locked flag is cleared

When releasing:
	it checks if a successor is already linked
	if yes, it wakes the successor
	if not, it tries to reset the global tail to NULL
	if that fails, it waits for a successor to link and then wakes it
*/

typedef struct K42Node
{
	struct K42Node* volatile Next;
	volatile boolean_t Locked;
} K42Node;

static __forceinline void K42_Acquire(K42Node* __restrict node, K42Node* volatile* __restrict globalTail)
{
	node->Next = null;
	node->Locked = 1;

	K42Node* predecessor = (K42Node*)_InterlockedExchangePointer((void* volatile*)globalTail, node);

	if (predecessor == null) return;

	predecessor->Next = node;

	while (node->Locked)
	{
		_mm_pause();
	}
}

static __forceinline void K42_Unlock(K42Node* node, K42Node* volatile* globalNode)
{
	if (node->Next == null)
	{
		if (node == (K42Node*)_InterlockedCompareExchangePointer((void* volatile*)globalNode, null, node)) return;

		while (node->Next == null)
		{
			_mm_pause();
		}
	}

	if (!node->Next) __assume(0);
	node->Next->Locked = 0;
}

// ░░░ Ticket Lock ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

typedef struct
{
	volatile uint32_t Next;
	volatile uint32_t Serving;
} TicketLock;

static __forceinline uint32_t TicketLock_Acquire(TicketLock* lock)
{
	uint32_t ticket = _InterlockedExchangeAdd(&lock->Next, 1);

	while (ticket != lock->Serving)
	{
		_mm_pause();
	}

	return ticket;
}

static __forceinline void TicketLock_Unlock(TicketLock* lock)
{
	_ReadWriteBarrier();
	++lock->Serving;
	_ReadWriteBarrier();
}

// ░░░ X86 String Helper ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// returns -1 if no match is found, otherwise the index
int64_t MemoryGetFirstByteMatchIndexX86(const void* buffer, uint8_t value, uint64_t count);

// returns -1 if no match is found, otherwise the index
int64_t MemoryGetFirstWordMatchIndexX86(const void* buffer, uint16_t value, uint64_t count);