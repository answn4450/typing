#include "TapInput.h"


void PushWLine(wchar_t* _Line, wchar_t _wcell)
{
    if (lstrlenW(_Line) < MAX_STRING)
    {
        _Line[lstrlenW(_Line) + 1] = '\0';
        _Line[lstrlenW(_Line)] = _wcell;
    }
}

void PopWLine(wchar_t* _Line)
{
    _Line[wcslen(_Line) - 1] = '\0';
}

void PushLine(char* _Line, char _char)
{
    if (strlen(_Line) < MAX_STRING)
    {
        _Line[strlen(_Line) + 1] = '\0';
        _Line[strlen(_Line)] = _char;
    }
}

void PopLine(char* _Line)
{
    _Line[strlen(_Line) - 1] = '\0';
}


void AddLine(wchar_t* _Line, int _index, wchar_t _wchar)
{

}

void SubLine(wchar_t* _Line, int _index)
{
    int i = 0;
    while (_Line[i])
    {
        if (i >= _index)
            _Line[i] = _Line[i + 1];

        ++i;
    }
}

bool ValidWChar(wchar_t _input)
{
    bool valid = true;
    if (_input == BACKSPACE)
        valid = false;

    if (_input == ENTER)
        valid = false;

    if (_input == ESC)
        valid = false;

    return valid;
}

int CountWchar(wchar_t input)
{
    return 1;
}

int CountRight(wchar_t* base, wchar_t* compare)
{
    int rightCount = 0;
    while (*base != '\0')
    {
        if (*compare != '\0')
        {
            if (*base == *compare)
                rightCount += CountWchar(*base);
            compare++;
            base++;
        }
        else
            return rightCount;
    }
    return rightCount;
}

int CountLine(wchar_t* line)
{
    int count = 0;
    while (*line != '\0')
    {
        count += CountWchar(*line);
        line++;
    }

    return count;
}
