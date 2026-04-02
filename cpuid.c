#include "intrinsics.h"

typedef union CPUID_FIELDS_EX
{
	uint32_t CPUIdentification[4];

	struct
	{
		uint32_t EAX;
		uint32_t EBX;
		uint32_t ECX;
		uint32_t EDX;
	} Registers;

	struct
	{
		struct
		{
			boolean_t F0 : 1;
			boolean_t F1 : 1;
			boolean_t F2 : 1;
			boolean_t F3 : 1;
			boolean_t F4 : 1;
			boolean_t F5 : 1;
			boolean_t F6 : 1;
			boolean_t F7 : 1;
			boolean_t F8 : 1;
			boolean_t F9 : 1;
			boolean_t F10 : 1;
			boolean_t F11 : 1;
			boolean_t F12 : 1;
			boolean_t F13 : 1;
			boolean_t F14 : 1;
			boolean_t F15 : 1;
			boolean_t F16 : 1;
			boolean_t F17 : 1;
			boolean_t F18 : 1;
			boolean_t F19 : 1;
			boolean_t F20 : 1;
			boolean_t F21 : 1;
			boolean_t F22 : 1;
			boolean_t F23 : 1;
			boolean_t F24 : 1;
			boolean_t F25 : 1;
			boolean_t F26 : 1;
			boolean_t F27 : 1;
			boolean_t F28 : 1;
			boolean_t F29 : 1;
			boolean_t F30 : 1;
			boolean_t F31 : 1;
		} EAX;

		struct
		{
			boolean_t F0 : 1;
			boolean_t F1 : 1;
			boolean_t F2 : 1;
			boolean_t F3 : 1;
			boolean_t F4 : 1;
			boolean_t F5 : 1;
			boolean_t F6 : 1;
			boolean_t F7 : 1;
			boolean_t F8 : 1;
			boolean_t F9 : 1;
			boolean_t F10 : 1;
			boolean_t F11 : 1;
			boolean_t F12 : 1;
			boolean_t F13 : 1;
			boolean_t F14 : 1;
			boolean_t F15 : 1;
			boolean_t F16 : 1;
			boolean_t F17 : 1;
			boolean_t F18 : 1;
			boolean_t F19 : 1;
			boolean_t F20 : 1;
			boolean_t F21 : 1;
			boolean_t F22 : 1;
			boolean_t F23 : 1;
			boolean_t F24 : 1;
			boolean_t F25 : 1;
			boolean_t F26 : 1;
			boolean_t F27 : 1;
			boolean_t F28 : 1;
			boolean_t F29 : 1;
			boolean_t F30 : 1;
			boolean_t F31 : 1;
		} EBX;

		struct
		{
			boolean_t F0 : 1;
			boolean_t F1 : 1;
			boolean_t F2 : 1;
			boolean_t F3 : 1;
			boolean_t F4 : 1;
			boolean_t F5 : 1;
			boolean_t F6 : 1;
			boolean_t F7 : 1;
			boolean_t F8 : 1;
			boolean_t F9 : 1;
			boolean_t F10 : 1;
			boolean_t F11 : 1;
			boolean_t F12 : 1;
			boolean_t F13 : 1;
			boolean_t F14 : 1;
			boolean_t F15 : 1;
			boolean_t F16 : 1;
			boolean_t F17 : 1;
			boolean_t F18 : 1;
			boolean_t F19 : 1;
			boolean_t F20 : 1;
			boolean_t F21 : 1;
			boolean_t F22 : 1;
			boolean_t F23 : 1;
			boolean_t F24 : 1;
			boolean_t F25 : 1;
			boolean_t F26 : 1;
			boolean_t F27 : 1;
			boolean_t F28 : 1;
			boolean_t F29 : 1;
			boolean_t F30 : 1;
			boolean_t F31 : 1;
		} ECX;

		struct
		{
			boolean_t F0 : 1;
			boolean_t F1 : 1;
			boolean_t F2 : 1;
			boolean_t F3 : 1;
			boolean_t F4 : 1;
			boolean_t F5 : 1;
			boolean_t F6 : 1;
			boolean_t F7 : 1;
			boolean_t F8 : 1;
			boolean_t F9 : 1;
			boolean_t F10 : 1;
			boolean_t F11 : 1;
			boolean_t F12 : 1;
			boolean_t F13 : 1;
			boolean_t F14 : 1;
			boolean_t F15 : 1;
			boolean_t F16 : 1;
			boolean_t F17 : 1;
			boolean_t F18 : 1;
			boolean_t F19 : 1;
			boolean_t F20 : 1;
			boolean_t F21 : 1;
			boolean_t F22 : 1;
			boolean_t F23 : 1;
			boolean_t F24 : 1;
			boolean_t F25 : 1;
			boolean_t F26 : 1;
			boolean_t F27 : 1;
			boolean_t F28 : 1;
			boolean_t F29 : 1;
			boolean_t F30 : 1;
			boolean_t F31 : 1;
		} EDX;
	} BitFields;
} CPUID_FIELDS_EX;
_Static_assert(sizeof(CPUID_FIELDS_EX) == 16, "CPUID_FIELDS_EX was NOT 16 bytes.");

void PrintCPUIDInformation()
{
	// syscall is supported
	CPUID_FIELDS_EX cpuid = { 0 };
	__cpuidex(&cpuid.CPUIdentification, 0x80000001, 0);
	boolean_t syscall = cpuid.BitFields.EDX.F20;

	// monitorX is supported
	__cpuidex(&cpuid.CPUIdentification, 0x80000001, 0);
	boolean_t monitorX = cpuid.BitFields.ECX.F29;

	__cpuidex(&cpuid.CPUIdentification, 0x5, 0);
	boolean_t monitorX = cpuid.BitFields.ECX.F29;

	//CPUID_FIELDS cpuInfo = { 0 };
	//__cpuidex((uint32_t *)&cpuInfo, 0x80000001, 0);

	//boolean_t syscall = (cpuInfo.EDX >> 20) & 1;




	//uint16_t smallest_line = (uint16_t)(cpuInfo.EAX & 0xFFFF);

	_mm_pause();
}