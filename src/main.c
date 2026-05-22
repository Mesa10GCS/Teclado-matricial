#include "stm32f103xb.h"
#include "tecladom.h"
#include "d7s.h"
#include "string.h"
int led_v = 14;
int led_rojo = 15;
char contra[4]={'1','2','3','4'};
char ingresada[4];

int main (void) {
    
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    
    GPIOA -> CRH &=~(0xF<<((led_rojo    %8)*4)); 
    GPIOA -> CRH |= (0x1<<((led_rojo    %8)*4));

    GPIOA -> CRH &=~(0xF<<((led_verde   %8)*4)); 
    GPIOA -> CRH |= (0x1<<((led_verde   %8)*4));

    tecladom_init (0, 1, 2, 3, 4, 5, 6, 7);
    d7s_init(8, 9, 10, 11, 12, 13, 5);

    while (1){
        char  =  tecladom(0, 1, 2, 3, 4, 5, 6, 7);
        
        for(int i = 0; i<=4; i++){
            
            while(tecla=='x') {
                d7s(11, 10, 5, 6, 7, 8, 9, tecla);
                ingresado [i] = tecla;
                tecla =  tecladom(0, 1, 2, 3, 4, 5, 6, 7);
        }
    }
    
        if (strcmp(ingresado, correcta) == 0) {

            GPIOA -> BSRR |= (1 << led_verde);    //aca se prende el led verde    (contraseña correcta)
            GPIOA -> BSRR |= (1 << (led_rojo + 16));    //aca se apaga el led rojo 
            memset(ingresado, 0, sizeof(ingresado));    //aca limpiamos la contraseña para sobre escribirla

            char tecla = tecladom(0, 1, 2, 3, 4, 5, 6, 7);
         if(tecla!='x') d7s(11, 10, 5, 6, 7, 8, 9, tecla);

         if(tecla == '#'){

            for(int i = 0; i<=4; i++){
        
        char tecla =  tecladom(0, 1, 2, 3, 4, 5, 6, 7);
         if(tecla!='x') d7s(11, 10, 5, 6, 7, 8, 9, tecla);

        correcta [i]= tecla;
    
        }
         }
            
    }else{

            GPIOA -> BSRR |= (1 << (led_verde + 16));    //aca se apaga el led verde    
            GPIOA -> BSRR |= (1 << led_rojo);    //aca se prende el led rojo     (contraseña incorrecta)
            memset(ingresado, 0, sizeof(ingresado));    //aca limpiamos la contraseña para sobre escribirla

    }

    }

}
