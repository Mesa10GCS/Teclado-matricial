#ifndef D7S_H//pregunto si esta definida
#define D7S_H//la defino
//incluyo los recursos
#include "stm32f103xb.h"
#include "ctype.h"
#include "stdbool.h"
#endif 
//definicion de funciones

void d7s_init(int a, int b, int c, int d, int e, int f, int g);
void d7s(int a, int b, int c, int d, int e, int f, int g, char num);