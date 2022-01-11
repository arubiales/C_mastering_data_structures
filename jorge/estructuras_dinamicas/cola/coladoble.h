#include <stdio.h>
#include <stdlib.h>


typedef struct Cola{
    int primero;
    int ultimo;
    int tamano;
    int disponibles;
    int *array;
}Cola;

Cola init(int tamano){
    Cola c;
    c.primero=1;
    c.ultimo=0;
    c.tamano = tamano;
    c.disponibles = tamano;
    c.array = (int *)calloc(c.tamano, sizeof(int));
    return c;
}

int is_empty(Cola c){
    if(c.primero == c.ultimo+1 && c.disponibles == c.tamano){
        return 1;
    }
    return 0;
}

void appendleft(Cola *c, int value){
    if(c->disponibles == 0){
        printf("La cola está llena");
    } else{
        c->disponibles--;
        c->ultimo = (c->ultimo%c->tamano)+1;  //esto es para saber que no nos pasamos del último elemento
        c->array[c->ultimo-1] = value;
    }
}

void appendright(Cola *c, int value){
    if(c->ultimo==0){
        appendleft(c, value);
    } else{
        if(c->disponibles == 0){
            printf("La cola está llena");
        } else{
            if(c->primero == 1){
                c->primero += c->tamano-1;
                c->array[c->primero-1] = value;
                c->disponibles--;
            } else {
                c->primero = (c->primero + c->tamano) % ((c->tamano)+1);
                c->array[c->primero-1] = value;
                c->disponibles--;
            }
        }
    }
}


int popright(Cola *c){
    if(is_empty(*c)){
        printf("La cola esta vacia");
    } else {
        c->disponibles++;
        int aux = c->array[c->primero-1];
        c->array[c->primero-1] = 0;
        if(c->primero != c->ultimo){
            c->primero = (c->primero%c->tamano)+1;
        } else {
            c->primero++;
        } if(c->primero==c->ultimo+1){
            *c = init(c->tamano);
        }
        return aux;
    }
}

int popleft(Cola *c){
    if(is_empty(*c)){
        printf("La cola esta vacia");
    } else{
        c->disponibles++;
        int aux = c->array[c->ultimo-1];
        c->array[c->ultimo-1] = 0;
        c->ultimo--;
    

        if(c->ultimo == 0){
            if(c->primero == c->ultimo+1){
                *c = init(c->tamano);
            } else{
                c->ultimo += c->tamano;
            }
        }
        if(c->primero == c->ultimo+1){
            *c = init(c->tamano);
        }
        return aux;
    }
}

void show(Cola c){  
    for(int i=0;i<c.tamano; i++){
        printf("Posición %d \t valor %d \n", i+1, c.array[i]);
    }
}
