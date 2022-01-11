#include <stdio.h>


int main(){
    int array[10]={6,3,8,10,16,7,5,2,9,14};
    int n_buscar = 10;
    int n_temp=0;

    for(int i=0; i<10-1; i++){
        n_temp = 10-array[i] ;
        if(n_temp == 0){
            printf("%d\n", n_buscar);
        } else{
            for(int j=i+1; j<10; j++ ){
                if(array[j] == n_temp){
                    printf("%d\n", array[j]);
                }
            }
        }
    }


    return 0;
}
