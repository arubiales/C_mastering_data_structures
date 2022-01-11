#include <iostream>
#include "arraycpp.h"

using namespace std;


int main(int argc, char const *argv[])
{
    Array n(20);
    Array n2(20);

    cout<<"Creamos el array\n";
    n.append(2);
    n.append(4);
    n.append(6);
    n.append(8);
    n.append(10);
    n.print();

    n2.append(1);
    n2.append(3);
    n2.append(5);
    n2.append(7);
    n2.append(9);
    
    cout<<"\nHacemos un pop\n";
    n.pop();
    n.print();

    cout<<"\nHacemos delete\n";
    n.del(0);
    n.print();
    
    cout<<"\nHacemos insert\n";
    n.insert(1, 21);
    n.print();
    
    cout<<"\nHacemos search:\n";
    cout<<n.search(6);
    
    cout<<"\nHacemos get:\n";
    cout<<n.get(3);

    cout<<"\nHacemos el max:\n";
    cout<<n.max();
    
    cout<<"\nHacemos el min:\n";
    cout<<n.min();

    cout<<"\nHacemos sum:\n";
    cout<<n.sum();

    cout<<"\nHacemos avg:\n";
    cout<<n.avg();

    cout<<"\nHacemos reverse:\n";
    n.reverse();
    n.print();

    cout<<"\nHacemos el concat:\n";
    n.concat(n2);
    n.print();

    return 0;
}



