#pragma once
#include "ntbase.h"
#include "ntpsapi.h"

//////////////////////////////////////////////////////////////////////////

typedef struct _ACTIVATION_CONTEXT_DATA {
    UINT32 Magic;                   // 'Actx'
    UINT32 HeaderSize;
    UINT32 FormatVersion;
    UINT32 TotalSize;
    UINT32 DefaultTocOffset;
    UINT32 ExtendedTocOffset;
    UINT32 AssemblyRosterOffset;
    UINT32 Flags;
} ACTIVATION_CONTEXT_DATA, *PACTIVATION_CONTEXT_DATA;
typedef const ACTIVATION_CONTEXT_DATA *PCACTIVATION_CONTEXT_DATA;

typedef struct _ASSEMBLY_STORAGE_MAP_ENTRY {
    UINT32 Flags;
    UNICODE_STRING DosPath;
    HANDLE Handle;
} ASSEMBLY_STORAGE_MAP_ENTRY, *PASSEMBLY_STORAGE_MAP_ENTRY;

typedef struct _ASSEMBLY_STORAGE_MAP {
    UINT32 Flags;
    UINT32 Count;
    ASSEMBLY_STORAGE_MAP_ENTRY *AssemblyArray[1];
} ASSEMBLY_STORAGE_MAP, *PASSEMBLY_STORAGE_MAP;

typedef struct _FLS_CALLBACK {
    void* Unknown;
    void* StartAddress;
} FLS_CALLBACK, *PFLS_CALLBACK;

typedef struct _FLS_CALLBACK_INFO
{
    void* Unknown;
    FLS_CALLBACK Callbacks[5];
} FLS_CALLBACK_INFO, *PFLS_CALLBACK_INFO;

typedef struct _PEB
{
    BOOLEAN InheritedAddressSpace;
    BOOLEAN ReadImageFileExecOptions;
    BOOLEAN BeingDebugged;
    union
    {
        UINT8 BitField;
        struct
        {
            BOOLEAN ImageUsesLargePages : 1;
            BOOLEAN IsProtectedProcess : 1;
            BOOLEAN IsImageDynamicallyRelocated : 1;
            BOOLEAN SkipPatchingUser32Forwarders : 1;
            BOOLEAN IsPackagedProcess : 1;
            BOOLEAN IsAppContainer : 1;
            BOOLEAN IsProtectedProcessLight : 1;
            BOOLEAN IsLongPathAwareProcess : 1;
        };
    };

    HANDLE Mutant;

    void* ImageBaseAddress;
    struct _PEB_LDR_DATA* Ldr;
    struct _PRTL_USER_PROCESS_PARAMETERS* ProcessParameters;
    void* SubSystemData;
    void* ProcessHeap;
    struct _RTL_CRITICAL_SECTION* FastPebLock;
    void* AtlThunkSListPtr;
    void* IFEOKey;
    union
    {
        UINT32 CrossProcessFlags;
        struct
        {
            UINT32 ProcessInJob : 1;
            UINT32 ProcessInitializing : 1;
            UINT32 ProcessUsingVEH : 1;
            UINT32 ProcessUsingVCH : 1;
            UINT32 ProcessUsingFTH : 1;
            UINT32 ProcessPreviouslyThrottled : 1;
            UINT32 ProcessCurrentlyThrottled : 1;
            UINT32 ReservedBits0 : 25;
        };
    };
    union
    {
        void* KernelCallbackTable;
        void* UserSharedInfoPtr;
    };
    UINT32 SystemReserved[1];
    UINT32 AtlThunkSListPtr32;
    void* ApiSetMap;
    UINT32 TlsExpansionCounter;
    void* TlsBitmap;
    UINT32 TlsBitmapBits[2];
    void* ReadOnlySharedMemoryBase;
    void* HotpatchInformation;
    void* *ReadOnlyStaticServerData;
    void* AnsiCodePageData;
    void* OemCodePageData;
    void* UnicodeCaseTableData;

    UINT32 NumberOfProcessors;
    UINT32 NtGlobalFlag;

    LARGE_INTEGER CriticalSectionTimeout;
    SIZE_T HeapSegmentReserve;
    SIZE_T HeapSegmentCommit;
    SIZE_T HeapDeCommitTotalFreeThreshold;
    SIZE_T HeapDeCommitFreeBlockThreshold;

    UINT32 NumberOfHeaps;
    UINT32 MaximumNumberOfHeaps;
    void* *ProcessHeaps;

    void* GdiSharedHandleTable;
    void* ProcessStarterHelper;
    UINT32 GdiDCAttributeList;

    struct _RTL_CRITICAL_SECTION* LoaderLock;

    UINT32 OSMajorVersion;
    UINT32 OSMinorVersion;
    UINT16 OSBuildNumber;
    UINT16 OSCSDVersion;
    UINT32 OSPlatformId;
    UINT32 ImageSubsystem;
    UINT32 ImageSubsystemMajorVersion;
    UINT32 ImageSubsystemMinorVersion;
    UINT_PTR ActiveProcessAffinityMask;
    GDI_HANDLE_BUFFER GdiHandleBuffer;
    void* PostProcessInitRoutine;

    void* TlsExpansionBitmap;
    UINT32 TlsExpansionBitmapBits[32];

    UINT32 SessionId;

    ULARGE_INTEGER AppCompatFlags;
    ULARGE_INTEGER AppCompatFlagsUser;
    void* pShimData;
    void* AppCompatInfo;

    UNICODE_STRING CSDVersion;

    struct _ACTIVATION_CONTEXT_DATA* ActivationContextData;
    struct _ASSEMBLY_STORAGE_MAP* ProcessAssemblyStorageMap;
    struct _ACTIVATION_CONTEXT_DATA* SystemDefaultActivationContextData;
    struct _ASSEMBLY_STORAGE_MAP* SystemAssemblyStorageMap;

    SIZE_T MinimumStackCommit;

    struct _FLS_CALLBACK_INFO* FlsCallback;
    LIST_ENTRY FlsListHead;
    void* FlsBitmap;
    UINT32 FlsBitmapBits[FLS_MAXIMUM_AVAILABLE / (sizeof(UINT32) * 8)];
    UINT32 FlsHighIndex;

    void* WerRegistrationData;
    void* WerShipAssertPtr;
    void* pContextData;
    void* pImageHeaderHash;
    union
    {
        UINT32 TracingFlags;
        struct
        {
            UINT32 HeapTracingEnabled : 1;
            UINT32 CritSecTracingEnabled : 1;
            UINT32 LibLoaderTracingEnabled : 1;
            UINT32 SpareTracingBits : 29;
        };
    };
    INT64 CsrServerReadOnlySharedMemoryBase;
    //void* TppWorkerpListLock;
    //LIST_ENTRY TppWorkerpList;
    //void* WaitOnAddressHashTable[128];
} PEB, *PPEB;
static_assert(sizeof(PEB) == 0x388, "PEB size is wrong!");

//////////////////////////////////////////////////////////////////////////

typedef enum _EXCEPTION_DISPOSITION : UINT32
{
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind
} EXCEPTION_DISPOSITION;

using PEXCEPTION_ROUTINE = EXCEPTION_DISPOSITION(*)(
    struct _EXCEPTION_RECORD *ExceptionRecord,
    void* EstablisherFrame,
    struct _CONTEXT *ContextRecord,
    void* DispatcherContext
);

typedef struct _EXCEPTION_REGISTRATION_RECORD {
    struct _EXCEPTION_REGISTRATION_RECORD *Next;
    PEXCEPTION_ROUTINE Handler;
} EXCEPTION_REGISTRATION_RECORD, *PEXCEPTION_REGISTRATION_RECORD;

typedef struct _NT_TIB {
    struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
    void* StackBase;
    void* StackLimit;
    void* SubSystemTib;
    union {
        void* FiberData;
        UINT32 Version;
    };
    void* ArbitraryUserPointer;
    struct _NT_TIB *Self;
} NT_TIB, *PNT_TIB;
static_assert(sizeof(NT_TIB) == 0x38, "NT_TIB size is wrong!");

typedef struct _GDI_TEB_BATCH
{
    enum : UINT32
    {
        GDI_BATCH_BUFFER_SIZE = 310,
    };
    struct  
    {
        UINT32 Offset : 31;
        UINT32 HasRenderingCommand : 1;
    };
    UINT_PTR HDC;
    UINT32 Buffer[GDI_BATCH_BUFFER_SIZE];
} GDI_TEB_BATCH, *PGDI_TEB_BATCH;

typedef struct _TEB_ACTIVE_FRAME_CONTEXT
{
    UINT32 Flags;
    PSTR FrameName;
} TEB_ACTIVE_FRAME_CONTEXT, *PTEB_ACTIVE_FRAME_CONTEXT;

typedef struct _TEB_ACTIVE_FRAME
{
    UINT32 Flags;
    struct _TEB_ACTIVE_FRAME *Previous;
    struct _TEB_ACTIVE_FRAME_CONTEXT* Context;
} TEB_ACTIVE_FRAME, *PTEB_ACTIVE_FRAME;

using LCID = UINT32;
typedef struct _TEB
{
    NT_TIB NtTib;

    void* EnvironmentPointer;
    CLIENT_ID ClientId;
    void* ActiveRpcHandle;
    void* ThreadLocalStoragePointer;
    struct _PEB* ProcessEnvironmentBlock;

    UINT32 LastErrorValue;
    UINT32 CountOfOwnedCriticalSections;
    void* CsrClientThread;
    void* Win32ThreadInfo;
    UINT32 User32Reserved[26];
    UINT32 UserReserved[5];
    void* WOW32Reserved;
    LCID CurrentLocale;
    UINT32 FpSoftwareStatusRegister;
    void* ReservedForDebuggerInstrumentation[16];
    void* SystemReserved1[37];
    BYTE WorkingOnBehalfTicket[8];
    NTSTATUS ExceptionCode;

    void* ActivationContextStackPointer;
    UINT_PTR InstrumentationCallbackSp;
    UINT_PTR InstrumentationCallbackPreviousPc;
    UINT_PTR InstrumentationCallbackPreviousSp;
    UINT32 TxFsContext;

    BOOLEAN InstrumentationCallbackDisabled;
    GDI_TEB_BATCH GdiTebBatch;
    CLIENT_ID RealClientId;
    HANDLE GdiCachedProcessHandle;
    UINT32 GdiClientPID;
    UINT32 GdiClientTID;
    void* GdiThreadLocalInfo;
    UINT_PTR Win32ClientInfo[62];
    void* glDispatchTable[233];
    UINT_PTR glReserved1[29];
    void* glReserved2;
    void* glSectionInfo;
    void* glSection;
    void* glTable;
    void* glCurrentRC;
    void* glContext;

    NTSTATUS LastStatusValue;
    UNICODE_STRING StaticUnicodeString;
    wchar_t StaticUnicodeBuffer[MAX_PATH + 1];

    void* DeallocationStack;
    void* TlsSlots[64];
    LIST_ENTRY TlsLinks;

    void* Vdm;
    void* ReservedForNtRpc;
    void* DbgSsReserved[2];

    UINT32 HardErrorMode;
#ifdef _WIN64
    void* Instrumentation[11];
#else
    void* Instrumentation[9];
#endif
    GUID ActivityId;

    void* SubProcessTag;
    void* PerflibData;
    void* EtwTraceData;
    void* WinSockData;
    UINT32 GdiBatchCount;

    union
    {
        PROCESSOR_NUMBER CurrentIdealProcessor;
        UINT32 IdealProcessorValue;
        struct
        {
            BYTE ReservedPad0;
            BYTE ReservedPad1;
            BYTE ReservedPad2;
            BYTE IdealProcessor;
        };
    };

    UINT32 GuaranteedStackBytes;
    void* ReservedForPerf;
    void* ReservedForOle;
    UINT32 WaitingOnLoaderLock;
    void* SavedPriorityState;
    UINT_PTR ReservedForCodeCoverage;
    void* ThreadPoolData;
    void* *TlsExpansionSlots;
#ifdef _WIN64
    void* DeallocationBStore;
    void* BStoreLimit;
#endif
    UINT32 MuiGeneration;
    UINT32 IsImpersonating;
    void* NlsCache;
    void* pShimData;
    UINT16 HeapVirtualAffinity;
    UINT16 LowFragHeapDataSlot;
    HANDLE CurrentTransactionHandle;
    struct _TEB_ACTIVE_FRAME* ActiveFrame;
    void* FlsData;

    void* PreferredLanguages;
    void* UserPrefLanguages;
    void* MergedPrefLanguages;
    UINT32 MuiImpersonation;

    union
    {
        UINT16 CrossTebFlags;
        UINT16 SpareCrossTebBits : 16;
    };
    union
    {
        UINT16 SameTebFlags;
        struct
        {
            UINT16 SafeThunkCall : 1;
            UINT16 InDebugPrint : 1;
            UINT16 HasFiberData : 1;
            UINT16 SkipThreadAttach : 1;
            UINT16 WerInShipAssertCode : 1;
            UINT16 RanProcessInit : 1;
            UINT16 ClonedThread : 1;
            UINT16 SuppressDebugMsg : 1;
            UINT16 DisableUserStackWalk : 1;
            UINT16 RtlExceptionAttached : 1;
            UINT16 InitialThread : 1;
            UINT16 SessionAware : 1;
            UINT16 LoadOwner : 1;
            UINT16 LoaderWorker : 1;
            UINT16 SkipLoaderInit : 1;
            UINT16 SpareSameTebBits : 1;
        };
    };

    void* TxnScopeEnterCallback;
    void* TxnScopeExitCallback;
    void* TxnScopeContext;
    UINT32 LockCount;
    INT32 WowTebOffset;
    void* ResourceRetValue;
    void* ReservedForWdf;
    //INT64 ReservedForCrt;
    //GUID EffectiveContainerId;
} TEB, *PTEB;
static_assert(sizeof(TEB) == 0x1820, "TEB size is wrong!");


#ifdef _WIN64
#define NtCurrentTeb()  ((TEB* const)__readgsqword(offsetof(NT_TIB, Self)))
#else
#define NtCurrentTeb()  ((TEB* const)__readfsdword(offsetof(NT_TIB, Self)))
#endif

#define NtCurrentPeb()  ((PEB* const)(NtCurrentTeb()->ProcessEnvironmentBlock))
