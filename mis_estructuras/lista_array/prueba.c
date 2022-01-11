#include "List.h"



int main(){
    list *lista;
    int prueba;

    lista = init(10);





    // Hacemos pruebas

    for(int i=0; i<10; i++){
        lista->nd[i].data = i*5;
        lista->length++;
        lista->mem_available -= sizeof(Node);
        printf("Datos: %d ", lista->nd[i].data);
        printf("Actual: %p ", lista->nd[i].ptr);
        printf("Back: %p ", lista->nd[i].back);
        printf("Next: %p\n", lista->nd[i].next);
    }

    printf("%d\n", lista->size);
    printf("%d\n", lista->length);

    //Destruir
    // destruct(lista);

    printf("%d", lista->size);

    // printf("%d", lista->nd[0].data);

    printf("\n  %d\n", lista->nd[3].data);

    // swap(lista, 0, 1);

    for(int i=0; i<10; i++){    
        lista->nd[i].data = i*5;
        printf("Datos: %d ", lista->nd[i].data);
        printf("Actual: %p ", &lista->nd[i]);
        printf("Back: %p ", lista->nd[i].back);
        printf("Next: %p\n", lista->nd[i].next);
    }

    printf("\nInicio: %p\n", lista->start);
    printf("Fin: %p", lista->end);


    printf("SWAPS\n");
    show(*lista);
    swap(lista, 2, 4);
    show(*lista);
    swap(lista, 3, 5);
    show(*lista);
    // swap(lista, 3, 5);
    // show(*lista);

    printf("\nREVERSE\n");
    reverse(lista);
    show(*lista);







    return 0;
}
