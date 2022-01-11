#include <stdio.h>

void input_n(int *);
float mean(int *array);
void show(int *array);
void upper_n(int *array, float n);
void lower_n(int *array, float n);

int main(){
    int array[10];
    float media;

    input_n(array);
    media = mean(array);

    printf("La media es: %f\n", media);

    upper_n(array, media);
    
    lower_n(array, media);

    return 0;
}


void input_n(int *array){

    printf("Por favor ingrese 10 números\n ");

    for(int i=0; i<10; i++){
        printf("Número %i:\n", i);
        scanf("%i", &array[i]);
    }
    printf("\n");
}

float mean(int *array){
    int sum = 0;

    for(int i=0; i<10; i++){
        sum += array[i];
    }

    return sum / 10;
}


void upper_n(int *array, float n){
    printf("Los número que están por encima de la media son\n");

    for(int i=0; i<10; i++){
        if(array[i] > n){
            printf("%i ", array[i]);
        }
    }
    printf("\n");
}


void lower_n(int *array, float n){
    printf("Los número que están por encima de la media son\n");

    for(int i=0; i<10; i++){
        if(array[i] < n){
            printf("%i ", array[i]);
        }
    }
    printf("\n");
}

