#pragma once
#include <ntbase.h>
#include <ntobapi.h>
#include <ntseapi.h>

//////////////////////////////////////////////////////////////////////////

//
// Base
//

using fun$BaseFormatObjectAttributes = NTSTATUS(__stdcall *)(
    OBJECT_ATTRIBUTES* aLocalObjectAttributes,
    SECURITY_ATTRIBUTES* aSecurityAttributes,
    UNICODE_STRING* aObjectName,
    OBJECT_ATTRIBUTES** aObjectAttributes);

using fun$BaseIsDosApplication = UINT32(__stdcall *)(
    UNICODE_STRING* PathName,
    NTSTATUS Status);

using fun$BaseGetNamedObjectDirectory = NTSTATUS(__stdcall *)(
    HANDLE* aObjectDirectory);

//
// Base private
//

using fun$BasepAppXExtension = NTSTATUS(__stdcall *)(
    HANDLE aToken,
    UNICODE_STRING* aPackageFullName,
    SECURITY_CAPABILITIES *aSecurityCapabilities,
    void* aEnvironment,
    void** aAppXContext,    // TODO: Unknown Struct
    void** aAppXEnvironment);

using fun$BasepAppContainerEnvironmentExtension = NTSTATUS(__stdcall *)(
    PSID aAppContainerSid,
    void* aEnvironment,
    void** aAppXEnvironmentExtension);

using fun$BasepProcessInvalidImage = BOOL(__stdcall *)(
    NTSTATUS aStatus,
    HANDLE aToken,
    PCWSTR aDosName,
    PCWSTR *aApplicationName,
    PWSTR *aCommandLine,
    PCWSTR aCurrentDirectory,
    UINT32 *aCreationFlags,
    BOOL *aInheritHandles,
    UNICODE_STRING *aNtPath,
    BOOLEAN *aUnknown,
    void** aEnvironment,
    LPSTARTUPINFOW aStartupInfo,
    struct _BASE_API_MESSAGE *aApiMsg,
    UINT32 *aVdmTask,
    UNICODE_STRING *aVdmCommandLine,
    ANSI_STRING *aAnsiVdmEnvironment,
    UNICODE_STRING *aUnicodeVdmEnvironment,
    UINT32 *aVdmUndoStates,
    UINT32 *aVdmBinaryType,
    BOOL *aVdmValid,
    HANDLE *aVdmWaitHandle);

using fun$BasepCheckWinSaferRestrictions = NTSTATUS(__stdcall *)(
    HANDLE aToken,
    PCWSTR aApplicationName,
    HANDLE aFile,
    UNICODE_STRING *aPackageFullName);

//
// Nt XXX
//

using fun$RaiseInvalid16BitExeError = void(__stdcall *)(
    UNICODE_STRING* aExePath);

using fun$NtVdm64CreateProcessInternal = BOOL(__stdcall *)(
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
    HANDLE* aNewToken);


//////////////////////////////////////////////////////////////////////////

extern"C" {

    //
    // Kernel32
    //

    void* __stdcall GetProcAddress(void* hModule, PCSTR lpProcName);
    void* __stdcall GetModuleHandleW(PCWSTR lpModuleName);

    UINT32 __stdcall GetLastError(void);
    void __stdcall SetLastError(UINT32 dwErrCode);

    BOOL __stdcall IsProcessInJob(
        HANDLE ProcessHandle,
        HANDLE JobHandle,
        BOOL* Result);

    UINT32 __stdcall GetFullPathNameW(
        PCWSTR lpFileName,
        UINT32 nBufferLength,
        PWSTR lpBuffer,
        PWSTR * lpFilePart);

    UINT32 __stdcall GetFileAttributesW(PCWSTR lpFileName);
}

//////////////////////////////////////////////////////////////////////////

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
    HANDLE* aNewToken);
