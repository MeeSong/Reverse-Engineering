#include "CreateProcessInternal.h"

int main(int /*argc*/, char** /*argv*/, char** /*envp*/)
{
    BOOL vResult{FALSE};

    vResult = CreateProcessInternal(
        nullptr,
        L"",
        L"",
        nullptr,
        nullptr,
        FALSE,
        0,
        nullptr,
        L"",
        nullptr,
        nullptr,
        nullptr);
    
    return vResult;
}