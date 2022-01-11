#include "list.h"


int main(){
    list *lst = __init__(4);



    appendright(lst, 5);
    appendright(lst, 6);
    appendright(lst, 7);
    appendright(lst, 8);
    appendright(lst, 9);
    appendright(lst, 10);
    appendright(lst, 11);
    appendright(lst, 12);
    appendright(lst, 13);
    appendright(lst, 14);
    appendleft(lst, 15);
    appendleft(lst, 16);
    show(*lst);
    printf("Poped right: %d\n", popright(lst));
    printf("Poped left: %d\n", popleft(lst));


    printf("Allocation before:  %d\n", lst->allocated);
    popright(lst); //NOTE: aquí quitamos otros
    printf("Allocation after: %d\n", lst->allocated);
    printf("Pop to check overallocation: %d\n", popright(lst));

    show(*lst);

    printf("Dato anterior end: %i\n", lst->end->back->data);

    printf("Inicio lista: %d\n", lst->start->data);
    printf("final lista: %d\n", lst->end->data);
    printf("Inicio puntero: %p\n", &lst->start);
    printf("Final puntero: %p\n", &lst->end);


    printf("Size: %d\n", lst->size);
    printf("Length: %d\n", lst->length);
    printf("Allocated: %d\n", lst->allocated);
    printf("Available: %d\n", lst->available);

    printf("Overallocated func: %d\n", _overallocate(10));


    printf("Suma de elementos: %d\n", sum(*lst));  
    printf("Maximo: %d\n", max(*lst));    
    printf("Minimo: %d\n", min(*lst));   
    printf("Buscar el 9: %d\n", search(*lst, 9));
    printf("Sacamos el indice 7: %i\n", get(*lst, 7));
    printf("insertamos en el 4: ");
    insert(lst, 4, 100);
    show(*lst); 
    printf("insertamos en el 0:\n");
    insert(lst, 0, 101);
    show(*lst);
    printf("insertamos en el ultimo: \n");
    appendright(lst, 13);
    insert(lst, 10, 102);
    insert(lst, 12, 103);
    show(*lst);

    delete(lst, 100);
    delete(lst, 101);
    // printf("El último es: %i\n", lst->end->data);
    show(*lst);
    delete(lst, 103);
    show(*lst);

    printf("Es ordenado: %i\n", is_sorted(*lst));
    popleft(lst);
    popright(lst);
    popright(lst);
    show(*lst);
    printf("Es ordenado: %i\n", is_sorted(*lst));
    return 0;
}




typedef struct node
{
    int value;
    struct node *next;
} Node;

Node *move_to_front (Node *head)
{
    Node *p, *q;
    if((head == NULL) || (head -> next == NULL))
         return head;
    q = NULL;
    p = head;

    while (p ->next != NULL){
        q=p;
        p = p->next;
    }


    return head;
}
