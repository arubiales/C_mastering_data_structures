#include <stdio.h>
#include <string.h>



int main(){

    FILE *archivo;
    char letra[1000];

    archivo = fopen("texto.txt", "wt");

    if(archivo == NULL){
        printf("El archivo no ha podido ser abierto");
        // exit(1);
    }

    printf("Introduzca una frase:");
    gets(letra);

    for(int i =0; i<strlen(letra); i++){
        if(letra[i] == ' '){
            fputc('\n', archivo);
        } else{
            fputc(letra[i], archivo);
        }
    }

    fclose(archivo);

    return 0;
}
