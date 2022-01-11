#include <stdio.h>
#include <stdlib.h>

#define TOPE 1000

int main(){
    double *p_array;
    p_array = malloc(TOPE *sizeof(double));

    if(p_array == NULL){
        printf("Error en la asignación de memoria\n");
        return -1;
    } else {
        srand(time(NULL));
        for(int i =0; i<TOPE; i++){
            p_array[i] = 1+rand() % ((TOPE+1)-1); //Creamos números aleatorios
            printf("%.2lf.\n", p_array[i]);
        }
    }

    return 0;
}
