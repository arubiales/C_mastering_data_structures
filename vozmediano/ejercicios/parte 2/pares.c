#include <stdio.h>


int main(){
    int a;

    printf("Ingresa un número para calcular los pares hasta el\n");
    scanf("%i", &a);

    for(int i=0; i<a; i++){
        if(i%2 ==0){
            printf("%i ", i);
        }
    }


    return 0;
}
