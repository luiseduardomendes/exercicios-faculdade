#include <bits/stdc++.h>

using namespace std;


short int k;
vector<short int> i;
short int j;
int main(){
    cin >> k;
    for(j = 0; j < 12; j ++){
        short int tmp;
        cin >> tmp;
        i.push_back(tmp);
    }
    
    sort(i.begin(), i.end());
    reverse(i.begin(), i.end());
    short int cont = 0;
    
    
    auto it = i.begin();
    j = 0;


    while (cont < k && it != i.end()){
        cont += *(it++);
        j ++;
    }
    if (cont >= k)
        cout << j << endl;
    else
        cout << "-1";
    
    return 0;
}