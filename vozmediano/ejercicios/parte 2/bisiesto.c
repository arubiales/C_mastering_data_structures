#include "stdio.h"


int main(){
    int a;

    printf("Introduce un año para saber si es visiesto\n");
    scanf("%i", &a);

    if(a%4 == 0 || a%400 == 0){
        printf("El año es bisiesto\n");
    }
    else{
        printf("No es bisiesto\n");
    }

    return 0;
}
