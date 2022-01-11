#include "lista.h"

int main(){

    Nodo *Node=NULL, *aux;
    int bor;

    insert(&Node, 5);
    insert(&Node, 6);
    insert(&Node, 7);
    insert(&Node, 8);
    insert(&Node, 9);

    bor = rm(&Node, 7);

    show(*Node);

    printf("\n%d ", pop(&Node));
    printf("\n%d ", pop(&Node));
    // printf("\n%d ", pop(&Node));

    show(*Node);
    return 0;
}
