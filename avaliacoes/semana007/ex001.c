#include <string.h>
#include <stdio.h>
#define SIZE_NAME 51
#define NUM_PROD 3
#define NUM_BRANCH 3


int main() {
    char product_names[NUM_PROD][SIZE_NAME];
    int i;
    char name[SIZE_NAME];

    for (i = 0; i < NUM_PROD; i ++) {
        fgets(&name, SIZE_NAME, stdin);
        strcpy(product_names[i], name);
    }

    return 0;
}