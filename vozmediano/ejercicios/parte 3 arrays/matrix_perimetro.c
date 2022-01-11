#include <stdio.h>


int main(){
    int matrix[5][5], perimetro=0, firs_lateral=0, sec_lateral=4;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            matrix[i][j] = rand()%10;
            printf("%i ", matrix[i][j]);
        }
    printf("\n");
    }

    //Perimetro

    for(int j=0; j<5; j++){
        perimetro += matrix[firs_lateral][j];
        perimetro += matrix[j][firs_lateral];
    }

    for(int i=1; i<5; i++){
        perimetro += matrix[i][sec_lateral];
        perimetro += matrix[sec_lateral][i];
    }
    perimetro -= matrix[firs_lateral][firs_lateral];
    perimetro -= matrix[sec_lateral][sec_lateral];


    //Espiral
    int counter=25, fil=0, col=0, showed=0;

    while(counter > 0){
        printf("%i ", matrix[fil][col]);

        




        counter--;
    }
    
    printf("\nPerimetro: %i\n", perimetro);

    return 0;
}
