#ifndef TECLADOM_H
#define TECLADOM_H
#include "stm32f103xb.h"
void tecladom_init(int f0, int f1, int f2, int f3, int c0, int c1, int c2, int c3);
char tecladom (int f0, int f1, int f2, int f3, int c0, int c1, int c2, int c3);
#endif