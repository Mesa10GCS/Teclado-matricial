#include "d7s.h"
//para el puerto a 

int d7s_c_estados[14][7]={
    {0,1,1,1,1,1,1},
    {0,0,0,0,1,1,0},
    {1,0,1,1,0,1,1},
    {1,0,0,1,1,1,1},
    {1,1,0,0,1,1,0},
    {0,1,0,1,1,0,1},
    {0,1,1,1,1,1,1},
    {0,0,0,0,1,1,1},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1},
    {1,1,1,0,1,1,1},//a
    {0,0,1,1,1,1,1},//b
    {1,0,0,1,1,1,0},//c
    {0,1,1,1,1,0,1},//d
};

void d7s_init(int a, int b, int c, int d, int e, int f, int g){ //funcion que inicia los pines del 7seg
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    int pines[7]={a,b,c,d,e,f,g};
    for(int i=0; i<7; i++){
        if(pines[i]<8){ //si los 
            GPIOA->CRL&=~(0xf<<(pines[i]*4));
            GPIOA->CRL|=(0x1<<pines[i]*4);
        }else{
            GPIOA->CRH&=~(0xf<<(pines[i]%8)*4);
            GPIOA->CRH|=(0x1<<(pines[i]%8)*4);
        }
    }
}

void d7s(int a, int b, int c, int d, int e, int f, int g, char num){
    int pines[7]={a,b,c,d,e,f,g};

    for(int i=0;i<7;i++){
        if(d7s_c_estados[((int) num-48)][(i)])GPIOB->BSRR|=(1<<pines[i]);
        else GPIOB ->BSRR |=(1<<(pines[i]+16)); 
    }
}

