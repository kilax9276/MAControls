// MA_AUTODOC: ============================================================================
// Copyright Kolobov Aleksei @kilax9276
// MA_AUTODOC: MAMSHFlexGridEx.h
// MA_AUTODOC: Объявление ActiveX-контрола CMAMSHFlexGridEx (MAMSHFlexGridEx).
// MA_AUTODOC: Контрол хостит внутри себя оригинальный MSHFlexGrid и предоставляет COM-методы для:
// MA_AUTODOC:   - настройки типов ячеек (text/combo/list/read-only) и их списков items,
// MA_AUTODOC:   - настройки навигации при выходе из редактирования (Tab/стрелки и т.п.),
// MA_AUTODOC:   - отображения popup текстового редактора вместо встроенного редактирования MSHFlexGrid.
// MA_AUTODOC: ============================================================================

#pragma once
#include "resource.h"
#include <atlctl.h>
#include <atlhost.h>
#include <atlstr.h>
#include <commctrl.h>
#include <map>
#include <vector>

#include "MAControls_i.h"
#include "_IMAMSHFlexGridExEvents_CP.h"
#include "AxHostHelpers.h"

using namespace ATL;

class ATL_NO_VTABLE CMAMSHFlexGridEx :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CMAMSHFlexGridEx, &CLSID_MAMSHFlexGridEx>,
    public CComControl<CMAMSHFlexGridEx>,
    public CStockPropImpl<CMAMSHFlexGridEx, IMAMSHFlexGridEx>,
    public IPersistStreamInitImpl<CMAMSHFlexGridEx>,
    public IOleControlImpl<CMAMSHFlexGridEx>,
    public IOleObjectImpl<CMAMSHFlexGridEx>,
    public IOleInPlaceActiveObjectImpl<CMAMSHFlexGridEx>,
    public IViewObjectExImpl<CMAMSHFlexGridEx>,
    public IOleInPlaceObjectWindowlessImpl<CMAMSHFlexGridEx>,
    public IConnectionPointContainerImpl<CMAMSHFlexGridEx>,
    public CProxy_IMAMSHFlexGridExEvents<CMAMSHFlexGridEx>,
    public IQuickActivateImpl<CMAMSHFlexGridEx>,
    public IProvideClassInfo2Impl<&CLSID_MAMSHFlexGridEx, &__uuidof(_IMAMSHFlexGridExEvents), &LIBID_MAControlsLib>,
    public IObjectSafetyImpl<CMAMSHFlexGridEx, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
    CMAMSHFlexGridEx();

    DECLARE_OLEMISC_STATUS(
        OLEMISC_RECOMPOSEONRESIZE |
        OLEMISC_CANTLINKINSIDE |
        OLEMISC_INSIDEOUT |
        OLEMISC_ACTIVATEWHENVISIBLE |
        OLEMISC_SETCLIENTSITEFIRST
    )

    DECLARE_REGISTRY_RESOURCEID(IDR_MAMSHFLEXGRIDEX)
    DECLARE_NOT_AGGREGATABLE(CMAMSHFlexGridEx)

    BEGIN_COM_MAP(CMAMSHFlexGridEx)
        COM_INTERFACE_ENTRY(IMAMSHFlexGridEx)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IViewObjectEx)
        COM_INTERFACE_ENTRY(IViewObject2)
        COM_INTERFACE_ENTRY(IViewObject)
        COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
        COM_INTERFACE_ENTRY(IOleInPlaceObject)
        COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
        COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
        COM_INTERFACE_ENTRY(IOleControl)
        COM_INTERFACE_ENTRY(IOleObject)
        COM_INTERFACE_ENTRY(IPersistStreamInit)
        COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
        COM_INTERFACE_ENTRY(IConnectionPointContainer)
        COM_INTERFACE_ENTRY(IQuickActivate)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
        COM_INTERFACE_ENTRY(IProvideClassInfo2)
        COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
    END_COM_MAP()

    BEGIN_PROP_MAP(CMAMSHFlexGridEx)
        PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
        PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
#ifndef _WIN32_WCE
        PROP_ENTRY_TYPE("BackColor", DISPID_BACKCOLOR, CLSID_StockColorPage, VT_UI4)
#endif
        PROP_ENTRY_TYPE("BorderStyle", DISPID_BORDERSTYLE, CLSID_NULL, VT_I4)
        PROP_ENTRY_TYPE("Enabled", DISPID_ENABLED, CLSID_NULL, VT_BOOL)
#ifndef _WIN32_WCE
        PROP_ENTRY_TYPE("Font", DISPID_FONT, CLSID_StockFontPage, VT_DISPATCH)
#endif
#ifndef _WIN32_WCE
        PROP_ENTRY_TYPE("ForeColor", DISPID_FORECOLOR, CLSID_StockColorPage, VT_UI4)
#endif
        PROP_ENTRY_TYPE("TabStop", DISPID_TABSTOP, CLSID_NULL, VT_BOOL)
    END_PROP_MAP()

    BEGIN_CONNECTION_POINT_MAP(CMAMSHFlexGridEx)
        CONNECTION_POINT_ENTRY(__uuidof(_IMAMSHFlexGridExEvents))
    END_CONNECTION_POINT_MAP()

    BEGIN_MSG_MAP(CMAMSHFlexGridEx)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
        MESSAGE_HANDLER(WM_MOUSEWHEEL, OnMouseWheel)
        MESSAGE_HANDLER(WM_TIMER, OnTimer)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_APP + 101, OnAppBeginEdit)
        MESSAGE_HANDLER(WM_APP + 102, OnAppEndEdit)
        MESSAGE_HANDLER(WM_APP + 103, OnAppFocusGrid)
        CHAIN_MSG_MAP(CComControl<CMAMSHFlexGridEx>)
        DEFAULT_REFLECTION_HANDLER()
    END_MSG_MAP()

    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

    // MA_AUTODOC: ---- Состояние и диагностика ----
    // MA_AUTODOC: m_ok/m_hrGrid/m_hrEditor используются, чтобы в случае ошибки создания ActiveX
    // MA_AUTODOC: корректно отрисовать fallback и иметь понятный HRESULT для диагностики.
    // ---- state ----
    bool m_ok = true;
    HRESULT m_hrGrid = S_OK;
    HRESULT m_hrEditor = S_OK;

    // MA_AUTODOC: ---- Окна-хосты ActiveX ----
    // MA_AUTODOC: m_axGrid  - контейнер для MSHFlexGrid.
    // MA_AUTODOC: m_axEdit  - контейнер для MAComboBoxEx (оверлей-редактор для combo/list ячеек).
    // Hosts
    CAxWindow m_axGrid;
    CAxWindow m_axEdit;

    // MA_AUTODOC: ---- IDispatch указатели на внутренние COM-объекты ----
    // MA_AUTODOC: m_gridDisp   - IDispatch MSHFlexGrid.
    // MA_AUTODOC: m_editorDisp - IDispatch MAComboBoxEx (внешняя оболочка редактора).
    // MA_AUTODOC: m_comboDisp  - IDispatch MSForms.ComboBox (внутренний реальный комбобокс).
    // Inner dispatch
    CComPtr<IDispatch> m_gridDisp;
    CComPtr<IDispatch> m_editorDisp;   // MAComboBoxEx as IDispatch (outer)
    CComPtr<IDispatch> m_comboDisp;    // MSForms.ComboBox (inner)

    // MA_AUTODOC: ---- ActiveObject интерфейсы ----
    // MA_AUTODOC: Эти интерфейсы используются в TranslateAccelerator для корректной маршрутизации клавиатуры.
    // Active objects (for keyboard routing)
    CComPtr<IOleInPlaceActiveObject> m_gridAO;
    CComPtr<IOleInPlaceActiveObject> m_editAO;

    // MA_AUTODOC: ---- Внутренние HWND (deep child) ----
    // MA_AUTODOC: Чтобы перехватывать WM_KEYDOWN/WM_CHAR и т.п., нужно ставить subclass не на CAxWindow,
    // MA_AUTODOC: а на 'самое глубокое' дочернее окно, которое реально получает ввод.
    // Inner HWND handles
    HWND m_hGridInner = nullptr;
    HWND m_hEditInner = nullptr; // deepest input hwnd for editor

    // MA_AUTODOC: ---- Флаги установки SetWindowSubclass ----
    // Subclass installed flags
    bool m_gridSubclassed = false;
    bool m_editSubclassed = false;

    // MA_AUTODOC: ---- Состояние редактирования ----
    // MA_AUTODOC: m_inEdit показывает, открыт ли сейчас внешний редактор.
    // MA_AUTODOC: m_editRow/m_editCol — координаты ячейки, которую редактируем.
    // edit state
    bool m_inEdit = false;
    bool m_endEditGuard = false;
    long m_editRow = 0;
    long m_editCol = 0;

    // MA_AUTODOC: ---- Отложенные операции ----
    // MA_AUTODOC: В некоторых контейнерах (VB6/ThunderForm) безопаснее начинать/заканчивать редактирование
    // MA_AUTODOC: через PostMessage (WM_APP_*), чтобы избежать гонок фокуса и re-entrancy.
    // deferred begin/end
    bool    m_beginPosted = false;
    int     m_pendingMode = 0;      // 13 / 0
    wchar_t m_pendingChar = 0;

    bool    m_endPosted = false;
    bool    m_pendingCommit = true;

    // deferred focus restore (fix: arrows stop after edit)
    bool m_focusGridPosted = false;

    // focus-end timer state (dropdown / inner windows)
    bool m_focusCheckArmed = false;


    // wheel accumulation (high-resolution wheels send partial deltas)
    int m_wheelAccV = 0;
    int m_wheelAccH = 0;

    // AllowUserResizing mode requested by the host (0..3). Applied to the underlying MSHFlexGrid.
    LONG m_allowUserResizing = 0;



    // MA_AUTODOC: ---- Popup текстовый редактор (Win32 EDIT) ----
    // MA_AUTODOC: Используется для maCellText. Окно создаётся как WS_POPUP и позиционируется рядом с ячейкой.
    // popup text editor (native Win32 EDIT, shown below the active cell)
    HWND m_hPopup = nullptr;
    HWND m_hPopupEdit = nullptr;
    bool m_usingPopupEditor = false;


// Popup editor settings (for maCellText editing)
LONG m_textEditWidthPx = 0;              // 0 => use cell width
LONG m_textEditVisibleLines = 1;         // >=1 (used when multiline)
VARIANT_BOOL m_textEditMultiline = VARIANT_FALSE;

// Current popup EDIT style (we may recreate the EDIT when switching singleline/multiline)
bool m_popupEditCreatedMultiline = false;


    // ---- Level-B navigation pending info (leave edit by arrows/tab) ----
    bool m_navPending = false;
    int  m_navDr = 0;
    int  m_navDc = 0;
    bool m_navFromTab = false;
    bool m_navShiftTab = false;
    VARIANT_BOOL m_navTabWrap = VARIANT_TRUE;
    VARIANT_BOOL m_navSkipReadOnly = VARIANT_TRUE;
    VARIANT_BOOL m_navBeginEditAfterMove = VARIANT_FALSE;

    enum : UINT_PTR { TIMER_HOOK = 1, TIMER_FOCUSCHECK = 2 };
    enum : UINT { WM_APP_BEGINEDIT = WM_APP + 101, WM_APP_ENDEDIT = WM_APP + 102, WM_APP_FOCUSGRID = WM_APP + 103 };

    // ---- cell configuration (defaults / per-column / per-cell) ----
    struct CellConfig
    {
        MACellEditorType type = maCellText;
        std::vector<CComBSTR> items;
        bool hasItems = false;
    };

    CellConfig m_defaultCfg;
    std::map<long, CellConfig> m_colCfg;                // col -> cfg
    std::map<unsigned long long, CellConfig> m_cellCfg; // (row,col) -> cfg

    // ---- Level-B navigation configuration (defaults / per-column / per-row / per-cell) ----
    struct NavConfig
    {
        LONG exitKeysMask = 0; // MANavExitKeys mask
        VARIANT_BOOL tabWrap = VARIANT_TRUE;
        VARIANT_BOOL skipReadOnly = VARIANT_TRUE;
        VARIANT_BOOL beginEditAfterMove = VARIANT_FALSE;
    };

    NavConfig m_defaultNav;
    std::map<long, NavConfig> m_colNav;                 // col -> nav
    std::map<long, NavConfig> m_rowNav;                 // row -> nav
    std::map<unsigned long long, NavConfig> m_cellNav;  // (row,col) -> nav

    static unsigned long long MakeKey(long row, long col)
    {
        return (static_cast<unsigned long long>(static_cast<unsigned long>(row)) << 32) |
            static_cast<unsigned long long>(static_cast<unsigned long>(col));
    }

    bool GetEffectiveConfig(long row, long col, CellConfig& out) const;
    bool GetEffectiveNavConfig(long row, long col, NavConfig& out) const;

    // ---- IDispatch API additions (see MAControls.idl) ----
    // MA_AUTODOC: Возвращает IDispatch внутреннего MSHFlexGrid (прямой доступ к свойствам/методам оригинального грида).
    STDMETHOD(get_Grid)(IDispatch** ppGrid);


// ---- Headers helpers (row/column titles) ----
STDMETHOD(SetColumnHeaderText)(LONG col, BSTR text);
STDMETHOD(SetRowHeaderText)(LONG row, BSTR text);
STDMETHOD(SetCornerHeaderText)(BSTR text);

// ---- Popup text editor settings (for maCellText editing) ----
// TextEditWidthPx: 0 = use current cell width.
// TextEditVisibleLines: for multiline editor, how many lines are visible at once (>=1).
// TextEditMultiline: True => multiline Win32 EDIT (Enter inserts newline, Ctrl+Enter commits).
STDMETHOD(put_TextEditWidthPx)(LONG px);
STDMETHOD(get_TextEditWidthPx)(LONG* ppx);

STDMETHOD(put_TextEditVisibleLines)(LONG lines);
STDMETHOD(get_TextEditVisibleLines)(LONG* plines);

STDMETHOD(put_TextEditMultiline)(VARIANT_BOOL vbool);
STDMETHOD(get_TextEditMultiline)(VARIANT_BOOL* pvbool);


    // Allow mouse resizing of columns/rows using the built-in MSHFlexGrid functionality.
    // mode: 0=flexResizeNone, 1=flexResizeColumns, 2=flexResizeRows, 3=flexResizeBoth
    STDMETHOD(put_AllowUserResizing)(LONG mode)
    {
        if (mode < 0 || mode > 3)
            return E_INVALIDARG;

        m_allowUserResizing = mode;
        if (m_gridDisp)
            DispPutLong(m_gridDisp, L"AllowUserResizing", mode);
        return S_OK;
    }

    STDMETHOD(get_AllowUserResizing)(LONG* pMode)
    {
        if (!pMode)
            return E_POINTER;

        *pMode = m_allowUserResizing;
        return S_OK;
    }


    STDMETHOD(SetCellType)(LONG row, LONG col, MACellEditorType cellType);
    STDMETHOD(GetCellType)(LONG row, LONG col, MACellEditorType* pCellType);
    STDMETHOD(SetCellItems)(LONG row, LONG col, VARIANT items);
    STDMETHOD(ClearCellItems)(LONG row, LONG col);
    STDMETHOD(ClearCellConfig)(LONG row, LONG col);

    STDMETHOD(SetColumnType)(LONG col, MACellEditorType cellType);
    STDMETHOD(SetColumnItems)(LONG col, VARIANT items);
    STDMETHOD(ClearColumnConfig)(LONG col);

    STDMETHOD(SetDefaultCellType)(MACellEditorType cellType);
    STDMETHOD(SetDefaultCellItems)(VARIANT items);
    STDMETHOD(ClearDefaultCellItems)();

    // ---- Level-B navigation COM API ----
    STDMETHOD(SetDefaultNavOptions)(LONG exitKeysMask, VARIANT_BOOL tabWrap, VARIANT_BOOL skipReadOnly, VARIANT_BOOL beginEditAfterMove);
    STDMETHOD(SetColumnNavOptions)(LONG col, LONG exitKeysMask, VARIANT_BOOL tabWrap, VARIANT_BOOL skipReadOnly, VARIANT_BOOL beginEditAfterMove);
    STDMETHOD(SetRowNavOptions)(LONG row, LONG exitKeysMask, VARIANT_BOOL tabWrap, VARIANT_BOOL skipReadOnly, VARIANT_BOOL beginEditAfterMove);
    STDMETHOD(SetCellNavOptions)(LONG row, LONG col, LONG exitKeysMask, VARIANT_BOOL tabWrap, VARIANT_BOOL skipReadOnly, VARIANT_BOOL beginEditAfterMove);
    STDMETHOD(ClearColumnNavOptions)(LONG col);
    STDMETHOD(ClearRowNavOptions)(LONG row);
    STDMETHOD(ClearCellNavOptions)(LONG row, LONG col);

    // ---- IOleInPlaceActiveObject override ----
    // MA_AUTODOC: Ключевой метод для клавиатуры: маршрутизирует сообщения между гридом и редактором и перехватывает exit-клавиши.
    STDMETHOD(TranslateAccelerator)(LPMSG lpmsg);

    // ---- msg handlers ----
    LRESULT OnCreate(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnSize(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnSetFocus(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnMouseWheel(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnTimer(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnAppBeginEdit(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnAppEndEdit(UINT, WPARAM, LPARAM, BOOL&);

        LRESULT OnAppFocusGrid(UINT, WPARAM, LPARAM, BOOL&);
// ---- logic ----
    void Layout();
    bool IsUserMode();

    bool CreateGrid();
    void StartHookTimer();
    void StopHookTimer();
    bool HookGridInnerIfPossible();
    bool HookEditInnerIfPossible();


    // mouse wheel scrolling support
    bool HandleMouseWheel(WPARAM wp, LPARAM lp, bool fromGridSubclass);
    bool ScrollGridByWheel(short wheelDelta, UINT keyState);
    bool TryScrollTopRow(int deltaRows);
    bool TryScrollLeftCol(int deltaCols);
    bool SendGridScroll(UINT scrollMsg, int scrollCmd, int count);
    bool IsPointOverHwnd(HWND h, POINT ptScreen) const;

    void PostBeginEdit(int mode, wchar_t ch);
    void PostEndEdit(bool commit);

    // After EndEdit: restore focus to the grid in a posted message.
    // This fixes a timing race in some containers (VB6/ThunderForm) where focus jumps back
    // to the form after hiding the editor, and arrow keys stop moving the grid selection.
    void PostFocusGrid();
    void FocusGridNow();

    // MA_AUTODOC: Открывает внешний редактор для текущей ячейки и переводит фокус внутрь редактора.
    void BeginEdit(int startMode, wchar_t firstChar);
    // MA_AUTODOC: Закрывает редактор. При commit записывает текст в ячейку и применяет отложенную навигацию.
    void EndEdit(bool commit);
    void PositionEditor();

    // ---- navigation helpers ----
    void ClearNavPending();
    void ApplyNavAfterEdit(); // called after EndEdit commit
    bool MoveSelectionByTab(bool shiftTab, VARIANT_BOOL wrap, VARIANT_BOOL skipReadOnly);
    bool MoveSelectionByArrow(int dr, int dc, VARIANT_BOOL skipReadOnly);
    bool ComboIsDroppedDown();
    bool SetGridRowCol(long row, long col);

    // handle exit keys early (before MSForms eats them)
    bool TryHandleEditExitKeyInTranslateAccelerator(LPMSG lpmsg);

    // if cell is combo/list with items -> Up/Down should control selection
    bool ComboCellWantsUpDownSelection() const;

    // manual selection step for MSForms ComboBox
    bool ComboStepSelection(int step);

    // selection helpers
    void ComboSetSelection(long selStart, long selLen);
    bool ComboGetSelection(long& selStart, long& selLen);
    long ComboGetTextLen();
    bool ShouldExitOnLeftRightKey(WPARAM vk);

    // helpers
    bool EnsureEditorCreated();


    // popup editor (native Win32 EDIT, shown below the active cell)
    bool EnsurePopupEditorCreated(bool wantMultiline);
    int  GetPopupEditLineHeightPx() const;
    void PositionPopupEditorBelowCell();

    bool DispGetLong(IDispatch* disp, LPCWSTR name, long& out);
    bool DispGetBstr(IDispatch* disp, LPCWSTR name, CComBSTR& out);
    bool DispPutLong(IDispatch* disp, LPCWSTR name, long v);
    bool DispPutBstr(IDispatch* disp, LPCWSTR name, const wchar_t* v);

    bool PutTextMatrix(long row, long col, const wchar_t* text);
    int  TwipsToPxX(long tw);
    int  TwipsToPxY(long tw);

    void ComboClear();
    void ComboAddItem(const wchar_t* text);
    long ComboGetStyle();
    void ComboSetStyle(long style);
    void ComboSetShowDropButtonWhen(long showMode);

    bool CanEditCurrentCell(long row, long col);

    // SetWindowSubclass procs
    // MA_AUTODOC: Subclass inner окна грида: старт редактирования, навигация и прокрутка.
    static LRESULT CALLBACK GridSubclassProc(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR);
    // MA_AUTODOC: Subclass inner окна редактора: commit/cancel и спец. обработка клавиш (Up/Down для списка).
    static LRESULT CALLBACK EditSubclassProc(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR);


    // popup window / edit procs (native Win32 EDIT editor)
    static LRESULT CALLBACK PopupWndProc(HWND, UINT, WPARAM, LPARAM);
    // MA_AUTODOC: Subclass Win32 EDIT в popup редакторе: Enter/Esc/Ctrl+Enter и защита от потери фокуса.
    static LRESULT CALLBACK PopupEditSubclassProc(HWND, UINT, WPARAM, LPARAM, UINT_PTR, DWORD_PTR);

    // draw fallback
    HRESULT OnDraw(ATL_DRAWINFO& di);

private:
    // MA_AUTODOC: Проверка принадлежности окна: h == parent или h является дочерним окном parent.
    static bool IsChildOrSelf(HWND parent, HWND h)
    {
        if (!parent || !h) return false;
        if (parent == h) return true;
        return ::IsChild(parent, h) ? true : false;
    }

    // MA_AUTODOC: Находит наиболее 'глубокое' дочернее окно, проходя по цепочке GW_CHILD.
    // MA_AUTODOC: Важно для ActiveX: именно deep-child обычно получает реальный ввод с клавиатуры.
    static HWND FindDeepestChild(HWND root)
    {
        if (!root) return nullptr;
        HWND cur = root;
        for (int i = 0; i < 16; ++i)
        {
            HWND ch = ::GetWindow(cur, GW_CHILD);
            if (!ch) break;
            cur = ch;
        }
        return (cur != root) ? cur : nullptr;
    }

    // MA_AUTODOC: Проверяет, находится ли текущий фокус внутри редактора (ActiveX или popup).
    // MA_AUTODOC: Это нужно, чтобы не завершать редактирование, когда фокус временно уходит в dropdown/IME окно.
    bool IsFocusWithinEditorWindow() const
    {
        HWND hFocus = ::GetFocus();
        if (!hFocus)
            return false;

        // Popup editor mode (native Win32 EDIT below the active cell)
        if (m_usingPopupEditor)
        {
            if (!m_hPopup)
                return false;

            if (hFocus == m_hPopup || hFocus == m_hPopupEdit || ::IsChild(m_hPopup, hFocus))
                return true;

            // Helper windows (IME etc.) may be owned by the popup but not be child.
            HWND owner = ::GetWindow(hFocus, GW_OWNER);
            if (owner && owner == m_hPopup)
                return true;

            HWND rootOwner = ::GetAncestor(hFocus, GA_ROOTOWNER);
            if (rootOwner && rootOwner == m_hPopup)
                return true;

            return false;
        }

        // ActiveX editor mode (MAComboBoxEx / MSForms.ComboBox)
        HWND hAxEdit = (HWND)m_axEdit;
        if (IsChildOrSelf(hAxEdit, hFocus))
            return true;

        // dropdown popup may not be child of our ActiveX window
        DWORD pid = 0;
        ::GetWindowThreadProcessId(hFocus, &pid);
        if (pid == ::GetCurrentProcessId())
        {
            LONG_PTR style = ::GetWindowLongPtrW(hFocus, GWL_STYLE);
            if (style & WS_POPUP)
            {
                HWND owner = ::GetWindow(hFocus, GW_OWNER);
                if (owner && IsChildOrSelf(hAxEdit, owner))
                    return true;

                HWND rootOwner = ::GetAncestor(hFocus, GA_ROOTOWNER);
                if (rootOwner && IsChildOrSelf(hAxEdit, rootOwner))
                    return true;
            }
        }

        return false;
    }
};

OBJECT_ENTRY_AUTO(__uuidof(MAMSHFlexGridEx), CMAMSHFlexGridEx)
