#include "Setting.h"
int menuStep;

void Setting()
{
	if (menuStep == 1)
	{
		MenuPrintLine("1. 글 쪽 쓰기");
		MenuPrintLine("2. 문장 따라 쓰기(예정)");
		MenuPrintLine("3. 환경 설정(예정)");

		if (Hand_Input == ENTER)
		{
			menuStep++;
			switch (GetChoiceMenu())
			{
			case MODE_PLAY_PAGE:
				break;
			}

		}
	}
}

void OpenSetting()
{
	menuStep = 0;
	TapSetMenu(3);
}

void SaveSetting()
{
}
