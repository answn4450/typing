#include "TapDraw.h"

void TapLine(int x, int y, char* text)
{
	gotoxy(x, y);
	printf("%s", text);
}

void TapWLine(int x, int y, wchar_t* text)
{
	gotoxy(x, y);
	printf("%ws", text);
}

void TapFloat(int x, int y, float f)
{
	gotoxy(x, y);
	printf("%.2f", f);
}
