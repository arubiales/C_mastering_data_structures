#include <stdio.h>



int main(){
    int matrix[5][5];
    int sum=0, sup_diag=0;
    float mean=0.0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            matrix[i][j] = rand() % 10;
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }


    printf("\nMostramos diagonal principal\n");

    for(int i=0; i<5; i++){
        printf("%i ", matrix[i][i]);
    }
    printf("\n");

    for(int i=0; i<5; i++){
        for(int j=0; j+sup_diag<5; j++){
            sum += matrix[i][j+sup_diag];
            printf("%i ", sum);
        }
        sup_diag++;
    }

    printf("\nLa media es: %f\n", sum/15.0);

    return 0;
}
