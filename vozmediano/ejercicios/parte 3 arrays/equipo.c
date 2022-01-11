#include <stdio.h>



struct equipo{
    char nombre[100];
    int jugados;
    int ganados;
    int empate;
    int perdidos;
    int puntos;
};

typedef struct equipo equipos;

int main(){

    equipos liga[10];
    

    liga[0].nombre = "Madrid";
    liga[1] = {"barsa", 44,5,6,7,3};

    printf("%s\n", Madrid.nombre);
    printf("%i\n", Madrid.jugados);
    printf("%i\n", Madrid.ganados);
    printf("%i\n", Madrid.empate);
    printf("%i\n", Madrid.perdidos);
    printf("%i\n", Madrid.puntos);
    
    return 0;
}
