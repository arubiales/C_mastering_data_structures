#include <stdio.h>
#include <stdlib.h>


struct s_cola
{
    int data;
    struct s_cola *ptr;
};


typedef struct s_cola cola;





// int display(cola **start, cola **end){
//     cola *aux;
//     int v;

//     aux = *start;
//     if(aux == NULL){
//         return -1;
//     }

//     *start = aux->ptr;

//     v = aux->data;

//     // free(aux);
//     if(*start==NULL){
//         *end = NULL;
//     }
//     return v;
// }


void insert(cola **start, cola **end, int value){
    cola *nw = (cola *)malloc(sizeof(cola));
    nw->data = value;
    nw->ptr = NULL;

    if(*end != NULL){
        (*end)->ptr = nw; 
    }

    *end = nw;
    
    if(*start == NULL){
        *start = nw;
    }
}

void insertar(cola **primero, cola **ultimo, int v) 
{
   cola* nuevo;
 
   nuevo = (cola*)malloc(sizeof(cola));	// Creamos el nuevo nodo
   nuevo->data = v;	// Le asignamos el dato
   nuevo->ptr = NULL;	// El nuevo nodo apuntar� a NULL
   if (*ultimo != NULL) 	// Si la cola no estaba vac�a...
       (*ultimo)->ptr = nuevo;	// ...enganchamos el nuevo al final
   *ultimo = nuevo;	// A partir de ahora, el nuevo ser� el �ltimo
   if (*primero == NULL) 	// Si la cola estaba vac�a...
       *primero = nuevo;	// ...el �ltimo tambi�n ser� el primero
}

int sacar(cola **primero, cola **ultimo) 
{
   cola *aux;	// Puntero auxiliar
   int v;	// Para almacenar el valor del dato y devolverlo
   
   aux = *primero;	// El auxiliar apunta a la cabeza
   if(aux == NULL) 	// La cola est� vac�a: devolver valor especial
      return -1; 
   *primero = aux->ptr;	// El primero apunta al segundo
   v = aux->data; 	// Recoger valor del primero
   free(aux);	// Eliminar el nodo primero
   if (*primero==NULL) 	// Si la cola se ha quedado vac�a...
      *ultimo = NULL;	// ...hacer que el �ltimo tambi�n apunte a NULL
   return v;	// Devolver el dato que hab�a en el primero
}




// void show(cola col){
//     cola aux = col;
//     while(aux.ptr != NULL){
//         printf("%d ", aux.data);
//         aux = *aux.ptr;
//         if(aux.ptr == NULL){
//             printf("%d ", aux.data);
//             break;
//         }
//     }
// }


