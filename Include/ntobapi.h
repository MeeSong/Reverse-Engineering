#pragma once
#include "ntbase.h"

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

