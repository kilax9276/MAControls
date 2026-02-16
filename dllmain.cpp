// MA_AUTODOC: ============================================================================
// Copyright Kolobov Aleksei @kilax9276
// MA_AUTODOC: dllmain.cpp
// MA_AUTODOC: Точка входа DLL и глобальный ATL модуль (_AtlModule).
// MA_AUTODOC: Вся инициализация COM/ATL (регистрация классов, DllCanUnloadNow и т.п.) завязана на _AtlModule.
// MA_AUTODOC: ============================================================================

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "MAControls_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CMAControlsModule _AtlModule;

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
    return _AtlModule.DllMain(dwReason, lpReserved);
}
