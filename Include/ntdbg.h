#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

//
// DbgUiXXXX
//

extern"C" NTSTATUS __stdcall DbgUiConnectToDbg();
extern"C" HANDLE __stdcall DbgUiGetThreadDebugObject();
