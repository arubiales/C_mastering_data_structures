#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(){
    int *array;

    array = (int *)calloc(SIZE, sizeof(int));

    for(int i=0; i<SIZE; i++){
        array[i] = i;
    }

    printf("%d\n", *array+2);

    return 0;
}
