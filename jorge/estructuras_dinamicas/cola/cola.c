#include "cola.h"

int main(){
     
     Cola col = init(5);

    printf("El primer elemento de la cola es: %d\n", col.primero);
    printf("El ultimo elemento de la cola es: %d\n", col.ultimo);
    printf("Está vacia la cola?: %d\n", is_empty(col));


    append(&col, 5);
    append(&col, 10);
    append(&col, 16);
    
    printf("Esta vacia la cola?: %d\n", is_empty(col));

    printf("Desencolamos: %d\n", pop(&col));
    printf("Desencolamos: %d\n", pop(&col));
    printf("Desencolamos: %d\n", pop(&col));

    printf("Ahora está vacia: %d\n", is_empty(col));

    return 0;
}
