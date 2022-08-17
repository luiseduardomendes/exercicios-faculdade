#include <vector>
#include <iostream>

using namespace std;


template <class Comparable>
int max_elem(const vector<Comparable> A){
    int k = A[0];
    for (int i = 1; i < A.size(); i ++)
        if (k < A[i])
            k = A[i];
    return k;
}

template <class Comparable>
void cout_vector(const vector<Comparable> A){
    for (int i = 0; i < A.size(); i ++)
        cout << A[i] << " ";
    cout << endl;
}

template <class Comparable>
void counting_sort(const vector<Comparable> &A, vector<Comparable> &B){
    vector<Comparable> C;
    int k;
    
    k = max_elem(A) + 1;

    C.assign(k, 0);

    for (int i = 0; i < A.size(); i++)
        C[A[i]] ++;

    for (int i = 1; i < k; i ++)
        C[i] = C[i] + C[i-1];   

    for (int i = A.size()-1; i >= 0; i --){
        C[A[i]] --;
        B[C[A[i]]] = A[i];
    }
}


int main(int argv, char ** argc){
    vector<int> A = {2,5,3,1,2,3,1,3};
    vector<int> B = {0,0,0,0,0,0,0,0};

    counting_sort(A, B);

    return 0;
}
