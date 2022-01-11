#include <stdio.h>
#include <stdlib.h>

//BST
typedef struct stree{
    int data;
    struct stree *left;
    struct stree *right;
} Tree;


Tree * __init__(int value){
    Tree *ptr_tree = (Tree *)malloc(sizeof(Tree));


    ptr_tree->data = value;
    ptr_tree->left = NULL;
    ptr_tree->right = NULL;
    
    return ptr_tree;
}

Tree * search(Tree *tree, int value){
    Tree *aux = tree;
    Tree *aux_aux;

    while(aux != NULL){
        if(aux->data == value){
            return aux;
        } else if(aux->data > value){
            aux = aux->left;
        } else if(aux->data < value){
            aux = aux->right;
        }
    }

    printf("Error al buscar.");
    return NULL;
}


Tree * insert(Tree *tree, int value){
    Tree *aux = tree;
    Tree *aux_aux;
    Tree * to_insert = __init__(value);

    int side=0;

    if(tree->data > value){
        to_insert = __init__(value);
        to_insert->data = value;
        to_insert->right = tree;
        return to_insert;
    }

    while(aux != NULL){
        aux_aux = aux;
        if(value < aux->data){
            aux = aux->left;
        } else if(value > aux->data){
            aux = aux->right;
        }
    }

    if(value < aux_aux->data){
        aux_aux->left = to_insert;
    } else {
        aux_aux->right = to_insert;
    }

    return tree;
}

struct NOde *RInsert(Tree *tree, int key){
    if(key < tree->data){
        tree->left = RInsert()
    }
}


void delete(int value){

}


void Inorder(Tree *p) {
    if (p){
        Inorder(p->left);
        printf("%d ", p->data);
        Inorder(p->right);
    }
}









 

















































































