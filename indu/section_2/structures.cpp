#include <stdio.h>
#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
} r2, r3; // Variables globales 

int main(){

    struct Rectangle r1={10,5};

    cout<<sizeof(r1)<<endl;

    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;

    r1.length = 3;
    r1.breadth = 99;

    cout<<r1.breadth<<endl;

    return 0;
}
