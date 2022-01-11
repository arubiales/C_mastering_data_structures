#include <stdio.h>
#include <malloc.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr);

int main()
{
    struct Array arr={{1,2,3,4,5},5,5};

    Display(arr);

    return 0;
}


void Display(struct Array arr){
    int i;
    printf("\nElements are \n");
    for(i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

