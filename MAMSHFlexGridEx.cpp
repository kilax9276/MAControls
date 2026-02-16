// MA_AUTODOC: ============================================================================
// Copyright Kolobov Aleksei @kilax9276
// MA_AUTODOC: MAMSHFlexGridEx.cpp
// MA_AUTODOC: ActiveX-контрол MAMSHFlexGridEx: обёртка над MSHierarchicalFlexGridLib.MSHFlexGrid.
// MA_AUTODOC: Контрол создаёт настоящий MSHFlexGrid внутри себя и добавляет поверх него настраиваемое редактирование ячеек:
// MA_AUTODOC:   - для текста: popup Win32 EDIT рядом с активной ячейкой (с опциональным multiline),
// MA_AUTODOC:   - для списка/комбо: оверлей ActiveX MAComboBoxEx (внутри MSForms.ComboBox).
// MA_AUTODOC: Дополнительно: реализована отложенная навигация после commit (Tab/стрелки) и восстановление фокуса,
// MA_AUTODOC: чтобы после редактирования не 'ломались' стрелки в гриде из-за гонок фокуса в контейнерах (VB6/ThunderForm).
// MA_AUTODOC: ============================================================================

#include "pch.h"
#include "MAMSHFlexGridEx.h"

#pragma comment(lib, "comctl32.lib")

// PROGIDs
static const wchar_t* PROGID_MSHFLEXGRID = L"MSHierarchicalFlexGridLib.MSHFlexGrid";
static const wchar_t* PROGID_EDITOR = L"C935_Gen34.MA_ComboBoxEx.1";

static const UINT_PTR SUBCLASS_ID_GRID = 11;
static const UINT_PTR SUBCLASS_ID_EDIT = 22;
static const UINT_PTR SUBCLASS_ID_POPUPEDIT = 33;

// Popup editor (native Win32 EDIT) window class / constants
static const wchar_t* POPUP_EDITOR_WNDCLASS = L"MA_MSHFlexGridEx_PopupEditor";
static const int POPUP_EDIT_ID = 1001;
static const int POPUP_PADDING_PX = 4;



#include <strsafe.h>
#include <windowsx.h>
#include <string>

#define MA_DIAG_FOCUS 0

#if MA_DIAG_FOCUS

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: MA_DbgOutV
// MA_AUTODOC: Диагностика фокуса (MA_DIAG_FOCUS): форматированный вывод в OutputDebugStringW (вариант с va_list).
// MA_AUTODOC: -----------------------------------------------------------------------------
static void MA_DbgOutV(const wchar_t* fmt, va_list ap)
{
    wchar_t buf[2048];
    buf[0] = 0;
    StringCchVPrintfW(buf, _countof(buf), fmt, ap);
    OutputDebugStringW(buf);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: MA_DbgOut
// MA_AUTODOC: Диагностика фокуса (MA_DIAG_FOCUS): форматированный вывод в OutputDebugStringW.
// MA_AUTODOC: -----------------------------------------------------------------------------
static void MA_DbgOut(const wchar_t* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    MA_DbgOutV(fmt, ap);
    va_end(ap);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: MA_DescribeHwnd
// MA_AUTODOC: Диагностика фокуса: формирует строку с информацией о HWND (класс, текст, style/exstyle).
// MA_AUTODOC: -----------------------------------------------------------------------------
static void MA_DescribeHwnd(HWND h, wchar_t* out, size_t cch)
{
    if (!out || cch == 0) return;
    out[0] = 0;

    if (!h || !IsWindow(h))
    {
        StringCchPrintfW(out, cch, L"(null/invalid)");
        return;
    }

    wchar_t cls[128] = L"";
    wchar_t txt[128] = L"";
    GetClassNameW(h, cls, _countof(cls));
    GetWindowTextW(h, txt, _countof(txt));

    LONG_PTR style = GetWindowLongPtrW(h, GWL_STYLE);
    LONG_PTR exstyle = GetWindowLongPtrW(h, GWL_EXSTYLE);

    StringCchPrintfW(out, cch,
        L"hwnd=0x%p class=%s text=\"%s\" style=0x%p ex=0x%p",
        h, cls, txt, (void*)style, (void*)exstyle);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: MA_DumpFocusSnapshot
// MA_AUTODOC: Диагностика фокуса: печатает снимок текущего фокуса и окон грида/редактора.
// MA_AUTODOC: -----------------------------------------------------------------------------
static void MA_DumpFocusSnapshot(
    const wchar_t* tag,
    HWND hCtrl,
    HWND hAxGrid,
    HWND hGridInner,
    HWND hAxEdit,
    HWND hEditInner,
    bool inEdit,
    bool usingPopup,
    HWND hPopup,
    HWND hPopupEdit)
{
    HWND hf = GetFocus();

    wchar_t a[256], b[256], c[256], d[256], e[256], f[256], g[256];
    MA_DescribeHwnd(hf, a, _countof(a));
    MA_DescribeHwnd(hCtrl, b, _countof(b));
    MA_DescribeHwnd(hAxGrid, c, _countof(c));
    MA_DescribeHwnd(hGridInner, d, _countof(d));
    MA_DescribeHwnd(hAxEdit, e, _countof(e));
    MA_DescribeHwnd(hEditInner, f, _countof(f));
    MA_DescribeHwnd(hPopupEdit, g, _countof(g));

    MA_DbgOut(L"[FOCUS:%s] inEdit=%d usingPopup=%d\n", tag ? tag : L"(null)", inEdit ? 1 : 0, usingPopup ? 1 : 0);
    MA_DbgOut(L"  GetFocus: %s\n", a);
    MA_DbgOut(L"  Ctrl    : %s\n", b);
    MA_DbgOut(L"  AxGrid  : %s\n", c);
    MA_DbgOut(L"  GridIn  : %s\n", d);
    MA_DbgOut(L"  AxEdit  : %s\n", e);
    MA_DbgOut(L"  EditIn  : %s\n", f);
    MA_DbgOut(L"  PopupEd : %s\n", g);

    if (hf && IsWindow(hf))
    {
        HWND root = GetAncestor(hf, GA_ROOT);
        HWND rootOwner = GetAncestor(hf, GA_ROOTOWNER);
        wchar_t r1[256], r2[256];
        MA_DescribeHwnd(root, r1, _countof(r1));
        MA_DescribeHwnd(rootOwner, r2, _countof(r2));
        MA_DbgOut(L"  Root    : %s\n", r1);
        MA_DbgOut(L"  RootOwn : %s\n", r2);
    }
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: MA_DumpGridChildren
// MA_AUTODOC: Диагностика: перечисляет первые N дочерних окон внутри Ax-хоста грида (для поиска 'inner' HWND).
// MA_AUTODOC: -----------------------------------------------------------------------------
static void MA_DumpGridChildren(HWND hAxGrid, const wchar_t* tag)
{
    if (!hAxGrid || !IsWindow(hAxGrid))
        return;

    MA_DbgOut(L"[GRIDCHILDREN:%s] hAxGrid=0x%p\n", tag ? tag : L"(null)", hAxGrid);

    struct Ctx { int n; };
    Ctx ctx{ 0 };

    EnumChildWindows(hAxGrid,
        [](HWND h, LPARAM lp) -> BOOL
        {
            auto* p = (Ctx*)lp;
            if (!p) return FALSE;
            if (p->n >= 32) return FALSE; // ограничим вывод

            wchar_t s[256];
            MA_DescribeHwnd(h, s, _countof(s));
            MA_DbgOut(L"  child[%02d]: %s\n", p->n, s);
            p->n++;
            return TRUE;
        },
        (LPARAM)&ctx);
}

#endif // MA_DIAG_FOCUS



// ---------------- variant -> items helper ----------------

static bool ExtractBstrItemsFromVariant(const VARIANT& in, std::vector<CComBSTR>& out)
{
    out.clear();

    VARIANT v;
    VariantInit(&v);

    HRESULT hr = VariantCopyInd(&v, const_cast<VARIANT*>(&in));
    if (FAILED(hr))
        return false;

    if (v.vt == VT_BSTR)
    {
        out.emplace_back(v.bstrVal ? v.bstrVal : L"");
        VariantClear(&v);
        return true;
    }

    if ((v.vt & VT_ARRAY) == VT_ARRAY)
    {
        SAFEARRAY* psa = v.parray;
        if (!psa)
        {
            VariantClear(&v);
            return false;
        }

        VARTYPE vtElem = VT_EMPTY;
        SafeArrayGetVartype(psa, &vtElem);

        LONG lBound = 0, uBound = -1;
        if (FAILED(SafeArrayGetLBound(psa, 1, &lBound)) || FAILED(SafeArrayGetUBound(psa, 1, &uBound)))
        {
            VariantClear(&v);
            return false;
        }

        for (LONG i = lBound; i <= uBound; ++i)
        {
            if (vtElem == VT_BSTR)
            {
                BSTR b = nullptr;
                if (SUCCEEDED(SafeArrayGetElement(psa, &i, &b)))
                {
                    out.emplace_back(b ? b : L"");
                    if (b) SysFreeString(b);
                }
            }
            else if (vtElem == VT_VARIANT)
            {
                VARIANT ev;
                VariantInit(&ev);
                if (SUCCEEDED(SafeArrayGetElement(psa, &i, &ev)))
                {
                    VARIANT t;
                    VariantInit(&t);
                    if (SUCCEEDED(VariantChangeType(&t, &ev, 0, VT_BSTR)))
                        out.emplace_back(t.bstrVal ? t.bstrVal : L"");
                    VariantClear(&t);
                    VariantClear(&ev);
                }
            }
        }

        VariantClear(&v);
        return true;
    }

    VariantClear(&v);
    return false;
}

// ---------------- CMAMSHFlexGridEx ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::CMAMSHFlexGridEx
// MA_AUTODOC: Конструктор: инициализирует поля объекта и дефолтные настройки редактора/навигации.
// MA_AUTODOC: -----------------------------------------------------------------------------
CMAMSHFlexGridEx::CMAMSHFlexGridEx()
{
    m_bWindowOnly = TRUE;
    m_sizeExtent.cx = 6000;
    m_sizeExtent.cy = 3000;
    m_sizeNatural = m_sizeExtent;

    m_defaultCfg.type = maCellText;
    m_defaultCfg.hasItems = false;

    m_defaultNav.exitKeysMask =
        maNavExitTab | maNavExitShiftTab |
        maNavExitLeft | maNavExitRight | maNavExitUp | maNavExitDown;
    m_defaultNav.tabWrap = VARIANT_TRUE;
    m_defaultNav.skipReadOnly = VARIANT_TRUE;
    m_defaultNav.beginEditAfterMove = VARIANT_FALSE;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::GetEffectiveConfig
// MA_AUTODOC: Вычисляет итоговую конфигурацию редактора для конкретной ячейки (default → column → cell).
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::GetEffectiveConfig(long row, long col, CellConfig& out) const
{
    auto itCell = m_cellCfg.find(MakeKey(row, col));
    if (itCell != m_cellCfg.end())
    {
        out = itCell->second;
        return true;
    }

    auto itCol = m_colCfg.find(col);
    if (itCol != m_colCfg.end())
    {
        out = itCol->second;
        return true;
    }

    out = m_defaultCfg;
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::GetEffectiveNavConfig
// MA_AUTODOC: Вычисляет итоговые опции навигации для конкретной ячейки (default → row/column → cell).
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::GetEffectiveNavConfig(long row, long col, NavConfig& out) const
{
    auto itCell = m_cellNav.find(MakeKey(row, col));
    if (itCell != m_cellNav.end())
    {
        out = itCell->second;
        return true;
    }

    auto itRow = m_rowNav.find(row);
    if (itRow != m_rowNav.end())
    {
        out = itRow->second;
        return true;
    }

    auto itCol = m_colNav.find(col);
    if (itCol != m_colNav.end())
    {
        out = itCol->second;
        return true;
    }

    out = m_defaultNav;
    return true;
}

// ---------------- IMAMSHFlexGridEx additions ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::get_Grid
// MA_AUTODOC: Возвращает IDispatch на внутренний MSHFlexGrid, чтобы хост мог напрямую читать/писать его свойства.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::get_Grid(IDispatch** ppGrid)
{
    if (!ppGrid) return E_POINTER;
    *ppGrid = m_gridDisp;
    if (*ppGrid) (*ppGrid)->AddRef();
    return S_OK;
}


// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetColumnHeaderText
// MA_AUTODOC: Устанавливает текст заголовка столбца в фиксированной строке (row=0) через TextMatrix.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetColumnHeaderText(LONG col, BSTR text)
{
    if (!m_gridDisp)
        return E_UNEXPECTED;

    long cols = 0;
    if (!DispGetLong(m_gridDisp, L"Cols", cols))
        return E_FAIL;

    if (col < 0 || col >= cols)
        return E_INVALIDARG;

    long fixedRows = 0;
    DispGetLong(m_gridDisp, L"FixedRows", fixedRows);
    if (fixedRows < 1)
        DispPutLong(m_gridDisp, L"FixedRows", 1);

    if (!PutTextMatrix(0, col, text ? text : L""))
        return E_FAIL;

    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetRowHeaderText
// MA_AUTODOC: Устанавливает текст заголовка строки в фиксированном столбце (col=0) через TextMatrix.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetRowHeaderText(LONG row, BSTR text)
{
    if (!m_gridDisp)
        return E_UNEXPECTED;

    long rows = 0;
    if (!DispGetLong(m_gridDisp, L"Rows", rows))
        return E_FAIL;

    if (row < 0 || row >= rows)
        return E_INVALIDARG;

    long fixedCols = 0;
    DispGetLong(m_gridDisp, L"FixedCols", fixedCols);
    if (fixedCols < 1)
        DispPutLong(m_gridDisp, L"FixedCols", 1);

    if (!PutTextMatrix(row, 0, text ? text : L""))
        return E_FAIL;

    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetCornerHeaderText
// MA_AUTODOC: Устанавливает текст в левом верхнем углу заголовков (row=0,col=0).
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetCornerHeaderText(BSTR text)
{
    if (!m_gridDisp)
        return E_UNEXPECTED;

    long fixedRows = 0, fixedCols = 0;
    DispGetLong(m_gridDisp, L"FixedRows", fixedRows);
    DispGetLong(m_gridDisp, L"FixedCols", fixedCols);

    if (fixedRows < 1)
        DispPutLong(m_gridDisp, L"FixedRows", 1);
    if (fixedCols < 1)
        DispPutLong(m_gridDisp, L"FixedCols", 1);

    if (!PutTextMatrix(0, 0, text ? text : L""))
        return E_FAIL;

    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::put_TextEditWidthPx
// MA_AUTODOC: Сохраняет ширину popup текстового редактора в пикселях (0 = ширина ячейки).
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::put_TextEditWidthPx(LONG px)
{
    if (px < 0)
        return E_INVALIDARG;

    m_textEditWidthPx = px;

    if (m_inEdit && m_usingPopupEditor)
        PositionPopupEditorBelowCell();

    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::get_TextEditWidthPx
// MA_AUTODOC: Возвращает текущую ширину popup текстового редактора в пикселях.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::get_TextEditWidthPx(LONG* ppx)
{
    if (!ppx)
        return E_POINTER;

    *ppx = m_textEditWidthPx;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::put_TextEditVisibleLines
// MA_AUTODOC: Задаёт количество видимых строк в multiline popup редакторе (>=1).
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::put_TextEditVisibleLines(LONG lines)
{
    if (lines < 1)
        return E_INVALIDARG;

    m_textEditVisibleLines = lines;

    if (m_inEdit && m_usingPopupEditor && m_popupEditCreatedMultiline)
        PositionPopupEditorBelowCell();

    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::get_TextEditVisibleLines
// MA_AUTODOC: Возвращает количество видимых строк для multiline popup редактора.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::get_TextEditVisibleLines(LONG* plines)
{
    if (!plines)
        return E_POINTER;

    *plines = m_textEditVisibleLines;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::put_TextEditMultiline
// MA_AUTODOC: Включает/выключает multiline режим popup редактора (Enter=новая строка, Ctrl+Enter=commit).
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::put_TextEditMultiline(VARIANT_BOOL vbool)
{
    m_textEditMultiline = vbool ? VARIANT_TRUE : VARIANT_FALSE;

    // If currently editing with popup editor, try to apply immediately by recreating the EDIT control.
    if (m_inEdit && m_usingPopupEditor && m_hPopup && m_hPopupEdit)
    {
        // Preserve current text and selection.
        int len = ::GetWindowTextLengthW(m_hPopupEdit);
        std::wstring buf;
        buf.resize((size_t)len + 1);
        ::GetWindowTextW(m_hPopupEdit, &buf[0], len + 1);
        buf.resize((size_t)len);

        DWORD selStart = 0, selEnd = 0;
        ::SendMessageW(m_hPopupEdit, EM_GETSEL, (WPARAM)&selStart, (LPARAM)&selEnd);

        const bool wantMultiline = (m_textEditMultiline == VARIANT_TRUE);
        if (EnsurePopupEditorCreated(wantMultiline))
        {
            ::SetWindowTextW(m_hPopupEdit, buf.c_str());
            ::SendMessageW(m_hPopupEdit, EM_SETSEL, selStart, selEnd);
            PositionPopupEditorBelowCell();
            ::SetFocus(m_hPopupEdit);
        }
    }

    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::get_TextEditMultiline
// MA_AUTODOC: Возвращает флаг multiline режима popup редактора.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::get_TextEditMultiline(VARIANT_BOOL* pvbool)
{
    if (!pvbool)
        return E_POINTER;

    *pvbool = m_textEditMultiline;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetCellType
// MA_AUTODOC: Задаёт тип редактора для конкретной ячейки (text/combo/list/read-only).
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetCellType(LONG row, LONG col, MACellEditorType cellType)
{
    CellConfig cfg;
    GetEffectiveConfig(row, col, cfg);

    cfg.type = cellType;
    m_cellCfg[MakeKey(row, col)] = cfg;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::GetCellType
// MA_AUTODOC: Возвращает итоговый тип редактора для конкретной ячейки.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::GetCellType(LONG row, LONG col, MACellEditorType* pCellType)
{
    if (!pCellType) return E_POINTER;

    CellConfig cfg;
    GetEffectiveConfig(row, col, cfg);
    *pCellType = cfg.type;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetCellItems
// MA_AUTODOC: Устанавливает список значений (items) для combo/list редактора конкретной ячейки.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetCellItems(LONG row, LONG col, VARIANT items)
{
    CellConfig cfg;
    GetEffectiveConfig(row, col, cfg);

    std::vector<CComBSTR> list;
    if (!ExtractBstrItemsFromVariant(items, list))
        return E_INVALIDARG;

    cfg.items = std::move(list);
    cfg.hasItems = true;
    m_cellCfg[MakeKey(row, col)] = cfg;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ClearCellItems
// MA_AUTODOC: Удаляет список значений (items) у конкретной ячейки, не меняя тип.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::ClearCellItems(LONG row, LONG col)
{
    auto it = m_cellCfg.find(MakeKey(row, col));
    if (it == m_cellCfg.end())
        return S_OK;

    it->second.items.clear();
    it->second.hasItems = false;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ClearCellConfig
// MA_AUTODOC: Удаляет все настройки для конкретной ячейки (возврат к column/default).
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::ClearCellConfig(LONG row, LONG col)
{
    m_cellCfg.erase(MakeKey(row, col));
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetColumnType
// MA_AUTODOC: Задаёт тип редактора по умолчанию для столбца.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetColumnType(LONG col, MACellEditorType cellType)
{
    CellConfig cfg;
    auto it = m_colCfg.find(col);
    if (it != m_colCfg.end()) cfg = it->second;
    else cfg = m_defaultCfg;

    cfg.type = cellType;
    m_colCfg[col] = cfg;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetColumnItems
// MA_AUTODOC: Задаёт список значений (items) по умолчанию для столбца.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetColumnItems(LONG col, VARIANT items)
{
    std::vector<CComBSTR> list;
    if (!ExtractBstrItemsFromVariant(items, list))
        return E_INVALIDARG;

    CellConfig cfg;
    auto it = m_colCfg.find(col);
    if (it != m_colCfg.end()) cfg = it->second;
    else cfg = m_defaultCfg;

    cfg.items = std::move(list);
    cfg.hasItems = true;
    m_colCfg[col] = cfg;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ClearColumnConfig
// MA_AUTODOC: Сбрасывает настройки столбца (тип/items).
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::ClearColumnConfig(LONG col)
{
    m_colCfg.erase(col);
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetDefaultCellType
// MA_AUTODOC: Задаёт глобальный тип редактора по умолчанию для всех ячеек.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetDefaultCellType(MACellEditorType cellType)
{
    m_defaultCfg.type = cellType;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetDefaultCellItems
// MA_AUTODOC: Задаёт глобальный список значений (items) по умолчанию для всех combo/list ячеек.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetDefaultCellItems(VARIANT items)
{
    std::vector<CComBSTR> list;
    if (!ExtractBstrItemsFromVariant(items, list))
        return E_INVALIDARG;

    m_defaultCfg.items = std::move(list);
    m_defaultCfg.hasItems = true;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ClearDefaultCellItems
// MA_AUTODOC: Сбрасывает глобальный список items по умолчанию.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::ClearDefaultCellItems()
{
    m_defaultCfg.items.clear();
    m_defaultCfg.hasItems = false;
    return S_OK;
}

// ---------------- Level-B navigation COM API ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetDefaultNavOptions
// MA_AUTODOC: Задаёт глобальные опции навигации (exitKeysMask/tabWrap/skipReadOnly/beginEditAfterMove).
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetDefaultNavOptions(LONG exitKeysMask, VARIANT_BOOL tabWrap, VARIANT_BOOL skipReadOnly, VARIANT_BOOL beginEditAfterMove)
{
    m_defaultNav.exitKeysMask = exitKeysMask;
    m_defaultNav.tabWrap = tabWrap;
    m_defaultNav.skipReadOnly = skipReadOnly;
    m_defaultNav.beginEditAfterMove = beginEditAfterMove;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetColumnNavOptions
// MA_AUTODOC: Задаёт опции навигации для столбца.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetColumnNavOptions(LONG col, LONG exitKeysMask, VARIANT_BOOL tabWrap, VARIANT_BOOL skipReadOnly, VARIANT_BOOL beginEditAfterMove)
{
    NavConfig cfg;
    cfg.exitKeysMask = exitKeysMask;
    cfg.tabWrap = tabWrap;
    cfg.skipReadOnly = skipReadOnly;
    cfg.beginEditAfterMove = beginEditAfterMove;
    m_colNav[col] = cfg;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetRowNavOptions
// MA_AUTODOC: Задаёт опции навигации для строки.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetRowNavOptions(LONG row, LONG exitKeysMask, VARIANT_BOOL tabWrap, VARIANT_BOOL skipReadOnly, VARIANT_BOOL beginEditAfterMove)
{
    NavConfig cfg;
    cfg.exitKeysMask = exitKeysMask;
    cfg.tabWrap = tabWrap;
    cfg.skipReadOnly = skipReadOnly;
    cfg.beginEditAfterMove = beginEditAfterMove;
    m_rowNav[row] = cfg;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetCellNavOptions
// MA_AUTODOC: Задаёт опции навигации для конкретной ячейки.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::SetCellNavOptions(LONG row, LONG col, LONG exitKeysMask, VARIANT_BOOL tabWrap, VARIANT_BOOL skipReadOnly, VARIANT_BOOL beginEditAfterMove)
{
    NavConfig cfg;
    cfg.exitKeysMask = exitKeysMask;
    cfg.tabWrap = tabWrap;
    cfg.skipReadOnly = skipReadOnly;
    cfg.beginEditAfterMove = beginEditAfterMove;
    m_cellNav[MakeKey(row, col)] = cfg;
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ClearColumnNavOptions
// MA_AUTODOC: Сбрасывает опции навигации столбца.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::ClearColumnNavOptions(LONG col)
{
    m_colNav.erase(col);
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ClearRowNavOptions
// MA_AUTODOC: Сбрасывает опции навигации строки.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::ClearRowNavOptions(LONG row)
{
    m_rowNav.erase(row);
    return S_OK;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ClearCellNavOptions
// MA_AUTODOC: Сбрасывает опции навигации конкретной ячейки.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::ClearCellNavOptions(LONG row, LONG col)
{
    m_cellNav.erase(MakeKey(row, col));
    return S_OK;
}

// ---------------- runtime/ambient helpers ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::IsUserMode
// MA_AUTODOC: Проверяет, запущен ли контрол в пользовательском режиме (а не в дизайнере/IDE).
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::IsUserMode()
{
    CComVariant v;
    HRESULT hr = GetAmbientProperty(DISPID_AMBIENT_USERMODE, v);
    if (SUCCEEDED(hr) && v.vt == VT_BOOL)
        return v.boolVal == VARIANT_TRUE;

    return true;
}

// ---------------- editor creation ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::EnsureEditorCreated
// MA_AUTODOC: Создаёт ActiveX редактор MAComboBoxEx внутри m_axEdit и получает IDispatch на внутренний MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::EnsureEditorCreated()
{
    if (m_editorDisp && m_comboDisp)
        return true;

    if (!m_axEdit)
        return false;

    m_editAO.Release();

    CComPtr<IUnknown> unk;
    HRESULT hr = CreateAxControlWithLicFallback(PROGID_EDITOR, m_axEdit, &unk);
    m_hrEditor = hr;
    if (FAILED(hr) || !unk)
        return false;

    unk->QueryInterface(&m_editorDisp);
    if (!m_editorDisp)
        return false;

    unk->QueryInterface(&m_editAO);

    {
        CComDispatchDriver dd(m_editorDisp);
        CComVariant v;
        if (SUCCEEDED(dd.GetPropertyByName(L"Combo", &v)) && v.vt == VT_DISPATCH && v.pdispVal)
            m_comboDisp = v.pdispVal;
    }

    HookEditInnerIfPossible();
    return (m_editorDisp != nullptr);
}


// ---------------- popup editor (native Win32 EDIT) ----------------


// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::EnsurePopupEditorCreated
// MA_AUTODOC: Создаёт popup окно и Win32 EDIT для текстового редактирования; при смене multiline может пересоздавать EDIT.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::EnsurePopupEditorCreated(bool wantMultiline)
{
    // Create the popup window (container) once, and (re)create the EDIT child
    // depending on single-line / multi-line mode.
    if (!m_hPopup)
    {
        WNDCLASSEXW wc{};
        wc.cbSize = sizeof(wc);
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = PopupWndProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = _AtlBaseModule.GetModuleInstance();
        wc.hCursor = ::LoadCursorW(nullptr, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszMenuName = nullptr;
        wc.lpszClassName = POPUP_EDITOR_WNDCLASS;

        ::RegisterClassExW(&wc);

        m_hPopup = ::CreateWindowExW(
            WS_EX_TOOLWINDOW,
            POPUP_EDITOR_WNDCLASS,
            L"",
            WS_POPUP | WS_BORDER,
            0, 0, 10, 10,
            m_hWnd,
            nullptr,
            _AtlBaseModule.GetModuleInstance(),
            this);

        if (!m_hPopup)
            return false;
    }

    // If mode changed, destroy and recreate the EDIT with proper styles.
    if (m_hPopupEdit && (m_popupEditCreatedMultiline != wantMultiline))
    {
        RemoveWindowSubclass(m_hPopupEdit, PopupEditSubclassProc, SUBCLASS_ID_POPUPEDIT);
        ::DestroyWindow(m_hPopupEdit);
        m_hPopupEdit = nullptr;
    }

    if (!m_hPopupEdit)
    {
        DWORD style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_NOHIDESEL;
        if (wantMultiline)
        {
            style |= WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN;
        }
        else
        {
            style |= ES_AUTOHSCROLL;
        }

        HINSTANCE hInst = _AtlBaseModule.GetModuleInstance();

        m_hPopupEdit = ::CreateWindowExW(
            WS_EX_CLIENTEDGE,
            L"EDIT",
            L"",
            style,
            POPUP_PADDING_PX, POPUP_PADDING_PX, 10, 10,
            m_hPopup,
            (HMENU)(INT_PTR)POPUP_EDIT_ID,
            hInst,
            nullptr);

        if (!m_hPopupEdit)
            return false;

        // Default GUI font
        HFONT hFont = (HFONT)::GetStockObject(DEFAULT_GUI_FONT);
        if (hFont)
            ::SendMessageW(m_hPopupEdit, WM_SETFONT, (WPARAM)hFont, TRUE);

        // Subclass the EDIT to intercept Enter/Escape and focus tracking.
        if (!SetWindowSubclass(m_hPopupEdit, PopupEditSubclassProc, SUBCLASS_ID_POPUPEDIT, (DWORD_PTR)this))
        {
            ::DestroyWindow(m_hPopupEdit);
            m_hPopupEdit = nullptr;
            return false;
        }

        m_popupEditCreatedMultiline = wantMultiline;
    }

    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::GetPopupEditLineHeightPx
// MA_AUTODOC: Вычисляет высоту строки для popup EDIT по текущему шрифту (для расчёта высоты multiline окна).
// MA_AUTODOC: -----------------------------------------------------------------------------
int CMAMSHFlexGridEx::GetPopupEditLineHeightPx() const
{
    HFONT hFont = nullptr;

    if (m_hPopupEdit && ::IsWindow(m_hPopupEdit))
        hFont = (HFONT)::SendMessageW(m_hPopupEdit, WM_GETFONT, 0, 0);

    if (!hFont)
        hFont = (HFONT)::GetStockObject(DEFAULT_GUI_FONT);

    HDC hdc = nullptr;
    if (m_hPopupEdit && ::IsWindow(m_hPopupEdit))
        hdc = ::GetDC(m_hPopupEdit);
    else if (m_hWnd)
        hdc = ::GetDC(m_hWnd);

    if (!hdc)
        return 16;

    HFONT hOld = nullptr;
    if (hFont)
        hOld = (HFONT)::SelectObject(hdc, hFont);

    TEXTMETRICW tm{};
    ::GetTextMetricsW(hdc, &tm);

    if (hOld)
        ::SelectObject(hdc, hOld);

    if (m_hPopupEdit && ::IsWindow(m_hPopupEdit))
        ::ReleaseDC(m_hPopupEdit, hdc);
    else
        ::ReleaseDC(m_hWnd, hdc);

    int lh = (int)tm.tmHeight + (int)tm.tmExternalLeading;
    if (lh < 14) lh = 14;
    return lh;
}


// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::PositionPopupEditorBelowCell
// MA_AUTODOC: Позиционирует popup редактор рядом с активной ячейкой (ниже/выше, чтобы влезло в root окно).
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::PositionPopupEditorBelowCell()
{
    if (!m_gridDisp || !m_hPopup || !m_hPopupEdit)
        return;

    long cellLeftTw = 0, cellTopTw = 0, cellWtw = 0, cellHtw = 0;
    if (!DispGetLong(m_gridDisp, L"CellLeft", cellLeftTw)) return;
    if (!DispGetLong(m_gridDisp, L"CellTop", cellTopTw))   return;
    if (!DispGetLong(m_gridDisp, L"CellWidth", cellWtw))   return;
    if (!DispGetLong(m_gridDisp, L"CellHeight", cellHtw))  return;

    int cellX = TwipsToPxX(cellLeftTw);
    int cellY = TwipsToPxY(cellTopTw);
    int cellW = max(40, TwipsToPxX(cellWtw));
    int cellH = max(18, TwipsToPxY(cellHtw));

    // Desired popup size:
    // - width: either configured width (px) or current cell width
    // - height: for multiline -> lineHeight * visibleLines; for singleline -> one line
    int pw = cellW;
    if (m_textEditWidthPx > 0)
        pw = (int)m_textEditWidthPx;
    pw = max(40, pw);

    const int gap = 2;

    int lineH = GetPopupEditLineHeightPx();
    bool isMultiline = m_popupEditCreatedMultiline;

    int visibleLines = 1;
    if (isMultiline)
        visibleLines = (m_textEditVisibleLines >= 1) ? (int)m_textEditVisibleLines : 1;

    int editH = 0;
    if (isMultiline)
        editH = lineH * visibleLines + 6;
    else
        editH = max(18, lineH + 6);

    int ph = editH + POPUP_PADDING_PX * 2;

    // Keep at least cell height (so it doesn't look smaller than the cell)
    ph = max(ph, cellH + POPUP_PADDING_PX * 2);

    int px = cellX;
    int py = cellY + cellH + gap;

    POINT pt{ px, py };
    ::ClientToScreen(m_hWnd, &pt);

    HWND hOwner = ::GetAncestor(m_hWnd, GA_ROOT);
    if (hOwner)
    {
        RECT rcOwner{};
        ::GetWindowRect(hOwner, &rcOwner);

        // horizontal clamp (keep within owner)
        if (pt.x + pw > rcOwner.right)
            pt.x = rcOwner.right - pw;
        if (pt.x < rcOwner.left)
            pt.x = rcOwner.left;

        // vertical clamp: if not enough space below -> show above
        if (pt.y + ph > rcOwner.bottom)
        {
            POINT ptAbove{ cellX, cellY - ph - gap };
            ::ClientToScreen(m_hWnd, &ptAbove);
            if (ptAbove.y >= rcOwner.top)
                pt.y = ptAbove.y;
        }
    }

    ::SetWindowPos(m_hPopup, HWND_TOP, pt.x, pt.y, pw, ph,
        SWP_NOACTIVATE | SWP_SHOWWINDOW);

    ::MoveWindow(m_hPopupEdit,
        POPUP_PADDING_PX,
        POPUP_PADDING_PX,
        max(10, pw - POPUP_PADDING_PX * 2),
        max(10, ph - POPUP_PADDING_PX * 2),
        TRUE);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::PopupWndProc
// MA_AUTODOC: WndProc popup окна: обслуживает создание/закрытие и маршрутизацию сообщений для Win32 EDIT.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CALLBACK CMAMSHFlexGridEx::PopupWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    if (msg == WM_NCCREATE)
    {
        CREATESTRUCTW* cs = (CREATESTRUCTW*)lp;
        if (cs && cs->lpCreateParams)
            ::SetWindowLongPtrW(hWnd, GWLP_USERDATA, (LONG_PTR)cs->lpCreateParams);
    }

    return ::DefWindowProcW(hWnd, msg, wp, lp);
}


// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::PopupEditSubclassProc
// MA_AUTODOC: SetWindowSubclass proc для Win32 EDIT: Enter/Esc/Ctrl+Enter, и focus-check для автокоммита/автокэнсела.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CALLBACK CMAMSHFlexGridEx::PopupEditSubclassProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,
    UINT_PTR, DWORD_PTR ref)
{
    auto* self = reinterpret_cast<CMAMSHFlexGridEx*>(ref);
    if (!self)
        return DefSubclassProc(hWnd, msg, wp, lp);

    switch (msg)
    {
    case WM_KEYDOWN:
        if (wp == VK_ESCAPE)
        {
            self->ClearNavPending();
            self->PostEndEdit(false);
            return 0;
        }

        if (wp == VK_RETURN)
        {
            if (::GetKeyState(VK_MENU) & 0x8000)
                break;

            // Multiline mode:
            //   Enter -> inserts newline (handled by EDIT because of ES_WANTRETURN)
            //   Ctrl+Enter -> commit edit
            if (self->m_popupEditCreatedMultiline)
            {
                if (::GetKeyState(VK_CONTROL) & 0x8000)
                {
                    self->ClearNavPending();
                    self->PostEndEdit(true);
                    return 0;
                }
                break; // let EDIT insert CRLF
            }

            // Single-line mode: Enter commits.
            self->ClearNavPending();
            self->PostEndEdit(true);
            return 0;
        }
        break;

    case WM_KILLFOCUS:
        if (!self->m_focusCheckArmed)
        {
            self->m_focusCheckArmed = true;
            ::SetTimer(self->m_hWnd, TIMER_FOCUSCHECK, 120, nullptr);
        }
        break;

    case WM_NCDESTROY:
        RemoveWindowSubclass(hWnd, PopupEditSubclassProc, SUBCLASS_ID_POPUPEDIT);
        if (self->m_hPopupEdit == hWnd)
            self->m_hPopupEdit = nullptr;
        break;
    }

    return DefSubclassProc(hWnd, msg, wp, lp);
}


// ---------------- dispatch helpers ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::DispGetLong
// MA_AUTODOC: Упрощённое чтение long-свойства через IDispatch.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::DispGetLong(IDispatch* disp, LPCWSTR name, long& out)
{
    if (!disp) return false;
    CComVariant v;
    HRESULT hr = CComDispatchDriver(disp).GetPropertyByName(name, &v);
    if (FAILED(hr)) return false;
    if (FAILED(v.ChangeType(VT_I4))) return false;
    out = v.lVal;
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::DispGetBstr
// MA_AUTODOC: Упрощённое чтение BSTR-свойства через IDispatch.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::DispGetBstr(IDispatch* disp, LPCWSTR name, CComBSTR& out)
{
    if (!disp) return false;
    CComVariant v;
    HRESULT hr = CComDispatchDriver(disp).GetPropertyByName(name, &v);
    if (FAILED(hr)) return false;
    if (FAILED(v.ChangeType(VT_BSTR))) return false;
    out = v.bstrVal;
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::DispPutLong
// MA_AUTODOC: Упрощённая запись long-свойства через IDispatch.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::DispPutLong(IDispatch* disp, LPCWSTR name, long v)
{
    if (!disp) return false;
    CComVariant cv(v);
    return SUCCEEDED(CComDispatchDriver(disp).PutPropertyByName(name, &cv));
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::DispPutBstr
// MA_AUTODOC: Упрощённая запись BSTR-свойства через IDispatch.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::DispPutBstr(IDispatch* disp, LPCWSTR name, const wchar_t* v)
{
    if (!disp) return false;
    CComVariant cv(v);
    return SUCCEEDED(CComDispatchDriver(disp).PutPropertyByName(name, &cv));
}

// ---------------- combo helpers ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboClear
// MA_AUTODOC: Очищает список элементов MSForms.ComboBox (Clear).
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::ComboClear()
{
    if (!m_comboDisp) return;
    CComDispatchDriver dd(m_comboDisp);
    dd.Invoke0(L"Clear");
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboAddItem
// MA_AUTODOC: Добавляет элемент в список MSForms.ComboBox (AddItem).
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::ComboAddItem(const wchar_t* text)
{
    if (!m_comboDisp) return;
    CComVariant v(text);
    CComDispatchDriver dd(m_comboDisp);
    dd.Invoke1(L"AddItem", &v);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboGetStyle
// MA_AUTODOC: Читает свойство Style у MSForms.ComboBox (dropdown/dropdownlist).
// MA_AUTODOC: -----------------------------------------------------------------------------
long CMAMSHFlexGridEx::ComboGetStyle()
{
    if (!m_comboDisp) return 0;
    CComVariant v;
    if (SUCCEEDED(CComDispatchDriver(m_comboDisp).GetPropertyByName(L"Style", &v)) && SUCCEEDED(v.ChangeType(VT_I4)))
        return v.lVal;
    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboSetStyle
// MA_AUTODOC: Записывает свойство Style у MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::ComboSetStyle(long style)
{
    if (!m_comboDisp) return;
    CComVariant v(style);
    CComDispatchDriver(m_comboDisp).PutPropertyByName(L"Style", &v);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboSetShowDropButtonWhen
// MA_AUTODOC: Настраивает показ кнопки drop-down (ShowDropButtonWhen) у MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::ComboSetShowDropButtonWhen(long showMode)
{
    if (!m_comboDisp) return;
    CComVariant v(showMode);
    CComDispatchDriver(m_comboDisp).PutPropertyByName(L"ShowDropButtonWhen", &v);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboIsDroppedDown
// MA_AUTODOC: Проверяет, открыт ли выпадающий список MSForms.ComboBox (DroppedDown).
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::ComboIsDroppedDown()
{
    if (!m_comboDisp) return false;
    CComVariant v;
    HRESULT hr = CComDispatchDriver(m_comboDisp).GetPropertyByName(L"DroppedDown", &v);
    if (FAILED(hr)) return false;
    if (SUCCEEDED(v.ChangeType(VT_BOOL)))
        return v.boolVal == VARIANT_TRUE;
    return false;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboCellWantsUpDownSelection
// MA_AUTODOC: Определяет, должна ли ячейка-комбо перехватывать Up/Down для выбора элемента списка.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::ComboCellWantsUpDownSelection() const
{
    CellConfig cfg;
    GetEffectiveConfig(m_editRow, m_editCol, cfg);

    bool hasList = (cfg.hasItems && !cfg.items.empty());
    if (!hasList)
        return false;

    return (cfg.type == maCellCombo || cfg.type == maCellList);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboStepSelection
// MA_AUTODOC: Сдвигает ListIndex MSForms.ComboBox на шаг step и синхронизирует Text.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::ComboStepSelection(int step)
{
    if (!m_comboDisp) return false;

    CComDispatchDriver dd(m_comboDisp);

    CComVariant vLC;
    if (FAILED(dd.GetPropertyByName(L"ListCount", &vLC)) || FAILED(vLC.ChangeType(VT_I4)))
        return false;
    long lc = vLC.lVal;
    if (lc <= 0)
        return false;

    CComVariant vLI;
    long li = -1;
    if (SUCCEEDED(dd.GetPropertyByName(L"ListIndex", &vLI)) && SUCCEEDED(vLI.ChangeType(VT_I4)))
        li = vLI.lVal;

    long newIndex = -1;

    if (li < 0)
    {
        newIndex = (step > 0) ? 0 : (lc - 1);
    }
    else
    {
        newIndex = li + step;
        if (newIndex < 0) newIndex = 0;
        if (newIndex > lc - 1) newIndex = lc - 1;
    }

    CComVariant putIdx(newIndex);
    HRESULT hrPut = dd.PutPropertyByName(L"ListIndex", &putIdx);
    if (FAILED(hrPut))
        return false;

    CComVariant tmp;
    dd.GetPropertyByName(L"Text", &tmp);

    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboSetSelection
// MA_AUTODOC: Устанавливает выделение текста (SelStart/SelLength) в MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::ComboSetSelection(long selStart, long selLen)
{
    if (!m_comboDisp) return;

    if (ComboGetStyle() == 2)
        return;

    CComDispatchDriver dd(m_comboDisp);

    {
        CComVariant v(selStart);
        dd.PutPropertyByName(L"SelStart", &v);
    }
    {
        CComVariant v(selLen);
        dd.PutPropertyByName(L"SelLength", &v);
    }
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboGetSelection
// MA_AUTODOC: Считывает текущие SelStart/SelLength в MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::ComboGetSelection(long& selStart, long& selLen)
{
    selStart = 0;
    selLen = 0;

    if (!m_comboDisp) return false;
    if (ComboGetStyle() == 2) return false;

    CComDispatchDriver dd(m_comboDisp);

    CComVariant vS, vL;
    if (FAILED(dd.GetPropertyByName(L"SelStart", &vS)) || FAILED(vS.ChangeType(VT_I4)))
        return false;
    if (FAILED(dd.GetPropertyByName(L"SelLength", &vL)) || FAILED(vL.ChangeType(VT_I4)))
        return false;

    selStart = vS.lVal;
    selLen = vL.lVal;
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ComboGetTextLen
// MA_AUTODOC: Возвращает длину текста текущего значения в MSForms.ComboBox.
// MA_AUTODOC: -----------------------------------------------------------------------------
long CMAMSHFlexGridEx::ComboGetTextLen()
{
    if (!m_comboDisp) return 0;
    if (ComboGetStyle() == 2) return 0;

    CComDispatchDriver dd(m_comboDisp);
    CComVariant v;
    if (FAILED(dd.GetPropertyByName(L"Text", &v)))
        return 0;
    if (FAILED(v.ChangeType(VT_BSTR)))
        return 0;

    return (long)SysStringLen(v.bstrVal ? v.bstrVal : L"");
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ShouldExitOnLeftRightKey
// MA_AUTODOC: Решает, следует ли выходить из редактирования по Left/Right (только если каретка на краю текста).
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::ShouldExitOnLeftRightKey(WPARAM vk)
{
    if (vk != VK_LEFT && vk != VK_RIGHT)
        return false;

    // Для DropDownList (Style=2) нет каретки — Left/Right это навигация всегда
    if (ComboGetStyle() == 2)
        return true;

    // Функционал "выхода по границам" ОТМЕНЁН:
    // Для Style=0 стрелки Left/Right никогда не должны завершать редактирование.
    return false;
}



// ---------------- caret helpers ----------------
// Самодельная каретка (CreateCaret/SetCaretPos) удалена.
// При редактировании ComboBox теперь используется штатная (системная) каретка самого контрола.

// ---------------- grid helpers ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::PutTextMatrix
// MA_AUTODOC: Записывает текст в TextMatrix(row,col) внутреннего грида.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::PutTextMatrix(long row, long col, const wchar_t* text)
{
    if (!m_gridDisp) return false;

    DISPID dispid{};
    OLECHAR* nm = const_cast<OLECHAR*>(L"TextMatrix");
    HRESULT hr = m_gridDisp->GetIDsOfNames(IID_NULL, &nm, 1, LOCALE_USER_DEFAULT, &dispid);
    if (FAILED(hr)) return false;

    CComVariant args[3];
    args[0] = CComVariant(text);
    args[1] = CComVariant(col);
    args[2] = CComVariant(row);

    DISPID dispidPut = DISPID_PROPERTYPUT;
    DISPPARAMS dp{};
    dp.rgvarg = args;
    dp.cArgs = 3;
    dp.rgdispidNamedArgs = &dispidPut;
    dp.cNamedArgs = 1;

    hr = m_gridDisp->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT,
        DISPATCH_PROPERTYPUT, &dp, nullptr, nullptr, nullptr);

    return SUCCEEDED(hr);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::TwipsToPxX
// MA_AUTODOC: Конвертирует twips → pixels по горизонтали (учёт DPI).
// MA_AUTODOC: -----------------------------------------------------------------------------
int CMAMSHFlexGridEx::TwipsToPxX(long tw)
{
    HDC hdc = ::GetDC(m_hWnd);
    int dpi = hdc ? ::GetDeviceCaps(hdc, LOGPIXELSX) : 96;
    if (hdc) ::ReleaseDC(m_hWnd, hdc);
    return (int)((double)tw * (double)dpi / 1440.0 + 0.5);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::TwipsToPxY
// MA_AUTODOC: Конвертирует twips → pixels по вертикали (учёт DPI).
// MA_AUTODOC: -----------------------------------------------------------------------------
int CMAMSHFlexGridEx::TwipsToPxY(long tw)
{
    HDC hdc = ::GetDC(m_hWnd);
    int dpi = hdc ? ::GetDeviceCaps(hdc, LOGPIXELSY) : 96;
    if (hdc) ::ReleaseDC(m_hWnd, hdc);
    return (int)((double)tw * (double)dpi / 1440.0 + 0.5);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::CanEditCurrentCell
// MA_AUTODOC: Проверяет, разрешено ли редактирование текущей ячейки (fixed rows/cols, read-only конфиг, валидность координат).
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::CanEditCurrentCell(long row, long col)
{
    long fr = 0, fc = 0;
    DispGetLong(m_gridDisp, L"FixedRows", fr);
    DispGetLong(m_gridDisp, L"FixedCols", fc);
    if (row < fr || col < fc)
        return false;

    CellConfig cfg;
    GetEffectiveConfig(row, col, cfg);
    if (cfg.type == maCellReadOnly)
        return false;

    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::PositionEditor
// MA_AUTODOC: Позиционирует оверлей ActiveX редактор (MAComboBoxEx) поверх активной ячейки.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::PositionEditor()
{
    if (!m_gridDisp || !m_axEdit) return;

    long cellLeftTw = 0, cellTopTw = 0, cellWtw = 0, cellHtw = 0;
    if (!DispGetLong(m_gridDisp, L"CellLeft", cellLeftTw)) return;
    if (!DispGetLong(m_gridDisp, L"CellTop", cellTopTw))   return;
    if (!DispGetLong(m_gridDisp, L"CellWidth", cellWtw))   return;
    if (!DispGetLong(m_gridDisp, L"CellHeight", cellHtw))  return;

    int x = TwipsToPxX(cellLeftTw);
    int y = TwipsToPxY(cellTopTw);
    int w = max(10, TwipsToPxX(cellWtw));
    int h = max(10, TwipsToPxY(cellHtw) + 6);

    m_axEdit.MoveWindow(x, y, w, h);
}

// ---------------- deferred begin/end ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::PostBeginEdit
// MA_AUTODOC: Постит сообщение WM_APP_BEGINEDIT для безопасного старта редактирования вне текущего стека сообщений.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::PostBeginEdit(int mode, wchar_t ch)
{
    if (m_beginPosted) return;
    m_pendingMode = mode;
    m_pendingChar = ch;
    m_beginPosted = true;
    ::PostMessageW(m_hWnd, WM_APP_BEGINEDIT, 0, 0);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::PostEndEdit
// MA_AUTODOC: Постит сообщение WM_APP_ENDEDIT для безопасного завершения редактирования (commit/cancel).
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::PostEndEdit(bool commit)
{
    if (m_endPosted) return;
    m_pendingCommit = commit;
    m_endPosted = true;
    ::PostMessageW(m_hWnd, WM_APP_ENDEDIT, 0, 0);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::PostFocusGrid
// MA_AUTODOC: Постит WM_APP_FOCUSGRID, чтобы вернуть фокус в грид после скрытия редактора (важно для стрелок).
// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: Важно: PostFocusGrid используется как 'костыль' от гонки фокуса.
// MA_AUTODOC: В VB6/ThunderForm после скрытия редактора фокус иногда уходит на форму,
// MA_AUTODOC: из-за чего стрелки больше не доходят до inner окна грида.
void CMAMSHFlexGridEx::PostFocusGrid()
{
    if (!m_hWnd)
        return;

    if (m_focusGridPosted)
        return;

    m_focusGridPosted = true;
    ::PostMessageW(m_hWnd, WM_APP_FOCUSGRID, 0, 0);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::FocusGridNow
// MA_AUTODOC: Непосредственно выставляет фокус в 'правильное' inner окно грида (или пытается найти его).
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::FocusGridNow()
{
    if (!m_hWnd)
        return;

    HWND hAxGrid = (HWND)m_axGrid;
    if (!hAxGrid)
        return;

#if MA_DIAG_FOCUS
    MA_DumpFocusSnapshot(L"FocusGridNow:enter", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
        m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
    MA_DumpGridChildren((HWND)m_axGrid, L"before HookGridInnerIfPossible");
#endif

    HookGridInnerIfPossible();

#if MA_DIAG_FOCUS
    MA_DumpGridChildren((HWND)m_axGrid, L"after HookGridInnerIfPossible");
#endif

    HWND prev = nullptr;

    if (m_hGridInner && ::IsWindow(m_hGridInner))
        prev = ::SetFocus(m_hGridInner);
    else
        prev = ::SetFocus(hAxGrid);

#if MA_DIAG_FOCUS
    MA_DbgOut(L"[FocusGridNow] SetFocus#1 prev=0x%p\n", prev);
    MA_DumpFocusSnapshot(L"FocusGridNow:after SetFocus#1", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
        m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
#endif

    HWND hFocus = ::GetFocus();
    if (hFocus && IsChildOrSelf(hAxGrid, hFocus))
        return;

    prev = ::SetFocus(hAxGrid);

#if MA_DIAG_FOCUS
    MA_DbgOut(L"[FocusGridNow] SetFocus#2(prev to AxGrid) prev=0x%p\n", prev);
    MA_DumpFocusSnapshot(L"FocusGridNow:after SetFocus#2", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
        m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
#endif

    hFocus = ::GetFocus();
    if (hFocus && IsChildOrSelf(hAxGrid, hFocus))
        return;

    HWND hDeep = FindDeepestChild(hAxGrid);
    if (hDeep)
        prev = ::SetFocus(hDeep);

#if MA_DIAG_FOCUS
    MA_DbgOut(L"[FocusGridNow] SetFocus#3(prev to deepest) prev=0x%p hDeep=0x%p\n", prev, hDeep);
    MA_DumpFocusSnapshot(L"FocusGridNow:after SetFocus#3", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
        m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
#endif
}


// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnAppFocusGrid
// MA_AUTODOC: Обработчик отложенного возврата фокуса в грид (WM_APP_FOCUSGRID).
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnAppFocusGrid(UINT, WPARAM, LPARAM, BOOL&)
{
#if MA_DIAG_FOCUS
    MA_DumpFocusSnapshot(L"OnAppFocusGrid:enter", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
        m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
#endif

    m_focusGridPosted = false;
    FocusGridNow();

#if MA_DIAG_FOCUS
    MA_DumpFocusSnapshot(L"OnAppFocusGrid:leave", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
        m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
#endif
    return 0;
}



// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnAppBeginEdit
// MA_AUTODOC: Обработчик отложенного старта редактирования (WM_APP_BEGINEDIT).
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnAppBeginEdit(UINT, WPARAM, LPARAM, BOOL&)
{
    m_beginPosted = false;
    BeginEdit(m_pendingMode, m_pendingChar);
    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnAppEndEdit
// MA_AUTODOC: Обработчик отложенного завершения редактирования (WM_APP_ENDEDIT).
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnAppEndEdit(UINT, WPARAM, LPARAM, BOOL&)
{
    m_endPosted = false;
    EndEdit(m_pendingCommit);
    return 0;
}

// ---------------- navigation helpers ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ClearNavPending
// MA_AUTODOC: Сбрасывает флаги/параметры отложенной навигации после выхода из редактирования.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::ClearNavPending()
{
    m_navPending = false;
    m_navDr = 0;
    m_navDc = 0;
    m_navFromTab = false;
    m_navShiftTab = false;
    m_navTabWrap = VARIANT_TRUE;
    m_navSkipReadOnly = VARIANT_TRUE;
    m_navBeginEditAfterMove = VARIANT_FALSE;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SetGridRowCol
// MA_AUTODOC: Устанавливает активные Row/Col грида через свойства, с защитой от ошибок.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::SetGridRowCol(long row, long col)
{
    if (!m_gridDisp) return false;
    bool ok1 = DispPutLong(m_gridDisp, L"Row", row);
    bool ok2 = DispPutLong(m_gridDisp, L"Col", col);
    return ok1 && ok2;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::MoveSelectionByArrow
// MA_AUTODOC: Перемещает выделение по стрелкам (dr/dc) с учётом skipReadOnly и границ.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::MoveSelectionByArrow(int dr, int dc, VARIANT_BOOL skipReadOnly)
{
    if (!m_gridDisp) return false;

    long rows = 0, cols = 0, fr = 0, fc = 0;
    if (!DispGetLong(m_gridDisp, L"Rows", rows)) return false;
    if (!DispGetLong(m_gridDisp, L"Cols", cols)) return false;
    DispGetLong(m_gridDisp, L"FixedRows", fr);
    DispGetLong(m_gridDisp, L"FixedCols", fc);

    long minRow = fr;
    long minCol = fc;
    long maxRow = rows - 1;
    long maxCol = cols - 1;

    long rr = m_editRow + dr;
    long cc = m_editCol + dc;

    if (rr < minRow) rr = minRow;
    if (rr > maxRow) rr = maxRow;
    if (cc < minCol) cc = minCol;
    if (cc > maxCol) cc = maxCol;

    if (skipReadOnly == VARIANT_TRUE)
    {
        for (int i = 0; i < (rows * cols); ++i)
        {
            if (rr < minRow || rr > maxRow || cc < minCol || cc > maxCol)
                break;

            if (CanEditCurrentCell(rr, cc))
                return SetGridRowCol(rr, cc);

            rr += dr;
            cc += dc;
        }
        return SetGridRowCol(rr, cc);
    }

    return SetGridRowCol(rr, cc);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::MoveSelectionByTab
// MA_AUTODOC: Перемещает выделение по Tab/Shift+Tab с учётом wrap и skipReadOnly.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::MoveSelectionByTab(bool shiftTab, VARIANT_BOOL wrap, VARIANT_BOOL skipReadOnly)
{
    if (!m_gridDisp) return false;

    long rows = 0, cols = 0, fr = 0, fc = 0;
    if (!DispGetLong(m_gridDisp, L"Rows", rows)) return false;
    if (!DispGetLong(m_gridDisp, L"Cols", cols)) return false;
    DispGetLong(m_gridDisp, L"FixedRows", fr);
    DispGetLong(m_gridDisp, L"FixedCols", fc);

    long minRow = fr;
    long minCol = fc;
    long maxRow = rows - 1;
    long maxCol = cols - 1;

    long rr = m_editRow;
    long cc = m_editCol;

    int step = shiftTab ? -1 : +1;

    for (int iter = 0; iter < (rows * cols); ++iter)
    {
        cc += step;

        if (cc > maxCol)
        {
            if (wrap == VARIANT_TRUE)
            {
                cc = minCol;
                rr += 1;
            }
            else
            {
                cc = maxCol;
            }
        }
        else if (cc < minCol)
        {
            if (wrap == VARIANT_TRUE)
            {
                cc = maxCol;
                rr -= 1;
            }
            else
            {
                cc = minCol;
            }
        }

        if (rr > maxRow) { rr = maxRow; cc = maxCol; break; }
        if (rr < minRow) { rr = minRow; cc = minCol; break; }

        if (skipReadOnly == VARIANT_FALSE)
            return SetGridRowCol(rr, cc);

        if (CanEditCurrentCell(rr, cc))
            return SetGridRowCol(rr, cc);
    }

    return SetGridRowCol(rr, cc);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ApplyNavAfterEdit
// MA_AUTODOC: Применяет отложенную навигацию (Tab/стрелки) после EndEdit.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::ApplyNavAfterEdit()
{
    if (!m_navPending)
        return;

    if (m_navFromTab)
        MoveSelectionByTab(m_navShiftTab, m_navTabWrap, m_navSkipReadOnly);
    else
        MoveSelectionByArrow(m_navDr, m_navDc, m_navSkipReadOnly);

    if (m_navBeginEditAfterMove == VARIANT_TRUE)
        PostBeginEdit(13, 0);

    ClearNavPending();
}

// ---------------- handle exit keys early in TranslateAccelerator ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::TryHandleEditExitKeyInTranslateAccelerator
// MA_AUTODOC: Ранний перехват exit-клавиш во время редактирования (Tab/стрелки/Enter) до обработки MSForms.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::TryHandleEditExitKeyInTranslateAccelerator(LPMSG lpmsg)
{
    if (!lpmsg) return false;
    if (!m_inEdit) return false;

    // При редактировании через popup Win32 EDIT ничего не перехватываем: пусть работает штатная логика EDIT.
    if (m_usingPopupEditor)
        return false;

    if (lpmsg->message != WM_KEYDOWN && lpmsg->message != WM_SYSKEYDOWN)
        return false;

    WPARAM wp = lpmsg->wParam;
    if (wp != VK_TAB && wp != VK_LEFT && wp != VK_RIGHT && wp != VK_UP && wp != VK_DOWN)
        return false;

    if (!IsFocusWithinEditorWindow())
        return false;

bool shift = (::GetKeyState(VK_SHIFT) & 0x8000) != 0;
    bool ctrl = (::GetKeyState(VK_CONTROL) & 0x8000) != 0;
    bool alt = (::GetKeyState(VK_MENU) & 0x8000) != 0;

    // combo/list cell: Up/Down should change selection (если не раскрыт)
    if ((wp == VK_UP || wp == VK_DOWN) && ComboCellWantsUpDownSelection())
    {
        if (ComboIsDroppedDown())
            return false;

        int step = (wp == VK_DOWN) ? +1 : -1;
        if (ComboStepSelection(step))
            return true;

        return false;
    }

    // Left/Right:
    // - Style=0: ТОЛЬКО движение курсора, без выхода из редактирования (переход по ячейкам отменён)
    // - Style=2: каретки нет, можно оставить как навигацию (провалится вниз)
    if (wp == VK_LEFT || wp == VK_RIGHT)
    {
        if (ComboGetStyle() != 2)
        {
            // С модификаторами не вмешиваемся (Ctrl+Left и т.п.), но навигацию по ячейкам не запускаем:
            // просто отдаём контролу.
            if (shift || ctrl || alt)
                return false;

            long selStart = 0, selLen = 0;
            if (!ComboGetSelection(selStart, selLen))
                return false;

            long textLen = ComboGetTextLen();

            // ---- НОРМАЛИЗАЦИЯ (КЛЮЧЕВОЕ ИСПРАВЛЕНИЕ) ----
            if (selStart < 0) selStart = 0;
            if (selStart > textLen) selStart = textLen;
            if (selLen < 0) selLen = 0;
            if (selStart + selLen > textLen)
               selLen = (textLen >= selStart) ? (textLen - selStart) : 0;
            // ---------------------------------------------

            // Если есть выделение — схлопнуть выделение как обычно
            if (selLen != 0)
            {
                long newPos = (wp == VK_LEFT) ? selStart : (selStart + selLen);

                if (newPos < 0) newPos = 0;
                if (newPos > textLen) newPos = textLen;

                ComboSetSelection(newPos, 0);
                return true;
            }

            // Выделения нет — двигаем на 1 символ, но НЕ выходим за границы
            if (wp == VK_LEFT)
            {
                if (selStart > 0) selStart -= 1;
                else selStart = 0;
            }
            else // VK_RIGHT
            {
                if (selStart < textLen) selStart += 1;
                else selStart = textLen;
            }

            ComboSetSelection(selStart, 0);
            return true; // НЕ даём ниже уйти в навигацию по ячейкам
        }

        // Style=2: проваливаемся вниз в навигацию (если включена)
    }

    NavConfig nav;
    GetEffectiveNavConfig(m_editRow, m_editCol, nav);

    LONG bit = 0;
    if (wp == VK_TAB) bit = shift ? maNavExitShiftTab : maNavExitTab;
    else if (wp == VK_LEFT) bit = maNavExitLeft;
    else if (wp == VK_RIGHT) bit = maNavExitRight;
    else if (wp == VK_UP) bit = maNavExitUp;
    else if (wp == VK_DOWN) bit = maNavExitDown;

    // если раскрыт dropdown — стрелки не должны выкидывать из редактирования
    if ((wp == VK_LEFT || wp == VK_RIGHT || wp == VK_UP || wp == VK_DOWN) && ComboIsDroppedDown())
        return false;

    if ((nav.exitKeysMask & bit) == 0)
        return false;

    m_navPending = true;
    m_navTabWrap = nav.tabWrap;
    m_navSkipReadOnly = nav.skipReadOnly;
    m_navBeginEditAfterMove = nav.beginEditAfterMove;

    if (wp == VK_TAB)
    {
        m_navFromTab = true;
        m_navShiftTab = shift;
        m_navDr = 0;
        m_navDc = 0;
    }
    else
    {
        m_navFromTab = false;
        m_navShiftTab = false;
        m_navDr = 0;
        m_navDc = 0;
        if (wp == VK_LEFT) m_navDc = -1;
        else if (wp == VK_RIGHT) m_navDc = +1;
        else if (wp == VK_UP) m_navDr = -1;
        else if (wp == VK_DOWN) m_navDr = +1;
    }

    PostEndEdit(true);
    return true;
}




// ---------------- IOleInPlaceActiveObject (keyboard routing) ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::TranslateAccelerator
// MA_AUTODOC: Маршрутизирует клавиатурные сообщения между гридом и редактором и перехватывает 'выходные' клавиши до того, как их съест MSForms.
// MA_AUTODOC: -----------------------------------------------------------------------------
STDMETHODIMP CMAMSHFlexGridEx::TranslateAccelerator(LPMSG lpmsg)
{
    if (!lpmsg) return E_POINTER;

#if MA_DIAG_FOCUS
    if (lpmsg->message == WM_KEYDOWN || lpmsg->message == WM_SYSKEYDOWN)
    {
        WPARAM vk = lpmsg->wParam;
        if (vk == VK_LEFT || vk == VK_RIGHT || vk == VK_UP || vk == VK_DOWN || vk == VK_RETURN || vk == VK_TAB)
        {
            HWND hf = GetFocus();
            wchar_t s[256];
            MA_DescribeHwnd(hf, s, _countof(s));
            MA_DbgOut(L"[TA] msg=0x%04X vk=0x%02X inEdit=%d focus=%s\n",
                (unsigned)lpmsg->message, (unsigned)vk, m_inEdit ? 1 : 0, s);
        }
    }
#endif

    if (m_inEdit && m_usingPopupEditor)
        return S_FALSE;

    if (TryHandleEditExitKeyInTranslateAccelerator(lpmsg))
        return S_OK;

    HWND hFocus = ::GetFocus();

    if (m_inEdit && m_editAO)
    {
        HWND hAxEdit = (HWND)m_axEdit;
        if (IsChildOrSelf(hAxEdit, hFocus) || IsChildOrSelf(m_hEditInner, hFocus))
        {
#if MA_DIAG_FOCUS
            MA_DbgOut(L"[TA] route -> EDIT AO\n");
#endif
            HRESULT hr = m_editAO->TranslateAccelerator(lpmsg);
            if (hr == S_OK)
                return S_OK;
        }
    }

    if (m_gridAO)
    {
        HWND hAxGrid = (HWND)m_axGrid;
        if (IsChildOrSelf(hAxGrid, hFocus) || IsChildOrSelf(m_hGridInner, hFocus))
        {
#if MA_DIAG_FOCUS
            MA_DbgOut(L"[TA] route -> GRID AO\n");
#endif
            HRESULT hr = m_gridAO->TranslateAccelerator(lpmsg);
            if (hr == S_OK)
                return S_OK;
        }
#if MA_DIAG_FOCUS
        else
        {
            wchar_t s[256];
            MA_DescribeHwnd(hFocus, s, _countof(s));
            MA_DbgOut(L"[TA] NOT routed to GRID (focus not inside). focus=%s\n", s);
        }
#endif
    }

    return IOleInPlaceActiveObjectImpl<CMAMSHFlexGridEx>::TranslateAccelerator(lpmsg);
}


// ---------------- window lifecycle ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnCreate
// MA_AUTODOC: WM_CREATE: создаёт хост-окна для грида и редактора, создаёт внутренний MSHFlexGrid и запускает таймер установки subclass.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnCreate(UINT, WPARAM, LPARAM, BOOL&)
{
    m_ok = true;
    m_hrGrid = S_OK;
    m_hrEditor = S_OK;

    AtlAxWinInit();

    RECT rc{};
    GetClientRect(&rc);

    if (!m_axGrid.Create(m_hWnd, rc, nullptr, WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN))
    {
        m_ok = false;
        m_hrGrid = HRESULT_FROM_WIN32(GetLastError());
        Invalidate();
        return 0;
    }

    if (!CreateGrid())
    {
        m_ok = false;
        ::ShowWindow(m_axGrid, SW_HIDE);
        Invalidate();
        return 0;
    }

    ::ShowWindow(m_axGrid, SW_SHOW);

    if (!m_axEdit.Create(m_hWnd, rc, nullptr, WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN))
    {
        m_hrEditor = HRESULT_FROM_WIN32(GetLastError());
    }
    ::ShowWindow(m_axEdit, SW_HIDE);

    Layout();

    // MA_AUTODOC: В runtime-режиме (не дизайнер) запускаем таймер, который будет искать 'inner' HWND
    // MA_AUTODOC: внутри ActiveX и ставить SetWindowSubclass для перехвата клавиатуры.
    if (IsUserMode())
        StartHookTimer();

    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::CreateGrid
// MA_AUTODOC: Создаёт внутренний ActiveX MSHFlexGrid и первично настраивает его (Rows/Cols/Editable и тестовые значения).
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::CreateGrid()
{
    m_gridDisp.Release();
    m_gridAO.Release();

    CComPtr<IUnknown> unk;
    HRESULT hr = CreateAxControlWithLicFallback(PROGID_MSHFLEXGRID, m_axGrid, &unk);
    m_hrGrid = hr;

    if (FAILED(hr) || !unk)
        return false;

    unk->QueryInterface(&m_gridDisp);
    if (!m_gridDisp)
        return false;

    unk->QueryInterface(&m_gridAO);

    // MA_AUTODOC: Встроенное редактирование MSHFlexGrid выключаем.
    // MA_AUTODOC: Дальше редактирование будет происходить только через наши внешние редакторы.
    DispPutLong(m_gridDisp, L"Editable", 0);

    DispPutLong(m_gridDisp, L"Rows", 6);
    DispPutLong(m_gridDisp, L"Cols", 4);

    PutTextMatrix(0, 0, L"r\\c");
    PutTextMatrix(0, 1, L"A");
    PutTextMatrix(0, 2, L"B");
    PutTextMatrix(0, 3, L"C");
    for (long r = 1; r < 6; ++r)
    {
        wchar_t buf[64];
        wsprintfW(buf, L"row %ld", r);
        PutTextMatrix(r, 0, buf);
        PutTextMatrix(r, 1, L"test");
        PutTextMatrix(r, 2, L"123");
        PutTextMatrix(r, 3, L"ok");
    }

    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::StartHookTimer
// MA_AUTODOC: Запускает таймер, который ищет inner HWND и ставит SetWindowSubclass.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::StartHookTimer()
{
    if (m_hWnd)
        ::SetTimer(m_hWnd, TIMER_HOOK, 50, nullptr);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::StopHookTimer
// MA_AUTODOC: Останавливает таймер установки subclass (когда уже всё успешно захвачено).
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::StopHookTimer()
{
    if (m_hWnd)
        ::KillTimer(m_hWnd, TIMER_HOOK);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnTimer
// MA_AUTODOC: WM_TIMER: периодически пытается найти inner HWND грида/редактора и поставить subclass; также обслуживает focus-check.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnTimer(UINT, WPARAM wp, LPARAM, BOOL&)
{
    // MA_AUTODOC: TIMER_HOOK — пытаемся подцепиться к самым глубоким окнам (inner HWND) грида/редактора.
    // MA_AUTODOC: Это нужно, потому что ActiveX создают вложенные окна асинхронно.
    if (wp == TIMER_HOOK)
    {
        bool ok1 = HookGridInnerIfPossible();
        bool ok2 = true;
        if (m_editorDisp) ok2 = HookEditInnerIfPossible();

        if (ok1 && ok2)
            StopHookTimer();

        return 0;
    }

    if (wp == TIMER_FOCUSCHECK)
    {
        ::KillTimer(m_hWnd, TIMER_FOCUSCHECK);
        m_focusCheckArmed = false;

        if (!m_inEdit)
            return 0;

        if (!IsFocusWithinEditorWindow())
            PostEndEdit(true);

        return 0;
    }

    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::HookGridInnerIfPossible
// MA_AUTODOC: Находит 'глубокое' окно внутри MSHFlexGrid и ставит subclass для перехвата клавиатуры/мыши.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::HookGridInnerIfPossible()
{
    HWND hAxGrid = (HWND)m_axGrid;
    if (!hAxGrid)
        return false;

    // If the grid recreated its window, the previous handle may be invalid.
    if (m_gridSubclassed && (!m_hGridInner || !::IsWindow(m_hGridInner)))
    {
        m_gridSubclassed = false;
        m_hGridInner = nullptr;
    }

    // MSHFlexGrid often uses a nested child window for keyboard/focus.
    // We want to subclass the window that actually receives WM_KEYDOWN/WM_CHAR.
    HWND hBest = FindDeepestChild(hAxGrid);
    if (!hBest)
        hBest = ::GetWindow(hAxGrid, GW_CHILD);

    if (!hBest)
        return false;

    // Already subclassed on the correct window.
    if (m_gridSubclassed && m_hGridInner == hBest)
        return true;

    // If we had a different inner window subclassed earlier, remove the subclass.
    if (m_gridSubclassed && m_hGridInner && ::IsWindow(m_hGridInner))
        RemoveWindowSubclass(m_hGridInner, GridSubclassProc, SUBCLASS_ID_GRID);

    m_hGridInner = hBest;

    if (!SetWindowSubclass(m_hGridInner, GridSubclassProc, SUBCLASS_ID_GRID, (DWORD_PTR)this))
    {
        m_hGridInner = nullptr;
        m_gridSubclassed = false;
        return false;
    }

    m_gridSubclassed = true;
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::HookEditInnerIfPossible
// MA_AUTODOC: Находит 'глубокое' окно внутри редактора (MAComboBoxEx/MSForms) и ставит subclass для перехвата клавиатуры.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::HookEditInnerIfPossible()
{
    if (m_editSubclassed) return true;
    if (!m_axEdit) return false;

    HWND hRoot = (HWND)m_axEdit;
    HWND hDeep = FindDeepestChild(hRoot);
    if (!hDeep)
    {
        hDeep = ::GetWindow(m_axEdit, GW_CHILD);
        if (!hDeep)
            return false;
    }

    m_hEditInner = hDeep;

    if (!SetWindowSubclass(m_hEditInner, EditSubclassProc, SUBCLASS_ID_EDIT, (DWORD_PTR)this))
        return false;

    m_editSubclassed = true;
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnSize
// MA_AUTODOC: WM_SIZE: переразмещает внутренние окна (грид/редактор) по размеру контрола.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnSize(UINT, WPARAM, LPARAM, BOOL&)
{
    Layout();
    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnSetFocus
// MA_AUTODOC: WM_SETFOCUS: возвращает фокус внутрь грида (или редактора, если редактирование активно).
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnSetFocus(UINT, WPARAM, LPARAM, BOOL&)
{
    if (m_inEdit)
    {
        if (m_usingPopupEditor && m_hPopupEdit)
            ::SetFocus(m_hPopupEdit);
        else if (m_hEditInner)
            ::SetFocus(m_hEditInner);
        else if (m_axEdit)
            ::SetFocus(m_axEdit);

        return 0;
    }

    // Important: in some containers focus may jump to the form (ThunderFormDC),
    // so we restore focus to the *real* inner grid window.
    FocusGridNow();
    return 0;
}


// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnMouseWheel
// MA_AUTODOC: WM_MOUSEWHEEL на окне контрола: направляет прокрутку в грид (учёт high-resolution колес).
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnMouseWheel(UINT, WPARAM wp, LPARAM lp, BOOL& bHandled)
{
    // Во время редактирования колесо мыши должно вести себя штатно (например, прокрутка формы контейнера).
    if (!m_inEdit && HandleMouseWheel(wp, lp, false))
    {
        bHandled = TRUE;
        return 0;
    }

    bHandled = FALSE;
    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::HandleMouseWheel
// MA_AUTODOC: Общая обработка колеса мыши: определяет направление/аккумулирует дельты и прокручивает грид.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::HandleMouseWheel(WPARAM wp, LPARAM lp, bool fromGridSubclass)
{
    if (m_inEdit)
        return false;

    if (!m_gridDisp)
        return false;

    // Координаты в WM_MOUSEWHEEL — экранные.
    POINT pt{ GET_X_LPARAM(lp), GET_Y_LPARAM(lp) };

    // Если сообщение пришло не от подкласса окна грида — проверим, что колесо крутят именно над гридом.
    // Это позволяет не "ломать" прокрутку формы/контейнера, когда курсор находится вне грида.
    if (!fromGridSubclass)
    {
        if (!IsPointOverHwnd((HWND)m_axGrid, pt))
            return false;

        // Если активен popup-редактор и курсор над ним — колесо относится к редактору/форме, не к гриду.
        if (m_usingPopupEditor && m_hPopup && ::IsWindowVisible(m_hPopup))
        {
            if (IsPointOverHwnd(m_hPopup, pt))
                return false;
        }
    }

    const short delta = (short)GET_WHEEL_DELTA_WPARAM(wp);
    const UINT keyState = GET_KEYSTATE_WPARAM(wp);

    return ScrollGridByWheel(delta, keyState);
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::ScrollGridByWheel
// MA_AUTODOC: Преобразует wheelDelta в количество строк/колонок и вызывает TryScrollTopRow/TryScrollLeftCol.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::ScrollGridByWheel(short wheelDelta, UINT keyState)
{
    if (wheelDelta == 0)
        return true;

    // На всякий случай поддержим пересоздание внутренних окон грида.
    HookGridInnerIfPossible();

    // Shift+Wheel часто используется как горизонтальная прокрутка.
    const bool horizontal = (keyState & MK_SHIFT) != 0;

    int& acc = horizontal ? m_wheelAccH : m_wheelAccV;
    acc += (int)wheelDelta;

    const int detents = acc / WHEEL_DELTA;
    acc -= detents * WHEEL_DELTA;

    if (detents == 0)
        return true;

    UINT lines = 3;
    if (!SystemParametersInfoW(SPI_GETWHEELSCROLLLINES, 0, &lines, 0) || lines == 0)
        lines = 3;

    // Режим "по страницам" — используем стандартные WM_VSCROLL/WM_HSCROLL команды.
    if (lines == WHEEL_PAGESCROLL)
    {
        const int count = abs(detents);
        if (!horizontal)
            return SendGridScroll(WM_VSCROLL, detents > 0 ? SB_PAGEUP : SB_PAGEDOWN, count);
        else
            return SendGridScroll(WM_HSCROLL, detents > 0 ? SB_PAGELEFT : SB_PAGERIGHT, count);
    }

    const int steps = detents * (int)lines;
    const int count = abs(steps);
    if (count == 0)
        return true;

    if (!horizontal)
    {
        // Wheel up => контент "вверх" => TopRow уменьшается.
        if (TryScrollTopRow(-steps))
            return true;

        return SendGridScroll(WM_VSCROLL, steps > 0 ? SB_LINEUP : SB_LINEDOWN, count);
    }
    else
    {
        if (TryScrollLeftCol(-steps))
            return true;

        return SendGridScroll(WM_HSCROLL, steps > 0 ? SB_LINELEFT : SB_LINERIGHT, count);
    }
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::TryScrollTopRow
// MA_AUTODOC: Пытается прокрутить грид по вертикали через свойство TopRow/WM_VSCROLL.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::TryScrollTopRow(int deltaRows)
{
    if (deltaRows == 0)
        return true;

    if (!m_gridDisp)
        return false;

    long top = 0;
    if (!DispGetLong(m_gridDisp, L"TopRow", top))
        return false;

    long rows = 0;
    if (!DispGetLong(m_gridDisp, L"Rows", rows))
        return false;

    long fixed = 0;
    DispGetLong(m_gridDisp, L"FixedRows", fixed);

    long minTop = fixed;
    long maxTop = rows - 1;
    if (maxTop < minTop)
        maxTop = minTop;

    long nt = top + (long)deltaRows;
    if (nt < minTop) nt = minTop;
    if (nt > maxTop) nt = maxTop;

    DispPutLong(m_gridDisp, L"TopRow", nt);
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::TryScrollLeftCol
// MA_AUTODOC: Пытается прокрутить грид по горизонтали через LeftCol/WM_HSCROLL.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::TryScrollLeftCol(int deltaCols)
{
    if (deltaCols == 0)
        return true;

    if (!m_gridDisp)
        return false;

    long left = 0;
    if (!DispGetLong(m_gridDisp, L"LeftCol", left))
        return false;

    long cols = 0;
    if (!DispGetLong(m_gridDisp, L"Cols", cols))
        return false;

    long fixed = 0;
    DispGetLong(m_gridDisp, L"FixedCols", fixed);

    long minLeft = fixed;
    long maxLeft = cols - 1;
    if (maxLeft < minLeft)
        maxLeft = minLeft;

    long nl = left + (long)deltaCols;
    if (nl < minLeft) nl = minLeft;
    if (nl > maxLeft) nl = maxLeft;

    DispPutLong(m_gridDisp, L"LeftCol", nl);
    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::SendGridScroll
// MA_AUTODOC: Посылает гриду сообщение прокрутки (WM_VSCROLL/WM_HSCROLL) с нужной командой.
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::SendGridScroll(UINT scrollMsg, int scrollCmd, int count)
{
    if (count <= 0)
        return true;

    HWND hTarget = m_hGridInner;
    if (!hTarget || !::IsWindow(hTarget))
        hTarget = (HWND)m_axGrid;

    if (!hTarget || !::IsWindow(hTarget))
        return false;

    for (int i = 0; i < count; ++i)
        ::SendMessageW(hTarget, scrollMsg, MAKEWPARAM(scrollCmd, 0), 0);

    return true;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::IsPointOverHwnd
// MA_AUTODOC: Проверяет, находится ли экранная точка над указанным HWND (для роутинга колеса).
// MA_AUTODOC: -----------------------------------------------------------------------------
bool CMAMSHFlexGridEx::IsPointOverHwnd(HWND h, POINT ptScreen) const
{
    if (!h || !::IsWindow(h))
        return false;

    RECT rc{};
    if (!::GetWindowRect(h, &rc))
        return false;

    return ::PtInRect(&rc, ptScreen) != 0;
}


// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnDestroy
// MA_AUTODOC: WM_DESTROY: снимает таймеры/сабклассы и уничтожает popup редактор, если он создан.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CMAMSHFlexGridEx::OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
{
    StopHookTimer();
    ::KillTimer(m_hWnd, TIMER_FOCUSCHECK);
    m_focusCheckArmed = false;

    // Самодельная каретка удалена; ничего освобождать не нужно.

    if (m_gridSubclassed && m_hGridInner)
        RemoveWindowSubclass(m_hGridInner, GridSubclassProc, SUBCLASS_ID_GRID);
    if (m_editSubclassed && m_hEditInner)
        RemoveWindowSubclass(m_hEditInner, EditSubclassProc, SUBCLASS_ID_EDIT);

    if (m_hPopupEdit)
        RemoveWindowSubclass(m_hPopupEdit, PopupEditSubclassProc, SUBCLASS_ID_POPUPEDIT);

    if (m_hPopup)
    {
        ::DestroyWindow(m_hPopup);
        m_hPopup = nullptr;
        m_hPopupEdit = nullptr;
    }

    m_usingPopupEditor = false;

    m_gridSubclassed = false;
    m_editSubclassed = false;

    m_hGridInner = nullptr;
    m_hEditInner = nullptr;

    m_gridAO.Release();
    m_editAO.Release();

    m_gridDisp.Release();
    m_comboDisp.Release();
    m_editorDisp.Release();

    return 0;
}

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::Layout
// MA_AUTODOC: Рассчитывает и применяет геометрию внутренних окон (m_axGrid/m_axEdit) по клиентской области контрола.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::Layout()
{
    RECT rc{};
    GetClientRect(&rc);

    if (m_axGrid)
        m_axGrid.MoveWindow(&rc);

    if (m_inEdit)
    {
        if (m_usingPopupEditor)
            PositionPopupEditorBelowCell();
        else
            PositionEditor();
    }
}

// ---------------- edit flow ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::BeginEdit
// MA_AUTODOC: Начинает редактирование активной ячейки: выбирает редактор (popup EDIT или combo), заполняет текст/items и ставит фокус.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::BeginEdit(int startMode, wchar_t firstChar)
{
    if (!m_gridDisp) return;

    long row = 0, col = 0;
    DispGetLong(m_gridDisp, L"Row", row);
    DispGetLong(m_gridDisp, L"Col", col);

    if (!CanEditCurrentCell(row, col))
        return;

    m_editRow = row;
    m_editCol = col;

    CellConfig cfg;
    GetEffectiveConfig(row, col, cfg);

    const bool hasList = (cfg.hasItems && !cfg.items.empty());

    // --------------------------------------------------------------------
    // ТЕКСТОВОЕ РЕДАКТИРОВАНИЕ: показываем popup окно ЧУТЬ НИЖЕ ячейки.
    // --------------------------------------------------------------------
    if (cfg.type == maCellText || !hasList)
    {
        const bool wantMultiline = (m_textEditMultiline == VARIANT_TRUE);
        if (!EnsurePopupEditorCreated(wantMultiline))
            return;

        // For multiline text in cells, the grid should be able to wrap CRLF.
        // We only try to enable it if the property exists on the underlying grid.
        if (wantMultiline)
            DispPutLong(m_gridDisp, L"WordWrap", -1);

        m_usingPopupEditor = true;
        m_inEdit = true;

        ::KillTimer(m_hWnd, TIMER_FOCUSCHECK);
        m_focusCheckArmed = false;

        ClearNavPending();

        // Hide ActiveX editor if it was created earlier
        if (m_axEdit)
            ::ShowWindow(m_axEdit, SW_HIDE);

        // Fill initial text
        CComBSTR cur;
        if (startMode == 13 && DispGetBstr(m_gridDisp, L"Text", cur))
            ::SetWindowTextW(m_hPopupEdit, cur.m_str ? cur.m_str : L"");
        else
            ::SetWindowTextW(m_hPopupEdit, L"");

        // Place caret like in standard in-cell editing: F2/Enter -> end, typing -> start (empty)
        int len = ::GetWindowTextLengthW(m_hPopupEdit);
        int caretPos = (startMode == 13) ? len : 0;
        ::SendMessageW(m_hPopupEdit, EM_SETSEL, caretPos, caretPos);

        PositionPopupEditorBelowCell();

        ::ShowWindow(m_hPopup, SW_SHOW);
        ::BringWindowToTop(m_hPopup);
        ::SetFocus(m_hPopupEdit);

        // If editing started from WM_CHAR, inject the first character into the EDIT
        if (startMode == 0 && firstChar >= 32)
            ::PostMessageW(m_hPopupEdit, WM_CHAR, (WPARAM)firstChar, 1);

        return;
    }

    // ---------------- COMBO/LIST MODE (ActiveX editor) ----------------
    if (!EnsureEditorCreated())
        return;

    m_usingPopupEditor = false;

    if (m_hPopup)
        ::ShowWindow(m_hPopup, SW_HIDE);

    ComboClear();

    if (cfg.type == maCellCombo)
    {
        for (const auto& it : cfg.items)
            ComboAddItem(it.m_str ? it.m_str : L"");

        if (m_comboDisp)
        {
            ComboSetStyle(0);
            ComboSetShowDropButtonWhen(2);
        }
    }
    else if (cfg.type == maCellList)
    {
        for (const auto& it : cfg.items)
            ComboAddItem(it.m_str ? it.m_str : L"");

        if (m_comboDisp)
        {
            ComboSetStyle(2);
            ComboSetShowDropButtonWhen(2);
        }
    }

    long caretPos = 0;

    if (startMode == 13)
    {
        CComBSTR cur;
        if (DispGetBstr(m_gridDisp, L"Text", cur))
        {
            DispPutBstr(m_editorDisp, L"Text", cur.m_str ? cur.m_str : L"");
            caretPos = (long)SysStringLen(cur.m_str ? cur.m_str : L"");
        }
        else
        {
            DispPutBstr(m_editorDisp, L"Text", L"");
            caretPos = 0;
        }
    }
    else
    {
        DispPutBstr(m_editorDisp, L"Text", L"");
        caretPos = 0;
    }

    m_inEdit = true;

    ::KillTimer(m_hWnd, TIMER_FOCUSCHECK);
    m_focusCheckArmed = false;

    ClearNavPending();

    PositionEditor();

    ::ShowWindow(m_axEdit, SW_SHOW);
    ::BringWindowToTop(m_axEdit);

    if (m_hEditInner) ::SetFocus(m_hEditInner);
    else ::SetFocus(m_axEdit);

    ComboSetSelection(caretPos, 0);

    // Если редактирование началось с WM_CHAR — "впрыснем" символ
    if (startMode == 0 && firstChar >= 32)
    {
        HWND hFocus = ::GetFocus();
        if (hFocus) ::PostMessageW(hFocus, WM_CHAR, (WPARAM)firstChar, 1);
    }

    // Каретку рисует сам MSForms.ComboBox (штатная системная каретка).
}


// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::EndEdit
// MA_AUTODOC: Завершает редактирование: при commit записывает текст в ячейку, скрывает редактор, выполняет отложенную навигацию и восстанавливает фокус.
// MA_AUTODOC: -----------------------------------------------------------------------------
void CMAMSHFlexGridEx::EndEdit(bool commit)
{
    if (!m_inEdit) return;
    if (m_endEditGuard) return;

    m_endEditGuard = true;

#if MA_DIAG_FOCUS
    MA_DumpFocusSnapshot(L"EndEdit:enter", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
        m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
#endif

    ::KillTimer(m_hWnd, TIMER_FOCUSCHECK);
    m_focusCheckArmed = false;

    if (m_usingPopupEditor)
    {
        if (commit && m_hPopupEdit)
        {
            int len = ::GetWindowTextLengthW(m_hPopupEdit);
            std::vector<wchar_t> buf((size_t)len + 1, L'\0');
            ::GetWindowTextW(m_hPopupEdit, buf.data(), (int)buf.size());
            PutTextMatrix(m_editRow, m_editCol, buf.data());
        }

        if (m_hPopup)
            ::ShowWindow(m_hPopup, SW_HIDE);

        m_usingPopupEditor = false;
        m_inEdit = false;

        ApplyNavAfterEdit();

#if MA_DIAG_FOCUS
        MA_DumpFocusSnapshot(L"EndEdit:popup(after hide)", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
            m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
#endif

        PostFocusGrid();

        m_endEditGuard = false;
        return;
    }

    if (commit)
    {
        CComBSTR txt;
        bool ok = false;

        if (m_comboDisp)
        {
            ok = DispGetBstr(m_comboDisp, L"Value", txt);
            if (!ok)
                ok = DispGetBstr(m_comboDisp, L"Text", txt);
        }

        if (!ok && m_editorDisp)
            ok = DispGetBstr(m_editorDisp, L"Text", txt);

        if (ok)
            PutTextMatrix(m_editRow, m_editCol, txt.m_str ? txt.m_str : L"");
    }

    // Самодельная каретка удалена; ничего освобождать не нужно.

    ::ShowWindow(m_axEdit, SW_HIDE);
    m_inEdit = false;

    ApplyNavAfterEdit();

#if MA_DIAG_FOCUS
    MA_DumpFocusSnapshot(L"EndEdit:ActiveX(after hide + nav)", m_hWnd, (HWND)m_axGrid, m_hGridInner, (HWND)m_axEdit, m_hEditInner,
        m_inEdit, m_usingPopupEditor, m_hPopup, m_hPopupEdit);
#endif

    PostFocusGrid();

    m_endEditGuard = false;
}



// ---------------- Subclass procs ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::GridSubclassProc
// MA_AUTODOC: SetWindowSubclass proc для inner HWND грида: старт редактирования и фолбэк-обработка стрелок/колеса.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CALLBACK CMAMSHFlexGridEx::GridSubclassProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,
    UINT_PTR, DWORD_PTR ref)
{
    auto* self = reinterpret_cast<CMAMSHFlexGridEx*>(ref);
    if (!self)
        return DefSubclassProc(hWnd, msg, wp, lp);

    switch (msg)
    {
    case WM_GETDLGCODE:
    {
        // Просим у контейнера не "забирать" стрелки/символы на диалоговую навигацию.
        LRESULT lr = DefSubclassProc(hWnd, msg, wp, lp);
        return lr | DLGC_WANTARROWS | DLGC_WANTCHARS;
    }

    case WM_MOUSEWHEEL:
    {
        // Прокрутка колесом мыши: у MSHFlexGrid это не всегда работает из коробки,
        // поэтому делаем прокрутку сами через свойства TopRow/LeftCol либо через WM_VSCROLL/WM_HSCROLL.
        if (self->HandleMouseWheel(wp, lp, true))
            return 0;
        break;
    }

    case WM_KEYDOWN:
    {
        if (wp == VK_RETURN || wp == VK_F2)
        {
            self->PostBeginEdit(13, 0);
            return 0;
        }

        const bool isArrow =
            (wp == VK_LEFT || wp == VK_RIGHT || wp == VK_UP || wp == VK_DOWN);

        // Дадим гриду шанс обработать стрелки штатно
        long r0 = 0, c0 = 0;
        bool gotBefore = false;

        if (!self->m_inEdit && isArrow && self->m_gridDisp)
        {
            gotBefore =
                self->DispGetLong(self->m_gridDisp, L"Row", r0) &&
                self->DispGetLong(self->m_gridDisp, L"Col", c0);
        }

        LRESULT lr = DefSubclassProc(hWnd, msg, wp, lp);

        // Если грид сам не двигает Row/Col после редактирования — двигаем вручную.
        // Важно: не вмешиваемся при Shift/Ctrl (могут быть режимы расширенного выделения).
        if (!self->m_inEdit && isArrow && gotBefore && self->m_gridDisp)
        {
            if ((GetKeyState(VK_SHIFT) & 0x8000) || (GetKeyState(VK_CONTROL) & 0x8000))
                return lr;

            long r1 = r0, c1 = c0;
            bool gotAfter =
                self->DispGetLong(self->m_gridDisp, L"Row", r1) &&
                self->DispGetLong(self->m_gridDisp, L"Col", c1);

            if (gotAfter && r1 == r0 && c1 == c0)
            {
                long rows = 0, cols = 0, fr = 0, fc = 0;
                if (self->DispGetLong(self->m_gridDisp, L"Rows", rows) &&
                    self->DispGetLong(self->m_gridDisp, L"Cols", cols))
                {
                    self->DispGetLong(self->m_gridDisp, L"FixedRows", fr);
                    self->DispGetLong(self->m_gridDisp, L"FixedCols", fc);

                    int dr = 0, dc = 0;
                    if (wp == VK_UP) dr = -1;
                    else if (wp == VK_DOWN) dr = +1;
                    else if (wp == VK_LEFT) dc = -1;
                    else if (wp == VK_RIGHT) dc = +1;

                    long minRow = fr;
                    long minCol = fc;
                    long maxRow = rows - 1;
                    long maxCol = cols - 1;

                    long nr = r0 + dr;
                    long nc = c0 + dc;

                    if (nr < minRow) nr = minRow;
                    if (nr > maxRow) nr = maxRow;
                    if (nc < minCol) nc = minCol;
                    if (nc > maxCol) nc = maxCol;

                    if (nr != r0 || nc != c0)
                    {
                        self->DispPutLong(self->m_gridDisp, L"Row", nr);
                        self->DispPutLong(self->m_gridDisp, L"Col", nc);
                    }
                }
            }
        }

        return lr;
    }

    case WM_CHAR:
        if (wp >= 32)
        {
            self->PostBeginEdit(0, (wchar_t)wp);
            return 0;
        }
        if (wp == VK_RETURN)
        {
            self->PostBeginEdit(13, 0);
            return 0;
        }
        break;

    case WM_LBUTTONDBLCLK:
        self->PostBeginEdit(13, 0);
        return 0;

    case WM_NCDESTROY:
        RemoveWindowSubclass(hWnd, GridSubclassProc, SUBCLASS_ID_GRID);
        self->m_gridSubclassed = false;
        self->m_hGridInner = nullptr;
        break;
    }

    return DefSubclassProc(hWnd, msg, wp, lp);
}




// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::EditSubclassProc
// MA_AUTODOC: SetWindowSubclass proc для inner HWND редактора: commit/cancel и обработка Up/Down для списка.
// MA_AUTODOC: -----------------------------------------------------------------------------
LRESULT CALLBACK CMAMSHFlexGridEx::EditSubclassProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp,
    UINT_PTR, DWORD_PTR ref)
{
    auto* self = reinterpret_cast<CMAMSHFlexGridEx*>(ref);
    if (!self)
        return DefSubclassProc(hWnd, msg, wp, lp);

    switch (msg)
    {
    case WM_SETFOCUS:
    {
        return DefSubclassProc(hWnd, msg, wp, lp);
    }

    case WM_KEYDOWN:
    {
        if (wp == VK_ESCAPE)
        {
            self->ClearNavPending();
            self->PostEndEdit(false);
            return 0;
        }

        if (wp == VK_RETURN)
        {
            if (::GetKeyState(VK_MENU) & 0x8000)
                break;

            self->ClearNavPending();
            self->PostEndEdit(true);
            return 0;
        }


        // VK_UP / VK_DOWN: выбор элементов в ComboBox стрелками, даже если список не раскрыт.
        // Это поведение нужно именно для combobox/list-ячейки (cfg.type=maCellCombo/maCellList).
        if (wp == VK_UP || wp == VK_DOWN)
        {
            // Если выпадающий список раскрыт — не вмешиваемся, пусть контрол работает штатно.
            if (!self->ComboIsDroppedDown() && self->ComboCellWantsUpDownSelection())
            {
                const bool shift = (::GetKeyState(VK_SHIFT) & 0x8000) != 0;
                const bool ctrl  = (::GetKeyState(VK_CONTROL) & 0x8000) != 0;
                const bool alt   = (::GetKeyState(VK_MENU) & 0x8000) != 0;

                // С модификаторами не перехватываем (на всякий случай, чтобы не ломать нестандартные комбинации).
                if (!shift && !ctrl && !alt)
                {
                    const int step = (wp == VK_DOWN) ? +1 : -1;
                    if (self->ComboStepSelection(step))
                        return 0;
                }
            }
        }

        break;
    }

    case WM_KEYUP:
    case WM_CHAR:
    case WM_LBUTTONUP:
    {
        // Дадим контролу обновить SelStart/SelLength. Каретку рисует сам контрол.
        return DefSubclassProc(hWnd, msg, wp, lp);
    }

    case WM_KILLFOCUS:
    {
        if (!self->m_focusCheckArmed)
        {
            self->m_focusCheckArmed = true;
            ::SetTimer(self->m_hWnd, TIMER_FOCUSCHECK, 120, nullptr);
        }
        break;
    }

    case WM_NCDESTROY:
        RemoveWindowSubclass(hWnd, EditSubclassProc, SUBCLASS_ID_EDIT);
        self->m_editSubclassed = false;
        self->m_hEditInner = nullptr;
        break;
    }

    return DefSubclassProc(hWnd, msg, wp, lp);
}

// ---------------- placeholder drawing ----------------

// MA_AUTODOC: -----------------------------------------------------------------------------
// MA_AUTODOC: CMAMSHFlexGridEx::OnDraw
// MA_AUTODOC: Отрисовка фона контрола (когда внутренний грид не создан/ошибка) — fallback рисование.
// MA_AUTODOC: -----------------------------------------------------------------------------
HRESULT CMAMSHFlexGridEx::OnDraw(ATL_DRAWINFO& di)
{
    RECT rc = { di.prcBounds->left, di.prcBounds->top, di.prcBounds->right, di.prcBounds->bottom };

    HBRUSH bg = (HBRUSH)::GetStockObject(WHITE_BRUSH);
    ::FillRect(di.hdcDraw, &rc, bg);
    ::Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

    if (m_ok)
        return S_OK;

    ::SetBkMode(di.hdcDraw, TRANSPARENT);

    CStringW msg;
    msg.Format(L"MAMSHFlexGridEx: grid failed to create.\r\nhr=0x%08X\r\n\r\n"
        L"Check: OCX registered (32-bit) + license availability.",
        (unsigned)m_hrGrid);

    RECT tr = rc;
    tr.left += 8; tr.top += 8; tr.right -= 8; tr.bottom -= 8;

    ::DrawTextW(di.hdcDraw, msg, msg.GetLength(), &tr, DT_LEFT | DT_TOP | DT_WORDBREAK);
    return S_OK;
}
