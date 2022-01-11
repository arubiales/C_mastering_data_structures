#include <stdio.h>

#define SIZE 10


int __hash__(int key)
{
    return key%SIZE;
}

int probe(int H[], int key){
    int index=__hash__(key);
    int i=0;

    while(H[(index+i)%SIZE] !=0){
        i++;
    }
    return (index+i)%SIZE;
}

void Insert(int H[], int key)
{
    int index= __hash__(key);

    if(H[index]!=0){
        index=probe(H, key); //La función que checkea el espacio libre
    }
    H[index] = key;
}

int Search(int H[], int key)
{
    int index=__hash__(key);
    int i =0;


    while(H[(index+i)%SIZE] != key ){
        i++;
    }

    return (index+i)%SIZE;
}

int main()
{
    int HT[10]={0};

    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);
    //Vemos esto en el debuging

    printf("Key encontrada en: %d\n", Search(HT, 35));

    return 0;
}
