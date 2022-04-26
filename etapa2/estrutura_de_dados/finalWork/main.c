#include "readcsv/readcsv.h"
#include "readcsv/binary_search_tree.h"
#include <locale.h>
/*
int main(){
    bst_node *root;
    int values[6] = {1,5,2,6,3,7}, i, j;
    float data[1000], *data2, *index;

    data2 = read_csv("data.csv", data);
    index = data2;
    for (i = 0; i < 4; i ++){
        for (j = 0; j < 3; j ++)
            printf("%.3f\t", index[i*3+j]);
        printf("\n");
    }

    printf("\n");

    root = bst_init();

    for (i = 0; i < 6; i ++)
        root = bst_insert(root, values[i], NULL);

    return 0;   
}
*/

int main(){
    setlocale(0, "pt-BR");
    bst_node *str_bst, *busca;
    str_bst = bst_init();

    str_bst = read_txt("MachadoDeAssis.txt", str_bst);

    print_inorder_left(str_bst);

    busca = bst_search(str_bst, "método");

    printf("\n%d\t%s\n", busca->occurrences, busca->key);
    
    return 0;
}