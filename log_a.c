#include "ntdll.h"
#include "console.h"
#include "utility.h"
#include "intrinsics.h"
#include "process_information.h"

static const char_t* _logWords[7] =
{
    "\x1B[92mDebug\x1B[0m",
    "\x1B[95mVerbose\x1B[0m",
    "\x1B[96mInfo\x1B[0m",
    "\x1B[33mWarning\x1B[0m",
    "\x1B[93mAlert\x1B[0m",
    "\x1B[91mError\x1B[0m",
    "\x1B[31mCritical\x1B[0m"
};

static const uint16_t _logWordLengthMap[7] =
{
    14, // "\x1B[92mDebug\x1B[0m",
    16,	// "\x1B[95mVerbose\x1B[0m",
    13,	// "\x1B[96mInfo\x1B[0m",
    16,	// "\x1B[33mWarning\x1B[0m",
    14,	// "\x1B[93mAlert\x1B[0m",
    14,	// "\x1B[91mError\x1B[0m",
    17	// "\x1B[31mCritical\x1B[0m"
};

#define TIME *(uint64_t*)(0x7FFE0000 +0x14)
#define LOCAL_OFFSET *(uint64_t*)(0x7FFE0000 +0x20)

#define DATE_LENGTH 21
#define PADDING_TARGET (52 + 9) // 52 is effective padding, plus 9 for ANSI codes (5 color, 4 reset)
#define MISC_CHAR_AMOUNT 7

static __forceinline void SetTime(char_t *const restrict buffer, uint64_t const *const restrict localNow)
{
    TIME_FIELDS timeFields;
    char_t *timeStringBuffer = _alloca(5);
    RtlTimeToTimeFields(localNow, &timeFields);

    buffer[0] = '[';
    buffer[5] = '.';
    buffer[8] = '.';
    buffer[11] = ' ';
    buffer[14] = ':';
    buffer[17] = ':';
    buffer[20] = ']';

    uint16_t length = UInt64ToChar(timeFields.Year, timeStringBuffer - 15);
    switch (length)
    {
    case 4:
        buffer[1] = timeStringBuffer[1];
        buffer[2] = timeStringBuffer[2];
        buffer[3] = timeStringBuffer[3];
        buffer[4] = timeStringBuffer[4];
        break;

    case 5:
        buffer[1] = 'W';
        buffer[2] = 'A';
        buffer[3] = 'R';
        buffer[4] = 'N';
        break;

    case 3:
        buffer[1] = '0';
        buffer[2] = timeStringBuffer[2];
        buffer[3] = timeStringBuffer[3];
        buffer[4] = timeStringBuffer[4];
        break;

    case 2:
        buffer[1] = '0';
        buffer[2] = '0';
        buffer[3] = timeStringBuffer[3];
        buffer[4] = timeStringBuffer[4];
        break;

    case 1:
        buffer[1] = '0';
        buffer[2] = '0';
        buffer[3] = '0';
        buffer[4] = timeStringBuffer[4];
        break;
    }

    length = UInt64ToChar(timeFields.Month, timeStringBuffer - 15);
    if (length == 1)
    {
        buffer[6] = '0';
        buffer[7] = timeStringBuffer[4];
    }
    else
    {
        buffer[6] = timeStringBuffer[3];
        buffer[7] = timeStringBuffer[4];
    }

    length = UInt64ToChar(timeFields.Day, timeStringBuffer - 15);
    if (length == 2)
    {
        buffer[9] = timeStringBuffer[3];
        buffer[10] = timeStringBuffer[4];
    }
    else
    {
        buffer[9] = '0';
        buffer[10] = timeStringBuffer[4];
    }

    length = UInt64ToChar(timeFields.Hour, timeStringBuffer - 15);
    if (length == 2)
    {
        buffer[12] = timeStringBuffer[3];
        buffer[13] = timeStringBuffer[4];
    }
    else
    {
        buffer[12] = '0';
        buffer[13] = timeStringBuffer[4];
    }

    length = UInt64ToChar(timeFields.Minute, timeStringBuffer - 15);
    if (length == 2)
    {
        buffer[15] = timeStringBuffer[3];
        buffer[16] = timeStringBuffer[4];
    }
    else
    {
        buffer[15] = '0';
        buffer[16] = timeStringBuffer[4];
    }

    length = UInt64ToChar(timeFields.Second, timeStringBuffer - 15);
    if (length == 2)
    {
        buffer[18] = timeStringBuffer[3];
        buffer[19] = timeStringBuffer[4];
    }
    else
    {
        buffer[18] = '0';
        buffer[19] = timeStringBuffer[4];
    }
}

void ConsoleLog(char_t const *const message, LogLevel logLevel, char_t const *const source)
{
    uint16_t sourceLength = (uint16_t)MemoryGetFirstByteMatchIndexX86(256, null, source);
    uint16_t messageLength = (uint16_t)MemoryGetFirstByteMatchIndexX86(256, null, message);

    ConsoleLogA(message, messageLength, logLevel, source, sourceLength, ProcessInformation.StandardOutput);
}

NtStatus ConsoleLogA(char_t const *const message, uint16_t messageLength, LogLevel logLevel, char_t const *const source, uint16_t sourceLength, Handle outputHandle)
{
    uint32_t bufferOffset = DATE_LENGTH;
    uint64_t localNow = TIME - LOCAL_OFFSET;

    uint32_t infoPortionLength = DATE_LENGTH + MISC_CHAR_AMOUNT + sourceLength + _logWordLengthMap[logLevel];
    uint32_t logLineLength = (PADDING_TARGET > infoPortionLength) ? PADDING_TARGET + messageLength + 1 : infoPortionLength + messageLength + 1; // 1 = \n

    char_t *logLineBuffer = _alloca((uint64_t)logLineLength);

    /* - - - - - - Insert Time - - - - - - - */

    SetTime(logLineBuffer, &localNow);

    /* - - - - - - Insert Info - - - - - - - */

    logLineBuffer[bufferOffset++] = ' ';
    logLineBuffer[bufferOffset++] = '[';
    __movsb(logLineBuffer + bufferOffset, _logWords[logLevel], (uint64_t)_logWordLengthMap[logLevel]);
    bufferOffset += _logWordLengthMap[logLevel];
    logLineBuffer[bufferOffset++] = ']';
    logLineBuffer[bufferOffset++] = '-';
    logLineBuffer[bufferOffset++] = '[';

    __movsb(logLineBuffer + bufferOffset, source, (uint64_t)sourceLength);
    bufferOffset += sourceLength;
    logLineBuffer[bufferOffset++] = ']';

MESSAGE_PADDING:
    logLineBuffer[bufferOffset] = ' ';
    if (++bufferOffset < PADDING_TARGET) goto MESSAGE_PADDING;

    __movsb(logLineBuffer + bufferOffset, message, (uint64_t)messageLength);
    logLineBuffer[logLineLength - 1] = L'\n';

    /* - - - - - - Print Console - - - - - - */

    IO_STATUS_BLOCK ioStatusBlock;
    return NtWriteFile(outputHandle, 0, null, null, &ioStatusBlock, logLineBuffer, logLineLength, 0, null);
}