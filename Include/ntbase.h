#pragma once
#include <intrin.h>
#include "ntstatus.h"

//////////////////////////////////////////////////////////////////////////

//
// Type definitions for the basic sized types.
//

using HANDLE    = void*;

using INT8      = signed __int8;
using INT16     = signed __int16;
using INT32     = signed __int32;
using INT64     = signed __int64;

using UINT8     = unsigned __int8;
using UINT16    = unsigned __int16;
using UINT32    = unsigned __int32;
using UINT64    = unsigned __int64;

#if defined(_WIN64)

using INT_PTR   = INT64;
using UINT_PTR  = UINT64;

using PTRDIFF   = INT64;
using SIZE_T    = UINT64;

#else

using INT_PTR   = INT32;
using UINT_PTR  = UINT32;

using PTRDIFF   = INT32;
using SIZE_T    = UINT32;

#endif

using PSTR      = char *;
using PCSTR     = const char*;

using PWSTR     = wchar_t *;
using PCWSTR    = const wchar_t *;

enum : UINT32
{
    DOS_MAX_COMPONENT_LENGTH    = 255,
    DOS_MAX_PATH_LENGTH         = DOS_MAX_COMPONENT_LENGTH + 5,
    MAX_PATH                    = DOS_MAX_PATH_LENGTH,
};

using BYTE      = UINT8;

using BOOL      = UINT32;
using BOOLEAN   = bool;

enum : BOOL
{
    FALSE = false,
    TRUE  = true,
};

//////////////////////////////////////////////////////////////////////////

#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#define DUMMYUNIONNAME6
#define DUMMYUNIONNAME7
#define DUMMYUNIONNAME8
#define DUMMYUNIONNAME9

#define DUMMYSTRUCTNAME
#define DUMMYSTRUCTNAME2
#define DUMMYSTRUCTNAME3
#define DUMMYSTRUCTNAME4
#define DUMMYSTRUCTNAME5
#define DUMMYSTRUCTNAME6

#define offsetof(s,m) ((size_t)&reinterpret_cast<char const volatile&>((((s*)0)->m)))

//////////////////////////////////////////////////////////////////////////

using LCID = UINT32;

typedef struct _LUID {
    UINT32 LowPart;
    INT32 HighPart;
} LUID, *PLUID;

typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

typedef struct _ANSI_STRING
{
    UINT16 Length;
    UINT16 MaximumLength;
    PSTR   Buffer;

}ANSI_STRING, STRING, *PANSI_STRING, *PSTRING;

typedef struct _UNICODE_STRING {
    UINT16 Length;
    UINT16 MaximumLength;
    PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY;

typedef union _LARGE_INTEGER {
    struct {
        UINT32 LowPart;
        INT32 HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        UINT32 LowPart;
        INT32 HighPart;
    } u;
    INT64 QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

typedef union _ULARGE_INTEGER {
    struct {
        UINT32 LowPart;
        UINT32 HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        UINT32 LowPart;
        UINT32 HighPart;
    } u;
    INT64 QuadPart;
} ULARGE_INTEGER, *PULARGE_INTEGER;

typedef struct _CLIENT_ID {
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _PROCESSOR_NUMBER {
    UINT16  Group;
    BYTE    Number;
    BYTE    Reserved;
} PROCESSOR_NUMBER, *PPROCESSOR_NUMBER;

typedef struct _KSYSTEM_TIME
{
    UINT32 LowPart;
    INT32 High1Time;
    INT32 High2Time;
} KSYSTEM_TIME, *PKSYSTEM_TIME;

typedef struct _OBJECT_ATTRIBUTES {
    UINT32 Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    UINT32 Attributes;
    void* SecurityDescriptor;
    void* SecurityQualityOfService;
} OBJECT_ATTRIBUTES;
typedef OBJECT_ATTRIBUTES *POBJECT_ATTRIBUTES;

typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        void* Pointer;
    } DUMMYUNIONNAME;

    UINT_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

typedef struct _SECURITY_ATTRIBUTES 
{
    UINT32  nLength;
    void*   lpSecurityDescriptor;
    BOOL    bInheritHandle;
}SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    UINT32 dwProcessId;
    UINT32 dwThreadId;
}PROCESS_INFORMATION, *LPPROCESS_INFORMATION;

typedef struct _STARTUPINFOW {
    UINT32  cb;
    PWSTR   lpReserved;
    PWSTR   lpDesktop;
    PWSTR   lpTitle;
    UINT32  dwX;
    UINT32  dwY;
    UINT32  dwXSize;
    UINT32  dwYSize;
    UINT32  dwXCountChars;
    UINT32  dwYCountChars;
    UINT32  dwFillAttribute;
    UINT32  dwFlags;
    UINT16  wShowWindow;
    UINT16  cbReserved2;
    BYTE*  lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
}STARTUPINFOW, *LPSTARTUPINFOW;

typedef struct _STARTUPINFOEXW {
    STARTUPINFOW StartupInfo;
    struct _PROC_THREAD_ATTRIBUTE_LIST* lpAttributeList;
}STARTUPINFOEXW, *LPSTARTUPINFOEXW;
