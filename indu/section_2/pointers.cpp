#include <iostream>
#include <stdio.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};



int main(){
    int a=10;
    int *p;
    p=&a;

    cout<<a<<endl;
    printf("using pointer %d %d", p, &a);


    int A[5]={2,3,4,5,6};
    int *b;
    b=A;

    for(int i=-1; i<5; i++){
        cout<<b[i]<<endl;
    }

    int *c;

    c = new int[5]; //creamos un array en el heap, es decir en la memoria fuera del programa
    c[0]=10; c[1]=15; c[2]=20; c[3]=25; c[4]=30;

    for(int i=0;i<5;i++){
        cout<<c[i]<<endl;
    }

    delete [] c; //En C++
    free(c); //En C

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;


    return 0;
}
