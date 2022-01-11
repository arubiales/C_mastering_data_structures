#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void par_impar(char[], int*);
void show();

int main(){
    int pares[100];
    int impares[100];
    int i=0, count=0;

    par_impar("par", pares);
    par_impar("impar", impares);

    show(pares);
    printf("\n");
    show(impares);

    return 0;
}


void par_impar(char option[100], int *vector){
    int i=0, count=0;

    printf("%s\n", option);
    if(strcmp(option, "par") == 0){
        printf("Entramos en el primerif\n");
        while(count<100){
            i++;
            if(i%2 == 0){
                vector[count] = i;
                count++;
            }
        }
    }

    else if(strcmp(option, "impar")== 0){
        printf("Entramos en el segundo if\n");
        while(count<100){
            i++;
            if(i%2 != 0){
                vector[count] = i;
                count++;
            }
        }
    }
}


void show(int *p_array){
    for(int i=0; i<100; i++){
        printf("%d ", p_array[i]);
    }
}


