#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main(){
    srand(time(NULL));
    const int random = rand() % 100 +1;
    int is_true = 1, user_n;

    while(is_true){
        printf("Introduzca un número para comprobar si es el generado por la máquina\n");
        scanf("%i", &user_n);
        if(user_n == random){
            printf("Enhorabuena el número es %i y usted lo ha acertado\n", user_n),
            is_true=0;
        }
        else{
            if(user_n<random){
                printf("No ha acertado el número, el número es MAYOR del que ha puesto\n");
            }
            else{
                printf("No ha acertado el número, el número es MENOR del que ha puesto\n");
            }
        }
    }    
}
