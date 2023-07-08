#include "Page.h"

int CurrentLine = 0;
int TapPage;
int PageCountBase;
int PageCountRight;

wchar_t *Pages[MAX_PAGE][MAX_PAGE_LINE][MAX_STRING];
wchar_t* HandLines[MAX_PAGE_LINE][MAX_STRING];

void Page()
{
	TapElapsed = (clock() - TapStartTime) / CLOCKS_PER_SEC;
	
	if (Hand_Input == ENTER)
	{
		if (CurrentLine + 1 < MAX_PAGE_LINE)
		{
			PageCountBase += max(
				CountLine(Hand_Line),
				CountLine(*Pages[TapPage][CurrentLine])
			);
			PageCountRight += CountRight(Hand_Line, *Pages[TapPage][CurrentLine]);
			wcscpy(HandLines[CurrentLine], Hand_Line);
			wcscpy(Hand_Line, L"");
			CurrentLine += 1;
		}
	}
	
	int pageSumBase = PageCountBase + CountLine(Hand_Line);
	int pageSumRight = PageCountRight + CountRight(Hand_Line, *Pages[TapPage][CurrentLine]);
	
	if (pageSumBase == 0)
	{
		TapPlayPercent = 0.0f;
		TapPlaySpeed = 0;
	}
	else
	{
		TapPlayPercent = (int)(
			100.0f * (float)(pageSumRight) / (float)(pageSumBase)
			);
		if (TapElapsed <= 0)
			TapPlaySpeed = 0.0f;
		else
			TapPlaySpeed = (pageSumBase * 60.0f / TapElapsed);
	}

	int currentY = 3;
	for (int i = 0; i < MAX_PAGE_LINE; ++i)
	{
		TapWLine(WINDOW_X0 + 4, WINDOW_Y0 + currentY, *Pages[TapPage][i]);
		++currentY;
		if (i < CurrentLine)
			TapWLine(WINDOW_X0 + 4, WINDOW_Y0 + currentY, HandLines[i]);
		else if (i == CurrentLine)
		{
			TapCellX = WINDOW_X0;
			TapCellY = WINDOW_Y0 + currentY;
			TapWLine(WINDOW_X0 + 4, WINDOW_Y0 + currentY, Hand_Line);
		}
		++currentY;
		++currentY;
	}
}

void OpenPage(int playPageMode)
{
	TapPage = 0;

	CurrentLine = 0;
	PageCountBase = 0;
	PageCountRight = 0;

	wcscpy(TapPlayTitle, L"소년 - 윤동주");

	*Pages[0][0] = L"소년 - 윤동주";
	*Pages[0][1] = L"여기저기서 단풍잎 같은 슬픈 가을이 뚝뚝 떨어진다.";
	*Pages[0][2] = L"단풍잎 떨어져 나온 자리마다 봄을 마련해 놓고 나뭇가지 위에 하늘이 펼쳐 있다.";
	*Pages[0][3] = L"가만히 하늘을 들여다 보려면 눈썹에 파란 물감이 든다.";
	*Pages[0][4] = L"두 손으로 따뜻한 볼을 쓸어 보면 손바닥에도 파란 물감이 묻어난다. (...)";
	
	for (int i = 0; i < MAX_PAGE_LINE; ++i)
		wcscpy(HandLines[i], L"");
}

void SavePage()
{
}

void PagePerInput()
{

}
