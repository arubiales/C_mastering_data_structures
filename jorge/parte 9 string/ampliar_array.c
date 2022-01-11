#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *p_nombre, *p_nombre_completo;

    p_nombre = malloc(10*sizeof(char));

    strcpy(p_nombre, "Jorge");
    printf("Nombre: %s", p_nombre);

    //Ampliamos la cadena a 30 espacios
    p_nombre_completo = realloc(p_nombre, 30*sizeof(char));
    strcat(p_nombre_completo, " Chochy Youtube");
    printf("\nNombre completo: %s", p_nombre_completo);

    return 0;
}
