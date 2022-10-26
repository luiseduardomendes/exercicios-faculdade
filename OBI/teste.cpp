#include <regex>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str = "top10 'ST'";
    std::smatch matches;
    std::regex top10_reg ("top([0-9]+) '([^.]+)'");
    
    if (regex_search(str, matches, top10_reg)){
        int p = matches.str().find(' ');
        int n = atoi(matches.str().substr(3, p).c_str());
        string pos = matches.str().substr(p+2);
        pos.pop_back();
        cout << n << " " << pos << endl;
    }
    
    return 0;
}
