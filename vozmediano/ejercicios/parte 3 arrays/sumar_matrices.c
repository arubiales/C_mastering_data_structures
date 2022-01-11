#include <stdio.h>

int main(){

    int mat1[3][3] = {1,2,1,2,1,2,1,2,1}, mat2[3][3] = {1,1,1,2,2,2,3,3,3}, mat_suma[3][3];
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            mat_suma[i][j] = mat1[i][j] + mat2[i][j];
            printf("%i ", mat_suma[i][j]);
        }
    printf("\n");
    }
    return 0;
}
