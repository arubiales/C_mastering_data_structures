#include <stdio.h>
#include <stdlib.h>

int * random_array(int, int, int);
void show(int *, int);

int main(){
    int *ptr, size=20;

    ptr = random_array(2, 10, size);
    show(ptr, size);

    return 0;
}


int * random_array(int low, int high, int size){
    int *array;

    array = (int *)malloc(size*sizeof(int));

    for(int i=0; i<size; i++){
        array[i] = rand()%(high-low) + low;
    }

    return array;
}


void show(int *array, int size){
    for(int i=0; i<size; i++){
        printf("%i ", array[i]);
    }
}
