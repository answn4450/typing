#include "Test.h"

int global = 23;

void Test()
{
}

void test()
{
    TapFilePath = L"..\\TextFile\\Page\\Short\\test.txt";
    FILE* fptr;
    fptr = _wfopen(TapFilePath, L"r, ccs=UTF-8");
    wchar_t* buffer[10][5][MAX_STRING];
    while (fgetws(buffer[0][0], MAX_STRING, fptr))
        printf("%ws", buffer[0][0]);
    int a = CountLine(buffer[0][0]);
    fclose(fptr);
    /*
    wchar_t Pages[MAX_PAGE][MAX_PAGE_LINE][MAX_STRING];
    TapFilePath = L"..\\TextFile\\Page\\Short\\test.txt";
    FILE* fptr;
    fptr = _wfopen(TapFilePath, L"r, ccs=UTF-8");

    int currentPage = 0;
    int currentLine = 0;
    int nextPage = 0;
    int nextLine = 0;

    int count = 0;

    while (fgetws(Pages[nextPage][nextLine], MAX_STRING, fptr))
    {
        if (nextLine == MAX_PAGE)
        {
            CurrentPage = nextPage;
            CurrentLine = nextLine;
            nextPage += 1;
            nextLine = 0;
        }
        else
            nextLine++;
    }

    PageCount = currentPage;
    PageLastLineCount = currentLine;
    */

}

void strcpy2(wchar_t* s, wchar_t* t) {
    while (*t) {
        *s = *t;
        s++;
        t++;
    }
    *s = *t;
}

void removeChar(wchar_t* word, wchar_t idxToDel) {

    memmove(&word[idxToDel], &word[idxToDel + 1], strlen(word) - idxToDel);
}


void LoopChar(char* b)
{
    printf("%s", b);
    while (*b)
    {
        printf("%c\n", *b);
        ++b;
    }
    /*
    */
    printf("---\n");
}

void LoopWChar(wchar_t* a)
{
    wchar_t* b = a;
    printf("%wd", b);
    int index = 0;
    while (*b)
    {
        *b = L'가';
        if (++index == 2)
        {
            *b = '\0';
            //break;
        }
        printf("%wc\n", *b);
        ++b;
    }
    printf("---\n");
}


void gotoxy(int x, int y)
{
    COORD CursorPosition = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void AutoHangul()
{
    //if (GetKeyState())
    keybd_event(VK_HANGUL, 0, 0, 0);
    wchar_t a = _getwch();
    printf("asdfasdf%d\n", a);
    keybd_event(VK_HANGUL, 0, KEYEVENTF_KEYUP, 0);
}


void ReadAndWrite(const char* path)
{
    FILE* fptr;
    if ((fptr = fopen(path, "r")) == NULL) {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    wchar_t* tempReader[MAX_STRING];
    readLine(fptr, tempReader);
    printf("%ws\n", tempReader);
    
    //fprintf(fptr, "asdfas가지가df");
    
    fclose(fptr);
}


int readLine(FILE* f, wchar_t* buffer)
{
    wchar_t c;
    int i;

    memset(buffer, 0, MAX_STRING);

    for (i = 0; i < MAX_STRING; i++)
    {
        //_fgetwchar
        //fgetwchar
        wchar_t c = fgetc(f);
        printf("%d", L'ㄱ' == c);

        if (!feof(f))
        {
            if (c == '\r')
                buffer[i] = 0;
            else if (c == '\n')
            {
                buffer[i] = 0;

                return i + 1;
            }
            else
                buffer[i] = c;
        }
        else
        {
            //fprintf(stderr, "read_line(): recv returned %d\n", c);
            return -1;
        }
    }

    return -1;
}

int wreadLine(FILE* f, wchar_t* buffer)
{
    wint_t c;
    int i;

    memset(buffer, 0, MAX_STRING);

    for (i = 0; i < MAX_STRING; i++)
    {
        c = fgetc(f);
        printf("%d", 'a' == c);

        if (!feof(f))
        {
            if (c == L'\r')
                buffer[i] = 0;
            else if (c == L'\n')
            {
                buffer[i] = 0;

                return i + 1;
            }
            else
                buffer[i] = c;
        }
        else
        {
            //fprintf(stderr, "read_line(): recv returned %d\n", c);
            return -1;
        }
    }

    return -1;

}

