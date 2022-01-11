#include <stdio.h>
#include <string.h>


int main(){
    //CONCATENAR
    
    char Cadena1[] = "Jorge", Cadena2[]="Ricardo";
    char Final[50];

    strcat(Final, Cadena1);
    strcat(Final, "-");
    strcat(Final, Cadena2);
    printf("%s", Final);


    return 0;
}
