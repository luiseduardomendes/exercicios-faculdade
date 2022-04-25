#include "../DataStructLib/binary_search_tree.h"
#include "readcsv/readcsv.h"

int main(){
    bst_node *root;
    int values[6] = {1,5,2,6,3,7}, i;

    read_csv("data.csv", 3);    

    root = bst_init();

    for (i = 0; i < 6; i ++)
        root = bst_insert(root, values[i], NULL);

    return 0;   
}