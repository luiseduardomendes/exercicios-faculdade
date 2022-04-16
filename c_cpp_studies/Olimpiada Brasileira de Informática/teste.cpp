#include <iostream>
#include <vector>

int main(){
    std::vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);

    int i, num;
    for (i = 0; i < vect.size(); i ++){
        printf("%d\n", vect[i]);
    }


    return 0;
}