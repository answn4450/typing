#include "Play.h"

//int Play_Mode = PLAY_PAGE_SHORT;
clock_t TapStartTime;
int TapCount;

wchar_t TapPlayTitle[MAX_STRING];
int TapPlaySpeed;
int TapPlayPercent;
int TapPlayX;
double TapElapsed;
bool TapPlayEnd;


void Play()
{
	if (ModePlayStep == 0)
	{
		TapMode = MODE_SETTING;
		ModePlayStep = 1;
	}
	else
	{
		Page();

		if (TapWChar != INVALID_WCHAR)
			TapCount++;

		if (TapElapsed <= 0)
			TapPlaySpeed = 0.0f;
		else
			TapPlaySpeed = (TapCount * 60.0f / TapElapsed);

		DrawTapLine(WINDOW_X0, WINDOW_Y0, "������ ª�� �۾��� \n\n\n");

		//	Ÿ�ڼӵ�		��Ȯ��		����			�ð�
		int tapSpeedX = 0;
		gotoxy(0, WINDOW_Y1);
		printf("[%d Ÿ]", TapPlaySpeed);

		int preciseX = 10;
		gotoxy(preciseX, WINDOW_Y1);
		printf("[%d%%]", TapPlayPercent);

		int titleX = 20;
		gotoxy(titleX, WINDOW_Y1);
		printf("[%ws]", TapPlayTitle);

		int elapsedX = 40;
		gotoxy(elapsedX, WINDOW_Y1);
		TapElapsed = (float)(clock() - TapStartTime) / CLOCKS_PER_SEC;
		printf("[%.1f��]", TapElapsed);

		if (TapPlayEnd && Hand_Input == ENTER)
		{
			TapMode = MODE_SETTING;
			TapPlayEnd = false;
		}
	}
}

void InitPlay()
{
	wcscpy(Hand_Line, L"");
	InitPage(PLAY_PAGE_SHORT);
	ModePlayStep = 1;
	TapPlayEnd = false;
	TapCount = 0;
	TapPlayPercent = 0;
	TapPlayX = 0;
	TapElapsed = 0;
}

void SavePlay()
{
}
