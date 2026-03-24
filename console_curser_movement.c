#include "ntdll.h"
#include "console.h"
#include "intrinsics.h"
#include "process_information.h"

static char_t const queryPosition[] = "\x1b[6n";

typedef struct CURSER_POSITION
{
	uint32_t COLOMN;
	uint32_t ROW;
} CURSER_POSITION;

static CURSER_POSITION QueryConsoleCurserPosition()
{
	CURSER_POSITION position;
	IO_STATUS_BLOCK ioStatus;
	uint8_t *const queryBuffer = _alloca(32);

	NtStatus status = NtWriteFile(ProcessInformation.StandardOutput, null, null, null, &ioStatus, queryPosition, sizeof(queryPosition) - 1, null, null);

	uint8_t index = 0;
AHH:
	if (STATUS_SUCCESS != NtReadFile(ProcessInformation.StandardInput, null, null, null, &ioStatus, queryBuffer + index, 1, null, null))
	{
		ConsoleWrite("NtReadFile failed: QueryConsoleCurserPosition()");
		return position;
	}
	if (queryBuffer[index++] != 'R') goto AHH;
	
	_mm_pause();
		
	return position;
}

boolean_t MoveConsoleCurser()
{
	ConsoleWrite("# VT100 Console Control\n\n");

	CURSER_POSITION position = QueryConsoleCurserPosition();


	



	return true;
}