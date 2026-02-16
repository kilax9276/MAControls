

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for MAControls.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0628 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __MAControls_i_h__
#define __MAControls_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IMAComboBoxEx_FWD_DEFINED__
#define __IMAComboBoxEx_FWD_DEFINED__
typedef interface IMAComboBoxEx IMAComboBoxEx;

#endif 	/* __IMAComboBoxEx_FWD_DEFINED__ */


#ifndef __IMAMSHFlexGridEx_FWD_DEFINED__
#define __IMAMSHFlexGridEx_FWD_DEFINED__
typedef interface IMAMSHFlexGridEx IMAMSHFlexGridEx;

#endif 	/* __IMAMSHFlexGridEx_FWD_DEFINED__ */


#ifndef ___IMAComboBoxExEvents_FWD_DEFINED__
#define ___IMAComboBoxExEvents_FWD_DEFINED__
typedef interface _IMAComboBoxExEvents _IMAComboBoxExEvents;

#endif 	/* ___IMAComboBoxExEvents_FWD_DEFINED__ */


#ifndef __MAComboBoxEx_FWD_DEFINED__
#define __MAComboBoxEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class MAComboBoxEx MAComboBoxEx;
#else
typedef struct MAComboBoxEx MAComboBoxEx;
#endif /* __cplusplus */

#endif 	/* __MAComboBoxEx_FWD_DEFINED__ */


#ifndef ___IMAMSHFlexGridExEvents_FWD_DEFINED__
#define ___IMAMSHFlexGridExEvents_FWD_DEFINED__
typedef interface _IMAMSHFlexGridExEvents _IMAMSHFlexGridExEvents;

#endif 	/* ___IMAMSHFlexGridExEvents_FWD_DEFINED__ */


#ifndef __MAMSHFlexGridEx_FWD_DEFINED__
#define __MAMSHFlexGridEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class MAMSHFlexGridEx MAMSHFlexGridEx;
#else
typedef struct MAMSHFlexGridEx MAMSHFlexGridEx;
#endif /* __cplusplus */

#endif 	/* __MAMSHFlexGridEx_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_MAControls_0000_0000 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum MACellEditorType
    {
        maCellText	= 0,
        maCellCombo	= 1,
        maCellList	= 2,
        maCellReadOnly	= 3
    } 	MACellEditorType;

typedef /* [v1_enum] */ 
enum MANavExitKeys
    {
        maNavExitNone	= 0,
        maNavExitEnter	= 1,
        maNavExitTab	= 2,
        maNavExitShiftTab	= 4,
        maNavExitLeft	= 8,
        maNavExitRight	= 16,
        maNavExitUp	= 32,
        maNavExitDown	= 64
    } 	MANavExitKeys;



extern RPC_IF_HANDLE __MIDL_itf_MAControls_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MAControls_0000_0000_v0_0_s_ifspec;

#ifndef __IMAComboBoxEx_INTERFACE_DEFINED__
#define __IMAComboBoxEx_INTERFACE_DEFINED__

/* interface IMAComboBoxEx */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMAComboBoxEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4faef8a5-5585-463b-9ac6-47fe50774672")
    IMAComboBoxEx : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BorderStyle( 
            /* [in] */ long style) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BorderStyle( 
            /* [retval][out] */ long *pstyle) = 0;
        
        virtual /* [id][requestedit][bindable][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp **ppFont) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabStop( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabStop( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR strText) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR *pstrText) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Row( 
            /* [in] */ LONG row) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Row( 
            /* [retval][out] */ LONG *pRow) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Col( 
            /* [in] */ LONG col) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Col( 
            /* [retval][out] */ LONG *pCol) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Combo( 
            /* [retval][out] */ IDispatch **ppCombo) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMAComboBoxExVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMAComboBoxEx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMAComboBoxEx * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMAComboBoxEx * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMAComboBoxEx * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMAComboBoxEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMAComboBoxEx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMAComboBoxEx * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_BackColor)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            IMAComboBoxEx * This,
            /* [in] */ OLE_COLOR clr);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_BackColor)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_BorderStyle)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderStyle )( 
            IMAComboBoxEx * This,
            /* [in] */ long style);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_BorderStyle)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderStyle )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ long *pstyle);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, putref_Font)
        /* [id][requestedit][bindable][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Font )( 
            IMAComboBoxEx * This,
            /* [in] */ IFontDisp *pFont);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_Font)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IMAComboBoxEx * This,
            /* [in] */ IFontDisp *pFont);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_Font)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ IFontDisp **ppFont);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_ForeColor)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForeColor )( 
            IMAComboBoxEx * This,
            /* [in] */ OLE_COLOR clr);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_ForeColor)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForeColor )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_Enabled)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IMAComboBoxEx * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_Enabled)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_TabStop)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabStop )( 
            IMAComboBoxEx * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_TabStop)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabStop )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_Text)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Text )( 
            IMAComboBoxEx * This,
            /* [in] */ BSTR strText);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_Text)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ BSTR *pstrText);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_Row)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Row )( 
            IMAComboBoxEx * This,
            /* [in] */ LONG row);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_Row)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Row )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ LONG *pRow);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, put_Col)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Col )( 
            IMAComboBoxEx * This,
            /* [in] */ LONG col);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_Col)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Col )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ LONG *pCol);
        
        DECLSPEC_XFGVIRT(IMAComboBoxEx, get_Combo)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Combo )( 
            IMAComboBoxEx * This,
            /* [retval][out] */ IDispatch **ppCombo);
        
        END_INTERFACE
    } IMAComboBoxExVtbl;

    interface IMAComboBoxEx
    {
        CONST_VTBL struct IMAComboBoxExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMAComboBoxEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMAComboBoxEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMAComboBoxEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMAComboBoxEx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMAComboBoxEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMAComboBoxEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMAComboBoxEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMAComboBoxEx_put_BackColor(This,clr)	\
    ( (This)->lpVtbl -> put_BackColor(This,clr) ) 

#define IMAComboBoxEx_get_BackColor(This,pclr)	\
    ( (This)->lpVtbl -> get_BackColor(This,pclr) ) 

#define IMAComboBoxEx_put_BorderStyle(This,style)	\
    ( (This)->lpVtbl -> put_BorderStyle(This,style) ) 

#define IMAComboBoxEx_get_BorderStyle(This,pstyle)	\
    ( (This)->lpVtbl -> get_BorderStyle(This,pstyle) ) 

#define IMAComboBoxEx_putref_Font(This,pFont)	\
    ( (This)->lpVtbl -> putref_Font(This,pFont) ) 

#define IMAComboBoxEx_put_Font(This,pFont)	\
    ( (This)->lpVtbl -> put_Font(This,pFont) ) 

#define IMAComboBoxEx_get_Font(This,ppFont)	\
    ( (This)->lpVtbl -> get_Font(This,ppFont) ) 

#define IMAComboBoxEx_put_ForeColor(This,clr)	\
    ( (This)->lpVtbl -> put_ForeColor(This,clr) ) 

#define IMAComboBoxEx_get_ForeColor(This,pclr)	\
    ( (This)->lpVtbl -> get_ForeColor(This,pclr) ) 

#define IMAComboBoxEx_put_Enabled(This,vbool)	\
    ( (This)->lpVtbl -> put_Enabled(This,vbool) ) 

#define IMAComboBoxEx_get_Enabled(This,pbool)	\
    ( (This)->lpVtbl -> get_Enabled(This,pbool) ) 

#define IMAComboBoxEx_put_TabStop(This,vbool)	\
    ( (This)->lpVtbl -> put_TabStop(This,vbool) ) 

#define IMAComboBoxEx_get_TabStop(This,pbool)	\
    ( (This)->lpVtbl -> get_TabStop(This,pbool) ) 

#define IMAComboBoxEx_put_Text(This,strText)	\
    ( (This)->lpVtbl -> put_Text(This,strText) ) 

#define IMAComboBoxEx_get_Text(This,pstrText)	\
    ( (This)->lpVtbl -> get_Text(This,pstrText) ) 

#define IMAComboBoxEx_put_Row(This,row)	\
    ( (This)->lpVtbl -> put_Row(This,row) ) 

#define IMAComboBoxEx_get_Row(This,pRow)	\
    ( (This)->lpVtbl -> get_Row(This,pRow) ) 

#define IMAComboBoxEx_put_Col(This,col)	\
    ( (This)->lpVtbl -> put_Col(This,col) ) 

#define IMAComboBoxEx_get_Col(This,pCol)	\
    ( (This)->lpVtbl -> get_Col(This,pCol) ) 

#define IMAComboBoxEx_get_Combo(This,ppCombo)	\
    ( (This)->lpVtbl -> get_Combo(This,ppCombo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMAComboBoxEx_INTERFACE_DEFINED__ */


#ifndef __IMAMSHFlexGridEx_INTERFACE_DEFINED__
#define __IMAMSHFlexGridEx_INTERFACE_DEFINED__

/* interface IMAMSHFlexGridEx */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMAMSHFlexGridEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e342b423-a2f6-4952-a7ee-eee980eecfa3")
    IMAMSHFlexGridEx : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BorderStyle( 
            /* [in] */ long style) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BorderStyle( 
            /* [retval][out] */ long *pstyle) = 0;
        
        virtual /* [id][requestedit][bindable][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp **ppFont) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_TabStop( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_TabStop( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR strText) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR *pstrText) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Grid( 
            /* [retval][out] */ IDispatch **ppGrid) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCellType( 
            /* [in] */ LONG row,
            /* [in] */ LONG col,
            /* [in] */ MACellEditorType cellType) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCellType( 
            /* [in] */ LONG row,
            /* [in] */ LONG col,
            /* [retval][out] */ MACellEditorType *pCellType) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCellItems( 
            /* [in] */ LONG row,
            /* [in] */ LONG col,
            /* [in] */ VARIANT items) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearCellItems( 
            /* [in] */ LONG row,
            /* [in] */ LONG col) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearCellConfig( 
            /* [in] */ LONG row,
            /* [in] */ LONG col) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetColumnType( 
            /* [in] */ LONG col,
            /* [in] */ MACellEditorType cellType) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetColumnItems( 
            /* [in] */ LONG col,
            /* [in] */ VARIANT items) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearColumnConfig( 
            /* [in] */ LONG col) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetDefaultCellType( 
            /* [in] */ MACellEditorType cellType) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetDefaultCellItems( 
            /* [in] */ VARIANT items) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearDefaultCellItems( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetDefaultNavOptions( 
            /* [in] */ LONG exitKeysMask,
            /* [in] */ VARIANT_BOOL tabWrap,
            /* [in] */ VARIANT_BOOL skipReadOnly,
            /* [in] */ VARIANT_BOOL beginEditAfterMove) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetColumnNavOptions( 
            /* [in] */ LONG col,
            /* [in] */ LONG exitKeysMask,
            /* [in] */ VARIANT_BOOL tabWrap,
            /* [in] */ VARIANT_BOOL skipReadOnly,
            /* [in] */ VARIANT_BOOL beginEditAfterMove) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetRowNavOptions( 
            /* [in] */ LONG row,
            /* [in] */ LONG exitKeysMask,
            /* [in] */ VARIANT_BOOL tabWrap,
            /* [in] */ VARIANT_BOOL skipReadOnly,
            /* [in] */ VARIANT_BOOL beginEditAfterMove) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCellNavOptions( 
            /* [in] */ LONG row,
            /* [in] */ LONG col,
            /* [in] */ LONG exitKeysMask,
            /* [in] */ VARIANT_BOOL tabWrap,
            /* [in] */ VARIANT_BOOL skipReadOnly,
            /* [in] */ VARIANT_BOOL beginEditAfterMove) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearColumnNavOptions( 
            /* [in] */ LONG col) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearRowNavOptions( 
            /* [in] */ LONG row) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearCellNavOptions( 
            /* [in] */ LONG row,
            /* [in] */ LONG col) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowUserResizing( 
            /* [in] */ LONG mode) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowUserResizing( 
            /* [retval][out] */ LONG *pMode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetColumnHeaderText( 
            /* [in] */ LONG col,
            /* [in] */ BSTR text) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetRowHeaderText( 
            /* [in] */ LONG row,
            /* [in] */ BSTR text) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCornerHeaderText( 
            /* [in] */ BSTR text) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TextEditWidthPx( 
            /* [in] */ LONG px) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TextEditWidthPx( 
            /* [retval][out] */ LONG *ppx) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TextEditVisibleLines( 
            /* [in] */ LONG lines) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TextEditVisibleLines( 
            /* [retval][out] */ LONG *plines) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TextEditMultiline( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TextEditMultiline( 
            /* [retval][out] */ VARIANT_BOOL *pvbool) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMAMSHFlexGridExVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMAMSHFlexGridEx * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMAMSHFlexGridEx * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMAMSHFlexGridEx * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMAMSHFlexGridEx * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_BackColor)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ OLE_COLOR clr);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_BackColor)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_BorderStyle)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderStyle )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ long style);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_BorderStyle)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderStyle )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ long *pstyle);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, putref_Font)
        /* [id][requestedit][bindable][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Font )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ IFontDisp *pFont);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_Font)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ IFontDisp *pFont);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_Font)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ IFontDisp **ppFont);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_ForeColor)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForeColor )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ OLE_COLOR clr);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_ForeColor)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForeColor )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_Enabled)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_Enabled)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_TabStop)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TabStop )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_TabStop)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TabStop )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_Text)
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Text )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ BSTR strText);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_Text)
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ BSTR *pstrText);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_Grid)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Grid )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ IDispatch **ppGrid);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetCellType)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCellType )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ LONG col,
            /* [in] */ MACellEditorType cellType);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, GetCellType)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCellType )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ LONG col,
            /* [retval][out] */ MACellEditorType *pCellType);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetCellItems)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCellItems )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ LONG col,
            /* [in] */ VARIANT items);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, ClearCellItems)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearCellItems )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ LONG col);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, ClearCellConfig)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearCellConfig )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ LONG col);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetColumnType)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetColumnType )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG col,
            /* [in] */ MACellEditorType cellType);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetColumnItems)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetColumnItems )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG col,
            /* [in] */ VARIANT items);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, ClearColumnConfig)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearColumnConfig )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG col);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetDefaultCellType)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetDefaultCellType )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ MACellEditorType cellType);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetDefaultCellItems)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetDefaultCellItems )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ VARIANT items);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, ClearDefaultCellItems)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearDefaultCellItems )( 
            IMAMSHFlexGridEx * This);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetDefaultNavOptions)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetDefaultNavOptions )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG exitKeysMask,
            /* [in] */ VARIANT_BOOL tabWrap,
            /* [in] */ VARIANT_BOOL skipReadOnly,
            /* [in] */ VARIANT_BOOL beginEditAfterMove);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetColumnNavOptions)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetColumnNavOptions )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG col,
            /* [in] */ LONG exitKeysMask,
            /* [in] */ VARIANT_BOOL tabWrap,
            /* [in] */ VARIANT_BOOL skipReadOnly,
            /* [in] */ VARIANT_BOOL beginEditAfterMove);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetRowNavOptions)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetRowNavOptions )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ LONG exitKeysMask,
            /* [in] */ VARIANT_BOOL tabWrap,
            /* [in] */ VARIANT_BOOL skipReadOnly,
            /* [in] */ VARIANT_BOOL beginEditAfterMove);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetCellNavOptions)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCellNavOptions )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ LONG col,
            /* [in] */ LONG exitKeysMask,
            /* [in] */ VARIANT_BOOL tabWrap,
            /* [in] */ VARIANT_BOOL skipReadOnly,
            /* [in] */ VARIANT_BOOL beginEditAfterMove);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, ClearColumnNavOptions)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearColumnNavOptions )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG col);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, ClearRowNavOptions)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearRowNavOptions )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, ClearCellNavOptions)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearCellNavOptions )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ LONG col);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_AllowUserResizing)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowUserResizing )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG mode);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_AllowUserResizing)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowUserResizing )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ LONG *pMode);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetColumnHeaderText)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetColumnHeaderText )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG col,
            /* [in] */ BSTR text);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetRowHeaderText)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetRowHeaderText )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG row,
            /* [in] */ BSTR text);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, SetCornerHeaderText)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCornerHeaderText )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ BSTR text);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_TextEditWidthPx)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextEditWidthPx )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG px);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_TextEditWidthPx)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextEditWidthPx )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ LONG *ppx);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_TextEditVisibleLines)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextEditVisibleLines )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ LONG lines);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_TextEditVisibleLines)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextEditVisibleLines )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ LONG *plines);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, put_TextEditMultiline)
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TextEditMultiline )( 
            IMAMSHFlexGridEx * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        DECLSPEC_XFGVIRT(IMAMSHFlexGridEx, get_TextEditMultiline)
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TextEditMultiline )( 
            IMAMSHFlexGridEx * This,
            /* [retval][out] */ VARIANT_BOOL *pvbool);
        
        END_INTERFACE
    } IMAMSHFlexGridExVtbl;

    interface IMAMSHFlexGridEx
    {
        CONST_VTBL struct IMAMSHFlexGridExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMAMSHFlexGridEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMAMSHFlexGridEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMAMSHFlexGridEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMAMSHFlexGridEx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMAMSHFlexGridEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMAMSHFlexGridEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMAMSHFlexGridEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMAMSHFlexGridEx_put_BackColor(This,clr)	\
    ( (This)->lpVtbl -> put_BackColor(This,clr) ) 

#define IMAMSHFlexGridEx_get_BackColor(This,pclr)	\
    ( (This)->lpVtbl -> get_BackColor(This,pclr) ) 

#define IMAMSHFlexGridEx_put_BorderStyle(This,style)	\
    ( (This)->lpVtbl -> put_BorderStyle(This,style) ) 

#define IMAMSHFlexGridEx_get_BorderStyle(This,pstyle)	\
    ( (This)->lpVtbl -> get_BorderStyle(This,pstyle) ) 

#define IMAMSHFlexGridEx_putref_Font(This,pFont)	\
    ( (This)->lpVtbl -> putref_Font(This,pFont) ) 

#define IMAMSHFlexGridEx_put_Font(This,pFont)	\
    ( (This)->lpVtbl -> put_Font(This,pFont) ) 

#define IMAMSHFlexGridEx_get_Font(This,ppFont)	\
    ( (This)->lpVtbl -> get_Font(This,ppFont) ) 

#define IMAMSHFlexGridEx_put_ForeColor(This,clr)	\
    ( (This)->lpVtbl -> put_ForeColor(This,clr) ) 

#define IMAMSHFlexGridEx_get_ForeColor(This,pclr)	\
    ( (This)->lpVtbl -> get_ForeColor(This,pclr) ) 

#define IMAMSHFlexGridEx_put_Enabled(This,vbool)	\
    ( (This)->lpVtbl -> put_Enabled(This,vbool) ) 

#define IMAMSHFlexGridEx_get_Enabled(This,pbool)	\
    ( (This)->lpVtbl -> get_Enabled(This,pbool) ) 

#define IMAMSHFlexGridEx_put_TabStop(This,vbool)	\
    ( (This)->lpVtbl -> put_TabStop(This,vbool) ) 

#define IMAMSHFlexGridEx_get_TabStop(This,pbool)	\
    ( (This)->lpVtbl -> get_TabStop(This,pbool) ) 

#define IMAMSHFlexGridEx_put_Text(This,strText)	\
    ( (This)->lpVtbl -> put_Text(This,strText) ) 

#define IMAMSHFlexGridEx_get_Text(This,pstrText)	\
    ( (This)->lpVtbl -> get_Text(This,pstrText) ) 

#define IMAMSHFlexGridEx_get_Grid(This,ppGrid)	\
    ( (This)->lpVtbl -> get_Grid(This,ppGrid) ) 

#define IMAMSHFlexGridEx_SetCellType(This,row,col,cellType)	\
    ( (This)->lpVtbl -> SetCellType(This,row,col,cellType) ) 

#define IMAMSHFlexGridEx_GetCellType(This,row,col,pCellType)	\
    ( (This)->lpVtbl -> GetCellType(This,row,col,pCellType) ) 

#define IMAMSHFlexGridEx_SetCellItems(This,row,col,items)	\
    ( (This)->lpVtbl -> SetCellItems(This,row,col,items) ) 

#define IMAMSHFlexGridEx_ClearCellItems(This,row,col)	\
    ( (This)->lpVtbl -> ClearCellItems(This,row,col) ) 

#define IMAMSHFlexGridEx_ClearCellConfig(This,row,col)	\
    ( (This)->lpVtbl -> ClearCellConfig(This,row,col) ) 

#define IMAMSHFlexGridEx_SetColumnType(This,col,cellType)	\
    ( (This)->lpVtbl -> SetColumnType(This,col,cellType) ) 

#define IMAMSHFlexGridEx_SetColumnItems(This,col,items)	\
    ( (This)->lpVtbl -> SetColumnItems(This,col,items) ) 

#define IMAMSHFlexGridEx_ClearColumnConfig(This,col)	\
    ( (This)->lpVtbl -> ClearColumnConfig(This,col) ) 

#define IMAMSHFlexGridEx_SetDefaultCellType(This,cellType)	\
    ( (This)->lpVtbl -> SetDefaultCellType(This,cellType) ) 

#define IMAMSHFlexGridEx_SetDefaultCellItems(This,items)	\
    ( (This)->lpVtbl -> SetDefaultCellItems(This,items) ) 

#define IMAMSHFlexGridEx_ClearDefaultCellItems(This)	\
    ( (This)->lpVtbl -> ClearDefaultCellItems(This) ) 

#define IMAMSHFlexGridEx_SetDefaultNavOptions(This,exitKeysMask,tabWrap,skipReadOnly,beginEditAfterMove)	\
    ( (This)->lpVtbl -> SetDefaultNavOptions(This,exitKeysMask,tabWrap,skipReadOnly,beginEditAfterMove) ) 

#define IMAMSHFlexGridEx_SetColumnNavOptions(This,col,exitKeysMask,tabWrap,skipReadOnly,beginEditAfterMove)	\
    ( (This)->lpVtbl -> SetColumnNavOptions(This,col,exitKeysMask,tabWrap,skipReadOnly,beginEditAfterMove) ) 

#define IMAMSHFlexGridEx_SetRowNavOptions(This,row,exitKeysMask,tabWrap,skipReadOnly,beginEditAfterMove)	\
    ( (This)->lpVtbl -> SetRowNavOptions(This,row,exitKeysMask,tabWrap,skipReadOnly,beginEditAfterMove) ) 

#define IMAMSHFlexGridEx_SetCellNavOptions(This,row,col,exitKeysMask,tabWrap,skipReadOnly,beginEditAfterMove)	\
    ( (This)->lpVtbl -> SetCellNavOptions(This,row,col,exitKeysMask,tabWrap,skipReadOnly,beginEditAfterMove) ) 

#define IMAMSHFlexGridEx_ClearColumnNavOptions(This,col)	\
    ( (This)->lpVtbl -> ClearColumnNavOptions(This,col) ) 

#define IMAMSHFlexGridEx_ClearRowNavOptions(This,row)	\
    ( (This)->lpVtbl -> ClearRowNavOptions(This,row) ) 

#define IMAMSHFlexGridEx_ClearCellNavOptions(This,row,col)	\
    ( (This)->lpVtbl -> ClearCellNavOptions(This,row,col) ) 

#define IMAMSHFlexGridEx_put_AllowUserResizing(This,mode)	\
    ( (This)->lpVtbl -> put_AllowUserResizing(This,mode) ) 

#define IMAMSHFlexGridEx_get_AllowUserResizing(This,pMode)	\
    ( (This)->lpVtbl -> get_AllowUserResizing(This,pMode) ) 

#define IMAMSHFlexGridEx_SetColumnHeaderText(This,col,text)	\
    ( (This)->lpVtbl -> SetColumnHeaderText(This,col,text) ) 

#define IMAMSHFlexGridEx_SetRowHeaderText(This,row,text)	\
    ( (This)->lpVtbl -> SetRowHeaderText(This,row,text) ) 

#define IMAMSHFlexGridEx_SetCornerHeaderText(This,text)	\
    ( (This)->lpVtbl -> SetCornerHeaderText(This,text) ) 

#define IMAMSHFlexGridEx_put_TextEditWidthPx(This,px)	\
    ( (This)->lpVtbl -> put_TextEditWidthPx(This,px) ) 

#define IMAMSHFlexGridEx_get_TextEditWidthPx(This,ppx)	\
    ( (This)->lpVtbl -> get_TextEditWidthPx(This,ppx) ) 

#define IMAMSHFlexGridEx_put_TextEditVisibleLines(This,lines)	\
    ( (This)->lpVtbl -> put_TextEditVisibleLines(This,lines) ) 

#define IMAMSHFlexGridEx_get_TextEditVisibleLines(This,plines)	\
    ( (This)->lpVtbl -> get_TextEditVisibleLines(This,plines) ) 

#define IMAMSHFlexGridEx_put_TextEditMultiline(This,vbool)	\
    ( (This)->lpVtbl -> put_TextEditMultiline(This,vbool) ) 

#define IMAMSHFlexGridEx_get_TextEditMultiline(This,pvbool)	\
    ( (This)->lpVtbl -> get_TextEditMultiline(This,pvbool) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMAMSHFlexGridEx_INTERFACE_DEFINED__ */



#ifndef __MAControlsLib_LIBRARY_DEFINED__
#define __MAControlsLib_LIBRARY_DEFINED__

/* library MAControlsLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_MAControlsLib;

#ifndef ___IMAComboBoxExEvents_DISPINTERFACE_DEFINED__
#define ___IMAComboBoxExEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IMAComboBoxExEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IMAComboBoxExEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6a2f3754-0418-468f-9dfe-a6034347ca14")
    _IMAComboBoxExEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IMAComboBoxExEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IMAComboBoxExEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IMAComboBoxExEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IMAComboBoxExEvents * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IMAComboBoxExEvents * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IMAComboBoxExEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IMAComboBoxExEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IMAComboBoxExEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IMAComboBoxExEventsVtbl;

    interface _IMAComboBoxExEvents
    {
        CONST_VTBL struct _IMAComboBoxExEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IMAComboBoxExEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IMAComboBoxExEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IMAComboBoxExEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IMAComboBoxExEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IMAComboBoxExEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IMAComboBoxExEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IMAComboBoxExEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IMAComboBoxExEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MAComboBoxEx;

#ifdef __cplusplus

class DECLSPEC_UUID("d3c4b88d-b1aa-4138-9616-a14dbf87d413")
MAComboBoxEx;
#endif

#ifndef ___IMAMSHFlexGridExEvents_DISPINTERFACE_DEFINED__
#define ___IMAMSHFlexGridExEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IMAMSHFlexGridExEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IMAMSHFlexGridExEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("bb57efd5-52f5-4b38-ba7e-7d034f5ef8b3")
    _IMAMSHFlexGridExEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IMAMSHFlexGridExEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IMAMSHFlexGridExEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IMAMSHFlexGridExEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IMAMSHFlexGridExEvents * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IMAMSHFlexGridExEvents * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IMAMSHFlexGridExEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IMAMSHFlexGridExEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IMAMSHFlexGridExEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IMAMSHFlexGridExEventsVtbl;

    interface _IMAMSHFlexGridExEvents
    {
        CONST_VTBL struct _IMAMSHFlexGridExEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IMAMSHFlexGridExEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IMAMSHFlexGridExEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IMAMSHFlexGridExEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IMAMSHFlexGridExEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IMAMSHFlexGridExEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IMAMSHFlexGridExEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IMAMSHFlexGridExEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IMAMSHFlexGridExEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MAMSHFlexGridEx;

#ifdef __cplusplus

class DECLSPEC_UUID("3bed3d81-37a8-429b-917a-7f40c245d228")
MAMSHFlexGridEx;
#endif
#endif /* __MAControlsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


