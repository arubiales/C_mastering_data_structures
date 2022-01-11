#include <stdio.h>
#include <stdlib.h>

typedef struct Pila
{
    int tope;
    int *lista;
    int length;
}Pila;


Pila init(int);
int isempty(Pila);
void append(Pila *, int);
int pop(Pila *);
int top(Pila);


Pila init(int length){
    Pila p;
    p.tope = 0;
    p.length = length;
    p.lista = (int *)malloc(length*sizeof(int));
    if(p.lista==NULL){
        printf("No se ha podio reservar la memoria");
        exit(1);
    }
    return p;
}

void clear(Pila *p){
    free(p->lista);
    p->tope = 0;
    p->length = 0;
}


int isempty(Pila p){
    if(p.tope == 0){
        return 1;
    } 
    return 0;
}

void append(Pila *p, int value){
    if(p->tope < p->length){
        p->lista[p->tope++] = value;
    } else{
        printf("Se ha alcanzado el tope de memoria de la pila");
    }
}

int pop(Pila *p){
    if(isempty(*p)){
        printf("La pila esta vacia");
        return -1;
    } else{
        int aux = p->lista[--p->tope];
        return aux;
    }
}


int top(Pila p){
    if(isempty(p)){
        printf("La pila esta vacia");
        return -1;
    } else{
        return p.lista[--p.tope]; 
    }
}
