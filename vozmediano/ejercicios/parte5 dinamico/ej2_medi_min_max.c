#include <stdio.h>
#include <stdlib.h>

int * random_array(int, int, int);
void show(int *, int);
int min(int *, int);
int max(int *, int);
int sum(int *, int);
float mean(int *, int);


int main(){
    int *ptr, size=10;

    ptr = random_array(0, 6, size);
    show(ptr, size);

    printf("Min: %i\n", min(ptr, size));
    printf("Max: %i\n", max(ptr, size));
    printf("Sum: %i\n", sum(ptr, size));
    printf("Mean: %f\n", mean(ptr, size));

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
    printf("\n");
}

int min(int *array, int size){
    int minimum = array[0];
    
    for(int i=1; i<size; i++){
        if(array[i] < minimum){
            minimum = array[i];
        }
    }
    return minimum;
}


int max(int *array, int size){
    int maximum = array[0];
    
    for(int i=1; i<size; i++){
        if(array[i] > maximum){
            maximum = array[i];
        }
    }
    return maximum;
}

int sum(int *array, int size){
    int summatory=0;

    for(int i=0; i<size; i++){
        summatory += array[i];
    }

    return summatory;
}

float mean(int *array, int size){
    int summatory = sum(array, size);

    return (float)summatory/size;
}


