#include <stdio.h>
#include <malloc.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr);
void Append(struct Array *arr, int value);
void Insert(struct Array *arr, int idx, int value);

int main()
{
    struct Array arr={{2,3,4,5,6},10,5};

    Append(&arr, 10);
    Insert(&arr, 3, 20);

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


void Append(struct Array *arr, int value){
    if(arr->length < arr->size){
        arr->A[arr->length++] = value;
    }
}

void Insert(struct Array *arr, int idx, int value){
    if(idx>=0 && idx<=arr->length){
        for(int i=arr->length; i>idx; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[idx] = value;
        arr->length++;
    }
}
