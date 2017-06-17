#include "CreateProcessInternal.h"
#include <hresult.h>
#include <ntpsapi.h>
#include <ntrtl.h>

#include <functional>

//////////////////////////////////////////////////////////////////////////

typedef struct tagPROCESSENTRY32W
{
    UINT32   dwSize;
    UINT32   cntUsage;
    UINT32   th32ProcessID;          // this process
    UINT_PTR th32DefaultHeapID;
    UINT32   th32ModuleID;           // associated exe
    UINT32   cntThreads;
    UINT32   th32ParentProcessID;    // this process's parent process
    INT32    pcPriClassBase;         // Base priority of process's threads
    UINT32   dwFlags;
    wchar_t  szExeFile[MAX_PATH];    // Path
} PROCESSENTRY32W, *PPROCESSENTRY32W;

#define TH32CS_SNAPHEAPLIST 0x00000001
#define TH32CS_SNAPPROCESS  0x00000002
#define TH32CS_SNAPTHREAD   0x00000004
#define TH32CS_SNAPMODULE   0x00000008
#define TH32CS_SNAPMODULE32 0x00000010
#define TH32CS_SNAPALL      (TH32CS_SNAPHEAPLIST | TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD | TH32CS_SNAPMODULE)
#define TH32CS_INHERIT      0x80000000

extern "C" HANDLE OpenProcess(
    UINT32 dwDesiredAccess, BOOL bInheritHandle, UINT32 dwProcessId);

extern"C" HANDLE CreateToolhelp32Snapshot(
    UINT32 dwFlags,
    UINT32 th32ProcessID);

extern"C" BOOL Process32FirstW(HANDLE hSnapshot, PPROCESSENTRY32W lppe);
extern"C" BOOL Process32NextW(HANDLE hSnapshot, PPROCESSENTRY32W lppe);

extern"C" BOOL CloseHandle(HANDLE hObject);

extern"C" BOOL InitializeProcThreadAttributeList(
    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
    UINT32 dwAttributeCount,
    UINT32 dwFlags,
    SIZE_T* lpSize);

extern"C" BOOL UpdateProcThreadAttribute(
    LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
    UINT32 dwFlags,
    UINT_PTR Attribute,
    void* lpValue,
    SIZE_T cbSize,
    void* lpPreviousValue,
    SIZE_T* lpReturnSize);

extern"C" void DeleteProcThreadAttributeList(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList);

extern"C" int lstrcmpiW(
    PCWSTR lpString1,
    PCWSTR lpString2);

//////////////////////////////////////////////////////////////////////////

HRESULT EnumerateProcess(std::function<bool(UINT32 aParentPID, UINT32 aPID, const wchar_t *aProcessName)> aCallback)
{
    HRESULT hr = S_OK;

    HANDLE vSnapHandle = INVALID_HANDLE_VALUE;
    PROCESSENTRY32W vProcessEntry32 = { 0 };

    for (;;)
    {
        vSnapHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (INVALID_HANDLE_VALUE == vSnapHandle)
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            break;
        }

        vProcessEntry32.dwSize = sizeof(vProcessEntry32);
        if (!Process32FirstW(vSnapHandle, &vProcessEntry32))
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            break;
        }

        hr = S_FALSE;
        do
        {
            if (aCallback(
                vProcessEntry32.th32ParentProcessID,
                vProcessEntry32.th32ProcessID,
                vProcessEntry32.szExeFile))
            {
                hr = S_OK;
                break;
            }

        } while (Process32NextW(vSnapHandle, &vProcessEntry32));

        break;
    }

    if (INVALID_HANDLE_VALUE != vSnapHandle)
    {
        CloseHandle(vSnapHandle);
        vSnapHandle = INVALID_HANDLE_VALUE;
    }

    return hr;
}

int main(int /*argc*/, char** /*argv*/, char** /*envp*/)
{
    BOOL vResult{ FALSE };
    HANDLE vParentHandle = nullptr;
    PROC_THREAD_ATTRIBUTE_LIST* vAttributeList = nullptr;

    for (;;)
    {
        HRESULT hr{ S_OK };

        wchar_t vCmd[] = { L"notepad" };
        STARTUPINFOEXW vStartup{ sizeof(vStartup) };
        PROCESS_INFORMATION vProcessInfo{};

        UINT32 vExplorerPid{ 0 };

        EnumerateProcess([&vExplorerPid](UINT32 /*aParentPID*/, UINT32 aPID, const wchar_t *aProcessName) -> bool
        {
            if (0 == lstrcmpiW(aProcessName, L"Explorer.exe"))
            {
                vExplorerPid = aPID;
                return true;
            }

            return false;
        });

        if (!vExplorerPid)
        {
            return vResult;
        }

        vParentHandle = OpenProcess(PROCESS_CREATE_PROCESS, FALSE, (UINT32)(UINT_PTR)vExplorerPid);
        if (nullptr == vParentHandle)
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            break;
        }

        vStartup.StartupInfo.cb = sizeof(vStartup);

        size_t vAttributeSize = 0;
        InitializeProcThreadAttributeList(nullptr, 2, 0, &vAttributeSize);

        vAttributeList = (LPPROC_THREAD_ATTRIBUTE_LIST)new(std::nothrow) char[vAttributeSize];
        if (nullptr == vAttributeList)
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            break;
        }
        RtlSecureZeroMemory(vAttributeList, vAttributeSize);

        if (FALSE == InitializeProcThreadAttributeList(vAttributeList, 2, 0, &vAttributeSize))
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            break;
        }

        if (FALSE == UpdateProcThreadAttribute(
            vAttributeList, 0, PROC_THREAD_ATTRIBUTE_PARENT_PROCESS,
            &vParentHandle, sizeof(vParentHandle), nullptr, nullptr))
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            break;
        }

        UINT32 vProtectionLevel = 3;// PROTECTION_LEVEL_SAME;
        if (FALSE == UpdateProcThreadAttribute(
            vAttributeList, 0, PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL,
            &vProtectionLevel, sizeof(vProtectionLevel), nullptr, nullptr))
        {
            hr = HRESULT_FROM_WIN32(GetLastError());
            break;
        }

        vStartup.lpAttributeList = vAttributeList;

        vResult = CreateProcessInternal(
            nullptr,
            nullptr,
            vCmd,
            nullptr,
            nullptr,
            FALSE,
            EXTENDED_STARTUPINFO_PRESENT,
            nullptr,
            nullptr,
            (STARTUPINFOW*)&vStartup,
            &vProcessInfo,
            nullptr);

        break;
    }


    if (vAttributeList)
    {
        DeleteProcThreadAttributeList(vAttributeList);
        delete[](char*)vAttributeList;
        vAttributeList = nullptr;
    }

    if (vParentHandle)
    {
        CloseHandle(vParentHandle);
        vParentHandle = nullptr;
    }

    return vResult;
}