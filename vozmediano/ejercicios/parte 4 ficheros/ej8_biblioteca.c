#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Biblioteca{
    char autor[60];
    char titulo[100];
    char editorial[50];
    char cdu[20];
};

int main(){
    struct Biblioteca blb[10000];
    FILE *archivo;
    char linea[1000];
    char to_struct[1000];

    int campo=0;
    int campo_idx=0;
    int cnt_line=0;

    archivo = fopen("biblioteca.txt", "r");
    if(archivo == NULL){
        printf("No se ha podido leer el archivo");
        exit(1);
    }

    printf("Antes while\n\n");
    while(!feof(archivo)){
        fgets(linea, 999, archivo);
        printf("%s", linea);
        for(int i=0; i<strlen(linea)-1; i++){
            if(linea[i] != '*' && linea[i] != '\0'){
                switch (campo)
                    {
                    case 0:
                    case 1:
                        blb[cnt_line].autor[campo_idx] = linea[i];
                        break;
                    case 2:
                        blb[cnt_line].titulo[campo_idx] = linea[i];
                        break;
                    case 3:
                        blb[cnt_line].editorial[campo_idx] = linea[i];
                        break;
                    case 4:
                        blb[cnt_line].cdu[campo_idx] = linea[i];
                        break;

                    default:
                        break;
                    }
                campo_idx++;
            } else {
                campo++;
                campo_idx = 0;
            }
        }
        cnt_line++;
        campo = 0;
        campo_idx=0;
    }

    printf("\n\n%s %s\n", blb[10].autor);
    printf("\nFIN\n");
    fclose(archivo);

    return 0;
}
