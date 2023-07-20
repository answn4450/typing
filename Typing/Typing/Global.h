#pragma once
#include "Define.h"

extern wchar_t Hand_Line[MAX_STRING];
extern wchar_t Hand_Input;
extern bool Submit;

extern int Play_Page_Short;

extern clock_t TapStartTime;
extern double TapElapsed;

// Play와 그 하위에 적용되는 것들

extern int TapPlayPercent;
extern int TapPlaySpeed;
extern wchar_t TapPlayTitle[MAX_STRING];


extern bool TapMode;

// 입력 중인 유니코드 한 칸을 띄울 위치.
extern int TapCellX;
extern int TapCellY;
extern wchar_t TapFilePath[MAX_STRING];
extern bool TapPause;

extern int TapPlayPage;
extern int TapPlayPageLine;

extern bool TapPlayEnd;

extern int ModeSettingStep;
extern int ModePlayStep;

extern bool TapPause;
extern wchar_t TapWChar;
