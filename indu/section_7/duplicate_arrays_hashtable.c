#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void count_duplicated(char *);


int main(){

    char A[]="finding";

    count_duplicated(A);



    return 0;
}


void count_duplicated(char *word){
    int ascii_hash_table[26];

    for(int i=0; i<26; i++){
        ascii_hash_table[i] = 0;
    }

    for(int i=0; i<strlen(word)-1; i++){
        ascii_hash_table[word[i]-97]++;
    }

    for(int i=0; i<26; i++){
        if(ascii_hash_table[i] > 1){
            printf("El caracter %c está duplicado %i vez/veces\n", i+97, ascii_hash_table[i]-1);
        }
    }
}
