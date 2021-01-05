#pragma once

#include "DebugMenu.h"
#include "EffectDispatcher.h"
#include "TwitchVoting.h"
#include "Effects/MetaEffectInfo.h"

#include <Windows.h>
#include <memory>
#include <map>

inline std::map<EffectType, EffectData> g_enabledEffects;
inline MetaEffectInfo g_metaInfo = MetaEffectInfo();

class Main
{
public:
	void Init();
	void Loop();
	void OnKeyboardInput(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);

private:
	std::unique_ptr<DebugMenu> m_debugMenu;
	std::unique_ptr<TwitchVoting> m_twitchVoting;

	bool m_clearAllEffects = false;
	bool m_pauseTimer = false;
	bool m_clearEffectsShortcutEnabled = false;
	int m_clearEffectsTextTime = 0;
	bool m_disableDrawTimerBar = false;
	bool m_disableDrawEffectTexts = false;
	bool m_toggleModShortcutEnabled = false;
	bool m_disableMod = false;
	bool m_enableDebugMenu = false;
	bool m_enablePauseTimerShortcut = false;

	void Reset();
};