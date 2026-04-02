#pragma once
#include "types.h"

// ░░░ Constants ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#define FAST_FAIL_LEGACY_GS_VIOLATION               0
#define FAST_FAIL_VTGUARD_CHECK_FAILURE             1
#define FAST_FAIL_STACK_COOKIE_CHECK_FAILURE        2
#define FAST_FAIL_CORRUPT_LIST_ENTRY                3
#define FAST_FAIL_INCORRECT_STACK                   4
#define FAST_FAIL_INVALID_ARG                       5
#define FAST_FAIL_GS_COOKIE_INIT                    6
#define FAST_FAIL_FATAL_APP_EXIT                    7
#define FAST_FAIL_RANGE_CHECK_FAILURE               8
#define FAST_FAIL_UNSAFE_REGISTRY_ACCESS            9
#define FAST_FAIL_GUARD_ICALL_CHECK_FAILURE         10
#define FAST_FAIL_GUARD_WRITE_CHECK_FAILURE         11
#define FAST_FAIL_INVALID_FIBER_SWITCH              12
#define FAST_FAIL_INVALID_SET_OF_CONTEXT            13
#define FAST_FAIL_INVALID_REFERENCE_COUNT           14
#define FAST_FAIL_INVALID_JUMP_BUFFER               18
#define FAST_FAIL_MRDATA_MODIFIED                   19
#define FAST_FAIL_CERTIFICATION_FAILURE             20
#define FAST_FAIL_INVALID_EXCEPTION_CHAIN           21
#define FAST_FAIL_CRYPTO_LIBRARY                    22
#define FAST_FAIL_INVALID_CALL_IN_DLL_CALLOUT       23
#define FAST_FAIL_INVALID_IMAGE_BASE                24
#define FAST_FAIL_DLOAD_PROTECTION_FAILURE          25
#define FAST_FAIL_UNSAFE_EXTENSION_CALL             26
#define FAST_FAIL_DEPRECATED_SERVICE_INVOKED        27
#define FAST_FAIL_INVALID_BUFFER_ACCESS             28
#define FAST_FAIL_INVALID_BALANCED_TREE             29
#define FAST_FAIL_INVALID_NEXT_THREAD               30
#define FAST_FAIL_GUARD_ICALL_CHECK_SUPPRESSED      31         // Telemetry, nonfatal
#define FAST_FAIL_APCS_DISABLED                     32
#define FAST_FAIL_INVALID_IDLE_STATE                33
#define FAST_FAIL_MRDATA_PROTECTION_FAILURE         34
#define FAST_FAIL_UNEXPECTED_HEAP_EXCEPTION         35
#define FAST_FAIL_INVALID_LOCK_STATE                36
#define FAST_FAIL_GUARD_JUMPTABLE                   37         // Known to compiler, must retain value 37
#define FAST_FAIL_INVALID_LONGJUMP_TARGET           38
#define FAST_FAIL_INVALID_DISPATCH_CONTEXT          39
#define FAST_FAIL_INVALID_THREAD                    40
#define FAST_FAIL_INVALID_SYSCALL_NUMBER            41         // Telemetry, nonfatal
#define FAST_FAIL_INVALID_FILE_OPERATION            42         // Telemetry, nonfatal
#define FAST_FAIL_LPAC_ACCESS_DENIED                43         // Telemetry, nonfatal
#define FAST_FAIL_GUARD_SS_FAILURE                  44
#define FAST_FAIL_LOADER_CONTINUITY_FAILURE         45         // Telemetry, nonfatal
#define FAST_FAIL_GUARD_EXPORT_SUPPRESSION_FAILURE  46
#define FAST_FAIL_INVALID_CONTROL_STACK             47
#define FAST_FAIL_SET_CONTEXT_DENIED                48
#define FAST_FAIL_INVALID_IAT                       49
#define FAST_FAIL_HEAP_METADATA_CORRUPTION          50
#define FAST_FAIL_PAYLOAD_RESTRICTION_VIOLATION     51
#define FAST_FAIL_LOW_LABEL_ACCESS_DENIED           52         // Telemetry, nonfatal
#define FAST_FAIL_ENCLAVE_CALL_FAILURE              53
#define FAST_FAIL_UNHANDLED_LSS_EXCEPTON            54
#define FAST_FAIL_ADMINLESS_ACCESS_DENIED           55         // Telemetry, nonfatal
#define FAST_FAIL_UNEXPECTED_CALL                   56
#define FAST_FAIL_CONTROL_INVALID_RETURN_ADDRESS    57
#define FAST_FAIL_UNEXPECTED_HOST_BEHAVIOR          58
#define FAST_FAIL_FLAGS_CORRUPTION                  59
#define FAST_FAIL_VEH_CORRUPTION                    60
#define FAST_FAIL_ETW_CORRUPTION                    61
#define FAST_FAIL_RIO_ABORT                         62
#define FAST_FAIL_INVALID_PFN                       63
#define FAST_FAIL_GUARD_ICALL_CHECK_FAILURE_XFG     64
#define FAST_FAIL_CAST_GUARD                        65         // Known to compiler, must retain value 65
#define FAST_FAIL_HOST_VISIBILITY_CHANGE            66
#define FAST_FAIL_KERNEL_CET_SHADOW_STACK_ASSIST    67
#define FAST_FAIL_PATCH_CALLBACK_FAILED             68
#define FAST_FAIL_NTDLL_PATCH_FAILED                69
#define FAST_FAIL_INVALID_FLS_DATA                  70
#define FAST_FAIL_ASAN_ERROR                        71         // Known to Asan, must retain value 71
#define FAST_FAIL_CLR_EXCEPTION_AOT                 72
#define FAST_FAIL_POINTER_AUTH_INVALID_RETURN_ADDRESS 73
#define FAST_FAIL_INVALID_THREAD_STATE              74
#define FAST_FAIL_CORRUPT_WOW64_STATE               75
#define FAST_FAIL_INVALID_EXTENDED_STATE            76
#define FAST_FAIL_KERNEL_POINTER_EXPECTED           77
#define FAST_FAIL_INVALID_FAST_FAIL_CODE            0xFFFFFFFF

// ░░░ Prototypes ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#ifdef __INTELLISENSE__  // for VS editor only

// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/memcpy-wmemcpy?view=msvc-170
void *memcpy(void *destination, const void *source, uint64_t count);

// https://learn.microsoft.com/en-us/cpp/intrinsics/stosb?view=msvc-170
void __stosb(void *Destination, uint8_t Data, uint64_t Count) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/movsb?view=msvc-170
void __movsb(void *Destination, void const *Source, uint64_t Count) {}

// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/alloca?view=msvc-170
void *_alloca(uint64_t size) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/readgsbyte-readgsdword-readgsqword-readgsword?view=msvc-170
uint64_t __readgsqword(uint32_t Offset) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/rdtscp?view=msvc-170
uint64_t __rdtscp(uint32_t *AUX) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/rdtsc?view=msvc-170
uint64_t __rdtsc() {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/fastfail?view=msvc-170
__declspec(noreturn) void __fastfail(uint32_t code) {}

// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#othertechs=CRC32
uint32_t _mm_crc32_u8(uint32_t crc, uint8_t v) {}
uint32_t _mm_crc32_u16(uint32_t crc, uint16_t v) {}
uint32_t _mm_crc32_u32(uint32_t crc, uint32_t v) {}
uint64_t _mm_crc32_u64(uint64_t crc, uint64_t v) {}

// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#othertechs=RDRAND
uint32_t _rdrand16_step(uint16_t *val) {}
uint32_t _rdrand32_step(uint32_t *val) {}
uint32_t _rdrand64_step(uint64_t *val) {}

// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#othertechs=RDSEED
uint32_t _rdseed16_step(uint16_t *val) {}
uint32_t _rdseed32_step(uint32_t *val) {}
uint32_t _rdseed64_step(uint64_t *val) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/interlockedcompareexchange-intrinsic-functions?view=msvc-170
uint8_t _InterlockedCompareExchange8(uint8_t volatile *Destination, uint8_t Exchange, uint8_t Comparand) {}
uint16_t _InterlockedCompareExchange16(uint16_t volatile *Destination, uint16_t Exchange, uint16_t Comparand) {}
uint32_t _InterlockedCompareExchange(uint32_t volatile *Destination, uint32_t Exchange, uint32_t Comparand) {}
uint64_t _InterlockedCompareExchange64(uint64_t volatile *Destination, uint64_t Exchange, uint64_t Comparand) {}
// https://learn.microsoft.com/en-us/cpp/intrinsics/interlockedcompareexchangepointer-intrinsic-functions?view=msvc-170
void *_InterlockedCompareExchangePointer(void *volatile *Destination, void *Exchange, void *Comparand) {}
// https://learn.microsoft.com/en-us/cpp/intrinsics/interlockedcompareexchange128?view=msvc-170
uint8_t _InterlockedCompareExchange128(uint64_t volatile *Destination, uint64_t ExchangeHigh, uint64_t ExchangeLow, uint64_t *ComparandResult) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/interlockedexchange-intrinsic-functions?view=msvc-170
uint8_t _InterlockedExchange8(uint8_t volatile *Target, uint8_t Value) {}
uint16_t _InterlockedExchange16(uint16_t volatile *Target, uint16_t Value) {}
uint32_t _InterlockedExchange(uint32_t volatile *Target, uint32_t Value) {}
uint64_t _InterlockedExchange64(uint64_t volatile *Target, uint64_t Value) {}
// https://learn.microsoft.com/en-us/cpp/intrinsics/interlockedexchangepointer-intrinsic-functions?view=msvc-170
void* _InterlockedExchangePointer(void *volatile *Target, void *Value) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/interlockedexchangeadd-intrinsic-functions?view=msvc-170
uint8_t _InterlockedExchangeAdd8(uint8_t volatile *Addend, uint8_t Value) {}
uint16_t _InterlockedExchangeAdd16(uint16_t volatile *Addend, uint16_t Value) {}
uint32_t _InterlockedExchangeAdd(uint32_t volatile *Addend, uint32_t Value) {}
uint64_t _InterlockedExchangeAdd64(uint64_t volatile *Addend, uint64_t Value) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/interlockedincrement-intrinsic-functions?view=msvc-170
uint16_t _InterlockedIncrement16(uint16_t volatile *lpAddend) {}
uint32_t _InterlockedIncrement(uint32_t volatile *lpAddend) {}
uint64_t _InterlockedIncrement64(uint64_t volatile *lpAddend) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/cpuid-cpuidex?view=msvc-170
void __cpuid(uint32_t cpuInfo[4], uint32_t function_id);
void __cpuidex(uint32_t cpuInfo[4], uint32_t function_id, uint32_t subfunction_id);

// https://learn.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-yieldprocessor
void _mm_pause() {}

// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#text=_mm_lfence
void _mm_lfence() {}
// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#text=_mm_sfence
void _mm_sfence() {}
// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#text=_mm_mfence
void _mm_mfence() {}

// https://clang.llvm.org/doxygen/mwaitxintrin_8h.html
void _mm_mwaitx(void *__extensions, uint32_t __hints, uint32_t __clock) {}
void _mm_monitorx(void *__p, uint32_t __extensions, uint32_t __hints) {}

// https://learn.microsoft.com/en-us/cpp/intrinsics/writebarrier?view=msvc-170
void _WriteBarrier() {}
// https://learn.microsoft.com/de-de/cpp/intrinsics/readwritebarrier?view=msvc-170
void _ReadWriteBarrier() {}
// https://learn.microsoft.com/de-de/cpp/intrinsics/readbarrier?view=msvc-170
void _ReadBarrier() {}

#endif