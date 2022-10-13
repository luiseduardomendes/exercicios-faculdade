#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int partition(vector<int> & array, int beg, int end){
    int pivot = array[beg];
    int part = beg;

    for (int j = beg+1; j <= end; j++){
        if (array[j] <= pivot){
            part++;
            swap(array[part], array[j]);
        }
    }
    swap(array[part], array[beg]);
    return part;
}

void quicksort_recursive(vector<int> & array, int beg, int end){
    int part;

    if (beg < end)
    {
        part = partition(array, beg, end);
        quicksort_recursive(array, beg, part-1);
        quicksort_recursive(array, part+1, end);
    }
}

void quicksort(vector<int> & array){
    quicksort_recursive(array, 0, array.size()-1);
}

int partition_2(int* array, int beg, int end){
    int pivot = array[beg];
    int part = beg;

    for (int j = beg+1; j <= end; j++){
        if (array[j] <= pivot){
            part++;
            swap(array[part], array[j]);
        }
    }
    swap(array[part], array[beg]);
    return part;
}

void quicksort_2_recursive(int* array, int beg, int end){
    int part;

    if (beg < end)
    {
        part = partition_2(array, beg, end);
        quicksort_2_recursive(array, beg, part-1);
        quicksort_2_recursive(array, part+1, end);
    }
}

void quicksort_2(int* array, int size){
    quicksort_2_recursive(array, 0, size-1);
}



#define max 1000000

int main(int argc, char** argv){
    time_t begin, end;
    vector<int> array;
    int array2[max];
    int rand_max = 1000000;

    begin = clock();
    quicksort(array);
    end = clock();

    cout << double(end - begin)/CLOCKS_PER_SEC << endl;

    begin = clock();
    quicksort_2(array2, max);
    end = clock();

    cout << double(end - begin)/CLOCKS_PER_SEC << endl;

    return 0;
}
