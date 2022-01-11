#include <stdio.h>
#include <time.h>

show(int *, int);
move(int *, int, int);
add(int *, int, int);



int main(){
    int size= 10;
    int array[10];
    int rand_int;

    for(int i=0; i<10; i++){
        rand_int = rand()%100;
        printf("%i ", rand_int);
        add(array, i, rand_int);
        printf("Show:");
        show(array, i);
        printf("\n");
    }
    printf("\n");

    show(array, 9);

    return 0;
}

show(int * array, int size){
    for(int i=0; i<=size; i++){
        printf("%i ", array[i]);
    }
    printf("\n");
}

move(int *array, int occuped_size, int n){
    for(int i=occuped_size; i>=n; i--){
        // printf("%i %i", i, n);
        array[i] = array[i-1];
    }
}

add(int *array, int size, int value){

    for(int i=0; i<=size; i++){
        if(i==size){
            array[i] = value;
            break;
        }
        if(value > array[i]){
            move(array, size, i);
            array[i] = value;
            break;
        }

    }

}
