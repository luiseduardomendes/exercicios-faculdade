#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int E[3], X;

    for (int i = 0; i < 3; i ++)
        cin >> E[i];
    cin >> X;

    if (abs(E[0] - E[1]) <= X)
        cout << E[1];
    else
        cout << E[2];
    return 0;
}