#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    FILE *archivo1, *archivo2, *archivoconcat;
    char texto1[1000], texto2[1000], textoconcat[2000], car;
    int i1=0, i2=0;

    archivo1 = fopen("texto1.txt", "rt");
    archivo2 = fopen("texto2.txt", "rt");
    archivoconcat = fopen("archivoconcat.txt", "wt");


    if(archivo1 == NULL || archivo2 == NULL || archivoconcat == NULL){
        printf("Error: los archivos no han podido abrirse");
        exit(1);
    }

    
    while(!feof(archivo1)){
        car = fgetc(archivo1);
        if(car != EOF){
            texto1[i1] = car;
            i1++;
        }
    }

    fclose(archivo1);


    while(!feof(archivo2)){
        car = fgetc(archivo2);
        if(car != EOF){
            texto2[i2] = car;
            i2++;
        }
    }

    fclose(archivo2);

    strcat(textoconcat, texto1);
    strcat(textoconcat, " ");
    strcat(textoconcat, texto2);

    for(int i=0; i<strlen(textoconcat)-1; i++){
        fputc(textoconcat[i], archivoconcat);
    }


    return 0;
}

