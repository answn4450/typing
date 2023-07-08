#include "Menu.h"

int Choice;
int ChoiceMin;
int ChoiceMax;
int PrintY0;
int PrintY;

void TapSetMenu(int menuSize)
{
	Choice = 1;
	ChoiceMax = menuSize;
	PrintY0 = WINDOW_Y0 + 2;
	PrintY = PrintY0;
}

void Menu()
{
	if (Hand_Input == UP && Choice < ChoiceMax)
		Choice++;
	if (Hand_Input == DOWN && Choice > 1)
		Choice--;
}

void MenuPrintLine(wchar_t* line)
{
	gotoxy(WINDOW_X0+2, PrintY);
	printf("%ws", line);

	if (PrintY - PrintY0 == Choice)
	{
		gotoxy(WINDOW_X0 + 1, PrintY);
		printf("[");
	}

	PrintY++;
}

void BackMenu(int min, int max)
{
	PrintY = PrintY0;
}

int GetChoiceMenu()
{
	return Choice;
}
