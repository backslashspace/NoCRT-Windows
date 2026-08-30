#pragma once
#include "types.h"

boolean_t EnableAndTestXTermOutput();

void TestExceptions();

boolean_t ASLR();

void PrintCPUIDInformation();

boolean_t Multithreading();
NtStatus LargePageStackTestThreadMain(void *argument);

void MWaitX();

void TestStatusBar(Handle const outputHandle);

void PrintArguments();