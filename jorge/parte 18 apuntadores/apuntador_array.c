/* Esto nos sirve para apuntar al principio de un array
y así no nos hace falta pasar el tamaño*/

#include <stdio.h>



int main(){
    int array[5] = {1,2,3,4,5};

    int *apuntadorArray = &array[0];

    while (*apuntadorArray != NULL)
    {
        printf("\n %d", *apuntadorArray);
        apuntadorArray++;
    }

    return 0;
}
  