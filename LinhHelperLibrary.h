#ifndef LINH_HELPER_H
#define LINH_HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <iostream>
#include <string>
#include <stack>

using namespace std;

void LINH_LIST_DIRECTORY(std::string, stack<string>&);
void LINH_PRINT_WEB(int num, const wchar_t* path, float score);

#endif


