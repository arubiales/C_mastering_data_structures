#include <stdio.h>
#include <stdlib.h>


typedef struct lower_matrix{
    int *data;
    int n;
} LowerMatrix;


void init(LowerMatrix *, int);
int _locate(LowerMatrix *, int, int);
void set(LowerMatrix *, int, int, int);
int get(LowerMatrix *, int, int);
void show(LowerMatrix);

int main(){
    LowerMatrix lm;
 
    
    init(&lm, 3);

    set(&lm,0,0,3);
    set(&lm,2,0,2);
    set(&lm,2,1,7);
    set(&lm,2,2,2);
    set(&lm,3,0,1);


    show(lm);

}


int _locate(LowerMatrix *lm, int i, int j){
    return lm->n*(j-1)+(j-2)*(j-1)/2+i-j;
}


void init(LowerMatrix *lm, int size){
    lm->n = size;

    lm->data = (int *)malloc(lm->n*(lm->n+1)/2*sizeof(int));
}

void set(LowerMatrix *lm, int i, int j, int value){
    if(i>=j){
        lm->data[_locate(lm, i, j)] = value;
    }
}


int get(LowerMatrix *lm, int i, int j){
    if(i>=j){
        return lm->data[_locate(lm, i, j)];
    }
    else{
        return 0;
    }
}


void show(LowerMatrix lm){
    for(int i=1; i<=lm.n; i++){
        for(int j=1; j<=lm.n; j++){
            if(i>=j){
                printf("%d ", lm.data[_locate(&lm, i, j)]);
            }
            else{
                printf("%i ", 0);
            }
        }
    printf("\n");
    }
}





// #include <stdio.h>
// #include <stdlib.h>

// struct Matrix{
//     int *A;
//     int n;
// };

// void Set(struct Matrix *m,int i,int j,int x){
//     if(i>=j)
//         m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
// }

// int Get(struct Matrix m,int i,int j){
//     if(i>=j)
//         return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
//     else
//         return 0;
// }


// void Display(struct Matrix m){
//     int i,j;
//     for(i=1;i<=m.n;i++){
//         for(j=1;j<=m.n;j++){
//             if(i>=j)
//             printf("%d ",m.A[m.n*(j-1)+
//             (j-2)*(j-1)/2+i-j]);
//             else
//             printf("0 ");}
//         printf("\n");
//     }
// }



// int main()
// {
//     struct Matrix m;
//     int i,j,x;
//     m.n = 3;
//     m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));


//     Set(&m,1,0,3);
//     Set(&m,1,1,2);
//     Set(&m,2,0,7);
//     Set(&m,2,1,2);
//     Set(&m,2,2,1);

//     printf("\n\n");
//     Display(m);
//     return 0;
// }
