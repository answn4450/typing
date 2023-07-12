#pragma once
#include "Include.h"

void PushWLine(wchar_t* _Line, wchar_t _wcell);
void PopWLine(wchar_t* _Line);

void PushLine(char* _Line, char _char);
void PopLine(char* _Line);

void AddLine(wchar_t* Line, int index, wchar_t _wchar);
void SubLine(wchar_t* Line, int _index);

wchar_t FilterWChar(wchar_t input);

int CountWchar(wchar_t input);
int CountRight(wchar_t* base, wchar_t* compare);
int CountLine(wchar_t* line);
