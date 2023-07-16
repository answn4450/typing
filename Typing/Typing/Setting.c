#include "Setting.h"
#include "Play.h"

int menuStep;

void Setting()
{
	if (menuStep < 2 && Hand_Input == L'1')
		menuStep++;

	gotoxy(WINDOW_X0, WINDOW_Y0);
	
	if (menuStep == 0)
	{
		printf("0 - 1. �� ����");
	}

	if (menuStep == 1)
	{
		printf("1 - �� ���� - ���� ����");
		
		gotoxy(WINDOW_X0, WINDOW_Y0 + 2);
		printf("1. %ws", L"test.txt");
	}

	if (menuStep == 2)
	{
		menuStep = 1;
		TapMode = MODE_PLAY;

		TapFilePath = L"..\\TextFile\\Page\\Short\\test.txt";

		wcscpy(TapPlayTitle, L"�׽�Ʈ ����");
		InitPlay();
	}
}

void InitSetting()
{
	menuStep = 0;
}

void SaveSetting()
{
}
