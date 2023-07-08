#include "Play.h"
#include "Page.h"

//int Play_Mode = PLAY_PAGE_SHORT;
clock_t TapStartTime;
int TapCount;

wchar_t TapPlayTitle[MAX_STRING];
int TapPlaySpeed;
int TapPlayPercent;
int TapPlayX;
double TapElapsed;

void Play()
{
	Page();

	TapLine(WINDOW_X0, WINDOW_Y0, "페이지 짧은 글쓰기 \n\n\n");

	//	타자속도		정확도		설명			시간
	int tapSpeedX = 0;
	gotoxy(0, WINDOW_Y1);
	printf("[%d 타]", TapPlaySpeed);

	int preciseX = 10;
	gotoxy(preciseX, WINDOW_Y1);
	printf("[%d%%]", TapPlayPercent);
	
	int titleX = 20;
	gotoxy(titleX, WINDOW_Y1);
	printf("[%ws]", TapPlayTitle);

	int elapsedX = 40;
	gotoxy(elapsedX, WINDOW_Y1);
	TapElapsed = (float)(clock() - TapStartTime) / CLOCKS_PER_SEC;
	printf("[%.1f초]", TapElapsed);
}

void OpenPlay()
{
	TapCount = 0;
	TapPlayPercent = 0;
	TapPlayX = 0;
	wcscpy(TapPlayTitle, L"장문 쓰기");
	TapElapsed = 0;

	OpenPage(PLAY_PAGE_SHORT);
}

void SavePlay()
{
}
