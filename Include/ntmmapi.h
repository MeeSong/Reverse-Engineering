#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

typedef struct _MEMORY_BASIC_INFORMATION
{
    void* BaseAddress;
    void* AllocationBase;
    UINT32 AllocationProtect;
    SIZE_T RegionSize;
    UINT32 State;
    UINT32 Protect;
    UINT32 Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;

typedef struct _MEMORY_WORKING_SET_BLOCK
{
    UINT_PTR Protection : 5;
    UINT_PTR ShareCount : 3;
    UINT_PTR Shared : 1;
    UINT_PTR Node : 3;
#ifdef _WIN64
    UINT_PTR VirtualPage : 52;
#else
    UINT32 VirtualPage : 20;
#endif
} MEMORY_WORKING_SET_BLOCK, *PMEMORY_WORKING_SET_BLOCK;

typedef struct _MEMORY_WORKING_SET_INFORMATION
{
    UINT_PTR NumberOfEntries;
    MEMORY_WORKING_SET_BLOCK WorkingSetInfo[1];
} MEMORY_WORKING_SET_INFORMATION, *PMEMORY_WORKING_SET_INFORMATION;

// private
typedef struct _MEMORY_REGION_INFORMATION
{
    void* AllocationBase;
    UINT32 AllocationProtect;
    union
    {
        UINT32 RegionType;
        struct
        {
            UINT32 Private : 1;
            UINT32 MappedDataFile : 1;
            UINT32 MappedImage : 1;
            UINT32 MappedPageFile : 1;
            UINT32 MappedPhysical : 1;
            UINT32 DirectMapped : 1;
            UINT32 Reserved : 26;
        };
    };
    SIZE_T RegionSize;
    SIZE_T CommitSize;
} MEMORY_REGION_INFORMATION, *PMEMORY_REGION_INFORMATION;

// private
typedef struct _MEMORY_WORKING_SET_EX_BLOCK
{
    union
    {
        struct
        {
            UINT_PTR Valid : 1;
            UINT_PTR ShareCount : 3;
            UINT_PTR Win32Protection : 11;
            UINT_PTR Shared : 1;
            UINT_PTR Node : 6;
            UINT_PTR Locked : 1;
            UINT_PTR LargePage : 1;
            UINT_PTR Priority : 3;
            UINT_PTR Reserved : 3;
            UINT_PTR SharedOriginal : 1;
            UINT_PTR Bad : 1;
#ifdef _WIN64
            UINT_PTR ReservedUlong : 32;
#endif
        };
        struct
        {
            UINT_PTR Valid : 1;
            UINT_PTR Reserved0 : 14;
            UINT_PTR Shared : 1;
            UINT_PTR Reserved1 : 5;
            UINT_PTR PageTable : 1;
            UINT_PTR Location : 2;
            UINT_PTR Priority : 3;
            UINT_PTR ModifiedList : 1;
            UINT_PTR Reserved2 : 2;
            UINT_PTR SharedOriginal : 1;
            UINT_PTR Bad : 1;
#ifdef _WIN64
            UINT_PTR ReservedUlong : 32;
#endif
        } Invalid;
    };
} MEMORY_WORKING_SET_EX_BLOCK, *PMEMORY_WORKING_SET_EX_BLOCK;

// private
typedef struct _MEMORY_WORKING_SET_EX_INFORMATION
{
    void* VirtualAddress;
    union
    {
        MEMORY_WORKING_SET_EX_BLOCK VirtualAttributes;
        UINT_PTR Long;
    } u1;
} MEMORY_WORKING_SET_EX_INFORMATION, *PMEMORY_WORKING_SET_EX_INFORMATION;

// private
typedef struct _MEMORY_SHARED_COMMIT_INFORMATION
{
    SIZE_T CommitSize;
} MEMORY_SHARED_COMMIT_INFORMATION, *PMEMORY_SHARED_COMMIT_INFORMATION;

// private
typedef struct _MEMORY_IMAGE_INFORMATION
{
    void* ImageBase;
    SIZE_T SizeOfImage;
    union
    {
        UINT32 ImageFlags;
        struct
        {
            UINT32 ImagePartialMap : 1;
            UINT32 ImageNotExecutable : 1;
            UINT32 Reserved : 30;
        };
    };
} MEMORY_IMAGE_INFORMATION, *PMEMORY_IMAGE_INFORMATION;

enum MMPFN_USE_DESCRIPTION: UINT8
{
    MMPFNLIST_ZERO = 0,
    MMPFNLIST_FREE = 1,
    MMPFNLIST_STANDBY = 2,
    MMPFNLIST_MODIFIED = 3,
    MMPFNLIST_MODIFIEDNOWRITE = 4,
    MMPFNLIST_BAD = 5,
    MMPFNLIST_ACTIVE = 6,
    MMPFNLIST_TRANSITION = 7,
};

enum MMPFN_LIST_DESCRIPTION : UINT8
{
    MMPFNUSE_PROCESSPRIVATE = 0,
    MMPFNUSE_FILE = 1,
    MMPFNUSE_PAGEFILEMAPPED = 2,
    MMPFNUSE_PAGETABLE = 3,
    MMPFNUSE_PAGEDPOOL = 4,
    MMPFNUSE_NONPAGEDPOOL = 5,
    MMPFNUSE_SYSTEMPTE = 6,
    MMPFNUSE_SESSIONPRIVATE = 7,
    MMPFNUSE_METAFILE = 8,
    MMPFNUSE_AWEPAGE = 9,
    MMPFNUSE_DRIVERLOCKPAGE = 10,
    MMPFNUSE_KERNELSTACK = 11,
};

// private
typedef struct _MEMORY_FRAME_INFORMATION
{
    UINT64 UseDescription : 4; // MMPFNUSE_*
    UINT64 ListDescription : 3; // MMPFNLIST_*
    UINT64 Reserved0 : 1; // reserved for future expansion
    UINT64 Pinned : 1; // 1 - pinned, 0 - not pinned
    UINT64 DontUse : 48; // *_INFORMATION overlay
    UINT64 Priority : 3; // rev
    UINT64 Reserved : 4; // reserved for future expansion
} MEMORY_FRAME_INFORMATION;

// private
typedef struct _FILEOFFSET_INFORMATION
{
    UINT64 DontUse : 9; // MEMORY_FRAME_INFORMATION overlay
    UINT64 Offset : 48; // mapped files
    UINT64 Reserved : 7; // reserved for future expansion
} FILEOFFSET_INFORMATION;

// private
typedef struct _PAGEDIR_INFORMATION
{
    UINT64 DontUse : 9; // MEMORY_FRAME_INFORMATION overlay
    UINT64 PageDirectoryBase : 48; // private pages
    UINT64 Reserved : 7; // reserved for future expansion
} PAGEDIR_INFORMATION;

// private
typedef struct _UNIQUE_PROCESS_INFORMATION
{
    UINT64 DontUse : 9; // MEMORY_FRAME_INFORMATION overlay
    UINT64 UniqueProcessKey : 48; // ProcessId
    UINT64 Reserved : 7; // reserved for future expansion
} UNIQUE_PROCESS_INFORMATION, *PUNIQUE_PROCESS_INFORMATION;

// private
typedef struct _MMPFN_IDENTITY
{
    union
    {
        MEMORY_FRAME_INFORMATION e1; // all
        FILEOFFSET_INFORMATION e2; // mapped files
        PAGEDIR_INFORMATION e3; // private pages
        UNIQUE_PROCESS_INFORMATION e4; // owning process
    } u1;
    UINT_PTR PageFrameIndex; // all
    union
    {
        struct
        {
            UINT_PTR Image : 1;
            UINT_PTR Mismatch : 1;
        } e1;
        struct
        {
            UINT_PTR CombinedPage;
        } e2;
        UINT_PTR FileObject; // mapped files
        UINT_PTR UniqueFileObjectKey;
        UINT_PTR ProtoPteAddress;
        UINT_PTR VirtualAddress;  // everything else
    } u2;
} MMPFN_IDENTITY, *PMMPFN_IDENTITY;

typedef struct _MMPFN_MEMSNAP_INFORMATION
{
    UINT_PTR InitialPageFrameIndex;
    UINT_PTR Count;
} MMPFN_MEMSNAP_INFORMATION, *PMMPFN_MEMSNAP_INFORMATION;

enum SECTION_INFORMATION_CLASS : UINT32
{
    SectionBasicInformation,
    SectionImageInformation,
    SectionRelocationInformation,       // name:wow64:whNtQuerySection_SectionRelocationInformation
    SectionOriginalBaseInformation,     // void* BaseAddress
    SectionInternalImageInformation,    // SECTION_INTERNAL_IMAGE_INFORMATION // since REDSTONE2
    MaxSectionInfoClass
};

typedef struct _SECTION_BASIC_INFORMATION
{
    void* BaseAddress;
    UINT32 AllocationAttributes;
    LARGE_INTEGER MaximumSize;
} SECTION_BASIC_INFORMATION, *PSECTION_BASIC_INFORMATION;

typedef struct _SECTION_IMAGE_INFORMATION
{
    void* TransferAddress;
    UINT32 ZeroBits;
    SIZE_T MaximumStackSize;
    SIZE_T CommittedStackSize;
    UINT32 SubSystemType;
    union
    {
        struct
        {
            UINT16 SubSystemMinorVersion;
            UINT16 SubSystemMajorVersion;
        };
        UINT32 SubSystemVersion;
    };
    union
    {
        struct
        {
            UINT16 MajorOperatingSystemVersion;
            UINT16 MinorOperatingSystemVersion;
        };
        UINT32 OperatingSystemVersion;
    };
    UINT16 ImageCharacteristics;
    UINT16 DllCharacteristics;
    UINT16 Machine;
    BOOLEAN ImageContainsCode;
    union
    {
        UINT8 ImageFlags;
        struct
        {
            UINT8 ComPlusNativeReady : 1;
            UINT8 ComPlusILOnly : 1;
            UINT8 ImageDynamicallyRelocated : 1;
            UINT8 ImageMappedFlat : 1;
            UINT8 BaseBelow4gb : 1;
            UINT8 ComPlusPrefer32bit : 1;
            UINT8 Reserved : 2;
        };
    };
    UINT32 LoaderFlags;
    UINT32 ImageFileSize;
    UINT32 CheckSum;
} SECTION_IMAGE_INFORMATION, *PSECTION_IMAGE_INFORMATION;
static_assert(sizeof(SECTION_IMAGE_INFORMATION) == 0x40, 
    "SECTION_IMAGE_INFORMATION size is wrong!");

typedef struct _SECTION_INTERNAL_IMAGE_INFORMATION
{
    SECTION_IMAGE_INFORMATION SectionInformation;
    union
    {
        UINT32 ExtendedFlags;
        struct
        {
            UINT32 ImageReturnFlowGuardEnabled : 1;
            UINT32 ImageReturnFlowGuardStrict : 1;
            UINT32 ImageExportSuppressionEnabled : 1;
            UINT32 Reserved : 29;
        };
    };
} SECTION_INTERNAL_IMAGE_INFORMATION, *PSECTION_INTERNAL_IMAGE_INFORMATION;

typedef enum _SECTION_INHERIT
{
    ViewShare = 1,
    ViewUnmap = 2
} SECTION_INHERIT;

//////////////////////////////////////////////////////////////////////////

enum MEM_PROTECTION : UINT32
{
    PAGE_NOACCESS               = 0x00000001,
    PAGE_READONLY               = 0x00000002,
    PAGE_READWRITE              = 0x00000004,
    PAGE_WRITECOPY              = 0x00000008,
    PAGE_EXECUTE                = 0x00000010,
    PAGE_EXECUTE_READ           = 0x00000020,
    PAGE_EXECUTE_READWRITE      = 0x00000040,
    PAGE_EXECUTE_WRITECOPY      = 0x00000080,
    PAGE_GUARD                  = 0x00000100,
    PAGE_NOCACHE                = 0x00000200,
    PAGE_WRITECOMBINE           = 0x00000400,

    PAGE_ENCLAVE_UNVALIDATED    = 0x20000000,
    PAGE_TARGETS_NO_UPDATE      = 0x40000000,
    PAGE_TARGETS_INVALID        = 0x40000000,
    PAGE_REVERT_TO_FILE_MAP     = 0x80000000,
    PAGE_ENCLAVE_THREAD_CONTROL = 0x80000000,
};

enum MEM_REGION : UINT32
{
    MEM_COMMIT                  = 0x00001000,
    MEM_RESERVE                 = 0x00002000,
    MEM_DECOMMIT                = 0x00004000,
    MEM_RELEASE                 = 0x00008000,
    MEM_FREE                    = 0x00010000,
    MEM_PRIVATE                 = 0x00020000,
    MEM_MAPPED                  = 0x00040000,
    MEM_RESET                   = 0x00080000,
    MEM_TOP_DOWN                = 0x00100000,
    MEM_WRITE_WATCH             = 0x00200000,
    MEM_PHYSICAL                = 0x00400000,
    MEM_ROTATE                  = 0x00800000,
    MEM_DIFFERENT_IMAGE_BASE_OK = 0x00800000,
    MEM_RESET_UNDO              = 0x01000000,
    MEM_LARGE_PAGES             = 0x20000000,
    MEM_4MB_PAGES               = 0x80000000,
};

enum MEM_SECTION : UINT32
{
    SEC_BASED           = 0x00200000,
    SEC_NO_CHANGE       = 0x00400000,
    SEC_FILE            = 0x00800000,
    SEC_IMAGE           = 0x01000000,
    SEC_PROTECTED_IMAGE = 0x02000000,
    SEC_RESERVE         = 0x04000000,
    SEC_COMMIT          = 0x08000000,
    SEC_NOCACHE         = 0x10000000,
    SEC_GLOBAL          = 0x20000000,
    SEC_WRITECOMBINE    = 0x40000000,
    SEC_LARGE_PAGES     = 0x80000000,
    SEC_IMAGE_NO_EXECUTE = SEC_IMAGE | SEC_NOCACHE,
    MEM_IMAGE           = SEC_IMAGE,
};

enum MEM_EXECUTE_OPTION : UINT32
{
    MEM_EXECUTE_OPTION_DISABLE                  = 0x01,
    MEM_EXECUTE_OPTION_ENABLE                   = 0x02,
    MEM_EXECUTE_OPTION_DISABLE_THUNK_EMULATION  = 0x04,
    MEM_EXECUTE_OPTION_PERMANENT                = 0x08,
    MEM_EXECUTE_OPTION_EXECUTE_DISPATCH_ENABLE  = 0x10,
    MEM_EXECUTE_OPTION_IMAGE_DISPATCH_ENABLE    = 0x20,
    MEM_EXECUTE_OPTION_VALID_FLAGS              = 0x3f,
};

enum MEMORY_INFORMATION_CLASS : UINT32
{
    MemoryBasicInformation,             // MEMORY_BASIC_INFORMATION
    MemoryWorkingSetInformation,        // MEMORY_WORKING_SET_INFORMATION
    MemoryMappedFilenameInformation,    // UNICODE_STRING
    MemoryRegionInformation,            // MEMORY_REGION_INFORMATION
    MemoryWorkingSetExInformation,      // MEMORY_WORKING_SET_EX_INFORMATION
    MemorySharedCommitInformation,      // MEMORY_SHARED_COMMIT_INFORMATION
    MemoryImageInformation,             // MEMORY_IMAGE_INFORMATION
    MemoryRegionInformationEx,
    MemoryPrivilegedBasicInformation
};

extern"C" NTSTATUS NtAllocateVirtualMemory(
    HANDLE ProcessHandle,
    void* *BaseAddress,
    UINT_PTR ZeroBits,
    SIZE_T* RegionSize,
    UINT32 AllocationType,
    UINT32 Protect
);

extern"C" NTSTATUS NtFreeVirtualMemory(
    HANDLE ProcessHandle,
    void* *BaseAddress,
    SIZE_T* RegionSize,
    UINT32 FreeType
);

extern"C" NTSTATUS NtReadVirtualMemory(
    HANDLE ProcessHandle,
    void* BaseAddress,
    void* Buffer,
    SIZE_T BufferSize,
    SIZE_T* NumberOfBytesRead
);

extern"C" NTSTATUS NtWriteVirtualMemory(
    HANDLE ProcessHandle,
    void* BaseAddress,
    void* Buffer,
    SIZE_T BufferSize,
    SIZE_T* NumberOfBytesWritten
);

extern"C" NTSTATUS NtProtectVirtualMemory(
    HANDLE ProcessHandle,
    void* *BaseAddress,
    SIZE_T* RegionSize,
    UINT32 NewProtect,
    UINT32* OldProtect
);

extern"C" NTSTATUS NtQueryVirtualMemory(
    HANDLE ProcessHandle,
    void* BaseAddress,
    MEMORY_INFORMATION_CLASS MemoryInformationClass,
    void* MemoryInformation,
    SIZE_T MemoryInformationLength,
    SIZE_T* ReturnLength
);
