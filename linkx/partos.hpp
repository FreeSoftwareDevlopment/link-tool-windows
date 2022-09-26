#pragma once
#include <functional>

typedef const char* c;
void partOS(void (*f)(c, c), bool lnk = false);
