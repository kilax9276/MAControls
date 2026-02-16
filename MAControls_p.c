

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "MAControls_i.h"

#define TYPE_FORMAT_STRING_SIZE   1251                              
#define PROC_FORMAT_STRING_SIZE   1969                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _MAControls_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MAControls_MIDL_TYPE_FORMAT_STRING;

typedef struct _MAControls_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MAControls_MIDL_PROC_FORMAT_STRING;

typedef struct _MAControls_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } MAControls_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax_2_0 = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

#if defined(_CONTROL_FLOW_GUARD_XFG)
#define XFG_TRAMPOLINES(ObjectType)\
NDR_SHAREABLE unsigned long ObjectType ## _UserSize_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize(pFlags, Offset, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserMarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserUnmarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE void ObjectType ## _UserFree_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree(pFlags, (ObjectType *)pObject);\
}
#define XFG_TRAMPOLINES64(ObjectType)\
NDR_SHAREABLE unsigned long ObjectType ## _UserSize64_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize64(pFlags, Offset, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserMarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal64(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE unsigned char * ObjectType ## _UserUnmarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal64(pFlags, pBuffer, (ObjectType *)pObject);\
}\
NDR_SHAREABLE void ObjectType ## _UserFree64_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree64(pFlags, (ObjectType *)pObject);\
}
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)\
static void* ObjectType ## _bind_XFG(HandleType pObject)\
{\
return ObjectType ## _bind((ObjectType) pObject);\
}\
static void ObjectType ## _unbind_XFG(HandleType pObject, handle_t ServerHandle)\
{\
ObjectType ## _unbind((ObjectType) pObject, ServerHandle);\
}
#define XFG_TRAMPOLINE_FPTR(Function) Function ## _XFG
#define XFG_TRAMPOLINE_FPTR_DEPENDENT_SYMBOL(Symbol) Symbol ## _XFG
#else
#define XFG_TRAMPOLINES(ObjectType)
#define XFG_TRAMPOLINES64(ObjectType)
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)
#define XFG_TRAMPOLINE_FPTR(Function) Function
#define XFG_TRAMPOLINE_FPTR_DEPENDENT_SYMBOL(Symbol) Symbol
#endif


extern const MAControls_MIDL_TYPE_FORMAT_STRING MAControls__MIDL_TypeFormatString;
extern const MAControls_MIDL_PROC_FORMAT_STRING MAControls__MIDL_ProcFormatString;
extern const MAControls_MIDL_EXPR_FORMAT_STRING MAControls__MIDL_ExprFormatString;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IMAComboBoxEx_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMAComboBoxEx_ProxyInfo;

#ifdef __cplusplus
namespace {
#endif

extern const MIDL_STUB_DESC Object_StubDesc;
#ifdef __cplusplus
}
#endif


extern const MIDL_SERVER_INFO IMAMSHFlexGridEx_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMAMSHFlexGridEx_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   forced complex structure or array, new range semantics, compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MAControls_MIDL_PROC_FORMAT_STRING MAControls__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure put_BackColor */


	/* Procedure put_BackColor */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter clr */


	/* Parameter clr */

/* 24 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_BackColor */


	/* Procedure get_BackColor */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x24 ),	/* 36 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pclr */


	/* Parameter pclr */

/* 60 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_BorderStyle */


	/* Procedure put_BorderStyle */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	NdrFcShort( 0x8 ),	/* 8 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 88 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter style */


	/* Parameter style */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_BorderStyle */


	/* Procedure get_BorderStyle */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0xa ),	/* 10 */
/* 116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x24 ),	/* 36 */
/* 122 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 124 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pstyle */


	/* Parameter pstyle */

/* 132 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure putref_Font */


	/* Procedure putref_Font */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0xb ),	/* 11 */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 160 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFont */


	/* Parameter pFont */

/* 168 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */


	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Font */


	/* Procedure put_Font */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0xc ),	/* 12 */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 194 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 196 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFont */


	/* Parameter pFont */

/* 204 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 208 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */


	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Font */


	/* Procedure get_Font */

/* 216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0xd ),	/* 13 */
/* 224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 230 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 232 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFont */


	/* Parameter ppFont */

/* 240 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 244 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Return value */


	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ForeColor */


	/* Procedure put_ForeColor */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0xe ),	/* 14 */
/* 260 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 268 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter clr */


	/* Parameter clr */

/* 276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ForeColor */


	/* Procedure get_ForeColor */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0xf ),	/* 15 */
/* 296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x24 ),	/* 36 */
/* 302 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 304 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pclr */


	/* Parameter pclr */

/* 312 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Enabled */


	/* Procedure put_Enabled */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x10 ),	/* 16 */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	NdrFcShort( 0x6 ),	/* 6 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 340 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter vbool */


	/* Parameter vbool */

/* 348 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 352 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Enabled */


	/* Procedure get_Enabled */

/* 360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x11 ),	/* 17 */
/* 368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x22 ),	/* 34 */
/* 374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 376 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbool */


	/* Parameter pbool */

/* 384 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 388 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TabStop */


	/* Procedure put_TabStop */

/* 396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x12 ),	/* 18 */
/* 404 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 406 */	NdrFcShort( 0x6 ),	/* 6 */
/* 408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 410 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 412 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter vbool */


	/* Parameter vbool */

/* 420 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 422 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 424 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TabStop */


	/* Procedure get_TabStop */

/* 432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x13 ),	/* 19 */
/* 440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x22 ),	/* 34 */
/* 446 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 448 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbool */


	/* Parameter pbool */

/* 456 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 458 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 460 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Text */


	/* Procedure put_Text */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x14 ),	/* 20 */
/* 476 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 482 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 484 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x1 ),	/* 1 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter strText */


	/* Parameter strText */

/* 492 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 494 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 496 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */


	/* Return value */

/* 498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 500 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Text */


	/* Procedure get_Text */

/* 504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x15 ),	/* 21 */
/* 512 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 520 */	0x8,		/* 8 */
			0x43,		/* Ext Flags:  new corr desc, clt corr check, has range on conformance */
/* 522 */	NdrFcShort( 0x1 ),	/* 1 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pstrText */


	/* Parameter pstrText */

/* 528 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 530 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 532 */	NdrFcShort( 0x56 ),	/* Type Offset=86 */

	/* Return value */


	/* Return value */

/* 534 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 536 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 538 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Row */

/* 540 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 542 */	NdrFcLong( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x16 ),	/* 22 */
/* 548 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 554 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 556 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 564 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 566 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 572 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Row */

/* 576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x17 ),	/* 23 */
/* 584 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x24 ),	/* 36 */
/* 590 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 592 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRow */

/* 600 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 602 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 608 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Col */

/* 612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x18 ),	/* 24 */
/* 620 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 626 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 628 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter col */

/* 636 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 638 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 644 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Col */

/* 648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x19 ),	/* 25 */
/* 656 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x24 ),	/* 36 */
/* 662 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 664 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCol */

/* 672 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 674 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 678 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 680 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Combo */

/* 684 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x1a ),	/* 26 */
/* 692 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x8 ),	/* 8 */
/* 698 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 700 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppCombo */

/* 708 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 710 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 712 */	NdrFcShort( 0x60 ),	/* Type Offset=96 */

	/* Return value */

/* 714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 716 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Grid */

/* 720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x16 ),	/* 22 */
/* 728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 734 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 736 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppGrid */

/* 744 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 748 */	NdrFcShort( 0x60 ),	/* Type Offset=96 */

	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCellType */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x17 ),	/* 23 */
/* 764 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 766 */	NdrFcShort( 0x18 ),	/* 24 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 772 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter col */

/* 786 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cellType */

/* 792 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 794 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 796 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 800 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCellType */

/* 804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x18 ),	/* 24 */
/* 812 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 814 */	NdrFcShort( 0x10 ),	/* 16 */
/* 816 */	NdrFcShort( 0x24 ),	/* 36 */
/* 818 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 820 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter col */

/* 834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 836 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCellType */

/* 840 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 842 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 844 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 848 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCellItems */

/* 852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x19 ),	/* 25 */
/* 860 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 862 */	NdrFcShort( 0x10 ),	/* 16 */
/* 864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 866 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 868 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x1 ),	/* 1 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter col */

/* 882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 884 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter items */

/* 888 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 892 */	NdrFcShort( 0x4d8 ),	/* Type Offset=1240 */

	/* Return value */

/* 894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 896 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearCellItems */

/* 900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x1a ),	/* 26 */
/* 908 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 910 */	NdrFcShort( 0x10 ),	/* 16 */
/* 912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 914 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 916 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 924 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter col */

/* 930 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 932 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 938 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearCellConfig */

/* 942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 948 */	NdrFcShort( 0x1b ),	/* 27 */
/* 950 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 952 */	NdrFcShort( 0x10 ),	/* 16 */
/* 954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 956 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 958 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 966 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 968 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter col */

/* 972 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 974 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 980 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetColumnType */

/* 984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x1c ),	/* 28 */
/* 992 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 994 */	NdrFcShort( 0x10 ),	/* 16 */
/* 996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 998 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1000 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter col */

/* 1008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1010 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cellType */

/* 1014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1016 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1018 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetColumnItems */

/* 1026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1034 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1040 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1042 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter col */

/* 1050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter items */

/* 1056 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1060 */	NdrFcShort( 0x4d8 ),	/* Type Offset=1240 */

	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearColumnConfig */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1076 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1080 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1082 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1084 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter col */

/* 1092 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1094 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDefaultCellType */

/* 1104 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1112 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1118 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1120 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cellType */

/* 1128 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1130 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1132 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1136 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDefaultCellItems */

/* 1140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1148 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1154 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1156 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter items */

/* 1164 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1166 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1168 */	NdrFcShort( 0x4d8 ),	/* Type Offset=1240 */

	/* Return value */

/* 1170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1172 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearDefaultCellItems */

/* 1176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1184 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1190 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1192 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1202 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDefaultNavOptions */

/* 1206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1214 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1216 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1220 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 1222 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter exitKeysMask */

/* 1230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1232 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter tabWrap */

/* 1236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1238 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1240 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter skipReadOnly */

/* 1242 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1244 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1246 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter beginEditAfterMove */

/* 1248 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1250 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1252 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1256 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetColumnNavOptions */

/* 1260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1268 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1270 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1274 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 1276 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1282 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter col */

/* 1284 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1286 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exitKeysMask */

/* 1290 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1292 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter tabWrap */

/* 1296 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1298 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1300 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter skipReadOnly */

/* 1302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1304 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1306 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter beginEditAfterMove */

/* 1308 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1310 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1312 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRowNavOptions */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1328 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1330 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1334 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 1336 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exitKeysMask */

/* 1350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter tabWrap */

/* 1356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1360 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter skipReadOnly */

/* 1362 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1364 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1366 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter beginEditAfterMove */

/* 1368 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1370 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1372 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1374 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1376 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCellNavOptions */

/* 1380 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1386 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1388 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1390 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1392 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1394 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 1396 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1404 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1406 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter col */

/* 1410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1412 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter exitKeysMask */

/* 1416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1418 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter tabWrap */

/* 1422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1424 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1426 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter skipReadOnly */

/* 1428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1430 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1432 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter beginEditAfterMove */

/* 1434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1436 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1438 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1440 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1442 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearColumnNavOptions */

/* 1446 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1448 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1454 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1460 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1462 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter col */

/* 1470 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1472 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1478 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearRowNavOptions */

/* 1482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1490 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1494 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1496 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1498 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1506 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1508 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearCellNavOptions */

/* 1518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1526 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1528 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1532 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1534 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1542 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter col */

/* 1548 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1556 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_AllowUserResizing */

/* 1560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1568 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1574 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1576 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter mode */

/* 1584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1586 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1592 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_AllowUserResizing */

/* 1596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1608 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1610 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1612 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pMode */

/* 1620 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1626 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetColumnHeaderText */

/* 1632 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1634 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1640 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1646 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1648 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1652 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter col */

/* 1656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1658 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter text */

/* 1662 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1664 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1666 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1670 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRowHeaderText */

/* 1674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1682 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1688 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1690 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1700 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter text */

/* 1704 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1706 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1708 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1712 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCornerHeaderText */

/* 1716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1724 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1730 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1732 */	0x8,		/* 8 */
			0x45,		/* Ext Flags:  new corr desc, srv corr check, has range on conformance */
/* 1734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1736 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter text */

/* 1740 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1742 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1744 */	NdrFcShort( 0x44 ),	/* Type Offset=68 */

	/* Return value */

/* 1746 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1748 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TextEditWidthPx */

/* 1752 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1760 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1766 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1768 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter px */

/* 1776 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1778 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1784 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TextEditWidthPx */

/* 1788 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1796 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1800 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1802 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1804 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppx */

/* 1812 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1814 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1818 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1820 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TextEditVisibleLines */

/* 1824 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1832 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1838 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1840 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lines */

/* 1848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1850 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1856 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TextEditVisibleLines */

/* 1860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1868 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1874 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1876 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter plines */

/* 1884 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1886 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1890 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1892 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TextEditMultiline */

/* 1896 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1902 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1904 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1906 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1910 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1912 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter vbool */

/* 1920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1922 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1924 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1928 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TextEditMultiline */

/* 1932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1940 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1946 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1948 */	0x8,		/* 8 */
			0x41,		/* Ext Flags:  new corr desc, has range on conformance */
/* 1950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvbool */

/* 1956 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1958 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1960 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1964 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MAControls_MIDL_TYPE_FORMAT_STRING MAControls__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0xbef6e003 ),	/* -1091117053 */
/* 12 */	NdrFcShort( 0xa874 ),	/* -22412 */
/* 14 */	NdrFcShort( 0x101a ),	/* 4122 */
/* 16 */	0x8b,		/* 139 */
			0xba,		/* 186 */
/* 18 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 20 */	0x0,		/* 0 */
			0x30,		/* 48 */
/* 22 */	0xc,		/* 12 */
			0xab,		/* 171 */
/* 24 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 26 */	NdrFcShort( 0xffec ),	/* Offset= -20 (6) */
/* 28 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 30 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 32 */	
			0x12, 0x0,	/* FC_UP */
/* 34 */	NdrFcShort( 0x18 ),	/* Offset= 24 (58) */
/* 36 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 38 */	NdrFcShort( 0x2 ),	/* 2 */
/* 40 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 42 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 44 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 46 */	0x0 , 
			0x0,		/* 0 */
/* 48 */	NdrFcLong( 0x0 ),	/* 0 */
/* 52 */	NdrFcLong( 0x0 ),	/* 0 */
/* 56 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 58 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 60 */	NdrFcShort( 0x8 ),	/* 8 */
/* 62 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (36) */
/* 64 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 66 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 68 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x4 ),	/* 4 */
/* 74 */	NdrFcShort( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (32) */
/* 78 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 80 */	NdrFcShort( 0x6 ),	/* Offset= 6 (86) */
/* 82 */	
			0x13, 0x0,	/* FC_OP */
/* 84 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (58) */
/* 86 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x4 ),	/* 4 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (82) */
/* 96 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 98 */	NdrFcShort( 0x2 ),	/* Offset= 2 (100) */
/* 100 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 102 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 112 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 114 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 116 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 118 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 120 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 122 */	
			0x12, 0x0,	/* FC_UP */
/* 124 */	NdrFcShort( 0x448 ),	/* Offset= 1096 (1220) */
/* 126 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 128 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 130 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 132 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 134 */	0x0 , 
			0x0,		/* 0 */
/* 136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x2 ),	/* Offset= 2 (146) */
/* 146 */	NdrFcShort( 0x10 ),	/* 16 */
/* 148 */	NdrFcShort( 0x2f ),	/* 47 */
/* 150 */	NdrFcLong( 0x14 ),	/* 20 */
/* 154 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 156 */	NdrFcLong( 0x3 ),	/* 3 */
/* 160 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 162 */	NdrFcLong( 0x11 ),	/* 17 */
/* 166 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 168 */	NdrFcLong( 0x2 ),	/* 2 */
/* 172 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 174 */	NdrFcLong( 0x4 ),	/* 4 */
/* 178 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 180 */	NdrFcLong( 0x5 ),	/* 5 */
/* 184 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 186 */	NdrFcLong( 0xb ),	/* 11 */
/* 190 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 192 */	NdrFcLong( 0xa ),	/* 10 */
/* 196 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 198 */	NdrFcLong( 0x6 ),	/* 6 */
/* 202 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (434) */
/* 204 */	NdrFcLong( 0x7 ),	/* 7 */
/* 208 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 210 */	NdrFcLong( 0x8 ),	/* 8 */
/* 214 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (32) */
/* 216 */	NdrFcLong( 0xd ),	/* 13 */
/* 220 */	NdrFcShort( 0xdc ),	/* Offset= 220 (440) */
/* 222 */	NdrFcLong( 0x9 ),	/* 9 */
/* 226 */	NdrFcShort( 0xff82 ),	/* Offset= -126 (100) */
/* 228 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 232 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (458) */
/* 234 */	NdrFcLong( 0x24 ),	/* 36 */
/* 238 */	NdrFcShort( 0x38c ),	/* Offset= 908 (1146) */
/* 240 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 244 */	NdrFcShort( 0x386 ),	/* Offset= 902 (1146) */
/* 246 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 250 */	NdrFcShort( 0x384 ),	/* Offset= 900 (1150) */
/* 252 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 256 */	NdrFcShort( 0x382 ),	/* Offset= 898 (1154) */
/* 258 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 262 */	NdrFcShort( 0x380 ),	/* Offset= 896 (1158) */
/* 264 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 268 */	NdrFcShort( 0x37e ),	/* Offset= 894 (1162) */
/* 270 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 274 */	NdrFcShort( 0x37c ),	/* Offset= 892 (1166) */
/* 276 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 280 */	NdrFcShort( 0x37a ),	/* Offset= 890 (1170) */
/* 282 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 286 */	NdrFcShort( 0x364 ),	/* Offset= 868 (1154) */
/* 288 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 292 */	NdrFcShort( 0x362 ),	/* Offset= 866 (1158) */
/* 294 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 298 */	NdrFcShort( 0x36c ),	/* Offset= 876 (1174) */
/* 300 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 304 */	NdrFcShort( 0x362 ),	/* Offset= 866 (1170) */
/* 306 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 310 */	NdrFcShort( 0x364 ),	/* Offset= 868 (1178) */
/* 312 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 316 */	NdrFcShort( 0x362 ),	/* Offset= 866 (1182) */
/* 318 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 322 */	NdrFcShort( 0x360 ),	/* Offset= 864 (1186) */
/* 324 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 328 */	NdrFcShort( 0x35e ),	/* Offset= 862 (1190) */
/* 330 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 334 */	NdrFcShort( 0x35c ),	/* Offset= 860 (1194) */
/* 336 */	NdrFcLong( 0x10 ),	/* 16 */
/* 340 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 342 */	NdrFcLong( 0x12 ),	/* 18 */
/* 346 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 348 */	NdrFcLong( 0x13 ),	/* 19 */
/* 352 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 354 */	NdrFcLong( 0x15 ),	/* 21 */
/* 358 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 360 */	NdrFcLong( 0x16 ),	/* 22 */
/* 364 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 366 */	NdrFcLong( 0x17 ),	/* 23 */
/* 370 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 372 */	NdrFcLong( 0xe ),	/* 14 */
/* 376 */	NdrFcShort( 0x33a ),	/* Offset= 826 (1202) */
/* 378 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 382 */	NdrFcShort( 0x33e ),	/* Offset= 830 (1212) */
/* 384 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 388 */	NdrFcShort( 0x33c ),	/* Offset= 828 (1216) */
/* 390 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 394 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (1154) */
/* 396 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 400 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (1158) */
/* 402 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 406 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (1162) */
/* 408 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 412 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (1158) */
/* 414 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 418 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (1158) */
/* 420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* Offset= 0 (424) */
/* 426 */	NdrFcLong( 0x1 ),	/* 1 */
/* 430 */	NdrFcShort( 0x0 ),	/* Offset= 0 (430) */
/* 432 */	NdrFcShort( 0xffff ),	/* Offset= -1 (431) */
/* 434 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 438 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 440 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 452 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 454 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 456 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 458 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 460 */	NdrFcShort( 0x2 ),	/* Offset= 2 (462) */
/* 462 */	
			0x12, 0x0,	/* FC_UP */
/* 464 */	NdrFcShort( 0x298 ),	/* Offset= 664 (1128) */
/* 466 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 468 */	NdrFcShort( 0x18 ),	/* 24 */
/* 470 */	NdrFcShort( 0xa ),	/* 10 */
/* 472 */	NdrFcLong( 0x8 ),	/* 8 */
/* 476 */	NdrFcShort( 0x64 ),	/* Offset= 100 (576) */
/* 478 */	NdrFcLong( 0xd ),	/* 13 */
/* 482 */	NdrFcShort( 0x9c ),	/* Offset= 156 (638) */
/* 484 */	NdrFcLong( 0x9 ),	/* 9 */
/* 488 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (696) */
/* 490 */	NdrFcLong( 0xc ),	/* 12 */
/* 494 */	NdrFcShort( 0x104 ),	/* Offset= 260 (754) */
/* 496 */	NdrFcLong( 0x24 ),	/* 36 */
/* 500 */	NdrFcShort( 0x174 ),	/* Offset= 372 (872) */
/* 502 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 506 */	NdrFcShort( 0x190 ),	/* Offset= 400 (906) */
/* 508 */	NdrFcLong( 0x10 ),	/* 16 */
/* 512 */	NdrFcShort( 0x1b4 ),	/* Offset= 436 (948) */
/* 514 */	NdrFcLong( 0x2 ),	/* 2 */
/* 518 */	NdrFcShort( 0x1d8 ),	/* Offset= 472 (990) */
/* 520 */	NdrFcLong( 0x3 ),	/* 3 */
/* 524 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (1032) */
/* 526 */	NdrFcLong( 0x14 ),	/* 20 */
/* 530 */	NdrFcShort( 0x220 ),	/* Offset= 544 (1074) */
/* 532 */	NdrFcShort( 0xffff ),	/* Offset= -1 (531) */
/* 534 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 536 */	NdrFcShort( 0x4 ),	/* 4 */
/* 538 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 544 */	0x0 , 
			0x0,		/* 0 */
/* 546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 554 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 556 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 558 */	NdrFcShort( 0x4 ),	/* 4 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x1 ),	/* 1 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	0x12, 0x0,	/* FC_UP */
/* 570 */	NdrFcShort( 0xfe00 ),	/* Offset= -512 (58) */
/* 572 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 574 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 576 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 580 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 582 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 584 */	NdrFcShort( 0x4 ),	/* 4 */
/* 586 */	NdrFcShort( 0x4 ),	/* 4 */
/* 588 */	0x11, 0x0,	/* FC_RP */
/* 590 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (534) */
/* 592 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 594 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 596 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 606 */	0x0 , 
			0x0,		/* 0 */
/* 608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 616 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 620 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 622 */	0x0 , 
			0x0,		/* 0 */
/* 624 */	NdrFcLong( 0x0 ),	/* 0 */
/* 628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 632 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 634 */	NdrFcShort( 0xff3e ),	/* Offset= -194 (440) */
/* 636 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 638 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x6 ),	/* Offset= 6 (650) */
/* 646 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 648 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 650 */	
			0x11, 0x0,	/* FC_RP */
/* 652 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (596) */
/* 654 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 664 */	0x0 , 
			0x0,		/* 0 */
/* 666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 674 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 678 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 680 */	0x0 , 
			0x0,		/* 0 */
/* 682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 690 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 692 */	NdrFcShort( 0xfdb0 ),	/* Offset= -592 (100) */
/* 694 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 696 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 698 */	NdrFcShort( 0x8 ),	/* 8 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x6 ),	/* Offset= 6 (708) */
/* 704 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 706 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 708 */	
			0x11, 0x0,	/* FC_RP */
/* 710 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (654) */
/* 712 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 714 */	NdrFcShort( 0x4 ),	/* 4 */
/* 716 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 722 */	0x0 , 
			0x0,		/* 0 */
/* 724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 734 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 736 */	NdrFcShort( 0x4 ),	/* 4 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x1 ),	/* 1 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	0x12, 0x0,	/* FC_UP */
/* 748 */	NdrFcShort( 0x1d8 ),	/* Offset= 472 (1220) */
/* 750 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 752 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 754 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0x6 ),	/* Offset= 6 (766) */
/* 762 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 764 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 766 */	
			0x11, 0x0,	/* FC_RP */
/* 768 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (712) */
/* 770 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 772 */	NdrFcLong( 0x2f ),	/* 47 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 782 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 784 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 786 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 788 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 790 */	NdrFcShort( 0x1 ),	/* 1 */
/* 792 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 794 */	NdrFcShort( 0x4 ),	/* 4 */
/* 796 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 798 */	0x0 , 
			0x0,		/* 0 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcLong( 0x0 ),	/* 0 */
/* 808 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 810 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 812 */	NdrFcShort( 0x10 ),	/* 16 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0xa ),	/* Offset= 10 (826) */
/* 818 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 820 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 822 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (770) */
/* 824 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 826 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 828 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (788) */
/* 830 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 832 */	NdrFcShort( 0x4 ),	/* 4 */
/* 834 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 840 */	0x0 , 
			0x0,		/* 0 */
/* 842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 846 */	NdrFcLong( 0x0 ),	/* 0 */
/* 850 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 852 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 854 */	NdrFcShort( 0x4 ),	/* 4 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x1 ),	/* 1 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	0x12, 0x0,	/* FC_UP */
/* 866 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (810) */
/* 868 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 870 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 872 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0x6 ),	/* Offset= 6 (884) */
/* 880 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 882 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 884 */	
			0x11, 0x0,	/* FC_RP */
/* 886 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (830) */
/* 888 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 892 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 894 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 896 */	NdrFcShort( 0x10 ),	/* 16 */
/* 898 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 900 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 902 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (888) */
			0x5b,		/* FC_END */
/* 906 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 908 */	NdrFcShort( 0x18 ),	/* 24 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0xa ),	/* Offset= 10 (922) */
/* 914 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 916 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 918 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (894) */
/* 920 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 922 */	
			0x11, 0x0,	/* FC_RP */
/* 924 */	NdrFcShort( 0xfeb8 ),	/* Offset= -328 (596) */
/* 926 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 928 */	NdrFcShort( 0x1 ),	/* 1 */
/* 930 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 936 */	0x0 , 
			0x0,		/* 0 */
/* 938 */	NdrFcLong( 0x0 ),	/* 0 */
/* 942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 946 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 948 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 952 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 954 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 956 */	NdrFcShort( 0x4 ),	/* 4 */
/* 958 */	NdrFcShort( 0x4 ),	/* 4 */
/* 960 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 962 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (926) */
/* 964 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 966 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 968 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 970 */	NdrFcShort( 0x2 ),	/* 2 */
/* 972 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 976 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 978 */	0x0 , 
			0x0,		/* 0 */
/* 980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 988 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 990 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 994 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 996 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 998 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1000 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1002 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1004 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (968) */
/* 1006 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1008 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1010 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1012 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1014 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1020 */	0x0 , 
			0x0,		/* 0 */
/* 1022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1026 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1030 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1032 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1036 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1038 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1040 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1042 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1044 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1046 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1010) */
/* 1048 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1050 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1052 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1054 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1056 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1062 */	0x0 , 
			0x0,		/* 0 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1072 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1074 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1078 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1080 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1082 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1084 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1086 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 1088 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1052) */
/* 1090 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1092 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1094 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1098 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1100 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1102 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1106 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1108 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1110 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1112 */	0x0 , 
			0x0,		/* 0 */
/* 1114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1122 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1124 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1094) */
/* 1126 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1128 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1130 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1132 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1102) */
/* 1134 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1134) */
/* 1136 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1138 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1140 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1142 */	NdrFcShort( 0xfd5c ),	/* Offset= -676 (466) */
/* 1144 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1146 */	
			0x12, 0x0,	/* FC_UP */
/* 1148 */	NdrFcShort( 0xfeae ),	/* Offset= -338 (810) */
/* 1150 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1152 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1154 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1156 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1158 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1160 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1162 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1164 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1166 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1168 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1170 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1172 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1174 */	
			0x12, 0x0,	/* FC_UP */
/* 1176 */	NdrFcShort( 0xfd1a ),	/* Offset= -742 (434) */
/* 1178 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1180 */	NdrFcShort( 0xfb84 ),	/* Offset= -1148 (32) */
/* 1182 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1184 */	NdrFcShort( 0xfd18 ),	/* Offset= -744 (440) */
/* 1186 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1188 */	NdrFcShort( 0xfbc0 ),	/* Offset= -1088 (100) */
/* 1190 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1192 */	NdrFcShort( 0xfd22 ),	/* Offset= -734 (458) */
/* 1194 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1196 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1198) */
/* 1198 */	
			0x12, 0x0,	/* FC_UP */
/* 1200 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1220) */
/* 1202 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1204 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1206 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1208 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1210 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1212 */	
			0x12, 0x0,	/* FC_UP */
/* 1214 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1202) */
/* 1216 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1218 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1220 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1222 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1226) */
/* 1228 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1230 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1232 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1234 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1236 */	NdrFcShort( 0xfbaa ),	/* Offset= -1110 (126) */
/* 1238 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1240 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1242 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1244 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0xfb9a ),	/* Offset= -1126 (122) */

			0x0
        }
    };

XFG_TRAMPOLINES(BSTR)
XFG_TRAMPOLINES(VARIANT)

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            (USER_MARSHAL_SIZING_ROUTINE)XFG_TRAMPOLINE_FPTR(BSTR_UserSize)
            ,(USER_MARSHAL_MARSHALLING_ROUTINE)XFG_TRAMPOLINE_FPTR(BSTR_UserMarshal)
            ,(USER_MARSHAL_UNMARSHALLING_ROUTINE)XFG_TRAMPOLINE_FPTR(BSTR_UserUnmarshal)
            ,(USER_MARSHAL_FREEING_ROUTINE)XFG_TRAMPOLINE_FPTR(BSTR_UserFree)
            
            }
            ,
            {
            (USER_MARSHAL_SIZING_ROUTINE)XFG_TRAMPOLINE_FPTR(VARIANT_UserSize)
            ,(USER_MARSHAL_MARSHALLING_ROUTINE)XFG_TRAMPOLINE_FPTR(VARIANT_UserMarshal)
            ,(USER_MARSHAL_UNMARSHALLING_ROUTINE)XFG_TRAMPOLINE_FPTR(VARIANT_UserUnmarshal)
            ,(USER_MARSHAL_FREEING_ROUTINE)XFG_TRAMPOLINE_FPTR(VARIANT_UserFree)
            
            }
            

        };



/* Standard interface: __MIDL_itf_MAControls_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMAComboBoxEx, ver. 0.0,
   GUID={0x4faef8a5,0x5585,0x463b,{0x9a,0xc6,0x47,0xfe,0x50,0x77,0x46,0x72}} */

#pragma code_seg(".orpc")
static const unsigned short IMAComboBoxEx_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    108,
    144,
    180,
    216,
    252,
    288,
    324,
    360,
    396,
    432,
    468,
    504,
    540,
    576,
    612,
    648,
    684
    };

static const MIDL_STUBLESS_PROXY_INFO IMAComboBoxEx_ProxyInfo =
    {
    &Object_StubDesc,
    MAControls__MIDL_ProcFormatString.Format,
    &IMAComboBoxEx_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMAComboBoxEx_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    MAControls__MIDL_ProcFormatString.Format,
    &IMAComboBoxEx_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IMAComboBoxExProxyVtbl = 
{
    &IMAComboBoxEx_ProxyInfo,
    &IID_IMAComboBoxEx,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_BackColor */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_BackColor */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_BorderStyle */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_BorderStyle */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::putref_Font */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_Font */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_Font */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_ForeColor */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_ForeColor */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_Enabled */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_Enabled */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_TabStop */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_TabStop */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_Text */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_Text */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_Row */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_Row */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::put_Col */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_Col */ ,
    (void *) (INT_PTR) -1 /* IMAComboBoxEx::get_Combo */
};


EXTERN_C DECLSPEC_SELECTANY const PRPC_STUB_FUNCTION IMAComboBoxEx_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMAComboBoxExStubVtbl =
{
    &IID_IMAComboBoxEx,
    &IMAComboBoxEx_ServerInfo,
    27,
    &IMAComboBoxEx_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IMAMSHFlexGridEx, ver. 0.0,
   GUID={0xe342b423,0xa2f6,0x4952,{0xa7,0xee,0xee,0xe9,0x80,0xee,0xcf,0xa3}} */

#pragma code_seg(".orpc")
static const unsigned short IMAMSHFlexGridEx_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    108,
    144,
    180,
    216,
    252,
    288,
    324,
    360,
    396,
    432,
    468,
    504,
    720,
    756,
    804,
    852,
    900,
    942,
    984,
    1026,
    1068,
    1104,
    1140,
    1176,
    1206,
    1260,
    1320,
    1380,
    1446,
    1482,
    1518,
    1560,
    1596,
    1632,
    1674,
    1716,
    1752,
    1788,
    1824,
    1860,
    1896,
    1932
    };

static const MIDL_STUBLESS_PROXY_INFO IMAMSHFlexGridEx_ProxyInfo =
    {
    &Object_StubDesc,
    MAControls__MIDL_ProcFormatString.Format,
    &IMAMSHFlexGridEx_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IMAMSHFlexGridEx_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    MAControls__MIDL_ProcFormatString.Format,
    &IMAMSHFlexGridEx_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(52) _IMAMSHFlexGridExProxyVtbl = 
{
    &IMAMSHFlexGridEx_ProxyInfo,
    &IID_IMAMSHFlexGridEx,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_BackColor */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_BackColor */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_BorderStyle */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_BorderStyle */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::putref_Font */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_Font */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_Font */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_ForeColor */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_ForeColor */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_Enabled */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_Enabled */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_TabStop */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_TabStop */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_Text */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_Text */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_Grid */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetCellType */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::GetCellType */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetCellItems */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::ClearCellItems */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::ClearCellConfig */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetColumnType */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetColumnItems */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::ClearColumnConfig */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetDefaultCellType */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetDefaultCellItems */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::ClearDefaultCellItems */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetDefaultNavOptions */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetColumnNavOptions */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetRowNavOptions */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetCellNavOptions */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::ClearColumnNavOptions */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::ClearRowNavOptions */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::ClearCellNavOptions */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_AllowUserResizing */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_AllowUserResizing */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetColumnHeaderText */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetRowHeaderText */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::SetCornerHeaderText */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_TextEditWidthPx */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_TextEditWidthPx */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_TextEditVisibleLines */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_TextEditVisibleLines */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::put_TextEditMultiline */ ,
    (void *) (INT_PTR) -1 /* IMAMSHFlexGridEx::get_TextEditMultiline */
};


EXTERN_C DECLSPEC_SELECTANY const PRPC_STUB_FUNCTION IMAMSHFlexGridEx_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IMAMSHFlexGridExStubVtbl =
{
    &IID_IMAMSHFlexGridEx,
    &IMAMSHFlexGridEx_ServerInfo,
    52,
    &IMAMSHFlexGridEx_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#ifdef __cplusplus
namespace {
#endif
static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    MAControls__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x8010274, /* MIDL Version 8.1.628 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };
#ifdef __cplusplus
}
#endif

const CInterfaceProxyVtbl * const _MAControls_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IMAMSHFlexGridExProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMAComboBoxExProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _MAControls_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IMAMSHFlexGridExStubVtbl,
    ( CInterfaceStubVtbl *) &_IMAComboBoxExStubVtbl,
    0
};

PCInterfaceName const _MAControls_InterfaceNamesList[] = 
{
    "IMAMSHFlexGridEx",
    "IMAComboBoxEx",
    0
};

const IID *  const _MAControls_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _MAControls_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _MAControls, pIID, n)

int __stdcall _MAControls_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _MAControls, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _MAControls, 2, *pIndex )
    
}

EXTERN_C const ExtendedProxyFileInfo MAControls_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _MAControls_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _MAControls_StubVtblList,
    (const PCInterfaceName * ) & _MAControls_InterfaceNamesList,
    (const IID ** ) & _MAControls_BaseIIDList,
    & _MAControls_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

