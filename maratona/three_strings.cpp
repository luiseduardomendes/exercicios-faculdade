#include <bits/stdc++.h>

using namespace std;

string a, b, c;
int n;

int main(){
    int i, j;
    cin >> n;

    for (i = 0; i < n; i ++){
        cin >> a;
        cin >> b;
        cin >> c;

        bool flag = true;
        for (j = 0; j < a.size(); j ++){
            if (a[j] != c[j] && b[j] != c[j]){
                flag = false;
            }
         
        }
        if (flag) cout << "YES" << endl; else cout << "NO" << endl;
    }


    return 0;
}