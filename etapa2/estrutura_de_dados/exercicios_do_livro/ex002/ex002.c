#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

int main(){
    Data dataList[MAX_SIZE_LIST], data;
    int listBegin = 10, listEnd = 20;

    generateRandomList(dataList, &listBegin, &listEnd);

    displayList(dataList, listBegin, listEnd);

    data.identifier = 1;
    data.name[0] = 'o';
    data.name[1] = 'i';
    data.value = 1;


    if (insertElement(dataList, &listBegin, &listEnd, 15, data)){
        displayList(dataList, listBegin, listEnd);
    }


    return 0;
}