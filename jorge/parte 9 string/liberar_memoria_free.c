#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char nombre[200];
    char *p_nombre;
    int longitud;


    strcpy(nombre, "Jorge");
    longitud = strlen(nombre);

    p_nombre = malloc((longitud + 1) *sizeof(char));
    strcpy(p_nombre,nombre);

    printf("Nombre: %s", p_nombre);
    free(p_nombre);

}
