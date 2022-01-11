#include <stdio.h>
#include <stdlib.h>


int * allocate_array(int);
void show(int *, int);
int * randint_array(int, int, int);
void par_impar(int *, int,  int *, int*);

int main(){
    int *rand_array, *pares, *impares, size=10, size_par=0, size_impar=0;

    rand_array = randint_array(0, 6, size);
    pares = allocate_array(size);
    impares = allocate_array(size);


    par_impar(rand_array, size, pares, impares);

    printf("Array aleatorio:\n");
    show(rand_array, size);

    printf("\nPares:\n");
    show(pares, size);

    printf("\nImpares:\n");
    show(impares, size);

}



int * allocate_array(int size){
    int *ptr = (int *)malloc(size * sizeof(int));
    if(ptr==NULL){
        printf("Error al allocar el array");
        exit(1);
    }
    return ptr;
}

void show(int *array, int size){
    for(int i=0; i<size; i++){
        printf("%i ", array[i]);
    }
    printf("\n");
}

int * randint_array(int low, int high, int size){
    int *ptr = allocate_array(size);

    for(int i=0; i<size; i++){
        ptr[i] = rand()%(high-low) + low;
    }

    return ptr;
}


void par_impar(int *arr, int size, int *pares, int *impares){
    int idx_par=0, idx_impar=0, n;

    for(int i=0; i<size; i++){
        n = arr[i];
        if(n%2 == 0){
            pares[idx_par++] = n;
        } else{
            impares[idx_impar++] = n;
        }
    }
}
