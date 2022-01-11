#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char *c, palabra[50];

    printf("Escribe una palabra: ");
    gets(palabra);

    c = calloc(strlen(palabra)+1, sizeof(char)); //Esto crea dinamicamente un espacio para un puntero, en función de lo ingresado-
    strcpy(c, palabra);

    printf("Palabra: %s\n", c);
    
    return 0;
}
