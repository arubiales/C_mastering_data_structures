#include <stdio.h>


int primos(int);
void show(int *);

int pn1[10000], pn2[10000], pn[10000];

int main(){
    int n1, n2;


    printf("Por favor ingrese dos números para calcular el MCD\n");
    scanf("%i%i", &n1, &n2);

    pn1 = primos(n1);
    // pn2 = primos(n2);

    for(int i=0; i<3; i++){
        printf("%i ", pn1[i]);
    }

    // show(pn1);

    return 0;
}


int primos(int a){
    int counter_array = 0;
    int aux = a, i=1; 
    
    printf("Adios\n");
    while(a>1 && i < (a/2)){
        printf("h\n");
        i++;
        if(a%i==0){
            a = aux/i;
            printf("%i",i);
            array[counter_array] = i;
            counter_array++;
            i = 2;
        }
    }
    printf("Salimos\n");
    return *array;
}


void show(int *array){
    for(int i=0; i<2; i++){
        printf("%i ", array[i]);
    }
}
