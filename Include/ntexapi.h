#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

typedef struct _SYSTEM_TIMEOFDAY_INFORMATION
{
    LARGE_INTEGER BootTime;
    LARGE_INTEGER CurrentTime;
    LARGE_INTEGER TimeZoneBias;
    UINT32 TimeZoneId;
    UINT32 Reserved;
    UINT64 BootTimeBias;
    UINT64 SleepTimeBias;
} SYSTEM_TIMEOFDAY_INFORMATION, *PSYSTEM_TIMEOFDAY_INFORMATION;

typedef struct _SYSTEM_BASIC_INFORMATION
{
    UINT32 Reserved;
    UINT32 TimerResolution;
    UINT32 PageSize;
    UINT32 NumberOfPhysicalPages;
    UINT32 LowestPhysicalPageNumber;
    UINT32 HighestPhysicalPageNumber;
    UINT32 AllocationGranularity;
    UINT_PTR MinimumUserModeAddress;
    UINT_PTR MaximumUserModeAddress;
    UINT_PTR ActiveProcessorsAffinityMask;
    UINT8 NumberOfProcessors;
} SYSTEM_BASIC_INFORMATION, *PSYSTEM_BASIC_INFORMATION;

enum ALTERNATIVE_ARCHITECTURE_TYPE : UINT32
{
    StandardDesign,                 // None == 0 == standard design
    NEC98x86,                       // NEC PC98xx series on X86
    EndAlternatives                 // past end of known alternatives
};

enum NT_PRODUCT_TYPE : UINT32
{
    NtProductWinNt = 1,
    NtProductLanManNt,
    NtProductServer
};

typedef struct _XSTATE_FEATURE {
    UINT32 Offset;
    UINT32 Size;
} XSTATE_FEATURE, *PXSTATE_FEATURE;

typedef struct _XSTATE_CONFIGURATION 
{
    enum : UINT32
    {
        MAXIMUM_XSTATE_FEATURES = 64,
    };

    // Mask of all enabled features
    UINT64 EnabledFeatures;

    // Mask of volatile enabled features
    UINT64 EnabledVolatileFeatures;

    // Total size of the save area
    UINT32 Size;

    UINT32 OptimizedSave : 1;

    // List of features (
    XSTATE_FEATURE Features[MAXIMUM_XSTATE_FEATURES];

} XSTATE_CONFIGURATION, *PXSTATE_CONFIGURATION;

typedef struct _KUSER_SHARED_DATA
{
    enum : UINT32
    {
        PROCESSOR_FEATURE_MAX = 64,
    };

    UINT32 TickCountLowDeprecated;
    UINT32 TickCountMultiplier;

    volatile KSYSTEM_TIME InterruptTime;
    volatile KSYSTEM_TIME SystemTime;
    volatile KSYSTEM_TIME TimeZoneBias;

    UINT16 ImageNumberLow;
    UINT16 ImageNumberHigh;

    wchar_t NtSystemRoot[MAX_PATH];

    UINT32 MaxStackTraceDepth;

    UINT32 CryptoExponent;

    UINT32 TimeZoneId;
    UINT32 LargePageMinimum;
    UINT32 AitSamplingValue;
    UINT32 AppCompatFlag;
    UINT64 RNGSeedVersion;
    UINT32 GlobalValidationRunlevel;
    INT32  TimeZoneBiasStamp;

    UINT32 NtBuildNumber;
    NT_PRODUCT_TYPE NtProductType;
    BOOLEAN ProductTypeIsValid;
    UINT8   Reserved0[1];
    UINT16 NativeProcessorArchitecture;

    UINT32 NtMajorVersion;
    UINT32 NtMinorVersion;

    BOOLEAN ProcessorFeatures[PROCESSOR_FEATURE_MAX];

    UINT32 Reserved1;
    UINT32 Reserved3;

    volatile UINT32 TimeSlip;

    ALTERNATIVE_ARCHITECTURE_TYPE AlternativeArchitecture;
    UINT32 BootId;

    LARGE_INTEGER SystemExpirationDate;

    UINT32 SuiteMask;

    BOOLEAN KdDebuggerEnabled;
    union
    {
        UINT8 MitigationPolicies;
        struct
        {
            UINT8 NXSupportPolicy : 2;
            UINT8 SEHValidationPolicy : 2;
            UINT8 CurDirDevicesSkippedForDlls : 2;
            UINT8 Reserved : 2;
        };
    };
    UINT8 Reserved6[2];

    volatile UINT32 ActiveConsoleId;

    volatile UINT32 DismountCount;

    UINT32 ComPlusPackage;

    UINT32 LastSystemRITEventTickCount;

    UINT32 NumberOfPhysicalPages;

    BOOLEAN SafeBootMode;
    UINT8 VirtualizationFlags;
    UINT8 Reserved12[2];

    union
    {
        UINT32 SharedDataFlags;
        struct
        {
            UINT32 DbgErrorPortPresent : 1;
            UINT32 DbgElevationEnabled : 1;
            UINT32 DbgVirtEnabled : 1;
            UINT32 DbgInstallerDetectEnabled : 1;
            UINT32 DbgLkgEnabled : 1;
            UINT32 DbgDynProcessorEnabled : 1;
            UINT32 DbgConsoleBrokerEnabled : 1;
            UINT32 DbgSecureBootEnabled : 1;
            UINT32 DbgMultiSessionSku : 1;
            UINT32 DbgMultiUsersInSessionSku : 1;
            UINT32 SpareBits : 22;
        };
    };
    UINT32 DataFlagsPad[1];

    UINT64 TestRetInstruction;
    INT64 QpcFrequency;
    UINT32 SystemCall;
    UINT64 SystemCallPad[2];

    union
    {
        volatile KSYSTEM_TIME TickCount;
        volatile UINT64 TickCountQuad;
        UINT32 ReservedTickCountOverlay[3];
    };
    //UINT32 TickCountPad[1];

    UINT32 Cookie;
    UINT32 CookiePad[1];

    INT64 ConsoleSessionForegroundProcessId;
    UINT64 TimeUpdateLock;
    UINT64 BaselineSystemTimeQpc;
    UINT64 BaselineInterruptTimeQpc;
    UINT64 QpcSystemTimeIncrement;
    UINT64 QpcInterruptTimeIncrement;
    UINT8 QpcSystemTimeIncrementShift;
    UINT8 QpcInterruptTimeIncrementShift;

    UINT16 UnparkedProcessorCount;
    UINT32 EnclaveFeatureMask[4];
    UINT32 Reserved8;
    UINT16 UserModeGlobalLogger[16];
    UINT32 ImageFileExecutionOptions;

    UINT32 LangGenerationCount;
    UINT64 Reserved4;
    volatile UINT64 InterruptTimeBias;
    volatile UINT64 QpcBias;

    UINT32 ActiveProcessorCount;
    volatile UINT8 ActiveGroupCount;
    UINT8 Reserved9;
    union
    {
        UINT16 QpcData;
        struct
        {
            UINT8 QpcBypassEnabled : 1;
            UINT8 QpcShift : 1;
        };
    };

    LARGE_INTEGER TimeZoneBiasEffectiveStart;
    LARGE_INTEGER TimeZoneBiasEffectiveEnd;
    XSTATE_CONFIGURATION XState;
} KUSER_SHARED_DATA, *PKUSER_SHARED_DATA;
static_assert(sizeof(KUSER_SHARED_DATA) == 0x5f0, "KUSER_SHARED_DATA size is wrong!");

#define KI_USER_SHARED_DATA     0x7FFE0000
#define SharedUserData          ((KUSER_SHARED_DATA * const)(KI_USER_SHARED_DATA))
