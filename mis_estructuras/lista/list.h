#include <stdio.h>
#include <stdlib.h>


typedef struct sNode
{ 
    int data;
    struct sNode *next;
    struct sNode *back;
    int active;
} Node;


typedef struct sList
{
    Node *start;
    Node *end;
    int size;
    int allocated;
    int length;
    int available;
} list;

int is_deallocated(list *lst){

    //predicate, que chequea si una lista está inicializada, es decir tiene nodos allocados aunque estén sin datos

    if(lst->start == NULL){
        return 1;
    }
    return 0;
}

int is_empty(list *lst){

    //Predicate que chekea si una lista tiene datos

    if(lst->start->active){
        return 0;
    }
    return 1;
}

int _overallocate(int size)
{
    //La formula para calcular la sobre alocación

    return (int )(size + (size*0.15) +1);
}

void __init_nodes__(list *lst, int ovl)
{
    //Inicializa un nodo reservando memoria para el  o varios nodos, segundo el parámetro de overallocation
    int idx=0;
    Node *aux;

    while(idx <ovl){
            aux = (Node *)malloc(sizeof(Node));
            aux->back = lst->end;
            aux->next = lst->start;
            aux->data = 0;
            aux->active = 0;

            lst->end->next = aux;
            lst->end = aux;
            idx++;
        }

        lst->start->back = lst->end;
        lst->available += ovl;
        lst->allocated += ovl;
        lst->size += ovl*sizeof(Node);
}

void _increase_in_one(list *lst){
    
    //Función auxiliar para usarse cuando se incresea uno

    lst->allocated++;
    lst->available++;
    lst->size += sizeof(Node);

}

list * _allocate_nodes(list *lst, int ovl)
{
    //si iniciamos una nueva lista
    if(is_deallocated(lst)){
        Node *aux = (Node*)malloc(sizeof(Node));
        aux->data = 0;
        aux->active = 0;
        aux->back = aux;
        aux->next = aux;
        lst->start = aux;
        lst->end = aux;



        _increase_in_one(lst);

        __init_nodes__(lst, ovl-1);

    } //si reservamos espacio a una lista ya asignada
    else{//esto solo se reserva espacio si no tenemos espacio, es decir si el final de los allocados coincide con lst->end
        __init_nodes__(lst, ovl);
    }

    return lst;
}


list * __init__(int length)
{
    //Inicializamos una lista de datos vacios, solo reservando espacios de memoria

    list *lst = (list *)malloc(sizeof(list));
    int ovl = _overallocate(length);

    lst->allocated = 0;
    lst->size = 0;
    lst->length = 0;
    lst->available = 0;
    lst->start = NULL;
    lst->end = NULL;

    _allocate_nodes(lst, ovl);

    return lst;
}

void show(list lst)
{
    // Mostramos los datos de la lista

    printf("\n");
    while(lst.start != lst.end){
        printf("%d ", lst.start->data);
        lst.start = lst.start->next;
    }
    printf("%d ", lst.end->data);
    printf("\n");
}


void appendright(list *lst, int value)
{

    if(lst->available){
        if(is_empty(lst)){
            lst->start->data = value;
            lst->start->active = 1;
            lst->end = lst->start;
        }
        else{
            lst->end = lst->end->next;
            lst->end->data = value;
            lst->end->active = 1;
        }
        lst->available--;
        lst->length++;
    } 
    else{
        int ovl = (_overallocate(lst->length)) - lst->allocated;
        Node *save_end = lst->end;

        _allocate_nodes(lst, ovl);

        lst->end = save_end->next;
        lst->end->data = value;
        lst->end->active = 1;
        lst->length++;
        lst->available--;
    }
}


void _append_left(list *lst, int value){

    //FUnción que ayuda a apendizar al inicio con memoria allocada

        lst->start = lst->start->back;
        lst->start->data = value; 
        lst->start->active = 1;
        lst->available--;
        lst->length++;
}

void appendleft(list *lst, int value){

    //apendizamos al principio

    if(lst->available){ //Si hay espacio convertimos un Nodo desocupado del final en el primero
        if(is_empty(lst)){
            appendright(lst, value);
        }
        _append_left(lst, value);
    }
    else{ //Si no allocamos al final y convertimos un Nodo desocupado del final en el primero
        int ovl = (_overallocate(lst->length)) - lst->allocated;
        Node *save_end = lst->end;

        _allocate_nodes(lst, ovl);

        lst->end = save_end;
        _append_left(lst, value);
    }
}



//Tenemos que hacer una función que creckee la memoria y la libere si hay demasiada
void check_and_free_overallocation(list *lst)
{
    //Basandose en un parámetros, borra si hay demasiados nodos sin información para aminorar el array

    int oversize_limit = (int) lst->allocated * 0.2;
    int node_size = sizeof(Node);
    Node *to_delete = lst->end->next;


    while(lst->available-1 > oversize_limit){ //este menos uno viene de lo que sumas cuando sobrealocas

        lst->end->next = to_delete->next;
        lst->end->next->back = lst->end;

        free(to_delete);
        lst->allocated--;
        lst->available--;
        lst->size-=node_size;
    }
}


int popright(list *lst)
{
    //Quitamos uno del final reasignando los punteros
    if(is_empty(lst)){
        printf("Error el nodo está vacio");
        exit(1);
    }

    int value = lst->end->data;

    lst->end->active = 0;
    lst->end = lst->end->back;
    lst->length--;
    lst->available++;

    check_and_free_overallocation(lst);

    return value;
}

int popleft(list *lst){

    //Quitamos uno del inicio reasignando los nodos
    if(is_empty(lst)){
        printf("Error el nodo está vacio");
        exit(1);
    }

    int value = lst->start->data;

    lst->start->active = 0;
    lst->start = lst->start->next;
    lst->length--;
    lst->available++;
    check_and_free_overallocation(lst);
    
    return value;
}



int count(list *lst){

    //El número de datos es la longitud de la lista

    return lst->length;
}

int sum(list lst){

    //Recorriendo desde start_active hasta last_active buscamos Sumamos los valores

    int summatory= lst.start->data;

    while(lst.start != lst.end){
        lst.start = lst.start->next;
        summatory += lst.start->data;
    }

    return summatory;
}

int max(list lst){

    //Recorriendo desde start_active hasta last_active buscamos el máximo

    int maximum = lst.start->data;
    while(lst.start != lst.end){
        lst.start = lst.start->next;
        if(lst.start->data > maximum){
            maximum = lst.start->data;
        }
    }

    return maximum;
}



int min(list lst){

    //Recorriendo desde start_active hasta last_active buscamos el mínimo

    int minimum = lst.start->data;
    while(lst.start != lst.end){
        lst.start = lst.start->next;
        if(lst.start->data < minimum){
            minimum = lst.start->data;
        }
    }
    
    return minimum;
}


int search(list lst, int value){

    //Buscamos un valor en la lista si retorna -1 es que no existe

    int count = 0;
    int list_value = lst.start->data;

    if(list_value == value){
        return 0;
    }

    while(lst.start != lst.end){
        count++;
        lst.start = lst.start->next;
        list_value = lst.start->data;
        if(list_value == value){
            return count;
        }
    } 

    return -1;
}


int get(list lst, int idx){
    
    //Obtenemos el valor en la posición idx de la lista

    int count = 0;

    if(idx < lst.length){
        while(lst.start != lst.end){
            if(count == idx){
                return lst.start->data;
            }
            count++;
            lst.start = lst.start->next;
        }
        return lst.end->data;
    }
    else{
        printf("IndexError: el indice es mayor que el tamaño de la lista");
        exit(1);
    }
}


Node * _get_node(list lst, int idx){
    
    // Conseguimos un Nodo, pero no solo el valor, si no el nodo entero
    
    int count = 0;

    if(idx < lst.length){
       while(lst.start != lst.end){
           if(count == idx){
               return lst.start;
           }
           count++;
           lst.start = lst.start->next;
       } 
       return lst.end;
    }
}


void insert(list *lst, int idx, int value){
    
    /* Insertamos un valor en la lista, necesita haber valores en la lista y no se puede insertar en la última posición.
    Si no hay nodos no tenemos nada implementado, tambien debemos usar los append para hacerlo al inicio y al final TODO:*/

    if(!idx){
        appendleft(lst, value);
    }
    else if(idx == lst->length){
        appendright(lst, value);
    }
    else if(idx < lst->length){ //aquí se podría usar allocate node
        Node *current_node = _get_node(*lst, idx);
        Node *insert_node = (Node *)malloc(sizeof(Node));
        
        //Inicializamos el nodo nuevo 
        insert_node->back = current_node->back;
        insert_node->active = 1;
        insert_node->data = value;

        //Cambiamos los nodos en la lista
        current_node->back->next = insert_node;        
        current_node->back = insert_node;
        insert_node->next = current_node;

        //Hacemos los cambios necesarios en la lista
        lst->allocated++;
        lst->length++;
        lst->size += sizeof(Node);
    }
    else{
        printf("IndexError: el indice es mayor que el tamaño de la lista");
        exit(1);
    }
}


void delete(list *lst, int value){

    if(lst->end->data == value){ //si es el último
        popright(lst);
        return;
    }
    else if(lst->start->data == value){ //si es el primero
        popleft(lst);
        return;
    }
    else{
        Node *aux = lst->start->next;
        while(aux != lst->end){
            if(aux->data == value){
                aux->back->next = aux->next;
                aux->next->back = aux->back;
                free(aux);
                lst->allocated--;
                lst->size -= sizeof(Node);
                lst->length--;
                return;
            }
            aux = aux->next;
        }
        printf("ValueError: el número no se encuentra en la lista");
        exit(1);
    }
}


int is_sorted(list lst){
    while(lst.start != lst.end){
        if(lst.start->data > lst.start->next->data){
            return 0;
        }
        lst.start = lst.start->next;
    }
    return 1;
}


list * reverse(list *lst){

}


void drop_duplicated(list *lst){

}



list * concat(list *lst1, list *lst2){
    
}
