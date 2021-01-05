#include <stdafx.h>

static Main m_main;

static void OnKeyboardInput(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow)
{
	m_main.OnKeyboardInput(key, repeats, scanCode, isExtended, isWithAlt, wasDownBefore, isUpNow);
}

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		Memory::Init();

		scriptRegister(hInstance, []() { m_main.Loop(); });

		keyboardHandlerRegister(OnKeyboardInput);

		SetUnhandledExceptionFilter(CrashHandler);

		break;
	case DLL_PROCESS_DETACH:
		Memory::Uninit();

		scriptUnregister(hInstance);

		keyboardHandlerUnregister(OnKeyboardInput);

		break;
	}

	return TRUE;
}