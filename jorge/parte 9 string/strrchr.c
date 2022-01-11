#include <stdio.h>
#include <string.h>

int main(){
    //sirve para cortar en el punto seleccionado

    char Abecedario[] = "abcdefghijklmnñopqrstuvwxyz";
    char Corte;

    printf("\nLetra donde se cortará el abecedario: ");
    scanf("%c", &Corte);
    printf("\n%s", strrchr(Abecedario, Corte));


    return 0;
}
