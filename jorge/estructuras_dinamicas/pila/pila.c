#include "pila.h"


int main(){
    Pila p;

    p = init(3);

    append(&p, 5);
    append(&p, 10);
    append(&p, 15);
    append(&p, 20);
    printf("Hacemos pop el valor es:%i \n", pop(&p));
    printf("Y el top ahora es:%d \n", top(p));
    printf("y los sacamos y es:%i \n", pop(&p));
    printf("y volvemos a sacar ahora es:%i \n", pop(&p));
    pop(&p);
    destruct(&p);


    return 0;
}
