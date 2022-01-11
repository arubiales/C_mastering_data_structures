#include <stdio.h>


int main(){

    FILE* Archivo = fopen("escribir_archivo.txt", "a"); //Creamos un archivo si no existe y añadimos información

    if(Archivo==NULL){ // tenemos que verificar que todo ha ido bien.
        printf("Error al intentar crear/acceder al archivo");
    } else {
        char Texto[] = "Hola Mundo";
        fprintf(Archivo, "Texto Escrito %s", Texto); //Introducimos el texto en el archivo
    }

    fclose(Archivo); // Siempre hay que cerrar

    return 0;
}
