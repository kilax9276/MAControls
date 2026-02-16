

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMAComboBoxEx,0x4faef8a5,0x5585,0x463b,0x9a,0xc6,0x47,0xfe,0x50,0x77,0x46,0x72);


MIDL_DEFINE_GUID(IID, IID_IMAMSHFlexGridEx,0xe342b423,0xa2f6,0x4952,0xa7,0xee,0xee,0xe9,0x80,0xee,0xcf,0xa3);


MIDL_DEFINE_GUID(IID, LIBID_MAControlsLib,0x7d464986,0x8807,0x4a52,0x85,0x9c,0x5d,0x7c,0x4a,0x9f,0x32,0x42);


MIDL_DEFINE_GUID(IID, DIID__IMAComboBoxExEvents,0x6a2f3754,0x0418,0x468f,0x9d,0xfe,0xa6,0x03,0x43,0x47,0xca,0x14);


MIDL_DEFINE_GUID(CLSID, CLSID_MAComboBoxEx,0xd3c4b88d,0xb1aa,0x4138,0x96,0x16,0xa1,0x4d,0xbf,0x87,0xd4,0x13);


MIDL_DEFINE_GUID(IID, DIID__IMAMSHFlexGridExEvents,0xbb57efd5,0x52f5,0x4b38,0xba,0x7e,0x7d,0x03,0x4f,0x5e,0xf8,0xb3);


MIDL_DEFINE_GUID(CLSID, CLSID_MAMSHFlexGridEx,0x3bed3d81,0x37a8,0x429b,0x91,0x7a,0x7f,0x40,0xc2,0x45,0xd2,0x28);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



