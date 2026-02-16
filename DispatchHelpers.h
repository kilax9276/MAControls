// MA_AUTODOC: ============================================================================
// MA_AUTODOC: DispatchHelpers.h
// MA_AUTODOC: Назначение: маленькие безопасные обёртки над IDispatch (Get/Put/Invoke) и утилиты VARIANT/буфера обмена.
// MA_AUTODOC: Используется MAMSHFlexGridEx и MAComboBoxEx для общения с ActiveX (MSHFlexGrid, MSForms.ComboBox) без зависимости от импортированных tlb.
// MA_AUTODOC: ============================================================================

#pragma once
#include <windows.h>
#include <oleauto.h>

#include <string>
#include <vector>   // ✅ ОБЯЗАТЕЛЬНО
#include <cwctype>  // ✅ для towlower 
#include <cstring>  // ✅ для memcpy

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: VariantToWString
// MA_AUTODOC: Преобразует VARIANT в std::wstring. Пытается VT_BSTR напрямую, иначе через VariantChangeType(VT_BSTR).
// MA_AUTODOC: -----------------------------------------------------------------------------
inline std::wstring VariantToWString(const VARIANT& v)
{
    if (v.vt == VT_BSTR && v.bstrVal) return std::wstring(v.bstrVal);
    if (v.vt == VT_EMPTY || v.vt == VT_NULL) return L"";
    VARIANT tmp; VariantInit(&tmp);
    if (SUCCEEDED(VariantChangeType(&tmp, const_cast<VARIANT*>(&v), 0, VT_BSTR)) && tmp.bstrVal)
    {
        std::wstring s(tmp.bstrVal);
        VariantClear(&tmp);
        return s;
    }
    VariantClear(&tmp);
    return L"";
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: WStringToVariant
// MA_AUTODOC: Создаёт VARIANT типа VT_BSTR из std::wstring (выделяет BSTR через SysAllocStringLen).
// MA_AUTODOC: -----------------------------------------------------------------------------
inline VARIANT WStringToVariant(const std::wstring& s)
{
    VARIANT v; VariantInit(&v);
    v.vt = VT_BSTR;
    v.bstrVal = SysAllocStringLen(s.data(), (UINT)s.size());
    return v;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: DispGetId
// MA_AUTODOC: Получает DISPID свойства/метода по имени через IDispatch::GetIDsOfNames.
// MA_AUTODOC: -----------------------------------------------------------------------------
inline HRESULT DispGetId(IDispatch* d, LPCOLESTR name, DISPID* pid)
{
    if (!d) return E_POINTER;
    LPOLESTR n = const_cast<LPOLESTR>(name);
    return d->GetIDsOfNames(IID_NULL, &n, 1, LOCALE_USER_DEFAULT, pid);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: DispInvoke
// MA_AUTODOC: Универсальная обёртка над IDispatch::Invoke (поддержка named args для PROPERTYPUT).
// MA_AUTODOC: -----------------------------------------------------------------------------
inline HRESULT DispInvoke(IDispatch* d, DISPID id, WORD flags, VARIANT* args, UINT argc, VARIANT* ret = nullptr, DISPID* named = nullptr, UINT namedCount = 0)
{
    if (!d) return E_POINTER;
    DISPPARAMS dp{};
    dp.rgvarg = args;
    dp.cArgs = argc;
    dp.rgdispidNamedArgs = named;
    dp.cNamedArgs = namedCount;

    EXCEPINFO ei{};
    UINT argErr = 0;
    return d->Invoke(id, IID_NULL, LOCALE_USER_DEFAULT, flags, &dp, ret, &ei, &argErr);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: DispGet
// MA_AUTODOC: Читает свойство по имени (DISPATCH_PROPERTYGET).
// MA_AUTODOC: -----------------------------------------------------------------------------
inline HRESULT DispGet(IDispatch* d, LPCOLESTR name, VARIANT* ret)
{
    if (!ret) return E_POINTER;
    VariantInit(ret);
    DISPID id{};
    HRESULT hr = DispGetId(d, name, &id);
    if (FAILED(hr)) return hr;
    return DispInvoke(d, id, DISPATCH_PROPERTYGET, nullptr, 0, ret);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: DispPut
// MA_AUTODOC: Пишет свойство по имени (DISPATCH_PROPERTYPUT).
// MA_AUTODOC: -----------------------------------------------------------------------------
inline HRESULT DispPut(IDispatch* d, LPCOLESTR name, const VARIANT& val)
{
    DISPID id{};
    HRESULT hr = DispGetId(d, name, &id);
    if (FAILED(hr)) return hr;

    VARIANT arg = val;
    DISPID dispidNamed = DISPID_PROPERTYPUT;
    return DispInvoke(d, id, DISPATCH_PROPERTYPUT, &arg, 1, nullptr, &dispidNamed, 1);
}

// property/method with indices (VB: Prop(i) / Prop(i,j) / Prop(i,j)=v)
// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: DispGetIndexed
// MA_AUTODOC: Читает индексированное свойство (например TextMatrix(row,col)). Индексы разворачиваются, как требует IDispatch.
// MA_AUTODOC: -----------------------------------------------------------------------------
inline HRESULT DispGetIndexed(IDispatch* d, LPCOLESTR name, VARIANT* idx, UINT idxCount, VARIANT* ret)
{
    if (!ret) return E_POINTER;
    VariantInit(ret);
    DISPID id{};
    HRESULT hr = DispGetId(d, name, &id);
    if (FAILED(hr)) return hr;

    // IDispatch wants args reversed
    std::vector<VARIANT> args(idxCount);
    for (UINT i = 0; i < idxCount; ++i) args[i] = idx[idxCount - 1 - i];

    return DispInvoke(d, id, DISPATCH_PROPERTYGET, args.data(), idxCount, ret);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: DispPutIndexed
// MA_AUTODOC: Пишет индексированное свойство. Аргументы формируются как: value, затем индексы в обратном порядке.
// MA_AUTODOC: -----------------------------------------------------------------------------
inline HRESULT DispPutIndexed(IDispatch* d, LPCOLESTR name, VARIANT* idx, UINT idxCount, const VARIANT& val)
{
    DISPID id{};
    HRESULT hr = DispGetId(d, name, &id);
    if (FAILED(hr)) return hr;

    // args: value first, then indices reversed
    std::vector<VARIANT> args(1 + idxCount);
    args[0] = val;
    for (UINT i = 0; i < idxCount; ++i) args[1 + i] = idx[idxCount - 1 - i];

    DISPID dispidNamed = DISPID_PROPERTYPUT;
    return DispInvoke(d, id, DISPATCH_PROPERTYPUT, args.data(), (UINT)args.size(), nullptr, &dispidNamed, 1);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: GetClipboardTextW
// MA_AUTODOC: Читает CF_UNICODETEXT из буфера обмена в std::wstring.
// MA_AUTODOC: -----------------------------------------------------------------------------
inline bool GetClipboardTextW(std::wstring& out)
{
    out.clear();
    if (!OpenClipboard(nullptr)) return false;

    HANDLE h = GetClipboardData(CF_UNICODETEXT);
    if (!h) { CloseClipboard(); return false; }

    const wchar_t* p = (const wchar_t*)GlobalLock(h);
    if (!p) { CloseClipboard(); return false; }

    out = p;
    GlobalUnlock(h);
    CloseClipboard();
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: SetClipboardTextW
// MA_AUTODOC: Записывает std::wstring в буфер обмена как CF_UNICODETEXT.
// MA_AUTODOC: -----------------------------------------------------------------------------
inline bool SetClipboardTextW(const std::wstring& s)
{
    if (!OpenClipboard(nullptr)) return false;
    EmptyClipboard();

    size_t bytes = (s.size() + 1) * sizeof(wchar_t);
    HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, bytes);
    if (!h) { CloseClipboard(); return false; }

    void* p = GlobalLock(h);
    memcpy(p, s.c_str(), bytes);
    GlobalUnlock(h);

    SetClipboardData(CF_UNICODETEXT, h);
    CloseClipboard();
    return true;
}
