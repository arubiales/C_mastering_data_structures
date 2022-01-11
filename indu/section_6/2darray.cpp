#include <stdio.h>
#include <stdlib.h>


int main(){

    //Vamos a ver 3 metodos

    // 1. Creamos un array en el stack:
    int A[3][4] = {
        {1,2,3,4},
        {2,4,6,8},
        {1,3,5,7},
    };

    // 2. forma creamos un vector al que le vamos a introducir vectores
    int *B[3];

    B[0] = (int *)malloc(4*sizeof(int));
    B[1] = (int *)malloc(4*sizeof(int));
    B[2] = (int *)malloc(4*sizeof(int));

    // 3. creamos un puntero de punteros e incializmos los subpunteros
    int **C;
    C = (int **)malloc(3*sizeof(int *));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));


    printf("A\n\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("B\n\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("C\n\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }


    return 0;
}
