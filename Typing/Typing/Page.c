#include "Page.h"

int PageIndex;
int LineIndex;

int PageCountBase;
int PageCountRight;

int PageMaxIndex;
int PageLastLineIndex;

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

		if (LineIndex == GetMaxLineIndex(PageIndex) && PageIndex == PageMaxIndex)
			TapPlayEnd = true;
		else
		{
			wcscpy(HandLines[LineIndex], Hand_Line);
			wcscpy(Hand_Line, L"");
			if (LineIndex == GetMaxLineIndex(PageIndex))
			{
				PageIndex++;
				LineIndex = 0;
			}
			else
			{
				LineIndex += 1;
			}
		}
	}

	int pageSumBase = PageCountBase + CountLine(Hand_Line);
	int pageSumRight = PageCountRight + CountRight(Hand_Line, Pages[PageIndex][LineIndex]);

	if (pageSumBase == 0)
		TapPlayPercent = 0.0f;
	else
		TapPlayPercent = (int)(
			100.0f * (float)(pageSumRight) / (float)(pageSumBase)
			);

	int currentY = 3;
	
	gotoxy(6, 6);
	
	for (int i = 0; i <= GetMaxLineIndex(PageIndex); ++i)
	{
		DrawTapWLine(WINDOW_X0 + 4, WINDOW_Y0 + currentY, Pages[PageIndex][i]);
		++currentY;
		if (i < LineIndex)
			DrawTapWLine(WINDOW_X0 + 4, WINDOW_Y0 + currentY, HandLines[i]);
		else if (i == LineIndex)
		{
			TapCellX = WINDOW_X0;
			TapCellY = WINDOW_Y0 + currentY;
			DrawTapWLine(WINDOW_X0 + 4, WINDOW_Y0 + currentY, Hand_Line);
		}
		++currentY;
		++currentY;
	}

}

void InitPage(int playPageMode)
{
	pause = false;
	PageIndex = 0;
	LineIndex = 0;
	PageCountBase = 0;
	PageCountRight = 0;

	PageMaxIndex = 0;
	PageLastLineIndex = 0;

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
	PageLastLineIndex = currentLine;

	for (int i = 0; i < MAX_PAGE_LINE; ++i)
		wcscpy(HandLines[i], L"");
}


int GetMaxLineIndex(int page)
{
	if (page == PageMaxIndex)
		return PageLastLineIndex;
	else
		return MAX_PAGE_LINE-1;
}