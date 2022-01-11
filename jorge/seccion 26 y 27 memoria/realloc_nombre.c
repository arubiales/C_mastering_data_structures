#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *p_nombre, *p_nombreCompleto;
    p_nombre = (char *)malloc(10*sizeof(char));
    strcpy(p_nombre, "Alberto");
    printf("%s\n", p_nombre);

    p_nombreCompleto = realloc(p_nombre, 30*sizeof(char));

    strcat(p_nombreCompleto, " Rubiales Borrego");
    printf("%s\n", p_nombreCompleto);
    free(p_nombreCompleto);
    free(p_nombre);



    return 0;
}
