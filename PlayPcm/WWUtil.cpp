#include "WWUtil.h"
#include <Windows.h>
#include <stdio.h>

void WWErrorDescription(HRESULT hr)
{
    if(FACILITY_WINDOWS == HRESULT_FACILITY(hr)) {
        hr = HRESULT_CODE(hr);
    }

    char* szErrMsg = NULL;

    if(!FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPSTR)&szErrMsg, 0, NULL) != 0) {
        //_tprintf(TEXT("unknown HRESULT %#x\n"), hr);
        return;
    }

    printf("    0x%08x is: %s", hr, szErrMsg);
    LocalFree(szErrMsg);
}

