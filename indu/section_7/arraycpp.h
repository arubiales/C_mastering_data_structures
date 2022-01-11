#include <iostream>

using namespace std;

template<class T>

class Array
{
    private:
        T *A;
        int size;
        int length;
        void swap(int *x, int *y);
    
    public:
        Array(int sz){
            this->size = sz;
            this->length = 0;
            this->A = new T[size];
        }

        ~Array(){
            delete []A;
        }

        void print(){
            for(int i=0; i<length; i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }

        void append(T value){
            if(length+1 <= size){
                A[length++] = value;
            }
        }

        void pop(){
            if(length > 0){
                A[length-1] = 0;
                length--;
            }
        }

        void del(int idx){
            for(int i=idx; i<length-1; i++){
                A[i] = A[i+1];
            }
            A[length--] = 0;
        }

        void insert(int idx, T value){
            int i=length;
            
            for(int i=length; i>idx-1; i--){
                A[i] = A[i-1];
            }
            
            A[idx] = value;
            length++;
        }

        int search(T value){
            for(int i=0; i<length; i++){
                if(A[i] == value){
                    return i;
                }
            }
            return -1;
        }

        int get(int idx){
            return A[idx];
        }

        int max(){
            int max = A[0];
            for(int i=1; i<length; i++){
                if(max < A[i]){
                    max = A[i];
                }
            }
            return max;
        }
    

        int min(){
            int max = A[0];
            for(int i=1; i<length; i++){
                if(max > A[i]){
                    max = A[i];
                }
            }
            return max;
        }

        T sum(){
            T summatory;
            for(int i=0; i<length; i++){
                summatory += A[i];
            }
            return summatory;
        }

        float avg(){
            return (float)sum()/length;
        }

        void reverse(){
            int idx_temp=0;
            Array temp_array(length);

            for(int i=length-1; i>-1; i--){
                temp_array.A[idx_temp++] = A[i];
            }

            for(int i=0; i<length; i++){
                A[i] = temp_array.A[i];
            }
            
            temp_array.~Array();
        }

        void concat(Array vect){
            int total_length = length + vect.length;
            int idx_vector=0;

            if(size > total_length){
                for(int i=length; i<total_length; i++){
                    A[i] = vect.A[idx_vector];
                    idx_vector++;
                    length++;
                }
            }
        }
};

