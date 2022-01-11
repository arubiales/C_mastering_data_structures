#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int print_options();
void open(int);

int main(){
    int opt;

    opt = print_options();
    open(opt);



    return 0;
}


int print_options(){
    int opt= 0;
    printf("Que desea,\n1.Abrir un archivo\n2.Crear un archivo\n");
    scanf("%d", &opt); 
    return opt;
}

void open(int opt){
    FILE *archivo;
    char n_archivo[100];
    char linea[100];
    char to_paste[10];
    int sum=0;
    float avg;

    printf("\nIndique el nombre del archivo:\n");
    scanf("%s", n_archivo);

    archivo = fopen(n_archivo, "r+");

    if(opt == 1){
        while(!feof(archivo)){
            fgets(linea, 999, archivo);
            printf("%s", linea);
        }
        fclose(archivo);
    } else if(opt==2){
        printf("Introduzca 5 números por favor\n");
        for(int i=0; i<5; i++){
            printf("\nNúmero %d: ", i);
            scanf("%s", &to_paste);
            fprintf(archivo, "%s\n", to_paste);
            sum += atoi(to_paste);
        }
        fprintf(archivo, "Suma: %i\n", sum);
        avg = (float)sum/5;
        fprintf(archivo, "Media: %f\n", avg);

        fclose(archivo);
    } else{
        printf("Lo siento la opción o es valida");
    }
}
