#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int *a, nombre[20], *p_nombre;
    int longitud;

    //Un número
    a = malloc(sizeof(int));
    
    *a = 5;
    printf("%d\n", *a);
    free(a);

    //Un string
    strcpy(nombre, "Jorge");
    longitud = strlen(nombre);

    p_nombre = malloc((longitud+1)*sizeof(char));

    strcpy(p_nombre, nombre);
    printf("%s ", p_nombre);
    free(p_nombre);

    return 0;
}
