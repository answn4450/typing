#include "Setting.h"
int menuStep;

void Setting()
{
	if (menuStep == 1)
	{
		MenuPrintLine("1. �� �� ����");
		MenuPrintLine("2. ���� ���� ����(����)");
		MenuPrintLine("3. ȯ�� ����(����)");

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
