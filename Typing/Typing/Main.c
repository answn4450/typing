﻿// 

#include "Include.h"
#include "Play.h"
#include "Setting.h"

wchar_t Hand_Line[MAX_STRING];
wchar_t Hand_Input;
wchar_t TapWChar;
wchar_t* TapFilePath;

bool TapMode = MODE_SETTING;
bool TapPause = false;

int TapCellX = 0;
int TapCellY = 0;

int ModePlayStep = 0;
int ModeSettingStep = 0;

int main()
{
    setlocale(LC_ALL, "");
    

    TapFilePath = L"..\\TextFile\\Page\\Short\\test.txt";
    wcscpy(Hand_Line, L"");
    TapMode = MODE_SETTING;
    InitSetting();
    InitPlay();
    
    Setting();

    //test();

    while (true)
    {
        // 입력중인 문자가 표시되는 위치.
        gotoxy(TapCellX, TapCellY);

        Hand_Input = _getwch();

        if (TapPause)
            TapPause = false;

        if (Hand_Input == ESC)
            TapMode = !TapMode;

        if (TapPause)
        {
            printf("esc로 pause 풀기");
        }
        else
        {
            system("cls");
            gotoxy(WINDOW_X0, WINDOW_Y0 + 1);

            TapWChar = FilterWChar(Hand_Input);

            if (TapWChar != INVALID_WCHAR)
            {
                PushWLine(Hand_Line, TapWChar);
            }
            else if (TapWChar == BACKSPACE)
                PopWLine(Hand_Line);

            if (TapWChar == ESC)
            {
                if (TapMode == MODE_SETTING && ModeSettingStep > 0)
                    ModeSettingStep--;

                if (TapMode == MODE_PLAY && ModePlayStep > 0)
                    ModePlayStep--;
            }

            if (TapMode == MODE_SETTING)
                Setting();
            else
                Play();

        }

    }

    return 0;
}