#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;

    p=(int *)malloc(5*sizeof(int));
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;

    //Creamos un array de 10 en el que vamos a realocar
    q=(int *)malloc(10*sizeof(int));
    
    //Realocamos
    for(int i=0; i<5; i++){
        q[i] = p[i];
    }

    //Apuntamos con p a q y despues borramos q
    free(p);
    p = q;
    q = NULL;

    for(int i=0; i<5; i++){
        printf("%d \n", p[i]);
    }

    return 0;
}
