#include <stdio.h>

void input_n(int *array);
void sum_by_sign(int *array);

int main(){
    int array[10];

    input_n(array);
    sum_by_sign(array);

    return 0;
}


void input_n(int *array){
    printf("Introduzca diez números:\n");
    for(int i=0; i<10; i++){
        printf("Número %i\n", i);
        scanf("%i", &array[i]);
    }
}

void sum_by_sign(int *array){
    int pos_sum=0, neg_sum=0;

    for(int i=0; i<10; i++){
        if(array[i] >0){
            pos_sum += array[i];
        }
        else{
            neg_sum+= array[i];
        }
    }

    printf("La suma de los negativos es: %i\n", neg_sum);
    printf("La suma de los negativos es: %i\n", pos_sum);
}
