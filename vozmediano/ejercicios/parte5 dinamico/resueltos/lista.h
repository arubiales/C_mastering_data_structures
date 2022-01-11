/* IMPLEMENTACION DE UNA LISTA ENLAZADA SIMPLE (ABIERTA) */
#include <stdio.h>

#define TIPO int	// cambiando esto podemos modificar el tipo de los datos de la lista

// Definción de la estructura básica de la lista
struct s_nodo
{
   TIPO dato;
   struct s_nodo *siguiente;
};

// Prototipos de funciones
void inicializar(struct s_nodo **primero);
int esta_vacia(struct s_nodo *primero);
int contar_nodos(struct s_nodo *primero);
void insertar(struct s_nodo **primero, TIPO dato);
int buscar_por_contenido(struct s_nodo *primero, TIPO dato);
int buscar_por_posicion(struct s_nodo *primero, int posic, TIPO *result);
void borrar_primero(struct s_nodo **primero);
void borrar_todos(struct s_nodo **primero);
int borrar_por_posicion(struct s_nodo **primero, int posic);
int borrar_por_contenido(struct s_nodo **primero, TIPO dato);
void mostrar_lista(struct s_nodo *primero);


