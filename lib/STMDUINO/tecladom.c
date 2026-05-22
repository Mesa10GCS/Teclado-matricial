#include "tecladom.h"

char tecla[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};


void tecladom_init(int f0, int f1, int f2, int f3, int c0, int c1, int c2, int c3){
//FILAS 1
    int fil [4]= {f0,f1,f2,f3};
    int col [4]= {c0,c1,c2,c3};
//CLK PA
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
//COL CCOMO ENTRADAS PULL UP
    for(int i=0;i<4;i++){
        if(col[i]<8){
            GPIOA->CRL&=~(0xf<<(col[i]*4));
            GPIOA->CRL|=(0x8<<col[i]*4);
        }else{
            GPIOA->CRH&=~(0xf<<(col[i]%8)*4);
            GPIOA->CRH|=(0x8<<(col[i]%8)*4);
        }
//FILAS COMO SALIDAS PUSH PULL
        if(fil[i]<8){
            GPIOA->CRL&=~(0xf<<(fil[i]*4));
            GPIOA->CRL|=(0x1<<fil[i]*4);
        }else{
            GPIOA->CRH&=~(0xf<<(fil[i]%8)*4);
            GPIOA->CRH|=(0x1<<(fil[i]%8)*4);
        }
    }
}

char tecladom (int f0, int f1, int f2, int f3, int c0, int c1, int c2, int c3){
    int fil [4]= {f0,f1,f2,f3};
    int col [4]= {c0,c1,c2,c3};
//ESCANEO FILAS
for(int i=0;i<4;i++){
    //APAGO FILA
    GPIOA->BSRR|=(1<<(fil[i]+16));
for(int j=0;j<4;j++){
    if(!(GPIOA->IDR&(1<<col[j]))) return tecla[i][j];
}
//PRENDO FILA PORQUE NO ENCONTRO EL CARACTER
GPIOA -> BSRR|=(1<<fil[i]);
} return 'x';
}










