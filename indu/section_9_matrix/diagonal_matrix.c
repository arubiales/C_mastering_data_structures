#include <stdio.h>
#include <stdlib.h>

typedef struct matrix
{
    int A[10];
    int n;
} Matrix;

void Set(Matrix *, int, int, int);
int Get(Matrix *, int, int);
void Show(Matrix *);

int main(){
    Matrix m;
    m.n=5;

    // Set(&m, 0,0,2);

    Set(&m, 0,0,5);
    Set(&m, 1,1,2);
    Set(&m, 2,2,8);
    Set(&m, 3,3,2);
    Set(&m, 4,4,12);
    printf("Usamos Get: %i\n\n", Get(&m, 2, 2));
    Show(&m);

    return 0;
}


void Set(Matrix *m, int i, int j, int x){
    if(i==j){
        m->A[i]=x;
    }
}

int Get(Matrix *m, int i, int j){
    if(i==j)
        return m->A[i];
    else 
        return 0;
}

void Show(Matrix *m){
    int i, j;

    for(i=0; i<m->n; i++){
        for(j=0; j<m->n; j++){
            if(i==j)
                printf("%d ", m->A[i]);
            else
                printf("0 ");
        }
    printf("\n");
    }
}
