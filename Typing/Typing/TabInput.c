#include "TabInput.h"


int GetSizeLine(wchar_t* Line)
{
    int size = 0;

    while (*Line)
    {
        ++Line;
        ++size;
    }

    return size;
}

void PushLine(wchar_t* _Line, wchar_t _wcell)
{
    if (GetSizeLine(_Line) < MAX_STRING)
    {
        _Line[GetSizeLine(_Line) + 1] = '\0';
        _Line[GetSizeLine(_Line)] = _wcell;
    }
}

void PopLine(wchar_t* _Line)
{
    _Line[GetSizeLine(_Line) - 1] = '\0';
}


void AddLine(wchar_t* _Line, int _index, wchar_t _wcell)
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
