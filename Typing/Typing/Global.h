#pragma once
#include "Define.h"

extern wchar_t Hand_Line[MAX_STRING];
extern wchar_t Hand_Input;
extern bool Submit;

extern int Play_Mode;
extern int Play_Page_Short;

extern clock_t TapStartTime;
extern double TapElapsed;

// Play�� �� ������ ����Ǵ� �͵�

extern int TapPlayPercent;
extern int TapPlaySpeed;
extern wchar_t TapPlayTitle[MAX_STRING];


extern int TapMode;

// �Է� ���� �����ڵ� �� ĭ�� ��� ��ġ.
extern int TapCellX;
extern int TapCellY;

extern bool TapPause;