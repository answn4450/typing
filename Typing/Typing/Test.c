#include "Test.h"

int global = 23;

void Test()
{
    printf("인풋: %wc, %d\n", Hand_Input, Hand_Input);
    if (Hand_Input == BACKSPACE)
        PopLine(Hand_Line);
    else if (ValidWChar(Hand_Input))
        PushLine(Hand_Line, Hand_Input);

    printf("%ws\n", Hand_Line);
    //global = 42;
}

void test()
{
    //ReadAndWrite("..\\TextFile\\Page\\Short\\test.txt");
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
int compareLine(wchar_t* original, wchar_t* compare)
{
    int rightCount = 0;
    while (*original != '\0')
    {
        if (*compare == '\0')
            return rightCount;
        else
        {
            if (*original == *compare)
                rightCount += 1;
            else
                rightCount -= 1;

            ++original;
            ++compare;
        }
    }
    return rightCount;
}

