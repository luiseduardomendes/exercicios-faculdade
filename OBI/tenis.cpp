#include <stdio.h>
#include <iostream>

int main(){
    int menor;
    int n[4];
    int i, j, temp;

    for (i = 0; i < 4; i ++){
        std::cin >> n[i];
    }
    
    for (i = 0; i < 4; i ++){
        menor = i;
        for (j = i; j < 4; j ++){
            if (n[menor] > n[j])
                menor = j;
        }
        temp = n[menor];
        n[menor] = n[i];
        n[i] = temp;
    }

    std::cout << abs(n[3]+n[0]-(n[1]+n[2])) << std::endl;
    
    return 0;
}