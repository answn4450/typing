#include "Setting.h"
#include "Play.h"
#include "vendor/dirent.h"

int menuStep;

const int SELECT_MODE = 0;
const int SELECT_FOLDER = 1;
const int SELECT_FILE = 2;


const int SETTING_X0 = WINDOW_X0 + 2;
const int SETTING_Y0 = WINDOW_Y0 + 2;
const int SETTING_X1 = WINDOW_X0 + 30;
const int SETTING_Y1 = WINDOW_Y0 + 20;

wchar_t* selectFolder;
bool submitted;
const int MAX_FILE_COUNT = 9;
wchar_t fileList[9][MAX_STRING];


void Setting()
{
	//TapClearScreen(SETTING_X0, SETTING_Y0, SETTING_X1, SETTING_Y1);
	system("cls");
	gotoxy(SETTING_X0, WINDOW_Y0);
	
	if (menuStep == SELECT_FOLDER)
	{
		//TapClearScreen(SETTING_X0, SETTING_Y0, SETTING_X1, SETTING_Y1);
		system("cls");

		gotoxy(SETTING_X0, SETTING_Y0);
		printf("[셋팅 0단계] 숫자키로 옵션 설정.");
		gotoxy(SETTING_X0, SETTING_Y0 +1);
		printf("1. 짧은 글 쓰기\n");
		gotoxy(SETTING_X0, SETTING_Y0 +2);
		printf("2. 긴 글 쓰기\n");

		if (!submitted)
		{
			submitted = Hand_Input == L'1' || Hand_Input == L'2';

			if (Hand_Input == L'1' || Hand_Input == L'2')
				menuStep = SELECT_FILE;

			if (Hand_Input == L'1')
				selectFolder = SOURCE_FOLDER_SHORT;
			else if (Hand_Input == L'2')
				selectFolder = SOURCE_FOLDER_LONG;
		}
	}

	if (menuStep == SELECT_FILE)
	{
		//TapClearScreen(SETTING_X0, SETTING_Y0, SETTING_X1, SETTING_Y1);
		system("cls");

		gotoxy(SETTING_X0, SETTING_Y0);
		printf("1 - 글 쓰기 - 파일 선택 (탐색 위치: %ws)\n", selectFolder);
		printf("0. 이전으로\n");

		WDIR* dr;
		struct _wdirent* txt;

		dr = _wopendir(selectFolder);
		int currentY = WINDOW_X0;
		int txtFileCount = 0;
		
		if (dr) {
			while ((txt = _wreaddir(dr)) != NULL && txtFileCount < MAX_FILE_COUNT) {
				
				if (IsTxtFile(txt->d_name))
				{
					++txtFileCount;
					wcscpy(fileList[txtFileCount - 1], txt->d_name);
				}
			}
			_wclosedir(dr);
		}

		for (int i = 0; i < txtFileCount; ++i)
		{
			gotoxy(SETTING_X0, SETTING_Y0 + 4+ i);
			printf("%d) %ws\n", i + 1, fileList[i]);
		}

		for (int i = txtFileCount; i < MAX_FILE_COUNT; ++i)
			wcscpy(fileList[i], L"");

		if (!submitted)
		{
			submitted = Hand_Input >= L'0' && Hand_Input <= L'0' + txtFileCount;

			if (Hand_Input == L'0')
			{
				menuStep = SELECT_FOLDER;
				Setting();
			}

			if (Hand_Input > L'0' && Hand_Input <= L'0' + txtFileCount)
			{
				//TapClearScreen(SETTING_X0, SETTING_Y0, SETTING_X1, SETTING_Y1);
				system("cls");

				TapMode = MODE_PLAY;

				wcscpy(TapFilePath, selectFolder);
				wcscat(TapFilePath, fileList[Hand_Input - L'0' - 1]);

				wcscpy(TapPlayTitle, fileList[Hand_Input - L'0' - 1]);
				InitPlay();
			}
		}
	}

	submitted = false;
}

void InitSetting()
{
	menuStep = SELECT_FOLDER;
	submitted = false;
}

void SaveSetting()
{
}

bool IsTxtFile(wchar_t* name)
{
	wchar_t* ptr;
	ptr = wcschr(name, L'.');

	if (ptr!=NULL)
		return CountRight(L".txt", ptr) == 4;
	else
		return false;
}
