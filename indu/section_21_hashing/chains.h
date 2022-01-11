#ifndef Chains_h
#define Chains_h

#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H,int x)
{
    struct Node *t,*q=NULL,*p=*H;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(*H==NULL) //Si el nodo está vacio, entonces el insertado es el nodo.
    {
        *H=t;
    }
    else //Si no está vacio
    {
        while(p && p->data<x) //buscaq el puntero más pequeño
            {
                q=p;
                p=p->next;
            }

        if(p==*H) //Si es igual, lo metemos detras y nuestro nodo raiz para a ser t
            {       
                t->next=*H;
                *H=t;
            }
        else // si no el nodo t lo metemos entre medio
        {
            t->next=q->next;
            q->next=t;
        }
    }
}


struct Node *Search(struct Node *p,int key)
{
    while(p!=NULL) //Buscamos el nodo, si lo encontramos lo retornamos, si no retornamos NULL.
    {
        if(key==p->data)
        {
            return p;
        }

        p=p->next;
    }
    return NULL;
}


#endif /* Chains_h */
