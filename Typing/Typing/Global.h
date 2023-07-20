#pragma once
#include "Define.h"

extern wchar_t Hand_Line[MAX_STRING];
extern wchar_t Hand_Input;
extern bool Submit;

extern int Play_Page_Short;

extern clock_t TapStartTime;
extern double TapElapsed;

// Play�� �� ������ ����Ǵ� �͵�

extern int TapPlayPercent;
extern int TapPlaySpeed;
extern wchar_t TapPlayTitle[MAX_STRING];


extern bool TapMode;

// �Է� ���� �����ڵ� �� ĭ�� ��� ��ġ.
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
