#include <stdio.h>
#include <time.h>

int main(){
    int num;

    srand(time(NULL));

    num = 1 + rand()%((10-1)-1);

    printf("%d", num);    

    return 0;
}
