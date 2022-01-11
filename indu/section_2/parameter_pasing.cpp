#include <iostream>

using namespace std;

int add(int a, int b)
{
    int c;
    c = a+b;
    return c;
}

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x = *y;
    *y = temp;
}

void swap2(int &x, int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}

int main()
{
    int num1=10, num2=15, sum;

    //paso de parámetros
    sum = add(num1, num2);
    cout<<"sum is: "<<sum<<endl;
    cout<<"num1 is: "<<num1<<endl;

    //paso por referencia
    swap(&num1, &num2);
    cout<<"num1 ahora es: "<<num1<<endl;
    cout<<"num2 ahora es: "<<num2<<endl;

    //paso por deferencia
    swap(num1, num2);
    cout<<"num1 ahora es: "<<num1<<endl;
    cout<<"num2 ahora es: "<<num2<<endl;

    return 0;
}
