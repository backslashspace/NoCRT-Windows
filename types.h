#pragma once
_Static_assert((char)255 > (char)0, "/J must be specified to compile - Default char Type Is unsigned");
_Static_assert(sizeof(void *) == 8, "void * is NOT 8 64-Bit");

// ░░░ Visuals ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define null 0
#define true 1
#define false 0

// ░░░ Primitives ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

typedef signed __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;

typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;

typedef unsigned __int8 boolean_t;
typedef unsigned __int32 bool_t;

typedef char char_t;
typedef unsigned __int16 wchar_t;

// ░░░ Scalars ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

typedef uint64_t Handle;
typedef uint32_t NtStatus;