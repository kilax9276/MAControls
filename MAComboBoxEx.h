// MA_AUTODOC: ============================================================================
// Copyright Kolobov Aleksei @kilax9276
// MA_AUTODOC: MAComboBoxEx.h
// MA_AUTODOC: Объявление ActiveX-контрола CMAComboBoxEx (MAComboBoxEx).
// MA_AUTODOC: Назначение: предоставить управляемый COM-интерфейс и IDispatch к MSForms.ComboBox,
// MA_AUTODOC: а также перехватывать внутреннее окно для дополнительного поведения (контекстное меню, Alt+Enter и т.п.).
// MA_AUTODOC: ============================================================================

#pragma once
#include "resource.h"
#include <atlctl.h>
#include <atlhost.h>
#include <atlstr.h>
#include <string>
#include "MAControls_i.h"
#include "_IMAComboBoxExEvents_CP.h"
#include "DispatchHelpers.h"

using namespace ATL;

class ATL_NO_VTABLE CMAComboBoxEx :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CStockPropImpl<CMAComboBoxEx, IMAComboBoxEx>,
    public IPersistStreamInitImpl<CMAComboBoxEx>,
    public IOleControlImpl<CMAComboBoxEx>,
    public IOleObjectImpl<CMAComboBoxEx>,
    public IOleInPlaceActiveObjectImpl<CMAComboBoxEx>,
    public IViewObjectExImpl<CMAComboBoxEx>,
    public IOleInPlaceObjectWindowlessImpl<CMAComboBoxEx>,
    public IConnectionPointContainerImpl<CMAComboBoxEx>,
    public CProxy_IMAComboBoxExEvents<CMAComboBoxEx>,
    public IQuickActivateImpl<CMAComboBoxEx>,
    public IProvideClassInfo2Impl<&CLSID_MAComboBoxEx, &__uuidof(_IMAComboBoxExEvents), &LIBID_MAControlsLib>,
    public IObjectSafetyImpl<CMAComboBoxEx, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
    public CComCoClass<CMAComboBoxEx, &CLSID_MAComboBoxEx>,
    public CComControl<CMAComboBoxEx>
{
public:
    CMAComboBoxEx();

    DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
        OLEMISC_CANTLINKINSIDE |
        OLEMISC_INSIDEOUT |
        OLEMISC_ACTIVATEWHENVISIBLE |
        OLEMISC_SETCLIENTSITEFIRST)

    DECLARE_REGISTRY_RESOURCEID(IDR_MACOMBOBOXEX)
    DECLARE_NOT_AGGREGATABLE(CMAComboBoxEx)

    BEGIN_COM_MAP(CMAComboBoxEx)
        COM_INTERFACE_ENTRY(IMAComboBoxEx)
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

    BEGIN_PROP_MAP(CMAComboBoxEx)
        PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
        PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
        PROP_ENTRY_TYPE("BackColor", DISPID_BACKCOLOR, CLSID_StockColorPage, VT_UI4)
        PROP_ENTRY_TYPE("BorderStyle", DISPID_BORDERSTYLE, CLSID_NULL, VT_I4)
        PROP_ENTRY_TYPE("Enabled", DISPID_ENABLED, CLSID_NULL, VT_BOOL)
        PROP_ENTRY_TYPE("Font", DISPID_FONT, CLSID_StockFontPage, VT_DISPATCH)
        PROP_ENTRY_TYPE("ForeColor", DISPID_FORECOLOR, CLSID_StockColorPage, VT_UI4)
        PROP_ENTRY_TYPE("TabStop", DISPID_TABSTOP, CLSID_NULL, VT_BOOL)
        PROP_ENTRY_TYPE("Text", DISPID_TEXT, CLSID_NULL, VT_BSTR)
    END_PROP_MAP()

    BEGIN_CONNECTION_POINT_MAP(CMAComboBoxEx)
        CONNECTION_POINT_ENTRY(__uuidof(_IMAComboBoxExEvents))
    END_CONNECTION_POINT_MAP()

    BEGIN_MSG_MAP(CMAComboBoxEx)
        MESSAGE_HANDLER(WM_CREATE, OnCreate)
        MESSAGE_HANDLER(WM_SIZE, OnSize)
        MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        CHAIN_MSG_MAP(CComControl<CMAComboBoxEx>)
        DEFAULT_REFLECTION_HANDLER()
    END_MSG_MAP()

    DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

    // MA_AUTODOC: --- VB-like поля ---
    // MA_AUTODOC: MAMSHFlexGridEx заполняет эти поля, чтобы редактор знал, для какой ячейки он сейчас показан.
    // MA_AUTODOC: Эти значения не влияют на MSForms.ComboBox напрямую, это метаданные уровня оболочки.
    // --- public VB-like fields ---
    LONG m_Row = 0;
    LONG m_Col = 0;

    // MA_AUTODOC: Внутренний MSForms.ComboBox живёт внутри CAxWindow (ActiveX-хост).
    // MA_AUTODOC: m_hInner — внутренний HWND окна ввода, на который мы ставим WndProc-хук.
    // Hosting MSForms.ComboBox.1 inside an AxWindow
    CAxWindow m_ax;
    CComPtr<IDispatch> m_cbDisp; // MSForms.ComboBox
    HWND m_hInner = nullptr;
    WNDPROC m_oldProc = nullptr;
    HMENU m_hMenu = nullptr;

    // message handlers
    // MA_AUTODOC: WM_CREATE: создаёт внутренний MSForms.ComboBox и готовит перехват сообщений.
    LRESULT OnCreate(UINT, WPARAM, LPARAM, BOOL&);
    // MA_AUTODOC: WM_SIZE: переразмещает внутренний ActiveX по размеру контрола.
    LRESULT OnSize(UINT, WPARAM, LPARAM, BOOL&);
    // MA_AUTODOC: WM_SETFOCUS: направляет фокус на внутреннее окно ввода.
    LRESULT OnSetFocus(UINT, WPARAM, LPARAM, BOOL&);
    // MA_AUTODOC: WM_DESTROY: снимает перехват и освобождает ресурсы.
    LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);

    // MA_AUTODOC: Подменённая WndProc внутреннего окна ввода MSForms.ComboBox.
    static LRESULT CALLBACK InnerWndProc(HWND, UINT, WPARAM, LPARAM);

    // helpers
    void SyncLayout();
    void HandleTextChangedLikeVB();
    void ShowContextMenu(int xScreen, int yScreen);
    void DoCopy();
    void DoPaste();
    void InsertCRLFAtCaret();

    // ---- IMAComboBoxEx ----
    HRESULT OnDraw(ATL_DRAWINFO& di);

    // MA_AUTODOC: Свойство Text проксируется во внутренний MSForms.ComboBox,
    // MA_AUTODOC: чтобы внешний мир (VB6/хост и MAMSHFlexGridEx) видел реальный введённый пользователем текст.
    // Forward Text property to the inner MSForms.ComboBox so that external callers
    // (including MAMSHFlexGridEx) always see the actual user-entered text.
    STDMETHOD(get_Text)(BSTR* pstrText);
    STDMETHOD(put_Text)(BSTR strText);

    // Extra properties declared in IDL (Row/Col/Combo)
    STDMETHOD(get_Row)(LONG* p) { if (!p) return E_POINTER; *p = m_Row; return S_OK; }
    STDMETHOD(put_Row)(LONG v) { m_Row = v; return S_OK; }
    STDMETHOD(get_Col)(LONG* p) { if (!p) return E_POINTER; *p = m_Col; return S_OK; }
    STDMETHOD(put_Col)(LONG v) { m_Col = v; return S_OK; }
    STDMETHOD(get_Combo)(IDispatch** pp) { if (!pp) return E_POINTER; *pp = m_cbDisp; if (*pp) (*pp)->AddRef(); return S_OK; }

    DECLARE_PROTECT_FINAL_CONSTRUCT()
    HRESULT FinalConstruct() { return S_OK; }
    void FinalRelease() {}
};

OBJECT_ENTRY_AUTO(__uuidof(MAComboBoxEx), CMAComboBoxEx)
