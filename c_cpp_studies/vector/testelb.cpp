#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string text = {"5 1 2 3 4 5 \n"};

    vector<string> tokens;
    vector<int> array;
    size_t start = 0, end = 0;

    while (text[text.size()-1] < '0' || text[text.size()-1] > '9')
        text.erase(text.end()-1);
    
    while ((end = text.find(' ', start)) != string::npos){
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(text.substr(start));

    
    
    cout << text;

    cout << atoi(" ") << endl;
    

    cout << str;
    
    return 0;
}
