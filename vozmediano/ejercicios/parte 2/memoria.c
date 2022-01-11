#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define clrscr() printf("\e[1;1H\e[2J")

void inicio();
int secs_dif();
int gen_random();
int series_iguales(int[], int[], int);


int main(){
    int time, n_serie = 0, serie[10], rand_n;
    int comp_serie[10];

    inicio();
    time = secs_dif();

    while(n_serie<10){
        rand_n = gen_random();
        serie[n_serie] = rand_n;
        printf("Memorice esta serie\n");
        for(int i=0; i<=n_serie; i++){
            printf("%i ", serie[i]);
        }

        printf("\n");
        sleep(time);
        clrscr();
        printf("Introduzca la serie que ha visto\n");

        for(int i=0; i<=n_serie; i++){
            scanf("%i", &comp_serie[i]);
        }

        if (!series_iguales(serie, comp_serie, n_serie)){
            printf("Se ha equivocado, el juego ha acabado\n");
            return 1;
        }
        n_serie++;
    }
    printf("¡Enhorabuena ha ganado!\n");
    return 0;
}


int series_iguales(int a[], int b[], int length){
    for(int i=0; i<=length; i++){
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}


void inicio(){
    printf("Este es un juego de memoria, usted debe mirar los números que aparecen\n en pantalla y después ingresarlos, si se equivoca pierde, si acierta habrá un número más\n en la serie hasta llegar a diez.\n\n ¡Vamos a comenzar!\n\n");
    printf("Elija un nivel de dificultad: Fácil / Medio / Difícil\n");
};


int secs_dif(){
    char dif[50];
    int opt_available = 0;


    while(opt_available == 0)
    {
        scanf("%s", dif);
        if(strcmp(dif, "Facil") == 0 || strcmp(dif, "Fácil") == 0 || strcmp(dif, "facil") == 0 || strcmp(dif, "facil") == 0){
                return 15;
                opt_available = 1;
        }

        if(strcmp(dif, "Medio") == 0 || strcmp(dif, "medio") == 0){
                return 10;
                opt_available = 1;
        }
         
        if(strcmp(dif, "Díficil") == 0 || strcmp(dif, "Dificil") == 0 || strcmp(dif, "dificil") == 0 || strcmp(dif, "díficil") == 0){
                return 2;
                opt_available = 1;
        }
        
        if(opt_available == 0){
            printf("La opción %s no se encuentra entre las disponibles, por favor introduzca una opción disponible.\n", dif);
        }
    }

    return 1;    
}


int gen_random(){
    srand(time(NULL));
    int n = rand()%3 + 1;
    return n;
}
