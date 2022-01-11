#include <stdio.h>
#include <stdlib.h>

struct s_nodo 
{
   int dato;
   struct s_nodo *siguiente;
};
typedef struct s_nodo t_nodo;


int main(void)
{
   t_nodo *primero, *ultimo;
   int v;
   
   primero = NULL;
   insertar(&primero, &ultimo, 4);
   insertar(&primero, &ultimo, 5);
   insertar(&primero, &ultimo, 8);
   insertar(&primero, &ultimo, 10);
   insertar(&primero, &ultimo, 13);
   
   v = sacar(&primero, &ultimo);
   printf("Valor = %i\n", v);
   v = sacar(&primero, &ultimo);
   printf("Valor = %i\n", v);
   v = sacar(&primero, &ultimo);
   printf("Valor = %i\n", v);
   v = sacar(&primero, &ultimo);
   printf("Valor = %i\n", v);
   v = sacar(&primero, &ultimo);
   printf("Valor = %i\n", v);

   return 0;
}   

void insertar(t_nodo **primero, t_nodo **ultimo, int v) 
{
   t_nodo* nuevo;
 
   nuevo = (t_nodo*)malloc(sizeof(t_nodo));	// Creamos el nuevo nodo
   nuevo->dato = v;	// Le asignamos el dato
   nuevo->siguiente = NULL;	// El nuevo nodo apuntar� a NULL
   if (*ultimo != NULL) 	// Si la cola no estaba vac�a...
       (*ultimo)->siguiente = nuevo;	// ...enganchamos el nuevo al final
   *ultimo = nuevo;	// A partir de ahora, el nuevo ser� el �ltimo
   if (*primero == NULL) 	// Si la cola estaba vac�a...
       *primero = nuevo;	// ...el �ltimo tambi�n ser� el primero
}

int sacar(t_nodo **primero, t_nodo **ultimo) 
{
   t_nodo *aux;	// Puntero auxiliar
   int v;	// Para almacenar el valor del dato y devolverlo
   
   aux = *primero;	// El auxiliar apunta a la cabeza
   if(aux == NULL) 	// La cola est� vac�a: devolver valor especial
      return -1; 
   *primero = aux->siguiente;	// El primero apunta al segundo
   v = aux->dato; 	// Recoger valor del primero
   free(aux);	// Eliminar el nodo primero
   if (*primero==NULL) 	// Si la cola se ha quedado vac�a...
      *ultimo = NULL;	// ...hacer que el �ltimo tambi�n apunte a NULL
   return v;	// Devolver el dato que hab�a en el primero
}
