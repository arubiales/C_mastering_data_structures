#include "cola.h"


int main(){
    cola *start=NULL, *end;
    int v=0;



    insertar(&start, &end, 10);
    insertar(&start, &end, 15);
    insertar(&start, &end, 20);
    insertar(&start, &end, 25);
    insertar(&start, &end, 30);
    // show(start);

    v = sacar(&start, &end);
    v = sacar(&start, &end);
    printf("%d ", v);


    return 0;
}
