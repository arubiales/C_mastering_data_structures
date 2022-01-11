#include <stdio.h>
#include <string.h>


void palindromo(char string[]);

int main(){
    char pal[] = "sabas", no_pal[] = "que pasa";

    palindromo(pal);
    palindromo(no_pal);

}


void palindromo(char string[]){
    int length= strlen(string), flag=0;

    for(int i=1; i<length; i++){
        if(string[i-1] != string[length-i]){
            flag=1;
            break;
        }
    }
    fflush(stdout);
    fflush(stdin);
    if(flag){
        printf("\n %s NO es palindromo", string);
    }else{
    printf("\n %s es palindromo", string);
    }

}
