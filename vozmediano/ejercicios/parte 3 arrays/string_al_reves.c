#include <stdio.h>
// #include <string.h>

int main(){
    char hola[] = "hola mundo";
    char hola_rev[1000];
    int length = 10, i=0;

    // printf("%i", length);
    // printf("%c", hola[1]);

    while(length>0){
        hola_rev[i] = hola[length-1];
        length--;
        i++;
    }
    
    // hola_rev[0] = '\0';


    // for(int i=10; i>0; i--){

    //     printf("%s", hola[i]);
    //     printf("hola");
    // }
    fflush(stdout); 
    printf("%s\n", hola_rev);

    return 0;
}


// #include <stdio.h>
// int main()
// {
//    char s[]="hola mundo", r[1000];
//    int begin, end, count = 0;


//    Calculating string length

//    while (s[count] != '\0')
//       count++;

//     printf("%i", count)
//     end = count - 1;

//    for (begin = 0; begin < count; begin++) {
//       r[begin] = s[end];
//       end--;
//    }

//    r[begin] = '\0';

//    printf("%s\n", r);

//    return 0;
// }

