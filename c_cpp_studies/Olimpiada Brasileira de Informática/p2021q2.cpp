#include <iostream>
#include <cmath>
int main(){
    int a=69961,b=487920;
    int bufferA, bufferB;
    int outA=0, outB=0;
    int iA=0, iB=0;
    
    while (a!=0 || b!=0){
        bufferA = a%10;
        bufferB = b%10;

        std::cout << bufferA << " " << bufferB << std::endl;

        if (bufferA < bufferB){
            outB += bufferB * pow(10,iB);
            iB ++;
        }
        else if (bufferA > bufferB){
            outA += bufferA * pow(10,iA);
            iA ++;
        }
        else{
            outA += bufferA * pow(10,iA);
            iA ++;
            outB += bufferB * pow(10,iB);
            iB ++;
        }

        a = a/10;
        b = b/10;
    }

    if (outA == 0)
        outA --;
    
    if (outB == 0)
        outB --;
    
    std::cout << outA << std::endl;
    std::cout << outB << std::endl;
    
    return 0;
}

