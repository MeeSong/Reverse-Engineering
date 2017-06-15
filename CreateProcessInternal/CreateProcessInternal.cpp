#include "CreateProcessInternal.h"

#include <doserror.h>
#include <ntstatus.h>
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
fun$BasepProcessInvalidImage        BasepProcessInvalidImage{ nullptr };
fun$BasepCheckWinSaferRestrictions  BasepCheckWinSaferRestrictions{ nullptr };
fun$BaseGetNamedObjectDirectory     BaseGetNamedObjectDirectory{ nullptr };

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
        
        BaseGetNamedObjectDirectory = (fun$BaseGetNamedObjectDirectory)GetProcAddress(
            GetModuleHandleW(L"Kernel32.dll"), "BaseGetNamedObjectDirectory");
        if (nullptr == BaseGetNamedObjectDirectory)
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
        SetLastError(ERROR_SUCCESS);
        break;
    }

    vDosError = (DOSERROR)GetLastError();
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
        SetLastError(vDosError);
        return vResult;
    }


    UINT32 vPriorityClass{ PROCESS_PRIORITY_CLASS_INVALID };
    UINT32 vProcessCreateFlags{};
    UINT32 vThreadCreateFlags{ THREAD_CREATE_FLAGS_CREATE_SUSPENDED };

    HANDLE vDebugObject{ nullptr };
    BOOL vErrorMode{ TRUE };

    STARTUPINFOEXW vStartupInfo{};
    HANDLE vParentProcessHandle{};
    HANDLE vProcessHandle{};
    HANDLE vThreadHandle{};
    HANDLE vExeFileHandle{};
    HANDLE vExeSectionHandle{};
    
    CLIENT_ID vClientId{};
    SECTION_IMAGE_INFORMATION vImageInfo{};

    UINT32 vPsAttributeCount{ 0 };
    PS_ATTRIBUTE_LIST *vPsAttributeList{ nullptr };

    for (;;)
    {
        //
        // 检查参数有效性
        //

        if ((!aApplicationName && !aCommandLine)
            || (!aProcessInformation || !aStartupInfo))
        {
            vDosError = (DOSERROR)RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
            break;
        }

        if ((aCreationFlags & (DETACHED_PROCESS | CREATE_NEW_CONSOLE))
            == (DETACHED_PROCESS | CREATE_NEW_CONSOLE))
        {
            vDosError = (DOSERROR)RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
            break;
        }

        if ((aCreationFlags & CREATE_SEPARATE_WOW_VDM)
            && (aCreationFlags & CREATE_SHARED_WOW_VDM))
        {
            // 不能同时请求分离和共享的 VDM
            vDosError = (DOSERROR)RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
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
                vDosError = (DOSERROR)RtlNtStatusToDosError(vStatus);
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
        vPsAttributeCount = 3;

        vPsAttributeList->Attributes[0].Attribute = PS_ATTRIBUTE_IMAGE_NAME;

        vPsAttributeList->Attributes[1].Attribute = PS_ATTRIBUTE_CLIENT_ID;
        vPsAttributeList->Attributes[1].Size = sizeof(vClientId);
        vPsAttributeList->Attributes[1].ValuePtr = &vClientId;

        vPsAttributeList->Attributes[2].Attribute = PS_ATTRIBUTE_IMAGE_INFO;
        vPsAttributeList->Attributes[2].Size = sizeof(vImageInfo);
        vPsAttributeList->Attributes[2].ValuePtr = &vImageInfo;

        if (vDebugObject)
        {
            vPsAttributeList->Attributes[vPsAttributeCount].Attribute = PS_ATTRIBUTE_DEBUG_PORT;
            vPsAttributeList->Attributes[vPsAttributeCount].Size = sizeof(vDebugObject);
            vPsAttributeList->Attributes[vPsAttributeCount].ValuePtr = vDebugObject;
            ++vPsAttributeCount;
        }

        if (PROCESS_PRIORITY_CLASS_INVALID != vPriorityClass)
        {
            vPsAttributeList->Attributes[vPsAttributeCount].Attribute = PS_ATTRIBUTE_PRIORITY_CLASS;
            vPsAttributeList->Attributes[vPsAttributeCount].Size = sizeof(vPriorityClass);
            vPsAttributeList->Attributes[vPsAttributeCount].ValuePtr = &vPriorityClass;
            ++vPsAttributeCount;
        }

        if (aCreationFlags & CREATE_DEFAULT_ERROR_MODE)
        {
            vPsAttributeList->Attributes[vPsAttributeCount].Attribute = PS_ATTRIBUTE_ERROR_MODE;
            vPsAttributeList->Attributes[vPsAttributeCount].Size = sizeof(vErrorMode);
            vPsAttributeList->Attributes[vPsAttributeCount].ValuePtr = &vErrorMode;
            ++vPsAttributeCount;
        }

        if (aToken)
        {
            vPsAttributeList->Attributes[vPsAttributeCount].Attribute = PS_ATTRIBUTE_TOKEN;
            vPsAttributeList->Attributes[vPsAttributeCount].Size = sizeof(aToken);
            vPsAttributeList->Attributes[vPsAttributeCount].ValuePtr = aToken;
            ++vPsAttributeCount;
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
                vDosError = (DOSERROR)RtlNtStatusToDosError(vStatus);
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
                vDosError = (DOSERROR)RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
                break;
            }

            vStartupInfo.lpAttributeList =
                ((STARTUPINFOEXW*)aStartupInfo)->lpAttributeList;

            if (vStartupInfo.lpAttributeList)
            {
                // TODO

                //vStatus = BasepConvertWin32AttributeList();

                if (!NT_SUCCESS(vStatus))
                {
                    vDosError = (DOSERROR)RtlNtStatusToDosError(vStatus);
                    break;
                }

                //if (vPsAttributeCount > 15) __int2c();
                //
                //if ((vStartupInfo.lpAttributeList->PresentFlags & PROCESS_CREATE_FLAGS_UNKNOWN0)
                //    && (vParentProcessHandle))
                //{
                //    vDosError = (DOSERROR)RtlNtStatusToDosError(STATUS_INVALID_PARAMETER);
                //    break;
                //}
            }
        }

        if (!vParentProcessHandle)
        {
            vParentProcessHandle = GetCurrentProcess();
        }
        
        if (!(aCreationFlags & CREATE_SEPARATE_WOW_VDM))
        {
            BOOL vInJob{ FALSE };
            if (IsProcessInJob(vProcessHandle, nullptr, &vInJob)
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
        // 未完待续...
        //

        vResult = TRUE;
        break;
    }

    return vResult;
}