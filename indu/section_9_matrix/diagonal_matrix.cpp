#include <iostream>

using namespace std;



class Diagonal{
    private:
        int n;
        int * A;
    
    public:
        Diagonal(){
            this->n = 1000;
            A = new int[n];
        }

        Diagonal(int n){
            this->n = n;
            A = new int[n];
        }

        ~Diagonal(){
            delete []A;
        }

        void set(int i, int j, int value){
            if(i==j){
                A[i] = value;
            }
        }

        int get(int i, int j){
            if(i==j){
                return A[i];
            }
        }

        void show(){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j){
                        cout<<" "<<A[i];
                    } 
                    else{
                        cout<<" "<<0;
                    }
                }
                cout<<endl;
            }
        }
};


int main(){
    Diagonal dg(5);

    dg.set(0, 0, 1);
    dg.set(1, 1, 2);
    dg.set(2, 2, 4);
    dg.set(3, 3, 7);
    dg.set(4, 4, 9);

    cout<<"Displayeamos elemento: "<<dg.get(3, 3)<<endl<<endl;
    dg.show();
    
}


