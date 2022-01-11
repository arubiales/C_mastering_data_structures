#include <stdio.h>


int sum(int *, int);
int find_missing(int *, int);
int find_missing2(int *, int);
void find_multiple_missing(int *, int);
void find_unordered_array(int *, int, int, int);

int main(){
    int array[10] = {1,2,3,4,5,7,8,9,10,11};
    int array2[10] = {4,5,6,7,9,10,11,12,13,14};
    int array3[10] = {1,2,4,5,7,9,10,11,12,13};
    int array4[10] = {3,5,6,12,1,4,8,10,11,2};

    printf("%i\n", find_missing(array, 10));
    printf("%i\n", find_missing2(array2, 10));
    find_multiple_missing(array3, 10);
    find_unordered_array(array4, 10, 1, 12);

    return 0;
}


int sum(int *arr, int size){
    int summatory = 0;
    
    for(int i=0; i<size; i++){
        summatory += arr[i];
    }
    return summatory;
}

int find_missing(int *arr, int size){
    int summatory = sum(arr, size);
    int formula = (11*(11+1)) / 2;
    return formula - summatory;
}

int find_missing2(int *arr, int size){
    int summatory = sum(arr, size);
    int n_test = arr[0];

    for(int i=0; i<size; i++){
        if(arr[i] -i != n_test){
            return arr[i]-1;
        }
    }
}


void find_multiple_missing(int *arr, int size){
    int summatory = sum(arr, size);
    int n_test = arr[0];


    for(int i=0; i<size; i++){
        if(arr[i] - i != n_test){
            printf("%i ", arr[i]-1);
            n_test++;
        }
    }

}


void find_unordered_array(int *arr, int size, int low, int high){
    int temp_array[high];

    for(int i=0; i<size; i++){
        temp_array[arr[i]] = 1;
    }

    for(int i=0; i<high; i++){
        if(temp_array[i] != 1){
            printf("El número %i falta\n", i);
        }
    }
}
