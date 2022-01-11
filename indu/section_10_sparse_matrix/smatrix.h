#include <stdio.h>
#include <stdlib.h>


typedef struct sNode
{
    int row;
    int col;
    int data;
} Node;


typedef struct sSparse
{   
    int nrows;
    int ncols;
    Node *element;
    int nelements;
} SparseMatrix;


SparseMatrix * __init__(int nrows, int ncols, int nelements)
{
    SparseMatrix *smatrix = (SparseMatrix *)malloc(sizeof(SparseMatrix)); 
    smatrix->nrows = nrows;
    smatrix->ncols = ncols;
    smatrix->element =  (Node *)malloc(nelements*sizeof(Node));
    smatrix->nelements = nelements;
    return smatrix;
}


void show(SparseMatrix *smatrix)
{
    int i=0, j=0, k=0;
    
    printf("\n");

    for(i; i<smatrix->nrows; i++){
        for(j=0; j<smatrix->ncols; j++){
            if(smatrix->element[k].row == i && smatrix->element[k].col == j){
                printf("%d ", smatrix->element[k++].data);
            }
            else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }

    printf("\n");
}


SparseMatrix * sum(SparseMatrix *sm1, SparseMatrix *sm2){
    SparseMatrix *sm_sum;
    int i=0, j=0, k=0;

    if(sm1->nrows != sm2->nrows && sm1->ncols != sm2->ncols){
        printf("Error, las matrices deben ser de las mismas dimensiones para poder sumar");
        exit(1);
    }

    sm_sum = (SparseMatrix *)malloc(sizeof(SparseMatrix));
    sm_sum->element = (Node *)malloc(sm1->nelements*sizeof(Node));

    while(i<sm1->nelements && j<sm2->nelements){
        if(sm1->element[i].row < sm2->element[j].row){
            sm_sum->element[k++] = sm1->element[i++];
        }
        else if(sm1->element[i].row > sm2->element[j].row ){
            sm_sum->element[k++] = sm2->element[j++];
        }
        else{
            if(sm1->element[i].col < sm2->element[j].col){
                sm_sum->element[k++] = sm1->element[i++];
            }
            else if(sm1->element[i].col > sm2->element[j].col ){
                sm_sum->element[k++] = sm2->element[j++];
            }
            else{
                sm_sum->element[k] = sm1->element[i];
                sm_sum->element[k++].data = sm1->element[i++].data + sm2->element[j++].data;
            }
        }
    }

    for(;i<sm1->nelements; i++){
        sm_sum->element[k++] = sm1->element[i];
    }
    
    for(;j<sm2->nelements; j++){
        sm_sum->element[k++] = sm2->element[j];
    }

    sm_sum->nrows=sm1->nrows;
    sm_sum->ncols=sm1->ncols;
    sm_sum->nelements=k;

    return sm_sum;
}
