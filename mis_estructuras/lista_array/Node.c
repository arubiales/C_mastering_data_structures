#include "Node.h"


int main(){
    Node *nd;

    nd = init(10);

    printf("Primer valor: %d\n", get(*nd));

    set(nd, 4);

    printf("Valor tras set: %d\n", get(*nd));

    destruct(nd);

    printf("Destruido: %d\n", get(*nd));
    return 0;
}
