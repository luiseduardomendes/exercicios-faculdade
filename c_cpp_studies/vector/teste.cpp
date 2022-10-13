#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void sort(vector<int> &temp_arr);

int main(int argv, char** argc){
    vector<int> 
        array, 
        temp_arr;
    int 
        max_rand = 10, 
        size_arr = 10;
    
    cout << "Before changes: " << endl;
    for (int i = 0; i < size_arr; i++){
        array.push_back(rand() % max_rand);
        temp_arr.push_back(0);
        cout << array[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < temp_arr.size(); i++)
        cout << temp_arr[i] << " ";
    cout << endl;
    
    copy(array.begin(), array.end(), temp_arr.begin());

    cout << "After changes: " << endl;
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
    for (int i = 0; i < array.size(); i++)
        cout << temp_arr[i] << " ";
    cout << endl;
    
    sort(temp_arr);

    
    cout << "After changes: " << endl;
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
    for (int i = 0; i < array.size(); i++)
        cout << temp_arr[i] << " ";
    cout << endl;
    
    return 0;

}

void sort(vector<int> &temp_arr){
    sort(temp_arr.begin(), temp_arr.end());
}