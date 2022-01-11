#include <stdlib.h>
#include <stdio.h>
#include "chains.h"




int __hash__(int key)
{
    return key%10;
}

void Insert(struct Node *H[], int key)
{
    int index=__hash__(key);
    SortedInsert(&H[index], key);
}


int main()
 {
     struct Node *HT[10];
     struct Node *temp;
     int i;

     for(i=0; i<10; i++){
         HT[i]=NULL;
     }

     Insert(HT, 12);
     Insert(HT, 22);
     Insert(HT, 42);

    temp = Search(HT[__hash__(22 )], 22);

    printf("%d", temp->data);

    return 0;
}
