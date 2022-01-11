#include "arbol.h"


int main(){
    Tree *a1;

    a1 = __init__(4);


    a1 = insert(a1, 2);
    a1 = insert(a1, 7);
    a1 = insert(a1, 10);
    a1 = insert(a1, 8);
    a1 = insert(a1, 0);
    a1 = insert(a1, 24);
    a1 = insert(a1, 12);


    printf("%d ", a1->data);
    // printf("%d ", a1->left->data);
    printf("%d ", a1->right->data);
    printf("%d ", a1->right->right->right->right->left->data);

    printf("\n%d", search(a1, 24)->data);
    search(a1, 89);


    // a1->left->data;

    // Inorder(a1);

    return 0;
}
