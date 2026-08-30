#pragma once
#include "types.h"

boolean_t EnableAndTestXTermOutput();

void TestExceptions();

boolean_t ASLR();

void PrintCPUIDInformation();

boolean_t Multithreading();
NtStatus LargePageStackTestThreadMain(void *argument);

void TestMWaitXSpinWait();

void TestStatusBar(Handle const outputHandle);

void PrintArguments();