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

//
// Define the create disposition values
//

#define FILE_SUPERSEDE                  0x00000000
#define FILE_OPEN                       0x00000001
#define FILE_CREATE                     0x00000002
#define FILE_OPEN_IF                    0x00000003
#define FILE_OVERWRITE                  0x00000004
#define FILE_OVERWRITE_IF               0x00000005
#define FILE_MAXIMUM_DISPOSITION        0x00000005

//
// Define the create/open option flags
//

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

#define STATUS_SUCCESS                    0x00000000L
#define STATUS_UNSUCCESSFUL               0xC0000001L
#define STATUS_INVALID_HANDLE             0xC0000008L
#define STATUS_ACCESS_DENIED              0xC0000022L
#define STATUS_BUFFER_TOO_SMALL           0xC0000023L
#define STATUS_INVALID_PARAMETER          0xC000000DL
#define STATUS_PENDING                    0x00000103L
#define STATUS_REPARSE                    0x00000104L
#define STATUS_TIMEOUT                    0x00000102L
#define STATUS_MORE_ENTRIES               0x00000105L
#define STATUS_ACCESS_VIOLATION           0xC0000005L
#define STATUS_ALERTED                    0x00000101L
#define STATUS_ALREADY_COMPLETE           0x000000FFL
#define STATUS_KERNEL_APC                 0x00000100L
#define STATUS_USER_APC                   0x000000C0L
#define STATUS_WAIT_0                     0x00000000L 
#define STATUS_ABANDONED_WAIT_0           0x00000080L    
#define STATUS_SEGMENT_NOTIFICATION       0x40000005L    
#define STATUS_FATAL_APP_EXIT             0x40000015L
#define STATUS_GUARD_PAGE_VIOLATION       0x80000001L    
#define STATUS_DATATYPE_MISALIGNMENT      0x80000002L    
#define STATUS_BREAKPOINT                 0x80000003L    
#define STATUS_SINGLE_STEP                0x80000004L    
#define STATUS_LONGJUMP                   0x80000026L    
#define STATUS_UNWIND_CONSOLIDATE         0x80000029L    
#define STATUS_IN_PAGE_ERROR              0xC0000006L    
#define STATUS_NO_MEMORY                  0xC0000017L    
#define STATUS_ILLEGAL_INSTRUCTION        0xC000001DL    
#define STATUS_NONCONTINUABLE_EXCEPTION   0xC0000025L    
#define STATUS_INVALID_DISPOSITION        0xC0000026L    
#define STATUS_ARRAY_BOUNDS_EXCEEDED      0xC000008CL    
#define STATUS_FLOAT_DENORMAL_OPERAND     0xC000008DL    
#define STATUS_FLOAT_DIVIDE_BY_ZERO       0xC000008EL    
#define STATUS_FLOAT_INEXACT_RESULT       0xC000008FL    
#define STATUS_FLOAT_INVALID_OPERATION    0xC0000090L    
#define STATUS_FLOAT_OVERFLOW             0xC0000091L    
#define STATUS_FLOAT_STACK_CHECK          0xC0000092L    
#define STATUS_FLOAT_UNDERFLOW            0xC0000093L    
#define STATUS_INTEGER_DIVIDE_BY_ZERO     0xC0000094L    
#define STATUS_INTEGER_OVERFLOW           0xC0000095L    
#define STATUS_PRIVILEGED_INSTRUCTION     0xC0000096L    
#define STATUS_STACK_OVERFLOW             0xC00000FDL    
#define STATUS_DLL_NOT_FOUND              0xC0000135L    
#define STATUS_ORDINAL_NOT_FOUND          0xC0000138L    
#define STATUS_ENTRYPOINT_NOT_FOUND       0xC0000139L    
#define STATUS_CONTROL_C_EXIT             0xC000013AL    
#define STATUS_DLL_INIT_FAILED            0xC0000142L    
#define STATUS_CONTROL_STACK_VIOLATION    0xC00001B2L    
#define STATUS_FLOAT_MULTIPLE_FAULTS      0xC00002B4L    
#define STATUS_FLOAT_MULTIPLE_TRAPS       0xC00002B5L    
#define STATUS_REG_NAT_CONSUMPTION        0xC00002C9L    
#define STATUS_HEAP_CORRUPTION            0xC0000374L    
#define STATUS_STACK_BUFFER_OVERRUN       0xC0000409L    
#define STATUS_INVALID_CRUNTIME_PARAMETER 0xC0000417L    
#define STATUS_ASSERTION_FAILURE          0xC0000420L    
#define STATUS_ENCLAVE_VIOLATION          0xC00004A2L    
#define STATUS_INTERRUPTED                0xC0000515L    
#define STATUS_THREAD_NOT_RUNNING         0xC0000516L    
#define STATUS_ALREADY_REGISTERED         0xC0000718L   

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

#define PAGE_NOACCESS			0x01
#define PAGE_READONLY			0x02
#define PAGE_READWRITE			0x04
#define PAGE_WRITECOPY			0x08
#define PAGE_EXECUTE			0x10
#define PAGE_EXECUTE_READ		0x20
#define PAGE_EXECUTE_READWRITE	0x40
#define PAGE_EXECUTE_WRITECOPY	0x80
#define PAGE_GUARD			   0x100
#define PAGE_NOCACHE		   0x200
#define PAGE_WRITECOMBINE	   0x400  

#define PAGE_GRAPHICS_NOACCESS			 0x0800
#define PAGE_GRAPHICS_READONLY			 0x1000
#define PAGE_GRAPHICS_READWRITE			 0x2000
#define PAGE_GRAPHICS_EXECUTE			 0x4000
#define PAGE_GRAPHICS_EXECUTE_READ		 0x8000
#define PAGE_GRAPHICS_EXECUTE_READWRITE 0x10000
#define PAGE_GRAPHICS_COHERENT			0x20000
#define PAGE_GRAPHICS_NOCACHE			0x40000
#define PAGE_ENCLAVE_THREAD_CONTROL 0x80000000
#define PAGE_REVERT_TO_FILE_MAP		0x80000000
#define PAGE_TARGETS_NO_UPDATE		0x40000000
#define PAGE_TARGETS_INVALID		0x40000000
#define PAGE_ENCLAVE_UNVALIDATED	0x20000000
#define PAGE_ENCLAVE_NO_CHANGE		0x20000000
#define PAGE_ENCLAVE_MASK			0x10000000
#define PAGE_ENCLAVE_DECOMMIT		(PAGE_ENCLAVE_MASK | 0)
#define PAGE_ENCLAVE_SS_FIRST		(PAGE_ENCLAVE_MASK | 1)
#define PAGE_ENCLAVE_SS_REST		(PAGE_ENCLAVE_MASK | 2)

#define MEM_COMMIT                      0x00001000  
#define MEM_RESERVE                     0x00002000
#define MEM_RESET                       0x00080000  
#define MEM_TOP_DOWN                    0x00100000  
#define MEM_WRITE_WATCH                 0x00200000  
#define MEM_PHYSICAL                    0x00400000  
#define MEM_RESET_UNDO                  0x01000000  

#define MEM_LARGE_PAGES                 0x20000000 

#define MEM_4MB_PAGES					0x80000000
#define MEM_64K_PAGES					(MEM_LARGE_PAGES | MEM_PHYSICAL)
#define MEM_DECOMMIT					0x00004000
#define MEM_RELEASE						0x00008000
#define MEM_FREE						0x00010000

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

#define UNWIND_HISTORY_TABLE_SIZE 12

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

// Defined values for the exception filter expression
#define EXCEPTION_EXECUTE_HANDLER      1
#define EXCEPTION_CONTINUE_SEARCH      0
#define EXCEPTION_CONTINUE_EXECUTION (-1)

#define EXCEPTION_MAXIMUM_PARAMETERS 15 // maximum number of exception parameters

/*lint -save -e767 */  
#define DBG_EXCEPTION_HANDLED            ((uint32_t)0x00010001L)    
#define DBG_CONTINUE                     ((uint32_t)0x00010002L)    
#define DBG_REPLY_LATER                  ((uint32_t)0x40010001L)    
#define DBG_TERMINATE_THREAD             ((uint32_t)0x40010003L)    
#define DBG_TERMINATE_PROCESS            ((uint32_t)0x40010004L)    
#define DBG_CONTROL_C                    ((uint32_t)0x40010005L)    
#define DBG_PRINTEXCEPTION_C             ((uint32_t)0x40010006L)    
#define DBG_RIPEXCEPTION                 ((uint32_t)0x40010007L)    
#define DBG_CONTROL_BREAK                ((uint32_t)0x40010008L)    
#define DBG_COMMAND_EXCEPTION            ((uint32_t)0x40010009L)    
#define DBG_PRINTEXCEPTION_WIDE_C        ((uint32_t)0x4001000AL)    
#define DBG_EXCEPTION_NOT_HANDLED        ((uint32_t)0x80010001L)    

/* compatibility macros */
#define STILL_ACTIVE                        STATUS_PENDING
#define EXCEPTION_ACCESS_VIOLATION          STATUS_ACCESS_VIOLATION
#define EXCEPTION_DATATYPE_MISALIGNMENT     STATUS_DATATYPE_MISALIGNMENT
#define EXCEPTION_BREAKPOINT                STATUS_BREAKPOINT
#define EXCEPTION_SINGLE_STEP               STATUS_SINGLE_STEP
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED     STATUS_ARRAY_BOUNDS_EXCEEDED
#define EXCEPTION_FLT_DENORMAL_OPERAND      STATUS_FLOAT_DENORMAL_OPERAND
#define EXCEPTION_FLT_DIVIDE_BY_ZERO        STATUS_FLOAT_DIVIDE_BY_ZERO
#define EXCEPTION_FLT_INEXACT_RESULT        STATUS_FLOAT_INEXACT_RESULT
#define EXCEPTION_FLT_INVALID_OPERATION     STATUS_FLOAT_INVALID_OPERATION
#define EXCEPTION_FLT_OVERFLOW              STATUS_FLOAT_OVERFLOW
#define EXCEPTION_FLT_STACK_CHECK           STATUS_FLOAT_STACK_CHECK
#define EXCEPTION_FLT_UNDERFLOW             STATUS_FLOAT_UNDERFLOW
#define EXCEPTION_INT_DIVIDE_BY_ZERO        STATUS_INTEGER_DIVIDE_BY_ZERO
#define EXCEPTION_INT_OVERFLOW              STATUS_INTEGER_OVERFLOW
#define EXCEPTION_PRIV_INSTRUCTION          STATUS_PRIVILEGED_INSTRUCTION
#define EXCEPTION_IN_PAGE_ERROR             STATUS_IN_PAGE_ERROR
#define EXCEPTION_ILLEGAL_INSTRUCTION       STATUS_ILLEGAL_INSTRUCTION
#define EXCEPTION_NONCONTINUABLE_EXCEPTION  STATUS_NONCONTINUABLE_EXCEPTION
#define EXCEPTION_STACK_OVERFLOW            STATUS_STACK_OVERFLOW
#define EXCEPTION_INVALID_DISPOSITION       STATUS_INVALID_DISPOSITION
#define EXCEPTION_GUARD_PAGE                STATUS_GUARD_PAGE_VIOLATION
#define EXCEPTION_INVALID_HANDLE            STATUS_INVALID_HANDLE
#define CONTROL_C_EXIT                      STATUS_CONTROL_C_EXIT

// ░░░ Structs uses by NtXxx Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

typedef struct EXCEPTION_RECORD
{
	uint32_t ExceptionCode;
	uint32_t ExceptionFlags;
	struct EXCEPTION_RECORD *ExceptionRecord;
	void *ExceptionAddress;
	uint32_t NumberParameters;
	uint64_t ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
} EXCEPTION_RECORD;

typedef struct IMAGE_RUNTIME_FUNCTION_ENTRY
{
	uint32_t BeginAddress;
	uint32_t EndAddress;
	union
	{
		uint32_t UnwindInfoAddress;
		uint32_t UnwindData;
	} DUMMYUNIONNAME;
} IMAGE_RUNTIME_FUNCTION_ENTRY;

typedef struct UNWIND_HISTORY_TABLE_ENTRY
{
	uint64_t ImageBase;
	IMAGE_RUNTIME_FUNCTION_ENTRY *FunctionEntry;
} UNWIND_HISTORY_TABLE_ENTRY;

typedef struct UNWIND_HISTORY_TABLE
{
	uint32_t Count;
	uint8_t  LocalHint;
	uint8_t  GlobalHint;
	uint8_t  Search;
	uint8_t  Once;
	uint64_t LowAddress;
	uint64_t HighAddress;
	UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
} UNWIND_HISTORY_TABLE;

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
typedef struct PS_ATTRIBUTE_LIST
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

typedef struct EXCEPTION_POINTERS
{
	EXCEPTION_RECORD *ExceptionRecord;
	CONTEXT *ContextRecord;
} EXCEPTION_POINTERS;

// excpt.h
typedef enum EXCEPTION_DISPOSITION
{
	ExceptionContinueExecution,
	ExceptionContinueSearch,
	ExceptionNestedException,
	ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;

typedef struct DISPATCHER_CONTEXT
{
	uint64_t ControlPc;
	uint64_t ImageBase;
	IMAGE_RUNTIME_FUNCTION_ENTRY *FunctionEntry;
	uint64_t EstablisherFrame;
	uint64_t TargetIp;
	CONTEXT *ContextRecord;
	EXCEPTION_DISPOSITION(*LanguageHandler)(EXCEPTION_RECORD *ExceptionRecord, void *EstablisherFrame, CONTEXT *ContextRecord, void *DispatcherContext);
	void *HandlerData;
	UNWIND_HISTORY_TABLE *HistoryTable;
	uint32_t ScopeIndex;
	uint32_t Fill0;
} DISPATCHER_CONTEXT;

// https://ntdoc.m417z.com/thread_name_information
typedef struct THREAD_NAME_INFORMATION
{
	UNICODE_STRING ThreadName;
} THREAD_NAME_INFORMATION;

// https://ntdoc.m417z.com/client_id
typedef struct CLIENT_ID
{
	Handle UniqueProcess;
	Handle UniqueThread;
} CLIENT_ID;

// https://ntdoc.m417z.com/kthread_state
typedef enum KTHREAD_STATE
{
	Initialized,
	Ready,
	Running,
	Standby,
	Terminated,
	Waiting,
	Transition,
	DeferredReady,
	GateWaitObsolete,
	WaitingForProcessInSwap,
	MaximumThreadState
} KTHREAD_STATE;

// https://ntdoc.m417z.com/kwait_reason
typedef enum KWAIT_REASON
{
	Executive,               // Waiting for an executive event.
	FreePage,                // Waiting for a free page.
	PageIn,                  // Waiting for a page to be read in.
	PoolAllocation,          // Waiting for a pool allocation.
	DelayExecution,          // Waiting due to a delay execution.           // NtDelayExecution
	Suspended,               // Waiting because the thread is suspended.    // NtSuspendThread
	UserRequest,             // Waiting due to a user request.              // NtWaitForSingleObject
	WrExecutive,             // Waiting for an executive event.
	WrFreePage,              // Waiting for a free page.
	WrPageIn,                // Waiting for a page to be read in.
	WrPoolAllocation,        // Waiting for a pool allocation.              // 10
	WrDelayExecution,        // Waiting due to a delay execution.
	WrSuspended,             // Waiting because the thread is suspended.
	WrUserRequest,           // Waiting due to a user request.
	WrEventPair,             // Waiting for an event pair.                  // NtCreateEventPair
	WrQueue,                 // Waiting for a queue.                        // NtRemoveIoCompletion
	WrLpcReceive,            // Waiting for an LPC receive.                 // NtReplyWaitReceivePort
	WrLpcReply,              // Waiting for an LPC reply.                   // NtRequestWaitReplyPort
	WrVirtualMemory,         // Waiting for virtual memory.
	WrPageOut,               // Waiting for a page to be written out.       // NtFlushVirtualMemory
	WrRendezvous,            // Waiting for a rendezvous.                   // 20
	WrKeyedEvent,            // Waiting for a keyed event.                  // NtCreateKeyedEvent
	WrTerminated,            // Waiting for thread termination.
	WrProcessInSwap,         // Waiting for a process to be swapped in.
	WrCpuRateControl,        // Waiting for CPU rate control.
	WrCalloutStack,          // Waiting for a callout stack.
	WrKernel,                // Waiting for a kernel event.
	WrResource,              // Waiting for a resource.
	WrPushLock,              // Waiting for a push lock.
	WrMutex,                 // Waiting for a mutex.
	WrQuantumEnd,            // Waiting for the end of a quantum.           // 30
	WrDispatchInt,           // Waiting for a dispatch interrupt.
	WrPreempted,             // Waiting because the thread was preempted.
	WrYieldExecution,        // Waiting to yield execution.
	WrFastMutex,             // Waiting for a fast mutex.
	WrGuardedMutex,          // Waiting for a guarded mutex.
	WrRundown,               // Waiting for a rundown.
	WrAlertByThreadId,       // Waiting for an alert by thread ID.
	WrDeferredPreempt,       // Waiting for a deferred preemption.
	WrPhysicalFault,         // Waiting for a physical fault.
	WrIoRing,                // Waiting for an I/O ring.                    // 40
	WrMdlCache,              // Waiting for an MDL cache.
	WrRcu,                   // Waiting for read-copy-update (RCU) synchronization.
	MaximumWaitReason
} KWAIT_REASON;

// https://ntdoc.m417z.com/system_thread_information
typedef struct SYSTEM_THREAD_INFORMATION
{
	uint64_t KernelTime;                   // Number of 100-nanosecond intervals spent executing kernel code.
	uint64_t UserTime;                     // Number of 100-nanosecond intervals spent executing user code.
	uint64_t CreateTime;                   // The date and time when the thread was created.
	uint32_t WaitTime;                             // The current time spent in ready queue or waiting (depending on the thread state).
	void *StartAddress;                         // The initial start address of the thread.
	CLIENT_ID ClientId;                         // The identifier of the thread and the process owning the thread.
	uint32_t Priority;                         // The dynamic priority of the thread.
	uint32_t BasePriority;                     // The starting priority of the thread.
	uint32_t ContextSwitches;                      // The total number of context switches performed.
	KTHREAD_STATE ThreadState;                  // The current state of the thread.
	KWAIT_REASON WaitReason;                    // The current reason the thread is waiting.
} SYSTEM_THREAD_INFORMATION;

// ntddk.h - https://ntdoc.m417z.com/system_firmware_table_information
typedef struct SYSTEM_FIRMWARE_TABLE_INFORMATION
{
	uint32_t ProviderSignature;   // 'RSMB'
	uint32_t Action;              // 1 = Get
	uint32_t TableID;             // 0 for SMBIOS
	uint32_t TableBufferLength;
	uint8_t TableBuffer[1];
} SYSTEM_FIRMWARE_TABLE_INFORMATION;

// https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsystemfirmwaretable
typedef struct RawSMBIOSData
{
	uint8_t Used20CallingMethod;
	uint8_t SMBIOSMajorVersion;
	uint8_t SMBIOSMinorVersion;
	uint8_t DmiRevision;
	uint32_t Length;
	uint8_t SMBIOSTableData[1];
} RawSMBIOSData;

// https://ntdoc.m417z.com/smbios_header
#pragma pack(push, 1)
typedef struct SMBIOS_HEADER
{
	uint8_t Type;
	uint8_t Length;
	uint16_t Handle;
} SMBIOS_HEADER;
#pragma pack(pop)

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

// https://ntdoc.m417z.com/threadinfoclass
typedef enum THREADINFOCLASS
{
	ThreadBasicInformation,                         // q: THREAD_BASIC_INFORMATION
	ThreadTimes,                                    // q: KERNEL_USER_TIMES
	ThreadPriority,                                 // s: KPRIORITY (requires SeIncreaseBasePriorityPrivilege)
	ThreadBasePriority,                             // s: KPRIORITY
	ThreadAffinityMask,                             // s: KAFFINITY
	ThreadImpersonationToken,                       // s: HANDLE
	ThreadDescriptorTableEntry,                     // q: DESCRIPTOR_TABLE_ENTRY (or WOW64_DESCRIPTOR_TABLE_ENTRY)
	ThreadEnableAlignmentFaultFixup,                // s: BOOLEAN
	ThreadEventPair,                                // q: Obsolete
	ThreadQuerySetWin32StartAddress,                // q: PVOID
	ThreadZeroTlsCell,                              // s: ULONG // TlsIndex // 10
	ThreadPerformanceCount,                         // q: LARGE_INTEGER
	ThreadAmILastThread,                            // q: ULONG
	ThreadIdealProcessor,                           // s: ULONG
	ThreadPriorityBoost,                            // qs: ULONG
	ThreadSetTlsArrayAddress,                       // s: ULONG_PTR
	ThreadIsIoPending,                              // q: ULONG
	ThreadHideFromDebugger,                         // q: BOOLEAN; s: void
	ThreadBreakOnTermination,                       // qs: ULONG
	ThreadSwitchLegacyState,                        // s: void // NtCurrentThread // NPX/FPU
	ThreadIsTerminated,                             // q: ULONG // 20
	ThreadLastSystemCall,                           // q: THREAD_LAST_SYSCALL_INFORMATION
	ThreadIoPriority,                               // qs: IO_PRIORITY_HINT (requires SeIncreaseBasePriorityPrivilege)
	ThreadCycleTime,                                // q: THREAD_CYCLE_TIME_INFORMATION (requires THREAD_QUERY_LIMITED_INFORMATION)
	ThreadPagePriority,                             // qs: PAGE_PRIORITY_INFORMATION
	ThreadActualBasePriority,                       // s: LONG (requires SeIncreaseBasePriorityPrivilege)
	ThreadTebInformation,                           // q: THREAD_TEB_INFORMATION (requires THREAD_GET_CONTEXT + THREAD_SET_CONTEXT)
	ThreadCSwitchMon,                               // q: Obsolete
	ThreadCSwitchPmu,                               // q: Obsolete
	ThreadWow64Context,                             // qs: WOW64_CONTEXT, ARM_NT_CONTEXT since 20H1
	ThreadGroupInformation,                         // qs: GROUP_AFFINITY // 30
	ThreadUmsInformation,                           // q: THREAD_UMS_INFORMATION // Obsolete
	ThreadCounterProfiling,                         // q: BOOLEAN; s: THREAD_PROFILING_INFORMATION?
	ThreadIdealProcessorEx,                         // qs: PROCESSOR_NUMBER; s: previous PROCESSOR_NUMBER on return
	ThreadCpuAccountingInformation,                 // q: BOOLEAN; s: HANDLE (NtOpenSession) // NtCurrentThread // since WIN8
	ThreadSuspendCount,                             // q: ULONG // since WINBLUE
	ThreadHeterogeneousCpuPolicy,                   // q: KHETERO_CPU_POLICY // since THRESHOLD
	ThreadContainerId,                              // q: GUID
	ThreadNameInformation,                          // qs: THREAD_NAME_INFORMATION (requires THREAD_SET_LIMITED_INFORMATION)
	ThreadSelectedCpuSets,                          // q: ULONG[]
	ThreadSystemThreadInformation,                  // q: SYSTEM_THREAD_INFORMATION // 40
	ThreadActualGroupAffinity,                      // q: GROUP_AFFINITY // since THRESHOLD2
	ThreadDynamicCodePolicyInfo,                    // q: ULONG; s: ULONG (NtCurrentThread)
	ThreadExplicitCaseSensitivity,                  // qs: ULONG; s: 0 disables, otherwise enables // (requires SeDebugPrivilege and PsProtectedSignerAntimalware)
	ThreadWorkOnBehalfTicket,                       // q: ALPC_WORK_ON_BEHALF_TICKET // RTL_WORK_ON_BEHALF_TICKET_EX // NtCurrentThread
	ThreadSubsystemInformation,                     // q: SUBSYSTEM_INFORMATION_TYPE // since REDSTONE2
	ThreadDbgkWerReportActive,                      // s: ULONG; s: 0 disables, otherwise enables
	ThreadAttachContainer,                          // s: HANDLE (job object) // NtCurrentThread
	ThreadManageWritesToExecutableMemory,           // s: MANAGE_WRITES_TO_EXECUTABLE_MEMORY // since REDSTONE3
	ThreadPowerThrottlingState,                     // qs: POWER_THROTTLING_THREAD_STATE // since REDSTONE3 (set), WIN11 22H2 (query)
	ThreadWorkloadClass,                            // q: THREAD_WORKLOAD_CLASS // since REDSTONE5 // 50
	ThreadCreateStateChange,                        // s: Obsolete // since WIN11
	ThreadApplyStateChange,                         // s: Obsolete
	ThreadStrongerBadHandleChecks,                  // s: ULONG // NtCurrentThread // since 22H1
	ThreadEffectiveIoPriority,                      // q: IO_PRIORITY_HINT
	ThreadEffectivePagePriority,                    // q: ULONG
	ThreadUpdateLockOwnership,                      // s: THREAD_LOCK_OWNERSHIP // since 24H2
	ThreadSchedulerSharedDataSlot,                  // q: SCHEDULER_SHARED_DATA_SLOT_INFORMATION
	ThreadTebInformationAtomic,                     // q: THREAD_TEB_INFORMATION (requires THREAD_GET_CONTEXT + THREAD_QUERY_INFORMATION)
	ThreadIndexInformation,                         // q: THREAD_INDEX_INFORMATION
	MaxThreadInfoClass
} THREADINFOCLASS;

// https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class
typedef enum PROCESSINFOCLASS
{
	ProcessBasicInformation,                        // q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
	ProcessQuotaLimits,                             // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
	ProcessIoCounters,                              // q: IO_COUNTERS
	ProcessVmCounters,                              // q: VM_COUNTERS, VM_COUNTERS_EX, VM_COUNTERS_EX2
	ProcessTimes,                                   // q: KERNEL_USER_TIMES
	ProcessBasePriority,                            // s: KPRIORITY
	ProcessRaisePriority,                           // s: PROCESS_RAISE_PRIORITY
	ProcessDebugPort,                               // q: HANDLE
	ProcessExceptionPort,                           // s: PROCESS_EXCEPTION_PORT (requires SeTcbPrivilege)
	ProcessAccessToken,                             // s: PROCESS_ACCESS_TOKEN
	ProcessLdtInformation,                          // qs: PROCESS_LDT_INFORMATION // 10
	ProcessLdtSize,                                 // s: PROCESS_LDT_SIZE
	ProcessDefaultHardErrorMode,                    // qs: PROCESS_DEFAULT_HARD_ERROR_MODE
	ProcessIoPortHandlers,                          // s: PROCESS_IO_PORT_HANDLER_INFORMATION // (kernel-mode only)
	ProcessPooledUsageAndLimits,                    // q: POOLED_USAGE_AND_LIMITS
	ProcessWorkingSetWatch,                         // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
	ProcessUserModeIOPL,                            // qs: PROCESS_USER_MODE_IOPL (requires SeTcbPrivilege)
	ProcessEnableAlignmentFaultFixup,               // s: BOOLEAN
	ProcessPriorityClass,                           // qs: PROCESS_PRIORITY_CLASS
	ProcessWx86Information,                         // qs: ULONG (requires SeTcbPrivilege) (VdmAllowed)
	ProcessHandleCount,                             // q: ULONG, PROCESS_HANDLE_INFORMATION // 20
	ProcessAffinityMask,                            // qs: KAFFINITY, qs: GROUP_AFFINITY
	ProcessPriorityBoost,                           // qs: PROCESS_PRIORITY_BOOST
	ProcessDeviceMap,                               // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
	ProcessSessionInformation,                      // q: PROCESS_SESSION_INFORMATION
	ProcessForegroundInformation,                   // s: PROCESS_FOREGROUND_BACKGROUND
	ProcessWow64Information,                        // q: ULONG_PTR
	ProcessImageFileName,                           // q: UNICODE_STRING
	ProcessLUIDDeviceMapsEnabled,                   // q: PROCESS_LUID_DEVICE_MAPS_ENABLED
	ProcessBreakOnTermination,                      // qs: ULONG
	ProcessDebugObjectHandle,                       // q: HANDLE // 30
	ProcessDebugFlags,                              // qs: PROCESS_DEBUG_FLAGS
	ProcessHandleTracing,                           // q: PROCESS_HANDLE_TRACING_QUERY; s: PROCESS_HANDLE_TRACING_ENABLE[_EX] or void to disable
	ProcessIoPriority,                              // qs: IO_PRIORITY_HINT
	ProcessExecuteFlags,                            // qs: PROCESS_EXECUTE_FLAGS
	ProcessTlsInformation,                          // qs: PROCESS_TLS_INFORMATION // ProcessResourceManagement
	ProcessCookie,                                  // q: ULONG
	ProcessImageInformation,                        // q: SECTION_IMAGE_INFORMATION
	ProcessCycleTime,                               // q: PROCESS_CYCLE_TIME_INFORMATION // since VISTA
	ProcessPagePriority,                            // qs: PAGE_PRIORITY_INFORMATION
	ProcessInstrumentationCallback,                 // s: PVOID or PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION // 40
	ProcessThreadStackAllocation,                   // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
	ProcessWorkingSetWatchEx,                       // q: PROCESS_WS_WATCH_INFORMATION_EX[]; s: void
	ProcessImageFileNameWin32,                      // q: UNICODE_STRING
	ProcessImageFileMapping,                        // q: HANDLE (input)
	ProcessAffinityUpdateMode,                      // qs: PROCESS_AFFINITY_UPDATE_MODE
	ProcessMemoryAllocationMode,                    // qs: PROCESS_MEMORY_ALLOCATION_MODE
	ProcessGroupInformation,                        // q: PROCESS_GROUP_INFORMATION
	ProcessTokenVirtualizationEnabled,              // s: ULONG
	ProcessConsoleHostProcess,                      // qs: ULONG_PTR // ProcessOwnerInformation
	ProcessWindowInformation,                       // q: PROCESS_WINDOW_INFORMATION // 50
	ProcessHandleInformation,                       // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
	ProcessMitigationPolicy,                        // qs: PROCESS_MITIGATION_POLICY_INFORMATION
	ProcessDynamicFunctionTableInformation,         // s: PROCESS_DYNAMIC_FUNCTION_TABLE_INFORMATION
	ProcessHandleCheckingMode,                      // qs: PROCESS_HANDLE_CHECKING_MODE; s: 0 disables, otherwise enables
	ProcessKeepAliveCount,                          // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
	ProcessRevokeFileHandles,                       // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
	ProcessWorkingSetControl,                       // s: PROCESS_WORKING_SET_CONTROL
	ProcessHandleTable,                             // q: ULONG[] // since WINBLUE
	ProcessCheckStackExtentsMode,                   // qs: ULONG // KPROCESS->CheckStackExtents (CFG)
	ProcessCommandLineInformation,                  // q: UNICODE_STRING // 60
	ProcessProtectionInformation,                   // q: PS_PROTECTION
	ProcessMemoryExhaustion,                        // s: PROCESS_MEMORY_EXHAUSTION_INFO // since THRESHOLD
	ProcessFaultInformation,                        // s: PROCESS_FAULT_INFORMATION
	ProcessTelemetryIdInformation,                  // q: PROCESS_TELEMETRY_ID_INFORMATION
	ProcessCommitReleaseInformation,                // qs: PROCESS_COMMIT_RELEASE_INFORMATION
	ProcessDefaultCpuSetsInformation,               // qs: SYSTEM_CPU_SET_INFORMATION[5] // ProcessReserved1Information
	ProcessAllowedCpuSetsInformation,               // qs: SYSTEM_CPU_SET_INFORMATION[5] // ProcessReserved2Information
	ProcessSubsystemProcess,                        // s: void // EPROCESS->SubsystemProcess
	ProcessJobMemoryInformation,                    // q: PROCESS_JOB_MEMORY_INFO
	ProcessInPrivate,                               // q: BOOLEAN; s: void // ETW // since THRESHOLD2 // 70
	ProcessRaiseUMExceptionOnInvalidHandleClose,    // qs: PROCESS_RAISE_UM_EXCEPTION_ON_INVALID_HANDLE_CLOSE; s: 0 disables, otherwise enables
	ProcessIumChallengeResponse,                    // q: PROCESS_IUM_CHALLENGE_RESPONSE
	ProcessChildProcessInformation,                 // q: PROCESS_CHILD_PROCESS_INFORMATION
	ProcessHighGraphicsPriorityInformation,         // q: BOOLEAN; s: BOOLEAN (requires SeTcbPrivilege)
	ProcessSubsystemInformation,                    // q: SUBSYSTEM_INFORMATION_TYPE // since REDSTONE2
	ProcessEnergyValues,                            // q: PROCESS_ENERGY_VALUES, PROCESS_EXTENDED_ENERGY_VALUES, PROCESS_EXTENDED_ENERGY_VALUES_V1
	ProcessPowerThrottlingState,                    // qs: POWER_THROTTLING_PROCESS_STATE
	ProcessActivityThrottlePolicy,                  // qs: PROCESS_ACTIVITY_THROTTLE_POLICY // ProcessReserved3Information
	ProcessWin32kSyscallFilterInformation,          // q: WIN32K_SYSCALL_FILTER
	ProcessDisableSystemAllowedCpuSets,             // s: BOOLEAN // 80
	ProcessWakeInformation,                         // q: PROCESS_WAKE_INFORMATION // (kernel-mode only)
	ProcessEnergyTrackingState,                     // qs: PROCESS_ENERGY_TRACKING_STATE
	ProcessManageWritesToExecutableMemory,          // s: MANAGE_WRITES_TO_EXECUTABLE_MEMORY // since REDSTONE3
	ProcessCaptureTrustletLiveDump,                 // q: ULONG
	ProcessTelemetryCoverage,                       // q: TELEMETRY_COVERAGE_HEADER; s: TELEMETRY_COVERAGE_POINT
	ProcessEnclaveInformation,                      // qs: not implemented
	ProcessEnableReadWriteVmLogging,                // qs: PROCESS_READWRITEVM_LOGGING_INFORMATION
	ProcessUptimeInformation,                       // q: PROCESS_UPTIME_INFORMATION
	ProcessImageSection,                            // q: HANDLE
	ProcessDebugAuthInformation,                    // s: CiTool.exe --device-id // PplDebugAuthorization // since RS4 // 90
	ProcessSystemResourceManagement,                // s: PROCESS_SYSTEM_RESOURCE_MANAGEMENT
	ProcessSequenceNumber,                          // q: ULONGLONG
	ProcessLoaderDetour,                            // qs: Obsolete // since RS5
	ProcessSecurityDomainInformation,               // q: PROCESS_SECURITY_DOMAIN_INFORMATION
	ProcessCombineSecurityDomainsInformation,       // s: PROCESS_COMBINE_SECURITY_DOMAINS_INFORMATION
	ProcessEnableLogging,                           // qs: PROCESS_LOGGING_INFORMATION
	ProcessLeapSecondInformation,                   // qs: PROCESS_LEAP_SECOND_INFORMATION
	ProcessFiberShadowStackAllocation,              // s: PROCESS_FIBER_SHADOW_STACK_ALLOCATION_INFORMATION // since 19H1
	ProcessFreeFiberShadowStackAllocation,          // s: PROCESS_FREE_FIBER_SHADOW_STACK_ALLOCATION_INFORMATION
	ProcessAltSystemCallInformation,                // s: PROCESS_SYSCALL_PROVIDER_INFORMATION // since 20H1 // 100
	ProcessDynamicEHContinuationTargets,            // s: PROCESS_DYNAMIC_EH_CONTINUATION_TARGETS_INFORMATION
	ProcessDynamicEnforcedCetCompatibleRanges,      // s: PROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE_INFORMATION // since 20H2
	ProcessCreateStateChange,                       // s: Obsolete // since WIN11
	ProcessApplyStateChange,                        // s: Obsolete
	ProcessEnableOptionalXStateFeatures,            // s: ULONG64 // EnableProcessOptionalXStateFeatures
	ProcessAltPrefetchParam,                        // qs: OVERRIDE_PREFETCH_PARAMETER // App Launch Prefetch (ALPF) // since 22H1
	ProcessAssignCpuPartitions,                     // s: HANDLE
	ProcessPriorityClassEx,                         // s: PROCESS_PRIORITY_CLASS_EX
	ProcessMembershipInformation,                   // q: PROCESS_MEMBERSHIP_INFORMATION
	ProcessEffectiveIoPriority,                     // q: IO_PRIORITY_HINT // 110
	ProcessEffectivePagePriority,                   // q: ULONG
	ProcessSchedulerSharedData,                     // q: SCHEDULER_SHARED_DATA_SLOT_INFORMATION // since 24H2
	ProcessSlistRollbackInformation,                // s: no input buffer, length 0, current process only
	ProcessNetworkIoCounters,                       // q: PROCESS_NETWORK_COUNTERS
	ProcessFindFirstThreadByTebValue,               // q: PROCESS_TEB_VALUE_INFORMATION // NtCurrentProcess
	ProcessEnclaveAddressSpaceRestriction,          // qs: // since 25H2
	ProcessAvailableCpus,                           // q: PROCESS_AVAILABLE_CPUS_INFORMATION
	MaxProcessInfoClass
} PROCESSINFOCLASS;

// https://learn.microsoft.com/en-us/windows/win32/api/winnt/ne-winnt-process_mitigation_policy
typedef enum PROCESS_MITIGATION_POLICY
{
	ProcessDEPPolicy,
	ProcessASLRPolicy,
	ProcessDynamicCodePolicy,
	ProcessStrictHandleCheckPolicy,
	ProcessSystemCallDisablePolicy,
	ProcessMitigationOptionsMask,
	ProcessExtensionPointDisablePolicy,
	ProcessControlFlowGuardPolicy,
	ProcessSignaturePolicy,
	ProcessFontDisablePolicy,
	ProcessImageLoadPolicy,
	ProcessSystemCallFilterPolicy,
	ProcessPayloadRestrictionPolicy,
	ProcessChildProcessPolicy,
	ProcessSideChannelIsolationPolicy,
	ProcessUserShadowStackPolicy,
	ProcessRedirectionTrustPolicy,
	ProcessUserPointerAuthPolicy,
	ProcessSEHOPPolicy,
	MaxProcessMitigationPolicy
} PROCESS_MITIGATION_POLICY;

// https://ntdoc.m417z.com/section_inherit
typedef enum SECTION_INHERIT
{
	ViewShare = 1, // The mapped view of the section will be mapped into any child processes created by the process.
	ViewUnmap = 2  // The mapped view of the section will not be mapped into any child processes created by the process.
} SECTION_INHERIT;

// winternal.h - https://ntdoc.m417z.com/system_information_class
typedef enum SYSTEM_INFORMATION_CLASS
{
	SystemBasicInformation,                                 // q: SYSTEM_BASIC_INFORMATION
	SystemProcessorInformation,                             // q: SYSTEM_PROCESSOR_INFORMATION
	SystemPerformanceInformation,                           // q: SYSTEM_PERFORMANCE_INFORMATION
	SystemTimeOfDayInformation,                             // q: SYSTEM_TIMEOFDAY_INFORMATION
	SystemPathInformation,                                  // q: not implemented
	SystemProcessInformation,                               // q: SYSTEM_PROCESS_INFORMATION
	SystemCallCountInformation,                             // q: SYSTEM_CALL_COUNT_INFORMATION
	SystemDeviceInformation,                                // q: SYSTEM_DEVICE_INFORMATION
	SystemProcessorPerformanceInformation,                  // q: SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemFlagsInformation,                                 // qs: SYSTEM_FLAGS_INFORMATION
	SystemCallTimeInformation,                              // q: SYSTEM_CALL_TIME_INFORMATION // not implemented // 10
	SystemModuleInformation,                                // q: RTL_PROCESS_MODULES
	SystemLocksInformation,                                 // q: RTL_PROCESS_LOCKS
	SystemStackTraceInformation,                            // q: RTL_PROCESS_BACKTRACES
	SystemPagedPoolInformation,                             // q: not implemented
	SystemNonPagedPoolInformation,                          // q: not implemented
	SystemHandleInformation,                                // q: SYSTEM_HANDLE_INFORMATION
	SystemObjectInformation,                                // q: SYSTEM_OBJECTTYPE_INFORMATION mixed with SYSTEM_OBJECT_INFORMATION
	SystemPageFileInformation,                              // q: SYSTEM_PAGEFILE_INFORMATION
	SystemVdmInstemulInformation,                           // q: SYSTEM_VDM_INSTEMUL_INFO
	SystemVdmBopInformation,                                // q: not implemented // 20
	SystemFileCacheInformation,                             // qs: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypeSystemCache)
	SystemPoolTagInformation,                               // q: SYSTEM_POOLTAG_INFORMATION
	SystemInterruptInformation,                             // q: SYSTEM_INTERRUPT_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemDpcBehaviorInformation,                           // qs: SYSTEM_DPC_BEHAVIOR_INFORMATION; s: SYSTEM_DPC_BEHAVIOR_INFORMATION (requires SeLoadDriverPrivilege)
	SystemFullMemoryInformation,                            // q: SYSTEM_MEMORY_USAGE_INFORMATION // not implemented
	SystemLoadGdiDriverInformation,                         // s: SYSTEM_GDI_DRIVER_INFORMATION (kernel-mode only)
	SystemUnloadGdiDriverInformation,                       // s: SYSTEM_GDI_DRIVER_UNLOAD_INFORMATION (kernel-mode only)
	SystemTimeAdjustmentInformation,                        // qs: SYSTEM_QUERY_TIME_ADJUST_INFORMATION; s: SYSTEM_SET_TIME_ADJUST_INFORMATION (requires SeSystemtimePrivilege)
	SystemSummaryMemoryInformation,                         // q: SYSTEM_MEMORY_USAGE_INFORMATION // not implemented
	SystemMirrorMemoryInformation,                          // qs: (requires license value "Kernel-MemoryMirroringSupported") (requires SeShutdownPrivilege) // 30
	SystemPerformanceTraceInformation,                      // qs: (type depends on EVENT_TRACE_INFORMATION_CLASS)
	SystemObsolete0,                                        // q: not implemented
	SystemExceptionInformation,                             // q: SYSTEM_EXCEPTION_INFORMATION
	SystemCrashDumpStateInformation,                        // s: SYSTEM_CRASH_DUMP_STATE_INFORMATION (requires SeDebugPrivilege)
	SystemKernelDebuggerInformation,                        // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION
	SystemContextSwitchInformation,                         // q: SYSTEM_CONTEXT_SWITCH_INFORMATION
	SystemRegistryQuotaInformation,                         // qs: SYSTEM_REGISTRY_QUOTA_INFORMATION; s (requires SeIncreaseQuotaPrivilege)
	SystemExtendServiceTableInformation,                    // s: SYSTEM_EXTEND_SERVICE_TABLE_INFORMATION (requires SeLoadDriverPrivilege) // loads win32k only
	SystemPrioritySeparation,                               // s: SYSTEM_PRIORITY_SEPARATION_INFORMATION (requires SeTcbPrivilege)
	SystemVerifierAddDriverInformation,                     // s: UNICODE_STRING (requires SeDebugPrivilege) // 40
	SystemVerifierRemoveDriverInformation,                  // s: UNICODE_STRING (requires SeDebugPrivilege)
	SystemProcessorIdleInformation,                         // q: SYSTEM_PROCESSOR_IDLE_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemLegacyDriverInformation,                          // q: SYSTEM_LEGACY_DRIVER_INFORMATION
	SystemCurrentTimeZoneInformation,                       // qs: RTL_TIME_ZONE_INFORMATION
	SystemLookasideInformation,                             // q: SYSTEM_LOOKASIDE_INFORMATION
	SystemTimeSlipNotification,                             // s: HANDLE (NtCreateEvent) (requires SeSystemtimePrivilege)
	SystemSessionCreate,                                    // q: not implemented
	SystemSessionDetach,                                    // q: not implemented
	SystemSessionInformation,                               // q: not implemented (SYSTEM_SESSION_INFORMATION)
	SystemRangeStartInformation,                            // q: SYSTEM_RANGE_START_INFORMATION // 50
	SystemVerifierInformation,                              // qs: SYSTEM_VERIFIER_INFORMATION; s (requires SeDebugPrivilege)
	SystemVerifierThunkExtend,                              // qs: (kernel-mode only)
	SystemSessionProcessInformation,                        // q: SYSTEM_SESSION_PROCESS_INFORMATION
	SystemLoadGdiDriverInSystemSpace,                       // qs: SYSTEM_GDI_DRIVER_INFORMATION (kernel-mode only) (same handler as SystemLoadGdiDriverInformation)
	SystemNumaProcessorMap,                                 // q: SYSTEM_NUMA_INFORMATION
	SystemPrefetcherInformation,                            // qs: PREFETCHER_INFORMATION // PfSnQueryPrefetcherInformation
	SystemExtendedProcessInformation,                       // q: SYSTEM_EXTENDED_PROCESS_INFORMATION
	SystemRecommendedSharedDataAlignment,                   // q: SYSTEM_RECOMMENDED_SHARED_DATA_ALIGNMENT_INFORMATION // KeGetRecommendedSharedDataAlignment
	SystemComPlusPackage,                                   // qs: SYSTEM_COMPLUS_PACKAGE_INFORMATION
	SystemNumaAvailableMemory,                              // q: SYSTEM_NUMA_INFORMATION // 60
	SystemProcessorPowerInformation,                        // q: SYSTEM_PROCESSOR_POWER_INFORMATION (EX in: USHORT ProcessorGroup)
	SystemEmulationBasicInformation,                        // q: SYSTEM_BASIC_INFORMATION
	SystemEmulationProcessorInformation,                    // q: SYSTEM_PROCESSOR_INFORMATION
	SystemExtendedHandleInformation,                        // q: SYSTEM_HANDLE_INFORMATION_EX
	SystemLostDelayedWriteInformation,                      // q: SYSTEM_LOST_DELAYED_WRITE_INFORMATION
	SystemBigPoolInformation,                               // q: SYSTEM_BIGPOOL_INFORMATION
	SystemSessionPoolTagInformation,                        // q: SYSTEM_SESSION_POOLTAG_INFORMATION
	SystemSessionMappedViewInformation,                     // q: SYSTEM_SESSION_MAPPED_VIEW_INFORMATION
	SystemHotpatchInformation,                              // qs: SYSTEM_HOTPATCH_CODE_INFORMATION
	SystemObjectSecurityMode,                               // q: SYSTEM_OBJECT_SECURITY_MODE_INFORMATION // 70
	SystemWatchdogTimerHandler,                             // s: SYSTEM_WATCHDOG_HANDLER_INFORMATION // (kernel-mode only)
	SystemWatchdogTimerInformation,                         // qs: out: SYSTEM_WATCHDOG_TIMER_INFORMATION (EX in: ULONG WATCHDOG_INFORMATION_CLASS) // NtQuerySystemInformationEx
	SystemLogicalProcessorInformation,                      // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION (EX in: USHORT ProcessorGroup) // NtQuerySystemInformationEx
	SystemWow64SharedInformationObsolete,                   // q: not implemented
	SystemRegisterFirmwareTableInformationHandler,          // s: SYSTEM_FIRMWARE_TABLE_HANDLER // (kernel-mode only)
	SystemFirmwareTableInformation,                         // q: SYSTEM_FIRMWARE_TABLE_INFORMATION
	SystemModuleInformationEx,                              // q: RTL_PROCESS_MODULE_INFORMATION_EX // since VISTA
	SystemVerifierTriageInformation,                        // q: not implemented
	SystemSuperfetchInformation,                            // qs: SUPERFETCH_INFORMATION // PfQuerySuperfetchInformation
	SystemMemoryListInformation,                            // q: SYSTEM_MEMORY_LIST_INFORMATION; s: SYSTEM_MEMORY_LIST_COMMAND (requires SeProfileSingleProcessPrivilege) // 80
	SystemFileCacheInformationEx,                           // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (same as SystemFileCacheInformation)
	SystemThreadPriorityClientIdInformation,                // s: SYSTEM_THREAD_CID_PRIORITY_INFORMATION (requires SeIncreaseBasePriorityPrivilege) // NtQuerySystemInformationEx
	SystemProcessorIdleCycleTimeInformation,                // q: SYSTEM_PROCESSOR_IDLE_CYCLE_TIME_INFORMATION[] (EX in: USHORT ProcessorGroup) // NtQuerySystemInformationEx
	SystemVerifierCancellationInformation,                  // q: SYSTEM_VERIFIER_CANCELLATION_INFORMATION // name:wow64:whNT32QuerySystemVerifierCancellationInformation
	SystemProcessorPowerInformationEx,                      // q: not implemented
	SystemRefTraceInformation,                              // qs: SYSTEM_REF_TRACE_INFORMATION // ObQueryRefTraceInformation
	SystemSpecialPoolInformation,                           // qs: SYSTEM_SPECIAL_POOL_INFORMATION (requires SeDebugPrivilege) // MmSpecialPoolTag, then MmSpecialPoolCatchOverruns != 0
	SystemProcessIdInformation,                             // q: SYSTEM_PROCESS_ID_INFORMATION
	SystemErrorPortInformation,                             // s: HANDLE (requires SeTcbPrivilege)
	SystemBootEnvironmentInformation,                       // q: SYSTEM_BOOT_ENVIRONMENT_INFORMATION // 90
	SystemHypervisorInformation,                            // q: SYSTEM_HYPERVISOR_QUERY_INFORMATION
	SystemVerifierInformationEx,                            // qs: SYSTEM_VERIFIER_INFORMATION_EX
	SystemTimeZoneInformation,                              // qs: RTL_TIME_ZONE_INFORMATION (requires SeTimeZonePrivilege)
	SystemImageFileExecutionOptionsInformation,             // s: SYSTEM_IMAGE_FILE_EXECUTION_OPTIONS_INFORMATION (requires SeTcbPrivilege)
	SystemCoverageInformation,                              // q: COVERAGE_MODULES s: COVERAGE_MODULE_REQUEST // ExpCovQueryInformation (requires SeDebugPrivilege)
	SystemPrefetchPatchInformation,                         // q: SYSTEM_PREFETCH_PATCH_INFORMATION
	SystemVerifierFaultsInformation,                        // s: SYSTEM_VERIFIER_FAULTS_INFORMATION (requires SeDebugPrivilege)
	SystemSystemPartitionInformation,                       // q: SYSTEM_SYSTEM_PARTITION_INFORMATION
	SystemSystemDiskInformation,                            // q: SYSTEM_SYSTEM_DISK_INFORMATION
	SystemProcessorPerformanceDistribution,                 // q: SYSTEM_PROCESSOR_PERFORMANCE_DISTRIBUTION (EX in: USHORT ProcessorGroup) // NtQuerySystemInformationEx // 100
	SystemNumaProximityNodeInformation,                     // qs: SYSTEM_NUMA_PROXIMITY_MAP
	SystemDynamicTimeZoneInformation,                       // qs: RTL_DYNAMIC_TIME_ZONE_INFORMATION (requires SeTimeZonePrivilege)
	SystemCodeIntegrityInformation,                         // q: SYSTEM_CODEINTEGRITY_INFORMATION // SeCodeIntegrityQueryInformation
	SystemProcessorMicrocodeUpdateInformation,              // s: SYSTEM_PROCESSOR_MICROCODE_UPDATE_INFORMATION (requires SeLoadDriverPrivilege)
	SystemProcessorBrandString,                             // q: SYSTEM_PROCESSOR_BRAND_STRING // HaliQuerySystemInformation -> HalpGetProcessorBrandString, info class 23
	SystemVirtualAddressInformation,                        // q: SYSTEM_VA_LIST_INFORMATION[]; s: SYSTEM_VA_LIST_INFORMATION[] (requires SeIncreaseQuotaPrivilege) // MmQuerySystemVaInformation
	SystemLogicalProcessorAndGroupInformation,              // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX (EX in: LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType) // since WIN7 // NtQuerySystemInformationEx // KeQueryLogicalProcessorRelationship
	SystemProcessorCycleTimeInformation,                    // q: SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION[] (EX in: USHORT ProcessorGroup) // NtQuerySystemInformationEx
	SystemStoreInformation,                                 // qs: SYSTEM_STORE_INFORMATION (requires SeProfileSingleProcessPrivilege) // SmQueryStoreInformation
	SystemRegistryAppendString,                             // s: SYSTEM_REGISTRY_APPEND_STRING_PARAMETERS // 110
	SystemAitSamplingValue,                                 // s: SYSTEM_AIT_SAMPLING_VALUE_INFORMATION (requires SeProfileSingleProcessPrivilege)
	SystemVhdBootInformation,                               // q: SYSTEM_VHD_BOOT_INFORMATION
	SystemCpuQuotaInformation,                              // qs: PS_CPU_QUOTA_QUERY_INFORMATION
	SystemNativeBasicInformation,                           // q: SYSTEM_BASIC_INFORMATION
	SystemErrorPortTimeouts,                                // q: SYSTEM_ERROR_PORT_TIMEOUTS
	SystemLowPriorityIoInformation,                         // q: SYSTEM_LOW_PRIORITY_IO_INFORMATION
	SystemTpmBootEntropyInformation,                        // q: BOOT_ENTROPY_NT_RESULT // ExQueryBootEntropyInformation
	SystemVerifierCountersInformation,                      // q: SYSTEM_VERIFIER_COUNTERS_INFORMATION
	SystemPagedPoolInformationEx,                           // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypePagedPool)
	SystemSystemPtesInformationEx,                          // q: SYSTEM_FILECACHE_INFORMATION; s (requires SeIncreaseQuotaPrivilege) (info for WorkingSetTypeSystemPtes) // 120
	SystemNodeDistanceInformation,                          // q: USHORT[4*NumaNodes] // (EX in: USHORT NodeNumber) // NtQuerySystemInformationEx
	SystemAcpiAuditInformation,                             // q: SYSTEM_ACPI_AUDIT_INFORMATION // HaliQuerySystemInformation -> HalpAuditQueryResults, info class 26
	SystemBasicPerformanceInformation,                      // q: SYSTEM_BASIC_PERFORMANCE_INFORMATION // name:wow64:whNtQuerySystemInformation_SystemBasicPerformanceInformation
	SystemQueryPerformanceCounterInformation,               // q: SYSTEM_QUERY_PERFORMANCE_COUNTER_INFORMATION // since WIN7 SP1
	SystemSessionBigPoolInformation,                        // q: SYSTEM_SESSION_POOLTAG_INFORMATION // since WIN8
	SystemBootGraphicsInformation,                          // qs: SYSTEM_BOOT_GRAPHICS_INFORMATION (kernel-mode only)
	SystemScrubPhysicalMemoryInformation,                   // qs: MEMORY_SCRUB_INFORMATION
	SystemBadPageInformation,                               // q: SYSTEM_BAD_PAGE_INFORMATION
	SystemProcessorProfileControlArea,                      // qs: SYSTEM_PROCESSOR_PROFILE_CONTROL_AREA
	SystemCombinePhysicalMemoryInformation,                 // s: MEMORY_COMBINE_INFORMATION, MEMORY_COMBINE_INFORMATION_EX, MEMORY_COMBINE_INFORMATION_EX2 // 130
	SystemEntropyInterruptTimingInformation,                // qs: SYSTEM_ENTROPY_TIMING_INFORMATION
	SystemConsoleInformation,                               // qs: SYSTEM_CONSOLE_INFORMATION // (requires SeLoadDriverPrivilege)
	SystemPlatformBinaryInformation,                        // q: SYSTEM_PLATFORM_BINARY_INFORMATION (requires SeTcbPrivilege)
	SystemPolicyInformation,                                // q: SYSTEM_POLICY_INFORMATION
	SystemHypervisorProcessorCountInformation,              // q: SYSTEM_HYPERVISOR_PROCESSOR_COUNT_INFORMATION
	SystemDeviceDataInformation,                            // q: SYSTEM_DEVICE_DATA_INFORMATION
	SystemDeviceDataEnumerationInformation,                 // q: SYSTEM_DEVICE_DATA_INFORMATION
	SystemMemoryTopologyInformation,                        // q: SYSTEM_MEMORY_TOPOLOGY_INFORMATION
	SystemMemoryChannelInformation,                         // q: SYSTEM_MEMORY_CHANNEL_INFORMATION
	SystemBootLogoInformation,                              // q: SYSTEM_BOOT_LOGO_INFORMATION // 140
	SystemProcessorPerformanceInformationEx,                // q: SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION_EX // (EX in: USHORT ProcessorGroup) // NtQuerySystemInformationEx // since WINBLUE
	SystemCriticalProcessErrorLogInformation,               // q: SYSTEM_CRITICAL_PROCESS_EXCEPTION_INFORMATION
	SystemSecureBootPolicyInformation,                      // q: SYSTEM_SECUREBOOT_POLICY_INFORMATION
	SystemPageFileInformationEx,                            // q: SYSTEM_PAGEFILE_INFORMATION_EX
	SystemSecureBootInformation,                            // q: SYSTEM_SECUREBOOT_INFORMATION
	SystemEntropyInterruptTimingRawInformation,             // qs: SYSTEM_ENTROPY_TIMING_INFORMATION
	SystemPortableWorkspaceEfiLauncherInformation,          // q: SYSTEM_PORTABLE_WORKSPACE_EFI_LAUNCHER_INFORMATION
	SystemFullProcessInformation,                           // q: SYSTEM_EXTENDED_PROCESS_INFORMATION with SYSTEM_PROCESS_INFORMATION_EXTENSION (requires admin)
	SystemKernelDebuggerInformationEx,                      // q: SYSTEM_KERNEL_DEBUGGER_INFORMATION_EX
	SystemBootMetadataInformation,                          // q: SYSTEM_BOOT_METADATA_INFORMATION // (requires SeTcbPrivilege) // 150
	SystemSoftRebootInformation,                            // qs: SYSTEM_SOFT_REBOOT_INFORMATION (s requires SeTcbPrivilege) // query returns ExSoftRebootFlags; set calls ExpSetSoftRebootFlags
	SystemElamCertificateInformation,                       // s: SYSTEM_ELAM_CERTIFICATE_INFORMATION
	SystemOfflineDumpConfigInformation,                     // q: OFFLINE_CRASHDUMP_CONFIGURATION_TABLE_V2
	SystemProcessorFeaturesInformation,                     // q: SYSTEM_PROCESSOR_FEATURES_INFORMATION
	SystemRegistryReconciliationInformation,                // s: NULL (requires admin) (flushes registry hives)
	SystemEdidInformation,                                  // q: SYSTEM_EDID_INFORMATION
	SystemManufacturingInformation,                         // q: SYSTEM_MANUFACTURING_INFORMATION // since THRESHOLD
	SystemEnergyEstimationConfigInformation,                // q: SYSTEM_ENERGY_ESTIMATION_CONFIG_INFORMATION
	SystemHypervisorDetailInformation,                      // q: SYSTEM_HYPERVISOR_DETAIL_INFORMATION
	SystemProcessorCycleStatsInformation,                   // q: SYSTEM_PROCESSOR_CYCLE_STATS_INFORMATION (EX in: USHORT ProcessorGroup) // NtQuerySystemInformationEx // 160
	SystemVmGenerationCountInformation,                     // s: PHYSICAL_ADDRESS (kernel-mode only) (vmgencounter.sys)
	SystemTrustedPlatformModuleInformation,                 // q: SYSTEM_TPM_INFORMATION
	SystemKernelDebuggerFlags,                              // q: SYSTEM_KERNEL_DEBUGGER_FLAGS
	SystemCodeIntegrityPolicyInformation,                   // qs: SYSTEM_CODEINTEGRITYPOLICY_INFORMATION
	SystemIsolatedUserModeInformation,                      // q: SYSTEM_ISOLATED_USER_MODE_INFORMATION
	SystemHardwareSecurityTestInterfaceResultsInformation,  // q: SYSTEM_HARDWARE_SECURITY_TEST_INTERFACE_RESULTS_INFORMATION
	SystemSingleModuleInformation,                          // q: SYSTEM_SINGLE_MODULE_INFORMATION
	SystemAllowedCpuSetsInformation,                        // s: SYSTEM_WORKLOAD_ALLOWED_CPU_SET_INFORMATION
	SystemVsmProtectionInformation,                         // q: SYSTEM_VSM_PROTECTION_INFORMATION (previously SystemDmaProtectionInformation)
	SystemInterruptCpuSetsInformation,                      // q: SYSTEM_INTERRUPT_CPU_SET_INFORMATION // 170
	SystemSecureBootPolicyFullInformation,                  // q: SYSTEM_SECUREBOOT_POLICY_FULL_INFORMATION
	SystemCodeIntegrityPolicyFullInformation,               // q: SYSTEM_CODE_INTEGRITY_POLICY_FULL_INFORMATION
	SystemAffinitizedInterruptProcessorInformation,         // q: KAFFINITY_EX // (requires SeIncreaseBasePriorityPrivilege)
	SystemRootSiloInformation,                              // q: SYSTEM_ROOT_SILO_INFORMATION
	SystemCpuSetInformation,                                // q: SYSTEM_CPU_SET_INFORMATION // since THRESHOLD2
	SystemCpuSetTagInformation,                             // q: SYSTEM_CPU_SET_TAG_INFORMATION
	SystemWin32WerStartCallout,                             // s: SYSTEM_WIN32_WER_START_CALLOUT (optional; 0-length uses current process)
	SystemSecureKernelProfileInformation,                   // q: SYSTEM_SECURE_KERNEL_HYPERGUARD_PROFILE_INFORMATION
	SystemCodeIntegrityPlatformManifestInformation,         // q: SYSTEM_SECUREBOOT_PLATFORM_MANIFEST_INFORMATION // NtQuerySystemInformationEx // since REDSTONE
	SystemInterruptSteeringInformation,                     // q: in: SYSTEM_INTERRUPT_STEERING_INFORMATION_INPUT, out: SYSTEM_INTERRUPT_STEERING_INFORMATION_OUTPUT // NtQuerySystemInformationEx // 180
	SystemSupportedProcessorArchitectures,                  // p: in opt: HANDLE, out: SYSTEM_SUPPORTED_PROCESSOR_ARCHITECTURES_INFORMATION[] // NtQuerySystemInformationEx
	SystemMemoryUsageInformation,                           // q: SYSTEM_MEMORY_USAGE_INFORMATION
	SystemCodeIntegrityCertificateInformation,              // q: SYSTEM_CODEINTEGRITY_CERTIFICATE_INFORMATION
	SystemPhysicalMemoryInformation,                        // q: SYSTEM_PHYSICAL_MEMORY_INFORMATION // since REDSTONE2
	SystemControlFlowTransition,                            // qs: SYSTEM_CONTROL_FLOW_TRANSITION // operation-tagged Warbird control-flow transition request
	SystemKernelDebuggingAllowed,                           // s: ULONG
	SystemActivityModerationExeState,                       // s: SYSTEM_ACTIVITY_MODERATION_EXE_STATE
	SystemActivityModerationUserSettings,                   // q: SYSTEM_ACTIVITY_MODERATION_USER_SETTINGS
	SystemCodeIntegrityPoliciesFullInformation,             // qs: SYSTEM_CODE_INTEGRITY_POLICIES_FULL_INFORMATION // NtQuerySystemInformationEx
	SystemCodeIntegrityUnlockInformation,                   // q: SYSTEM_CODEINTEGRITY_UNLOCK_INFORMATION // 190
	SystemIntegrityQuotaInformation,                        // s: SYSTEM_INTEGRITY_QUOTA_INFORMATION (requires SeDebugPrivilege)
	SystemFlushInformation,                                 // q: SYSTEM_FLUSH_INFORMATION
	SystemProcessorIdleMaskInformation,                     // q: ULONG_PTR[ActiveGroupCount] // since REDSTONE3
	SystemSecureDumpEncryptionInformation,                  // qs: SYSTEM_SECURE_DUMP_ENCRYPTION_INFORMATION // NtQuerySystemInformationEx // opaque dump-key transform buffer (q: requires SeDebugPrivilege) (s: 0-length only, requires SeTcbPrivilege)
	SystemWriteConstraintInformation,                       // q: SYSTEM_WRITE_CONSTRAINT_INFORMATION
	SystemKernelVaShadowInformation,                        // q: SYSTEM_KERNEL_VA_SHADOW_INFORMATION
	SystemHypervisorSharedPageInformation,                  // q: SYSTEM_HYPERVISOR_SHARED_PAGE_INFORMATION // since REDSTONE4
	SystemFirmwareBootPerformanceInformation,               // q: SYSTEM_FIRMWARE_BOOT_PERFORMANCE_INFORMATION // HaliQuerySystemInformation -> HalpFwBootPerformanceTable, info class 34
	SystemCodeIntegrityVerificationInformation,             // q: SYSTEM_CODEINTEGRITYVERIFICATION_INFORMATION
	SystemFirmwarePartitionInformation,                     // q: SYSTEM_FIRMWARE_PARTITION_INFORMATION // 200
	SystemSpeculationControlInformation,                    // q: SYSTEM_SPECULATION_CONTROL_INFORMATION // (CVE-2017-5715) REDSTONE3 and above.
	SystemDmaGuardPolicyInformation,                        // q: SYSTEM_DMA_GUARD_POLICY_INFORMATION
	SystemEnclaveLaunchControlInformation,                  // q: SYSTEM_ENCLAVE_LAUNCH_CONTROL_INFORMATION
	SystemWorkloadAllowedCpuSetsInformation,                // q: SYSTEM_WORKLOAD_ALLOWED_CPU_SET_INFORMATION // since REDSTONE5
	SystemCodeIntegrityUnlockModeInformation,               // q: SYSTEM_CODEINTEGRITY_UNLOCK_INFORMATION
	SystemLeapSecondInformation,                            // qs: SYSTEM_LEAP_SECOND_INFORMATION // (s: requires SeSystemtimePrivilege)
	SystemFlags2Information,                                // q: SYSTEM_FLAGS_INFORMATION // (s: requires SeDebugPrivilege)
	SystemSecurityModelInformation,                         // q: SYSTEM_SECURITY_MODEL_INFORMATION // since 19H1
	SystemCodeIntegritySyntheticCacheInformation,           // qs: NtQuerySystemInformationEx
	SystemFeatureConfigurationInformation,                  // q: in: SYSTEM_FEATURE_CONFIGURATION_QUERY, out: SYSTEM_FEATURE_CONFIGURATION_INFORMATION; s: SYSTEM_FEATURE_CONFIGURATION_UPDATE // NtQuerySystemInformationEx // since 20H1 // 210
	SystemFeatureConfigurationSectionInformation,           // q: in: SYSTEM_FEATURE_CONFIGURATION_SECTIONS_REQUEST, out: SYSTEM_FEATURE_CONFIGURATION_SECTIONS_INFORMATION // NtQuerySystemInformationEx
	SystemFeatureUsageSubscriptionInformation,              // q: SYSTEM_FEATURE_USAGE_SUBSCRIPTION_DETAILS; s: SYSTEM_FEATURE_USAGE_SUBSCRIPTION_UPDATE
	SystemSecureSpeculationControlInformation,              // q: SECURE_SPECULATION_CONTROL_INFORMATION
	SystemSpacesBootInformation,                            // q: SYSTEM_SPACES_BOOT_INFORMATION // variable-length opaque blob copied from ExpSpacesBootInformation (kernel mode only) // since 20H2
	SystemFwRamdiskInformation,                             // q: SYSTEM_FIRMWARE_RAMDISK_INFORMATION
	SystemWheaIpmiHardwareInformation,                      // q: SYSTEM_WHEA_IPMI_HARDWARE_INFORMATION
	SystemDifSetRuleClassInformation,                       // s: SYSTEM_DIF_VOLATILE_INFORMATION (requires SeDebugPrivilege)
	SystemDifClearRuleClassInformation,                     // s: NULL (requires SeDebugPrivilege)
	SystemDifApplyPluginVerificationOnDriver,               // q: SYSTEM_DIF_PLUGIN_DRIVER_INFORMATION (requires SeDebugPrivilege)
	SystemDifRemovePluginVerificationOnDriver,              // q: SYSTEM_DIF_PLUGIN_DRIVER_INFORMATION (requires SeDebugPrivilege) // 220
	SystemShadowStackInformation,                           // q: SYSTEM_SHADOW_STACK_INFORMATION
	SystemBuildVersionInformation,                          // q: in: SYSTEM_BUILD_VERSION_INFORMATION_INPUT, out: SYSTEM_BUILD_VERSION_INFORMATION // NtQuerySystemInformationEx // CmQueryBuildVersionInformation
	SystemPoolLimitInformation,                             // q: SYSTEM_POOL_LIMIT_INFORMATION (requires SeIncreaseQuotaPrivilege) // NtQuerySystemInformationEx
	SystemCodeIntegrityAddDynamicStore,                     // q: SYSTEM_CODE_INTEGRITY_DYNAMIC_STORE // CodeIntegrity-AllowConfigurablePolicy-CustomKernelSigners
	SystemCodeIntegrityClearDynamicStores,                  // q: SYSTEM_CODE_INTEGRITY_DYNAMIC_STORE // CodeIntegrity-AllowConfigurablePolicy-CustomKernelSigners
	SystemDifPoolTrackingInformation,                       // s: SYSTEM_DIF_POOL_TRACKING_INFORMATION (requires SeDebugPrivilege)
	SystemPoolZeroingInformation,                           // q: SYSTEM_POOL_ZEROING_INFORMATION
	SystemDpcWatchdogInformation,                           // qs: SYSTEM_DPC_WATCHDOG_CONFIGURATION_INFORMATION
	SystemDpcWatchdogInformation2,                          // qs: SYSTEM_DPC_WATCHDOG_CONFIGURATION_INFORMATION_V2
	SystemSupportedProcessorArchitectures2,                 // q: in opt: HANDLE, out: SYSTEM_SUPPORTED_PROCESSOR_ARCHITECTURES_INFORMATION[] // NtQuerySystemInformationEx // 230
	SystemSingleProcessorRelationshipInformation,           // q: SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX // (EX in: PROCESSOR_NUMBER Processor) // NtQuerySystemInformationEx
	SystemXfgCheckFailureInformation,                       // q: SYSTEM_XFG_FAILURE_INFORMATION
	SystemIommuStateInformation,                            // q: SYSTEM_IOMMU_STATE_INFORMATION // since 22H1
	SystemHypervisorMinrootInformation,                     // q: SYSTEM_HYPERVISOR_MINROOT_INFORMATION
	SystemHypervisorBootPagesInformation,                   // q: SYSTEM_HYPERVISOR_BOOT_PAGES_INFORMATION
	SystemPointerAuthInformation,                           // q: SYSTEM_POINTER_AUTH_INFORMATION
	SystemSecureKernelDebuggerInformation,                  // q: in: SYSTEM_SECURE_KERNEL_DEBUGGER_INFORMATION_INPUT, out: SYSTEM_SECURE_KERNEL_DEBUGGER_INFORMATION // NtQuerySystemInformationEx // kernel mode only on this build
	SystemOriginalImageFeatureInformation,                  // q: in: SYSTEM_ORIGINAL_IMAGE_FEATURE_INFORMATION_INPUT, out: SYSTEM_ORIGINAL_IMAGE_FEATURE_INFORMATION_OUTPUT // NtQuerySystemInformationEx
	SystemMemoryNumaInformation,                            // q: SYSTEM_MEMORY_NUMA_INFORMATION_INPUT, SYSTEM_MEMORY_NUMA_INFORMATION_OUTPUT // NtQuerySystemInformationEx
	SystemMemoryNumaPerformanceInformation,                 // q: SYSTEM_MEMORY_NUMA_PERFORMANCE_INFORMATION_INPUT, SYSTEM_MEMORY_NUMA_PERFORMANCE_INFORMATION_OUTPUT // since 24H2 // 240
	SystemCodeIntegritySignedPoliciesFullInformation,       // qs: SYSTEM_CODE_INTEGRITY_SIGNED_POLICIES // NtQuerySystemInformationEx
	SystemSecureCoreInformation,                            // qs: SYSTEM_SECURE_CORE_INFORMATION // SystemSecureSecretsInformation
	SystemTrustedAppsRuntimeInformation,                    // q: SYSTEM_TRUSTEDAPPS_RUNTIME_INFORMATION
	SystemBadPageInformationEx,                             // q: SYSTEM_BAD_PAGE_INFORMATION
	SystemResourceDeadlockTimeout,                          // q: ULONG
	SystemBreakOnContextUnwindFailureInformation,           // q: ULONG (requires SeDebugPrivilege)
	SystemOslRamdiskInformation,                            // q: SYSTEM_OSL_RAMDISK_INFORMATION
	SystemCodeIntegrityPolicyManagementInformation,         // q: SYSTEM_CODEINTEGRITYPOLICY_MANAGEMENT // since 25H2
	SystemMemoryNumaCacheInformation,                       // q: SYSTEM_MEMORY_NUMA_CACHE_INFORMATION
	SystemProcessorFeaturesBitMapInformation,               // q: ULONG64[2] // RTL_BITMAP_EX // RtlInitializeBitMapEx // 250
	SystemRefTraceInformationEx,                            // q: SYSTEM_REF_TRACE_INFORMATION_EX
	SystemBasicProcessInformation,                          // q: SYSTEM_BASICPROCESS_INFORMATION
	SystemHandleCountInformation,                           // q: SYSTEM_HANDLECOUNT_INFORMATION
	SystemRuntimeAttestationReport,                         // q: SYSTEM_RUNTIME_REPORT_INPUT
	SystemPoolTagInformation2,                              // q: SYSTEM_POOLTAG_INFORMATION2 // since 26H1
	SystemCodeIntegrityEndpointSecurityInformation,         // q: SYSTEM_CODE_INTEGRITY_ENDPOINT_SECURITY_INFORMATION
	MaxSystemInfoClass
} SYSTEM_INFORMATION_CLASS;

// ░░░ Loader API ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

boolean_t InitializeNtDll();
extern Handle NtDllBaseAddress;

boolean_t LoadNtClose();
boolean_t LoadNtOpenFile();
boolean_t LoadNtReadFile();
boolean_t LoadNtWriteFile();
boolean_t LoadNtCreateFile();

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
boolean_t LoadNtYieldExecution();
boolean_t LoadNtTerminateThread();
boolean_t LoadNtGetContextThread();
boolean_t LoadNtSetContextThread();
boolean_t LoadNtAlertResumeThread();
boolean_t LoadNtSetInformationThread();
boolean_t LoadNtSetInformationProcess();
boolean_t LoadNtQuerySystemInformation();

boolean_t LoadNtOpenSection();
boolean_t LoadNtCreateSection();
boolean_t LoadNtMapViewOfSection();
boolean_t LoadNtUnmapViewOfSection();

boolean_t LoadLdrLoadDll();
boolean_t LoadLdrUnloadDll();
boolean_t LoadNtDelayExecution();
boolean_t LoadLdrGetDllHandleEx();
boolean_t LoadNtTerminateProcess();
boolean_t LoadNtFreeVirtualMemory();
boolean_t LoadNtWaitForSingleObject();
boolean_t LoadNtProtectVirtualMemory();
boolean_t LoadNtAllocateVirtualMemory();

boolean_t LoadRtlUnicodeToUTF8N();
boolean_t LoadRtlTimeToTimeFields();

boolean_t Load__C_specific_handler();
boolean_t LoadRtlAddVectoredContinueHandler();
boolean_t LoadRtlSetUnhandledExceptionFilter();
boolean_t LoadRtlAddVectoredExceptionHandler();
boolean_t LoadRtlRemoveVectoredContinueHandler();
boolean_t LoadRtlRemoveVectoredExceptionHandler();

// ░░░ Callbacks / Parameter Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://ntdoc.m417z.com/io_apc_routine
typedef void (*io_apc_routine_t)(void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, uint32_t Reserved);

// https://ntdoc.m417z.com/io_apc_routine
typedef EXCEPTION_DISPOSITION(*exception_routine_t)(EXCEPTION_RECORD *ExceptionRecord, void *EstablisherFrame, CONTEXT *ContextRecord, void *DispatcherContext);

// https://ntdoc.m417z.com/rtlp_unhandled_exception_filter
// https://learn.microsoft.com/en-us/windows/win32/api/winnt/nc-winnt-pvectored_exception_handler
typedef int32_t(*exception_handler_t)(EXCEPTION_POINTERS *ExceptionInfo);

// ░░░ NtXxx Function Typedefs ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// https://learn.microsoft.com/en-us/windows/win32/devnotes/--c-specific-handler2
typedef EXCEPTION_DISPOSITION(*__C_specific_handler_t)(EXCEPTION_RECORD *ExceptionRecord, void *EstablisherFrame, CONTEXT *ContextRecord, DISPATCHER_CONTEXT *DispatcherContext);

// https://ntdoc.m417z.com/rtlsetunhandledexceptionfilter
typedef void (*RtlSetUnhandledExceptionFilter_t)(exception_handler_t UnhandledExceptionFilter);

// https://ntdoc.m417z.com/rtladdvectoredexceptionhandler
typedef void *(*RtlAddVectoredExceptionHandler_t)(bool_t First, exception_handler_t Handler);

// https://ntdoc.m417z.com/rtladdvectoredcontinuehandler
typedef void *(*RtlAddVectoredContinueHandler_t)(bool_t First, exception_handler_t Handler);

// https://ntdoc.m417z.com/rtlremovevectoredcontinuehandler
typedef int32_t(*RtlRemoveVectoredContinueHandler_t)(exception_handler_t Handler);

// https://ntdoc.m417z.com/rtlremovevectoredexceptionhandler
typedef int32_t(*RtlRemoveVectoredExceptionHandler_t)(exception_handler_t Handler);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatesection
typedef NtStatus(*NtCreateSection_t)(Handle *SectionHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, uint64_t *MaximumSize, uint32_t SectionPageProtection, uint32_t AllocationAttributes, Handle FileHandle);

// https://ntdoc.m417z.com/ntopensection
typedef NtStatus(*NtOpenSection_t)(Handle *SectionHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes);

// https://ntdoc.m417z.com/ntmapviewofsection
typedef NtStatus(*NtMapViewOfSection_t)(Handle SectionHandle, Handle ProcessHandle, void **BaseAddress, uint64_t ZeroBits, uint64_t CommitSize, uint64_t *SectionOffset, uint64_t *ViewSize, SECTION_INHERIT InheritDisposition, uint32_t AllocationType, uint32_t PageProtection);

// https://ntdoc.m417z.com/ntunmapviewofsection
typedef NtStatus(*NtUnmapViewOfSection_t)(Handle ProcessHandle, void *BaseAddress);

// https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntquerysysteminformation
typedef NtStatus(*NtQuerySystemInformation_t)(SYSTEM_INFORMATION_CLASS SystemInformationClass, void *SystemInformation, uint32_t SystemInformationLength, uint32_t *ReturnLength);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose
typedef NtStatus(*NtClose_t)(Handle Handle);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile
typedef NtStatus(*NtCreateFile_t)(Handle *FileHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, IO_STATUS_BLOCK *IoStatusBlock, uint64_t *AllocationSize, uint32_t FileAttributes, uint32_t ShareAccess, uint32_t CreateDisposition, uint32_t CreateOptions, void* EaBuffer, uint32_t EaLength);

// https://ntdoc.m417z.com/ntprotectvirtualmemory
typedef NtStatus(*NtProtectVirtualMemory_t)(Handle ProcessHandle, void **BaseAddress, uint64_t *RegionSize, uint32_t NewProtection, uint32_t *OldProtection);

// https://ntdoc.m417z.com/ldrgetdllhandleex
typedef NtStatus(*LdrGetDllHandleEx_t)(uint32_t Flags, wchar_t *DllPath, uint32_t *DllCharacteristics, UNICODE_STRING *DllName, Handle *DllHandle);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryobject
typedef NtStatus(*NtQueryObject_t)(Handle Handle, OBJECT_INFORMATION_CLASS ObjectInformationClass, void *ObjectInformation, uint32_t ObjectInformationLength, uint32_t *ReturnLength);

// https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntdeviceiocontrolfile
typedef NtStatus(*NtDeviceIoControlFile_t)(Handle FileHandle, Handle Event, io_apc_routine_t ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, uint32_t IoControlCode, void *InputBuffer, uint32_t InputBufferLength, void *OutputBuffer, uint32_t OutputBufferLength);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile
typedef NtStatus(*NtQueryInformationFile_t)(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile
typedef NtStatus(*NtSetInformationFile_t)(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass);

// https://learn.microsoft.com/de-de/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile
typedef NtStatus(*NtOpenFile_t)(Handle *FileHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, IO_STATUS_BLOCK *IoStatusBlock, uint32_t ShareAccess, uint32_t OpenOptions);

// https://ntdoc.m417z.com/ldrloaddll
typedef NtStatus(*LdrLoadDll_t)(wchar_t const *DllPath, uint32_t *DllCharacteristics, UNICODE_STRING const *DllName, Handle *DllHandle);

// https://ntdoc.m417z.com/ldrunloaddll
typedef NtStatus(*LdrUnloadDll_t)(Handle DllHandle);

// https://ntdoc.m417z.com/ntcreatethreadex
typedef NtStatus(*NtCreateThreadEx_t)(Handle *ThreadHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, Handle ProcessHandle, NtStatus(*StartRoutine)(void *), void *Argument, uint32_t CreateFlags, uint64_t ZeroSize, uint64_t StackSize, uint64_t MaximumStackSize, PS_ATTRIBUTE_LIST *AttributeList);

// https://ntdoc.m417z.com/ntresumethread
typedef NtStatus(*NtResumeThread_t)(Handle ThreadHandle, uint32_t *PreviousSuspendCount);

// https://ntdoc.m417z.com/ntalertresumethread
typedef NtStatus(*NtAlertResumeThread_t)(Handle ThreadHandle, uint32_t *PreviousSuspendCount);

// https://ntdoc.m417z.com/ntgetcontextthread
typedef NtStatus(*NtGetContextThread_t)(Handle ThreadHandle, CONTEXT *ThreadContext);

// https://ntdoc.m417z.com/ntsetcontextthread
typedef NtStatus(*NtSetContextThread_t)(Handle ThreadHandle, CONTEXT *ThreadContext);

// https://ntdoc.m417z.com/ntsuspendthread
typedef NtStatus(*NtSuspendThread_t)(Handle ThreadHandle, uint32_t *PreviousSuspendCount);

// https://ntdoc.m417z.com/ntalertthread
typedef NtStatus(*NtAlertThread_t)(Handle ThreadHandle);

// https://ntdoc.m417z.com/ntyieldexecution
typedef NtStatus(*NtYieldExecution_t)();

// https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ntwaitforsingleobject
typedef NtStatus(*NtWaitForSingleObject_t)(Handle Handle, boolean_t Alertable, uint64_t *Timeout);

// https://ntdoc.m417z.com/ntdelayexecution
typedef NtStatus(*NtDelayExecution_t)(boolean_t Alertable, int64_t *DelayInterval);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtltimetotimefields
typedef void(*RtlTimeToTimeFields_t)(uint64_t *Time, TIME_FIELDS *TimeFields);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodetoutf8n
typedef NtStatus(*RtlUnicodeToUTF8N_t)(char_t *UTF8StringDestination, uint32_t UTF8StringMaxByteCount, uint32_t *UTF8StringActualByteCount, wchar_t const *UnicodeStringSource, uint32_t UnicodeStringByteCount);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntwritefile
typedef NtStatus(*NtWriteFile_t)(Handle FileHandle, Handle Event, io_apc_routine_t ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key);

// https://learn.microsoft.com/en-us/windows/win32/devnotes/ntreadfile
typedef NtStatus(*NtReadFile_t)(Handle FileHandle, Handle Event, io_apc_routine_t ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key);

// https://ntdoc.m417z.com/ntterminateprocess
typedef NtStatus(*NtTerminateProcess_t)(Handle ProcessHandle, NtStatus ExitStatus);

// https://ntdoc.m417z.com/ntterminatethread
typedef NtStatus(*NtTerminateThread_t)(Handle ThreadHandle, NtStatus ExitStatus);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationthread
typedef NtStatus(*NtSetInformationThread_t)(Handle ThreadHandle, THREADINFOCLASS ThreadInformationClass, void *ThreadInformation, uint32_t ThreadInformationLength);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationtoken
typedef NtStatus(*NtQueryInformationToken_t)(Handle TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, void *TokenInformation, uint32_t TokenInformationLength, uint32_t *ReturnLength);

// // https://ntdoc.m417z.com/ntsetinformationprocess
typedef NtStatus(*NtSetInformationProcess_t)(Handle ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, void *ProcessInformation, uint32_t ProcessInformationLength);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenprocesstoken
typedef NtStatus(*NtOpenProcessToken_t)(Handle ProcessHandle, uint32_t DesiredAccess, Handle *TokenHandle);

// https://ntdoc.m417z.com/ntadjustprivilegestoken
typedef NtStatus(*NtAdjustPrivilegesToken_t)(Handle TokenHandle, boolean_t DisableAllPrivileges, TOKEN_PRIVILEGES *NewState, uint32_t BufferLength, TOKEN_PRIVILEGES *PreviousState, uint32_t *ReturnLength);

// https://ntdoc.m417z.com/ldrgetprocedureaddressex
typedef NtStatus(*LdrGetProcedureAddressEx_t)(Handle DllHandle, STRING const *ProcedureName, uint32_t ProcedureNumber, void **ProcedureAddress, uint32_t Flags);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntallocatevirtualmemory
typedef NtStatus(*NtAllocateVirtualMemory_t)(Handle ProcessHandle, void **BaseAddress, uint64_t ZeroBits, uint64_t *RegionSize, uint32_t AllocationType, uint32_t Protect);

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntfreevirtualmemory
typedef NtStatus(*NtFreeVirtualMemory_t)(Handle ProcessHandle, void **BaseAddress, uint64_t *RegionSize, uint32_t FreeType);

// ░░░ Callable Grouped ntdll Functions ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

struct NtDllFunctions
{
	NtClose_t NtClose;
	NtOpenFile_t NtOpenFile;
	LdrLoadDll_t LdrLoadDll;
	NtReadFile_t NtReadFile;
	NtWriteFile_t NtWriteFile;
	LdrUnloadDll_t LdrUnloadDll;
	NtCreateFile_t NtCreateFile;
	NtAlertThread_t NtAlertThread;
	NtOpenSection_t NtOpenSection;
	NtQueryObject_t NtQueryObject;
	NtResumeThread_t NtResumeThread;
	NtCreateSection_t NtCreateSection;
	NtSuspendThread_t NtSuspendThread;
	NtYieldExecution_t NtYieldExecution;
	NtCreateThreadEx_t NtCreateThreadEx;
	NtDelayExecution_t NtDelayExecution;
	LdrGetDllHandleEx_t LdrGetDllHandleEx;
	NtTerminateThread_t NtTerminateThread;
	RtlUnicodeToUTF8N_t RtlUnicodeToUTF8N;
	NtGetContextThread_t NtGetContextThread;
	NtMapViewOfSection_t NtMapViewOfSection;
	NtSetContextThread_t NtSetContextThread;
	NtTerminateProcess_t NtTerminateProcess;
	NtOpenProcessToken_t NtOpenProcessToken;
	NtAlertResumeThread_t NtAlertResumeThread;
	NtFreeVirtualMemory_t NtFreeVirtualMemory;
	RtlTimeToTimeFields_t RtlTimeToTimeFields;
	__C_specific_handler_t __C_specific_handler;
	NtSetInformationFile_t NtSetInformationFile;
	NtUnmapViewOfSection_t NtUnmapViewOfSection;
	NtDeviceIoControlFile_t NtDeviceIoControlFile;
	NtWaitForSingleObject_t NtWaitForSingleObject;
	NtProtectVirtualMemory_t NtProtectVirtualMemory;
	NtQueryInformationFile_t NtQueryInformationFile;
	NtSetInformationThread_t NtSetInformationThread;
	NtAdjustPrivilegesToken_t NtAdjustPrivilegesToken;
	NtAllocateVirtualMemory_t NtAllocateVirtualMemory;
	NtQueryInformationToken_t NtQueryInformationToken;
	NtSetInformationProcess_t NtSetInformationProcess;
	NtQuerySystemInformation_t NtQuerySystemInformation;
	LdrGetProcedureAddressEx_t LdrGetProcedureAddressEx;
	RtlAddVectoredContinueHandler_t RtlAddVectoredContinueHandler;
	RtlSetUnhandledExceptionFilter_t RtlSetUnhandledExceptionFilter;
	RtlAddVectoredExceptionHandler_t RtlAddVectoredExceptionHandler;
	RtlRemoveVectoredContinueHandler_t RtlRemoveVectoredContinueHandler;
	RtlRemoveVectoredExceptionHandler_t RtlRemoveVectoredExceptionHandler;
};

extern struct NtDllFunctions NtDll;

// ░░░ Wrap to normal Function ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

static __forceinline NtStatus NtClose(Handle Handle) { return NtDll.NtClose(Handle); }
static __forceinline NtStatus NtOpenFile(Handle *FileHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, IO_STATUS_BLOCK *IoStatusBlock, uint32_t ShareAccess, uint32_t OpenOptions) { return NtDll.NtOpenFile(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, ShareAccess, OpenOptions); }
static __forceinline NtStatus NtReadFile(Handle FileHandle, Handle Event, io_apc_routine_t ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key) { return NtDll.NtReadFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key); }
static __forceinline NtStatus NtWriteFile(Handle FileHandle, Handle Event, io_apc_routine_t ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, void *Buffer, uint32_t Length, uint64_t *ByteOffset, uint32_t *Key) { return NtDll.NtWriteFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key); }
static __forceinline NtStatus NtCreateFile(Handle *FileHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, IO_STATUS_BLOCK *IoStatusBlock, uint64_t *AllocationSize, uint32_t FileAttributes, uint32_t ShareAccess, uint32_t CreateDisposition, uint32_t CreateOptions, void *EaBuffer, uint32_t EaLength) { return NtDll.NtCreateFile(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, AllocationSize, FileAttributes, ShareAccess, CreateDisposition, CreateOptions, EaBuffer, EaLength); }

static __forceinline NtStatus NtQueryObject(Handle Handle, OBJECT_INFORMATION_CLASS ObjectInformationClass, void *ObjectInformation, uint32_t ObjectInformationLength, uint32_t *ReturnLength) { return NtDll.NtQueryObject(Handle, ObjectInformationClass, ObjectInformation, ObjectInformationLength, ReturnLength); }
static __forceinline NtStatus NtDeviceIoControlFile(Handle FileHandle, Handle Event, io_apc_routine_t ApcRoutine, void *ApcContext, IO_STATUS_BLOCK *IoStatusBlock, uint32_t IoControlCode, void *InputBuffer, uint32_t InputBufferLength, void *OutputBuffer, uint32_t OutputBufferLength) { return NtDll.NtDeviceIoControlFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, IoControlCode, InputBuffer, InputBufferLength, OutputBuffer, OutputBufferLength); }
static __forceinline NtStatus NtSetInformationFile(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass) { return NtDll.NtSetInformationFile(FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass); }
static __forceinline NtStatus NtQueryInformationFile(Handle FileHandle, IO_STATUS_BLOCK *IoStatusBlock, void *FileInformation, uint32_t Length, FILE_INFORMATION_CLASS FileInformationClass) { return NtDll.NtQueryInformationFile(FileHandle, IoStatusBlock, FileInformation, Length, FileInformationClass); }

static __forceinline NtStatus NtOpenProcessToken(Handle ProcessHandle, uint32_t DesiredAccess, Handle *TokenHandle) { return NtDll.NtOpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle); }
static __forceinline NtStatus NtAdjustPrivilegesToken(Handle TokenHandle, boolean_t DisableAllPrivileges, TOKEN_PRIVILEGES* NewState, uint32_t BufferLength, TOKEN_PRIVILEGES* PreviousState, uint32_t* ReturnLength) { return NtDll.NtAdjustPrivilegesToken(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength); }
static __forceinline NtStatus NtQueryInformationToken(Handle TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, void *TokenInformation, uint32_t TokenInformationLength, uint32_t *ReturnLength) { return NtDll.NtQueryInformationToken(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength, ReturnLength); }

static __forceinline NtStatus NtAlertThread(Handle ThreadHandle) { return NtDll.NtAlertThread(ThreadHandle); }
static __forceinline NtStatus NtResumeThread(Handle ThreadHandle, uint32_t *PreviousSuspendCount) { return NtDll.NtResumeThread(ThreadHandle, PreviousSuspendCount); }
static __forceinline NtStatus NtSuspendThread(Handle ThreadHandle, uint32_t *PreviousSuspendCount) { return NtDll.NtSuspendThread(ThreadHandle, PreviousSuspendCount); }
static __forceinline NtStatus NtYieldExecution() { return NtDll.NtYieldExecution(); }
static __forceinline NtStatus NtCreateThreadEx(Handle *ThreadHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, Handle ProcessHandle, NtStatus(*StartRoutine)(void *), void *Argument, uint32_t CreateFlags, uint64_t ZeroSize, uint64_t StackSize, uint64_t MaximumStackSize, PS_ATTRIBUTE_LIST *AttributeList) { return NtDll.NtCreateThreadEx(ThreadHandle, DesiredAccess, ObjectAttributes, ProcessHandle, StartRoutine, Argument, CreateFlags, ZeroSize, StackSize, MaximumStackSize, AttributeList); }
static __forceinline NtStatus NtTerminateThread(Handle ThreadHandle, NtStatus ExitStatus) { return NtDll.NtTerminateThread(ThreadHandle, ExitStatus); }
static __forceinline NtStatus NtGetContextThread(Handle ThreadHandle, CONTEXT *ThreadContext) { return NtDll.NtGetContextThread(ThreadHandle, ThreadContext); }
static __forceinline NtStatus NtSetContextThread(Handle ThreadHandle, CONTEXT *ThreadContext) { return NtDll.NtSetContextThread(ThreadHandle, ThreadContext); }
static __forceinline NtStatus NtAlertResumeThread(Handle ThreadHandle, uint32_t *PreviousSuspendCount) { return NtDll.NtAlertResumeThread(ThreadHandle, PreviousSuspendCount); }
static __forceinline NtStatus NtSetInformationThread(Handle ThreadHandle, THREADINFOCLASS ThreadInformationClass, void *ThreadInformation, uint32_t ThreadInformationLength) { return NtDll.NtSetInformationThread(ThreadHandle, ThreadInformationClass, ThreadInformation, ThreadInformationLength); }
static __forceinline NtStatus NtSetInformationProcess(Handle ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, void *ProcessInformation, uint32_t ProcessInformationLength) { return NtDll.NtSetInformationProcess(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength); }
static __forceinline NtStatus NtQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, void *SystemInformation, uint32_t SystemInformationLength, uint32_t *ReturnLength) { return NtDll.NtQuerySystemInformation(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength); }

static __forceinline NtStatus NtOpenSection(Handle *SectionHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes) { return NtDll.NtOpenSection(SectionHandle, DesiredAccess, ObjectAttributes); }
static __forceinline NtStatus NtCreateSection(Handle *SectionHandle, uint32_t DesiredAccess, OBJECT_ATTRIBUTES *ObjectAttributes, uint64_t *MaximumSize, uint32_t SectionPageProtection, uint32_t AllocationAttributes, Handle FileHandle) { return NtDll.NtCreateSection(SectionHandle, DesiredAccess, ObjectAttributes, MaximumSize, SectionPageProtection, AllocationAttributes, FileHandle); }
static __forceinline NtStatus NtMapViewOfSection(Handle SectionHandle, Handle ProcessHandle, void **BaseAddress, uint64_t ZeroBits, uint64_t CommitSize, uint64_t *SectionOffset, uint64_t *ViewSize, SECTION_INHERIT InheritDisposition, uint32_t AllocationType, uint32_t PageProtection) { return NtDll.NtMapViewOfSection(SectionHandle, ProcessHandle, BaseAddress, ZeroBits, CommitSize, SectionOffset, ViewSize, InheritDisposition, AllocationType, PageProtection); }
static __forceinline NtStatus NtUnmapViewOfSection(Handle ProcessHandle, void *BaseAddress) { return NtDll.NtUnmapViewOfSection(ProcessHandle, BaseAddress); }

static __forceinline NtStatus LdrLoadDll(wchar_t const *DllPath, uint32_t *DllCharacteristics, UNICODE_STRING const *DllName, Handle *DllHandle) { return NtDll.LdrLoadDll(DllPath, DllCharacteristics, DllName, DllHandle); }
static __forceinline NtStatus LdrUnloadDll(Handle DllHandle) { return NtDll.LdrUnloadDll(DllHandle); }
static __forceinline NtStatus NtDelayExecution(boolean_t Alertable, int64_t *DelayInterval) { return NtDll.NtDelayExecution(Alertable, DelayInterval); }
static __forceinline NtStatus LdrGetDllHandleEx(uint32_t Flags, wchar_t *DllPath, uint32_t *DllCharacteristics, UNICODE_STRING *DllName, Handle *DllHandle) { return NtDll.LdrGetDllHandleEx(Flags, DllPath, DllCharacteristics, DllName, DllHandle); }
static __forceinline NtStatus NtTerminateProcess(Handle ProcessHandle, NtStatus ExitStatus) { return NtDll.NtTerminateProcess(ProcessHandle, ExitStatus); }
static __forceinline NtStatus NtFreeVirtualMemory(Handle ProcessHandle, void **BaseAddress, uint64_t *RegionSize, uint32_t FreeType) { return NtDll.NtFreeVirtualMemory(ProcessHandle, BaseAddress, RegionSize, FreeType); }
static __forceinline NtStatus NtWaitForSingleObject(Handle Handle, boolean_t Alertable, uint64_t *Timeout) { return NtDll.NtWaitForSingleObject(Handle, Alertable, Timeout); }
static __forceinline NtStatus NtProtectVirtualMemory(Handle ProcessHandle, void **BaseAddress, uint64_t *RegionSize, uint32_t NewProtection, uint32_t *OldProtection) { return NtDll.NtProtectVirtualMemory(ProcessHandle, BaseAddress, RegionSize, NewProtection, OldProtection); }
static __forceinline NtStatus NtAllocateVirtualMemory(Handle ProcessHandle, void **BaseAddress, uint64_t ZeroBits, uint64_t *RegionSize, uint32_t AllocationType, uint32_t Protect) { return NtDll.NtAllocateVirtualMemory(ProcessHandle, BaseAddress, ZeroBits, RegionSize, AllocationType, Protect); }
static __forceinline NtStatus LdrGetProcedureAddressEx(Handle DllHandle, STRING const *ProcedureName, uint32_t ProcedureNumber, void **ProcedureAddress, uint32_t Flags) { return NtDll.LdrGetProcedureAddressEx(DllHandle, ProcedureName, ProcedureNumber, ProcedureAddress, Flags); }

static __forceinline void RtlTimeToTimeFields(uint64_t *Time, TIME_FIELDS *TimeFields) { NtDll.RtlTimeToTimeFields(Time, TimeFields); }
static __forceinline NtStatus RtlUnicodeToUTF8N(char_t *UTF8StringDestination, uint32_t UTF8StringMaxByteCount, uint32_t * UTF8StringActualByteCount, wchar_t const *UnicodeStringSource, uint32_t UnicodeStringByteCount) { return NtDll.RtlUnicodeToUTF8N(UTF8StringDestination, UTF8StringMaxByteCount, UTF8StringActualByteCount, UnicodeStringSource, UnicodeStringByteCount); }

static __forceinline void RtlSetUnhandledExceptionFilter(exception_handler_t UnhandledExceptionFilter) { NtDll.RtlSetUnhandledExceptionFilter(UnhandledExceptionFilter); }
static __forceinline void *RtlAddVectoredContinueHandler(bool_t First, exception_handler_t Handler) { return NtDll.RtlAddVectoredContinueHandler(First, Handler); }
static __forceinline void *RtlAddVectoredExceptionHandler(bool_t First, exception_handler_t Handler) { return NtDll.RtlAddVectoredExceptionHandler(First, Handler); }
static __forceinline int32_t RtlRemoveVectoredContinueHandler(exception_handler_t Handler) { return NtDll.RtlRemoveVectoredContinueHandler(Handler); }
static __forceinline int32_t RtlRemoveVectoredExceptionHandler(exception_handler_t Handler) { return NtDll.RtlRemoveVectoredExceptionHandler(Handler); }

// ░░░ Normal implementations ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

EXCEPTION_DISPOSITION __C_specific_handler(EXCEPTION_RECORD *ExceptionRecord, void *EstablisherFrame, CONTEXT *ContextRecord, DISPATCHER_CONTEXT *DispatcherContext);