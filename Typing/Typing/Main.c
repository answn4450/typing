// Play는 

#include "Include.h"

wchar_t Hand_Line[MAX_STRING];
wchar_t Hand_Input;

int Mode = MODE_PLAY;


int main()
{
    setlocale(LC_ALL, "");

    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    wcscpy(Hand_Line, L"");
    
    printf("현재: % s", asctime(timeinfo));
    printf("간단한 타자연습.\n");
    printf("ESC: 모드 스위치.\n");
    printf("Mode 1 = 설정, Mode 2 = 플레이\n");
    //test();

    switch (Mode)
    {
    case(MODE_PLAY):
        OpenPlay();
    default:
        break;
    }

    while (true)
    {
        // 한글 입력 중 일때 띄워놓을 위치 
        gotoxy(WINDOW_X0+20, WINDOW_Y0+20);
        
        Hand_Input = _getwch();
        system("cls");
        gotoxy(WINDOW_X0, WINDOW_Y0 + 1);

        if (Hand_Input == BACKSPACE)
            PopLine(Hand_Line);
        else if (ValidWChar(Hand_Input))
            PushLine(Hand_Line, Hand_Input);
        
        if (Hand_Input == ESC)
        {
            // 모드 전환 준비를 한다.
            switch (Mode)
            {
            case MODE_SETTING:
                SaveSetting();
                OpenPlay();
                break;
            case MODE_PLAY:
                SavePlay();
                OpenSetting();
                break;
            }

            Mode = 1 - Mode;
        }

        switch (Mode)
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

    return 0;
}