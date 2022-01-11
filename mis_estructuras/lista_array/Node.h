#include <stdio.h>
#include <stdlib.h>

struct s_Node{
    int data;
    // int idx;
    struct s_Node *next;
    struct s_Node *back;
    struct s_Node *ptr;
};

typedef struct s_Node Node;

int __get__(Node nd){
    return nd.data;
}

void __set__(Node *nd, int value){
    nd->data = value;
}

Node * __init__(int value){
    Node *nd;
    nd = (Node *)malloc(sizeof(Node));
    nd->data = value;
    return nd;
}

void __delete__(Node *nd){
    free(nd);
}

