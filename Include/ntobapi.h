#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

//
// File 
//

enum FILE_ATTRIBUTE : UINT32
{
    FILE_ATTRIBUTE_READONLY = 0x00000001,
    FILE_ATTRIBUTE_HIDDEN = 0x00000002,
    FILE_ATTRIBUTE_SYSTEM = 0x00000004,
    FILE_ATTRIBUTE_DIRECTORY = 0x00000010,
    FILE_ATTRIBUTE_ARCHIVE = 0x00000020,
    FILE_ATTRIBUTE_DEVICE = 0x00000040,
    FILE_ATTRIBUTE_NORMAL = 0x00000080,
    FILE_ATTRIBUTE_TEMPORARY = 0x00000100,
    FILE_ATTRIBUTE_SPARSE_FILE = 0x00000200,
    FILE_ATTRIBUTE_REPARSE_POINT = 0x00000400,
    FILE_ATTRIBUTE_COMPRESSED = 0x00000800,
    FILE_ATTRIBUTE_OFFLINE = 0x00001000,
    FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = 0x00002000,
    FILE_ATTRIBUTE_ENCRYPTED = 0x00004000,
    FILE_ATTRIBUTE_INTEGRITY_STREAM = 0x00008000,
    FILE_ATTRIBUTE_VIRTUAL = 0x00010000,
    FILE_ATTRIBUTE_NO_SCRUB_DATA = 0x00020000,
    FILE_ATTRIBUTE_EA = 0x00040000,

    INVALID_FILE_ATTRIBUTES = -1,
};

//////////////////////////////////////////////////////////////////////////

enum OBJECT_ATTRIBUTES_FLAGS : UINT32
{
    OBJ_PROTECT_CLOSE = 0x00000001L,
    OBJ_INHERIT = 0x00000002L,
    OBJ_AUDIT_OBJECT_CLOSE = 0x00000004L,
    OBJ_HANDLE_ATTRIBUTES = (OBJ_PROTECT_CLOSE | OBJ_INHERIT | OBJ_AUDIT_OBJECT_CLOSE),
    OBJ_PERMANENT = 0x00000010L,
    OBJ_EXCLUSIVE = 0x00000020L,
    OBJ_CASE_INSENSITIVE = 0x00000040L,
    OBJ_OPENIF = 0x00000080L,
    OBJ_OPENLINK = 0x00000100L,
    OBJ_KERNEL_HANDLE = 0x00000200L,
    OBJ_FORCE_ACCESS_CHECK = 0x00000400L,
    OBJ_IGNORE_IMPERSONATED_DEVICEMAP = 0x00000800L,
    OBJ_DONT_REPARSE = 0x00001000L,
    OBJ_VALID_ATTRIBUTES = 0x00001FF2L,
};

typedef struct _OBJECT_ATTRIBUTES {
    UINT32 Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    UINT32 Attributes;
    void* SecurityDescriptor;
    void* SecurityQualityOfService;
} OBJECT_ATTRIBUTES;
typedef OBJECT_ATTRIBUTES *POBJECT_ATTRIBUTES;

#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

//////////////////////////////////////////////////////////////////////////

extern"C" NTSTATUS NtClose(HANDLE Handle);
