#include "circularList.h"


/*

void createList(t_data *dataList, t_descriptor *descript){
    int i;
    
    descript->indexBeg = -1;
    descript->indexEnd = -1;
    descript->size = 0;

    for (i = 0; i < MAX_SIZE_LIST; i ++){
        dataList[i].identifier = NULL_VALUE_ID;
        dataList[i].role = -1;
        strcpy(dataList[i].name, "");
    }
}

bool insertElement(t_data *dataList, t_descriptor *descript, int position, t_data element){
    bool error = false;

    int insertionPos = position + descript->indexBeg;
    if(insertionPos >= MAX_SIZE_LIST){
        insertionPos -= MAX_SIZE_LIST;
    }
    
    if(isListNotFull(dataList, *descript)){
        if(isListEmpty(*descript)){
            dataList[insertionPos + 1] = element;
            descript->indexBeg = insertionPos + 1;
            descript->indexEnd = insertionPos + 1;
            descript->size = 1;
        }
        else{
            if (isPositionValid(dataList, *descript, insertionPos)){
                if(!isPositionEmpty(dataList, *descript, insertionPos)){
                    if(isPositionEmpty(dataList, *descript, MAX_SIZE_LIST - 1)){
                        shiftListRight(dataList, descript, insertionPos);
                    }
                    else{
                        shiftListLeft(dataList, descript, insertionPos);
                    }
                }
                (descript->size) += 1;
                dataList[insertionPos] = element;
            }
            else    
                error = true;
        }
    }
    return !error;    
}

bool isPositionValid(t_data *t_dataList, t_descriptor descript, int position){
    bool valid = false;
    if (position >= 0 && position < MAX_SIZE_LIST)
        valid = true;

    return valid;
}

bool isListNotFull(t_data *t_dataList, t_descriptor descript){
    bool valid = true;
    if (descript.size <= MAX_SIZE_LIST)
        valid = false;

    return valid;
}
*/
bool isListEmpty(t_descriptor descript){
    bool isEmpty = false;
    if (descript.size == 0)
        isEmpty = true;
        
    return isEmpty;
}
/*
bool isPositionEmpty(t_data *dataList, t_descriptor descript, int position){
    if(dataList[position].identifier != NULL_VALUE_ID)
        return false;
    return true;
}

bool shiftListRight(t_data *dataList, t_descriptor *descript, int fromWhere){
    int i, flag;
    
    if(isListEmpty(*descript) && isPositionValid(dataList, *descript, fromWhere)){ 
        for (i = descript->indexEnd; i >= fromWhere; i --){
            dataList[i] = dataList[i-1]; 
        }
        (descript->indexEnd)++;
        flag = true;
    }
    else{
        flag = false;
    }
    return flag;
}
*/
bool shiftListLeft(t_data *dataList, t_descriptor *descript, int fromWhere){
    int i, flag;
    t_data buffer;
    
    if (!isListEmpty(*descript)){
        i = fromWhere; 
        if (i == MAX_SIZE_LIST - 1)
            dataList[i] = dataList[0];
        else    
            dataList[i] = dataList[i+1];
        i++;
        do{
            if (i == MAX_SIZE_LIST - 1){
                buffer = dataList[i];
                dataList[i] = dataList[0];
                dataList[0] = buffer;
                i = 0;
            }
            else{
                buffer = dataList[i];
                dataList[i] = dataList[i+1];
                dataList[i+1] = buffer;
                i++;
            }
        } while(i != descript->indexEnd);
        dataList[i].identifier = 0;
        
        (descript->indexEnd) --;
    }else
        return false;
    
    return true;
}


void displayList(t_data *dataList, t_descriptor descriptor){
    int i;
    
    /*for (i = descriptor.indexBeg; i != descriptor.indexEnd; i ++){
        printf("%d\t", dataList[i].identifier);
        if (i == MAX_SIZE_LIST - 1)
            i = -1;
    }*/
    for(i = 0; i < MAX_SIZE_LIST; i ++)
        printf("%d  ", dataList[i].identifier);
    printf("\n");
}

void generateRandomList(t_data *dataList, t_descriptor *descript){
    int i;
    descript->indexBeg = 7;
    descript->indexEnd = 3;
    descript->size = 0;

    for (i = 0; i < MAX_SIZE_LIST; i ++){
        dataList[i].identifier = 0;
        dataList[i].role = -1;
        strcpy(dataList[i].name, "");
    }

    for (i = descript->indexBeg; i != descript->indexEnd; i ++){
        dataList[i].identifier = rand() % 10;
        if (i == MAX_SIZE_LIST - 1)
            i = -1;
        (descript-> size) ++;
    }
        
}