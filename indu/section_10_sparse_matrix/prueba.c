#include "smatrix.h"


int main(){
    SparseMatrix *smatrix1 = __init__(3, 3, 2);
    SparseMatrix *smatrix2 = __init__(3, 3, 2);
    SparseMatrix *smatrix3;


    smatrix1->element[0].row = 0;
    smatrix1->element[0].col = 0;
    smatrix1->element[0].data = 1;

    smatrix1->element[1].row = 1;
    smatrix1->element[1].col = 2;
    smatrix1->element[1].data = 7;

    smatrix2->element[0].row = 0;
    smatrix2->element[0].col = 1;
    smatrix2->element[0].data = 3;

    smatrix2->element[1].row = 1;
    smatrix2->element[1].col = 2;
    smatrix2->element[1].data = 2;

    show(smatrix1);    
    show(smatrix2);    

    smatrix3 = sum(smatrix1, smatrix2);
    show(smatrix3);

    return 0;
}
