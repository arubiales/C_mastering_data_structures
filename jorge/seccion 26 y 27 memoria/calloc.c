#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *hola = (int*)malloc(sizeof(int));

    printf("%p", hola);
    printf("\nhola = %d", *hola);

    //Calloc es como Malloc solo que pones el número de veces que quieres esa memoria 
    int *adios = (int*)calloc(10, sizeof(int));

    printf("\nadios = %p ", adios);
    printf("\nadios = %d ", *adios); 

    return 0;
}
