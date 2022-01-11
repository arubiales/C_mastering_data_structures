#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    double *p_double;

    p_double = (double *)malloc(1000*sizeof(double));

    if(p_double == NULL){
        printf("Array no reservado");
    } else{
        printf("Array reservado");
    }

    return 0;
}
