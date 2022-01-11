#include <iostream>

using namespace std;

class Node
{
    public:
        int row;
        int col;
        int data;
};

class SparseMatrix
{
    private:
        int ncols;
        int nrows;
        int nelements;

    public:
        Node *ele;
        SparseMatrix(){}

        SparseMatrix(int nrows, int ncols, int nelements){
            this->ncols = ncols;
            this->nrows = nrows;
            this->nelements = nelements;
            ele = new Node[nelements];
        }
        ~SparseMatrix(){
            delete [] ele;
        }

        //Sobrecarga de operadores
        SparseMatrix operator+(SparseMatrix &sm);
        friend ostream & operator<<(ostream &os,SparseMatrix &sm);
};

//Sobrecargamos un operador en C+++
ostream & operator<<(ostream &os,SparseMatrix &sm){
    int k = 0;
    cout<<endl;
    for(int i=0; i<sm.nrows; i++){
        for(int j=0; j<sm.ncols; j++){
            if(i == sm.ele[k].row && j == sm.ele[k].col){
                cout<<sm.ele[k++].data<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
    cout<<endl;
    }
    return os;
};

SparseMatrix SparseMatrix::operator+(SparseMatrix &sm)
{
    int i,j,k;
    SparseMatrix *sm_sum = new SparseMatrix(nrows, ncols, nelements+ sm.nelements);

    
    if(nrows != sm.nrows || ncols != sm.ncols){
            cout<<"Las matrices tienen distintas dimensiones";
            exit(-1);
    }

    i=j=k=0;
     while(i<nelements && j<sm.nelements){
        if(ele[i].row<sm.ele[j].row){
            sm_sum->ele[k++]=ele[i++];
        }

        else if(ele[i].row > sm.ele[j].row){
            sm_sum->ele[k++]=sm.ele[j++];
        }
        else{
            if(ele[i].col<sm.ele[j].row){
                sm_sum->ele[k++]=ele[i++];
            }
            else if(ele[i].col > sm.ele[j].col){
                sm_sum->ele[k++]=sm.ele[j++];
            }
            else{
                sm_sum->ele[k]=ele[i];
                sm_sum->ele[k++].data=ele[i++].data+sm.ele[j++].data;
            }
        }
     }

        for(;i<nelements;i++){
            sm_sum->ele[k++]=ele[i];
        }
        for(;j<sm.nelements;j++){
            sm_sum->ele[k++]=sm.ele[j];
        }
        
        sm_sum->nelements=k;

        return *sm_sum;
}
