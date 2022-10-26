#include <iostream>
#include <vector>
#include <string>

void print(std::string str){
    for(auto it : str){
        std::cout << it << std::endl;
    }
}

int main(){
    print("Hello, World!");
    return 0;
}