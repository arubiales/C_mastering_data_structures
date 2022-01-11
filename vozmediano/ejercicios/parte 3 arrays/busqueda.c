#include <stdio.h>
#include <time.h>


int randint(int min, int max);
int unique(int *, int, int);
void randint_array_unique(int *, int, int, int);
void randint_array(int *, int, int, int);
void burbuja(int *, int);
void seleccion_directa(int *, int);
void quicksort(int *, int);

int main(){
    int size=5;
    int array[size];

    randint_array_unique(array, size, 0, 1000);
    printf("El array desordenado es:\n");
    show(array, size);

    // burbuja(array, size);
    seleccion_directa(array, size);
    printf("El array ordenado es:\n");
    show(array, size);

    return 0;
}


int randint(int min, int max){
    // srand(time(NULL));
    return rand()%(max-min) + min;
}


int unique(int *array, int size, int value){
    
    for(int i=0; i<size; i++){
        if(array[i] == value){
            return 0;
        }
    }
    return 1;
}


void randint_array_unique(int *array, int size, int min, int max){
    int temp_rand = randint(min, max);
    
    for(int i=0; i<size; i++){
        while(!unique(array, size, temp_rand)){
            temp_rand = randint(min, max);
        }
        array[i] = temp_rand;
    }
}


void randint_array(int *array, int size, int min, int max){
    for(int i=0; i<size; i++){
        array[i] = randint(min, max);
    }
}


void show(int *array, int size){
    
    for(int i=0; i<size; i++){
        printf("%i ", array[i]);
    }
    printf("\n");
}


void burbuja(int *array, int size){
    int i=1, j,  temp;

    for(i; i<size; i++){
        for(j=size-1; j>=i; j--){
            if(array[j-1] > array[j]){
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
        }
    }
}


void seleccion_directa(int *array, int size){
    int i, element, idx, minimo;

    for(i=0; i<size; i++){
        minimo = array[i];
        idx = i;
        for(int j= i+1; j<size; j++){
            if(array[j] < minimo){
                minimo = array[j];
                idx = j;
            }
        }
        array[idx] = array[i];
        array[i] = minimo;
    }
}

