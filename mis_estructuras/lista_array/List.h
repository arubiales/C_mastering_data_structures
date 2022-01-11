#include "Node.h"


struct s_list{
    Node *nd;
    int size;
    int mem_available;
    int length;
    Node *start;
    Node *end;
};



typedef struct s_list list;


list * init(int size){
    list *lst;
    Node *nd;
    int last_n = size-1, node_size = size * sizeof(Node);
    
    node_size = overallocate(node_size);
    //Reservamos memoria
    lst = (list *)malloc(sizeof(lst));
    lst->nd = (Node *)malloc(node_size);

    //fijamos atributos
    lst->size = node_size;
    lst->length = 0;
    lst->mem_available = node_size;

    //Inicializamos los Nodos
    for(int i=1; i<size-1; i++){
        lst->nd[i].data = 0;
        // lst->nd[i].idx = i;
        lst->nd[i].next = lst->nd+(i+1);
        lst->nd[i].back = lst->nd+(i-1);
        lst->nd[i].ptr = lst->nd+i;
    }

    lst->nd[0].data = 0;
    lst->nd[last_n].data = 0;

    lst->nd[0].next = lst->nd+1;
    lst->nd[last_n].next = lst->nd;

    lst->nd[0].back = lst->nd+last_n;
    lst->nd[last_n].back = lst->nd+(last_n-1);

    lst->nd[0].ptr = lst->nd;
    lst->nd[last_n].ptr = lst->nd+last_n;

    //fijamos el inicio y el fin
    lst->start = lst->nd->ptr;
    lst->end = lst->nd[last_n].ptr;

    return lst;
}




void destruct(list *lst){
    free(lst->nd);
    free(lst);
}


void swap(list *lst, int idx1, int idx2){
    int aux;

    //Si son indices iguales, finalizamos la función
    if(idx1 == idx2){
        return;
    }

    //Si idx1 no es el índice más pequeño, hacemos que así lo sea
    if(idx1 > idx2){
        int aux_idx = idx1;
        idx1 = idx2;
        idx2 = aux_idx;
    }

    aux = lst->nd[idx1].data;
    lst->nd[idx1].data = lst->nd[idx2].data;
    lst->nd[idx2].data = aux; 

}


void reverse(list *lst){
    int i=0, j=lst->length-1;
    int aux;

    for(i, j; i<lst->length/2; i++, j--){
        aux = lst->nd[i].data;
        lst->nd[i].data = lst->nd[j].data;
        lst->nd[j].data = aux;
    }
}

void show(list lst){
    int counter = 0;
    Node *aux = lst.start;
    printf("\n");
    do{
        printf("%d ", aux->data);
        aux = aux->next;
        counter++;
    }while(aux != lst.end && counter<lst.length);

    printf("%d\n", lst.end->data);
}

int overallocate(int size){
    return (int)((size*0.15) + size +1);
}



// void appendright(list *lst, int value){
//     Node node;
//     int node_size = sizeof(Node); //Esto deberíamos declararlo como una constante definida arriba del todo en preprocesado

//     if(lst->mem_available < node_size){
//         int oversize = lst->size - overallocate(lst->size);
//         lst->nd = realloc(lst->nd, oversize);
//         lst->size += oversize;
//         lst->mem_available += oversize - node_size;
//     }

//     node.data = value;
//     node.back = lst->end;
//     node.ptr = &node;
//     node.next = lst->start;

//     lst->length++;
//     lst->nd[lst->length-1].next = node.ptr;
//     lst->nd[0].back = node.ptr;
// }


















//--------------------------------------------------------------------------------------------------------
//------------------------- SWAP antiguo usando punteros ------------------------------------------------- le falta acabar porque daba fallos
//--------------------------------------------------------------------------------------------------------

// void swap(list *lst, int idx1, int idx2){
//     Node aux;

//     //Si son indices iguales, finalizamos la función
//     if(idx1 == idx2){
//         return;
//     }

//     //Si idx1 no es el índice más pequeño, hacemos que así lo sea
//     if(idx1 > idx2){
//         int aux_idx = idx1;
//         idx1 = idx2;
//         idx2 = aux_idx;
//     }

//     //Inicializamos variables
//     int last_idx1= idx1-1, last_idx2 = idx2-1, next_idx1 = idx1+1, next_idx2 = idx2+1;
//     int max_idx = lst->length-1;

//     //Si es el primero o el último, tenemos que cambiar como van a ser cambiados esos apuntadores
//     if(last_idx1 == -1){
//         last_idx1 = max_idx;
//     }
//     if(next_idx2 > max_idx){
//         next_idx2 = 0;
//     }

//     //Si es el primero o el último tenemos que cambiar el inicio y fin de la lista
//     if(idx1 == 0){
//         lst->start = lst->nd[idx2].ptr;
//     }
//     if(idx2 == max_idx){
//         lst->end = lst->nd[idx1].ptr;
//     }

//     //Cambiamos los indices
//     aux = lst->nd[idx2];

//     lst->nd[last_idx1].next = lst->nd[idx2].ptr;
//     lst->nd[next_idx1].back = lst->nd[idx2].ptr;
//     lst->nd[idx2].back = lst->nd[idx1].back;
//     lst->nd[idx2].next = lst->nd[idx1].next;
//     lst->nd[idx2].idx = idx1;

//     lst->nd[last_idx2].next = lst->nd[idx1].ptr;
//     lst->nd[next_idx2].back = lst->nd[idx1].ptr;
//     lst->nd[idx1].back = aux.back;
//     lst->nd[idx1].next = aux.next;
//     lst->nd[idx1].idx = idx2;
// }
