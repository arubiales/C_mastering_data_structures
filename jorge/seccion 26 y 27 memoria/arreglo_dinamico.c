#include <stdio.h>
#include <stdlib.h>


int * reserve(int *, int);
void reserve2(int **, int);

int main(){
    int size=10, *p;

    // p = reserve(p, size);
    reserve2(&p, size);

    for(int i=0; i<size; i++){
        p[i] = i;
    }

    for(int i=0; i<size; i++){
        printf("%d ", p[i]);
    }

    return 0;
}


int * reserve(int *p, int size){
    p = (int *)malloc(size*sizeof(int));
    return p;
}


void reserve2(int **p, int size){
    *p = (int *)malloc(size*sizeof(int));    
}
