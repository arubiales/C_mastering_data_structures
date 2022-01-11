#include <stdio.h>
#include <string.h>

int main(){
    char hola[] = "Hola mundo";

    for(int i=0; i<strlen(hola); i++){
        if(hola[i] == 'a' || hola[i] == 'e' || hola[i] == 'i' ||
           hola[i] == 'o' || hola[i] == 'u'){
               hola[i] = '*';
        }
    }

    printf("%s", hola);
    return 0;
}
