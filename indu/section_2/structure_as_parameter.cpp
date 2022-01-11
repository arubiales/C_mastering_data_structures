#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
    int lenght;
    int breadth;
};

void fun(struct Rectangle r)
{
    r.lenght = 20;
    cout<<"Length"<<r.lenght<<endl<<"Breadth"<<r.breadth<<endl;
}

void fun_pointer(struct Rectangle *p)
{
    p->lenght=20;
    cout<<"Length"<<p->lenght<<endl<<"Breadth"<<p->breadth<<endl;
}

struct Rectangle *fun_create()
{
    struct Rectangle *p;
    // p = new Rectangle; //En c++
    p=(struct Rectangle*)malloc(sizeof(struct Rectangle)); //en C
    p->lenght=2;
    p->breadth=2;
    
    return p;
}

int main()
{
    struct Rectangle r={10,5};
    struct Rectangle *ptr;

    fun(r);
    printf("Length %d \nBreadth %d\n", r.lenght, r.breadth);

    fun_pointer(&r);
    printf("Length %d \nBreadth %d\n", r.lenght, r.breadth);

    ptr = fun_create();
    cout<<"Length "<<ptr->lenght<<endl<<"Breadth "<<ptr->breadth<<endl;

    return 0;
}
