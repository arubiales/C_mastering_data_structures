#include "c++smatrix.h"


int main(){
    SparseMatrix s1(3,3,2);
    SparseMatrix s2(3,3,2);

    s1.ele->row = 0;
    s1.ele->col = 0;
    s1.ele->data = 7;

    s1.ele->row = 2;
    s1.ele->row = 3;
    s1.ele->data = 4;
    

    s2.ele->row = 0;
    s2.ele->col = 0;
    s2.ele->data = 1;

    s2.ele->row = 1;
    s2.ele->row = 1;
    s2.ele->data = 9;





    SparseMatrix sm_sum= s1 + s2;
    cout<<s1;
    cout<<s2; 
    cout<<sm_sum;

    return 0;
}
