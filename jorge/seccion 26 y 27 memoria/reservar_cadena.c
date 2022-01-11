#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char *p_cadena;
    char cadena[100];

    printf("Escriba una cadena\n");
    gets(cadena);

    p_cadena = (char *)malloc(strlen(cadena)+1*sizeof(char));
    strcpy(p_cadena, cadena);

    printf("\nLa cadena es: %s\n", p_cadena);
    free(p_cadena);
    // p_cadena= NULL;
    // *p_cadena;

    p_cadena = (char *)calloc(strlen(cadena)+1, sizeof(char));
    strcpy(p_cadena, cadena);
    printf("\nAhora con Calloc: %s\n", p_cadena);
    free(p_cadena);

    return 0;
}
