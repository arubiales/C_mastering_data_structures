#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define BUSCAR 5

int * allocate_array(int);
int * randint_array(int, int, int);
void show(int *, int);
int search(int *, int, int);


int main(){
    int *rand_array;
    rand_array = randint_array(0, 10, SIZE);

    show(rand_array, SIZE);

    printf("%d", search(rand_array, SIZE, 9));

    return 0;
}


int * allocate_array(int size){
    
    int *array = (int *)calloc(size, sizeof(int));
    
    if(array == NULL){
        printf("El array no ha podido ser creado");
        exit(1);
    }
    return array;
}


int * randint_array(int low, int high, int size){
    int *array = allocate_array(size);
    int i = 0;

    while(i<size){
        array[i] = (rand() % (high-low)) + low;
        i++;
    }

    return array;
}

void show(int *array, int size){
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int search(int *array, int size, int value){
    for(int i=0; i<size; i++){
        if(array[i] == value){
            return i;
        }
    }
}
