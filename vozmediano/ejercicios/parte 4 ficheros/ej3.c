#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *archivo;
    char car;

    archivo = fopen("texto.txt", "rt");

    if(archivo == NULL){
        printf("No se ha podido abrir el archivo");
        exit(1);
    }

    while(!feof(archivo)){
        car = fgetc(archivo);
        if(car == '\n'){
            printf(" ");
        } else{
            printf("%c", car);
        }
    }

    fclose(archivo);
    
    return 0;
}
