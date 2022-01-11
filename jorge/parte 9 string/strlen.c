#include <stdio.h>
#include <string.h>

int main(){

    char array[200];
    printf("Escribe cualquier string\n");
    fflush(stdin);
    scanf("%s", &array);
    printf("\nLa longitud de la cadena digitada es: %i \n", strlen(array));



    return 0;
}
