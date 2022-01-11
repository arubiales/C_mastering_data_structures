#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encabezado(char[]);
void body(char[]);
void atributos(char []);


int main(){
    char init[]={"<html>"}, end[]={"</html>"};
    char cabecera[100];
    char cuerpo[1000];
    char total[1150];
    FILE *archivo;

    encabezado(cabecera);
    body(cuerpo);

    strcat(total, init);
    strcat(total, cabecera);
    strcat(total, cuerpo);
    strcat(total, end);
    
    archivo = fopen("pagina_web.html", "w");

    if(archivo == NULL){
        printf("No se ha podido crear la web");
        exit(1);
    }

    fprintf(archivo, total);
    
    fclose(archivo);

    return 0;
}


void encabezado(char main_str[]){
    char h1[100];


    strcpy(main_str, "<h1");
    printf("Introduzca la cabecera del html\n");
    gets(h1);

    atributos(main_str);

    strcat(main_str, h1);
    strcat(main_str, "</h1>");
}

void body(char main_str[]){
    char cuerpo[900];

    strcpy(main_str, "\n\n<body");
    printf("Introduzca el texto del body\n");
    gets(cuerpo);

    atributos(main_str);
    strcat(main_str, cuerpo);
    strcat(main_str, "</body>\n");

}

void atributos(char main_str[]){
    char color[20], tamano[3], fuente[20];

    printf("Ahora introduzca el tamaño, el color, y la fuente, en ese orden\n");
    gets(tamano);
    gets(color);
    gets(fuente);


    strcat(main_str, " style='font-size:");
    strcat(main_str, tamano);
    strcat(main_str, "; color:");
    strcat(main_str, color);
    strcat(main_str, "; font-family:");
    strcat(main_str, fuente);
    strcat(main_str, "'>");
}
