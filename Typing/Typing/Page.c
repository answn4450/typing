#include "Page.h"

wchar_t TapLine0[MAX_STRING];
wchar_t TapLine1[MAX_STRING];
wchar_t TapLine2[MAX_STRING];

wchar_t HandLine0[MAX_STRING];
wchar_t HandLine1[MAX_STRING];
wchar_t HandLine2[MAX_STRING];

int CurrentLine = 0;

void Page()
{
	gotoxy(WINDOW_X0, WINDOW_Y0);
	printf("페이지 짧은 글쓰기 \n\n\n");
	
	if (Hand_Input == ENTER && CurrentLine < 2)
	{
		CurrentLine += 1;
		wcscpy(Hand_Line, L"");
	}
		
	if (CurrentLine==0)
		wcscpy(HandLine0, Hand_Line);
	if (CurrentLine == 1)
		wcscpy(HandLine1, Hand_Line);
	if (CurrentLine == 2)
		wcscpy(HandLine2, Hand_Line);

	printf("%ws\n\t", TapLine0);
	printf("%ws\n\t", HandLine0);
	printf("%ws\n\t", TapLine1);
	printf("%ws\n\t", HandLine1);
	printf("%ws\n\t", TapLine2);
	printf("%ws\n\t", HandLine2);
}

void OpenPage(int playPageMode)
{
	wcscpy(TapLine0, L"ㅁㄴㅇㄹ");
	wcscpy(TapLine1, L"1234");
	wcscpy(TapLine2, L"asdf");

	wcscpy(HandLine0, L"");
	wcscpy(HandLine1, L"");
	wcscpy(HandLine2, L"");
}

void SavePage()
{
}
