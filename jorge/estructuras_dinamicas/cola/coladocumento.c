#include "coladocumento.h"
#include <string.h>

int main(){
    int cantidadDocumentos=10;
    
    //localizamos la cantidad de documentos que queramos
    Documento *ptrdoc = (Documento *)malloc(cantidadDocumentos*sizeof(Documento));

    Cola doc_col = init();

    //llenamos los datos de los documentos
    strcpy(ptrdoc[0].nombre,"Andres");
    strcpy(ptrdoc[0].autor,"Mickel Richi");
    ptrdoc[0].num_pags = 50;
    ptrdoc[0].tamanio = 60;
    encolar(&doc_col, ptrdoc[0]);


    //llenamos los datos de los documentos
    strcpy(ptrdoc[1].nombre,"Alberto");
    strcpy(ptrdoc[1].autor,"La viiiiiiiii");
    ptrdoc[1].num_pags = 1;
    ptrdoc[1].tamanio = 1;
    encolar(&doc_col, ptrdoc[1]);


    //llenamos los datos de los documentos
    strcpy(ptrdoc[2].nombre,"Manflato");
    strcpy(ptrdoc[2].autor,"Einstein");
    ptrdoc[2].num_pags = 2;
    ptrdoc[2].tamanio = 2;
    encolar(&doc_col, ptrdoc[2]);


    //llenamos los datos de los documentos
    strcpy(ptrdoc[3].nombre,"Alejandro");
    strcpy(ptrdoc[3].autor,"Macarena");
    ptrdoc[3].num_pags = 3;
    ptrdoc[3].tamanio = 6;
    encolar(&doc_col, ptrdoc[3]);

    float total = 0.0;
    for(int i=0; i<4; i++){
        Documento cola_regresada = desencolar(&doc_col);
        printf("Nombre: %s\n", cola_regresada.nombre);
        float tiempo_segundo = (cola_regresada.num_pags)*3;
        tiempo_segundo/=60;
        total += tiempo_segundo;
    }
    printf("Tiempo total de impresión (minutos): %.2f\n", total);


    return 0;
}
