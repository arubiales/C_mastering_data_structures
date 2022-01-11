#include <stdio.h>
#include <ctype.h>


int main(){
    char texto[100];
    printf("Escribed un texto con mayusculas y minúsculas\n");
    fflush(stdin);
    gets(texto); //Get string guarda los espacios

    printf("El nuevo texto es el siguiente:\n");
    for(int i=0; texto[i]; i++){
        texto[i] = tolower(texto[i]);
    }
    printf("%s\n", texto);


    return 0;
}
