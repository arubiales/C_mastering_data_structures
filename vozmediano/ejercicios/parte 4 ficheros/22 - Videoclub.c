/* VIDEOCLUB

Para simplificar la resoluci�n del ejercicio se han asignado los c�digos de pel�cula autom�ticamente. Cuando se inserta una nueva pel�cula, se busca un hueco en el archivo (de una pel�cula anteriormente borrada). Si se encuentra un hueco, se asigna ese c�digo a la nueva pel�cula. As� no hay que modificar el archivo de �ndices. Y si no existe ning�n hueco, se inserta la pel�cula al final del archivo de datos, asign�ndole el c�digo de la �ltima pel�cula m�s uno. De este modo, s�lo hay que modificar la �ltima entrada del archivo de �ndices, o agregar una nueva entrada si el segmento ya estaba lleno.

Con esta forma de asignar c�digos a las nuevas pel�culas se matan tres p�jaros de un tiro:
S�lo hay que tocar el �ltimo registro del archivo de �ndices (o a�adir un registro nuevo si el �ltimo segmento estaba lleno)
No hay que crear �rea de excedentes.
El archivo de datos siempre se mantiene ordenado.

N�tese que esto puede hacerse por la naturaleza peculiar de los datos del fichero. En otros programas, esta asignaci�n consecutiva de c�digos quiz� no pueda hacerse. Cada caso debe ser estudiado por separado.

Como siempre, se recomienda revisar atentamente el c�digo del programa (a ser posible, despu�s de haber intentado hacerlo).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------------------------------------------------------------------------------------------------
// Definici�n de constantes
// ------------------------------------------------------------------------------------------------------------

#define ARCHIVO_DATOS "video.dat" 
#define ARCHIVO_INDICE "video.idx" 
#define TAM_SEG 3  // Tama�o del segmento 

// ------------------------------------------------------------------------------------------------------------
// Definici�n de tipos de datos
// ------------------------------------------------------------------------------------------------------------
struct s_pelicula 
{ 
   char titulo[50]; 
   char director[20]; 
   char reparto[200]; 
   char genero[20]; 
   char nacionalidad[10]; 
   int duracion; 
   char borrado; 
   int codigo; 
}; 

struct s_indice 
{ 
    long int num_segmento; 
    long int direccion_primero; 
    int clave_ultimo; 
}; 


// ------------------------------------------------------------------------------------------------------------
// Prototipos de funciones
// ------------------------------------------------------------------------------------------------------------
void borrar_pantalla(void); 
void pulsar_tecla(void); 
int comprobar_archivo(void); 
int menu(void); 
void insertar_pelicula(int *n_regs); 
void listar_datos(void); 
void importar_datos(int *n_regs); 
void buscar_por_codigo(void); 
void reconstruir_indice(void); 
void mostrar_indice(void); 
void introducir_datos_pelicula(struct s_pelicula* peli); 
void borrar_pelicula(void); 
void modificar_pelicula(void); 


 // ------------------------------------------------------------------------------------------------------------
// Funci�n main()
// ------------------------------------------------------------------------------------------------------------
int main(void) 
{ 
   int opc, n_regs; 
   
   // Comprueba si el archivo de datos existe. Si no existe, lo crea. 
   n_regs = comprobar_archivo(); 

   do 
   { 
      borrar_pantalla(); 
      opc = menu(); 
      switch (opc) 
      { 
        case 1: insertar_pelicula(&n_regs); break; 
        case 2: buscar_por_codigo(); break; 
        case 3: borrar_pelicula(); break; 
        case 4: modificar_pelicula(); break; 
        case 5: listar_datos(); break; 
        case 6: mostrar_indice(); break; 
        case 7: reconstruir_indice(); break; 
      } 
   } 
   while (opc != 0);     // 0 es "salir" 
   
   return 0; 
} 

// ------------------------------------------------------------------------------------------------------------
// Borra la pantalla de texto 
// ------------------------------------------------------------------------------------------------------------
void borrar_pantalla(void) 
{ 
    int i; 
    for (i=0; i<40; i++) 
	printf("\n"); 
} 


// ------------------------------------------------------------------------------------------------------------
// Muestra el texto "Pulse Intro para continuar" y espera a que el usuario pulse Intro 
// ------------------------------------------------------------------------------------------------------------
void pulsar_tecla(void) 
{ 
   printf("Pulse Intro para continuar...\n"); 
   getchar(); 
} 


// ------------------------------------------------------------------------------------------------------------
// Muestra el men� y lee la opci�n del usuario. Devuelve el c�digo de la opci�n elegida. 
// ------------------------------------------------------------------------------------------------------------
int menu(void) 
{ 
   int opc = 1; 
   char aux[50]; 
   
   printf("EJERCICIO DEL VIDEOCLUB\n"); 
   printf("--------------------------------------\n"); 

   // Muestra el men� 
   printf("Men� de opciones\n\n"); 
   printf("1. A�adir pel�cula\n");   
   printf("2. Buscar pel�cula\n");   
   printf("3. Borrar pel�cula\n");   
   printf("4. Modificar pel�cula\n");   
   printf("5. Listar pel�culas\n");   
   printf("6. Mostrar �ndice (para depuraci�n)\n");   
   printf("7. Reconstruir �ndice\n");   
   printf("0. Salir\n\n"); 

   // Leer opci�n seleccionada 
   printf("Seleccione opci�n --> "); 
   gets(aux); 
   opc = atoi(aux); 
   
   return opc; 
} 

// ------------------------------------------------------------------------------------------------------------
// Comprueba si el archivo de datos existe. Si no existe, lo crea. 
// Devuelve el c�digo del �ltimo registro almacenado en el archivo. 
// ------------------------------------------------------------------------------------------------------------
int comprobar_archivo(void) 
{ 
    FILE *f; 
    struct s_pelicula peli; 
    int n_regs; 
    
    f = fopen(ARCHIVO_DATOS, "r+"); 
    if (f == NULL)        // El archivo no existe: se crea y se pone el nº de registros a 0 
    { 
        f = fopen(ARCHIVO_DATOS, "a"); 
        if (f == NULL) 
        { 
                printf("Error al crear el archivo de datos\n"); 
                return 0; 
        } 
        n_regs = 0; 
        fclose(f); 
    } 
    else                // El archivo s�� existe: mirar cu�l es el c�digo del �ltimo registro 
    { 
        fseek (f, -sizeof(struct s_pelicula), SEEK_END); 
        fread(&peli, sizeof(struct s_pelicula), 1, f); 
        n_regs = peli.codigo; 
        fclose(f); 
    } 
    
    return n_regs; 
} 


// ------------------------------------------------------------------------------------------------------------
// A�ade una pel�cula al final del archivo de datos. El c�digo de la nueva pel�cula se 
// asigna autom�ticamente sum�ndole uno a la �ltima pel�cula que exista en el archivo, as� 
// que la nueva pel�cula siempre se agregar� al final del �ltimo segmento */ 
// ------------------------------------------------------------------------------------------------------------
void insertar_pelicula(int *n_regs) 
{ 
   FILE *f, *f_ind; 
   struct s_pelicula nuevo, peli; 
   struct s_indice entrada_indice; 
   int n, terminado = 0; 
   
   // Introducir por teclado los datos del nuevo registro 
   borrar_pantalla(); 
   printf("INSERTAR NUEVA PELICULA\n"); 
   printf("Introduzca los datos de la pel�cula\n"); 
   
   // Introducir por teclado los datos de la pel�cula 
   introducir_datos_pelicula(&nuevo); 
   
   // Abrir el archivo para a�adir datos en �l (modo secuencial, para agregar al final) 
   f = fopen(ARCHIVO_DATOS, "r+b"); 
   if (f == NULL) 
   { 
      printf("Error al abrir el archivo de datos"); 
      pulsar_tecla(); 
   } 
   else 
   { 
      // Buscamos un hueco donde insertar la pel�cula 
      while ((!feof(f)) && (terminado == 0)) 
      { 
         n = fread(&peli, sizeof(struct s_pelicula), 1, f); 
         if ((n > 0) && (peli.borrado == '*'))         // Hemos encontrado un hueco 
         { 
             fseek(f, -sizeof(struct s_pelicula), SEEK_CUR);         // Retrocedemos 
             nuevo.codigo = peli.codigo;                             // Reaprovechamos el c�digo antiguo 
             fwrite(&nuevo, sizeof(struct s_pelicula), 1, f); 
             terminado = 1; 
         } 
      } 

      if (terminado == 0)             // No se encontr� ning�n hueco 
      {                               
         fseek(f, 0, SEEK_END);            // Escribiremos el registro AL FINAL del archivo 
         nuevo.codigo = (*n_regs) + 1;     // El c�digo es el siguiente del �ltimo asignado 
         fwrite(&nuevo, sizeof(struct s_pelicula), 1, f); 
         // Al insertar al final, tenemos que actualizar el ��ndice 
         if (nuevo.codigo % TAM_SEG == 0) 
         {    // Crear nueva entrada en el ��ndice 
              f_ind = fopen(ARCHIVO_INDICE, "ab"); 
              if (f_ind == NULL) { printf("Pel�cula insertada, pero no puedo actualizar el �ndice\n"); return; } 
              entrada_indice.clave_ultimo = nuevo.codigo; 
              entrada_indice.direccion_primero = ftell(f); 
              entrada_indice.num_segmento = nuevo.codigo / TAM_SEG; 
              fwrite(&entrada_indice, sizeof(struct s_indice), 1, f_ind); 
              fclose(f_ind); 
         } 
         else 
         {    // Modificar �ltima entrada del ��ndice 
              f_ind = fopen(ARCHIVO_INDICE, "r+b"); 
              if (f_ind == NULL) { printf("Pel�cula insertada, pero no puedo actualizar el �ndice\n"); return; } 
              fseek(f_ind, -sizeof(struct s_indice), SEEK_END); 
              fread(&entrada_indice, sizeof(struct s_indice), 1, f_ind); 
              entrada_indice.clave_ultimo = nuevo.codigo; 
              fseek(f_ind, -sizeof(struct s_indice), SEEK_END); 
              fwrite(&entrada_indice, sizeof(struct s_indice), 1, f_ind); 
              fclose(f_ind); 
         } 
      } 
      
      fclose(f); 
      printf("Pel�cula insertada con el c�digo %i\n", nuevo.codigo); 
      (*n_regs)++; 
      pulsar_tecla(); 
   } 
} 


// ------------------------------------------------------------------------------------------------------------
// Lee por teclado los datos de una pel�cula y los devuelve en el par�metro pasado por variable. 
// Asigna todos los campos EXCEPTO EL CODIGO, que se asigna autom�ticamente en la funci�n 
// de inserci�n de la pel�cula. 
// ------------------------------------------------------------------------------------------------------------
void introducir_datos_pelicula(struct s_pelicula* peli) 
{ 
   char aux[50]; 
   
   printf("  T�tulo: "); 
   gets(peli->titulo); 
   printf("  Director: "); 
   gets(peli->director); 
   printf("  Reparto: "); 
   gets(peli->reparto); 
   printf("  G�nero: "); 
   gets(peli->genero); 
   printf("  Nacionalidad: "); 
   gets(peli->nacionalidad); 
   printf("  Duraci�n (minutos): "); 
   gets(aux); 
   peli->duracion = atoi(aux); 
   // Ponemos la marca de "no borrado" 
   peli->borrado = '-'; 
} 


// ------------------------------------------------------------------------------------------------------------
// Localiza una pel�cula por su c�digo 
// ------------------------------------------------------------------------------------------------------------
void buscar_por_codigo(void) 
{ 
    FILE *f, *f_ind; 
    struct s_pelicula peli; 
    struct s_indice entrada_indice; 
    int cod_buscado, n, cont; 
    char aux[50]; 
    
    f = fopen(ARCHIVO_DATOS, "r+b"); 
    if (f == NULL) { printf("Error al abrir archivo de datos\n"); return; } 
    f_ind = fopen(ARCHIVO_INDICE, "rb"); 
    if (f_ind == NULL) { printf("Error al abrir archivo de ��ndices\n"); return; } 
    
    borrar_pantalla(); 
    printf("BUSCAR UNA PEL�CULA POR C�DIGO\n"); 
    printf("Introduzca el c�digo buscado\n"); 
    gets(aux); 
    cod_buscado = atoi(aux); 
    
    // Buscamos entrada del indice 
    entrada_indice.clave_ultimo = -9999; 
    while ((!feof(f_ind)) && (entrada_indice.clave_ultimo < cod_buscado)) 
        fread(&entrada_indice, sizeof(struct s_indice), 1, f_ind); 
    
    if (cod_buscado <= entrada_indice.clave_ultimo) 
    { 
        // Buscamos pel�cula 
        fseek(f, entrada_indice.direccion_primero, SEEK_SET); 
        cont = 0; 
        do 
        { 
                fread(&peli, sizeof(struct s_pelicula), 1, f); 
                cont++; 
        } 
        while ((cont < TAM_SEG) && (peli.codigo != cod_buscado)); 
        
        // Pel�cula encontrada: mostrar 
        if ((peli.codigo == cod_buscado) && (peli.borrado == '-')) 
        { 
               printf("DATOS DEL REGISTRO:\n"); 
               printf("%-3i %s (%s), %s, %s, %i min\n", peli.codigo, peli.titulo, peli.director, peli.nacionalidad, peli.genero, peli.duracion); 
               printf("Reparto: %s\n", peli.reparto); 
        } 
        else 
               printf("Pel�cula no encontrada en su segmento\n"); 
    } // if 
    else 
       printf("Pel�cula no encontrada en el ��ndice\n"); 

    pulsar_tecla(); 
    fclose(f); 
    fclose(f_ind);        
} 

// ------------------------------------------------------------------------------------------------------------
// Muestra el contenido del archivo de datos por la pantalla 
// ------------------------------------------------------------------------------------------------------------
void listar_datos(void) 
{ 
   FILE *f; 
   struct s_pelicula peli; 
   int n; 
   
   // Abre el archivo en modo de lectura secuencial 
   borrar_pantalla(); 
   f = fopen(ARCHIVO_DATOS, "rb"); 
   if (f == NULL) 
   { 
      printf("Error al abrir el archivo de datos"); 
      pulsar_tecla(); 
   } 
   else 
   { 
       // Escribe en la pantalla la cabecera de la lista 
       while (!feof(f)) 
       { 
           // Lee un registro del archivo 
           n = fread(&peli, sizeof(struct s_pelicula), 1, f); 
           // Muestra por la pantalla el contenido del registro (si no est� marcado como borrado) 
           if ((n>0) && (peli.borrado == '-')) 
           { 
               printf("------------------------------------------------------------------------------\n"); 
               printf("%-3i %s (%s), %s, %s, %i min\n", peli.codigo, peli.titulo, peli.director, peli.nacionalidad, peli.genero, peli.duracion); 
               printf("Reparto: %s\n", peli.reparto); 
           } 
       } // while 
       fclose(f); 
       printf("------------------------------------------------------------------------------\n"); 
       pulsar_tecla(); 
   } // else 

} 

// ------------------------------------------------------------------------------------------------------------
// Reconstruye el archivo �ndice 
// ------------------------------------------------------------------------------------------------------------
void reconstruir_indice(void) 
{ 
    FILE *f, *f_ind; 
    struct s_pelicula peli; 
    struct s_indice ind; 
    int registro, segmento, dir_inicial, n; 
    

    borrar_pantalla(); 
    printf("Reconstruyendo el �ndice...\n"); 
    
    // Abrimos el archivo de datos en modo secuencial 
    f = fopen(ARCHIVO_DATOS, "rb"); 
    if (f == NULL) 
    { 
        printf("No se puede abrir el archivo de datos. Operaci�n cancelada.\n"); 
        pulsar_tecla(); return; 
    } 
    
    // Creamos un nuevo archivo de �ndices
    f_ind = fopen("temp", "wb"); 
    if (f_ind == NULL) 
    { 
        printf("No se puede crear el nuevo archivo de �ndices. Operaci�n cancelada.\n"); 
        pulsar_tecla(); return; 
    } 
    
    // Recorremos secuencialmente el archivo de datos 
    segmento = 1;       // Contador de segmentos 
    registro = 0;       // Contador de registros en el segmento 
    dir_inicial = 0;    // Direcci�n inicial del segmento 
    while (!feof(f)) 
    { 
        n = fread(&peli, sizeof(struct s_pelicula), 1, f); 
        if (n > 0) 
        { 
           registro++; 
           if (registro % TAM_SEG == 0)        // Cambiar de segmento 
           { 
                // Creamos una entrada en el �ndice y la grabamos 
                ind.num_segmento = segmento; 
                ind.direccion_primero = dir_inicial; 
                ind.clave_ultimo = peli.codigo; 
                fwrite(&ind, sizeof(struct s_indice), 1, f_ind); 
                
                // Iniciamos el nuevo segmento 
                segmento++; 
                dir_inicial = ftell(f); 
           } 
        } // if 
    } // while 
    
    // Si el �ltimo segmento no est� completo, no se habr� grabado 
    // su entrada en el archivo de �ndices, as� que lo haremos ahora 
    if (registro % TAM_SEG != 0) 
    { 
        // Creamos una entrada en el �ndice y la grabamos 
        ind.num_segmento = segmento; 
        ind.direccion_primero = dir_inicial; 
        ind.clave_ultimo = peli.codigo; 
        fwrite(&ind, sizeof(struct s_indice), 1, f_ind); 
    } 
 
    // Cerramos y renombramos el �ndice 
    fclose(f); 
    fclose(f_ind); 
    remove(ARCHIVO_INDICE); 
    rename("temp", ARCHIVO_INDICE); 
    printf("Proceso concluido con �xito.\n"); 
    pulsar_tecla();       
} 


// ------------------------------------------------------------------------------------------------------------
// Muestra el contenido del archivo de �ndices 
// (SOLO CON PROP�SITOS DE DEPURACI�N. Esta funci�n deber�a desaparecer de la versi�n definitiva del programa) 
// ------------------------------------------------------------------------------------------------------------
void mostrar_indice(void) 
{ 
   FILE *f; 
   struct s_indice entrada_indice; 
   int n; 
   
   // Abre el archivo en modo de lectura secuencial 
   borrar_pantalla(); 
   f = fopen(ARCHIVO_INDICE, "rb"); 
   if (f == NULL) 
   { 
      printf("Error al abrir el archivo de �ndices"); 
      pulsar_tecla(); 
   } 
   else 
   { 
       printf("SEG.  DIR.  CLAVE\n"); 
       printf("-----------------\n"); 
       while (!feof(f)) 
       { 
           // Lee un registro del archivo 
           n = fread(&entrada_indice, sizeof(struct s_indice), 1, f); 
           // Muestra por la pantalla el contenido del registro 
           if (n>0) 
           { 
               printf("%-3i   %-5i  %-4i\n", entrada_indice.num_segmento, entrada_indice.direccion_primero, entrada_indice.clave_ultimo); 
           } 
       } // while 
       fclose(f); 
       pulsar_tecla(); 
   } // else 
    
} 


// ------------------------------------------------------------------------------------------------------------
// Busca una pel�cula y, si existe, permite que el usuario modifique cualquiera de sus campos (excepto el c�digo) 
// ------------------------------------------------------------------------------------------------------------
void modificar_pelicula(void) 
{ 
    FILE *f, *f_ind; 
    struct s_pelicula peli; 
    struct s_indice entrada_indice; 
    int cod_buscado, n, cont; 
    char aux[50]; 
    
    f = fopen(ARCHIVO_DATOS, "r+b"); 
    if (f == NULL) { printf("Error al abrir archivo de datos\n"); return; } 
    f_ind = fopen(ARCHIVO_INDICE, "rb"); 
    if (f_ind == NULL) { printf("Error al abrir archivo de �ndices\n"); return; } 
    
    borrar_pantalla(); 
    printf("MODIFICAR UNA PEL�CULA\n"); 
    printf("Introduzca el c�digo de la pel�cula:\n"); 
    gets(aux); 
    cod_buscado = atoi(aux); 
    
    // Buscamos entrada del indice 
    entrada_indice.clave_ultimo = -9999; 
    while ((!feof(f_ind)) && (entrada_indice.clave_ultimo < cod_buscado)) 
        fread(&entrada_indice, sizeof(struct s_indice), 1, f_ind); 
    
    if (cod_buscado <= entrada_indice.clave_ultimo) 
    { 
        // Buscamos pel�cula 
        fseek(f, entrada_indice.direccion_primero, SEEK_SET); 
        cont = 0; 
        do 
        { 
                fread(&peli, sizeof(struct s_pelicula), 1, f); 
                cont++; 
        } 
        while ((cont < TAM_SEG) && (peli.codigo != cod_buscado)); 
        
        // Pel�cula encontrada: mostramos los datos y pedimos su modificaci�n. Si se pulsa "Intro", los dejamos sin cambios. 
        if ((peli.codigo == cod_buscado) && (peli.borrado == '-')) 
        { 
        	printf("Modifique el registro (pulse Intro para dejar igual):\n"); 
		printf("C�digo: %i\n", peli.codigo); 
		printf("T�tulo (%s): \n", peli.titulo); 
		gets(aux); if (strcmp(aux,"") != 0) strcpy(peli.titulo, aux); 
		printf("Director (%s): \n", peli.director); 
		gets(aux); if (strcmp(aux,"") != 0) strcpy(peli.director, aux); 
		printf("Reparto (%s): \n", peli.reparto); 
		gets(aux); if (strcmp(aux,"") != 0) strcpy(peli.reparto, aux); 
		printf("Nacionalidad (%s): \n", peli.nacionalidad); 
		gets(aux); if (strcmp(aux,"") != 0) strcpy(peli.nacionalidad, aux); 
		printf("G�nero (%s): \n", peli.genero); 
		gets(aux); if (strcmp(aux,"") != 0) strcpy(peli.genero, aux); 
		printf("Duraci�n (%i): \n", peli.duracion); 
		gets(aux); if (strcmp(aux,"") != 0) peli.duracion = atoi(aux); 

		printf("�Confirma la modificaci�n del registro? (S/N)"); 
		gets(aux); 
		if ((aux[0] == 's') || (aux[0] == 'S')) 
	        { 
			// Retrocedemos un registro en el fichero de datos 
			fseek(f, -sizeof(struct s_pelicula), SEEK_CUR); 
			// Sobreescribimos el registro con los nuevos datos 
			fwrite(&peli, sizeof(struct s_pelicula), 1, f); 
			printf("Registro modificado\n"); 
		} 
		else 
			printf("Operaci�n cancelada\n"); 
        } 
        else 
               printf("Pel�cula no encontrada en su segmento\n"); 
    } // if 
    else 
       printf("Pel�cula no encontrada en el �ndice\n"); 

    pulsar_tecla(); 
    fclose(f); 
    fclose(f_ind);        
} 

// ------------------------------------------------------------------------------------------------------------
// Busca una pel�cula y, si existe, la marca como borrada 
// ------------------------------------------------------------------------------------------------------------
void borrar_pelicula(void) 
{ 
    FILE *f, *f_ind; 
    struct s_pelicula peli; 
    struct s_indice entrada_indice; 
    int cod_buscado, n, cont; 
    char aux[50]; 
    
    f = fopen(ARCHIVO_DATOS, "r+b"); 
    if (f == NULL) { printf("Error al abrir archivo de datos\n"); return; } 
    f_ind = fopen(ARCHIVO_INDICE, "rb"); 
    if (f_ind == NULL) { printf("Error al abrir archivo de �ndices\n"); return; } 
    
    borrar_pantalla(); 
    printf("BORRAR UNA PEL�CULA\n"); 
    printf("Introduzca el c�digo de la pel�cula:\n"); 
    gets(aux); 
    cod_buscado = atoi(aux); 
    
    // Buscamos entrada del indice 
    entrada_indice.clave_ultimo = -9999; 
    while ((!feof(f_ind)) && (entrada_indice.clave_ultimo < cod_buscado)) 
        fread(&entrada_indice, sizeof(struct s_indice), 1, f_ind); 
    
    if (cod_buscado <= entrada_indice.clave_ultimo) 
    { 
        // Buscamos pel�cula 
        fseek(f, entrada_indice.direccion_primero, SEEK_SET); 
        cont = 0; 
        do 
        { 
                fread(&peli, sizeof(struct s_pelicula), 1, f); 
                cont++; 
        } 
        while ((cont < TAM_SEG) && (peli.codigo != cod_buscado)); 
        
        // Pel�cula encontrada: pedimos confirmaci�n y borramos 
        if ((peli.codigo == cod_buscado) && (peli.borrado == '-')) 
        { 
               printf("DATOS DEL REGISTRO:\n"); 
               printf("%-3i %s (%s), %s, %s, %i min\n", peli.codigo, peli.titulo, peli.director, peli.nacionalidad, peli.genero, peli.duracion); 
               printf("Reparto: %s\n\n", peli.reparto); 
	       printf("�Est� seguro de que desea borrar la pel�cula? (S/N)"); 
	       gets(aux); 
	       if ((aux[0] == 's') || (aux[0] == 'S')) 
	       { 
			// Retrocedemos un registro en el fichero de datos 
			fseek(f, -sizeof(struct s_pelicula), SEEK_CUR); 
			// Sobreescribimos el registro marcando la pel�cula como borrada 
			peli.borrado = '*'; 
			fwrite(&peli, sizeof(struct s_pelicula), 1, f); 
			printf("Registro borrado\n"); 
		} 
		else 
			printf("Operaci�n cancelada\n"); 
        } 
        else 
               printf("Pel�cula no encontrada en su segmento\n"); 
    } // if 
    else 
       printf("Pel�cula no encontrada en el ��ndice\n"); 

    pulsar_tecla(); 
    fclose(f); 
    fclose(f_ind);        
} 
