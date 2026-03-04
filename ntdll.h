#pragma once
#include "types.h"

// ░░░ Definitions uses by NtXxx Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// ################# ntstatus.h #################

#define STATUS_SUCCESS                   ((NtStatus)0x00000000L)
#define STATUS_ACCESS_DENIED             ((NtStatus)0xC0000022L)
#define STATUS_BUFFER_TOO_SMALL          ((NtStatus)0xC0000023L)

// ################# winnt.h #################

#define PAGE_NOACCESS					0x01    
#define PAGE_READONLY					0x02    
#define PAGE_READWRITE					0x04    
#define PAGE_WRITECOPY					0x08    
#define PAGE_EXECUTE					0x10    
#define PAGE_EXECUTE_READ				0x20    
#define PAGE_EXECUTE_READWRITE			0x40    
#define PAGE_EXECUTE_WRITECOPY			0x80    
#define PAGE_GUARD						0x100    
#define PAGE_NOCACHE					0x200    
#define PAGE_WRITECOMBINE				0x400   

#define MEM_COMMIT                      0x00001000  
#define MEM_RESERVE                     0x00002000
#define MEM_RESET                       0x00080000  
#define MEM_TOP_DOWN                    0x00100000  
#define MEM_WRITE_WATCH                 0x00200000  
#define MEM_PHYSICAL                    0x00400000  
#define MEM_RESET_UNDO                  0x01000000  

#define MEM_LARGE_PAGES                 0x20000000 

#define SE_PRIVILEGE_ENABLED_BY_DEFAULT 0x00000001L
#define SE_PRIVILEGE_ENABLED            0x00000002L
#define SE_PRIVILEGE_REMOVED            0X00000004L
#define SE_PRIVILEGE_USED_FOR_ACCESS    0x80000000L

#define SE_PRIVILEGE_VALID_ATTRIBUTES   (SE_PRIVILEGE_ENABLED_BY_DEFAULT | \
                                         SE_PRIVILEGE_ENABLED            | \
                                         SE_PRIVILEGE_REMOVED            | \
                                         SE_PRIVILEGE_USED_FOR_ACCESS)

#define TOKEN_ASSIGN_PRIMARY    (0x0001)
#define TOKEN_DUPLICATE         (0x0002)
#define TOKEN_IMPERSONATE       (0x0004)
#define TOKEN_QUERY             (0x0008)
#define TOKEN_QUERY_SOURCE      (0x0010)
#define TOKEN_ADJUST_PRIVILEGES (0x0020)
#define TOKEN_ADJUST_GROUPS     (0x0040)
#define TOKEN_ADJUST_DEFAULT    (0x0080)
#define TOKEN_ADJUST_SESSIONID  (0x0100)

#define DELETE                           (0x00010000L)
#define READ_CONTROL                     (0x00020000L)
#define WRITE_DAC                        (0x00040000L)
#define WRITE_OWNER                      (0x00080000L)
#define SYNCHRONIZE                      (0x00100000L)

#define STANDARD_RIGHTS_REQUIRED         (0x000F0000L)

#define STANDARD_RIGHTS_READ             (READ_CONTROL)
#define STANDARD_RIGHTS_WRITE            (READ_CONTROL)
#define STANDARD_RIGHTS_EXECUTE          (READ_CONTROL)

#define STANDARD_RIGHTS_ALL              (0x001F0000L)

#define SPECIFIC_RIGHTS_ALL              (0x0000FFFFL)


#define TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED  |\
                          TOKEN_ASSIGN_PRIMARY      |\
                          TOKEN_DUPLICATE           |\
                          TOKEN_IMPERSONATE         |\
                          TOKEN_QUERY               |\
                          TOKEN_QUERY_SOURCE        |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT )


#define TOKEN_ALL_ACCESS  (TOKEN_ALL_ACCESS_P |\
                          TOKEN_ADJUST_SESSIONID )


#define TOKEN_READ       (STANDARD_RIGHTS_READ      |\
                          TOKEN_QUERY)


#define TOKEN_WRITE      (STANDARD_RIGHTS_WRITE     |\
                          TOKEN_ADJUST_PRIVILEGES   |\
                          TOKEN_ADJUST_GROUPS       |\
                          TOKEN_ADJUST_DEFAULT)

#define TOKEN_EXECUTE    (STANDARD_RIGHTS_EXECUTE)

#define TOKEN_TRUST_CONSTRAINT_MASK    (STANDARD_RIGHTS_READ  | \
                                       TOKEN_QUERY  |\
                                       TOKEN_QUERY_SOURCE )

#define TOKEN_TRUST_ALLOWED_MASK    (TOKEN_TRUST_CONSTRAINT_MASK |\
                                    TOKEN_DUPLICATE              |\
                                    TOKEN_IMPERSONATE)


// ░░░ Structs uses by NtXxx Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/api/subauth/ns-subauth-unicode_string
typedef struct UNICODE_STRING
{
	uint16_t Length;
	uint16_t MaximumLength;
	wchar_t *Buffer;
} UNICODE_STRING;

// https://learn.microsoft.com/en-us/windows/win32/api/ntdef/ns-ntdef-string
typedef struct STRING
{
	uint16_t Length;
	uint16_t MaximumLength;
	char_t *Buffer;
} STRING;

// https://learn.microsoft.com/en-us/windows/win32/api/ntdef/ns-ntdef-_object_attributes
typedef struct OBJECT_ATTRIBUTES
{
	uint32_t Length;
	Handle RootDirectory;
	UNICODE_STRING *ObjectName;
	uint32_t Attributes;
	void *SecurityDescriptor;
	void *SecurityQualityOfService;
} OBJECT_ATTRIBUTES;

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block
typedef struct IO_STATUS_BLOCK
{
	union
	{
		NtStatus Status;
		void *Pointer;
	};
	uint64_t Information;
} IO_STATUS_BLOCK;

// // https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ns-wdm-time_fields
typedef struct TIME_FIELDS
{
	uint16_t Year;        // range [1601...]
	uint16_t Month;       // range [1..12]
	uint16_t Day;         // range [1..31]
	uint16_t Hour;        // range [0..23]
	uint16_t Minute;      // range [0..59]
	uint16_t Second;      // range [0..59]
	uint16_t Milliseconds;// range [0..999]
	uint16_t Weekday;     // range [0..6] == [Sunday..Saturday]
} TIME_FIELDS;

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_mode_information
typedef struct FILE_MODE_INFORMATION
{
	uint32_t Mode;
} FILE_MODE_INFORMATION;

// https://learn.microsoft.com/de-de/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid
typedef struct LUID
{
	uint32_t LowPart;
	int32_t HighPart;
} LUID;

// https://learn.microsoft.com/de-de/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes
typedef struct LUID_AND_ATTRIBUTES
{
	LUID Luid;
	uint32_t Attributes;
} LUID_AND_ATTRIBUTES;

// https://learn.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-token_privileges
typedef struct TOKEN_PRIVILEGES
{
	uint32_t PrivilegeCount;
	LUID_AND_ATTRIBUTES Privileges[1];
} TOKEN_PRIVILEGES;

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_object_information_class
typedef enum OBJECT_INFORMATION_CLASS
{
	ObjectBasicInformation = 0,
	ObjectTypeInformation = 2
} OBJECT_INFORMATION_CLASS;

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class
typedef enum FILE_INFORMATION_CLASS
{
	FileDirectoryInformation = 1,
	FileFullDirectoryInformation = 2,
	FileBothDirectoryInformation = 3,
	FileBasicInformation = 4,
	FileStandardInformation = 5,
	FileInternalInformation = 6,
	FileEaInformation = 7,
	FileAccessInformation = 8,
	FileNameInformation = 9,
	FileRenameInformation = 10,
	FileLinkInformation = 11,
	FileNamesInformation = 12,
	FileDispositionInformation = 13,
	FilePositionInformation = 14,
	FileFullEaInformation = 15,
	FileModeInformation = 16,
	FileAlignmentInformation = 17,
	FileAllInformation = 18,
	FileAllocationInformation = 19,
	FileEndOfFileInformation = 20,
	FileAlternateNameInformation = 21,
	FileStreamInformation = 22,
	FilePipeInformation = 23,
	FilePipeLocalInformation = 24,
	FilePipeRemoteInformation = 25,
	FileMailslotQueryInformation = 26,
	FileMailslotSetInformation = 27,
	FileCompressionInformation = 28,
	FileObjectIdInformation = 29,
	FileCompletionInformation = 30,
	FileMoveClusterInformation = 31,
	FileQuotaInformation = 32,
	FileReparsePointInformation = 33,
	FileNetworkOpenInformation = 34,
	FileAttributeTagInformation = 35,
	FileTrackingInformation = 36,
	FileIdBothDirectoryInformation = 37,
	FileIdFullDirectoryInformation = 38,
	FileValidDataLengthInformation = 39,
	FileShortNameInformation = 40,
	FileIoCompletionNotificationInformation = 41,
	FileIoStatusBlockRangeInformation = 42,
	FileIoPriorityHintInformation = 43,
	FileSfioReserveInformation = 44,
	FileSfioVolumeInformation = 45,
	FileHardLinkInformation = 46,
	FileProcessIdsUsingFileInformation = 47,
	FileNormalizedNameInformation = 48,
	FileNetworkPhysicalNameInformation = 49,
	FileIdGlobalTxDirectoryInformation = 50,
	FileIsRemoteDeviceInformation = 51,
	FileUnusedInformation = 52,
	FileNumaNodeInformation = 53,
	FileStandardLinkInformation = 54,
	FileRemoteProtocolInformation = 55,
	FileRenameInformationBypassAccessCheck = 56,
	FileLinkInformationBypassAccessCheck = 57,
	FileVolumeNameInformation = 58,
	FileIdInformation = 59,
	FileIdExtdDirectoryInformation = 60,
	FileReplaceCompletionInformation = 61,
	FileHardLinkFullIdInformation = 62,
	FileIdExtdBothDirectoryInformation = 63,
	FileDispositionInformationEx = 64,
	FileRenameInformationEx = 65,
	FileRenameInformationExBypassAccessCheck = 66,
	FileDesiredStorageClassInformation = 67,
	FileStatInformation = 68,
	FileMemoryPartitionInformation = 69,
	FileStatLxInformation = 70,
	FileCaseSensitiveInformation = 71,
	FileLinkInformationEx = 72,
	FileLinkInformationExBypassAccessCheck = 73,
	FileStorageReserveIdInformation = 74,
	FileCaseSensitiveInformationForceAccessCheck = 75,
	FileKnownFolderInformation = 76,
	FileStatBasicInformation = 77,
	FileId64ExtdDirectoryInformation = 78,
	FileId64ExtdBothDirectoryInformation = 79,
	FileIdAllExtdDirectoryInformation = 80,
	FileIdAllExtdBothDirectoryInformation = 81,
	FileStreamReservationInformation,
	FileMupProviderInfo,
	FileMaximumInformation
} FILE_INFORMATION_CLASS;

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class
typedef enum TOKEN_INFORMATION_CLASS
{
	TokenUser = 1,
	TokenGroups,
	TokenPrivileges,
	TokenOwner,
	TokenPrimaryGroup,
	TokenDefaultDacl,
	TokenSource,
	TokenType,
	TokenImpersonationLevel,
	TokenStatistics,
	TokenRestrictedSids,
	TokenSessionId,
	TokenGroupsAndPrivileges,
	TokenSessionReference,
	TokenSandBoxInert,
	TokenAuditPolicy,
	TokenOrigin,
	TokenElevationType,
	TokenLinkedToken,
	TokenElevation,
	TokenHasRestrictions,
	TokenAccessInformation,
	TokenVirtualizationAllowed,
	TokenVirtualizationEnabled,
	TokenIntegrityLevel,
	TokenUIAccess,
	TokenMandatoryPolicy,
	TokenLogonSid,
	TokenIsAppContainer,
	TokenCapabilities,
	TokenAppContainerSid,
	TokenAppContainerNumber,
	TokenUserClaimAttributes,
	TokenDeviceClaimAttributes,
	TokenRestrictedUserClaimAttributes,
	TokenRestrictedDeviceClaimAttributes,
	TokenDeviceGroups,
	TokenRestrictedDeviceGroups,
	TokenSecurityAttributes,
	TokenIsRestricted,
	TokenProcessTrustLevel,
	TokenPrivateNameSpace,
	TokenSingletonAttributes,
	TokenBnoIsolation,
	TokenChildProcessFlags,
	TokenIsLessPrivilegedAppContainer,
	TokenIsSandboxed,
	TokenIsAppSilo,
	TokenLoggingInformation,
	TokenLearningMode,
	MaxTokenInfoClass  // MaxTokenInfoClass should always be the last enum
} TOKEN_INFORMATION_CLASS;

// ░░░ Loader API ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t InitializeNtDll();
extern uint8_t *NtDllBaseAddress;

boolean_t LoadNtClose();
boolean_t LoadNtOpenFile();
boolean_t LoadNtReadFile();
boolean_t LoadNtWriteFile();

boolean_t LoadNtQueryObject();
boolean_t LoadNtSetInformationFile();
boolean_t LoadNtDeviceIoControlFile();
boolean_t LoadNtQueryInformationFile();

boolean_t LoadNtOpenProcessToken();
boolean_t LoadNtAdjustPrivilegesToken();
boolean_t LoadNtQueryInformationToken();

boolean_t LoadLdrLoadDll();
boolean_t LoadLdrUnloadDll();
boolean_t LoadNtDelayExecution();
boolean_t LoadNtTerminateProcess();
boolean_t LoadNtFreeVirtualMemory();
boolean_t LoadNtWaitForSingleObject();
boolean_t LoadNtAllocateVirtualMemory();

boolean_t LoadRtlTimeToTimeFields();

// ░░░ NtXxx Function Typedefs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose
typedef NtStatus(*NtClose_t)(Handle Handle);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose
typedef NtStatus(*NtQueryObject_t)(Handle Handle, OBJECT_INFORMATION_CLASS ObjectInformationClass, void *ObjectInformation, uint32_t ObjectInformationLength, uint32_t *ReturnLength);

// https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntdeviceiocontrolfile
typedef NtStatus(*NtDeviceIoControlFile_t)(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, uint32_t IoControlCode, void *InputBuffer, uint32_t InputBufferLength, void *OutputBuffer, uint32_t OutputBufferLength);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile
typedef NtStatus(*NtQueryInformationFile_t)(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile
typedef NtStatus(*NtSetInformationFile_t)(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass);

// https://learn.microsoft.com/de-de/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile
typedef NtStatus(*NtOpenFile_t)(Handle *fileHandle, uint32_t desiredAccess, OBJECT_ATTRIBUTES *objectAttributes, IO_STATUS_BLOCK *IoStatusBlock, uint32_t shareAccess, uint32_t openOptions);

// https://ntdoc.m417z.com/ldrloaddll
typedef NtStatus(*LdrLoadDll_t)(wchar_t const *DllPath, uint32_t *DllCharacteristics, UNICODE_STRING const *DllName, Handle DllHandle);

// https://ntdoc.m417z.com/ldrunloaddll
typedef NtStatus(*LdrUnloadDll_t)(Handle DllHandle);

// https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntwaitforsingleobject
typedef NtStatus(*NtWaitForSingleObject_t)(Handle Handle, boolean_t Alertable, uint64_t *Timeout);

// https://ntdoc.m417z.com/ntdelayexecution
typedef NtStatus(*NtDelayExecution_t)(boolean_t Alertable, uint64_t *DelayInterval);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimetotimefields
typedef void(*RtlTimeToTimeFields_t)(uint64_t const *const Time, TIME_FIELDS *TimeFields);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntwritefile
typedef NtStatus(*NtWriteFile_t)(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void const *const Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key);

// https://learn.microsoft.com/en-us/windows/win32/devnotes/ntreadfile
typedef NtStatus(*NtReadFile_t)(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, uint32_t Length, uint64_t ByteOffset, uint32_t *Key);

// https://ntdoc.m417z.com/ntterminateprocess
typedef NtStatus(*NtTerminateProcess_t)(Handle ProcessHandle, NtStatus ExitStatus);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationtoken
typedef NtStatus(*NtQueryInformationToken_t)(Handle TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, void *TokenInformation, uint32_t TokenInformationLength, uint32_t *ReturnLength);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenprocesstoken
typedef NtStatus(*NtOpenProcessToken_t)(Handle ProcessHandle, uint32_t DesiredAccess, Handle* TokenHandle);

// https://ntdoc.m417z.com/ntadjustprivilegestoken
typedef NtStatus(*NtAdjustPrivilegesToken_t)(Handle ProcessHandle, boolean_t DisableAllPrivileges, TOKEN_PRIVILEGES *NewState, uint32_t BufferLength, TOKEN_PRIVILEGES *PreviousState, uint32_t *ReturnLength);

// https://ntdoc.m417z.com/ldrgetprocedureaddressex
typedef NtStatus(*LdrGetProcedureAddressEx_t)(Handle DllHandle, STRING *ProcedureName, uint32_t ProcedureNumber, void *ProcedureAddress, uint32_t Flags);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntallocatevirtualmemory
typedef NtStatus(*NtAllocateVirtualMemory_t)(Handle ProcessHandle, void *BaseAddress, uint64_t ZeroBits, uint64_t *RegionSize, uint32_t AllocationType, uint32_t Protect);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntfreevirtualmemory
typedef NtStatus(*NtFreeVirtualMemory_t)(Handle ProcessHandle, void *BaseAddress, uint64_t *RegionSize, uint32_t FreeType);

// ░░░ Callable Grouped NtXxx Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct NtDllFunctions
{
	NtClose_t NtClose;
	NtOpenFile_t NtOpenFile;
	LdrLoadDll_t LdrLoadDll;
	NtReadFile_t NtReadFile;
	NtWriteFile_t NtWriteFile;
	LdrUnloadDll_t LdrUnloadDll;
	NtQueryObject_t NtQueryObject;
	NtDelayExecution_t NtDelayExecution;
	NtTerminateProcess_t NtTerminateProcess;
	NtOpenProcessToken_t NtOpenProcessToken;
	RtlTimeToTimeFields_t RtlTimeToTimeFields;
	NtFreeVirtualMemory_t NtFreeVirtualMemory;
	NtSetInformationFile_t NtSetInformationFile;
	NtDeviceIoControlFile_t NtDeviceIoControlFile;
	NtWaitForSingleObject_t NtWaitForSingleObject;
	NtQueryInformationFile_t NtQueryInformationFile;
	NtAdjustPrivilegesToken_t NtAdjustPrivilegesToken;
	NtAllocateVirtualMemory_t NtAllocateVirtualMemory;
	NtQueryInformationToken_t NtQueryInformationToken;
	LdrGetProcedureAddressEx_t LdrGetProcedureAddressEx;
};

extern struct NtDllFunctions NtDll;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline NtStatus NtClose(Handle Handle) { return NtDll.NtClose(Handle); }
static __forceinline NtStatus NtOpenFile(Handle *fileHandle, uint32_t desiredAccess, OBJECT_ATTRIBUTES *objectAttributes, IO_STATUS_BLOCK *IoStatusBlock, uint32_t shareAccess, uint32_t openOptions) { return NtDll.NtOpenFile(fileHandle, desiredAccess, objectAttributes, IoStatusBlock, shareAccess, openOptions); }
static __forceinline NtStatus NtReadFile(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, uint32_t Length, uint64_t ByteOffset, uint32_t *Key) { return NtDll.NtReadFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key); }
static __forceinline NtStatus NtWriteFile(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void const *const Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key) { return NtDll.NtWriteFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key); }

static __forceinline NtStatus NtQueryObject(Handle Handle, OBJECT_INFORMATION_CLASS ObjectInformationClass, void *ObjectInformation, uint32_t ObjectInformationLength, uint32_t *ReturnLength) { return NtDll.NtQueryObject(Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength, ReturnLength); }
static __forceinline NtStatus NtDeviceIoControlFile(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, uint32_t IoControlCode, void *InputBuffer, uint32_t InputBufferLength, void *OutputBuffer, uint32_t OutputBufferLength) { return NtDll.NtDeviceIoControlFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, IoControlCode, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength); }
static __forceinline NtStatus NtSetInformationFile(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass) { return NtDll.NtSetInformationFile(FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass); }
static __forceinline NtStatus NtQueryInformationFile(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass) { return NtDll.NtQueryInformationFile(FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass); }

static __forceinline NtStatus NtOpenProcessToken(Handle ProcessHandle, uint32_t DesiredAccess, Handle *TokenHandle) { return NtDll.NtOpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle); }
static __forceinline NtStatus NtAdjustPrivilegesToken(Handle ProcessHandle, boolean_t DisableAllPrivileges, TOKEN_PRIVILEGES* NewState, uint32_t BufferLength, TOKEN_PRIVILEGES* PreviousState, uint32_t* ReturnLength) { return NtDll.NtAdjustPrivilegesToken(ProcessHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength); }
static __forceinline NtStatus NtQueryInformationToken(Handle TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, void *TokenInformation, uint32_t TokenInformationLength, uint32_t *ReturnLength) { return NtDll.NtQueryInformationToken(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength); }

static __forceinline NtStatus LdrLoadDll(wchar_t const *DllPath, uint32_t *DllCharacteristics, UNICODE_STRING const *DllName, Handle DllHandle) { return NtDll.LdrLoadDll(DllPath, DllCharacteristics, DllName, DllHandle); }
static __forceinline NtStatus LdrUnloadDll(Handle DllHandle) { return NtDll.LdrUnloadDll(DllHandle); }
static __forceinline NtStatus NtDelayExecution(boolean_t Alertable, uint64_t *DelayInterval) { return NtDll.NtDelayExecution(Alertable, DelayInterval); }
static __forceinline NtStatus NtTerminateProcess(Handle ProcessHandle, NtStatus ExitStatus) { return NtDll.NtTerminateProcess(ProcessHandle, ExitStatus); }
static __forceinline NtStatus NtFreeVirtualMemory(Handle ProcessHandle, void *BaseAddress, uint64_t *RegionSize, uint32_t FreeType) { return NtDll.NtFreeVirtualMemory(ProcessHandle, BaseAddress, RegionSize, FreeType); }
static __forceinline NtStatus NtWaitForSingleObject(Handle Handle, boolean_t Alertable, uint64_t *Timeout) { return NtDll.NtWaitForSingleObject(Handle, Alertable, Timeout); }
static __forceinline NtStatus NtAllocateVirtualMemory(Handle ProcessHandle, void *BaseAddress, uint64_t ZeroBits, uint64_t *RegionSize, uint32_t AllocationType, uint32_t Protect) { return NtDll.NtAllocateVirtualMemory(ProcessHandle, BaseAddress, ZeroBits, RegionSize, AllocationType, Protect); }
static __forceinline NtStatus LdrGetProcedureAddressEx(Handle DllHandle, STRING *ProcedureName, uint32_t ProcedureNumber, void *ProcedureAddress, uint32_t Flags) { return NtDll.LdrGetProcedureAddressEx(DllHandle, ProcedureName, ProcedureNumber, ProcedureAddress, Flags); }

static __forceinline void RtlTimeToTimeFields(uint64_t const *const Time, TIME_FIELDS *TimeFields) { NtDll.RtlTimeToTimeFields(Time, TimeFields); }