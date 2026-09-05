#pragma once
#include "types.h"

boolean_t EnableAndTestXTermOutput();

void TestExceptions();

boolean_t ASLR();

void PrintCPUIDInformation();

void TestDNS();

void TestUDP();
void TestTCP();

boolean_t TestLargePageThreadStack();
NtStatus LargePageStackTestThreadMain(void *argument);

void TestMWaitXSpinWait();

void TestStatusBar(Handle const outputHandle);

void PrintArguments();