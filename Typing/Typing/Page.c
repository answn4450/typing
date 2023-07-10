#include "Page.h"

int PageIndex;
int LineIndex;

int PageCountBase;
int PageCountRight;

int PageMaxIndex;
int PageLastLineCount;

bool pause;

wchar_t *Pages[MAX_PAGE][MAX_PAGE_LINE][MAX_STRING];
wchar_t* HandLines[MAX_PAGE_LINE][MAX_STRING];

void Page()
{
	TapElapsed = (clock() - TapStartTime) / CLOCKS_PER_SEC;

	if (Hand_Input == ENTER)
	{
		PageCountBase += max(
			CountLine(Hand_Line),
			CountLine(Pages[PageIndex][LineIndex])
		);
		PageCountRight += CountRight(Hand_Line, Pages[PageIndex][LineIndex]);
		wcscpy(HandLines[LineIndex], Hand_Line);
		wcscpy(Hand_Line, L"");

		if (LineIndex == GetMaxLineIndex(PageIndex, LineIndex))
		{
			pause = true;
			if (PageIndex != PageMaxIndex)
			{
				PageIndex++;
				LineIndex = 0;
			}
		}
		else
			LineIndex += 1;
	}

	int pageSumBase = PageCountBase + CountLine(Hand_Line);
	int pageSumRight = PageCountRight + CountRight(Hand_Line, Pages[PageIndex][LineIndex]);

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
	int printMaxLine;
	gotoxy(6, 6);
	printf("%d", GetMaxLineIndex(PageIndex));
	for (int i = 0; i < GetMaxLineIndex(PageIndex); ++i)
	{
		TapWLine(WINDOW_X0 + 4, WINDOW_Y0 + currentY, Pages[PageIndex][i]);
		++currentY;
		if (i < LineIndex)
			TapWLine(WINDOW_X0 + 4, WINDOW_Y0 + currentY, HandLines[i]);
		else if (i == LineIndex)
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
	pause = false;
	PageIndex = 0;
	LineIndex = 0;
	PageCountBase = 0;
	PageCountRight = 0;

	PageMaxIndex = 0;
	PageLastLineCount = 0;

	wcscpy(TapPlayTitle, L"테스트 파일");

	TapFilePath = L"..\\TextFile\\Page\\Short\\test.txt";
	FILE* fptr;
	fptr = _wfopen(TapFilePath, L"r, ccs=UTF-8");

	int currentPage = 0;
	int currentLine = 0;
	int nextPage = 0;
	int nextLine = 0;

	int count = 0;

	while (fgetws(Pages[nextPage][nextLine], MAX_STRING, fptr))
	{
		if (nextLine + 1 == MAX_PAGE_LINE)
		{
			currentPage = nextPage;
			currentLine = nextLine;
			nextPage += 1;
			nextLine = 0;
		}
		else
			nextLine++;
	}

	PageMaxIndex = currentPage;
	PageLastLineCount = currentLine;

	for (int i = 0; i < MAX_PAGE_LINE; ++i)
		wcscpy(HandLines[i], L"");
}

void SavePage()
{
}

void PagePerInput()
{
	
}

int GetMaxLineIndex(int page)
{
	if (page == PageMaxIndex)
		return PageLastLineCount;
	else
		return MAX_PAGE_LINE;
}