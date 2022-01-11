#include <stdio.h>


int main(){
    int a;
    int is_primo = 1;

    printf("Introduzca un número para comprobar primos\n");
    scanf("%i", &a);

    for(int i=2; i<a && is_primo==1; i++){
        if(a%i == 0){
            is_primo=0;
        }
    }

    if(is_primo==1){
        printf("El número %i es primo\n", a);
    }
    else{
        printf("El número %i no es primo\n", a);
    }

    return 0;
}
