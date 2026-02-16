// MA_AUTODOC: ============================================================================
// Copyright Kolobov Aleksei @kilax9276
// MA_AUTODOC: MAComboBoxEx.cpp
// MA_AUTODOC: ActiveX-контрол MAComboBoxEx: тонкая обёртка над MSForms.ComboBox.1.
// MA_AUTODOC: Контрол используется как 'оверлей-редактор' в MAMSHFlexGridEx для combo/list ячеек.
// MA_AUTODOC: Ключевая идея: хостить MSForms.ComboBox внутри CAxWindow и перехватывать его внутреннее окно (WndProc) для доп. клавиш/меню.
// MA_AUTODOC: ============================================================================

#include "pch.h"
#include "MAComboBoxEx.h"

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::CMAComboBoxEx
// MA_AUTODOC: Конструктор: задаёт параметры ATL контрола (window-only, размеры по умолчанию).
// MA_AUTODOC: -----------------------------------------------------------------------------
CMAComboBoxEx::CMAComboBoxEx()
{
    m_bWindowOnly = TRUE;
    m_sizeExtent.cx = 2500;
    m_sizeExtent.cy = 600;
    m_sizeNatural = m_sizeExtent;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::OnCreate
// MA_AUTODOC: WM_CREATE: инициализирует AtlAxWin, создаёт MSForms.ComboBox внутри CAxWindow, ставит перехват WndProc и готовит контекстное меню.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAComboBoxEx::OnCreate(UINT, WPARAM, LPARAM, BOOL&)
{
    AtlAxWinInit();

    RECT rc{};
    GetClientRect(&rc);

    m_ax.Create(m_hWnd, rc, nullptr, WS_CHILD | WS_VISIBLE);
    if (!m_ax) return -1;

    // MA_AUTODOC: Создаём внутренний MSForms.ComboBox (Forms.ComboBox.1) — он будет реальным UI ввода.
    HRESULT hr = m_ax.CreateControl(CComBSTR(L"Forms.ComboBox.1"));
    if (FAILED(hr)) return -1;

    hr = m_ax.QueryControl(&m_cbDisp);
    if (FAILED(hr) || !m_cbDisp) return -1;

    // MA_AUTODOC: Находим внутреннее HWND окна ввода MSForms и подменяем его WndProc,
    // MA_AUTODOC: чтобы добавить VB-подобные особенности и своё контекстное меню.
    m_hInner = ::GetWindow(m_ax, GW_CHILD);
    if (m_hInner)
    {
        ::SetWindowLongPtrW(m_hInner, GWLP_USERDATA, (LONG_PTR)this);
        m_oldProc = (WNDPROC)::SetWindowLongPtrW(m_hInner, GWLP_WNDPROC, (LONG_PTR)&CMAComboBoxEx::InnerWndProc);
    }

    // MA_AUTODOC: Простейшее контекстное меню (Copy/Paste). Команды реализованы через SelText.
    m_hMenu = ::CreatePopupMenu();
    ::AppendMenuW(m_hMenu, MF_STRING, 1, L"Copy");
    ::AppendMenuW(m_hMenu, MF_STRING, 2, L"Paste");

    SyncLayout();
    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::OnSize
// MA_AUTODOC: WM_SIZE: синхронизирует геометрию внутреннего Ax окна под размер контрола.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAComboBoxEx::OnSize(UINT, WPARAM, LPARAM, BOOL&)
{
    SyncLayout();
    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::OnSetFocus
// MA_AUTODOC: WM_SETFOCUS: переводит фокус на внутреннее окно ввода MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAComboBoxEx::OnSetFocus(UINT, WPARAM, LPARAM, BOOL&)
{
    if (m_hInner) ::SetFocus(m_hInner);
    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::OnDestroy
// MA_AUTODOC: WM_DESTROY: снимает перехват WndProc, уничтожает меню и освобождает COM ссылки.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAComboBoxEx::OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
{
    if (m_hInner && m_oldProc)
    {
        ::SetWindowLongPtrW(m_hInner, GWLP_WNDPROC, (LONG_PTR)m_oldProc);
        m_oldProc = nullptr;
    }
    if (m_hMenu)
    {
        ::DestroyMenu(m_hMenu);
        m_hMenu = nullptr;
    }
    m_cbDisp.Release();
    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::SyncLayout
// MA_AUTODOC: Вспомогательная функция: растягивает внутренний CAxWindow на весь клиентский прямоугольник.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAComboBoxEx::SyncLayout()
{
    if (!m_ax) return;
    RECT rc{};
    GetClientRect(&rc);
    m_ax.MoveWindow(&rc);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: GetLongProp
// MA_AUTODOC: Утилита: читает LONG/long-свойство из IDispatch. Возвращает def, если свойства нет или тип нельзя привести к VT_I4.
// MA_AUTODOC: -----------------------------------------------------------------------------
static LONG GetLongProp(IDispatch* d, LPCOLESTR name, LONG def = 0)
{
    VARIANT v;
    VariantInit(&v);
    if (SUCCEEDED(DispGet(d, name, &v)))
    {
        VARIANT t;
        VariantInit(&t);
        if (SUCCEEDED(VariantChangeType(&t, &v, 0, VT_I4)))
        {
            LONG r = t.lVal;
            VariantClear(&t);
            VariantClear(&v);
            return r;
        }
        VariantClear(&t);
    }
    VariantClear(&v);
    return def;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: GetStrProp
// MA_AUTODOC: Утилита: читает строковое свойство из IDispatch и возвращает std::wstring (пусто при ошибке).
// MA_AUTODOC: -----------------------------------------------------------------------------
static std::wstring GetStrProp(IDispatch* d, LPCOLESTR name)
{
    VARIANT v;
    VariantInit(&v);
    if (SUCCEEDED(DispGet(d, name, &v)))
    {
        std::wstring s = VariantToWString(v);
        VariantClear(&v);
        return s;
    }
    return L"";
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::HandleTextChangedLikeVB
// MA_AUTODOC: VB-подобная автопрокрутка списка: если Text является префиксом элемента List, двигает TopIndex к этому элементу.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAComboBoxEx::HandleTextChangedLikeVB()
{
    // VB-like: if Text is prefix of some List item -> scroll TopIndex to that item.
    LONG lc = GetLongProp(m_cbDisp, L"ListCount", 0);
    std::wstring txt = GetStrProp(m_cbDisp, L"Text");

    auto lower = [](std::wstring s)
        {
            for (auto& ch : s) ch = (wchar_t)towlower(ch);
            return s;
        };

    std::wstring ltxt = lower(txt);

    for (LONG i = lc - 1; i >= 0; --i)
    {
        VARIANT idx;
        VariantInit(&idx);
        idx.vt = VT_I4;
        idx.lVal = i;

        VARIANT item;
        VariantInit(&item);
        if (SUCCEEDED(DispGetIndexed(m_cbDisp, L"List", &idx, 1, &item)))
        {
            std::wstring li = lower(VariantToWString(item));
            VariantClear(&item);

            if (!ltxt.empty() && li.rfind(ltxt, 0) == 0) // starts with
            {
                VARIANT v;
                VariantInit(&v);
                v.vt = VT_I4;
                v.lVal = i;
                DispPut(m_cbDisp, L"TopIndex", v);
                VariantClear(&v);
                break;
            }
        }
        VariantClear(&idx);
    }
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::DoCopy
// MA_AUTODOC: Копирует выделенный текст (SelText) MSForms.ComboBox в буфер обмена (CF_UNICODETEXT).
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAComboBoxEx::DoCopy()
{
    LONG selLen = GetLongProp(m_cbDisp, L"SelLength", 0);
    if (selLen <= 0) return;

    std::wstring sel = GetStrProp(m_cbDisp, L"SelText");
    if (!sel.empty()) SetClipboardTextW(sel);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::DoPaste
// MA_AUTODOC: Вставляет текст из буфера обмена в текущую позицию (SelText) MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAComboBoxEx::DoPaste()
{
    std::wstring clip;
    if (!GetClipboardTextW(clip) || clip.empty()) return;

    VARIANT v = WStringToVariant(clip);
    DispPut(m_cbDisp, L"SelText", v);
    VariantClear(&v);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::InsertCRLFAtCaret
// MA_AUTODOC: Вставляет CRLF в Text в позиции каретки (SelStart) и переводит каретку после вставки.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAComboBoxEx::InsertCRLFAtCaret()
{
    LONG selStart = GetLongProp(m_cbDisp, L"SelStart", 0);
    std::wstring text = GetStrProp(m_cbDisp, L"Text");

    if (selStart < 0) selStart = 0;
    if (selStart > (LONG)text.size()) selStart = (LONG)text.size();

    text.insert((size_t)selStart, L"\r\n");

    VARIANT v = WStringToVariant(text);
    DispPut(m_cbDisp, L"Text", v);
    VariantClear(&v);

    VARIANT ss;
    VariantInit(&ss);
    ss.vt = VT_I4;
    ss.lVal = selStart + 2;
    DispPut(m_cbDisp, L"SelStart", ss);
    VariantClear(&ss);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::ShowContextMenu
// MA_AUTODOC: Показывает контекстное меню Copy/Paste и включает/выключает пункты в зависимости от выделения/буфера.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAComboBoxEx::ShowContextMenu(int xScreen, int yScreen)
{
    if (!m_hMenu) return;

    std::wstring clip;
    bool hasClip = GetClipboardTextW(clip) && !clip.empty();
    LONG selLen = GetLongProp(m_cbDisp, L"SelLength", 0);

    ::EnableMenuItem(m_hMenu, 1, MF_BYCOMMAND | (selLen > 0 ? MF_ENABLED : MF_GRAYED));
    ::EnableMenuItem(m_hMenu, 2, MF_BYCOMMAND | (hasClip ? MF_ENABLED : MF_GRAYED));

    UINT cmd = ::TrackPopupMenu(m_hMenu, TPM_RETURNCMD | TPM_NONOTIFY, xScreen, yScreen, 0, m_hWnd, nullptr);
    if (cmd == 1) DoCopy();
    else if (cmd == 2) DoPaste();
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::InnerWndProc
// MA_AUTODOC: Подменённая WndProc внутреннего окна: перехватывает Alt+Enter, правый клик и триггерит VB-подобную реакцию на изменение текста.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CALLBACK CMAComboBoxEx::InnerWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    auto* self = (CMAComboBoxEx*)::GetWindowLongPtrW(hWnd, GWLP_USERDATA);
    if (!self || !self->m_oldProc) return ::DefWindowProcW(hWnd, msg, wp, lp);

    switch (msg)
    {
    case WM_KEYDOWN:
    {
        // Alt+Enter inserts CRLF
        if ((GetKeyState(VK_MENU) & 0x8000) && wp == VK_RETURN)
        {
            self->InsertCRLFAtCaret();
            return 0;
        }
        break;
    }
    case WM_KEYUP:
    case WM_CHAR:
        // handled after default proc
        break;

    case WM_RBUTTONUP:
    {
        POINT pt{};
        ::GetCursorPos(&pt);
        self->ShowContextMenu(pt.x, pt.y);
        return 0;
    }
    default:
        break;
    }

    LRESULT r = ::CallWindowProcW(self->m_oldProc, hWnd, msg, wp, lp);

    if (msg == WM_KEYUP || msg == WM_CHAR)
        self->HandleTextChangedLikeVB();

    return r;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::OnDraw
// MA_AUTODOC: Отрисовка: window-only контрол, рисует сам MSForms.ComboBox; здесь ничего не рисуем.
// MA_AUTODOC: -----------------------------------------------------------------------------
HRESULT CMAComboBoxEx::OnDraw(ATL_DRAWINFO&)
{
    // Window-only control: the inner MSForms.ComboBox paints itself.
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::get_Text
// MA_AUTODOC: Читает Text из внутреннего MSForms.ComboBox (предпочтительно), иначе из stock property ATL.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAComboBoxEx::get_Text(BSTR* pstrText)
{
    if (!pstrText) return E_POINTER;
    *pstrText = nullptr;

    // Prefer the inner control (real value)
    if (m_cbDisp)
    {
        CComVariant v;
        HRESULT hr = CComDispatchDriver(m_cbDisp).GetPropertyByName(L"Text", &v);
        if (SUCCEEDED(hr) && SUCCEEDED(v.ChangeType(VT_BSTR)))
        {
            *pstrText = ::SysAllocString(v.bstrVal ? v.bstrVal : L"");
            return *pstrText ? S_OK : E_OUTOFMEMORY;
        }
    }

    // Fallback: stock stored property value
    return CStockPropImpl<CMAComboBoxEx, IMAComboBoxEx>::get_Text(pstrText);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAComboBoxEx::put_Text
// MA_AUTODOC: Пишет Text в stock property (для persistence) и синхронно применяет его к внутреннему MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAComboBoxEx::put_Text(BSTR strText)
{
    // Store into stock property (persistence)
    HRESULT hrBase = CStockPropImpl<CMAComboBoxEx, IMAComboBoxEx>::put_Text(strText);

    // Apply to inner control
    if (m_cbDisp)
    {
        CComVariant v(strText);
        CComDispatchDriver(m_cbDisp).PutPropertyByName(L"Text", &v);
    }

    return hrBase;
}
