#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct user
{
    int id;
    char nombre[30];
    char telf[20];
    char dir[40];
    char mail[40];
    int activo;
} User;


int options();
FILE * open();
void add();
void list();
void find();
void modify();

int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    User usr;
    int opt=0, idx_agenda;


    while(opt < 6){
        opt = options();
        switch (opt)
        {
            case 1:
                add();
                break;
            
            case 2:
                find();
                break;

            case 3:
                list();
                break;
            
            case 4:
                modify();
                break;
            
            case 5:
                delete();
                break;
            
            case 6:
                exit(1);

            default:
                break;
        }
    }


    return 0;
}

FILE * open(){
    FILE *archivo;
    archivo = fopen("agenda.dat", "a+b");

    if(archivo == NULL){
        printf("El archivo no ha podido abrirse");
        exit(1);
    }
    fseek(archivo, 0, SEEK_SET);
    return archivo;
}

int options(){
    int opt;

    printf("Escoga una opción:\n");
    printf("1. Añadir nuevo contacto\n");
    printf("2. Buscar contacto\n");
    printf("3. Listar todos los contactos\n");
    printf("4. Modificar contacto\n");
    printf("5. Borrar un contacto\n");
    printf("6. Salir\n\n");
    scanf("%i", &opt);

    return opt;
}


void add(){
    FILE *archivo;
    User usr;

    archivo = open(archivo);

    printf("Introduzca los siguientes datos:\n");

    printf("ID\n");
    scanf("%i", &usr.id);

    printf("Nombre\n");
    gets(usr.nombre);
    gets(usr.nombre);
    
    printf("Telefono:\n");
    gets(usr.telf);
    
    printf("Direccion:\n");
    gets(usr.dir);
    
    printf("Mail:\n");
    gets(usr.mail);
    
    usr.activo = 1;
    fwrite(&usr, sizeof(User), 1, archivo);

    fclose(archivo);
}

void list(){
    FILE *archivo;
    User usr;
    int n;

    archivo = open(archivo);

    printf("ID NOMBRE DIRECCIÓN TELÉFONO E-MAIL\n");
    printf("-------------------------------------------------------------------------\n");
    while(!feof(archivo)){
        n = fread(&usr, sizeof(User), 1, archivo);
        if(n>0 && usr.activo==1){
            printf("%i %s %s %s %s\n\n", usr.id,  usr.nombre, usr.dir, usr.telf, usr.mail);
        }
    }

    fclose(archivo);
}


void find(){
    FILE *archivo;
    User usr;
    int id=0, n, band=0;

    archivo = open(archivo);
    printf("Por favor ingrese el id a buscar\n");
    scanf("%i", &id);

    while(!feof(archivo)){
        n = fread(&usr, sizeof(User), 1, archivo);

        if(n>0 && usr.activo == 1 && usr.id == id){
            printf("Usuario encontrado\n");
            printf("%i %s %s %s %s\n\n", usr.id,  usr.nombre, usr.dir, usr.telf, usr.mail);
            band = 1;
        }
    }

    if(!band){
        printf("Lo sentimos el usuario no existe\n\n");
    }

    fclose(archivo);
}


void modify(){
    FILE *archivo;
    User usr;
    int id=0, n, band=0, idx=0;

    archivo = open(archivo);
    printf("Por favor ingrese el id a modificar\n");
    scanf("%i", &id);

    while(!feof(archivo)){
        n = fread(&usr, sizeof(User), 1, archivo);
        
        if(n>0){
            idx++;
        }

        if(n>0 && usr.id == id){
                fseek(archivo, (idx-1) * sizeof(User), SEEK_SET);
                printf("Introduzca los siguientes datos:\n");

                printf("ID\n");
                scanf("%i", &usr.id);

                printf("Nombre\n");
                gets(usr.nombre);
                gets(usr.nombre);
                
                printf("Telefono:\n");
                gets(usr.telf);
                
                printf("Direccion:\n");
                gets(usr.dir);
                
                printf("Mail:\n");
                gets(usr.mail);

                usr.activo = 1;
                fwrite(&usr, sizeof(User), 1, archivo);
                fseek(archivo, idx * sizeof(User), SEEK_SET);
                printf("Datos modificados con exito");
        }
    }

    fclose(archivo);
}


void delete(){
    FILE *archivo;
    int id, n, idx;
    User usr;

    archivo = open(archivo);

    printf("Ingrese el ID del archivo a borrar");
    scan("%i", &id);

    while(!feof(archivo)){
        n = fread(&usr, sizeof(User), 1, archivo);

        if(n>0){
            idx++;
        }

        if(n>0 &&usr.id == id){
            usr.activo = 0;
            fseek(archivo, (idx-1)*sizeof(User), SEEK_SET);
            fwrite(&usr, sizeof(User), 1, archivo);
            fseek(archivo, idx * sizeof(User), SEEK_SET);
        }
    }
}
