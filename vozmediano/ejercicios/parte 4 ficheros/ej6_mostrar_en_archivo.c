#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE *archivo;
    char car, string[1000];
    int counter = 0;

    archivo = fopen("mostrar_en_archivo.txt", "rt");

    if(archivo == NULL){
        printf("El archivo no ha podido ser abierto");
        exit(1);
    }

    while(!feof(archivo)){
        //Tambien vale fgets haciendo una configuración distinta
        car = getc(archivo);
        if(car != '\n'){
            string[counter++] = car;
        } else{
            if(strstr(string, "amigo")){
                printf("%s\n", string);
                }
            memset(string, 0, strlen(string));
            counter = 0;
            }
        }

    fclose(archivo);

    return 0;
}
