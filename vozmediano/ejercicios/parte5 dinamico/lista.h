#include <stdio.h>
#include <stdlib.h>


struct s_Nodo{
    int dato;
    struct s_Nodo *siguiente;
};

typedef struct s_Nodo Nodo;

void insert(Nodo **primero, int v){
    Nodo *nuevo;
    
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = v;
    nuevo->siguiente = *primero;
    *primero = nuevo;   
}

int rm(Nodo **primero, int v){
    Nodo *anterior, *aux;
    
    int borrado = -1;

    anterior = *primero;
    while(anterior !=NULL){
        aux = anterior->siguiente;
        
        if((aux != NULL) && (aux->dato == v)){
            break;
        }
        anterior = anterior->siguiente;
    }

    if((anterior != NULL) && (aux != NULL)){
        anterior->siguiente = aux->siguiente;
        free(aux);
        borrado = 1;
    }

    return borrado;
}


void show(Nodo node){
    Nodo *aux = &node;
    printf("\n");
    do{
        printf("%d ", aux->dato);
        aux = aux->siguiente;
        if(aux->siguiente == NULL){
            printf("%d", aux->dato);
        } 
    }while(aux->siguiente != NULL);
    printf("\n");
}


int pop(Nodo **primero){
    Nodo *aux;
    int dato;

    aux = *primero;
    if(aux == NULL){
        return -1;
    }

    dato = (*primero)->dato;

    *primero = aux->siguiente;
    free(aux);
    return dato;
}
