// #include <stdio.h>
// #include <stdlib.h>



// int main(){
//     char cpy[2];
//     int mem_init = 10, mem_fill = 0;
//     char *texto;

//     texto = (char *)malloc(mem_init*sizeof(char));
//     if(texto == NULL){
//         printf("No se ha podido allocar memoria");
//         exit(1);
//     }

//     do{
//         gets(cpy);
//         if(cpy[0] != 27){
//             texto[mem_fill] = cpy[0];
//             mem_fill++;
//         }
//         if(mem_fill < mem_init-1){
//             texto = (char *)realloc(texto, 10);
//             mem_init+=10;
//             if(texto == NULL){
//                 printf("No se ha podido alocar más memoria");
//                 exit(1);
//             }
//         }
//     } while(cpy != '27'); //27 es la tecla de escape

//     printf("El texto introducido es\n\n%s", texto);

//     return 0;
// }


