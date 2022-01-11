#include <stdio.h>
#include <string.h>

int main(){
    FILE *Archivo = fopen("palabras.txt", "r");
    int Apariciones=0;

    if(Archivo == NULL){
        printf("Error al acceder al archivo\n");
    }
    else{
        char TextoRecibido[1000];
        char PalabraBuscada[] = "Alberto";
        
        while (fscanf(Archivo, "%s", TextoRecibido) != EOF)
        {
            if(strcmp(TextoRecibido, PalabraBuscada) == 0){
                Apariciones++;
            }
        }
    }

    fclose(Archivo);
    printf("\nEl número de aparciones es: %i\n", Apariciones);

    return 0;
}
