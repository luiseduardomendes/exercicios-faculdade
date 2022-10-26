#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> split_atoi(string str, char sep);
int verify_subseq(vector<int> S, int E, int D);
vector<int> set_dividers(int a);

int main(){
    int N; // number of elements in the sequence
    int M; // number of operations
    vector<int> S;
    vector<int> buffer;
    vector<int> out;
    string buff_in;
    int buff_int;

    buffer.assign(3,0);

    getline(cin, buff_in);
    S = split_atoi(buff_in, ' ');
    N = S[0];
    M = S[1];
    
    getline(cin, buff_in);
    S = split_atoi(buff_in, ' ');

    for (int i = 0; i < M; i ++) {
        cin >> buffer[0] >> buffer[1] >> buffer[2];
        switch (buffer[0]){
            case 1:{
                int I = buffer[1] - 1;
                int V = buffer[2];
                S[I] = V;
                break;
            }
            case 2:{
                int E = buffer[1] - 1;
                int D = buffer[2] - 1;
                out.push_back(verify_subseq(S, E, D));
                break;
            }        
        }
    }
    for (auto it = out.begin(); it != out.end(); it ++)
        cout << *it << endl;
    
    return 0;
}

vector<int> split_atoi(string str, char sep){
    vector<int> token;
    size_t start = 0, end = 0;

    while ((end = str.find(sep, start)) != string::npos){
        token.push_back(atoi(str.substr(start, end-start).c_str()));
        start = end + 1;
    }
    token.push_back(atoi(str.substr(start).c_str()));
    
    return token;
}

int verify_subseq(vector<int> S, int E, int D) {
    int count = 0;

    for (int i = E; i <= D; i ++){
        for (int j = i; j <= D; j ++){
            bool divider = true;
            for (int k = i; k <= j; k ++){
                if (S[k] % S[i] != 0){
                    divider = false;
                    break;
                }
            }
            if (divider){
                count ++;
            }  
            else{          
                for (int d = sqrt(S[i]); d >= 2; d --){
                    if (S[i] % d == 0){  
                        divider = true;
                        for (int k = i; k <= j; k ++){
                            if (S[k] % d != 0){
                                divider = false;
                                break;
                            }
                        }
                        if (divider){
                            count ++; 
                            break;
                        } 
                    }
                }
            }
        }
    }
    return count;
}
