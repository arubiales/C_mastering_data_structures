#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int randint(int, int);
int unique(int *, int, int);
void unique_rand_array(int *, int, int, int);
void show(int *, int);

int main(){
    int array[6];
    
    unique_rand_array(array, 6, 0, 50);
    show(array, 6);


    return 0;    
}


int randint(int low, int high){
    srand(time(NULL));
    return rand()%(high - low) + low;
}

int unique(int *array, int size, int n){

    for(int i=0; i<size; i++){
        if(array[i] == n){
            return 0;
        }
    }
    return 1;
}

void unique_rand_array(int *array, int size, int min, int max){
    int rand_temp = 0, temp_size = size, i=0;

    do{
        rand_temp = randint(min, max);
        if(unique(array, size, rand_temp)){
            array[i] = rand_temp;
            i++;
            temp_size--;
        }
    } while(0 < temp_size);

}


void show(int *array, int size){
    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

