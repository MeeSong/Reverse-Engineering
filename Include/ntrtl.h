#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

typedef struct _CURDIR
{
    UNICODE_STRING DosPath;
    HANDLE Handle;
} CURDIR, *PCURDIR;

#define RTL_USER_PROC_CURDIR_CLOSE      0x00000002
#define RTL_USER_PROC_CURDIR_INHERIT    0x00000003

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
    UINT16 Flags;
    UINT16 Length;
    UINT32 TimeStamp;
    STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;

#define RTL_MAX_DRIVE_LETTERS 32
#define RTL_DRIVE_LETTER_VALID (UINT16)0x0001

typedef struct _RTL_USER_PROCESS_PARAMETERS
{
    UINT32 MaximumLength;
    UINT32 Length;

    UINT32 Flags;
    UINT32 DebugFlags;

    HANDLE ConsoleHandle;
    UINT32 ConsoleFlags;
    HANDLE StandardInput;
    HANDLE StandardOutput;
    HANDLE StandardError;

    CURDIR CurrentDirectory;
    UNICODE_STRING DllPath;
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    void* Environment;

    UINT32 StartingX;
    UINT32 StartingY;
    UINT32 CountX;
    UINT32 CountY;
    UINT32 CountCharsX;
    UINT32 CountCharsY;
    UINT32 FillAttribute;

    UINT32 WindowFlags;
    UINT32 ShowWindowFlags;
    UNICODE_STRING WindowTitle;
    UNICODE_STRING DesktopInfo;
    UNICODE_STRING ShellInfo;
    UNICODE_STRING RuntimeData;
    RTL_DRIVE_LETTER_CURDIR CurrentDirectories[RTL_MAX_DRIVE_LETTERS];

    UINT_PTR EnvironmentSize;
    UINT_PTR EnvironmentVersion;
    void* PackageDependencyData;
    UINT32 ProcessGroupId;
    UINT32 LoaderThreads;
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;
static_assert(sizeof(RTL_USER_PROCESS_PARAMETERS) == 0x410, 
    "RTL_USER_PROCESS_PARAMETERS size is wrong!");

#define RTL_USER_PROC_PARAMS_NORMALIZED         0x00000001
#define RTL_USER_PROC_PROFILE_USER              0x00000002
#define RTL_USER_PROC_PROFILE_KERNEL            0x00000004
#define RTL_USER_PROC_PROFILE_SERVER            0x00000008
#define RTL_USER_PROC_RESERVE_1MB               0x00000020
#define RTL_USER_PROC_RESERVE_16MB              0x00000040
#define RTL_USER_PROC_CASE_SENSITIVE            0x00000080
#define RTL_USER_PROC_DISABLE_HEAP_DECOMMIT     0x00000100
#define RTL_USER_PROC_DLL_REDIRECTION_LOCAL     0x00001000
#define RTL_USER_PROC_APP_MANIFEST_PRESENT      0x00002000
#define RTL_USER_PROC_IMAGE_KEY_MISSING         0x00004000
#define RTL_USER_PROC_OPTIN_PROCESS             0x00020000

//////////////////////////////////////////////////////////////////////////

typedef struct _SYSTEMTIME {
    INT16 wYear;
    INT16 wMonth;
    INT16 wDayOfWeek;
    INT16 wDay;
    INT16 wHour;
    INT16 wMinute;
    INT16 wSecond;
    INT16 wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

typedef struct _TIME_ZONE_INFORMATION {
    INT32 Bias;
    wchar_t StandardName[32];
    SYSTEMTIME StandardDate;
    INT32 StandardBias;
    wchar_t DaylightName[32];
    SYSTEMTIME DaylightDate;
    INT32 DaylightBias;
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;


//////////////////////////////////////////////////////////////////////////

__inline void* RtlSecureZeroMemory(void* aPtr, SIZE_T aCount)
{
    volatile char *vPtr = (volatile char *)aPtr;
    __stosb((BYTE*)((UINT64)vPtr), 0, aCount);
    return aPtr;
}

//
// RtlXXXHeap
//

using PRTL_HEAP_COMMIT_ROUTINE = NTSTATUS(*)(
    void* Base,
    void** CommitAddress,
    SIZE_T* CommitSize);

typedef struct _RTL_HEAP_PARAMETERS {
    UINT32 Length;
    SIZE_T SegmentReserve;
    SIZE_T SegmentCommit;
    SIZE_T DeCommitFreeBlockThreshold;
    SIZE_T DeCommitTotalFreeThreshold;
    SIZE_T MaximumAllocationSize;
    SIZE_T VirtualMemoryThreshold;
    SIZE_T InitialCommit;
    SIZE_T InitialReserve;
    PRTL_HEAP_COMMIT_ROUTINE CommitRoutine;
    SIZE_T Reserved[2];
} RTL_HEAP_PARAMETERS, *PRTL_HEAP_PARAMETERS;

extern"C" HANDLE RtlCreateHeap(
    UINT32 Flags,
    void* HeapBase,
    SIZE_T ReserveSize,
    SIZE_T CommitSize,
    void* Lock,
    PRTL_HEAP_PARAMETERS Parameters
);

extern"C" HANDLE RtlDestroyHeap(
    HANDLE HeapHandle
);

extern"C" void* RtlAllocateHeap(
    HANDLE HeapHandle,
    UINT32 Flags,
    SIZE_T Size);


extern"C" BOOLEAN RtlFreeHeap(
    HANDLE HeapHandle,
    UINT32 Flags,
    void* BaseAddress
);

extern"C" SIZE_T RtlSizeHeap(
    HANDLE HeapHandle,
    UINT32 Flags,
    void* BaseAddress
);

extern"C" NTSTATUS RtlZeroHeap(
    HANDLE HeapHandle,
    UINT32 Flags
);

extern"C" void RtlProtectHeap(
    HANDLE HeapHandle,
    BOOLEAN MakeReadOnly
);

#define RtlProcessHeap() (HANDLE(NtCurrentPeb()->ProcessHeap))

extern"C" BOOLEAN RtlLockHeap(
    HANDLE HeapHandle
);

extern"C" BOOLEAN RtlUnlockHeap(
    HANDLE HeapHandle
);

extern"C" void* RtlReAllocateHeap(
    HANDLE HeapHandle,
    UINT32 Flags,
    void* BaseAddress,
    SIZE_T Size
);

//
// RtlSetXXXXError
//

extern"C" DOSERROR __stdcall RtlNtStatusToDosError(NTSTATUS aStatus);
extern"C" void __stdcall RtlSetLastWin32Error(DOSERROR aDosError);
extern"C" NTSTATUS __stdcall RtlGetLastNtStatus(void);
extern"C" DOSERROR __stdcall RtlGetLastWin32Error(void);

//
// RtlAcquirePrivileges
//

enum ACQUIRE_PRIVILEGES_FLAGS : UINT32
{
    RTL_ACQUIRE_PRIVILEGE_NULL,
    RTL_ACQUIRE_PRIVILEGE_IMPERSONATE,
    RTL_ACQUIRE_PRIVILEGE_PROCESS
};

extern"C" NTSTATUS __stdcall RtlAcquirePrivilege(
    UINT32* Privilege,
    UINT32 NumPriv,
    UINT32 Flags,
    void** ReturnedState);


extern"C" void __stdcall RtlReleasePrivilege(void* ReturnedState);

//
// RtlXXXEnvironment
//

enum CREATE_ENVIRONMENT_FLAGS : UINT32
{
    RTL_CREATE_ENVIRONMENT_TRANSLATE = 0x1,             // translate from multi-byte to Unicode
    RTL_CREATE_ENVIRONMENT_TRANSLATE_FROM_OEM = 0x2,    // translate from OEM to Unicode (Translate flag must also be set)
    RTL_CREATE_ENVIRONMENT_EMPTY = 0x4,                 // create empty environment block
};

extern"C" NTSTATUS RtlCreateEnvironmentEx(
    void* SourceEnv,
    void** Environment,
    UINT32 Flags);
extern"C" NTSTATUS RtlDestroyEnvironment(void* Environment);