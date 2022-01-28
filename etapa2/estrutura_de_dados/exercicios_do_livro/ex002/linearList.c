#include "linearList.h"

void createList(Data *dataList, int *listBegin, int *listEnd){
    int i;
    
    *listBegin = -1;
    *listEnd = -1;

    for (i = 0; i < MAX_SIZE_LIST; i ++){
        dataList[i].identifier = NULL_VALUE_ID;
        dataList[i].value = 0.0;
        strcpy(dataList[i].name, "");
    }
}

bool insertElement(Data *dataList, int *listBegin, int *listEnd, int position, Data element){
    bool error = false;
    
    if(isListNotFull(dataList, *listBegin, *listEnd)){
        if(isListEmpty(*listBegin, *listEnd)){
            dataList[0] = element;
            *listBegin = 0;
            *listEnd = 1;
        }
        else{
            if (isPositionValid(dataList, *listBegin, *listEnd, position)){
                if(position - *listBegin > *listEnd - position){
                    if (*listEnd < MAX_SIZE_LIST){
                        shiftListRight(dataList, listBegin, listEnd, position);
                    }else error = true;
                }
                else{
                    if (*listBegin > 0){
                        shiftListLeft(dataList, listBegin, listEnd, position);
                    }else error = true;
                }
                dataList[position] = element;
            }
            else    
                error = true;
        }
    }
    return !error;
    
    
    
}

bool isPositionValid(Data *dataList, int listBegin, int listEnd, int position){
    bool valid = false;
    if (position >= 0)
        if(position >= listBegin && position <= listEnd)
            valid = true;

    return valid;
}

bool isListNotFull(Data *dataList, int listBegin, int listEnd){
    bool valid = true;
    if (listBegin == 0 && listEnd == MAX_SIZE_LIST)
        valid = false;

    return valid;
}

bool isListEmpty(int listBegin, int listEnd){
    bool isEmpty = false;
    if (listBegin == listEnd)
        isEmpty = true;
        
    return isEmpty;
}

bool shiftListRight(Data *dataList, int *listBegin, int *listEnd, int fromWhere){
    int i, flag;
    
    if(*listEnd < MAX_SIZE_LIST && isPositionValid(dataList, *listBegin, *listEnd, fromWhere)){ 
        for (i = *listEnd; i >= fromWhere; i --){
            dataList[i] = dataList[i-1]; 
        }
        (*listEnd)++;
        flag = true;
    }
    else{
        flag = false;
    }
    return flag;
}

bool shiftListLeft(Data *dataList, int *listBegin, int *listEnd, int fromWhere){
    int i, flag;
    
    if(*listBegin > 0 && isPositionValid(dataList, *listBegin, *listEnd, fromWhere)){ 
        for (i = *listBegin; i <= fromWhere; i ++){
            dataList[i-1] = dataList[i]; 
        }
        (*listBegin) --;
        flag = true;
    }
    else{
        flag = false;
    }
    return flag;
}

void displayList(Data *dataList, int listBegin, int listEnd){
    int i;
    
    for (i = listBegin; i < listEnd; i ++)
        printf("%.2f \t", dataList[i].value);
    printf("\n");
}

void generateRandomList(Data *dataList, int *listBegin, int *listEnd){
    int i;

    for (i = *listBegin; i < *listEnd; i ++)
        dataList[i].value = rand() % 10;
}