#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char *cad = "20";
    char *cad2 = "22.2123";
    int valor;
    float valor2;

    valor = atoi(cad);
    printf("Numero entero: %i", valor);
    printf("\n%i", valor +5);

    valor2 = atof(cad2);
    printf("\nNúmero flotante: %.2lf", valor2);
    printf("\n%f", valor2 + 5);

    return 0;
}
