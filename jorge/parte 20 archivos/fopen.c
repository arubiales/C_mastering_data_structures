#include <stdio.h>


int main(){

    FILE *fd;

    char direccion[]="/home/rubiales/Desktop/Projects/General/C_mastering_data_structures/jorge/parte 20 archivos/fopen.txt";
    
    fd = fopen(direccion, "r");

    if(fd == NULL){
        printf("El archivo no existe");
    } else{
        printf("El archivo si existe");
    }



    return 0;
}
