#pragma once
#include "types.h"

// ░░░ Definitions uses by NtXxx Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// ################# winnt.h #################

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

// ################# wdm.h #################

#define FILE_DIRECTORY_FILE                     0x00000001
#define FILE_WRITE_THROUGH                      0x00000002
#define FILE_SEQUENTIAL_ONLY                    0x00000004
#define FILE_NO_INTERMEDIATE_BUFFERING          0x00000008

#define FILE_SYNCHRONOUS_IO_ALERT               0x00000010
#define FILE_SYNCHRONOUS_IO_NONALERT            0x00000020
#define FILE_NON_DIRECTORY_FILE                 0x00000040
#define FILE_CREATE_TREE_CONNECTION             0x00000080

#define FILE_COMPLETE_IF_OPLOCKED               0x00000100
#define FILE_NO_EA_KNOWLEDGE                    0x00000200
#define FILE_OPEN_REMOTE_INSTANCE               0x00000400
#define FILE_RANDOM_ACCESS                      0x00000800

#define FILE_DELETE_ON_CLOSE                    0x00001000
#define FILE_OPEN_BY_FILE_ID                    0x00002000
#define FILE_OPEN_FOR_BACKUP_INTENT             0x00004000
#define FILE_NO_COMPRESSION                     0x00008000

#define THREAD_TERMINATE                 (0x0001)  
#define THREAD_SUSPEND_RESUME            (0x0002)  
#define THREAD_ALERT                     (0x0004)
#define THREAD_GET_CONTEXT               (0x0008)  
#define THREAD_SET_CONTEXT               (0x0010)  
#define THREAD_SET_INFORMATION           (0x0020)  
#define THREAD_SET_LIMITED_INFORMATION   (0x0400)  
#define THREAD_QUERY_LIMITED_INFORMATION (0x0800)  
#define THREAD_RESUME                    (0x1000)

#define THREAD_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFFF)

#define THREAD_CREATE_FLAGS_CREATE_SUSPENDED 0x00000001
#define THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH 0x00000002
#define THREAD_CREATE_FLAGS_HIDE_FROM_DEBUGGER 0x00000004
#define THREAD_CREATE_FLAGS_LOADER_WORKER 0x00000010
#define THREAD_CREATE_FLAGS_SKIP_LOADER_INIT 0x00000020
#define THREAD_CREATE_FLAGS_BYPASS_PROCESS_FREEZE 0x00000040

// ################# ntstatus.h #################

#define STATUS_SUCCESS                   0x00000000L
#define STATUS_UNSUCCESSFUL              0xC0000001L
#define STATUS_INVALID_HANDLE            0xC0000008L
#define STATUS_ACCESS_DENIED             0xC0000022L
#define STATUS_BUFFER_TOO_SMALL          0xC0000023L
#define STATUS_INVALID_PARAMETER         0xC000000DL
#define STATUS_PENDING                   0x00000103L
#define STATUS_REPARSE                   0x00000104L
#define STATUS_TIMEOUT                   0x00000102L
#define STATUS_MORE_ENTRIES              0x00000105L
#define STATUS_ACCESS_VIOLATION          0xC0000005L
#define STATUS_ALERTED                   0x00000101L
#define STATUS_ALREADY_COMPLETE          0x000000FFL
#define STATUS_KERNEL_APC                0x00000100L
#define STATUS_USER_APC                  0x000000C0L

// ################# ntdef.h #################

#define OBJ_INHERIT                         0x00000002L
#define OBJ_PERMANENT                       0x00000010L
#define OBJ_EXCLUSIVE                       0x00000020L
#define OBJ_CASE_INSENSITIVE                0x00000040L
#define OBJ_OPENIF                          0x00000080L
#define OBJ_OPENLINK                        0x00000100L
#define OBJ_KERNEL_HANDLE                   0x00000200L
#define OBJ_FORCE_ACCESS_CHECK              0x00000400L
#define OBJ_IGNORE_IMPERSONATED_DEVICEMAP   0x00000800L
#define OBJ_DONT_REPARSE                    0x00001000L
#define OBJ_VALID_ATTRIBUTES                0x00001FF2L

// ################# winnt.h #################

#define CONTEXT_AMD64   0x00100000L

#define CONTEXT_CONTROL         (CONTEXT_AMD64 | 0x00000001L)
#define CONTEXT_INTEGER         (CONTEXT_AMD64 | 0x00000002L)
#define CONTEXT_SEGMENTS        (CONTEXT_AMD64 | 0x00000004L)
#define CONTEXT_FLOATING_POINT  (CONTEXT_AMD64 | 0x00000008L)
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x00000010L)

#define CONTEXT_FULL            (CONTEXT_CONTROL | CONTEXT_INTEGER | \
                                 CONTEXT_FLOATING_POINT)

#define CONTEXT_ALL             (CONTEXT_CONTROL | CONTEXT_INTEGER | \
                                 CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | \
                                 CONTEXT_DEBUG_REGISTERS)

#define CONTEXT_XSTATE          (CONTEXT_AMD64 | 0x00000040L)
#define CONTEXT_KERNEL_CET      (CONTEXT_AMD64 | 0x00000080L)

#define FILE_READ_DATA            ( 0x0001 )    // file & pipe
#define FILE_LIST_DIRECTORY       ( 0x0001 )    // directory

#define FILE_WRITE_DATA           ( 0x0002 )    // file & pipe
#define FILE_ADD_FILE             ( 0x0002 )    // directory

#define FILE_APPEND_DATA          ( 0x0004 )    // file
#define FILE_ADD_SUBDIRECTORY     ( 0x0004 )    // directory
#define FILE_CREATE_PIPE_INSTANCE ( 0x0004 )    // named pipe


#define FILE_READ_EA              ( 0x0008 )    // file & directory

#define FILE_WRITE_EA             ( 0x0010 )    // file & directory

#define FILE_EXECUTE              ( 0x0020 )    // file
#define FILE_TRAVERSE             ( 0x0020 )    // directory

#define FILE_DELETE_CHILD         ( 0x0040 )    // directory

#define FILE_READ_ATTRIBUTES      ( 0x0080 )    // all

#define FILE_WRITE_ATTRIBUTES     ( 0x0100 )    // all

#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)

#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)


#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)


#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)

#define FILE_SHARE_READ                 0x00000001  
#define FILE_SHARE_WRITE                0x00000002  
#define FILE_SHARE_DELETE               0x00000004  
#define FILE_ATTRIBUTE_READONLY             0x00000001  
#define FILE_ATTRIBUTE_HIDDEN               0x00000002  
#define FILE_ATTRIBUTE_SYSTEM               0x00000004  
#define FILE_ATTRIBUTE_DIRECTORY            0x00000010  
#define FILE_ATTRIBUTE_ARCHIVE              0x00000020  
#define FILE_ATTRIBUTE_DEVICE               0x00000040  
#define FILE_ATTRIBUTE_NORMAL               0x00000080  
#define FILE_ATTRIBUTE_TEMPORARY            0x00000100  
#define FILE_ATTRIBUTE_SPARSE_FILE          0x00000200  
#define FILE_ATTRIBUTE_REPARSE_POINT        0x00000400  
#define FILE_ATTRIBUTE_COMPRESSED           0x00000800  
#define FILE_ATTRIBUTE_OFFLINE              0x00001000  
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000  
#define FILE_ATTRIBUTE_ENCRYPTED            0x00004000  
#define FILE_ATTRIBUTE_INTEGRITY_STREAM     0x00008000  
#define FILE_ATTRIBUTE_VIRTUAL              0x00010000  
#define FILE_ATTRIBUTE_NO_SCRUB_DATA        0x00020000  
#define FILE_ATTRIBUTE_EA                   0x00040000  
#define FILE_ATTRIBUTE_PINNED               0x00080000  
#define FILE_ATTRIBUTE_UNPINNED             0x00100000  
#define FILE_ATTRIBUTE_RECALL_ON_OPEN       0x00040000  
#define FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS 0x00400000 
#define TREE_CONNECT_ATTRIBUTE_PRIVACY      0x00004000  
#define TREE_CONNECT_ATTRIBUTE_INTEGRITY    0x00008000  
#define TREE_CONNECT_ATTRIBUTE_GLOBAL       0x00000004  
#define TREE_CONNECT_ATTRIBUTE_PINNED       0x00000002  
#define FILE_ATTRIBUTE_STRICTLY_SEQUENTIAL  0x20000000  
#define FILE_NOTIFY_CHANGE_FILE_NAME    0x00000001   
#define FILE_NOTIFY_CHANGE_DIR_NAME     0x00000002   
#define FILE_NOTIFY_CHANGE_ATTRIBUTES   0x00000004   
#define FILE_NOTIFY_CHANGE_SIZE         0x00000008   
#define FILE_NOTIFY_CHANGE_LAST_WRITE   0x00000010   
#define FILE_NOTIFY_CHANGE_LAST_ACCESS  0x00000020   
#define FILE_NOTIFY_CHANGE_CREATION     0x00000040   
#define FILE_NOTIFY_CHANGE_SECURITY     0x00000100   
#define FILE_ACTION_ADDED                   0x00000001   
#define FILE_ACTION_REMOVED                 0x00000002   
#define FILE_ACTION_MODIFIED                0x00000003   
#define FILE_ACTION_RENAMED_OLD_NAME        0x00000004   
#define FILE_ACTION_RENAMED_NEW_NAME        0x00000005   
#define MAILSLOT_NO_MESSAGE             ((uint32_t)-1) 
#define MAILSLOT_WAIT_FOREVER           ((uint32_t)-1) 
#define FILE_CASE_SENSITIVE_SEARCH          0x00000001  
#define FILE_CASE_PRESERVED_NAMES           0x00000002  
#define FILE_UNICODE_ON_DISK                0x00000004  
#define FILE_PERSISTENT_ACLS                0x00000008  
#define FILE_FILE_COMPRESSION               0x00000010  
#define FILE_VOLUME_QUOTAS                  0x00000020  
#define FILE_SUPPORTS_SPARSE_FILES          0x00000040  
#define FILE_SUPPORTS_REPARSE_POINTS        0x00000080  
#define FILE_SUPPORTS_REMOTE_STORAGE        0x00000100  
#define FILE_RETURNS_CLEANUP_RESULT_INFO    0x00000200  
#define FILE_SUPPORTS_POSIX_UNLINK_RENAME   0x00000400  
#define FILE_SUPPORTS_BYPASS_IO             0x00000800  
#define FILE_SUPPORTS_STREAM_SNAPSHOTS      0x00001000  
#define FILE_SUPPORTS_CASE_SENSITIVE_DIRS   0x00002000  

#define FILE_VOLUME_IS_COMPRESSED           0x00008000  
#define FILE_SUPPORTS_OBJECT_IDS            0x00010000  
#define FILE_SUPPORTS_ENCRYPTION            0x00020000  
#define FILE_NAMED_STREAMS                  0x00040000  
#define FILE_READ_ONLY_VOLUME               0x00080000  
#define FILE_SEQUENTIAL_WRITE_ONCE          0x00100000  
#define FILE_SUPPORTS_TRANSACTIONS          0x00200000  
#define FILE_SUPPORTS_HARD_LINKS            0x00400000  
#define FILE_SUPPORTS_EXTENDED_ATTRIBUTES   0x00800000  
#define FILE_SUPPORTS_OPEN_BY_FILE_ID       0x01000000  
#define FILE_SUPPORTS_USN_JOURNAL           0x02000000  
#define FILE_SUPPORTS_INTEGRITY_STREAMS     0x04000000  
#define FILE_SUPPORTS_BLOCK_REFCOUNTING     0x08000000  
#define FILE_SUPPORTS_SPARSE_VDL            0x10000000  
#define FILE_DAX_VOLUME                     0x20000000  
#define FILE_SUPPORTS_GHOSTING              0x40000000

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

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_standard_information
typedef struct FILE_STANDARD_INFORMATION
{
	uint64_t AllocationSize;
	uint64_t EndOfFile;
	uint32_t NumberOfLinks;
	boolean_t DeletePending;
	boolean_t Directory;
} FILE_STANDARD_INFORMATION;

// https://ntdoc.m417z.com/ps_attribute
typedef struct PS_ATTRIBUTE
{
	uint64_t Attribute;
	uint64_t Size;
	union
	{
		uint64_t Value;
		void *ValuePtr;
	};
	uint64_t *ReturnLength;
} PS_ATTRIBUTE;

// https://ntdoc.m417z.com/ps_attribute_list
typedef struct _PS_ATTRIBUTE_LIST
{
	uint64_t TotalLength;
	PS_ATTRIBUTE Attributes[1];
} PS_ATTRIBUTE_LIST;

__declspec(align(16)) typedef struct M128A
{
	uint64_t Low;
	uint64_t High;
} M128A;

__declspec(align(16)) typedef struct XSAVE_FORMAT
{
	uint16_t ControlWord;
	uint16_t StatusWord;
	uint8_t TagWord;
	uint8_t Reserved1;
	uint16_t ErrorOpcode;
	uint32_t ErrorOffset;
	uint16_t ErrorSelector;
	uint16_t Reserved2;
	uint32_t DataOffset;
	uint16_t DataSelector;
	uint16_t Reserved3;
	uint32_t MxCsr;
	uint32_t MxCsr_Mask;
	M128A FloatRegisters[8];
	M128A XmmRegisters[16];
	uint8_t Reserved4[96];
} XSAVE_FORMAT;

// from windows.h
// https://learn.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-context
__declspec(align(16)) typedef struct CONTEXT
{
	// Register parameter home addresses.
	//
	// N.B. These fields are for convience - they could be used to extend the
	//      context record in the future.
	uint64_t P1Home;
	uint64_t P2Home;
	uint64_t P3Home;
	uint64_t P4Home;
	uint64_t P5Home;
	uint64_t P6Home;

	// Control flags.
	uint32_t ContextFlags;
	uint32_t MxCsr;

	// Segment Registers and processor flags.
	uint16_t   SegCs;
	uint16_t   SegDs;
	uint16_t   SegEs;
	uint16_t   SegFs;
	uint16_t   SegGs;
	uint16_t   SegSs;
	uint32_t EFlags;

	// Debug registers
	uint64_t Dr0;
	uint64_t Dr1;
	uint64_t Dr2;
	uint64_t Dr3;
	uint64_t Dr6;
	uint64_t Dr7;

	// Integer registers.
	uint64_t Rax;
	uint64_t Rcx;
	uint64_t Rdx;
	uint64_t Rbx;
	uint64_t Rsp;
	uint64_t Rbp;
	uint64_t Rsi;
	uint64_t Rdi;
	uint64_t R8;
	uint64_t R9;
	uint64_t R10;
	uint64_t R11;
	uint64_t R12;
	uint64_t R13;
	uint64_t R14;
	uint64_t R15;

	// Program counter.
	uint64_t Rip;

	// Floating point state.
	union
	{
		XSAVE_FORMAT FltSave;
		struct
		{
			M128A Header[2];
			M128A Legacy[8];
			M128A Xmm0;
			M128A Xmm1;
			M128A Xmm2;
			M128A Xmm3;
			M128A Xmm4;
			M128A Xmm5;
			M128A Xmm6;
			M128A Xmm7;
			M128A Xmm8;
			M128A Xmm9;
			M128A Xmm10;
			M128A Xmm11;
			M128A Xmm12;
			M128A Xmm13;
			M128A Xmm14;
			M128A Xmm15;
		} DUMMYSTRUCTNAME;
	} DUMMYUNIONNAME;

	// Vector registers.
	M128A VectorRegister[26];
	uint64_t VectorControl;

	// Special debug control registers.
	uint64_t DebugControl;
	uint64_t LastBranchToRip;
	uint64_t LastBranchFromRip;
	uint64_t LastExceptionToRip;
	uint64_t LastExceptionFromRip;
} CONTEXT;

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

boolean_t LoadNtAlertThread();
boolean_t LoadNtResumeThread();
boolean_t LoadNtSuspendThread();
boolean_t LoadNtCreateThreadEx();
boolean_t LoadNtTerminateThread();
boolean_t LoadNtYieldExecution();
boolean_t LoadNtGetContextThread();
boolean_t LoadNtSetContextThread();
boolean_t LoadNtAlertResumeThread();

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

// https://ntdoc.m417z.com/ntcreatethreadex
typedef NtStatus(*NtCreateThreadEx_t)(Handle *ThreadHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, Handle *ProcessHandle, NtStatus(*StartRoutine)(void *), void *Argument, uint32_t CreateFlags, uint64_t ZeroSize, uint64_t StackSize, uint64_t MaximumStackSize, PS_ATTRIBUTE_LIST *AttributeList);

// https://ntdoc.m417z.com/ntresumethread
typedef NtStatus(*NtResumeThread_t)(Handle *ThreadHandle, uint32_t *PreviousSuspendCount);

// https://ntdoc.m417z.com/ntalertresumethread
typedef NtStatus(*NtAlertResumeThread_t)(Handle *ThreadHandle, uint32_t *PreviousSuspendCount);

// https://ntdoc.m417z.com/ntsetcontextthread
typedef NtStatus(*NtSetContextThread_t)(Handle *ThreadHandle, CONTEXT *ThreadContext);

// https://ntdoc.m417z.com/ntgetcontextthread
typedef NtStatus(*NtGetContextThread_t)(Handle *ThreadHandle, CONTEXT *ThreadContext);

// https://ntdoc.m417z.com/ntsuspendthread
typedef NtStatus(*NtSuspendThread_t)(Handle *ThreadHandle, uint32_t *PreviousSuspendCount);

// https://ntdoc.m417z.com/ntalertthread
typedef NtStatus(*NtAlertThread_t)(Handle *ThreadHandle);

// https://ntdoc.m417z.com/ntyieldexecution
typedef NtStatus(*NtYieldExecution_t)();

// https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntwaitforsingleobject
typedef NtStatus(*NtWaitForSingleObject_t)(Handle Handle, boolean_t Alertable, uint64_t *Timeout);

// https://ntdoc.m417z.com/ntdelayexecution
typedef NtStatus(*NtDelayExecution_t)(boolean_t Alertable, int64_t *DelayInterval);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimetotimefields
typedef void(*RtlTimeToTimeFields_t)(uint64_t const *const Time, TIME_FIELDS *TimeFields);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntwritefile
typedef NtStatus(*NtWriteFile_t)(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void const *const Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key);

// https://learn.microsoft.com/en-us/windows/win32/devnotes/ntreadfile
typedef NtStatus(*NtReadFile_t)(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key);

// https://ntdoc.m417z.com/ntterminateprocess
typedef NtStatus(*NtTerminateProcess_t)(Handle ProcessHandle, NtStatus ExitStatus);

// https://ntdoc.m417z.com/ntterminatethread
typedef NtStatus(*NtTerminateThread_t)(Handle ThreadHandle, NtStatus ExitStatus);

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
	NtAlertThread_t NtAlertThread;
	NtQueryObject_t NtQueryObject;
	NtResumeThread_t NtResumeThread;
	NtSuspendThread_t NtSuspendThread;
	NtYieldExecution_t NtYieldExecution;
	NtCreateThreadEx_t NtCreateThreadEx;
	NtDelayExecution_t NtDelayExecution;
	NtTerminateThread_t NtTerminateThread;
	NtGetContextThread_t NtGetContextThread;
	NtSetContextThread_t NtSetContextThread;
	NtTerminateProcess_t NtTerminateProcess;
	NtOpenProcessToken_t NtOpenProcessToken;
	NtAlertResumeThread_t NtAlertResumeThread;
	NtFreeVirtualMemory_t NtFreeVirtualMemory;
	RtlTimeToTimeFields_t RtlTimeToTimeFields;
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
extern uint64_t NtTerminateThreadFunctionPointer;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline NtStatus NtClose(Handle Handle) { return NtDll.NtClose(Handle); }
static __forceinline NtStatus NtOpenFile(Handle *fileHandle, uint32_t desiredAccess, OBJECT_ATTRIBUTES *objectAttributes, IO_STATUS_BLOCK *IoStatusBlock, uint32_t shareAccess, uint32_t openOptions) { return NtDll.NtOpenFile(fileHandle, desiredAccess, objectAttributes, IoStatusBlock, shareAccess, openOptions); }
static __forceinline NtStatus NtReadFile(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key) { return NtDll.NtReadFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key); }
static __forceinline NtStatus NtWriteFile(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void const *const Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key) { return NtDll.NtWriteFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key); }

static __forceinline NtStatus NtQueryObject(Handle Handle, OBJECT_INFORMATION_CLASS ObjectInformationClass, void *ObjectInformation, uint32_t ObjectInformationLength, uint32_t *ReturnLength) { return NtDll.NtQueryObject(Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength, ReturnLength); }
static __forceinline NtStatus NtDeviceIoControlFile(Handle FileHandle, Handle Event, void *ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, uint32_t IoControlCode, void *InputBuffer, uint32_t InputBufferLength, void *OutputBuffer, uint32_t OutputBufferLength) { return NtDll.NtDeviceIoControlFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, IoControlCode, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength); }
static __forceinline NtStatus NtSetInformationFile(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass) { return NtDll.NtSetInformationFile(FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass); }
static __forceinline NtStatus NtQueryInformationFile(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass) { return NtDll.NtQueryInformationFile(FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass); }

static __forceinline NtStatus NtOpenProcessToken(Handle ProcessHandle, uint32_t DesiredAccess, Handle *TokenHandle) { return NtDll.NtOpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle); }
static __forceinline NtStatus NtAdjustPrivilegesToken(Handle ProcessHandle, boolean_t DisableAllPrivileges, TOKEN_PRIVILEGES* NewState, uint32_t BufferLength, TOKEN_PRIVILEGES* PreviousState, uint32_t* ReturnLength) { return NtDll.NtAdjustPrivilegesToken(ProcessHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength); }
static __forceinline NtStatus NtQueryInformationToken(Handle TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, void *TokenInformation, uint32_t TokenInformationLength, uint32_t *ReturnLength) { return NtDll.NtQueryInformationToken(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength); }

static __forceinline NtStatus NtAlertThread(Handle *ThreadHandle) { return NtDll.NtAlertThread(ThreadHandle); }
static __forceinline NtStatus NtResumeThread(Handle *ThreadHandle, uint32_t *PreviousSuspendCount) { return NtDll.NtResumeThread(ThreadHandle, PreviousSuspendCount); }
static __forceinline NtStatus NtSuspendThread(Handle *ThreadHandle, uint32_t *PreviousSuspendCount) { return NtDll.NtSuspendThread(ThreadHandle, PreviousSuspendCount); }
static __forceinline NtStatus NtYieldExecution() { return NtDll.NtYieldExecution(); }
static __forceinline NtStatus NtCreateThreadEx(Handle *ThreadHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, Handle *ProcessHandle, NtStatus(*StartRoutine)(void *), void *Argument, uint32_t CreateFlags, uint64_t ZeroSize, uint64_t StackSize, uint64_t MaximumStackSize, PS_ATTRIBUTE_LIST *AttributeList) { return NtDll.NtCreateThreadEx(ThreadHandle, DesiredAccess, ObjectAttributes, ProcessHandle, StartRoutine, Argument, CreateFlags, ZeroSize, StackSize, MaximumStackSize, AttributeList); }
static __forceinline NtStatus NtTerminateThread(Handle ThreadHandle, NtStatus ExitStatus) { return NtDll.NtTerminateThread(ThreadHandle, ExitStatus); }
static __forceinline NtStatus NtGetContextThread(Handle *ThreadHandle, CONTEXT *ThreadContext) { return NtDll.NtGetContextThread(ThreadHandle, ThreadContext); }
static __forceinline NtStatus NtSetContextThread(Handle *ThreadHandle, CONTEXT *ThreadContext) { return NtDll.NtSetContextThread(ThreadHandle, ThreadContext); }
static __forceinline NtStatus NtAlertResumeThread(Handle *ThreadHandle, uint32_t *PreviousSuspendCount) { return NtDll.NtAlertResumeThread(ThreadHandle, PreviousSuspendCount); }

static __forceinline NtStatus LdrLoadDll(wchar_t const *DllPath, uint32_t *DllCharacteristics, UNICODE_STRING const *DllName, Handle DllHandle) { return NtDll.LdrLoadDll(DllPath, DllCharacteristics, DllName, DllHandle); }
static __forceinline NtStatus LdrUnloadDll(Handle DllHandle) { return NtDll.LdrUnloadDll(DllHandle); }
static __forceinline NtStatus NtDelayExecution(boolean_t Alertable, int64_t *DelayInterval) { return NtDll.NtDelayExecution(Alertable, DelayInterval); }
static __forceinline NtStatus NtTerminateProcess(Handle ProcessHandle, NtStatus ExitStatus) { return NtDll.NtTerminateProcess(ProcessHandle, ExitStatus); }
static __forceinline NtStatus NtFreeVirtualMemory(Handle ProcessHandle, void *BaseAddress, uint64_t *RegionSize, uint32_t FreeType) { return NtDll.NtFreeVirtualMemory(ProcessHandle, BaseAddress, RegionSize, FreeType); }
static __forceinline NtStatus NtWaitForSingleObject(Handle Handle, boolean_t Alertable, uint64_t *Timeout) { return NtDll.NtWaitForSingleObject(Handle, Alertable, Timeout); }
static __forceinline NtStatus NtAllocateVirtualMemory(Handle ProcessHandle, void *BaseAddress, uint64_t ZeroBits, uint64_t *RegionSize, uint32_t AllocationType, uint32_t Protect) { return NtDll.NtAllocateVirtualMemory(ProcessHandle, BaseAddress, ZeroBits, RegionSize, AllocationType, Protect); }
static __forceinline NtStatus LdrGetProcedureAddressEx(Handle DllHandle, STRING *ProcedureName, uint32_t ProcedureNumber, void *ProcedureAddress, uint32_t Flags) { return NtDll.LdrGetProcedureAddressEx(DllHandle, ProcedureName, ProcedureNumber, ProcedureAddress, Flags); }

static __forceinline void RtlTimeToTimeFields(uint64_t const *const Time, TIME_FIELDS *TimeFields) { NtDll.RtlTimeToTimeFields(Time, TimeFields); }