#pragma once
#include "Include.h"

void strcpy2(wchar_t* s, wchar_t* t);
void removeChar(wchar_t* word, wchar_t idxToDel);
void test();

void LoopChar(char* b);
void LoopWChar(wchar_t* a);

void gotoxy(int x, int y);

void AutoHangul();
void ReadAndWrite(const char* path);
int readLine(FILE* f, char* buffer);
int compareLine(wchar_t* original, wchar_t* compare);