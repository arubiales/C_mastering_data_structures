#include <stdio.h>

void show(int **, int, int);

int main(){
    int matrix[10][10];

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            matrix[i][j] = -1;
        }
    }

    show(matrix, 10, 10);

    return 0;
}

void show(int **array, int idx_i, int idx_j){
    for(int i=0; i<idx_i; i++){
        for(int j=0; j<idx_j; j++){
            printf("%i ", array[i][j]);
        }
    printf("\n");
    }
}
