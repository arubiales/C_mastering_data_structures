#include <stdio.h>
#include <math.h>

int main(){
    char a = 'a';
    double total_mem = 0;
    const int used_mem = 55;
    double amount_register = 0.0;

    total_mem = 2 * pow(1000, 2);

    amount_register = total_mem / used_mem;

    printf("Tamaño char: %lu\n", sizeof(a));
    printf("Memoria total: %f\n", total_mem);
    printf("Amount of user can register: %f\n", amount_register);


    printf("%f\n", 2*8*pow(1024, 2));
    printf("%i\n", 128*8*1024);
    printf("%i\n", 94/2);
    return 0;
}
