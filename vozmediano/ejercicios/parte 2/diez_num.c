#include <stdio.h>

int main(){
    int array[10], min=0, max=0, sum=0;
    float mean;
    printf("Introduzca 10 números por teclado\n");

    for(int i=0; i<10; i++){
        scanf("%i", &array[i]);
    }

    min = array[0];
    max = 0;

    for(int i=1; i<10; i++){
        sum += array[i];
        if(min > array[i]){
            min = array[i];
        }
        if(max < array[i]){
            max = array[i];
        }
    }

    mean = sum / 10;

    printf("El mínimo es: %i\n", min);
    printf("El máximo es: %i\n", max);
    printf("El valor médio es: %f\n", mean);



}
