#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int A[5];
    A[0]=12;
    A[1] = 15;
    A[2] = 25;

    int B[5]={1,2,3,4,5};
    int C[]={2,4,6,8,10,12,14,16};
    
    cout<<sizeof(A)<<endl;
    cout<<A[1]<<endl;
    printf("%d\n", A[2]);

    for(int i=0; i<8; i++)
    {
        cout<<C[i]<<endl;
    }

    for(int x:A)
    {
        cout<<x<<endl;
    }

    int n;
    cout<<"Enter size: ";cin>>n;
    
    int D[n];

    for(int x:D)
    {
        cout<<x<<endl;
    }

    return 0;
}
