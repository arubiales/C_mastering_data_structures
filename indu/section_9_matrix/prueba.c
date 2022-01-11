#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int *A;
    int n;
};

void Set(struct Matrix *m,int i,int j,int x){
    if(i>=j)
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
}

int Get(struct Matrix m,int i,int j){
    if(i>=j)
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    else
        return 0;
}


void Display(struct Matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i>=j)
            printf("%d ",m.A[m.n*(j-1)+
            (j-2)*(j-1)/2+i-j]);
            else
            printf("0 ");}
        printf("\n");
    }
}



int main()
{
    struct Matrix m;
    int i,j,x;
    m.n = 3;
    m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));


    Set(&m,1,1,2);
    Set(&m,2,0,7);
    Set(&m,2,1,2);
    Set(&m,2,2,1);

    printf("\n\n");
    Display(m);
    return 0;
}
