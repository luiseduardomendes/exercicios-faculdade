#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int buffer_int;
    int N;
    vector<int> R;
    int i;

    cin >> N;
    for (i = 0; i < N; i ++){
        cin >> buffer_int;
        R.push_back(buffer_int);
    }

    sort(R.begin(), R.end());

    for (i = N; i > 0 && R[i-1] > N-i; i --){}
    cout << N - i << endl;

    return 0;
}