#include <iostream>

using namespace std;

//Los arrays siempre son pasado por referencia
void fun(int A[])
{
    cout<<endl<<sizeof(A) / sizeof(int)<<endl;
}

void fun2(int A[])
{
    //al ser un paso por parámetro los arrays en funciones debe de hacerse los for así
    // no se puede hacer int x:A
    for(int i=0; i<5; i++){
        cout<<A[i]<<" ";
    }
}

//creamos un array de 7
int * fun3(int size)
{
    int *p;
    p=new int[size];

    for(int i=0;i<size;i++){
        p[i]=i+1;
    }

    return p;
}

int main()
{
    int A[]={2,4,6,8,10};
    int n=5;
    int *ptr;

    fun(A);
    fun2(A);
    cout<<sizeof(A) / sizeof(int)<<endl;
    for(int x:A){
        cout<<x<<" ";
    }

    cout<<endl;
    ptr = fun3(n);
    for(int i=0; i<n; i++){
        cout<<ptr[i]<<" ";
    }


    free(ptr);

    return 0;
}
