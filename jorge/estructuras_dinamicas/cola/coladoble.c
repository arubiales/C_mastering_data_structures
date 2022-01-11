#include "coladoble.h"


int main(){
    Cola queue = init(10);

    appendleft(&queue, 10);
    appendleft(&queue, 20);
    appendleft(&queue, 30);
    appendleft(&queue, 40);
    appendleft(&queue, 50);
    appendright(&queue, 30);
    appendright(&queue, 70);

    show(queue);

    printf("Sacamos uno por la izquierda: %d\n", popright(&queue));
    printf("Sacamos uno por la izquierda: %d\n", popleft(&queue));

    show(queue);
    return 0;
}




