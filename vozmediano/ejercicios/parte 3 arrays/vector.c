#include <stdio.h>
#include <math.h>

float media(int[]);
float std(int[]);
float sum(int[]);

int main(){

    int array[5] = {2,1,3,5,4};

    printf("Suma: %f\n", sum(array));
    printf("Media: %f\n", media(array));
    printf("std: %f\n", std(array));


    return 0;
}



float sum(int array[5]){
    float suma=0;

    for(int i=0; i<5; i++){
        suma += array[i];
    }
    
    return suma;
}

float media(int array[5]){
    float suma=0;

    suma = sum(array);

    return suma / 5;
}

float std(int array[5]){
    float mean, desviacion;

    mean = media(array);

    for(int i=0; i<5; i++){
        desviacion += fabs(array[i] - mean);
    }

    return desviacion;
}
