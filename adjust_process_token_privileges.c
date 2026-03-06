#include "ntdll.h"
#include "console.h"
#include "utility.h"
#include "advapi32.h"

static wchar_t const SeLockMemoryPrivilege[] = L"SeLockMemoryPrivilege";
static wchar_t const SeChangeNotifyPrivilege[] = L"SeChangeNotifyPrivilege";

static boolean_t DisablePrivilege(Handle token, LUID *luid)
{
	TOKEN_PRIVILEGES tokenPrivileges;
	tokenPrivileges.PrivilegeCount = 1;
	tokenPrivileges.Privileges[0].Luid = *luid;
	tokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_REMOVED;

	if (STATUS_SUCCESS != NtAdjustPrivilegesToken(token, 0, &tokenPrivileges, sizeof(tokenPrivileges), null, null))
	{
		ConsoleWrite("NtAdjustPrivilegesToken() failed at step remove privilege\n");
		return false;
	}

	return true;
}

static boolean_t EnableSeLockMemoryPrivilege(Handle token)
{
	LUID luid = { 0 };
	if (!LookupPrivilegeValueW(null, L"SeLockMemoryPrivilege", &luid))
	{
		ConsoleWrite("NtAdjustPrivilegesToken() failed at step enable SeLockMemoryPrivilege\n");
		return false;
	}

	TOKEN_PRIVILEGES tokenPrivileges;
	tokenPrivileges.PrivilegeCount = 1;
	tokenPrivileges.Privileges[0].Luid = luid;
	tokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (STATUS_SUCCESS != NtAdjustPrivilegesToken(token, 0, &tokenPrivileges, sizeof(tokenPrivileges), null, null))
	{
		ConsoleWrite("NtAdjustPrivilegesToken() failed at step enable SeLockMemoryPrivilege\n");
		return false;
	}

	return true;
}

boolean_t AdjustProcessTokenPrivileges()
{
	Handle token = null;
	if (STATUS_SUCCESS != NtOpenProcessToken((Handle)-1i64, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token))
	{
		ConsoleWrite("NtOpenProcessToken() failed.\n");
		return false;
	}

	if (!EnableSeLockMemoryPrivilege(token)) return false;
	ConsoleWrite("Enabled: EnableSeLockMemoryPrivilege\n\n");

	// -----------------------------------------------------------------

	uint32_t length = 0;
	if (STATUS_BUFFER_TOO_SMALL != NtQueryInformationToken(token, TokenPrivileges, null, null, &length))
	{
		ConsoleWrite("NtQueryInformationToken() failed at step length query\n");
		return false;
	}

	TOKEN_PRIVILEGES *tokenPrivilegesPointer = (TOKEN_PRIVILEGES *)_alloca(length);
	if (STATUS_SUCCESS != NtQueryInformationToken(token, TokenPrivileges, tokenPrivilegesPointer, length, &length))
	{
		ConsoleWrite("NtQueryInformationToken() failed at step query data\n");
		return false;
	}

	// -----------------------------------------------------------------

	IO_STATUS_BLOCK ioStatusBlock = { 0 };
	wchar_t *name = (wchar_t *)_alloca(256);

	for (uint16_t i = 0; i < tokenPrivilegesPointer->PrivilegeCount; ++i)
	{
		uint32_t nameLength = 128;
		LUID_AND_ATTRIBUTES *entry = &tokenPrivilegesPointer->Privileges[i];

		if (!LookupPrivilegeNameW(null, &entry->Luid, name, &nameLength))
		{
			ConsoleWrite("LookupPrivilegeNameW() failed\n");
			return false;
		}

		if (!MemoryCompareX86(nameLength, name, SeLockMemoryPrivilege) && !MemoryCompareX86(nameLength, name, SeChangeNotifyPrivilege))
		{
			if (DisablePrivilege(token, &entry->Luid))
			{
				ConsoleWrite("Removed: ");
				NtWriteFile(ConsoleWriteHandle, null, null, null, &ioStatusBlock, name, nameLength << 1, 0, null);
				NtWriteFile(ConsoleWriteHandle, null, null, null, &ioStatusBlock, "\n", 1, 0, null);
			}
		}
		else
		{
			ConsoleWrite("Keeping: ");
			NtWriteFile(ConsoleWriteHandle, null, null, null, &ioStatusBlock, name, nameLength << 1, 0, null);
			NtWriteFile(ConsoleWriteHandle, null, null, null, &ioStatusBlock, "\n", 1, 0, null);
		}
	}

	NtWriteFile(ConsoleWriteHandle, null, null, null, &ioStatusBlock, "\n", 1, 0, null);

	return true;
}