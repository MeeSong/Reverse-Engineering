#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

enum PROCESS_ACCESS_MASK : UINT32
{
    PROCESS_TERMINATE = 0x0001,
    PROCESS_CREATE_THREAD = 0x0002,
    PROCESS_SET_SESSIONID = 0x0004,
    PROCESS_VM_OPERATION = 0x0008,
    PROCESS_VM_READ = 0x0010,
    PROCESS_VM_WRITE = 0x0020,
    PROCESS_DUP_HANDLE = 0x0040,
    PROCESS_CREATE_PROCESS = 0x0080,
    PROCESS_SET_QUOTA = 0x0100,
    PROCESS_SET_INFORMATION = 0x0200,
    PROCESS_QUERY_INFORMATION = 0x0400,
    PROCESS_SET_PORT = 0x0800,
    PROCESS_SUSPEND_RESUME = 0x0800,
    PROCESS_QUERY_LIMITED_INFORMATION = 0x1000,
    PROCESS_SET_LIMITED_INFORMATION = 0x2000,

    PROCESS_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFFF),
};

enum THREAD_ACCESS_MASK : UINT32
{
    THREAD_TERMINATE = 0x0001,
    THREAD_SUSPEND_RESUME = 0x0002,
    THREAD_GET_CONTEXT = 0x0008,
    THREAD_SET_CONTEXT = 0x0010,
    THREAD_SET_INFORMATION = 0x0020,
    THREAD_QUERY_INFORMATION = 0x0040,
    THREAD_SET_THREAD_TOKEN = 0x0080,
    THREAD_IMPERSONATE = 0x0100,
    THREAD_DIRECT_IMPERSONATION = 0x0200,
    THREAD_SET_LIMITED_INFORMATION = 0x0400,
    THREAD_QUERY_LIMITED_INFORMATION = 0x0800,
    THREAD_RESUME = 0x1000,

    THREAD_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFFF),
};

enum JOB_ACCESS_MASK : UINT32
{
    JOB_OBJECT_ASSIGN_PROCESS = 0x0001,
    JOB_OBJECT_SET_ATTRIBUTES = 0x0002,
    JOB_OBJECT_QUERY = 0x0004,
    JOB_OBJECT_TERMINATE = 0x0008,
    JOB_OBJECT_SET_SECURITY_ATTRIBUTES = 0x0010,

    JOB_OBJECT_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F),
};


#define GDI_HANDLE_BUFFER_SIZE32 34
#define GDI_HANDLE_BUFFER_SIZE64 60

#if defined(_WIN64)
#define GDI_HANDLE_BUFFER_SIZE GDI_HANDLE_BUFFER_SIZE64
#else
#define GDI_HANDLE_BUFFER_SIZE GDI_HANDLE_BUFFER_SIZE32
#endif

typedef UINT32 GDI_HANDLE_BUFFER[GDI_HANDLE_BUFFER_SIZE];

typedef UINT32 GDI_HANDLE_BUFFER32[GDI_HANDLE_BUFFER_SIZE32];
typedef UINT32 GDI_HANDLE_BUFFER64[GDI_HANDLE_BUFFER_SIZE64];

#define FLS_MAXIMUM_AVAILABLE   128
#define TLS_MINIMUM_AVAILABLE   64
#define TLS_EXPANSION_SLOTS     1024


typedef struct _PEB_LDR_DATA
{
    UINT32 Length;
    BOOLEAN Initialized;
    HANDLE SsHandle;
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    void* EntryInProgress;
    BOOLEAN ShutdownInProgress;
    HANDLE ShutdownThreadId;
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct _INITIAL_TEB
{
    struct
    {
        void* OldStackBase;
        void* OldStackLimit;
    } OldInitialTeb;
    void* StackBase;
    void* StackLimit;
    void* StackAllocationBase;
} INITIAL_TEB, *PINITIAL_TEB;

typedef struct _WOW64_PROCESS
{
    void* Wow64;
} WOW64_PROCESS, *PWOW64_PROCESS;

//////////////////////////////////////////////////////////////////////////

//
// NtQueryInformationProcess
//

enum PROCESSINFOCLASS : UINT32
{
    ProcessBasicInformation, // q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
    ProcessQuotaLimits, // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
    ProcessIoCounters, // q: IO_COUNTERS
    ProcessVmCounters, // q: VM_COUNTERS, VM_COUNTERS_EX, VM_COUNTERS_EX2
    ProcessTimes, // q: KERNEL_USER_TIMES
    ProcessBasePriority, // s: KPRIORITY
    ProcessRaisePriority, // s: ULONG
    ProcessDebugPort, // q: HANDLE
    ProcessExceptionPort, // s: HANDLE
    ProcessAccessToken, // s: PROCESS_ACCESS_TOKEN
    ProcessLdtInformation, // qs: PROCESS_LDT_INFORMATION // 10
    ProcessLdtSize, // s: PROCESS_LDT_SIZE
    ProcessDefaultHardErrorMode, // qs: ULONG
    ProcessIoPortHandlers, // (kernel-mode only)
    ProcessPooledUsageAndLimits, // q: POOLED_USAGE_AND_LIMITS
    ProcessWorkingSetWatch, // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
    ProcessUserModeIOPL,
    ProcessEnableAlignmentFaultFixup, // s: BOOLEAN
    ProcessPriorityClass, // qs: PROCESS_PRIORITY_CLASS
    ProcessWx86Information,
    ProcessHandleCount, // q: ULONG, PROCESS_HANDLE_INFORMATION // 20
    ProcessAffinityMask, // s: KAFFINITY
    ProcessPriorityBoost, // qs: ULONG
    ProcessDeviceMap, // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
    ProcessSessionInformation, // q: PROCESS_SESSION_INFORMATION
    ProcessForegroundInformation, // s: PROCESS_FOREGROUND_BACKGROUND
    ProcessWow64Information, // q: ULONG_PTR
    ProcessImageFileName, // q: UNICODE_STRING
    ProcessLUIDDeviceMapsEnabled, // q: ULONG
    ProcessBreakOnTermination, // qs: ULONG
    ProcessDebugObjectHandle, // q: HANDLE // 30
    ProcessDebugFlags, // qs: ULONG
    ProcessHandleTracing, // q: PROCESS_HANDLE_TRACING_QUERY; s: size 0 disables, otherwise enables
    ProcessIoPriority, // qs: IO_PRIORITY_HINT
    ProcessExecuteFlags, // qs: ULONG
    ProcessResourceManagement,
    ProcessCookie, // q: ULONG
    ProcessImageInformation, // q: SECTION_IMAGE_INFORMATION
    ProcessCycleTime, // q: PROCESS_CYCLE_TIME_INFORMATION // since VISTA
    ProcessPagePriority, // q: ULONG
    ProcessInstrumentationCallback, // 40
    ProcessThreadStackAllocation, // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
    ProcessWorkingSetWatchEx, // q: PROCESS_WS_WATCH_INFORMATION_EX[]
    ProcessImageFileNameWin32, // q: UNICODE_STRING
    ProcessImageFileMapping, // q: HANDLE (input)
    ProcessAffinityUpdateMode, // qs: PROCESS_AFFINITY_UPDATE_MODE
    ProcessMemoryAllocationMode, // qs: PROCESS_MEMORY_ALLOCATION_MODE
    ProcessGroupInformation, // q: USHORT[]
    ProcessTokenVirtualizationEnabled, // s: ULONG
    ProcessConsoleHostProcess, // q: ULONG_PTR
    ProcessWindowInformation, // q: PROCESS_WINDOW_INFORMATION // 50
    ProcessHandleInformation, // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
    ProcessMitigationPolicy, // s: PROCESS_MITIGATION_POLICY_INFORMATION
    ProcessDynamicFunctionTableInformation,
    ProcessHandleCheckingMode,
    ProcessKeepAliveCount, // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
    ProcessRevokeFileHandles, // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
    ProcessWorkingSetControl, // s: PROCESS_WORKING_SET_CONTROL
    ProcessHandleTable, // since WINBLUE
    ProcessCheckStackExtentsMode,
    ProcessCommandLineInformation, // q: UNICODE_STRING // 60
    ProcessProtectionInformation, // q: PS_PROTECTION
    ProcessMemoryExhaustion, // PROCESS_MEMORY_EXHAUSTION_INFO // since THRESHOLD
    ProcessFaultInformation, // PROCESS_FAULT_INFORMATION
    ProcessTelemetryIdInformation, // PROCESS_TELEMETRY_ID_INFORMATION
    ProcessCommitReleaseInformation, // PROCESS_COMMIT_RELEASE_INFORMATION
    ProcessDefaultCpuSetsInformation,
    ProcessAllowedCpuSetsInformation,
    ProcessSubsystemProcess,
    ProcessJobMemoryInformation, // PROCESS_JOB_MEMORY_INFO
    ProcessInPrivate, // since THRESHOLD2 // 70
    ProcessRaiseUMExceptionOnInvalidHandleClose,
    ProcessIumChallengeResponse,
    ProcessChildProcessInformation, // PROCESS_CHILD_PROCESS_INFORMATION
    ProcessHighGraphicsPriorityInformation,
    ProcessSubsystemInformation, // q: SUBSYSTEM_INFORMATION_TYPE // since REDSTONE2
    ProcessEnergyValues, // PROCESS_ENERGY_VALUES, PROCESS_EXTENDED_ENERGY_VALUES
    ProcessActivityThrottleState, // PROCESS_ACTIVITY_THROTTLE_STATE
    ProcessActivityThrottlePolicy, // PROCESS_ACTIVITY_THROTTLE_POLICY
    ProcessWin32kSyscallFilterInformation,
    ProcessDisableSystemAllowedCpuSets,
    ProcessWakeInformation, // PROCESS_WAKE_INFORMATION
    ProcessEnergyTrackingState, // PROCESS_ENERGY_TRACKING_STATE
    MaxProcessInfoClass
};

extern"C" NTSTATUS NtQueryInformationProcess(
    HANDLE ProcessHandle,
    PROCESSINFOCLASS ProcessInformationClass,
    void* ProcessInformation,
    UINT32 ProcessInformationLength,
    UINT32* ReturnLength);

//////////////////////////////////////////////////////////////////////////

//
// NtQueryInformationThread
//

typedef enum _THREADINFOCLASS : UINT32
{
    ThreadBasicInformation, // q: THREAD_BASIC_INFORMATION
    ThreadTimes, // q: KERNEL_USER_TIMES
    ThreadPriority, // s: KPRIORITY
    ThreadBasePriority, // s: LONG
    ThreadAffinityMask, // s: KAFFINITY
    ThreadImpersonationToken, // s: HANDLE
    ThreadDescriptorTableEntry, // q: DESCRIPTOR_TABLE_ENTRY (or WOW64_DESCRIPTOR_TABLE_ENTRY)
    ThreadEnableAlignmentFaultFixup, // s: BOOLEAN
    ThreadEventPair,
    ThreadQuerySetWin32StartAddress, // q: PVOID
    ThreadZeroTlsCell, // 10
    ThreadPerformanceCount, // q: LARGE_INTEGER
    ThreadAmILastThread, // q: ULONG
    ThreadIdealProcessor, // s: ULONG
    ThreadPriorityBoost, // qs: ULONG
    ThreadSetTlsArrayAddress,
    ThreadIsIoPending, // q: ULONG
    ThreadHideFromDebugger, // s: void
    ThreadBreakOnTermination, // qs: ULONG
    ThreadSwitchLegacyState,
    ThreadIsTerminated, // q: ULONG // 20
    ThreadLastSystemCall, // q: THREAD_LAST_SYSCALL_INFORMATION
    ThreadIoPriority, // qs: IO_PRIORITY_HINT
    ThreadCycleTime, // q: THREAD_CYCLE_TIME_INFORMATION
    ThreadPagePriority, // q: ULONG
    ThreadActualBasePriority,
    ThreadTebInformation, // q: THREAD_TEB_INFORMATION (requires THREAD_GET_CONTEXT + THREAD_SET_CONTEXT)
    ThreadCSwitchMon,
    ThreadCSwitchPmu,
    ThreadWow64Context, // q: WOW64_CONTEXT
    ThreadGroupInformation, // q: GROUP_AFFINITY // 30
    ThreadUmsInformation, // q: THREAD_UMS_INFORMATION
    ThreadCounterProfiling,
    ThreadIdealProcessorEx, // q: PROCESSOR_NUMBER
    ThreadCpuAccountingInformation, // since WIN8
    ThreadSuspendCount, // since WINBLUE
    ThreadHeterogeneousCpuPolicy, // q: KHETERO_CPU_POLICY // since THRESHOLD
    ThreadContainerId, // q: GUID
    ThreadNameInformation, // qs: THREAD_NAME_INFORMATION
    ThreadSelectedCpuSets,
    ThreadSystemThreadInformation, // q: SYSTEM_THREAD_INFORMATION // 40
    ThreadActualGroupAffinity, // since THRESHOLD2
    ThreadDynamicCodePolicyInfo,
    ThreadExplicitCaseSensitivity,
    ThreadWorkOnBehalfTicket,
    ThreadSubsystemInformation, // q: SUBSYSTEM_INFORMATION_TYPE // since REDSTONE2
    ThreadDbgkWerReportActive,
    ThreadAttachContainer,
    MaxThreadInfoClass
} THREADINFOCLASS;

extern"C" NTSTATUS NtQueryInformationThread(
    HANDLE ThreadHandle,
    THREADINFOCLASS ThreadInformationClass,
    void* ThreadInformation,
    UINT32 ThreadInformationLength,
    UINT32* ReturnLength
);

//////////////////////////////////////////////////////////////////////////

extern"C" NTSTATUS NtSuspendThread(
    HANDLE ThreadHandle,
    UINT32* PreviousSuspendCount
);

extern"C" NTSTATUS NtResumeThread(
    HANDLE ThreadHandle,
    UINT32* PreviousSuspendCount
);

//////////////////////////////////////////////////////////////////////////

//
// CreateProcess dwCreationFlag values
//

enum PROCESS_CREATION_FLAGS : UINT32
{
    DEBUG_PROCESS = 0x00000001,
    DEBUG_ONLY_THIS_PROCESS = 0x00000002,
    CREATE_SUSPENDED = 0x00000004,
    DETACHED_PROCESS = 0x00000008,

    CREATE_NEW_CONSOLE = 0x00000010,
    NORMAL_PRIORITY_CLASS = 0x00000020,
    IDLE_PRIORITY_CLASS = 0x00000040,
    HIGH_PRIORITY_CLASS = 0x00000080,

    REALTIME_PRIORITY_CLASS = 0x00000100,
    CREATE_NEW_PROCESS_GROUP = 0x00000200,
    CREATE_UNICODE_ENVIRONMENT = 0x00000400,
    CREATE_SEPARATE_WOW_VDM = 0x00000800,

    CREATE_SHARED_WOW_VDM = 0x00001000,
    CREATE_FORCEDOS = 0x00002000,
    BELOW_NORMAL_PRIORITY_CLASS = 0x00004000,
    ABOVE_NORMAL_PRIORITY_CLASS = 0x00008000,

    INHERIT_PARENT_AFFINITY = 0x00010000,
    INHERIT_CALLER_PRIORITY = 0x00020000,    // Deprecated
    CREATE_PROTECTED_PROCESS = 0x00040000,
    EXTENDED_STARTUPINFO_PRESENT = 0x00080000,

    PROCESS_MODE_BACKGROUND_BEG= 0x00100000,
    PROCESS_MODE_BACKGROUND_END = 0x00200000,

    CREATE_BREAKAWAY_FROM_JOB = 0x01000000,
    CREATE_PRESERVE_CODE_AUTHZ_LEVEL = 0x02000000,
    CREATE_DEFAULT_ERROR_MODE = 0x04000000,
    CREATE_NO_WINDOW = 0x08000000,

    PROFILE_USER = 0x10000000,
    PROFILE_KERNEL = 0x20000000,
    PROFILE_SERVER = 0x40000000,
    CREATE_IGNORE_SYSTEM_DEFAULT = 0x80000000,
};

//
// CreateProcess StartupInfo.dwFlags value
//

enum STARTUP_INFO_FLAGS : UINT32
{
    STARTF_USESHOWWINDOW = 0x00000001,
    STARTF_USESIZE = 0x00000002,
    STARTF_USEPOSITION = 0x00000004,
    STARTF_USECOUNTCHARS = 0x00000008,

    STARTF_USEFILLATTRIBUTE = 0x00000010,
    STARTF_RUNFULLSCREEN = 0x00000020,  // ignored for non-x86 platforms
    STARTF_FORCEONFEEDBACK = 0x00000040,
    STARTF_FORCEOFFFEEDBACK = 0x00000080,

    STARTF_USESTDHANDLES = 0x00000100,
    STARTF_USEHOTKEY = 0x00000200,
    STARTF_SHELLPRIVATE = 0x00000400,
    STARTF_TITLEISLINKNAME = 0x00000800,

    STARTF_TITLEISAPPID = 0x00001000,
    STARTF_PREVENTPINNING = 0x00002000,
};

//////////////////////////////////////////////////////////////////////////

// 
// Struct and flag for CreateProcessInternal
//


typedef struct _UMS_CREATE_THREAD_ATTRIBUTES {
    UINT32 UmsVersion;
    void* UmsContext;
    void* UmsCompletionList;
} UMS_CREATE_THREAD_ATTRIBUTES, *PUMS_CREATE_THREAD_ATTRIBUTES;


#define PROTECTION_LEVEL_SAME   (UINT32(0xFFFFFFFF))

enum PROCESS_CREATION_MITIGATION_POLICY : UINT64
{
    //
    // Define legacy creation mitigation policy options, which are straight
    // bitmasks.  Bits 0-5 are legacy bits.
    //

    PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE = 0x01,
    PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE = 0x02,
    PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE = 0x04,

    //
    // Define mandatory ASLR options.  Mandatory ASLR forcibly rebases images that
    // are not dynamic base compatible by acting as though there were an image base
    // collision at load time.
    //
    // Note that 'require relocations' mode refuses load of images that do not have
    // a base relocation section.
    //

    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_MASK = (0x00000003 << 8),
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_DEFER = (0x00000000 << 8),
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON = (0x00000001 << 8),
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF = (0x00000002 << 8),
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON_REQ_RELOCS = (0x00000003 << 8),

    //
    // Define heap terminate on corruption options.  Note that 'always off' does
    // not override the default opt-in for binaries with current subsystem versions
    // set in the image header.
    //
    // Heap terminate on corruption is user mode enforced.
    //

    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_MASK = (0x00000003 << 12),
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_DEFER = (0x00000000 << 12),
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON = (0x00000001 << 12),
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_OFF = (0x00000002 << 12),
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_RESERVED = (0x00000003 << 12),

    //
    // Define bottom up randomization (includes stack randomization) options,
    // i.e. randomization of the lowest user address.
    //

    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_MASK = (0x00000003 << 16),
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_DEFER = (0x00000000 << 16),
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON = (0x00000001 << 16),
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF = (0x00000002 << 16),
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_RESERVED = (0x00000003 << 16),

    //
    // Define high entropy bottom up randomization.  Note that high entropy bottom
    // up randomization is effective if and only if bottom up ASLR is also enabled.
    //
    // N.B.  High entropy mode is only meaningful for native 64-bit processes.  in
    //       high entropy mode, up to 1TB of bottom up variance is enabled.
    //

    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_MASK = (0x00000003 << 20),
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_DEFER = (0x00000000 << 20),
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON = (0x00000001 << 20),
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF = (0x00000002 << 20),
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_RESERVED = (0x00000003 << 20),

    //
    // Define handle checking enforcement options.  Handle checking enforcement
    // causes an exception to be raised immediately on a bad handle reference,
    // versus simply returning a failure status from the handle reference.
    //

    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_MASK = (0x00000003 << 24),
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_DEFER = (0x00000000 << 24),
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON = (0x00000001 << 24),
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF = (0x00000002 << 24),
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_RESERVED = (0x00000003 << 24),

    //
    // Define win32k system call disable options.  Win32k system call disable
    // prevents a process from making Win32k calls.
    //

    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_MASK = (0x00000003 << 28),
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_DEFER = (0x00000000 << 28),
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON = (0x00000001 << 28),
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF = (0x00000002 << 28),
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_RESERVED = (0x00000003 << 28),

    //
    // Define the extension point disable options.  Extension point disable allows
    // a process to opt-out of loading various arbitrary extension point DLLs.
    //

    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_MASK = (0x00000003ui64 << 32),
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_DEFER = (0x00000000ui64 << 32),
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON = (0x00000001ui64 << 32),
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF = (0x00000002ui64 << 32),
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_RESERVED = (0x00000003ui64 << 32),

    //
    // Define dynamic code options.
    //

    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK = (0x00000003ui64 << 36),
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_DEFER = (0x00000000ui64 << 36),
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON = (0x00000001ui64 << 36),
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_OFF = (0x00000002ui64 << 36),
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON_ALLOW_OPT_OUT = (0x00000003ui64 << 36),

    //
    // Define Control Flow Guard (CFG) mitigation policy options.  Control Flow
    // Guard allows indirect control transfers to be checked at runtime.
    //

    PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_MASK = (0x00000003ui64 << 40),
    PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_DEFER = (0x00000000ui64 << 40),
    PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_ON = (0x00000001ui64 << 40),
    PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_OFF = (0x00000002ui64 << 40),
    PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_RESERVED = (0x00000003ui64 << 40),

    //
    // Define module signature options.  When enabled, this option will
    // block mapping of non-microsoft binaries.
    //

    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK = (0x00000003ui64 << 44),
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_DEFER = (0x00000000ui64 << 44),
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON = (0x00000001ui64 << 44),
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF = (0x00000002ui64 << 44),
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_RESERVED = (0x00000003ui64 << 44),

    // Windows 10+

    //
    // Define Font Disable Policy.  When enabled, this option will
    // block loading Non System Fonts.
    //

    PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_MASK = (0x00000003ui64 << 48),
    PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_DEFER = (0x00000000ui64 << 48),
    PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_ALWAYS_ON = (0x00000001ui64 << 48),
    PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_ALWAYS_OFF = (0x00000002ui64 << 48),
    PROCESS_CREATION_MITIGATION_POLICY_AUDIT_NONSYSTEM_FONTS = (0x00000003ui64 << 48),

    //
    // Define remote image load options.  When enabled, this option will
    // block mapping of images from remote devices.
    //

    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_MASK = (0x00000003ui64 << 52),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_DEFER = (0x00000000ui64 << 52),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_ALWAYS_ON = (0x00000001ui64 << 52),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_ALWAYS_OFF = (0x00000002ui64 << 52),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_RESERVED = (0x00000003ui64 << 52),

    //
    // Define low IL image load options.  When enabled, this option will
    // block mapping of images that have the low mandatory label.
    //

    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_MASK = (0x00000003ui64 << 56),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_DEFER = (0x00000000ui64 << 56),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_ALWAYS_ON = (0x00000001ui64 << 56),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_ALWAYS_OFF = (0x00000002ui64 << 56),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_RESERVED = (0x00000003ui64 << 56),

    //
    // Define image load options to prefer System32 images compared to 
    // the same images in application directory. When enabled, this option
    // will prefer loading images from system32 folder.
    //

    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_MASK = (0x00000003ui64 << 60),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_DEFER = (0x00000000ui64 << 60),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_ALWAYS_ON = (0x00000001ui64 << 60),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_ALWAYS_OFF = (0x00000002ui64 << 60),
    PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_RESERVED = (0x00000003ui64 << 60),
};

enum PROC_THREAD_ATTRIBUTE_NUM : UINT32
{
    ProcThreadAttributeParentProcess = 0, // in PHANDLE
    ProcThreadAttributeExtendedFlags = 1,
    ProcThreadAttributeHandleList = 2,
    ProcThreadAttributeGroupAffinity = 3, // in PGROUP_AFFINITY
    ProcThreadAttributePreferredNode = 4, // in INT16*
    ProcThreadAttributeIdealProcessor = 5, 
    ProcThreadAttributeUmsThread = 6, // in PUMS_CREATE_THREAD_ATTRIBUTES
    ProcThreadAttributeMitigationPolicy = 7, // in UINT32 or UINT64. PROCESS_CREATION_MITIGATION_POLICY
    ProcThreadAttributePackageFullName = 8,
    ProcThreadAttributeSecurityCapabilities = 9,
    ProcThreadAttributeConsoleReference = 10,
    ProcThreadAttributeProtectionLevel = 11,

    ProcThreadAttributeMaxWin8 = 12,

    ProcThreadAttributeUnknown0 = 12,
    ProcThreadAttributeJobList = 13,
    ProcThreadAttributeChildProcessPolicy = 14,
    ProcThreadAttributeAllApplicationPackagesPolicy = 15,
    ProcThreadAttributeWin32kFilter = 16,
    ProcThreadAttributeSafeOpenPromptOriginClaim = 17,
    ProcThreadAttributeDesktopAppPolicy = 18,
    ProcThreadAttributeBnoIsolation = 19,
    ProcThreadAttributeMax
};

#define PROC_THREAD_ATTRIBUTE_NUMBER    0x0000FFFF
#define PROC_THREAD_ATTRIBUTE_THREAD    0x00010000  // Attribute may be used with thread creation
#define PROC_THREAD_ATTRIBUTE_INPUT     0x00020000  // Attribute is input only
#define PROC_THREAD_ATTRIBUTE_ADDITIVE  0x00040000  // Attribute may be "accumulated," e.g. bitmasks, counters, etc.

#define ProcThreadAttributeValue(Number, Thread, Input, Additive) \
    (((Number) & PROC_THREAD_ATTRIBUTE_NUMBER) | \
     ((Thread) ? PROC_THREAD_ATTRIBUTE_THREAD : 0) | \
     ((Input) ? PROC_THREAD_ATTRIBUTE_INPUT : 0) | \
     ((Additive) ? PROC_THREAD_ATTRIBUTE_ADDITIVE : 0))

#define PROC_THREAD_ATTRIBUTE_PARENT_PROCESS \
    ProcThreadAttributeValue (ProcThreadAttributeParentProcess, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_EXTENDED_FLAGS \
    ProcThreadAttributeValue (ProcThreadAttributeExtendedFlags, FALSE, TRUE, TRUE)
#define PROC_THREAD_ATTRIBUTE_HANDLE_LIST \
    ProcThreadAttributeValue (ProcThreadAttributeHandleList, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY \
    ProcThreadAttributeValue (ProcThreadAttributeGroupAffinity, TRUE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_PREFERRED_NODE \
    ProcThreadAttributeValue (ProcThreadAttributePreferredNode, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR \
    ProcThreadAttributeValue (ProcThreadAttributeIdealProcessor, TRUE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_UMS_THREAD \
    ProcThreadAttributeValue (ProcThreadAttributeUmsThread, TRUE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY \
    ProcThreadAttributeValue (ProcThreadAttributeMitigationPolicy, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_PACKAGE_FULL_NAME \
    ProcThreadAttributeValue (ProcThreadAttributePackageFullName, FALSE, TRUE, TRUE)
#define PROC_THREAD_ATTRIBUTE_SECURITY_CAPABILITIES \
    ProcThreadAttributeValue (ProcThreadAttributeSecurityCapabilities, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_CONSOLE_REFERENCE \
    ProcThreadAttributeValue (ProcThreadAttributeConsoleReference, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL \
    ProcThreadAttributeValue (ProcThreadAttributeProtectionLevel, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_UNKNOWN_0 \
    ProcThreadAttributeValue (ProcThreadAttributeUnknown0, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_JOB_LIST \
    ProcThreadAttributeValue (ProcThreadAttributeJobList, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_CHILD_PROCESS_POLICY \
    ProcThreadAttributeValue (ProcThreadAttributeChildProcessPolicy, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_ALL_APPLICATION_PACKAGES_POLICY \
    ProcThreadAttributeValue (ProcThreadAttributeAllApplicationPackagesPolicy, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_WIN32K_FILTER \
    ProcThreadAttributeValue (ProcThreadAttributeWin32kFilter, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_SAFE_OPEN_PROMPT_ORIGIN_CLAIM \
    ProcThreadAttributeValue (ProcThreadAttributeSafeOpenPromptOriginClaim, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_DESKTOP_APP_POLICY \
    ProcThreadAttributeValue (ProcThreadAttributeDesktopAppPolicy, FALSE, TRUE, FALSE)
#define PROC_THREAD_ATTRIBUTE_BNO_ISOLATION \
    ProcThreadAttributeValue (ProcThreadAttributeBnoIsolation, FALSE, TRUE, FALSE)

typedef struct _PROC_THREAD_ATTRIBUTE
{
    UINT_PTR Attribute;
    SIZE_T Size;
    UINT_PTR Value;

}PROC_THREAD_ATTRIBUTE, *LPPROC_THREAD_ATTRIBUTE;

typedef struct _PROC_THREAD_ATTRIBUTE_LIST
{
    UINT32 PresentFlags;
    UINT32 AttributeCount;
    UINT32 LastAttribute;
    UINT32 SpareUlong0;
    PROC_THREAD_ATTRIBUTE* ExtendedFlagsAttribute;
    PROC_THREAD_ATTRIBUTE Attributes[1];
}PROC_THREAD_ATTRIBUTE_LIST, *LPPROC_THREAD_ATTRIBUTE_LIST;

//////////////////////////////////////////////////////////////////////////

// 
// Struct and flag for NtCreateUserProcess
//

enum PROCESS_PRIORITY_CLASSES : UINT8
{
    PROCESS_PRIORITY_CLASS_INVALID,
    PROCESS_PRIORITY_CLASS_IDLE,
    PROCESS_PRIORITY_CLASS_NORMAL,
    PROCESS_PRIORITY_CLASS_HIGH,
    PROCESS_PRIORITY_CLASS_REALTIME,
    PROCESS_PRIORITY_CLASS_BELOW_NORMAL,
    PROCESS_PRIORITY_CLASS_ABOVE_NORMAL,
};

typedef struct _PROCESS_PRIORITY_CLASS {
    BOOLEAN Foreground;
    UINT8 PriorityClass;
} PROCESS_PRIORITY_CLASS, *PPROCESS_PRIORITY_CLASS;

enum PROCESS_CREATE_FLAGS : UINT32
{
    PROCESS_CREATE_FLAGS_BREAKAWAY                  = 0x00000001,
    PROCESS_CREATE_FLAGS_NO_DEBUG_INHERIT           = 0x00000002,
    PROCESS_CREATE_FLAGS_INHERIT_HANDLES            = 0x00000004,
    PROCESS_CREATE_FLAGS_OVERRIDE_ADDRESS_SPACE     = 0x00000008,
    PROCESS_CREATE_FLAGS_LARGE_PAGES                = 0x00000010,
    PROCESS_CREATE_FLAGS_ALL_LARGE_PAGE_FLAGS       = PROCESS_CREATE_FLAGS_LARGE_PAGES,
    PROCESS_CREATE_FLAGS_LARGE_PAGE_SYSTEM_DLL      = 0x00000020,

    // Extended PROCESS_CREATE_FLAGS_
    PROCESS_CREATE_FLAGS_PROTECTED_PROCESS          = 0x00000040,
    PROCESS_CREATE_FLAGS_CREATE_SESSION             = 0x00000080, // ?
    PROCESS_CREATE_FLAGS_INHERIT_FROM_PARENT        = 0x00000100,
    PROCESS_CREATE_FLAGS_SUSPENDED                  = 0x00000200,
    PROCESS_CREATE_FLAGS_EXTENDED_UNKNOWN           = 0x00000400,

    PROCESS_CREATE_FLAGS_LEGAL_MASK = (PROCESS_CREATE_FLAGS_BREAKAWAY | \
    PROCESS_CREATE_FLAGS_NO_DEBUG_INHERIT | \
        PROCESS_CREATE_FLAGS_INHERIT_HANDLES | \
        PROCESS_CREATE_FLAGS_OVERRIDE_ADDRESS_SPACE | \
        PROCESS_CREATE_FLAGS_ALL_LARGE_PAGE_FLAGS),
};

enum THREAD_CREATE_FLAGS : UINT32
{
    THREAD_CREATE_FLAGS_CREATE_SUSPENDED        = 0x00000001,
    THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH      = 0x00000002,
    THREAD_CREATE_FLAGS_HIDE_FROM_DEBUGGER      = 0x00000004,
    THREAD_CREATE_FLAGS_HAS_SECURITY_DESCRIPTOR = 0x00000010,
    THREAD_CREATE_FLAGS_ACCESS_CHECK_IN_TARGET  = 0x00000020,
    THREAD_CREATE_FLAGS_INITIAL_THREAD          = 0x00000080,
};


enum PS_STD_HANDLE_STATE : UINT8
{
    PsNeverDuplicate,
    PsRequestDuplicate, // duplicate standard handles specified by PseudoHandleMask, and only if StdHandleSubsystemType matches the image subsystem
    PsAlwaysDuplicate,  // always duplicate standard handles
    PsMaxStdHandleStates
};

typedef struct _PS_STD_HANDLE_INFO
{
    union
    {
        UINT32 Flags;
        struct
        {
            UINT32 StdHandleState : 2;
            UINT32 PseudoHandleMask : 3;
        };
    };
    UINT32 StdHandleSubsystemType;

}PS_STD_HANDLE_INFO, *PPS_STD_HANDLE_INFO;


typedef enum _PS_PROTECTED_TYPE
{
    PsProtectedTypeNone,
    PsProtectedTypeProtectedLight,
    PsProtectedTypeProtected,
    PsProtectedTypeMax
} PS_PROTECTED_TYPE;

typedef enum _PS_PROTECTED_SIGNER
{
    PsProtectedSignerNone,
    PsProtectedSignerAuthenticode,
    PsProtectedSignerCodeGen,
    PsProtectedSignerAntimalware,
    PsProtectedSignerLsa,
    PsProtectedSignerWindows,
    PsProtectedSignerWinTcb,
    PsProtectedSignerWinSystem,
    PsProtectedSignerApp,
    PsProtectedSignerMax
} PS_PROTECTED_SIGNER;

#define PS_PROTECTED_SIGNER_MASK    0xFF
#define PS_PROTECTED_AUDIT_MASK     0x08
#define PS_PROTECTED_TYPE_MASK      0x07

// e.g vProtectionLevel.Level = PsProtectedValue(PsProtectedSignerCodeGen, FALSE, PsProtectedTypeProtectedLight)
#define PsProtectedValue(aSigner, aAudit, aType) \
    ( \
    ((aSigner & PS_PROTECTED_SIGNER_MASK) << 4) | \
    ((aAudit & PS_PROTECTED_AUDIT_MASK) << 3) | \
    (aType & PS_PROTECTED_TYPE_MASK)\
    )

// e.g InitializePsProtection(&vProtectionLevel, PsProtectedSignerCodeGen, FALSE, PsProtectedTypeProtectedLight)
#define InitializePsProtection(aProtectionLevelPtr, aSigner, aAudit, aType) { \
    (aProtectionLevelPtr)->Signer = aSigner;  \
    (aProtectionLevelPtr)->Audit = aAudit;    \
    (aProtectionLevelPtr)->Type = aType;      \
    }

typedef struct _PS_PROTECTION
{
    union
    {
        UINT8 Level;
        struct
        {
            UINT8 Type : 3;
            UINT8 Audit : 1;
            UINT8 Signer : 4;
        };
    };
} PS_PROTECTION, *PPS_PROTECTION;

enum PS_ATTRIBUTE_NUM : UINT32
{
    PsAttributeParentProcess,       // in HANDLE
    PsAttributeDebugPort,           // in HANDLE
    PsAttributeToken,               // in HANDLE
    PsAttributeClientId,            // out PCLIENT_ID
    PsAttributeTebAddress,          // out PTEB *
    PsAttributeImageName,           // in PWSTR
    PsAttributeImageInfo,           // out PSECTION_IMAGE_INFORMATION
    PsAttributeMemoryReserve,       // in PPS_MEMORY_RESERVE
    PsAttributePriorityClass,       // in UINT8
    PsAttributeErrorMode,           // in UINT32
    PsAttributeStdHandleInfo,       // 10, in PPS_STD_HANDLE_INFO
    PsAttributeHandleList,          // in PHANDLE
    PsAttributeGroupAffinity,       // in PGROUP_AFFINITY
    PsAttributePreferredNode,       // in PUSHORT
    PsAttributeIdealProcessor,      // in PPROCESSOR_NUMBER
    PsAttributeUmsThread,           // ? in PUMS_CREATE_THREAD_ATTRIBUTES
    PsAttributeMitigationOptions,   // in UINT8
    PsAttributeProtectionLevel,     // in UINT8
    PsAttributeSecureProcess,       // since THRESHOLD
    PsAttributeJobList,
    PsAttributeChildProcessPolicy,  // since THRESHOLD2
    PsAttributeAllApplicationPackagesPolicy, // since REDSTONE
    PsAttributeWin32kFilter,
    PsAttributeSafeOpenPromptOriginClaim,
    PsAttributeBnoIsolation,        // PS_BNO_ISOLATION_PARAMETERS
    PsAttributeDesktopAppPolicy,    // in UINT32
    PsAttributeMax
};

#define PS_ATTRIBUTE_NUMBER_MASK    0x0000ffff
#define PS_ATTRIBUTE_THREAD         0x00010000 // may be used with thread creation
#define PS_ATTRIBUTE_INPUT          0x00020000 // input only
#define PS_ATTRIBUTE_ADDITIVE       0x00040000 // "accumulated" e.g. bitmasks, counters, etc.

#define PsAttributeValue(Number, Thread, Input, Additive) \
    (((Number) & PS_ATTRIBUTE_NUMBER_MASK) | \
    ((Thread) ? PS_ATTRIBUTE_THREAD : 0) | \
    ((Input) ? PS_ATTRIBUTE_INPUT : 0) | \
    ((Additive) ? PS_ATTRIBUTE_ADDITIVE : 0))

#define PS_ATTRIBUTE_PARENT_PROCESS \
    PsAttributeValue(PsAttributeParentProcess, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_DEBUG_PORT \
    PsAttributeValue(PsAttributeDebugPort, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_TOKEN \
    PsAttributeValue(PsAttributeToken, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_CLIENT_ID \
    PsAttributeValue(PsAttributeClientId, TRUE, FALSE, FALSE)
#define PS_ATTRIBUTE_TEB_ADDRESS \
    PsAttributeValue(PsAttributeTebAddress, TRUE, FALSE, FALSE)
#define PS_ATTRIBUTE_IMAGE_NAME \
    PsAttributeValue(PsAttributeImageName, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_IMAGE_INFO \
    PsAttributeValue(PsAttributeImageInfo, FALSE, FALSE, FALSE)
#define PS_ATTRIBUTE_MEMORY_RESERVE \
    PsAttributeValue(PsAttributeMemoryReserve, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_PRIORITY_CLASS \
    PsAttributeValue(PsAttributePriorityClass, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_ERROR_MODE \
    PsAttributeValue(PsAttributeErrorMode, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_STD_HANDLE_INFO \
    PsAttributeValue(PsAttributeStdHandleInfo, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_HANDLE_LIST \
    PsAttributeValue(PsAttributeHandleList, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_GROUP_AFFINITY \
    PsAttributeValue(PsAttributeGroupAffinity, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_PREFERRED_NODE \
    PsAttributeValue(PsAttributePreferredNode, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_IDEAL_PROCESSOR \
    PsAttributeValue(PsAttributeIdealProcessor, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_UMS_THREAD \
    PsAttributeValue(PsAttributeUmsThread, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_MITIGATION_OPTIONS \
    PsAttributeValue(PsAttributeMitigationOptions, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_PROTECTION_LEVEL \
    PsAttributeValue(PsAttributeProtectionLevel, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_SECURE_PROCESS \
    PsAttributeValue(PsAttributeSecureProcess, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_JOB_LIST \
    PsAttributeValue(PsAttributeJobList, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_CHILD_PROCESS_POLICY \
    PsAttributeValue(PsAttributeChildProcessPolicy, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_ALL_APPLICATION_PACKAGES_POLICY \
    PsAttributeValue(PsAttributeAllApplicationPackagesPolicy, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_WIN32K_FILTER \
    PsAttributeValue(PsAttributeWin32kFilter, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_SAFE_OPEN_PROMPT_ORIGIN_CLAIM \
    PsAttributeValue(PsAttributeSafeOpenPromptOriginClaim, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_BNO_ISOLATION \
    PsAttributeValue(PsAttributeBnoIsolation, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_DESKTOP_APP_POLICY \
    PsAttributeValue(PsAttributeDesktopAppPolicy, FALSE, TRUE, FALSE)


typedef struct _PS_ATTRIBUTE
{
    UINT_PTR Attribute;
    SIZE_T Size;
    union
    {
        UINT_PTR Value;
        void* ValuePtr;
    };
    SIZE_T* ReturnLength;
} PS_ATTRIBUTE, *PPS_ATTRIBUTE;

typedef struct _PS_ATTRIBUTE_LIST
{
    SIZE_T TotalLength;
    PS_ATTRIBUTE Attributes[1]; // Attributes[8] or Attributes[PsAttributeMax] ?
} PS_ATTRIBUTE_LIST, *PPS_ATTRIBUTE_LIST;

enum PS_CREATE_STATE : UINT32
{
    PsCreateInitialState,
    PsCreateFailOnFileOpen,
    PsCreateFailOnSectionCreate,
    PsCreateFailExeFormat,
    PsCreateFailMachineMismatch,
    PsCreateFailExeName, // Debugger specified
    PsCreateSuccess,
    PsCreateMaximumStates
};

typedef struct _PS_CREATE_INFO
{
    SIZE_T Size;
    PS_CREATE_STATE State;

    union
    {
        // PsCreateInitialState
        struct
        {
            union
            {
                UINT32 InitFlags;
                struct
                {
                    UINT8 WriteOutputOnExit : 1;
                    UINT8 DetectManifest : 1;
                    UINT8 IFEOSkipDebugger : 1;
                    UINT8 IFEODoNotPropagateKeyState : 1;
                    UINT8 SpareBits1 : 4;
                    UINT8 SpareBits2 : 8;
                    UINT16 ProhibitedImageCharacteristics : 16;
                };
            };
            ACCESS_MASK AdditionalFileAccess;
        } InitState;

        // PsCreateFailOnSectionCreate
        struct
        {
            HANDLE FileHandle;
        } FailSection;

        // PsCreateFailExeFormat
        struct
        {
            UINT16 DllCharacteristics;
        } ExeFormat;

        // PsCreateFailExeName
        struct
        {
            HANDLE IFEOKey;
        } ExeName;

        // PsCreateSuccess
        struct
        {
            union
            {
                UINT32 OutputFlags;
                struct
                {
                    UINT8 ProtectedProcess : 1;
                    UINT8 AddressSpaceOverride : 1;
                    UINT8 DevOverrideEnabled : 1; // from Image File Execution Options
                    UINT8 ManifestDetected : 1;
                    UINT8 ProtectedProcessLight : 1;
                    UINT8 SpareBits1 : 3;
                    UINT8 SpareBits2 : 8;
                    UINT16 SpareBits3 : 16;
                };
            };
            HANDLE FileHandle;
            HANDLE SectionHandle;
            struct _RTL_USER_PROCESS_PARAMETERS* UserProcessParametersNative;
            UINT32 UserProcessParametersWow64;  // RTL_USER_PROCESS_PARAMETERS32*
            UINT32 CurrentParameterFlags;
            struct _PEB* PebAddressNative;
            UINT32 PebAddressWow64;             // PEB32*
            void* ManifestAddress;
            UINT32 ManifestSize;
        } SuccessState;
    };
}PS_CREATE_INFO, *PPS_CREATE_INFO;
static_assert(sizeof(PS_CREATE_INFO) == 0x58, "PS_CREATE_INFO size is wrong!");

extern"C" NTSTATUS NtCreateUserProcess(
    HANDLE* ProcessHandle,
    HANDLE* ThreadHandle,
    ACCESS_MASK ProcessDesiredAccess,
    ACCESS_MASK ThreadDesiredAccess,
    POBJECT_ATTRIBUTES ProcessObjectAttributes,
    POBJECT_ATTRIBUTES ThreadObjectAttributes,
    UINT32 ProcessFlags, // PROCESS_CREATE_FLAGS_*
    UINT32 ThreadFlags, // THREAD_CREATE_FLAGS_*
    void* ProcessParameters, // PRTL_USER_PROCESS_PARAMETERS
    PPS_CREATE_INFO CreateInfo,
    PPS_ATTRIBUTE_LIST AttributeList
);
