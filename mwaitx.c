#include "types.h"

typedef __declspec(align(64)) union CACHELINE
{
	char_t Char[64];
	uint16_t UInt16[32];
	uint32_t UInt32[16];
	uint64_t UInt64[8];
} CACHELINE;
_Static_assert(_Alignof(CACHELINE) == 64, "CACHELINE struct was NOT 64 byte aligned.");

void MWaitX()
{

}