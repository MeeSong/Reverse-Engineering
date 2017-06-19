#include "CreateProcessInternal.h"

#include <doserror.h>
#include <ntstatus.h>
#include <ntobapi.h>
#include <ntpebteb.h>
#include <ntrtl.h>
#include <ntseapi.h>
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

            bool vInsertPsAttribute = true;
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
                vInsertPsAttribute = false;
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

                vInsertPsAttribute = false;
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

                if ((vAttribute->Size - 4) & SIZE_T(~(4)))
                {
                    // Only UINT32 or UINT64
                    vStatus = STATUS_INVALID_PARAMETER;
                    break;
                }

                // TODO
                //vStatus = BasepConvertMitigationPolicyFlags(
                //    vAttribute, aMitigationPolicyFlags, vStatus, vInsertPsAttribute);
                if (!NT_SUCCESS(vStatus))
                {
                    break;
                }

                aPsAttributeList->Attributes[vPsAttributesCount].Attribute = PS_ATTRIBUTE_SECURE_PROCESS;
                aPsAttributeList->Attributes[vPsAttributesCount].Size = sizeof(UINT64);
                aPsAttributeList->Attributes[vPsAttributesCount].ValuePtr = aMitigationPolicyFlags;
                aPsAttributeList->Attributes[vPsAttributesCount].ReturnLength = nullptr;

                ++vPsAttributesCount;
                vInsertPsAttribute = false;
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

                vInsertPsAttribute = false;
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
                vInsertPsAttribute = false;
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
                vInsertPsAttribute = false;
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

                vInsertPsAttribute = false;
                break;
            }

            }

            if (!NT_SUCCESS(vStatus))
            {
                break;
            }

            if (vInsertPsAttribute)
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

NTSTATUS BasepCreateLowBox(
    HANDLE aToken,
    SECURITY_CAPABILITIES* aSecurityCapabilities,
    HANDLE* aLowBoxToken)
{

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
    void* vAppXContext{ nullptr };

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
            // AppContainer , IE 经常用..
            //

            if (vSecurityCapabilities)
            {
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