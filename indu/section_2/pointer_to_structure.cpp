#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct  Rectangle
{
    int length;
    int breadth;
};

int main()
{   
    Rectangle r={10, 5};
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    Rectangle *p=&r;

    cout<<p->length<<endl;
    cout<<p->breadth<<endl;


    //Lo creamos en el heap para C
    Rectangle *z;
    z = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    z->breadth = 2;
    z->length = 4;

    cout<<z->length<<endl;
    cout<<z->breadth<<endl;
    
    free(z);

    //LO creamos en C++
    struct Rectangle *v;
    v = new Rectangle;
    
    v->length = 100;
    v->breadth = 200;

    cout<<v->breadth<<endl;
    cout<<v->length<<endl;

    return 0;
}
