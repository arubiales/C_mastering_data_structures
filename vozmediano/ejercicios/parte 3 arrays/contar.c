#include <stdio.h>
#include <string.h>

void contar(char []);


int main(){
    char hola[] = "HolA mundo";
    
    contar(hola);


    return 1;
}


void contar(char string[]){
    int a=0, e= 0, i= 0, o=0, u= 0;
    for(int i=0; i<strlen(string-1); i++){
 
        switch (string[i])
        {
        case 'a':
        case 'A':
            a +=1;
            break;
        case 'e':
        case 'E':
            e++;
            break;
        case 'i':
        case 'I':
            i++;
            break;
        case 'o':
        case 'O':
            o++;
            break;
        case 'u':
        case 'U':
            u++;
            break;
        default:
            break;
        }
    }

    printf("Tenemos:\na: %i\ne:%i\ni:%i\no:%i\nu:%i\n", a,e,i,o,u);
}
