#include "lista.h"

int main(){
    ListaLigada * lista = obtenerNuevaListaLigada();
    Nodo *a = getNode(1);
    Nodo *b = getNode(2);
    Nodo *c = getNode(3);
    Nodo *d = getNode(4);

    add(lista, a);
    add(lista, b);
    add(lista, c);
    add(lista, d);

    printf("Read: %d", read(lista, 1)->valor);
    update(lista, 1, 9);
    printf("\nRead: %d\n", read(lista, 1)->valor);

    removed(lista, 1);

    printf("Valor una vez borrad %d\n", read(lista, 1)->valor);
    
    free(lista);

    return 0;
}


