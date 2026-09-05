#pragma once
#include "types.h"

typedef struct GUID
{
    uint32_t  Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t Data4[8];
} GUID;