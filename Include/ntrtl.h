#pragma once
#include "ntbase.h"

#include <wchar.h>
#include <stdarg.h>

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
// RtlStringXXXX
//

enum NTSTRSAFE_MAX : INT32
{
    NTSTRSAFE_MAX_CCH = MAX_INT32,
};

static __inline NTSTATUS __stdcall RtlStringVPrintfWorkerW(
    PWSTR pszDest,
    size_t cchDest,
    size_t* pcchNewDestLength,
    PCWSTR pszFormat,
    va_list argList)
{
    NTSTATUS status = STATUS_SUCCESS;
    int iRet = 0;
    size_t cchMax = 0;
    size_t cchNewDestLength = 0;

    // leave the last space for the null terminator
    cchMax = cchDest - 1;
    iRet = _vsnwprintf_s(pszDest, cchDest, cchMax, pszFormat, argList);
    // ASSERT((iRet < 0) || (((size_t)iRet) <= cchMax));

    if ((iRet < 0) || (((size_t)iRet) > cchMax))
    {
        // need to null terminate the string
        pszDest += cchMax;
        *pszDest = L'\0';

        cchNewDestLength = cchMax;

        // we have truncated pszDest
        status = STATUS_BUFFER_OVERFLOW;
    }
    else if (((size_t)iRet) == cchMax)
    {
        // need to null terminate the string
        pszDest += cchMax;
        *pszDest = L'\0';

        cchNewDestLength = cchMax;
    }
    else
    {
        cchNewDestLength = (size_t)iRet;
    }

    if (pcchNewDestLength)
    {
        *pcchNewDestLength = cchNewDestLength;
    }

    return status;
}

__inline NTSTATUS __stdcall RtlStringCchPrintfW(
    PWSTR pszDest,
    size_t cchDest,
    PCWSTR pszFormat,
    ...)
{
    NTSTATUS status{ STATUS_SUCCESS };

    if ((cchDest == 0) || (cchDest > NTSTRSAFE_MAX_CCH))
    {
        status = STATUS_INVALID_PARAMETER;
    }

    if (NT_SUCCESS(status))
    {
        va_list argList;

        va_start(argList, pszFormat);

        status = RtlStringVPrintfWorkerW(pszDest,
            cchDest,
            NULL,
            pszFormat,
            argList);

        va_end(argList);
    }
    else if (cchDest > 0)
    {
        *pszDest = '\0';
    }

    return status;
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

//
// RtlXXXXString
//

#define RTL_CONSTANT_STRING(s)  \
{ \
    sizeof(s) - sizeof((s)[0]), \
    sizeof(s),                  \
    s                           \
}

extern"C" void RtlInitUnicodeString(
    PUNICODE_STRING DestinationString,
    PCWSTR SourceString);

extern"C" void RtlFreeUnicodeString(PUNICODE_STRING UnicodeString);

//
// RtlXXXXAppContainer
//

extern"C" BOOLEAN RtlIsParentOfChildAppContainer(PSID aParentSid, PSID aChildSid);

extern"C" NTSTATUS RtlGetAppContainerSidType(PSID aSid, UINT32* aSidType);

extern"C" NTSTATUS RtlGetAppContainerParent(PSID aAppContainerSid, PSID* aParentSid);

extern"C" UINT32* RtlSubAuthoritySid(PSID Sid, UINT32 SubAuthority);

//
// RtlXXXSid/Luid/Guid
//

extern"C" UINT32 RtlLengthSid(PSID Sid);

extern"C" BOOLEAN RtlEqualSid(PSID Sid1, PSID Sid2);

extern"C" NTSTATUS RtlConvertSidToUnicodeString(
    PUNICODE_STRING UnicodeString,
    PSID Sid,
    BOOLEAN AllocateDestinationString);

extern"C" NTSTATUS RtlAllocateAndInitializeSid(
    SID_IDENTIFIER_AUTHORITY* IdentifierAuthority,
    UINT8 SubAuthorityCount,
    UINT32 SubAuthority0,
    UINT32 SubAuthority1,
    UINT32 SubAuthority2,
    UINT32 SubAuthority3,
    UINT32 SubAuthority4,
    UINT32 SubAuthority5,
    UINT32 SubAuthority6,
    UINT32 SubAuthority7,
    PSID *Sid);

extern"C" NTSTATUS RtlInitializeSid(
    PSID Sid,
    PSID_IDENTIFIER_AUTHORITY IdentifierAuthority,
    UINT8 SubAuthorityCount);

extern"C" NTSTATUS RtlInitializeSidEx(
    PSID Sid,
    PSID_IDENTIFIER_AUTHORITY IdentifierAuthority,
    UINT8 SubAuthorityCount,
    ...);

extern"C" PSID_IDENTIFIER_AUTHORITY RtlIdentifierAuthoritySid(PSID Sid);

extern"C" UINT32* RtlSubAuthoritySid(PSID Sid, UINT32 SubAuthority);

extern"C" UINT8* RtlSubAuthorityCountSid(PSID Sid);

extern"C" UINT32 RtlLengthSid(
    PSID Sid);

extern"C" NTSTATUS RtlCopySid(
    UINT32 DestinationSidLength,
    PSID DestinationSid,
    PSID SourceSid);

//
// RtlXXXAce
//

extern"C" NTSTATUS RtlAddAce(
    PACL Acl,
    UINT32 AceRevision,
    UINT32 StartingAceIndex,
    void* AceList,
    UINT32 AceListLength);

extern"C" NTSTATUS RtlDeleteAce(
    PACL Acl,
    UINT32 AceIndex);

extern"C" NTSTATUS RtlGetAce(
    PACL Acl,
    UINT32 AceIndex,
    void** Ace);

extern"C" BOOLEAN RtlFirstFreeAce(
    PACL Acl,
    void** FirstFree);

extern"C" NTSTATUS RtlAddAccessAllowedAce(
    PACL Acl, 
    UINT32 AceRevision,
    ACCESS_MASK AccessMask,
    PSID Sid);

extern"C" NTSTATUS RtlAddAccessAllowedAceEx(
    PACL Acl,
    UINT32 AceRevision,
    UINT32 AceFlags,
    ACCESS_MASK AccessMask, 
    PSID Sid);

extern"C" NTSTATUS RtlAddMandatoryAce(
    PACL Acl,
    UINT32 AceRevision,
    UINT32 AceFlags,
    PSID Sid,
    UINT8 AceType,
    ACCESS_MASK AccessMask);

//
// RtlXXXXAcl
//

//
//  The following declarations are used for setting and querying information
//  about and ACL.  First are the various information classes available to
//  the user.
//

enum ACL_INFORMATION_CLASS : UINT32
{
    AclRevisionInformation = 1,
    AclSizeInformation
};

//
//  This record is returned/sent if the user is requesting/setting the
//  AclRevisionInformation
//

typedef struct _ACL_REVISION_INFORMATION {
    UINT32 AclRevision;
} ACL_REVISION_INFORMATION, *PACL_REVISION_INFORMATION;

//
//  This record is returned if the user is requesting AclSizeInformation
//

typedef struct _ACL_SIZE_INFORMATION {
    UINT32 AceCount;
    UINT32 AclBytesInUse;
    UINT32 AclBytesFree;
} ACL_SIZE_INFORMATION, *PACL_SIZE_INFORMATION;

extern"C" NTSTATUS RtlCreateAcl(PACL Acl, UINT32 AclLength, UINT32 AclRevision);

extern"C" NTSTATUS RtlQueryInformationAcl(
    ACL* Acl,
    void* AclInformation,
    UINT32 AclInformationLength,
    ACL_INFORMATION_CLASS AclInformationClass);

//
// RtlXXXXSecurityDescriptor
//

extern"C" NTSTATUS RtlCreateSecurityDescriptor(
    SECURITY_DESCRIPTOR* SecurityDescriptor,
    UINT32 Revision);

extern"C" NTSTATUS RtlGetDaclSecurityDescriptor(
    SECURITY_DESCRIPTOR* SecurityDescriptor,
    BOOLEAN*             DaclPresent,
    ACL*                 *Dacl,
    BOOLEAN*             DaclDefaulted);

extern"C" NTSTATUS RtlSetDaclSecurityDescriptor(
    PSECURITY_DESCRIPTOR SecurityDescriptor, 
    BOOLEAN DaclPresent,
    PACL Dacl, 
    BOOLEAN DaclDefaulted);

extern"C" NTSTATUS RtlSetSaclSecurityDescriptor(
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    BOOLEAN SaclPresent,
    PACL Sacl,
    BOOLEAN SaclDefaulted);

extern"C" NTSTATUS RtlGetSaclSecurityDescriptor(
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    BOOLEAN* SaclPresent,
    PACL *Sacl,
    BOOLEAN* SaclDefaulted);

