#include <iostream>
#include <vector>
#include <string>

enum {bombacha, bota, chapeu, lenco};
using namespace std;

vector<float> split_to_float(string str);
template <typename iterable>
void print_vector(vector<vector<iterable>> vect);
template <typename iterable>
void print_vector(vector<iterable> vect);
template <typename iterable>
int partition(vector<iterable> &v, vector<iterable> &v_aux, int begin, int end);
template <typename iterable>
void quicksort(vector<iterable> &v, vector<iterable> &v_aux, int begin, int end);

int main(){
    int H, S, C, P;
    double W;
    vector<vector<float>> d, z;
    vector<int> x;
    
    cin >> H >> S >> C >> P >> W;
    x.push_back(H);
    x.push_back(S);
    x.push_back(C);
    x.push_back(P);
    cin.get();
    
    for (int i = 0; i < 4; i ++){
        string temp;
        vector<float> a;

        for(int j = 0; j < x[i]; j++){
            float buff;
            cin >> buff; 
            a.push_back(buff);
        }
        d.push_back(a);

        a.clear();
        for(int j = 0; j < x[i]; j++){
            float buff;
            cin >> buff; 
            a.push_back(buff);
        }
        z.push_back(a);

    }
    for (int i = 0; i < 4; i ++){
        quicksort(d[i], z[i], 0, d.size());
    }

    

    return 0;
}

vector<float> split_to_float(string str){
    size_t begin = 0, end;
    vector<float> token;
    while (end = str.find(' ') != string::npos){
        token.push_back(atof(str.substr(begin, end).c_str()));
        begin = end + 1;
    }
    token.push_back(atof(str.substr(begin).c_str()));
    return token;
}

template <typename iterable>
void quicksort(vector<iterable> &v, vector<iterable> &v_aux, int begin, int end){
    if (begin < end){
        int p = partition(v, v_aux, begin, end);
        quicksort(v, v_aux, begin, p);
        quicksort(v, v_aux, p+1, end);
    }
}

template <typename iterable>
int partition(vector<iterable> &v, vector<iterable> &v_aux, int begin, int end){
    int pivot = begin;
    int partition = begin;
    for (int i = begin; i < end; i ++){
        if (v[pivot] < v[i]){
            partition ++;   
            iterable temp = v[partition];
            v[partition] = v[i];
            v[i] = temp;

            temp = v_aux[partition];
            v_aux[partition] = v_aux[i];
            v_aux[i] = temp;
        }
    }
    iterable temp = v[pivot];
    v[pivot] = v[partition];
    v[partition] = temp;

    temp = v_aux[partition];
    v_aux[partition] = v_aux[pivot];
    v_aux[pivot] = temp;
    return partition;
}

template <typename iterable>
void print_vector(vector<iterable> vect){
    for (iterable i : vect)
        std::cout << i << "\t";
    std::cout << endl;
}

template <typename iterable>
void print_vector(vector<vector<iterable>> vect){
    for (vector<iterable> list : vect){
        for (iterable i : list){
            cout << i << "\t";
        }
        cout << endl;
    }
    cout << endl;
}