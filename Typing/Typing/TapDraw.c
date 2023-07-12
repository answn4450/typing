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
