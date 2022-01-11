#include <stdio.h>


int main(){
    int a, b;

    printf("Ingrese dos números\n");
    scanf("%i%i", &a, &b);

    if(a <b){
        printf("%i mayor que %i\n",b, a);
    }
    else{
        printf("%i menor que %i\n",a ,b);
    }

    return 0;
}
