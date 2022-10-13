#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> shellsort (vector<int> & array){
    int x, N, h, t, i, j;

    N = array.size();
    
    x = 3;
    while (h < int(N / 3))
        h = 3 * h + 1;

    while (h >= 1){
        for (int i = h; i < N; i ++){
            t = array[i];
            j = i;
            while (j >= h && t < array[j - h]){ 
                array[j] = array[j-h];
                array[j-h] = t;
                j -= h;
            }
        }
        h = int(h / x);
    }

    return array;
}

int* shellsort_2 (int array[], int size){
    int h, t, i, j;
    
    while (h < int(size / 3))
        h = 3 * h + 1;

    while (h >= 1){
        for (int i = h; i < size; i ++){
            t = array[i];
            j = i;
            while (j >= h && t < array[j - h]){ 
                array[j] = array[j-h];
                array[j-h] = t;
                j -= h;
            }
        }
        h = int(h / 3);
    }

    return array;
}
#define max 1000000

int main(int argc, char **argv){
    time_t begin, end;
    vector<int> array;
    int array2[max];
    int rand_max = 1000000;

    for (int i = 0; i < max; i ++){
        array.push_back(rand() % rand_max);
        array2[i] = array[i];
    }

    begin = clock();
    shellsort(array);
    end = clock();

    cout << double(begin - end)/CLOCKS_PER_SEC << endl;

    begin = clock();
    shellsort_2(array2, max);
    end = clock();

    cout << double(begin - end)/CLOCKS_PER_SEC << endl;
    
    return 0;
}