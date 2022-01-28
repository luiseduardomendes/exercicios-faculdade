#include <stdio.h>
#include <stdlib.h>
#include "circularList.h"

int main(){
    t_data dataList[MAX_SIZE_LIST], data;
    t_descriptor desc;
    

    generateRandomList(dataList, &desc);
    
    dataList[8].identifier = 0;

    displayList(dataList, desc);

    shiftListLeft(dataList, &desc, 8);
    
    displayList(dataList, desc);


    

    return 0;
}