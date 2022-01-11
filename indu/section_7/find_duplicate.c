
#include <stdio.h>


void find_duplicate(int *, int);
void find_duplicate2(int *, int, int, int);

int main(){

    int order_duplicate[10] = {2,2,5,6,7,8,8,8,9,10};
    int unorder_duplicate[10] = {6,6,6, 3,10,1, 1,12,11,9};

    find_duplicate(order_duplicate, 10);
    find_duplicate2(order_duplicate, 10, 2, 10);
    find_duplicate2(unorder_duplicate, 10, 1, 12);

    return 0;
}


void find_duplicate(int *arr, int size){
    int last_dup;

    for(int i=0; i<size-1; i++){
        if(arr[i] >= arr[i+1] && arr[i] != last_dup){
            printf("Duplicado %d: \n", arr[i]);
            last_dup = arr[i];
        }
    }
}


void find_duplicate2(int *arr, int size, int low, int high){
    int temp_arr_size = high, i=0;
    int temp_arr[temp_arr_size];
    
    for(i; i<temp_arr_size; i++){
        temp_arr[i] = 0;
    }

    for(i=0; i<size; i++){
        temp_arr[arr[i]]++;
    }

    for(i=0; i<temp_arr_size; i++){
        if(temp_arr[i] > 1){
            printf("El número %i está duplicado %d vez/veces.\n", i, temp_arr[i]-1);
        }
    }

} 
