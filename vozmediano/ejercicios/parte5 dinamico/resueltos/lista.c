/* IMPLEMENTACION DE UNA LISTA ENLAZADA SIMPLE (ABIERTA) */
#include <stdio.h>
#include "lista.h"

void inicializar(struct s_nodo **primero)
{
   *primero = NULL;
}


int esta_vacia(struct s_nodo *primero)
{
   if (primero == NULL)
     return 1;
   else
     return 0;
}


int contar_nodos(struct s_nodo *primero)
{
   int cont = 0;
   struct s_nodo *nodo;
   
   nodo = primero;
   while (nodo != NULL)
   { 
      cont++;
      nodo = nodo->siguiente;
   }
   
   return cont;
}

void insertar(struct s_nodo **primero, TIPO dato)
{
   struct s_nodo *nuevo;
   
   nuevo = (TIPO*) malloc (sizeof(TIPO));
   nuevo->dato = dato;
   nuevo->siguiente = *primero;
   *primero = nuevo;
}


int buscar_por_contenido(struct s_nodo *primero, TIPO dato)
{
   struct s_nodo *nodo;
   int pos = 0, encontrado = 0;
   
   nodo = primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      pos++;
      if (nodo->dato == dato)
         encontrado = 1;
      nodo = nodo->siguiente;
   }
   
   if (encontrado == 0)
      pos = -1;
      
   return pos;
}


int buscar_por_posicion(struct s_nodo *primero, int posic, TIPO *result)
{
   struct s_nodo *nodo;
   int i = 0, encontrado = 0;
   
   nodo = primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      i++;
      if (i == posic) {
         encontrado = 1;
	 *result = nodo->dato;
      }
      nodo = nodo->siguiente;
   }
   
   return encontrado;
}


void borrar_primero(struct s_nodo **primero)
{
   struct s_nodo *segundo;
   
   segundo = (*primero)->siguiente;   
   free(primero);
   *primero = segundo;
}


void borrar_todos(struct s_nodo **primero)
{
   struct s_nodo *nodo, *sig;
   
   nodo = *primero;
   while (nodo != NULL)
   {
      sig = nodo->siguiente;
      free(nodo);
      nodo = sig;
   }

   *primero = NULL;
}
   


int borrar_por_posicion(struct s_nodo **primero, int posic)
{
   struct s_nodo *nodo, *anterior;
   int cont = 0, encontrado = 0;
   
   nodo = *primero;
   anterior = *primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      cont++;
      if (cont == posic)
      {
         if (nodo == *primero)
	    *primero = (*primero)->siguiente;
	 else
	    anterior->siguiente = nodo->siguiente;
	 free(nodo);
	 encontrado = 1;
      }
      else
      {
         anterior = nodo;
         nodo = nodo->siguiente;
      }
    }
   
   return encontrado;
}



int borrar_por_contenido(struct s_nodo **primero, TIPO dato)
{
   struct s_nodo *nodo, *anterior;
   int encontrado = 0;
   
   nodo = *primero;
   anterior = *primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      if (nodo->dato == dato)
      {
         if (nodo == *primero)
	    *primero = (*primero)->siguiente;
	 else
	    anterior->siguiente = nodo->siguiente;
	 free(nodo);
	 encontrado = 1;
      }
      else
      {
         anterior = nodo;
         nodo = nodo->siguiente;
      }
   }
   
   return encontrado;
}
   

void mostrar_lista(struct s_nodo *primero)
{
  struct s_nodo *nodo;
  
  nodo = primero;
  while (nodo != NULL)
  {
     printf("%i\n", nodo->dato);		// ESTO HAY QUE CAMBIARLO dependiendo del tipo de los datos
     nodo = nodo->siguiente;
  }
}
