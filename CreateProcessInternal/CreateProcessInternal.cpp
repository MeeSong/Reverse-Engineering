#include "CreateProcessInternal.h"

#include <doserror.h>
#include <ntstatus.h>
#include <ntpebteb.h>
#include <ntrtl.h>
#include <ntdbg.h>
#include <ntexapi.h>
#include <ntmmapi.h>

//////////////////////////////////////////////////////////////////////////

#define GetCurrentProcess() (HANDLE(-1))
#define GetCurrentThread()  (HANDLE(-2))

//////////////////////////////////////////////////////////////////////////
ptrdiff_t BaseStaticServerData{ 0 };

fun$BaseFormatObjectAttributes      BaseFormatObjectAttributes{ nullptr };
fun$BaseIsDosApplication            BaseIsDosApplication{ nullptr };
fun$BaseGetNamedObjectDirectory     BaseGetNamedObjectDirectory{ nullptr };

fun$BasepProcessInvalidImage        BasepProcessInvalidImage{ nullptr };
fun$BasepCheckWinSaferRestrictions  BasepCheckWinSaferRestrictions{ nullptr };
fun$BasepAppXExtension              BasepAppXExtension{ nullptr };
fun$BasepAppContainerEnvironmentExtension BasepAppContainerEnvironmentExtension{ nullptr };

fun$RaiseInvalid16BitExeError       RaiseInvalid16BitExeError{ nullptr };

fun$NtVdm64CreateProcessInternal    NtVdm64CreateProcessInternal{ nullptr };


//////////////////////////////////////////////////////////////////////////

void InitializeBaseData()
{
    enum : UINT32
    {
        BASESRV_SERVERDLL_INDEX = 1,
    };

    static bool vIsInitialize = false;
    if (vIsInitialize) return;

    ///////////////////////////

    BaseStaticServerData = (((ptrdiff_t)(NtCurrentPeb()->ReadOnlySharedMemoryBase) \
        + (ptrdiff_t)(NtCurrentPeb()->ReadOnlyStaticServerData[BASESRV_SERVERDLL_INDEX]) \
        - (ptrdiff_t)(NtCurrentPeb()->CsrServerReadOnlySharedMemoryBase)));

    ///////////////////////////

    vIsInitialize = true;
}

inline BOOLEAN IsDefaultSeparateVDM()
{
    // Win10 Used for real machine debugging
    if (NtCurrentPeb()->OSMajorVersion == 10)
        return (*(BOOLEAN*)(BaseStaticServerData + 0x958));

    return (*(BOOLEAN*)(BaseStaticServerData + 0x744));
}

DOSERROR InitializeDependentFunction()
{
    DOSERROR vDosError = ERROR_SUCCESS;

    static bool vIsInitialize = false;

    if (vIsInitialize)
    {
        return ERROR_SUCCESS;
    }

    for (;;)
    {
        BaseFormatObjectAttributes = (fun$BaseFormatObjectAttributes)GetProcAddress(
            GetModuleHandleW(L"Kernelbase.dll"), "BaseFormatObjectAttributes");
        if (nullptr == BaseFormatObjectAttributes)
        {
            break;
        }

        BaseIsDosApplication = (fun$BaseIsDosApplication)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "BaseIsDosApplication");
        if (nullptr == BaseIsDosApplication)
        {
            break;
        }

        BaseGetNamedObjectDirectory = (fun$BaseGetNamedObjectDirectory)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "BaseGetNamedObjectDirectory");
        if (nullptr == BaseGetNamedObjectDirectory)
        {
            break;
        }

        BasepProcessInvalidImage = (fun$BasepProcessInvalidImage)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "BasepProcessInvalidImage");
        if (nullptr == BasepProcessInvalidImage)
        {
            break;
        }

        BasepCheckWinSaferRestrictions = (fun$BasepCheckWinSaferRestrictions)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "BasepCheckWinSaferRestrictions");
        if (nullptr == BasepCheckWinSaferRestrictions)
        {
            break;
        }

        BasepAppXExtension = (fun$BasepAppXExtension)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "BasepAppXExtension");
        if (nullptr == BasepAppXExtension)
        {
            break;
        }

        BasepAppContainerEnvironmentExtension = (fun$BasepAppContainerEnvironmentExtension)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "BasepAppContainerEnvironmentExtension");
        if (nullptr == BasepAppContainerEnvironmentExtension)
        {
            break;
        }

        RaiseInvalid16BitExeError = (fun$RaiseInvalid16BitExeError)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "RaiseInvalid16BitExeError");
        if (nullptr == RaiseInvalid16BitExeError)
        {
            break;
        }

        NtVdm64CreateProcessInternal = (fun$NtVdm64CreateProcessInternal)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "NtVdm64CreateProcessInternalW");
        if (nullptr == NtVdm64CreateProcessInternal)
        {
            break;
        }

        vIsInitialize = true;
        RtlSetLastWin32Error(ERROR_SUCCESS);
        break;
    }

    vDosError = RtlGetLastWin32Error();
    return vDosError;
}

DOSERROR BaseSetLastNtError(NTSTATUS aStatus)
{
    DOSERROR vDosError = ERROR_SUCCESS;
    vDosError = (DOSERROR)RtlNtStatusToDosError(aStatus);
    RtlSetLastWin32Error(vDosError);
    return vDosError;
}

void* BasepIsRealtimeAllowed(BOOLEAN aKeep, BOOLEAN aImpersonate)
{
    UINT32 vPrivilege = SE_INC_BASE_PRIORITY_PRIVILEGE;
    void* vState;
    NTSTATUS vStatus;

    vStatus = RtlAcquirePrivilege(&vPrivilege, 1, aImpersonate ?
        RTL_ACQUIRE_PRIVILEGE_IMPERSONATE : RTL_ACQUIRE_PRIVILEGE_NULL, &vState);
    if (!NT_SUCCESS(vStatus)) return nullptr;

    if (!aKeep)
    {
        RtlReleasePrivilege(vState);
        vState = (void*)TRUE;
    }

    return vState;
}

NTSTATUS BasepConvertMitigationPolicyFlags(
    PROC_THREAD_ATTRIBUTE* aAttribute,
    UINT64* aMitigationPolicyFlags)
{
    UINT64 vPolicy{ 0 };

    if (aAttribute->Size == sizeof(UINT32))
    {
        vPolicy = *(UINT32*)(aAttribute->Value);
    }
    else if (aAttribute->Size == sizeof(UINT64))
    {
        vPolicy = *(UINT64*)(aAttribute->Value);
    }
    else
    {
        return STATUS_INVALID_PARAMETER;
    }

    *aMitigationPolicyFlags = 0;

    if (vPolicy & ~(PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE
        | PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE
        | PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE
        | PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_MASK
        | PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK
        // Windows 10 +
        // | PROCESS_CREATION_MITIGATION_POLICY_FONT_DISABLE_MASK
        // | PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_REMOTE_MASK
        // | PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_NO_LOW_LABEL_MASK
        // | PROCESS_CREATION_MITIGATION_POLICY_IMAGE_LOAD_PREFER_SYSTEM32_MASK
        ))
    {
        return STATUS_INVALID_PARAMETER;
    }

    if ((vPolicy & (PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE
        | PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE))
        == PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE)
    {
        *aMitigationPolicyFlags |= 0x0000000000000001;
    }
    else if ((vPolicy & (PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE
        | PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE))
        == PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE)
    {
        *aMitigationPolicyFlags |= 0x0000000000000002;
    }
    else if ((vPolicy & (PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE
        | PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE))
        == (PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE
            | PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE))
    {
        *aMitigationPolicyFlags |= 0x0000000000000003;
    }
    else
    {
        *aMitigationPolicyFlags |= 0x0000000000000002;
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE)
    {
        *aMitigationPolicyFlags |= 0x0000000000000010;
    }
    else
    {
        *aMitigationPolicyFlags |= 0x0000000000000030;
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_MASK)
    {
        UINT64 vForceRelocateImagesPolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_MASK);
        if (vForceRelocateImagesPolicy == PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000000000000100;
        }
        else if (vForceRelocateImagesPolicy == PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000000000000200;
        }
        else if (vForceRelocateImagesPolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF))
        {
            *aMitigationPolicyFlags |= 0x0000000000000300;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_MASK)
    {
        UINT64 vHeapTerminatePolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_MASK);
        if (vHeapTerminatePolicy == PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000000000001000;
        }
        else if (vHeapTerminatePolicy == PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000000000002000;
        }
        else if (vHeapTerminatePolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_MASK)
    {
        UINT64 vBottomUpASLRPolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_MASK);
        if (vBottomUpASLRPolicy == PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000000000010000;
        }
        else if (vBottomUpASLRPolicy == PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000000000020000;
        }
        else if (vBottomUpASLRPolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_MASK)
    {
        UINT64 vHighEntropyASLRPolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_MASK);
        if (vHighEntropyASLRPolicy == PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000000000100000;
        }
        else if (vHighEntropyASLRPolicy == PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000000000200000;
        }
        else if (vHighEntropyASLRPolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_MASK)
    {
        UINT64 vStrictHandleChecksPolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_MASK);
        if (vStrictHandleChecksPolicy == PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000000001000000;
        }
        else if (vStrictHandleChecksPolicy == PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000000002000000;
        }
        else if (vStrictHandleChecksPolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_MASK)
    {
        UINT64 vWin32kSystemCallDisablePolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_MASK);
        if (vWin32kSystemCallDisablePolicy == PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000000010000000;
        }
        else if (vWin32kSystemCallDisablePolicy == PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000000020000000;
        }
        else if (vWin32kSystemCallDisablePolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_MASK)
    {
        UINT64 vExtensionPointDisablePolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_MASK);
        if (vExtensionPointDisablePolicy == PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000000100000000;
        }
        else if (vExtensionPointDisablePolicy == PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000000200000000;
        }
        else if (vExtensionPointDisablePolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK)
    {
        UINT64 vProhibitDynamicCodePolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK);
        if (vProhibitDynamicCodePolicy == PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000001000000000;
        }
        else if (vProhibitDynamicCodePolicy == PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000002000000000;
        }
        else if (vProhibitDynamicCodePolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_MASK)
    {
        UINT64 vControlFlowGuardPolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_MASK);
        if (vControlFlowGuardPolicy == PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000010000000000;
        }
        else if (vControlFlowGuardPolicy == PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000020000000000;
        }
        else if (vControlFlowGuardPolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_CONTROL_FLOW_GUARD_DEFER
        {
            assert(FALSE);
        }
    }

    if (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK)
    {
        UINT64 vBlockNonMicrosoftBinariesPolicy = (vPolicy & PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK);
        if (vBlockNonMicrosoftBinariesPolicy == PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON)
        {
            *aMitigationPolicyFlags |= 0x0000100000000000;
        }
        else if (vBlockNonMicrosoftBinariesPolicy == PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF)
        {
            *aMitigationPolicyFlags |= 0x0000200000000000;
        }
        else if (vBlockNonMicrosoftBinariesPolicy ==
            (PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON
                | PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF))
        {
            return STATUS_INVALID_PARAMETER;
        }
        else // PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_DEFER
        {
            assert(FALSE);
        }
    }

    return STATUS_SUCCESS;
}

// Windows 10 的版本, 这个函数多了几个参数...
// 应该是多了几个 Attribute 的处理
NTSTATUS BasepConvertWin32AttributeList(
    LPPROC_THREAD_ATTRIBUTE_LIST aThreadAttributeList,
    BOOLEAN aIsThread,
    UINT32* aExtendedFlags,
    UNICODE_STRING* aPackageFullName,
    SECURITY_CAPABILITIES** aSecurityCapabilities, // AppContainer 
    BOOLEAN* aHasHandleList,
    HANDLE* aParentProcessHandle,
    HANDLE* aConsoleHandle,
    UINT64* aMitigationPolicyFlags,
    PS_ATTRIBUTE_LIST* aPsAttributeList,
    UINT32* aPsAttrubutesCount,
    UINT32 aMaxPsAttributeCount)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    //
    // 检查参数
    //

    assert(aIsThread || (aPackageFullName && aSecurityCapabilities));
    assert(*aPsAttrubutesCount < aMaxPsAttributeCount);
    assert(aMaxPsAttributeCount - *aPsAttrubutesCount >= 8);

    if ((aThreadAttributeList->LastAttribute > aThreadAttributeList->AttributeCount)
        || (aThreadAttributeList->LastAttribute > ProcThreadAttributeMaxWin8))
    {
        return STATUS_INVALID_PARAMETER;
    }

    //
    // 处理 Thread attribute list
    //

    UINT32 vPsAttributesCount = *aPsAttrubutesCount;
    UINT32 vPresentFlags{ 0 };
    UINT32 vExtendedFlags{ 0 };

    if (aThreadAttributeList->LastAttribute)
    {
        for (UINT32 vIndex = 0; vIndex < aThreadAttributeList->LastAttribute; ++vIndex)
        {
            PROC_THREAD_ATTRIBUTE* vAttribute = &(aThreadAttributeList->Attributes[vIndex]);
            UINT_PTR vAttributeValue = vAttribute->Attribute;
            UINT32 vPresentFlag = 1 << (vAttribute->Attribute & PROC_THREAD_ATTRIBUTE_NUMBER);

            if (!(vPresentFlag & aThreadAttributeList->PresentFlags)
                || (vPresentFlag & vPresentFlags)
                || aIsThread
                || (vAttributeValue & PROC_THREAD_ATTRIBUTE_THREAD))
            {
                break;
            }

            bool vIsNormalAttribute = true;
            UINT_PTR vPsAttribute{ 0 };

            switch (vAttributeValue)
            {
            default:
            {
                vStatus = STATUS_INVALID_PARAMETER;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_PARENT_PROCESS:
            {
                assert(!aIsThread && aParentProcessHandle);

                if (vAttribute->Size != sizeof(HANDLE))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                aPsAttributeList->Attributes[vPsAttributesCount].Attribute = PS_ATTRIBUTE_PARENT_PROCESS;
                aPsAttributeList->Attributes[vPsAttributesCount].Size = sizeof(HANDLE);
                aPsAttributeList->Attributes[vPsAttributesCount].ValuePtr = *(HANDLE*)(vAttribute->Value);
                aPsAttributeList->Attributes[vPsAttributesCount].ReturnLength = nullptr;

                ++vPsAttributesCount;

                *aParentProcessHandle = *(HANDLE*)(vAttribute->Value);
                vIsNormalAttribute = false;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_EXTENDED_FLAGS:
            {
                if (vAttribute->Size != sizeof(UINT32))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                vExtendedFlags = UINT32(vAttribute->Value);
                if (vExtendedFlags & UINT32(~(7)))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                vIsNormalAttribute = false;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_HANDLE_LIST:
            {
                assert(!aIsThread && aHasHandleList);

                if (vAttribute->Size <= 0 || vAttribute->Size & 7)
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                vPsAttribute = PS_ATTRIBUTE_HANDLE_LIST;
                *aHasHandleList = TRUE;

                break;
            }

            case PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY:
            {
                if (!aIsThread || vAttribute->Size != sizeof(GROUP_AFFINITY))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                vPsAttribute = PS_ATTRIBUTE_GROUP_AFFINITY;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_PREFERRED_NODE:
            {
                if (vAttribute->Size != sizeof(UINT16))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                vPsAttribute = PS_ATTRIBUTE_PREFERRED_NODE;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR:
            {
                if (!aIsThread || vAttribute->Size != sizeof(PROCESSOR_NUMBER))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                vPsAttribute = PS_ATTRIBUTE_IDEAL_PROCESSOR;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_UMS_THREAD:
            {
                if (!aIsThread || vAttribute->Size != sizeof(UMS_CREATE_THREAD_ATTRIBUTES))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                vPsAttribute = PS_ATTRIBUTE_UMS_THREAD;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY:
            {
                assert(!aIsThread && aMitigationPolicyFlags);

                if ((vAttribute->Size - sizeof(UINT32)) & SIZE_T(~(sizeof(UINT32))))
                {
                    // Only UINT32 or UINT64
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                vStatus = BasepConvertMitigationPolicyFlags(
                    vAttribute, aMitigationPolicyFlags);
                if (NT_WARNING(vStatus))
                {
                    break;
                }

                aPsAttributeList->Attributes[vPsAttributesCount].Attribute = PS_ATTRIBUTE_SECURE_PROCESS;
                aPsAttributeList->Attributes[vPsAttributesCount].Size = sizeof(UINT64);
                aPsAttributeList->Attributes[vPsAttributesCount].ValuePtr = aMitigationPolicyFlags;
                aPsAttributeList->Attributes[vPsAttributesCount].ReturnLength = nullptr;

                ++vPsAttributesCount;
                vIsNormalAttribute = false;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_PACKAGE_FULL_NAME:
            {
                assert(!aIsThread && aPackageFullName);

                if (!vAttribute->Size
                    || vAttribute->Size & 1
                    || vAttribute->Size >= 0xFFFF)
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                aPackageFullName->Buffer = (PWSTR)vAttribute->Value;
                aPackageFullName->Length = UINT16(vAttribute->Size);
                aPackageFullName->MaximumLength = UINT16(vAttribute->Size);

                if (L'\0' == aPackageFullName->Buffer[vAttribute->Size / sizeof(wchar_t) - 1])
                {
                    aPackageFullName->Length -= sizeof(wchar_t);
                }

                vIsNormalAttribute = false;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_SECURITY_CAPABILITIES:
            {
                if (vAttribute->Size != sizeof(SECURITY_CAPABILITIES)
                    || ((SECURITY_CAPABILITIES*)(vAttribute->Value))->Reserved)
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                *aSecurityCapabilities = (SECURITY_CAPABILITIES*)(vAttribute->Value);
                vIsNormalAttribute = false;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_CONSOLE_REFERENCE:
            {
                assert(!aIsThread && aConsoleHandle);

                if (vAttribute->Size != sizeof(HANDLE))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                *aConsoleHandle = HANDLE(vAttribute->Value);
                vIsNormalAttribute = false;
                break;
            }

            case PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL:
            {
                assert(!aIsThread);

                if (vAttribute->Size != sizeof(UINT32))
                {
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                PS_PROTECTION vProtectionLevel{};

                switch (*(UINT32*)(vAttribute->Value))
                {
                default:
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;

                case 0:
                    InitializePsProtection(
                        &vProtectionLevel,
                        PsProtectedSignerWinTcb,
                        FALSE,
                        PsProtectedTypeProtectedLight);
                    break;

                case 1:
                    InitializePsProtection(
                        &vProtectionLevel,
                        PsProtectedSignerWindows,
                        FALSE,
                        PsProtectedTypeProtected);
                    break;

                case 2:
                    InitializePsProtection(
                        &vProtectionLevel,
                        PsProtectedSignerWindows,
                        FALSE,
                        PsProtectedTypeProtectedLight);
                    break;

                case 3:
                    InitializePsProtection(
                        &vProtectionLevel,
                        PsProtectedSignerAntimalware,
                        FALSE,
                        PsProtectedTypeProtectedLight);
                    break;

                case 4:
                    InitializePsProtection(
                        &vProtectionLevel,
                        PsProtectedSignerLsa,
                        FALSE,
                        PsProtectedTypeProtectedLight);
                    break;

                case 5:
                    InitializePsProtection(
                        &vProtectionLevel,
                        PsProtectedSignerWinTcb,
                        FALSE,
                        PsProtectedTypeProtected);
                    break;

                case 6:
                    InitializePsProtection(
                        &vProtectionLevel,
                        PsProtectedSignerCodeGen,
                        FALSE,
                        PsProtectedTypeProtectedLight);
                    break;

                case 7:
                    InitializePsProtection(
                        &vProtectionLevel,
                        PsProtectedSignerAuthenticode,
                        FALSE,
                        PsProtectedTypeProtected);
                    break;

                case PROTECTION_LEVEL_SAME:
                {
                    vStatus = NtQueryInformationProcess(
                        GetCurrentProcess(),
                        ProcessProtectionInformation,
                        &vProtectionLevel,
                        sizeof(vProtectionLevel),
                        nullptr);
                    break;
                }

                }

                if (!NT_SUCCESS(vStatus))
                {
                    break;
                }

                assert(vPsAttributesCount < aMaxPsAttributeCount);

                aPsAttributeList->Attributes[vPsAttributesCount].Attribute = PS_ATTRIBUTE_PROTECTION_LEVEL;
                aPsAttributeList->Attributes[vPsAttributesCount].Size = sizeof(vProtectionLevel);
                aPsAttributeList->Attributes[vPsAttributesCount].Value = vProtectionLevel.Level;
                aPsAttributeList->Attributes[vPsAttributesCount].ReturnLength = nullptr;

                vIsNormalAttribute = false;
                break;
            }

            }

            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            if (vIsNormalAttribute)
            {
                assert(vPsAttributesCount < aMaxPsAttributeCount);

                aPsAttributeList->Attributes[vPsAttributesCount].Attribute = vPsAttribute;
                aPsAttributeList->Attributes[vPsAttributesCount].Size = vAttribute->Size;
                aPsAttributeList->Attributes[vPsAttributesCount].Value = vAttribute->Value;
                aPsAttributeList->Attributes[vPsAttributesCount].ReturnLength = nullptr;
            }

            vPresentFlags |= vPresentFlag;
        }
    }

    assert(vPsAttributesCount <= aMaxPsAttributeCount);

    if (aThreadAttributeList->PresentFlags & ~vPresentFlags & 2)
    {
        PROC_THREAD_ATTRIBUTE* vExtendedFlagsAttribute = aThreadAttributeList->ExtendedFlagsAttribute;

        assert(vExtendedFlagsAttribute);

        if ((vExtendedFlagsAttribute->Attribute != PROC_THREAD_ATTRIBUTE_EXTENDED_FLAGS)
            || vExtendedFlagsAttribute->Size != sizeof(UINT32))
        {
            vStatus = STATUS_INVALID_PARAMETER;
            return vStatus;
        }

        vExtendedFlags = UINT32(vExtendedFlagsAttribute->Value);
        if (vExtendedFlags & UINT32(~(7)))
        {
            vStatus = STATUS_INVALID_PARAMETER;
            return vStatus;
        }

        vPresentFlags |= 2;
    }

    if (aThreadAttributeList->PresentFlags & (~vPresentFlags))
    {
        vStatus = STATUS_INVALID_PARAMETER;
        return vStatus;
    }

    *aPsAttrubutesCount = vPsAttributesCount;
    *aExtendedFlags = vExtendedFlags;

    return vStatus;
}

// Duplicate LowboxToken
NTSTATUS BasepCreateTokenFromLowboxToken(
    HANDLE aToken,
    SECURITY_CAPABILITIES* aSecurityCapabilities,
    HANDLE* aLowBoxToken)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    TOKEN_APPCONTAINER_INFORMATION *vAppContainer{ nullptr };
    TOKEN_GROUPS *vTokenGroups{ nullptr };

    for (;;)
    {
        UINT32 vQuerySize{};

        vStatus = NtQueryInformationToken(aToken, TokenAppContainerSid, 0, 0, &vQuerySize);
        if (vStatus != STATUS_BUFFER_TOO_SMALL)
        {
            break;
        }

        vAppContainer = (TOKEN_APPCONTAINER_INFORMATION*)RtlAllocateHeap(RtlProcessHeap(), 0, vQuerySize);
        if (nullptr == vAppContainer)
        {
            vStatus = STATUS_NO_MEMORY;
            break;
        }

        vStatus = NtQueryInformationToken(aToken, TokenAppContainerSid, vAppContainer, vQuerySize, &vQuerySize);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        if (!RtlEqualSid(vAppContainer->TokenAppContainer, aSecurityCapabilities->AppContainerSid))
        {
            vStatus = STATUS_INVALID_PARAMETER;
            break;
        }

        UINT32 vSidType{ 0 };

        vStatus = RtlGetAppContainerSidType(aSecurityCapabilities->AppContainerSid, &vSidType);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        if (vSidType != 1)
        {
            vStatus = NtQueryInformationToken(aToken, TokenCapabilities, 0, 0, &vQuerySize);
            if (vStatus != STATUS_BUFFER_TOO_SMALL)
            {
                break;
            }

            vTokenGroups = (TOKEN_GROUPS*)RtlAllocateHeap(RtlProcessHeap(), 0, vQuerySize);
            if (nullptr == vTokenGroups)
            {
                vStatus = STATUS_NO_MEMORY;
                break;
            }

            vStatus = NtQueryInformationToken(aToken, TokenCapabilities, vTokenGroups, vQuerySize, &vQuerySize);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            if (aSecurityCapabilities->CapabilityCount != vTokenGroups->GroupCount)
            {
                vStatus = STATUS_INVALID_PARAMETER;
                break;
            }

            bool vIsMatch{ vTokenGroups->GroupCount ? true : false };

            for (UINT32 i = 0; i < vTokenGroups->GroupCount; ++i)
            {
                if ((RtlEqualSid(vTokenGroups->Groups[i].Sid, aSecurityCapabilities->Capabilities[i].Sid))
                    && (vTokenGroups->Groups[i].Attributes == aSecurityCapabilities->Capabilities[i].Attributes))
                {
                    vIsMatch = true;
                    break;
                }
            }

            if (!vIsMatch)
            {
                vStatus = STATUS_INVALID_PARAMETER;
                break;
            }
        }

        vStatus = NtDuplicateToken(aToken, TOKEN_ALL_ACCESS, nullptr, FALSE, TokenPrimary, aLowBoxToken);
        break;
    }

    if (vTokenGroups)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vTokenGroups);
    }

    if (vAppContainer)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vAppContainer);
    }

    return vStatus;
}

NTSTATUS BasepOpenBaseObjectDirectory(
    UINT32 aAppContainerSidType,
    UINT32 aSessionId,
    UNICODE_STRING* aParentSidString,
    HANDLE* aDirectoryHandle)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    wchar_t vDirectoryPathBuffer[MAXIMUM_FILENAME_LENGTH] {};
    UNICODE_STRING vDirectoryPath{};

    if ((aAppContainerSidType != 2)
        && (aAppContainerSidType != 1 || !aParentSidString || !aParentSidString->Buffer))
    {
        return STATUS_INVALID_PARAMETER;
    }

    for (;;)
    {
        *aDirectoryHandle = nullptr;

        if (aSessionId)
        {
            wchar_t *vSessionsPart = L"\\Sessions";

            if (aAppContainerSidType == 2)
            {
                swprintf_s(vDirectoryPathBuffer, ARRAYSIZE(vDirectoryPathBuffer), L"%ws\\%ld\\BaseNamedObjects", vSessionsPart, aSessionId);
            }
            else
            {
                swprintf_s(vDirectoryPathBuffer, ARRAYSIZE(vDirectoryPathBuffer), L"%ws\\%ld\\AppContainerNamedObjects\\%ws",
                    vSessionsPart, aSessionId, aParentSidString->Buffer);
            }
        }
        else
        {
            swprintf_s(vDirectoryPathBuffer, ARRAYSIZE(vDirectoryPathBuffer), L"\\BaseNamedObjects");
        }

        RtlInitUnicodeString(&vDirectoryPath, vDirectoryPathBuffer);

        OBJECT_ATTRIBUTES vObjectAttributes{};
        InitializeObjectAttributes(&vObjectAttributes, &vDirectoryPath, 0, nullptr, nullptr);

        vStatus = NtOpenDirectoryObject(
            aDirectoryHandle, 
            STANDARD_RIGHTS_READ | DIRECTORY_QUERY | DIRECTORY_TRAVERSE, 
            &vObjectAttributes);
        break;
    }

    return vStatus;
}

BOOLEAN IsLogonSid(PSID aSid)
{
    static SID_IDENTIFIER_AUTHORITY vSIDAuthNT = SECURITY_NT_AUTHORITY;

    PSID_IDENTIFIER_AUTHORITY vSidIdentifier{ nullptr };
    vSidIdentifier = RtlIdentifierAuthoritySid(aSid);

    // 如果不符合 SECURITY_NT_AUTHORITY 则返回 false
    if (memcmp(vSidIdentifier, &vSIDAuthNT, SID_IDENTIFIER_AUTHORITY_LENGTH))
    {
        return FALSE;
    }

    if (SECURITY_LOGON_IDS_RID_COUNT == *RtlSubAuthorityCountSid(aSid)
        && SECURITY_LOGON_IDS_RID == *RtlSubAuthoritySid(aSid, 0))
    {
        return TRUE;
    }

    return FALSE;
}

enum BUILD_SECURITY_DESCRIPTOR_SID_FLAGS: UINT32
{
    BUILD_SID_NULL          = 0x0,
    BUILD_SID_ADMINS        = 0x1,
    BUILD_SID_RESTRICTED    = 0x2,
    BUILD_SID_EVERYONE      = 0x4,
};

NTSTATUS BasepBuildPackageSecurityDescriptor(
    SECURITY_DESCRIPTOR* aSecurityDescriptor,
    PSID aAppContainerSid,
    PSID aTokenSid,
    UINT32 aFlags,
    SECURITY_DESCRIPTOR* aNewSecurityDescriptor)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    PACL vDAcl{ nullptr };
    PACL vNewAcl{ nullptr };

    PSID vAdminSid{ nullptr };
    PSID vEveryoneSid{ nullptr };
    PSID vRestrictedSid{ nullptr };

    for (;;)
    {
        vStatus = RtlCreateSecurityDescriptor(aNewSecurityDescriptor, SECURITY_DESCRIPTOR_REVISION);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        BOOLEAN vDaclParent{};
        BOOLEAN vDaclDefaulted{};

        vStatus = RtlGetDaclSecurityDescriptor(aSecurityDescriptor, &vDaclParent, &vDAcl, &vDaclDefaulted);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        ACL_SIZE_INFORMATION vDaclSizeInfo{};
        vStatus = RtlQueryInformationAcl(vDAcl, &vDaclSizeInfo, sizeof(vDaclSizeInfo), AclSizeInformation);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        ACL_REVISION_INFORMATION vDaclRevisionInfo{};
        vStatus = RtlQueryInformationAcl(vDAcl, &vDaclRevisionInfo, sizeof(vDaclRevisionInfo), AclRevisionInformation);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        static SID_IDENTIFIER_AUTHORITY vSIAAuthWorld = SECURITY_WORLD_SID_AUTHORITY;
        static SID_IDENTIFIER_AUTHORITY vSIAAuthNT    = SECURITY_NT_AUTHORITY;

        UINT32 vSidCount{ 0 };
        UINT32 vSidTotalSize{ 0 };

        if (aFlags & BUILD_SID_ADMINS)
        {
            // 管理员组 SID
            vStatus = RtlAllocateAndInitializeSid(&vSIAAuthNT, 2, SECURITY_BUILTIN_DOMAIN_RID,
                DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &vAdminSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            ++vSidCount;
            vSidTotalSize += RtlLengthSid(vAdminSid);
        }
        
        if (aFlags & BUILD_SID_RESTRICTED)
        {
            // 受限组 SID
            vStatus = RtlAllocateAndInitializeSid(&vSIAAuthNT, 1, SECURITY_RESTRICTED_CODE_RID,
                0, 0, 0, 0, 0, 0, 0, &vRestrictedSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            ++vSidCount;
            vSidTotalSize += RtlLengthSid(vRestrictedSid);
        }

        if (aFlags & BUILD_SID_EVERYONE)
        {
            // Everyone 组 SID
            vStatus = RtlAllocateAndInitializeSid(&vSIAAuthWorld, 1, SECURITY_WORLD_RID,
                0, 0, 0, 0, 0, 0, 0, &vEveryoneSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            ++vSidCount;
            vSidTotalSize += RtlLengthSid(vEveryoneSid);
        }

        vSidCount += 2;
        vSidTotalSize += 2 * RtlLengthSid(aTokenSid);

        vSidCount += 2;
        vSidTotalSize += 2 * RtlLengthSid(aAppContainerSid);

        UINT32 vNewAclSize = 0xFFFFFFFC & 
            (vSidTotalSize
            + (sizeof(PSID) * vSidCount)
            + vDaclSizeInfo.AclBytesInUse
            + (sizeof(ACL) * 2)
            + 3);
        
        vNewAcl = (PACL)RtlAllocateHeap(RtlProcessHeap(), 0, vNewAclSize);
        if (nullptr == vNewAcl)
        {
            vStatus = STATUS_NO_MEMORY;
            break;
        }
        RtlSecureZeroMemory(vNewAcl, vNewAclSize);

        vStatus = RtlCreateAcl(vNewAcl, vNewAclSize, vDaclRevisionInfo.AclRevision);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        //
        // Copy old ace
        //

        ACCESS_ALLOWED_ACE *vOldAce{ nullptr };
        vStatus = RtlGetAce(vDAcl, 0, (void**)&vOldAce);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = RtlAddAce(vNewAcl, vDaclRevisionInfo.AclRevision, 0, vOldAce, vDaclSizeInfo.AclBytesInUse - sizeof(ACL));
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        bool vIsExistUserSid{ false };

        if (vDaclSizeInfo.AceCount)
        {
            ACCESS_ALLOWED_ACE *vAce{ nullptr };

            for (UINT32 i = 0; i < vDaclSizeInfo.AceCount; ++i)
            {
                if (!NT_SUCCESS(RtlGetAce(vNewAcl, i, (void**)&vAce)))
                {
                    break;
                }

                if (IsLogonSid(PSID(&vAce->SidStart)))
                {
                    vAce->Mask = DIRECTORY_ALL_ACCESS;
                }

                if (RtlEqualSid(aTokenSid, PSID(&vAce->SidStart)))
                {
                    vIsExistUserSid = true;
                    break;
                }
            }
        }

        if (!vIsExistUserSid)
        {
            // 添加 ACE (特殊) - 用户SID
            vStatus = RtlAddAccessAllowedAce(
                vNewAcl,
                vDaclRevisionInfo.AclRevision,
                DIRECTORY_ALL_ACCESS,
                aTokenSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            //添加 ACE (InheritNone) - 用户SID
            vStatus = RtlAddAccessAllowedAceEx(
                vNewAcl,
                vDaclRevisionInfo.AclRevision,
                OBJECT_INHERIT_ACE | CONTAINER_INHERIT_ACE | INHERIT_ONLY_ACE,
                GENERIC_ALL,
                aTokenSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }
        }

        // 添加ACE (特殊) - 沙盒SID
        vStatus = RtlAddAccessAllowedAce(
            vNewAcl,
            vDaclRevisionInfo.AclRevision,
            DIRECTORY_ALL_ACCESS,
            aAppContainerSid);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        // 添加 ACE (InheritNone) - 沙盒SID
        vStatus = RtlAddAccessAllowedAceEx(
            vNewAcl,
            vDaclRevisionInfo.AclRevision,
            OBJECT_INHERIT_ACE | CONTAINER_INHERIT_ACE | INHERIT_ONLY_ACE,
            GENERIC_ALL,
            aAppContainerSid);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        if (aFlags & BUILD_SID_ADMINS)
        {
            // 添加ACE (InheritNone) - 管理员SID
            vStatus = RtlAddAccessAllowedAceEx(
                vNewAcl,
                vDaclRevisionInfo.AclRevision,
                OBJECT_INHERIT_ACE | CONTAINER_INHERIT_ACE | INHERIT_ONLY_ACE,
                GENERIC_ALL,
                vAdminSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }
        }

        if (aFlags & BUILD_SID_RESTRICTED)
        {
            // 添加ACE (InheritNone) - 受限SID
            vStatus = RtlAddAccessAllowedAceEx(
                vNewAcl,
                vDaclRevisionInfo.AclRevision,
                OBJECT_INHERIT_ACE | CONTAINER_INHERIT_ACE | INHERIT_ONLY_ACE,
                GENERIC_READ | GENERIC_EXECUTE,
                vRestrictedSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }
        }

        if (aFlags & BUILD_SID_EVERYONE)
        {
            // 添加ACE (InheritNone) - Everyone SID
            vStatus = RtlAddAccessAllowedAceEx(
                vNewAcl,
                vDaclRevisionInfo.AclRevision,
                OBJECT_INHERIT_ACE | CONTAINER_INHERIT_ACE | INHERIT_ONLY_ACE,
                GENERIC_READ | GENERIC_EXECUTE,
                vEveryoneSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }
        }

        vStatus = RtlSetDaclSecurityDescriptor(aNewSecurityDescriptor, TRUE, vNewAcl, FALSE);

        break;
    }

    if (!NT_SUCCESS(vStatus) && vNewAcl)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vNewAcl);
    }

    if (vAdminSid)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vAdminSid);
    }

    if (vRestrictedSid)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vRestrictedSid);
    }

    if (vEveryoneSid)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vEveryoneSid);
    }

    return vStatus;
}

void BasepReleasePackageSecurityDescriptor(
    SECURITY_DESCRIPTOR* aSecurityDescriptor)
{
    if (aSecurityDescriptor->Dacl)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, aSecurityDescriptor->Dacl);
        aSecurityDescriptor->Dacl = nullptr;
    }
}

NTSTATUS BasepOpenLowBoxRootDirectory(
    UINT32 aAppContainerSidType,
    UINT32 aSessionId,
    UNICODE_STRING* aParentSidString,
    PWSTR aLowBoxRootDirectory,
    UINT32 aLowBoxRootDirectorySize,
    HANDLE* aLowBoxRootDirectoryHandle)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    for (;;)
    {
        if (aAppContainerSidType == 1)
        {
            if (!aParentSidString || !aParentSidString->Buffer)
            {
                vStatus = STATUS_INVALID_PARAMETER;
                break;
            }

            vStatus = RtlStringCchPrintfW(
                aLowBoxRootDirectory, aLowBoxRootDirectorySize,
                L"%ws\\%ld\\AppContainerNamedObjects\\%ws", 
                L"\\Sessions", aSessionId, aParentSidString->Buffer);
        }
        else if (aAppContainerSidType == 2)
        {
            vStatus = RtlStringCchPrintfW(
                aLowBoxRootDirectory, aLowBoxRootDirectorySize,
                L"%ws\\%ld\\AppContainerNamedObjects",
                L"\\Sessions", aSessionId);
        }
        else
        {
            vStatus = STATUS_INVALID_PARAMETER;
            break;
        }

        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        UNICODE_STRING vLowBoxRootDirectory{};
        RtlInitUnicodeString(&vLowBoxRootDirectory, aLowBoxRootDirectory);

        OBJECT_ATTRIBUTES vObjectAttributes{};
        InitializeObjectAttributes(&vObjectAttributes, &vLowBoxRootDirectory, 0, nullptr, nullptr);

        vStatus = NtOpenDirectoryObject(
            aLowBoxRootDirectoryHandle,
            DIRECTORY_QUERY | DIRECTORY_TRAVERSE | DIRECTORY_CREATE_OBJECT | DIRECTORY_CREATE_SUBDIRECTORY,
            &vObjectAttributes);

        break;
    }

    return vStatus;
}

NTSTATUS BasepSetKernelIntegrityLabel(
    HANDLE aDirectoryObject)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    HANDLE vNewObject{ nullptr };
    PSID vMandatorySid{ nullptr };

    for (;;)
    {
        vStatus = NtDuplicateObject(
            GetCurrentProcess(), 
            aDirectoryObject,
            GetCurrentProcess(), 
            &vNewObject,
            DIRECTORY_ALL_ACCESS,
            0, 
            0);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        static SID_IDENTIFIER_AUTHORITY vSIAAuthLabel = SECURITY_MANDATORY_LABEL_AUTHORITY;

        vStatus = RtlAllocateAndInitializeSid(
            &vSIAAuthLabel,
            1,
            SECURITY_MANDATORY_LOW_RID,
            0, 0, 0, 0, 0, 0, 0,
            &vMandatorySid);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        SECURITY_DESCRIPTOR vSecurityDescriptor{};
        vStatus = RtlCreateSecurityDescriptor(&vSecurityDescriptor, SECURITY_DESCRIPTOR_REVISION);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        UINT8 vAclBuffer[sizeof(ACL) + 80]{};
        PACL vAcl = (PACL)vAclBuffer;

        vStatus = RtlCreateAcl(vAcl, sizeof(vAclBuffer), ACL_REVISION);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = RtlAddMandatoryAce(
            vAcl, 
            ACL_REVISION, 
            0, 
            vMandatorySid,
            SYSTEM_MANDATORY_LABEL_ACE_TYPE,
            OBJECT_TYPE_CREATE);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = RtlSetSaclSecurityDescriptor(&vSecurityDescriptor, TRUE, vAcl, FALSE);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = NtSetSecurityObject(
            vNewObject, 
            LABEL_SECURITY_INFORMATION, 
            &vSecurityDescriptor);

        break;
    }

    if (vNewObject)
    {
        NtClose(vNewObject);
    }
    if (vMandatorySid)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vMandatorySid);
    }

    return vStatus;
}

NTSTATUS BasepOpenShadowRpcControlDirectory(
    UINT32 aAppContainersSidType,
    HANDLE aLowBoxRootDirectoryHandle,
    HANDLE* aShadowRpcDirectoryHandle)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    for (;;)
    {
        if (INT32(aAppContainersSidType) -1 > 1)
        {
            vStatus = STATUS_INVALID_PARAMETER;
            break;
        }

        wchar_t vRpcDirectoryBuffer[MAXIMUM_FILENAME_LENGTH]{};
        UNICODE_STRING vRpcDirectory{};

        OBJECT_ATTRIBUTES vObjectAttributes{};

        if (aAppContainersSidType == 1)
        {
            swprintf_s(vRpcDirectoryBuffer, ARRAYSIZE(vRpcDirectoryBuffer), L"RPC Control");
            RtlInitUnicodeString(&vRpcDirectory, vRpcDirectoryBuffer);

            InitializeObjectAttributes(&vObjectAttributes, &vRpcDirectory, 0, nullptr, nullptr);
        }
        else if (aAppContainersSidType == 2)
        {
            swprintf_s(vRpcDirectoryBuffer, ARRAYSIZE(vRpcDirectoryBuffer), L"\\RPC Control");
            RtlInitUnicodeString(&vRpcDirectory, vRpcDirectoryBuffer);

            InitializeObjectAttributes(&vObjectAttributes, &vRpcDirectory, 0, aLowBoxRootDirectoryHandle, nullptr);
        }

        vStatus = NtOpenDirectoryObject(
            aShadowRpcDirectoryHandle,
            DIRECTORY_QUERY | DIRECTORY_TRAVERSE,
            &vObjectAttributes);

        break;
    }

    return vStatus;
}

NTSTATUS BasepCreateLowBoxSymbolicLinks(
    HANDLE aRootDirectoryHandle, 
    UNICODE_STRING* aLowBoxSymbolicString,
    SECURITY_DESCRIPTOR* aSecurityDescriptor,
    HANDLE* aLocalSymbolic,
    HANDLE* aGlobalSymbolic,
    HANDLE* aSessionSymbolic)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    static UNICODE_STRING sGlobalName  = RTL_CONSTANT_STRING(L"Global");
    static UNICODE_STRING sLocalName   = RTL_CONSTANT_STRING(L"Local");
    static UNICODE_STRING sSessionName = RTL_CONSTANT_STRING(L"Session");

    HANDLE vGlobalSymbolic{ nullptr };
    HANDLE vLocalSymbolic{ nullptr };
    HANDLE vSessionSymbolic{ nullptr };

    *aLocalSymbolic = nullptr;
    *aGlobalSymbolic = nullptr;
    *aSessionSymbolic = nullptr;

    for (;;)
    {
        UNICODE_STRING vBaseNamedNamespace = RTL_CONSTANT_STRING(L"\\BaseNamedObjects");
        OBJECT_ATTRIBUTES vObjectAttributes{};

        InitializeObjectAttributes(
            &vObjectAttributes,
            &sGlobalName,
            OBJ_INHERIT | OBJ_OPENIF,
            aRootDirectoryHandle,
            aSecurityDescriptor);

        vStatus = NtCreateSymbolicLinkObject(
            &vGlobalSymbolic,
            SYMBOLIC_LINK_ALL_ACCESS,
            &vObjectAttributes,
            &vBaseNamedNamespace);

        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        InitializeObjectAttributes(
            &vObjectAttributes,
            &sLocalName,
            OBJ_INHERIT | OBJ_OPENIF,
            aRootDirectoryHandle,
            aSecurityDescriptor);

        vStatus = NtCreateSymbolicLinkObject(
            &vLocalSymbolic,
            SYMBOLIC_LINK_ALL_ACCESS,
            &vObjectAttributes,
            aLowBoxSymbolicString);
        
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        InitializeObjectAttributes(
            &vObjectAttributes,
            &sSessionName,
            OBJ_INHERIT | OBJ_OPENIF,
            aRootDirectoryHandle,
            aSecurityDescriptor);

        vStatus = NtCreateSymbolicLinkObject(
            &vSessionSymbolic,
            SYMBOLIC_LINK_ALL_ACCESS,
            &vObjectAttributes,
            aLowBoxSymbolicString);

        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        *aGlobalSymbolic    = vGlobalSymbolic;
        *aLocalSymbolic     = vLocalSymbolic;
        *aSessionSymbolic   = vSessionSymbolic;

        break;
    }

    if (!NT_SUCCESS(vStatus))
    {
        if (vGlobalSymbolic)
        {
            NtClose(vGlobalSymbolic);
        }

        if (vLocalSymbolic)
        {
            NtClose(vLocalSymbolic);
        }

        if (vSessionSymbolic)
        {
            NtClose(vSessionSymbolic);
        }
    }

    return vStatus;
}

NTSTATUS BasepCreateLowBoxObjectDirectories(
    PSID aAppContainerSid,
    HANDLE aToken,
    LOWBOX_DATA* aLowBoxData)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    wchar_t vSidStr[MAXIMUM_FILENAME_LENGTH]{};
    UNICODE_STRING vSidString{};
    UNICODE_STRING vParentSidString{};

    HANDLE vBaseDirectoryHandle{ nullptr };
    HANDLE vLowBoxRootDirectoryHandle{ nullptr };
    HANDLE vRootDirectoryHandle{ nullptr };

    HANDLE vShadowRpcDirectoryHandle{ nullptr };
    HANDLE vRpcDirectoryHandle{ nullptr };

    HANDLE vNamedPipeHandle{ nullptr };

    HANDLE vLocalSymbolic{ nullptr };
    HANDLE vGlobalSymbolic{ nullptr };
    HANDLE vSessionSymbolic{ nullptr };

    SECURITY_DESCRIPTOR* vSecurityDescriptor{ nullptr };
    TOKEN_USER* vTokenUser{ nullptr };

    SECURITY_DESCRIPTOR vRootDirectorySD{};
    SECURITY_DESCRIPTOR vRpcControlSD{};

    for (;;)
    {
        UINT32 vQuerySize{ 0 };

        UINT32 vSessionId{ 0 };
        vStatus = NtQueryInformationToken(aToken, TokenSessionId, &vSessionId, sizeof(vSessionId), &vQuerySize);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        UINT32 vAppContainerSidType{ 0 };
        vStatus = RtlGetAppContainerSidType(aAppContainerSid, &vAppContainerSidType);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        if (vAppContainerSidType == 2)
        {
            vStatus = RtlConvertSidToUnicodeString(&vSidString, aAppContainerSid, TRUE);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }
        }
        else
        {
            assert(vAppContainerSidType == 1);

            PSID vParentSid{ nullptr };
            vStatus = RtlGetAppContainerParent(aAppContainerSid, &vParentSid);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            vStatus = RtlConvertSidToUnicodeString(&vParentSidString, vParentSid, TRUE);
            RtlFreeHeap(RtlProcessHeap(), 0, vParentSid);

            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            vStatus = RtlStringCchPrintfW(vSidStr, ARRAYSIZE(vSidStr), L"%u-%u-%u-%u",
                RtlSubAuthoritySid(aAppContainerSid, 8),
                RtlSubAuthoritySid(aAppContainerSid, 9),
                RtlSubAuthoritySid(aAppContainerSid, 10),
                RtlSubAuthoritySid(aAppContainerSid, 11));
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            RtlInitUnicodeString(&vSidString, vSidStr);
        }

        vStatus = BasepOpenBaseObjectDirectory(vAppContainerSidType, vSessionId, 
            &vParentSidString, &vBaseDirectoryHandle);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = NtQuerySecurityObject(vBaseDirectoryHandle,
            DACL_SECURITY_INFORMATION, nullptr, 0, &vQuerySize);
        if ( NT_WARNING(vStatus) && vStatus != STATUS_BUFFER_TOO_SMALL)
        {
            break;
        }

        vSecurityDescriptor = (SECURITY_DESCRIPTOR*)RtlAllocateHeap(RtlProcessHeap(), 0, vQuerySize);
        if (nullptr == vSecurityDescriptor)
        {
            vStatus = STATUS_NO_MEMORY;
            break;
        }

        vStatus = NtQuerySecurityObject(vBaseDirectoryHandle,
            DACL_SECURITY_INFORMATION, vSecurityDescriptor, vQuerySize, &vQuerySize);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = NtQueryInformationToken(aToken, TokenUser, nullptr, 0, &vQuerySize);
        if (vStatus != STATUS_BUFFER_TOO_SMALL)
        {
            break;
        }

        vTokenUser = (TOKEN_USER*)RtlAllocateHeap(RtlProcessHeap(), 0, vQuerySize);
        if (nullptr == vTokenUser)
        {
            vStatus = STATUS_NO_MEMORY;
            break;
        }

        vStatus = NtQueryInformationToken(aToken, TokenUser, vTokenUser, vQuerySize, &vQuerySize);
        if (!NT_WARNING(vStatus))
        {
            break;
        }

        vStatus = BasepBuildPackageSecurityDescriptor(
            vSecurityDescriptor, 
            aAppContainerSid,
            vTokenUser->User.Sid,
            0,
            &vRootDirectorySD);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        wchar_t vLowBoxRootDirectory[MAXIMUM_FILENAME_LENGTH]{};
        vStatus = BasepOpenLowBoxRootDirectory(
            vAppContainerSidType, 
            vSessionId, 
            &vParentSidString,
            vLowBoxRootDirectory, 
            ARRAYSIZE(vLowBoxRootDirectory), 
            &vLowBoxRootDirectoryHandle);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        OBJECT_ATTRIBUTES vObjectAttributes{};
        InitializeObjectAttributes(
            &vObjectAttributes, 
            &vSidString, 
            OBJ_INHERIT | OBJ_OPENIF,
            vLowBoxRootDirectoryHandle,
            &vRootDirectorySD);

        vStatus = NtCreateDirectoryObjectEx(
            &vRootDirectoryHandle,
            DIRECTORY_QUERY | DIRECTORY_TRAVERSE | DIRECTORY_CREATE_OBJECT | DIRECTORY_CREATE_SUBDIRECTORY,
            &vObjectAttributes,
            vBaseDirectoryHandle,
            1);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = BasepSetKernelIntegrityLabel(vRootDirectoryHandle);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = BasepOpenShadowRpcControlDirectory(
            vAppContainerSidType, 
            vLowBoxRootDirectoryHandle, 
            &vShadowRpcDirectoryHandle);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = BasepBuildPackageSecurityDescriptor(
            vSecurityDescriptor,
            aAppContainerSid,
            vTokenUser->User.Sid,
            BUILD_SID_ADMINS | BUILD_SID_RESTRICTED | BUILD_SID_EVERYONE,
            &vRpcControlSD);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        UNICODE_STRING vRpcString{};
        RtlInitUnicodeString(&vRpcString, L"RPC Control");

        InitializeObjectAttributes(
            &vObjectAttributes, 
            &vRpcString,
            OBJ_INHERIT | OBJ_OPENIF,
            vRootDirectoryHandle,
            &vRpcControlSD);

        vStatus = NtCreateDirectoryObjectEx(
            &vRpcDirectoryHandle,
            DIRECTORY_QUERY | DIRECTORY_TRAVERSE | DIRECTORY_CREATE_OBJECT | DIRECTORY_CREATE_SUBDIRECTORY, 
            &vObjectAttributes,
            vShadowRpcDirectoryHandle,
            1);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        vStatus = BasepSetKernelIntegrityLabel(vRpcDirectoryHandle);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        wchar_t vLowBoxSymbolicLinksStrBuffer[MAXIMUM_FILENAME_LENGTH]{};
        swprintf_s(vLowBoxSymbolicLinksStrBuffer, ARRAYSIZE(vLowBoxSymbolicLinksStrBuffer),
            L"%ws\\%ws", vLowBoxRootDirectory, vSidString.Buffer);

        UNICODE_STRING vLowBoxSymbolicStr{};
        RtlInitUnicodeString(&vLowBoxSymbolicStr, vLowBoxSymbolicLinksStrBuffer);

        vStatus = BasepCreateLowBoxSymbolicLinks(
            vRootDirectoryHandle, 
            &vLowBoxSymbolicStr,
            &vRootDirectorySD,
            &vLocalSymbolic,
            &vGlobalSymbolic,
            &vSessionSymbolic);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        wchar_t vNamedPipeStrBuffer[MAXIMUM_FILENAME_LENGTH]{};
        swprintf_s(vNamedPipeStrBuffer, ARRAYSIZE(vNamedPipeStrBuffer),
            L"\\Device\\NamedPipe%ws", vLowBoxSymbolicLinksStrBuffer);

        UNICODE_STRING vNamedPipeStr{};
        RtlInitUnicodeString(&vNamedPipeStr, vNamedPipeStrBuffer);

        InitializeObjectAttributes(
            &vObjectAttributes,
            &vNamedPipeStr,
            OBJ_INHERIT | OBJ_CASE_INSENSITIVE,
            nullptr,
            &vRootDirectorySD);

        assert(!(vRootDirectorySD.Control & SE_SELF_RELATIVE));
        assert(vRootDirectorySD.Dacl);

        PACL vRootDirectoryDacl = vRootDirectorySD.Dacl;
        ACCESS_ALLOWED_ACE* vAce{ nullptr };
        for (UINT32 i = 0; NT_SUCCESS(RtlGetAce(vRootDirectoryDacl, i, (void**)&vAce)); ++i)
        {
            UINT16 vMask = UINT16(vAce->Mask);
            vAce->Mask &= (~0xFFFF);

            if (vMask & FILE_CREATE_PIPE_INSTANCE)
            {
                vAce->Mask |= SYNCHRONIZE | FILE_WRITE_DATA;
            }

            if (vMask & FILE_READ_EA)
            {
                vAce->Mask |= SYNCHRONIZE | FILE_CREATE_PIPE_INSTANCE;
            }
        }

        IO_STATUS_BLOCK vIOStatusBlock{};
        vStatus = NtCreateFile(
            &vNamedPipeHandle,
            PIPE_ALL_ACCESS,
            &vObjectAttributes,
            &vIOStatusBlock,
            nullptr,
            FILE_ATTRIBUTE_NORMAL,
            FILE_SHARE_READ | FILE_SHARE_WRITE,
            FILE_OPEN_IF,
            FILE_DIRECTORY_FILE, 
            nullptr,
            0);

        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        aLowBoxData->RootDirectory          = vRootDirectoryHandle;
        aLowBoxData->RpcControlDirectory    = vRpcDirectoryHandle;
        aLowBoxData->LocalSymbolicLink      = vLocalSymbolic;
        aLowBoxData->GlobalSymbolicLink     = vGlobalSymbolic;
        aLowBoxData->SessionSymbolicLink    = vSessionSymbolic;
        aLowBoxData->NamedPipe              = vNamedPipeHandle;

        vStatus = STATUS_SUCCESS;
        break;
    }

    if (!NT_SUCCESS(vStatus))
    {
        if (vRootDirectoryHandle)
        {
            NtClose(vRootDirectoryHandle);
        }
        if (vRpcDirectoryHandle)
        {
            NtClose(vRpcDirectoryHandle);
        }
    }

    BasepReleasePackageSecurityDescriptor(&vRootDirectorySD);
    BasepReleasePackageSecurityDescriptor(&vRpcControlSD);

    if (vSidString.Buffer != vSidStr)
    {
        RtlFreeUnicodeString(&vSidString);
    }
    RtlFreeUnicodeString(&vParentSidString);

    if (vTokenUser)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vTokenUser);
    }
    if (vSecurityDescriptor)
    {
        RtlFreeHeap(RtlProcessHeap(), 0, vSecurityDescriptor);
    }
    if (vBaseDirectoryHandle)
    {
        NtClose(vBaseDirectoryHandle);
    }
    if (vLowBoxRootDirectoryHandle)
    {
        NtClose(vLowBoxRootDirectoryHandle);
    }
    if (vShadowRpcDirectoryHandle)
    {
        NtClose(vShadowRpcDirectoryHandle);
    }

    return vStatus;
}

NTSTATUS BasepCreateLowBox(
    HANDLE aToken,
    SECURITY_CAPABILITIES* aSecurityCapabilities,
    HANDLE* aLowBoxToken)
{
    NTSTATUS vStatus{ STATUS_SUCCESS };

    HANDLE vToken{ aToken };
    LOWBOX_DATA vLowBoxData{};

    for (;;)
    {
        if (!aSecurityCapabilities->AppContainerSid)
        {
            vStatus = STATUS_INVALID_PARAMETER;
            break;
        }

        if (!vToken)
        {
            if (NtCurrentTeb()->IsImpersonating)
            {
                vStatus = NtOpenThreadToken(GetCurrentThread(), TOKEN_ALL_ACCESS, FALSE, &vToken);
            }
            else
            {
                vStatus = NtOpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &vToken);
            }

            if (!NT_SUCCESS(vStatus))
            {
                break;
            }
        }

        if (aSecurityCapabilities->CapabilityCount > 0
            && !aSecurityCapabilities->Capabilities)
        {
            vStatus = STATUS_INVALID_PARAMETER;
            break;
        }

        UINT32 vQuerySize{ 0 };

        BOOL vIsAppContainer{ FALSE };
        vStatus = NtQueryInformationToken(vToken, TokenIsAppContainer,
            &vIsAppContainer, sizeof(vIsAppContainer), &vQuerySize);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        if (vIsAppContainer)
        {
            vQuerySize = TOKEN_APPCONTAINER_SID_MAX_SIZE;
            UINT8 vAppContainerSidBuffer[TOKEN_APPCONTAINER_SID_MAX_SIZE]{};

            vStatus = NtQueryInformationToken(vToken, TokenAppContainerSid, vAppContainerSidBuffer, vQuerySize, &vQuerySize);
            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            bool vIsFamily{ false };

            if (RtlIsParentOfChildAppContainer(
                ((TOKEN_APPCONTAINER_INFORMATION*)(vAppContainerSidBuffer))->TokenAppContainer,
                aSecurityCapabilities->AppContainerSid))
            {
                vIsFamily = true;
            }
            else
            {
                vStatus = BasepCreateTokenFromLowboxToken(vToken, aSecurityCapabilities, aLowBoxToken);
                if (NT_WARNING(vStatus))
                {
                    break;
                }

                break; // return
            }
        }

        vStatus = BasepCreateLowBoxObjectDirectories(
            aSecurityCapabilities->AppContainerSid, 
            vToken,
            &vLowBoxData);
        if (!NT_SUCCESS(vStatus))
        {
            break;
        }

        OBJECT_ATTRIBUTES vObjectAttributes{};
        InitializeObjectAttributes(
            &vObjectAttributes,
            nullptr,
            0, 
            nullptr,
            nullptr);

        vStatus = NtCreateLowBoxToken(
            aLowBoxToken,
            vToken,
            TOKEN_ALL_ACCESS,
            &vObjectAttributes,
            aSecurityCapabilities->AppContainerSid,
            aSecurityCapabilities->CapabilityCount,
            aSecurityCapabilities->Capabilities,
            sizeof(LOWBOX_DATA) / sizeof(HANDLE),
            &vLowBoxData);

        break;
    }

    HANDLE* vHandles = (HANDLE*)&vLowBoxData;
    for (UINT32 i = 0; i < (sizeof(LOWBOX_DATA) / sizeof(HANDLE)); ++i)
    {
        if (vHandles[i])
        {
            NtClose(vHandles[i]);
        }
    }

    if (!aToken && vToken)
    {
        NtClose(vToken);
    }

    return vStatus;
}

BOOL CreateProcessInternal(
    HANDLE aToken,
    PCWSTR aApplicationName,
    PWSTR aCommandLine,
    LPSECURITY_ATTRIBUTES aProcessAttributes,
    LPSECURITY_ATTRIBUTES aThreadAttributes,
    BOOL aInheritHandles,
    UINT32 aCreationFlags,
    void* aEnvironment,
    PCWSTR aCurrentDirectory,
    LPSTARTUPINFOW aStartupInfo,
    LPPROCESS_INFORMATION aProcessInformation,
    HANDLE* aNewToken)
{
    BOOL vResult{ FALSE };
    DOSERROR vDosError{ ERROR_SUCCESS };
    NTSTATUS vStatus{ STATUS_SUCCESS };

    InitializeBaseData();

    vDosError = InitializeDependentFunction();
    if (ERROR_SUCCESS != vDosError)
    {
        RtlSetLastWin32Error(vDosError);
        return vResult;
    }

    wchar_t *vCurrentDirectory{ nullptr };
    void *vEnvironment{ aEnvironment };

    UINT8 vPriorityClass{ PROCESS_PRIORITY_CLASS_INVALID };
    UINT32 vProcessCreateFlags{};
    UINT32 vThreadCreateFlags{ THREAD_CREATE_FLAGS_CREATE_SUSPENDED };

    UINT32 vExtendedFlags{ 0 };
    UNICODE_STRING vPackageFullName{};
    SECURITY_CAPABILITIES* vSecurityCapabilities{}; // AppContainer 
    BOOLEAN vHasHandleList{ FALSE };
    UINT64 vMitigationPolicyFlags{ 0 };

    BOOLEAN vTestedAppX{ false };
    void* vAppXEnvironment{ nullptr };
    void* vAppXContext{ nullptr }; // TODO: 暂时未知结构

    HANDLE vDebugObject{ nullptr };
    BOOL vErrorMode{ TRUE };

    STARTUPINFOEXW vStartupInfo{};
    HANDLE vParentProcessHandle{};
    HANDLE vConsoleHandle{};
    HANDLE vProcessHandle{};
    HANDLE vThreadHandle{};
    HANDLE vExeFileHandle{};
    HANDLE vExeSectionHandle{};
    HANDLE vLowBoxToken{};

    CLIENT_ID vClientId{};
    SECTION_IMAGE_INFORMATION vImageInfo{};

    UINT32 vPsAttributesCount{ 0 };
    PS_ATTRIBUTE_LIST *vPsAttributeList{ nullptr };

    OBJECT_ATTRIBUTES *vProcessObjectAttribute{ nullptr };
    OBJECT_ATTRIBUTES *vThreadObjectAttribute{ nullptr };

    for (;;)
    {
        //
        // 检查参数有效性
        //

        if ((!aApplicationName && !aCommandLine)
            || (!aProcessInformation || !aStartupInfo))
        {
            vDosError = RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
            break;
        }

        if ((aCreationFlags & (DETACHED_PROCESS | CREATE_NEW_CONSOLE))
            == (DETACHED_PROCESS | CREATE_NEW_CONSOLE))
        {
            vDosError = RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
            break;
        }

        if ((aCreationFlags & CREATE_SEPARATE_WOW_VDM)
            && (aCreationFlags & CREATE_SHARED_WOW_VDM))
        {
            // 不能同时请求分离和共享的 VDM
            vDosError = RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
            break;
        }
        else if (!(aCreationFlags & CREATE_SHARED_WOW_VDM)
            && IsDefaultSeparateVDM())
        {
            aCreationFlags |= CREATE_SEPARATE_WOW_VDM;
        }

        //
        // 转换优先级类型
        //

        if (aCreationFlags & IDLE_PRIORITY_CLASS)
        {
            vPriorityClass = PROCESS_PRIORITY_CLASS_IDLE;
        }
        else if (aCreationFlags & BELOW_NORMAL_PRIORITY_CLASS)
        {
            vPriorityClass = PROCESS_PRIORITY_CLASS_BELOW_NORMAL;
        }
        else if (aCreationFlags & NORMAL_PRIORITY_CLASS)
        {
            vPriorityClass = PROCESS_PRIORITY_CLASS_NORMAL;
        }
        else if (aCreationFlags & ABOVE_NORMAL_PRIORITY_CLASS)
        {
            vPriorityClass = PROCESS_PRIORITY_CLASS_ABOVE_NORMAL;
        }
        else if (aCreationFlags & HIGH_PRIORITY_CLASS)
        {
            vPriorityClass = PROCESS_PRIORITY_CLASS_HIGH;
        }
        else if (aCreationFlags & REALTIME_PRIORITY_CLASS)
        {
            vPriorityClass = (PROCESS_PRIORITY_CLASS_HIGH
                + (UINT8)(BasepIsRealtimeAllowed(FALSE, aToken != nullptr) != nullptr));
        }
        else
        {
            vPriorityClass = PROCESS_PRIORITY_CLASS_INVALID;
        }

        aCreationFlags &=
            ~(NORMAL_PRIORITY_CLASS
                | IDLE_PRIORITY_CLASS
                | HIGH_PRIORITY_CLASS
                | REALTIME_PRIORITY_CLASS
                | BELOW_NORMAL_PRIORITY_CLASS
                | ABOVE_NORMAL_PRIORITY_CLASS);

        //
        // 转换 CreateFlags
        //

        if (aCreationFlags & CREATE_PROTECTED_PROCESS)
        {
            vProcessCreateFlags = PROCESS_CREATE_FLAGS_PROTECTED_PROCESS;
        }
        if (aCreationFlags & CREATE_BREAKAWAY_FROM_JOB)
        {
            vProcessCreateFlags |= PROCESS_CREATE_FLAGS_BREAKAWAY;
        }
        if (aCreationFlags & INHERIT_PARENT_AFFINITY)
        {
            vProcessCreateFlags |= PROCESS_CREATE_FLAGS_INHERIT_FROM_PARENT;
        }
        if (!(aCreationFlags & CREATE_SUSPENDED))
        {
            vProcessCreateFlags |= PROCESS_CREATE_FLAGS_SUSPENDED;
        }
        if (aInheritHandles)
        {
            vProcessCreateFlags |= PROCESS_CREATE_FLAGS_INHERIT_HANDLES;
        }
        else
        {
            vProcessCreateFlags &= (~PROCESS_CREATE_FLAGS_INHERIT_HANDLES);
        }

        //
        // 检查调试标志
        //

        if (aCreationFlags & (DEBUG_ONLY_THIS_PROCESS | DEBUG_PROCESS))
        {
            vStatus = DbgUiConnectToDbg();
            if (!NT_SUCCESS(vStatus))
            {
                vDosError = RtlNtStatusToDosError(vStatus);
                break;
            }

            vDebugObject = DbgUiGetThreadDebugObject();

            if (aCreationFlags & DEBUG_ONLY_THIS_PROCESS)
            {
                vProcessCreateFlags |= PROCESS_CREATE_FLAGS_NO_DEBUG_INHERIT;
            }
        }

        //
        // 配置部分属性列表
        //

        BYTE vPsAttributeListBuffer[sizeof(PS_ATTRIBUTE_LIST) + 14 * sizeof(PS_ATTRIBUTE)]{};
        vPsAttributeList = (PS_ATTRIBUTE_LIST*)vPsAttributeListBuffer;
        vPsAttributesCount = 3;

        vPsAttributeList->Attributes[0].Attribute = PS_ATTRIBUTE_IMAGE_NAME;
        vPsAttributeList->Attributes[0].ReturnLength = nullptr;

        vPsAttributeList->Attributes[1].Attribute = PS_ATTRIBUTE_CLIENT_ID;
        vPsAttributeList->Attributes[1].Size = sizeof(vClientId);
        vPsAttributeList->Attributes[1].ValuePtr = &vClientId;
        vPsAttributeList->Attributes[1].ReturnLength = nullptr;

        vPsAttributeList->Attributes[2].Attribute = PS_ATTRIBUTE_IMAGE_INFO;
        vPsAttributeList->Attributes[2].Size = sizeof(vImageInfo);
        vPsAttributeList->Attributes[2].ValuePtr = &vImageInfo;
        vPsAttributeList->Attributes[2].ReturnLength = nullptr;

        if (vDebugObject)
        {
            vPsAttributeList->Attributes[vPsAttributesCount].Attribute = PS_ATTRIBUTE_DEBUG_PORT;
            vPsAttributeList->Attributes[vPsAttributesCount].Size = sizeof(vDebugObject);
            vPsAttributeList->Attributes[vPsAttributesCount].ValuePtr = vDebugObject;
            ++vPsAttributesCount;
        }

        if (PROCESS_PRIORITY_CLASS_INVALID != vPriorityClass)
        {
            vPsAttributeList->Attributes[vPsAttributesCount].Attribute = PS_ATTRIBUTE_PRIORITY_CLASS;
            vPsAttributeList->Attributes[vPsAttributesCount].Size = sizeof(vPriorityClass);
            vPsAttributeList->Attributes[vPsAttributesCount].ValuePtr = &vPriorityClass;
            ++vPsAttributesCount;
        }

        if (aCreationFlags & CREATE_DEFAULT_ERROR_MODE)
        {
            vPsAttributeList->Attributes[vPsAttributesCount].Attribute = PS_ATTRIBUTE_ERROR_MODE;
            vPsAttributeList->Attributes[vPsAttributesCount].Size = sizeof(vErrorMode);
            vPsAttributeList->Attributes[vPsAttributesCount].ValuePtr = &vErrorMode;
            ++vPsAttributesCount;
        }

        RtlSecureZeroMemory(aProcessInformation, sizeof(*aProcessInformation));

        //
        // 转换环境变量编码
        //

        if (aEnvironment && !(aCreationFlags & CREATE_UNICODE_ENVIRONMENT))
        {
            void* vUnicodeEnvironment{ nullptr };
            vStatus = RtlCreateEnvironmentEx(aEnvironment, &vUnicodeEnvironment,
                RTL_CREATE_ENVIRONMENT_TRANSLATE);
            if (!NT_SUCCESS(vStatus))
            {
                vDosError = RtlNtStatusToDosError(vStatus);
                break;
            }

            aEnvironment = vUnicodeEnvironment;
            aCreationFlags |= CREATE_UNICODE_ENVIRONMENT;
        }

        //
        // 保存/处理 Startup 信息, 处理附加属性列表
        //

        vStartupInfo.StartupInfo = *aStartupInfo;

        if (aCreationFlags & EXTENDED_STARTUPINFO_PRESENT)
        {
            if (vStartupInfo.StartupInfo.cb != sizeof(STARTUPINFOEXW))
            {
                vDosError = RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
                break;
            }

            vStartupInfo.lpAttributeList =
                ((STARTUPINFOEXW*)aStartupInfo)->lpAttributeList;

            if (vStartupInfo.lpAttributeList)
            {
                vStatus = BasepConvertWin32AttributeList(
                    vStartupInfo.lpAttributeList,
                    FALSE,
                    &vExtendedFlags,
                    &vPackageFullName,
                    &vSecurityCapabilities,
                    &vHasHandleList,
                    &vParentProcessHandle,
                    &vConsoleHandle,
                    &vMitigationPolicyFlags,
                    vPsAttributeList,
                    &vPsAttributesCount,
                    ProcThreadAttributeMaxWin8 + 3); // 3 is vPsAttributeList->Attributes[0~2]

                if (!NT_SUCCESS(vStatus))
                {
                    vDosError = RtlNtStatusToDosError(vStatus);
                    break;
                }

                assert(vPsAttributesCount <= (ProcThreadAttributeMaxWin8 + 3));

                if ((vStartupInfo.lpAttributeList->PresentFlags & (1 << ProcThreadAttributeConsoleReference))
                    && (vParentProcessHandle || vSecurityCapabilities))
                {
                    vDosError = RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
                    break;
                }

                if (vExtendedFlags & 4)
                {
                    vProcessCreateFlags |= PROCESS_CREATE_FLAGS_EXTENDED_UNKNOWN; // 0x400
                }
            }
        }

        if (!(aCreationFlags & CREATE_SEPARATE_WOW_VDM))
        {
            BOOL vInJob{ FALSE };
            if (IsProcessInJob(vParentProcessHandle ? vParentProcessHandle : GetCurrentProcess(), nullptr, &vInJob)
                && vInJob)
            {
                aCreationFlags =
                    (aCreationFlags & ~(CREATE_SHARED_WOW_VDM))
                    | CREATE_SEPARATE_WOW_VDM;
            }
        }

        if ((vStartupInfo.StartupInfo.dwFlags & STARTF_USESTDHANDLES)
            && vStartupInfo.StartupInfo.dwFlags & (STARTF_USEHOTKEY | STARTF_SHELLPRIVATE))
        {
            // 不能同时设置
            vStartupInfo.StartupInfo.dwFlags &= ~(STARTF_USESTDHANDLES);
        }

        //
        // 获取 & 检查 Current directory
        //

        if (aCurrentDirectory)
        {
            vCurrentDirectory = (wchar_t*)RtlAllocateHeap(RtlProcessHeap(), 0,
                sizeof(wchar_t) * (MAX_PATH - 1));
            if (nullptr == vCurrentDirectory)
            {
                vDosError = RtlNtStatusToDosError(STATUS_NO_MEMORY);
                break;
            }

            // lpFilePart 在逆向的代码中是有传参数, 但是没有用到, 所以我直接给了 nullptr
            UINT32 vFullPathLength = GetFullPathNameW(aCurrentDirectory,
                MAX_PATH - 1, vCurrentDirectory, nullptr);
            if (!vFullPathLength)
            {
                vDosError = RtlGetLastWin32Error();
                break;
            }
            else if (vFullPathLength >= MAX_PATH)
            {
                vDosError = ERROR_DIRECTORY;
                break;
            }
        }

        OBJECT_ATTRIBUTES vLocalProcessObjectAttribute{};
        OBJECT_ATTRIBUTES vLocalThreadObjectAttribute{};

        vStatus = BaseFormatObjectAttributes(
            &vLocalProcessObjectAttribute, aProcessAttributes,
            nullptr, &vProcessObjectAttribute);
        if (!NT_SUCCESS(vStatus))
        {
            vDosError = RtlNtStatusToDosError(vStatus);
            break;
        }

        vStatus = BaseFormatObjectAttributes(
            &vLocalThreadObjectAttribute, aThreadAttributes,
            nullptr, &vThreadObjectAttribute);
        if (!NT_SUCCESS(vStatus))
        {
            vDosError = RtlNtStatusToDosError(vStatus);
            break;
        }

        wchar_t* vNameBuffer{ nullptr };
        wchar_t* vFullPathBuffer{ nullptr };
        wchar_t* vQuotedCmdLine{ nullptr };

        UNICODE_STRING vNtName{};

        for (;;)
        {
            BOOL v157{ TRUE };

            if (!aInheritHandles || vHasHandleList)
            {
                v157 = FALSE;
            }

            if (vNameBuffer)
            {
                RtlFreeHeap(RtlProcessHeap(), 0, vNameBuffer);
                vNameBuffer = nullptr;
            }

            if (vFullPathBuffer)
            {
                RtlFreeHeap(RtlProcessHeap(), 0, vFullPathBuffer);
                vFullPathBuffer = nullptr;
            }

            if (vQuotedCmdLine)
            {
                RtlFreeHeap(RtlProcessHeap(), 0, vQuotedCmdLine);
                vQuotedCmdLine = nullptr;
            }

            RtlFreeUnicodeString(&vNtName);

            if (vExeFileHandle)
            {
                assert(NT_SUCCESS(NtClose(vExeFileHandle)));
                vExeFileHandle = nullptr;
            }

            if (vLowBoxToken)
            {
                assert(NT_SUCCESS(NtClose(vLowBoxToken)));
                vLowBoxToken = nullptr;
            }

            if (vAppXEnvironment)
            {
                assert(NT_SUCCESS(RtlDestroyEnvironment(vAppXEnvironment)));
                vAppXEnvironment = nullptr;
            }

            //
            // AppX 或者称为 PackageProcess ?
            //

            if (!vTestedAppX
                && !vParentProcessHandle
                && (vPackageFullName.Length || NtCurrentPeb()->IsPackagedProcess))
            {
                vTestedAppX = true;

                vStatus = BasepAppXExtension(
                    aToken,
                    &vPackageFullName,
                    vSecurityCapabilities,
                    aEnvironment,
                    &vAppXContext,
                    &vAppXEnvironment);
                if (!NT_SUCCESS(vStatus))
                {
                    vDosError = RtlNtStatusToDosError(vStatus);
                    break;
                }

                if (vAppXEnvironment)
                {
                    vEnvironment = vAppXEnvironment;
                }

                if (vAppXContext)
                {
                    // TODO
                }
                else
                {
                    vPackageFullName.Buffer = nullptr;
                    vPackageFullName.Length = 0;
                    vPackageFullName.MaximumLength = 0;
                }
            }

            //
            // AppContainer , UWP 应用基本都在用的沙盒Token
            //

            if (vSecurityCapabilities)
            {
                // 创建 LowBox 完整性等级的Token
                vStatus = BasepCreateLowBox(aToken, vSecurityCapabilities, &vLowBoxToken);
                if (!NT_SUCCESS(vStatus))
                {
                    vDosError = RtlNtStatusToDosError(vStatus);
                    break;
                }

                void *vAppXEnvironmentExtension{ nullptr };

                vStatus = BasepAppContainerEnvironmentExtension(
                    vSecurityCapabilities->AppContainerSid, aEnvironment, &vAppXEnvironmentExtension);
                if (!NT_SUCCESS(vStatus))
                {
                    vDosError = RtlNtStatusToDosError(vStatus);
                    break;
                }

                if (vLowBoxToken)
                {
                    aToken = vLowBoxToken;
                }

                if (vAppXEnvironmentExtension)
                {
                    if (vAppXEnvironment)
                    {
                        assert(vEnvironment == vAppXEnvironment);
                        assert(NT_SUCCESS(RtlDestroyEnvironment(vAppXEnvironment)));
                    }

                    vAppXEnvironment = vAppXEnvironmentExtension;
                    vEnvironment = vAppXEnvironmentExtension;
                }
            }

            // 检查目录正确性

            if (vCurrentDirectory)
            {
                UINT32 vDirAttributes = GetFileAttributesW(vCurrentDirectory);
                if ((vDirAttributes == INVALID_FILE_ATTRIBUTES)
                    || !(vDirAttributes & FILE_ATTRIBUTE_DIRECTORY))
                {
                    vDosError = ERROR_DIRECTORY;
                    break;
                }
            }

            if (aToken)
            {
                vPsAttributeList->Attributes[vPsAttributesCount].Attribute = PS_ATTRIBUTE_TOKEN;
                vPsAttributeList->Attributes[vPsAttributesCount].Size = sizeof(aToken);
                vPsAttributeList->Attributes[vPsAttributesCount].ValuePtr = aToken;
                ++vPsAttributesCount;
            }

            PS_CREATE_INFO vCreateInfo{ sizeof(vCreateInfo) };

            //
            // 未完待续...
            //

            vResult = TRUE;
            break;
        }

        break;
    }

    RtlSetLastWin32Error(vDosError);
    return vResult;
}
