﻿// MA_AUTODOC: ============================================================================
// Copyright Kolobov Aleksei @kilax9276
// MA_AUTODOC: AxHostHelpers.h
// MA_AUTODOC: Назначение: создание ActiveX-контролов внутри ATL CAxWindow с учётом возможного лицензирования (IClassFactory2).
// MA_AUTODOC: Главная задача: уметь создать ActiveX даже в окружениях, где контроль требует лиценз-ключ (CLASS_E_NOTLICENSED).
// MA_AUTODOC: ============================================================================

#pragma once
#include <atlbase.h>
#include <atlhost.h>
#include <atlstr.h>
#include <comdef.h>
#include <commctrl.h>

#pragma comment(lib, "comctl32.lib")

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CreateAxControlWithLicFallback
// MA_AUTODOC: Создаёт экземпляр ActiveX по ProgID/CLSID в окне-хосте.
// MA_AUTODOC:   1) Сначала пробует AtlAxCreateControlEx (обычный путь).
// MA_AUTODOC:   2) Если получаем CLASS_E_NOTLICENSED или E_ACCESSDENIED, пробуем fallback через IClassFactory2:
// MA_AUTODOC:      - RequestLicKey() → CreateInstanceLic().
// MA_AUTODOC: Возвращает IUnknown* созданного объекта (caller обязан Release).
// MA_AUTODOC: -----------------------------------------------------------------------------
inline HRESULT CreateAxControlWithLicFallback(LPCWSTR clsOrProgId, HWND hHost, IUnknown** ppUnk)
{
    if (!ppUnk) return E_POINTER;
    *ppUnk = nullptr;

    // MA_AUTODOC: Путь 1: обычный AtlAxCreateControlEx (самый быстрый вариант, без лиценз-логики).
    CComPtr<IUnknown> unk;
    HRESULT hr = AtlAxCreateControlEx(
        clsOrProgId,
        hHost,
        nullptr,
        nullptr,
        &unk,
        IID_NULL,
        nullptr
    );

    if (SUCCEEDED(hr) && unk)
    {
        *ppUnk = unk.Detach();
        return S_OK;
    }

    // MA_AUTODOC: Если ошибка не связана с лицензией/доступом, возвращаем её сразу — fallback не поможет.
    if (hr != CLASS_E_NOTLICENSED && hr != E_ACCESSDENIED)
        return hr;

    // MA_AUTODOC: Путь 2 (fallback): создаём через IClassFactory2, запрашиваем лиценз-ключ и вызываем CreateInstanceLic().
    CLSID clsid{};
    HRESULT hrC = CLSIDFromString(const_cast<LPOLESTR>(clsOrProgId), &clsid);
    if (FAILED(hrC))
    {
        hrC = CLSIDFromProgID(clsOrProgId, &clsid);
        if (FAILED(hrC))
            return hrC;
    }

    CComPtr<IClassFactory2> cf2;
    hrC = CoGetClassObject(
        clsid,
        CLSCTX_INPROC_SERVER,
        nullptr,
        IID_PPV_ARGS(&cf2)
    );
    if (FAILED(hrC) || !cf2)
        return hr; // возвращаем первичную ошибку AtlAxCreateControlEx, чтобы хост видел причину

    CComBSTR lic;
    hrC = cf2->RequestLicKey(0, &lic);
    if (FAILED(hrC) || lic.Length() == 0)
        return CLASS_E_NOTLICENSED;

    hrC = cf2->CreateInstanceLic(nullptr, nullptr, IID_IUnknown, lic, (void**)&unk);
    if (FAILED(hrC) || !unk)
        return hrC;

    *ppUnk = unk.Detach();
    return S_OK;
}
