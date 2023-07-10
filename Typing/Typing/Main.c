// Play는 

#include "Include.h"

wchar_t Hand_Line[MAX_STRING];
wchar_t Hand_Input;
wchar_t* TapFilePath;

int TapMode = MODE_PLAY;

int TapCellX;
int TapCellY;

 bool TapPause = false;

int main()
{
    setlocale(LC_ALL, "");

    wcscpy(Hand_Line, L"");

    TapPause = false;
    TapCellX = 0;
    TapCellY = 0;
    
    printf("간단한 타자연습.\n");
    printf("ESC: 모드 스위치.\n");

    test();

    if (TapMode == MODE_PLAY)
        OpenPlay();
    else if (TapMode == MODE_SETTING)
        OpenSetting();

    while (true)
    {
        // 입력중인 문자가 표시되는 위치.
        gotoxy(TapCellX, TapCellY);
        
        Hand_Input = _getwch();

        system("cls");
        gotoxy(WINDOW_X0, WINDOW_Y0 + 1);

        if (Hand_Input == BACKSPACE)
            PopWLine(Hand_Line);
        else if (ValidWChar(Hand_Input))
            PushWLine(Hand_Line, Hand_Input);

        if (Hand_Input == ESC)
        {
            switch (TapMode)
            {
            case MODE_SETTING:
                SaveSetting();
                break;
            case MODE_PLAY:
                SavePlay();
                break;
            }

            TapPause = !TapPause;
        }

        if (TapPause)
        {
            gotoxy(5, 5);
            printf("===================");
            gotoxy(5, 6);
            printf("=      pause      =");
            gotoxy(5, 7);
            printf("===================");
            gotoxy(5, 8);
            printf("========enter======");
        }
        else
        {
            gotoxy(WINDOW_X0, WINDOW_Y0);
            switch (TapMode)
            {
            case MODE_SETTING:
                printf("셋팅 모드\n");
                Setting();
                break;
            case MODE_PLAY:
                printf("플레이 모드\n");
                Play();
                break;
            default:
                printf("테스트 모드\n");
                Test();
            }
        }

    }

    return 0;
}