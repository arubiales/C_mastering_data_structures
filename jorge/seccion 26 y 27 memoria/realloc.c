#include <stdio.h>
#include <stdlib.h>

//Sirve para una memoria que ya está asignada a un puntero aumentarla or reducirla

int main(int argc, char const *argv[])
{
    
    int *vector, *vector_convertido;
    int i;
    vector = malloc(3*sizeof(int));

    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;

    for(i=0; i<3; i++){
        printf("%i ", vector[i]);
    }

    //aquí cambiamos a 5 posiciones, es decir realocamos más memoria
    vector_convertido = realloc(vector, 5*sizeof(int));

    vector[3] = 4;
    vector[4] = 5;
    
    printf("\n\n");

    for(i=0; i<5; i++){
        printf("%i ",vector[i]);
    }

    free(vector);

    return 0;
}
