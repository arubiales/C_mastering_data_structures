#include <stdio.h>
#include <stdlib.h>


int main(){
    int *p_array, *p_big_array;

    p_array = (int *)malloc(5*sizeof(int));

    for(int i=0; i<5; i++){
        p_array[i] = i;
    }

    p_big_array = realloc(p_array, 10*sizeof(int));

    for(int i=5; i<10; i++){
        p_big_array[i] = i;
    }

    for(int i=0; i<10; i++){
        printf("%i ", p_big_array[i]);
    }
    printf("\n");

    free(p_array);
    free(p_big_array);


    return 0;
}
