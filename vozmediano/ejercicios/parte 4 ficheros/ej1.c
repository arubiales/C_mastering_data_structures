#include <stdio.h>


int main(){

    int n_multiplicar = 5;
    FILE *archivo;

    archivo = fopen("multiplicar.txt", "w+");
    
    if(archivo == NULL){
        printf("El archivo no ha sido creado con exito");
    }
    
    for(int i=0; i<=10; i++){
        fprintf(archivo, "%d ", i*n_multiplicar);
    }

    return 0;
}
