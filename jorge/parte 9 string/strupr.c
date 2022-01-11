#include <stdio.h>
#include <ctype.h>


int main(){
    
    char texto[100];

    printf("Escribe un texto que será pasado a mayusculas\n");
    gets(texto);

    printf("El nuevo texto es el siguiente\n");
    for(int i=0; texto[i]; i++){
        texto[i] = toupper(texto[i]);
    }

    printf("%s\n", texto);

    return 0;
}
