#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max_char(int, int);
void crip_file(FILE *, FILE *, int);
void decrip_file(FILE *, int);

int main(){
    FILE *archivo, *encriptado;
    int N=3;

    archivo = fopen("archivoconcat.txt", "r");
    encriptado = fopen("encriptadoconcat.txt", "w+");

    if(archivo == NULL || encriptado == NULL){
        printf("No se ha podido abrir alguno de los archivos\n");
        exit(1);
    }

    crip_file(archivo, encriptado, N);

    decrip_file(encriptado, N);


    fclose(archivo);
    fclose(encriptado);

    return 0;
}

int max_char(int car, int mode){
    if(!mode){
        return car - 127;
    } else{
        return car + 127;
    }
}


void crip_file(FILE *archivo1, FILE *archivo2, int N){
    char texto[1000];
    int cript_char_int;
    char cript_int_char;


    fgets(texto,999, archivo1);

    for(int i=0; i<strlen(texto)-1; i++){
        cript_char_int = texto[i];
        cript_char_int += N;
        if(cript_char_int > 127){
            cript_char_int = max_char(cript_char_int, 0);
        }
        putc(cript_char_int, archivo2);
    }
}


void decrip_file(FILE *archivo1, int N){
    fseek(archivo1, 0, SEEK_SET);
    char texto[1000], res[1000];
    int cript_char_int, z=0;
    char cript_int_char;

    while(!feof(archivo1)){
        fgets(texto,999, archivo1);

        for(int i=0; i<strlen(texto)-1; i++){
            cript_char_int = texto[i];
            cript_char_int -= N;
            if(cript_char_int < 0){
                cript_char_int = max_char(cript_char_int, 1);
            }
            res[z] = cript_char_int;
            z++;
        }
    }
    printf("\nEl texto es:\n%s", res);
}
