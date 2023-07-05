#pragma once
#include "Include.h"

int GetSizeLine(wchar_t* Line);

void PushLine(wchar_t* _Line, wchar_t _wcell);
void PopLine(wchar_t* _Line);

void AddLine(wchar_t* Line, int index, wchar_t wcell);
void SubLine(wchar_t* Line, int _index);

bool ValidWChar(wchar_t input);