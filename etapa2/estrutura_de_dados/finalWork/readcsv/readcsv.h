#include "binary_search_tree.h"

#define MAX_C 32
#define MAX_R 2048
#define MAX_W 4096
#define SIZE_WORD 32

float* read_csv(char *filename, float data[]);
bst_node* read_txt(char *filename, bst_node* str_bst);