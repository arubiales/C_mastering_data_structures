#include <stdio.h>

long factorial(int n);

int main(){
    printf("%li\n", factorial(4));
    
    return 0;
}

long factorial(int n){
    if(n<=1){
        return n;
    } else{
        return n*factorial(n-1);
    }

}
