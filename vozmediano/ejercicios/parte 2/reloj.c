#include <stdio.h>
#include <unistd.h> 


struct Reloj
{
    long int hour, min, sec;
};

void update(struct Reloj *rj);


int main(){
    struct Reloj rj;

    printf("Inserte la hora\n");
    printf("Horas: \n"); scanf("%li", &rj.hour);
    printf("Minutos: \n"); scanf("%li", &rj.min);
    printf("Segundos: \n"); scanf("%li", &rj.sec);

    while(1){
        update(&rj);
        printf("La hora ahora es: %li:%li:%li\n", rj.hour, rj.min, rj.sec);
        sleep(1);
    }

    return 0;
}


void update(struct Reloj *rj){
    rj->sec+= 1;
    if(rj->sec>60){
        rj->min += 1;
        rj->sec = 0;
    }
    if(rj->min==60){
        rj->hour+= 1;
        rj->min = 0;
    }
    if(rj->hour>24){
        rj->hour = 0;
    }
}
