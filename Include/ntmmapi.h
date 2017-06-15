#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

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
