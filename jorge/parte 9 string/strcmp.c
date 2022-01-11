#include <stdio.h>
#include <string.h>

int main(){
    // Comparar dos cadenas de texto, si es igual devuelve 0
    // Si la cadena 2 es mayor que la 1 devuelve un número mayor que cero
    // Si la cadena 2 es menor que la uno, devuelve un número negativo

    char ClaveSecreta[] = "Contraseña";
    char UsuarioDigito[128];
    int intentosRestantes=3;

    do{
        printf("Escribe la clave secreta: ");
        fflush(stdin);
        scanf("%s", &UsuarioDigito);

        if(strcmp(ClaveSecreta, UsuarioDigito) == 0){
            printf("Bienvenido al sistema\n");
            break;
        } else {
            intentosRestantes--;
            printf("Clave Secreta Incorrecta, le quedan: %i intentos\n", intentosRestantes);
        } 
    } while(intentosRestantes > 0);



    return 0;
}
