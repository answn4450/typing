// 문자열이 아닌것과 한글을 섞어 치면 출력 전체가 제대로 되지 않음.해결중

#include "Include.h"

void Draw();

int main()
{
    // 유저가 쓰는 중인 있는 한 줄. 제출되지 않고 현재 수정 중인 글 칸은 포함하지 않는다. 
    wchar_t Hand_Line[MAX_STRING];

    setlocale(LC_ALL, "");
    time_t rawtime;
    struct tm* timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current local time and date: %s", asctime(timeinfo));
    
    printf("간단한 타자연습\n");

    wcscpy(Hand_Line, L"핸드 라인 가지가 그렇게");
    wcscat(Hand_Line, L"asdf가지");

    //test();

    while (true)
    {
        if (_kbhit())
        {
            system("cls");
            gotoxy(10, 10);
            wchar_t input = _getwch();
            printf("인풋: %wc\n",input);

            printf("===입력 중===");
            
            if (input == BACKSPACE)
                PopLine(Hand_Line);
            else
                PushLine(Hand_Line, input);
            
            printf("%ws\n", Hand_Line);
        }
    }
    return 0;
}

void Draw()
{
}