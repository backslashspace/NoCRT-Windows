#include "console.h"
#include "intrinsics.h"
#include "kernelbase.h"
#include "process_information.h"

typedef union CPUID_FIELDS
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
} CPUID_FIELDS;
_Static_assert(sizeof(CPUID_FIELDS) == 16, "CPUID_FIELDS was NOT 16 bytes.");

// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

void PrintCPUIDInformation()
{
	ConsoleWrite(u"# CPU ID\n\n");

	char_t vendorString[13];
	char_t processorName[49];

	boolean_t isAMD = false;
	boolean_t isIntel = false;

	boolean_t erms = false;
	boolean_t rdrand = false;
	boolean_t rdseed = false;
	boolean_t amxTile = false;
	boolean_t avx512F = false;
	boolean_t _1GBPages = false;
	boolean_t monitorX = false;
	boolean_t invariantTSC = false;
	boolean_t monitorXExtensions = false;
	boolean_t monitorXInterrupExempt = false;

	CPUID_FIELDS cpuid = { 0 };

	// cpu brand string
	__cpuidex((uint32_t *)&processorName, 0x80000002, 0);
	__cpuidex((uint32_t *)&processorName + 4, 0x80000003, 0);
	__cpuidex((uint32_t *)&processorName + 8, 0x80000004, 0);
	processorName[48] = 0;

	// cpu vendor string
	__cpuidex(&cpuid.CPUIdentification, 0x0, 0);
	uint32_t *vendorView = (uint32_t *)vendorString;
	vendorView[0] = cpuid.Registers.EBX;
	vendorView[1] = cpuid.Registers.EDX;
	vendorView[2] = cpuid.Registers.ECX;
	vendorString[12] = 0;

	isIntel = vendorView[0] == 1970169159 && vendorView[1] == 1231384169 && vendorView[2] == 1818588270;
	isAMD = vendorView[0] == 1752462657 && vendorView[1] == 1769238117 && vendorView[2] == 1145913699;

	// rdrand, 
	__cpuidex(&cpuid.CPUIdentification, 0x1, 0);
	rdrand = cpuid.BitFields.ECX.F30;

	// monitorX, 1gb page support
	__cpuidex(&cpuid.CPUIdentification, 0x80000001, 0);
	if (isAMD) monitorX = cpuid.BitFields.ECX.F29;
	_1GBPages = cpuid.BitFields.EDX.F26;
	
	if (isAMD)
	{
		// monitorX extensions are supported
		// allow interrupts to cause exit from the monitor event pending state when eFLAGS.IF =0
		__cpuidex(&cpuid.CPUIdentification, 0x5, 0);
		monitorXExtensions = cpuid.BitFields.ECX.F0;
		monitorXInterrupExempt = cpuid.BitFields.ECX.F1;
	}

	// supports avx512 foundation, rdseed, enhanced REP MOVSB/STOSB support
	__cpuidex(&cpuid.CPUIdentification, 0x7, 0);
	if (isIntel) erms = cpuid.BitFields.EBX.F9;
	rdseed = cpuid.BitFields.EBX.F18;
	amxTile = cpuid.BitFields.EDX.F24;
	avx512F = cpuid.BitFields.EBX.F16;

	// invariant tsc
	__cpuidex(&cpuid.CPUIdentification, 0x80000007, 0);
	invariantTSC = cpuid.BitFields.EDX.F8;

	if (isAMD)
	{
		// enhanced REP MOVSB/STOSB support
		__cpuidex(&cpuid.CPUIdentification, 0x80000021, 0);
		erms = cpuid.BitFields.EAX.F15;
	}

	// ---------------------------------------------------------------------

	ConsoleWrite(u"Vendor: ");
	WriteConsoleA(OwnProcessInformation.StandardOutput, vendorString, (uint32_t)MemoryGetFirstByteMatchIndexX86(256, null, vendorString), null, null);
	ConsoleWrite(u"\nModel name: ");
	WriteConsoleA(OwnProcessInformation.StandardOutput, processorName, (uint32_t)MemoryGetFirstByteMatchIndexX86(256, null, processorName), null, null);

	if (erms) ConsoleWrite(u"\n\nEnhanced REP MOVSB/STOSB supported\n");
	else ConsoleWrite(u"\n\nEnhanced REP MOVSB/STOSB NOT supported\n");
	if (rdrand) ConsoleWrite(u"RDRAND supported\n");
	else ConsoleWrite(u"RDRAND NOT supported\n");
	if (rdseed) ConsoleWrite(u"RDSEED supported\n");
	else ConsoleWrite(u"RDSEED NOT supported\n");
	if (amxTile) ConsoleWrite(u"Intel AMX Tile supported\n");
	else ConsoleWrite(u"Intel AMX-Tile NOT supported\n");
	if (avx512F) ConsoleWrite(u"AVX512F supported\n");
	else ConsoleWrite(u"AVX512F NOT supported\n");
	if (_1GBPages) ConsoleWrite(u"1GB pages supported\n");
	else ConsoleWrite(u"1GB pages NOT supported\n");
	if (invariantTSC) ConsoleWrite(u"Invariant TSC supported\n");
	else ConsoleWrite(u"TSC NOT invariant\n");
	
	if (isAMD)
	{
		if (monitorX) ConsoleWrite(u"MonitorX supported\n");
		else ConsoleWrite(u"MonitorX NOT supported\n");
		if (monitorXExtensions) ConsoleWrite(u"MonitorX extensions supported\n");
		else ConsoleWrite(u"MonitorX extensions NOT supported\n");
		if (monitorXInterrupExempt) ConsoleWrite(u"MonitorX interrupt eFLAGS ignore supported\n");
		else ConsoleWrite(u"MonitorX interrupt eFLAGS ignore NOT supported\n");
	}

	ConsoleWrite(u"\n----------------------------------------------------------------\n\n");
}