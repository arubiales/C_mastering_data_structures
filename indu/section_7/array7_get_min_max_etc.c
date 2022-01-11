#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr);
void Append(struct Array *arr, int value);
void Insert(struct Array *arr, int idx, int value);
void Delete(struct Array *arr, int idx);
int LinearSearch(struct Array *arr, int key);
int BinarySearch(struct Array *arr, int key);
int Get(struct Array *arr, int idx);
void Set(struct Array *arr, int idx, int value);
int Max(struct Array *arr);
int Min(struct Array *arr);
int Sum(struct Array *arr);
float Avg(struct Array *arr);
void Reverse(struct Array *arr);
void ReverseSwap(struct Array *arr);
int IsSorted(struct Array *arr);
void Sorted(struct Array *arr);
void InsertSorted(struct Array *arr, int value);




int main()
{
    struct Array arr={{2,3,4,5,6},10,5};

    Append(&arr, 10);
    Insert(&arr, 3, 20);
    Delete(&arr, 1);

    // BinarySearch(&arr, 0, 5, 20);
    // printf("%d ", arr.length);
    printf("Encontrado en posición: %d", BinarySearch(&arr, 20));
    printf("\nElemento 1: %d", Get(&arr, 1));
    Set(&arr, 4, 100);
    printf("\nEl elemento máximo es: %d", Max(&arr));
    printf("\nEl elemento mínimo es: %d", Min(&arr));
    printf("\nLa suma de todos los elementos es: %d", Sum(&arr));
    printf("\nLa media de todos los elementos es: %f", Avg(&arr)); 
    Display(arr);
    Reverse(&arr);

    printf("\nRevertido");
    Display(arr);

    printf("\nRevertido con swap");
    ReverseSwap(&arr);
    Display(arr);

    printf("Is sort: %i", IsSorted(&arr));
    Sorted(&arr);
    Display(arr);

    InsertSorted(&arr, 3);
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


void Delete(struct Array *arr, int idx){
    if(idx >= 0 && idx <= arr->length){
        for(int i =idx; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}


int LinearSearch(struct Array *arr, int key){
    for(int i=0; i<arr->length; i++){
        if(key==arr->A[i]){
            return i;
        }
    }
    return -1; 
}


int BinarySearch(struct Array *arr,int key){
    int mid, n_mid, low = 0, high=arr->length-1;

    while(low <=high){
        mid = (low+high)/2;
        n_mid = arr->A[mid];

        if(n_mid == key){
            return mid;
        } else if(n_mid > key){
            high = mid;
        } else{
            low = mid;
        }
    }
    return -1;
}

int Get(struct Array *arr, int idx){
    if(idx < arr->length && idx >= 0){
        return arr->A[idx];
    }
    return -1;
}


void Set(struct Array *arr, int idx, int value){
    if(idx >= 0 && idx < arr->length){
        arr->A[idx] = value;
    }
}


int Max(struct Array *arr){
    int max = arr->A[0];
    for(int i=1; i<arr->length; i++){
        if(arr->A[i] > max){
            max = arr->A[i];
        }
    }
    return max;
}

int Min(struct Array *arr){
    int min = arr->A[0];
    for(int i=1; i<arr->length; i++){
        if(arr->A[i] < min){
            min = arr->A[i];
        }
    }
    return min;
}


int Sum(struct Array *arr){
    int sum=0;
    for(int i=0; i<arr->length; i++){
        sum += arr->A[i];
    }
    return sum;
}

float Avg(struct Array *arr){
    return (float)Sum(arr) / arr->length;
}


void Reverse(struct Array *arr){
    int *B;
    int i, j;

    B = (int *)malloc(arr->length*sizeof(int));

    for(i=arr->length-1, j=0; i>=0; i--, j++){
        B[j] = arr->A[i];
    }

    for(int i=0; i<arr->length; i++){
        arr->A[i] = B[i];
    }
    free(B);
}


void ReverseSwap(struct Array *arr){
    int i, j, aux;
    for(i=0, j=arr->length-1; i<j; i++, j--){
        aux = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = aux;
    }
}


int IsSorted(struct Array *arr){
    for(int i=0; i<arr->length-1; i++){
        if(arr->A[i] > arr->A[i+1]){
            return 0;
        }
    }
    return 1;
}


void Sorted(struct Array *arr){
    int aux;
    for(int i=1; i<arr->length; i++){
        for(int j=0; j<arr->length-i; j++){
            if(arr->A[j] > arr->A[j+1]){
                aux = arr->A[j];
                arr->A[j] = arr->A[j+1];
                arr->A[j+1] = aux;
            }
        }
    }
}


void InsertSorted(struct Array *arr, int value){

    if(!IsSorted(arr)){
        Sorted(arr);
    }

    int i=0;
    while(arr->A[i] < value){
        i++;
    }

    for(int x=arr->length-1; x>i-1; x--){
        arr->A[x+1] = arr->A[x];
    }
    arr->length++;

    arr->A[i] = value;
}
