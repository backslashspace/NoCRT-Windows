#include "types.h"

static const wchar_t DIGITS_LUTW[201] = L"00010203040506070809101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899";

/// <summary>
/// Written back to front - front bytes might be empty for small numbers
/// </summary>
/// <remarks>
/// To get the actually start use buffer + 20 - length | 20 is internal max length <br/>Version of <see href="https://gist.githubusercontent.com/lpereira/c0bf3ca3148321395037/raw/97aac8794c4c79321f1a102fc2c82d2b05c32878/gistfile1.cpp">facebook_fixed_test</see>
/// </remarks>
/// <param name="value">Input</param>
/// <param name="buffer">Buffer of length 20</param>
/// <returns>Length in visual digits</returns>
uint16_t UInt64ToWChar(uint64_t value, wchar_t *const buffer)
{
    uint16_t position = 19; // max length = 20 - 1
    uint16_t index = 0;

    while (value >= 100)
    {
        index = (value % 100) << 1;
        value /= 100;
        buffer[position] = DIGITS_LUTW[index + 1];
        buffer[position - 1] = DIGITS_LUTW[index];
        position -= 2;
    }

    if (value < 10)
    {
        buffer[position] = (48 + (wchar_t)value);
        return (20 - position);
    }

    index = (uint16_t)value << 1;
    buffer[position] = DIGITS_LUTW[index + 1];
    buffer[position - 1] = DIGITS_LUTW[index];

    return (20 - position + 1);
}