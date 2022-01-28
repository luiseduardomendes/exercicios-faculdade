#include <stdio.h>
#include <stdlib.h>
#include "linearListWDescript.h"

int main(){
    t_data dataList[MAX_SIZE_LIST], data;
    t_descriptor desc;
    desc.indexBeg = 10;
    desc.indexEnd = 20;

    generateRandomList(dataList, &desc);

    displayList(dataList, desc);

    data.identifier = 1;
    data.name[0] = 'o';
    data.name[1] = 'i';
    data.value = 1;


    if (insertElement(dataList, &desc, 15, data))
        displayList(dataList, desc);

    return 0;
}