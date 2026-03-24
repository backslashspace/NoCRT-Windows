#include "ntdll.h"
#include "utility.h"
#include "console.h"

static uint32_t _globalVariable = 0;

void ASLR()
{
	ConsoleWrite("# ASLR\n\nFunction and global data ASLR should at least change after a reboot.\n");

	uint32_t stackVariable = 67;

	uint32_t *stackVariablePointer = &stackVariable;
	uint32_t *globalVariablePointer = &_globalVariable;

	void (*functionPointer)() = &ASLR;

	uint64_t size = 4096;
	void *heapMemory = null;
	if (0 != NtAllocateVirtualMemory((Handle)-1, &heapMemory, 0, &size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE))
	{
		ConsoleWrite("Failed to allocate heap memory");
		NtTerminateProcess((Handle)-1, 67);
	}

	/* ----------------------------------------------------- */

	char_t *stackVariableString = (char_t *)_alloca(21);
	stackVariableString[20] = '\n';
	uint16_t stackVariableStringLength = UInt64ToChar((uint64_t)stackVariablePointer, stackVariableString);

	char_t *globalVariableString = (char_t *)_alloca(21);
	uint16_t globalVariableStringLength = UInt64ToChar((uint64_t)globalVariablePointer, globalVariableString);
	globalVariableString[20] = '\n';

	char_t *functionVariableString = (char_t *)_alloca(21);
	uint16_t functionVariableStringLength = UInt64ToChar((uint64_t)functionPointer, functionVariableString);
	functionVariableString[20] = '\n';

	char_t *heapVariableString = (char_t *)_alloca(21);
	uint16_t heapVariableStringLength = UInt64ToChar((uint64_t)heapMemory, heapVariableString);
	heapVariableString[20] = '\n';

	ConsoleWrite("Stack Variable: ");
	ConsoleWriteA(stackVariableString + (20 - stackVariableStringLength), stackVariableStringLength + 1);
	ConsoleWrite("Global Variable: ");
	ConsoleWriteA(globalVariableString + (20 - globalVariableStringLength), globalVariableStringLength + 1);
	ConsoleWrite("Function Pointer: ");
	ConsoleWriteA(functionVariableString + (20 - functionVariableStringLength), functionVariableStringLength + 1);
	ConsoleWrite("Heap Memory: ");
	ConsoleWriteA(heapVariableString + (20 - heapVariableStringLength), heapVariableStringLength + 1);
	ConsoleWrite("\n");
}