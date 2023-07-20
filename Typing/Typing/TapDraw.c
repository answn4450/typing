#include "TapDraw.h"

void DrawTapLine(int x, int y, char* text)
{
	gotoxy(x, y);
	printf("%s", text);
}

void DrawTapWLine(int x, int y, wchar_t* text)
{
	gotoxy(x, y);
	printf("%ws", text);
}

void DrawTapFloat(int x, int y, float f)
{
	gotoxy(x, y);
	printf("%.2f", f);
}

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void TapClearScreen(int x0, int y0, int x1, int y1)
{
	for (int y = y0; y < y1; ++y)
	{
		for (int x = x0; x < x1; ++x)
		{
			gotoxy(x, y);
			printf(" ");
		}
	}
}
