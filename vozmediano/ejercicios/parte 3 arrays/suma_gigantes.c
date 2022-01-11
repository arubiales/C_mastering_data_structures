#include <stdio.h>

void show(int *, int);
void randint_vec(int *, int);
void sum_big_nbr(int *, int *, int, int, int*);

int main(){
    int size= 1000;
    int n1[size], n2[size], sum_array[size+1];
    
    randint_vec(n1, size);
    randint_vec(n2, size);

    show(n1, size);
    show(n2, size);

    sum_big_nbr(n1, n2, size, size, sum_array);
    show(sum_array, size+1);



    return 0;
}

void randint_vec(int *array, int size){
    for(int i=0; i<size; i++){
        array[i] = rand() %10;
    }
}

void show(int *array, int size){
    for(int i=0; i<size; i++){
        printf("%i ", array[i]);
    }
    printf("\n");
}

void sum_big_nbr(int *array1, int *array2, int size1, int size2, int *sum_array){
    int llevada=0, bigger_size, temp_sum;

    if(size1 >= size2){
        bigger_size = size1;
    }else{
        bigger_size = size2;
    }

    for(int i=bigger_size+1; i>=0; i--){
        temp_sum = array1[i-1] + array2[i-1];
        if(llevada>0){
            temp_sum += llevada;
        }

        if(temp_sum>=10){
            llevada = 1;
            temp_sum = temp_sum - 10;
        } else{
            llevada = 0;
        }
        sum_array[i] = temp_sum;
    }

}
