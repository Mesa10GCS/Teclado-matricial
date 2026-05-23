#include "stm32f103xb.h"
#include "tecladom.h"
#include "d7s.h"
#include "string.h"
#define ledv 14
#define ledr 15
char contra[4]={'1','2','3','4'};
char ingresada[4];

int main (void) {
    char tecla;
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    GPIOA -> CRH &=~(0xF<<((ledv%8)*4)); 
    GPIOA -> CRH |= (0x1<<((ledr%8)*4));
    GPIOA -> CRH &=~(0xF<<((ledr%8)*4)); 
    GPIOA -> CRH |= (0x1<<((ledr%8)*4));
    tecladom_init (0, 1, 2, 3, 4, 5, 6, 7);
    d7s_init(8, 9, 10, 11, 12, 13, 5);

    while (1){
        tecla=tecladom(0, 1, 2, 3, 4, 5, 6, 7);
        for(int i = 0; i<=4; i++){
            while(tecla!='x'){
                d7s(11, 10, 5, 6, 7, 8, 9, tecla);
                ingresada[i] = tecla;
                tecla =  tecladom(0, 1, 2, 3, 4, 5, 6, 7);
        }
    }
        if(strcmp(ingresada, contra) == 0){
            GPIOA -> BSRR |= (1 << ledv);
            GPIOA -> BSRR |= (1 << (ledr + 16));
            memset(ingresada, 0, sizeof(ingresada));
            char cambio = tecladom(0, 1, 2, 3, 4, 5, 6, 7);
            if(cambio!='x'){ d7s(11, 10, 5, 6, 7, 8, 9, cambio);
            if(cambio=='#'){
              	for(int i = 0; i<=4; i++){
                tecla=tecladom(0, 1, 2, 3, 4, 5, 6, 7);
                if(tecla!='x') d7s(11, 10, 5, 6, 7, 8, 9, cambio);
                contra[i]= tecla;
            }
        }
    }
 }else{
            GPIOA -> BSRR |= (1 << (ledv+ 16));   
            GPIOA -> BSRR |= (1 << ledr);  
            memset(ingresada, 0, sizeof(ingresada));
        }
    }
}
