#include <stdio.h>
#include <stdlib.h>


typedef struct Cola{
    int primero;
    int ultimo;
    int *array;
    int size;
} Cola;

Cola init(int);
void clean(Cola *);
void append(Cola *, int);

// Todo está visto desde la perspectiva de salir.
Cola init(int size){
    Cola c;
    c.array = (int *)malloc(size*sizeof(int));
    if(c.array == NULL){
        printf("No se a podido reservar el espacio en memoria");
        exit(1);
    }
    c.size=size;
    c.primero = 1;
    c.ultimo = 0;
    return c;
}

void clean(Cola *c){
    free(c->array);
    c->primero = 1;
    c->ultimo = 0;
    c->size = 0;
}

int is_empty(Cola c){
    if(c.primero == c.ultimo+1){
        return 1;
    }
    return 0;
}


void append(Cola *c, int value){
    c->array[c->ultimo++] = value;
}

int pop(Cola *c){
    if(is_empty(*c)){
        printf("La cola ya esta vacia");
    } else{
        int aux = c->array[c->primero-1];
        c->primero++;
        if(c->primero == c->ultimo+1){
            *c = init(c->size);
        }
        return aux;
    }
}


int first(Cola c){
    c.primero++;
    return c.array[c.primero-1];
}
