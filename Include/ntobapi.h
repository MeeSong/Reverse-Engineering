#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

//
// File 
//

enum FILE_ACCESS_MASK : UINT32
{
    //
    // The FILE_READ_DATA and FILE_WRITE_DATA constants are also defined in
    // devioctl.h as FILE_READ_ACCESS and FILE_WRITE_ACCESS. The values for these
    // constants *MUST* always be in sync.
    // The values are redefined in devioctl.h because they must be available to
    // both DOS and NT.
    //

    FILE_READ_DATA              = (0x0001),    // file & pipe
    FILE_LIST_DIRECTORY         = (0x0001),    // directory

    FILE_WRITE_DATA             = (0x0002),    // file & pipe
    FILE_ADD_FILE               = (0x0002),    // directory

    FILE_APPEND_DATA            = (0x0004),    // file
    FILE_ADD_SUBDIRECTORY       = (0x0004),    // directory
    FILE_CREATE_PIPE_INSTANCE   = (0x0004),    // named pipe


    FILE_READ_EA                = (0x0008),    // file & directory

    FILE_WRITE_EA               = (0x0010),    // file & directory

    FILE_EXECUTE                = (0x0020),    // file
    FILE_TRAVERSE               = (0x0020),    // directory

    FILE_DELETE_CHILD           = (0x0040),    // directory

    FILE_READ_ATTRIBUTES        = (0x0080),    // all

    FILE_WRITE_ATTRIBUTES       = (0x0100),    // all

    FILE_ALL_ACCESS             = (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF),

    FILE_GENERIC_READ           = 
        (STANDARD_RIGHTS_READ
            | FILE_READ_DATA
            | FILE_READ_ATTRIBUTES
            | FILE_READ_EA
            | SYNCHRONIZE),


    FILE_GENERIC_WRITE = 
        (STANDARD_RIGHTS_WRITE
            | FILE_WRITE_DATA
            | FILE_WRITE_ATTRIBUTES
            | FILE_WRITE_EA
            | FILE_APPEND_DATA
            | SYNCHRONIZE),


    FILE_GENERIC_EXECUTE =
        (STANDARD_RIGHTS_EXECUTE
            | FILE_READ_ATTRIBUTES
            | FILE_EXECUTE
            | SYNCHRONIZE),
};

enum FILE_SHARED_MASK : UINT32
{
    FILE_SHARE_READ     = 0x00000001,
    FILE_SHARE_WRITE    = 0x00000002,
    FILE_SHARE_DELETE   = 0x00000004,
};

enum FILE_ATTRIBUTE_MASK : UINT32
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

    INVALID_FILE_ATTRIBUTES = UINT32(-1),
};

enum FILE_CREATE_DISPOSITION_FLAGS : UINT32
{
    FILE_SUPERSEDE = 0x00000000,
    FILE_OPEN = 0x00000001,
    FILE_CREATE = 0x00000002,
    FILE_OPEN_IF = 0x00000003,
    FILE_OVERWRITE = 0x00000004,
    FILE_OVERWRITE_IF = 0x00000005,
    FILE_MAXIMUM_DISPOSITION = 0x00000005,
};

enum FILE_CREATE_OPTION_MASK : UINT32
{
    FILE_DIRECTORY_FILE = 0x00000001,
    FILE_WRITE_THROUGH = 0x00000002,
    FILE_SEQUENTIAL_ONLY = 0x00000004,
    FILE_NO_INTERMEDIATE_BUFFERING = 0x00000008,

    FILE_SYNCHRONOUS_IO_ALERT = 0x00000010,
    FILE_SYNCHRONOUS_IO_NONALERT = 0x00000020,
    FILE_NON_DIRECTORY_FILE = 0x00000040,
    FILE_CREATE_TREE_CONNECTION = 0x00000080,

    FILE_COMPLETE_IF_OPLOCKED = 0x00000100,
    FILE_NO_EA_KNOWLEDGE = 0x00000200,
    FILE_OPEN_REMOTE_INSTANCE = 0x00000400,
    FILE_RANDOM_ACCESS = 0x00000800,

    FILE_DELETE_ON_CLOSE = 0x00001000,
    FILE_OPEN_BY_FILE_ID = 0x00002000,
    FILE_OPEN_FOR_BACKUP_INTENT = 0x00004000,
    FILE_NO_COMPRESSION = 0x00008000,

    FILE_OPEN_REQUIRING_OPLOCK = 0x00010000,
    FILE_DISALLOW_EXCLUSIVE = 0x00020000,
    FILE_SESSION_AWARE = 0x00040000,

    FILE_RESERVE_OPFILTER = 0x00100000,
    FILE_OPEN_REPARSE_POINT = 0x00200000,
    FILE_OPEN_NO_RECALL = 0x00400000,
    FILE_OPEN_FOR_FREE_SPACE_QUERY = 0x00800000,
};

enum FILE_VALID_OPTION_MASK : UINT32
{
    FILE_VALID_OPTION_FLAGS = 0x00ffffff,
    FILE_VALID_PIPE_OPTION_FLAGS = 0x00000032,
    FILE_VALID_MAILSLOT_OPTION_FLAGS = 0x00000032,
    FILE_VALID_SET_FLAGS = 0x00000036,
};

//
// Pipe
//

enum PIPE_ACCESS_MASK : UINT32
{
    PIPE_ACCESS_INBOUND     = 0x00000001,
    PIPE_ACCESS_OUTBOUND    = 0x00000002,
    PIPE_ACCESS_DUPLEX      = 0x00000003,

    PIPE_ALL_ACCESS         = 
        (SYNCHRONIZE
            | STANDARD_RIGHTS_REQUIRED
            | PIPE_ACCESS_INBOUND
            | PIPE_ACCESS_OUTBOUND
            | PIPE_ACCESS_DUPLEX),
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

enum OBJECT_ACCESS_MASK : UINT32
{
    OBJECT_TYPE_CREATE      = 0x0001,
    OBJECT_TYPE_ALL_ACCESS  = (STANDARD_RIGHTS_REQUIRED | 0x1),
};

extern"C" NTSTATUS NtClose(HANDLE Handle);

enum DUPLICATE_OPTIONS : UINT32
{
    DUPLICATE_CLOSE_SOURCE  = 0x00000001,
    DUPLICATE_SAME_ACCESS   = 0x00000002,
    DUPLICATE_SAME_ATTRIBUTES = 0x00000004,
};

extern"C" NTSTATUS NtDuplicateObject(
    HANDLE SourceProcessHandle,
    HANDLE SourceHandle,
    HANDLE TargetProcessHandle,
    HANDLE* TargetHandle,
    ACCESS_MASK DesiredAccess,
    UINT32 HandleAttributes,
    UINT32 Options);

enum SECURITY_INFORMATION : UINT32
{
    OWNER_SECURITY_INFORMATION = (0x00000001L),
    GROUP_SECURITY_INFORMATION = (0x00000002L),
    DACL_SECURITY_INFORMATION = (0x00000004L),
    SACL_SECURITY_INFORMATION = (0x00000008L),
    LABEL_SECURITY_INFORMATION = (0x00000010L),
    ATTRIBUTE_SECURITY_INFORMATION = (0x00000020L),
    SCOPE_SECURITY_INFORMATION = (0x00000040L),
    PROCESS_TRUST_LABEL_SECURITY_INFORMATION = (0x00000080L),
    BACKUP_SECURITY_INFORMATION = (0x00010000L),

    PROTECTED_DACL_SECURITY_INFORMATION = (0x80000000L),
    PROTECTED_SACL_SECURITY_INFORMATION = (0x40000000L),
    UNPROTECTED_DACL_SECURITY_INFORMATION = (0x20000000L),
    UNPROTECTED_SACL_SECURITY_INFORMATION = (0x10000000L),
};

extern"C" NTSTATUS NtQuerySecurityObject(
    HANDLE Handle,
    SECURITY_INFORMATION SecurityInformation,
    struct _SECURITY_DESCRIPTOR* SecurityDescriptor,
    UINT32 Length,
    UINT32* LengthNeeded);

enum DIRECTORY_ACCESS_MASK : UINT32
{
    DIRECTORY_QUERY = (0x0001),
    DIRECTORY_TRAVERSE = (0x0002),
    DIRECTORY_CREATE_OBJECT = (0x0004),
    DIRECTORY_CREATE_SUBDIRECTORY = (0x0008),

    DIRECTORY_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED | 0xF),
};

extern"C"
{
    NTSTATUS NtCreateDirectoryObject(
        HANDLE* DirectoryHandle,
        ACCESS_MASK DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes);

    NTSTATUS NtCreateDirectoryObjectEx(
        HANDLE* DirectoryHandle,
        ACCESS_MASK DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes,
        HANDLE ShadowDirectoryHandle,
        UINT32 Flags);

    NTSTATUS NtOpenDirectoryObject(
        HANDLE* DirectoryHandle,
        ACCESS_MASK DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes);

    NTSTATUS NtCreateFile(
        HANDLE* FileHandle,
        ACCESS_MASK DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes,
        IO_STATUS_BLOCK* IoStatusBlock,
        LARGE_INTEGER* AllocationSize,
        UINT32 FileAttributes,
        UINT32 ShareAccess,
        UINT32 CreateDisposition,
        UINT32 CreateOptions,
        void* EaBuffer,
        UINT32 EaLength);

    NTSTATUS NtCreateNamedPipeFile(
        HANDLE* FileHandle,
        UINT32 DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes,
        IO_STATUS_BLOCK* IoStatusBlock,
        UINT32 ShareAccess,
        UINT32 CreateDisposition,
        UINT32 CreateOptions,
        UINT32 NamedPipeType,
        UINT32 ReadMode,
        UINT32 CompletionMode,
        UINT32 MaximumInstances,
        UINT32 InboundQuota,
        UINT32 OutboundQuota,
        LARGE_INTEGER* DefaultTimeout);
}

//
// Symbolic links
//

enum SYMBOLIC_LINK_ACCESS_MASK : UINT32
{
    SYMBOLIC_LINK_QUERY = (0x0001),
    SYMBOLIC_LINK_SET   = (0x0002),

    SYMBOLIC_LINK_ALL_ACCESS    = (STANDARD_RIGHTS_REQUIRED | 0x1),
    SYMBOLIC_LINK_ALL_ACCESS_EX = (STANDARD_RIGHTS_REQUIRED | 0xFFFF),
};

extern"C"
{
    NTSTATUS NtCreateSymbolicLinkObject(
        HANDLE* LinkHandle,
        ACCESS_MASK DesiredAccess,
        POBJECT_ATTRIBUTES ObjectAttributes,
        PUNICODE_STRING LinkTarget);

    NTSTATUS NtOpenSymbolicLinkObject(
        HANDLE* LinkHandle,
        ACCESS_MASK DesiredAccess,
        POBJECT_ATTRIBUTES ObjectAttributes);

    NTSTATUS NtQuerySymbolicLinkObject(
        HANDLE LinkHandle,
        PUNICODE_STRING LinkTarget,
        UINT32 ReturnedLength);
}

