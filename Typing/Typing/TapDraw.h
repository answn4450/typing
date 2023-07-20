#pragma once
#include "Include.h"

void DrawTapLine(int x, int y, char* text);
void DrawTapWLine(int x, int y, wchar_t* text);

void DrawTapFloat(int x, int y, float f);

void gotoxy(int x, int y);

void TapClearScreen(int x0, int y0, int x1, int y1);