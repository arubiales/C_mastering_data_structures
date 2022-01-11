#include <stdio.h>
#include <string.h>

is_ordenado(char *);

int main(){
    char orden[100] = "ABCDE", no_orden[100] = "CDAEFG";

    is_ordenado(orden);
    is_ordenado(no_orden);


}


is_ordenado(char *string){
    for(int i =0; i<strlen(string)-1; i++){
        if(string[i] > string[i+1]){
            printf("\nEl string está desordenado");
            break;
        }
    }
}
