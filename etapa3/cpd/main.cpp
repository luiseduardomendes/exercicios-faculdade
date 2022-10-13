#include "hash_table.hpp"
#include <time.h>

int main(int argv, char **argc){
    srand(time(0));
    int size = 30;
    Hash::Hash_table hash_table = Hash::Hash_table(size);

    for (int i = 0; i < size; i ++){
        hash_table.insert(rand() % 100);
    }


    std::cout  <<  "Hello" << endl;
    hash_table.print();
    
    return 0;
}