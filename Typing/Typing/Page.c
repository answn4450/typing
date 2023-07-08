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

	wcscpy(TapPlayTitle, L"�ҳ� - ������");

	*Pages[0][0] = L"�ҳ� - ������";
	*Pages[0][1] = L"�������⼭ ��ǳ�� ���� ���� ������ �Ҷ� ��������.";
	*Pages[0][2] = L"��ǳ�� ������ ���� �ڸ����� ���� ������ ���� �������� ���� �ϴ��� ���� �ִ�.";
	*Pages[0][3] = L"������ �ϴ��� �鿩�� ������ ���翡 �Ķ� ������ ���.";
	*Pages[0][4] = L"�� ������ ������ ���� ���� ���� �չٴڿ��� �Ķ� ������ �����. (...)";
	
	for (int i = 0; i < MAX_PAGE_LINE; ++i)
		wcscpy(HandLines[i], L"");
}

void SavePage()
{
}

void PagePerInput()
{

}
