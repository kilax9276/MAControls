// MA_AUTODOC: ============================================================================
// Copyright Kolobov Aleksei @kilax9276
// MA_AUTODOC: dllmain.h
// MA_AUTODOC: Объявление ATL-модуля CMAControlsModule.
// MA_AUTODOC: Модуль хранит LIBID, APPID и реализует стандартные ATL части (DllMain/DllRegisterServer и т.п.).
// MA_AUTODOC: ============================================================================

// dllmain.h : Declaration of module class.

// MA_AUTODOC: CMAControlsModule — единственный глобальный ATL модуль DLL.
// MA_AUTODOC: ATL использует его для управления временем жизни DLL и регистрации COM классов.
class CMAControlsModule : public ATL::CAtlDllModuleT< CMAControlsModule >
{
public :
	DECLARE_LIBID(LIBID_MAControlsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MACONTROLS, "{7d464986-8807-4a52-859c-5d7c4a9f3242}")
};

extern class CMAControlsModule _AtlModule;
