#include "linearListWDescript.h"

void createList(t_data *dataList, t_descriptor *descript){
    int i;
    
    descript->indexBeg = -1;
    descript->indexEnd = -1;
    descript->size = 0;

    for (i = 0; i < MAX_SIZE_LIST; i ++){
        dataList[i].identifier = NULL_VALUE_ID;
        dataList[i].value = 0.0;
        strcpy(dataList[i].name, "");
    }
}

bool insertElement(t_data *dataList, t_descriptor *descript, int position, t_data element){
    bool error = false;
    
    if(isListNotFull(dataList, *descript)){
        if(isListEmpty(*descript)){
            dataList[0] = element;
            descript->indexBeg = 0;
            descript->indexEnd = 1;
            descript->size = 1;
        }
        else{
            if (isPositionValid(dataList, *descript, position)){
                if(position - descript->indexBeg > descript->indexEnd - position){
                    if (descript->indexEnd < MAX_SIZE_LIST){
                        shiftListRight(dataList, descript, position);
                    }else error = true;
                }
                else{
                    if (descript->indexBeg > 0){
                        shiftListLeft(dataList, descript, position);
                    }else error = true;
                }
                descript->size += 1;
                dataList[position] = element;
            }
            else    
                error = true;
        }
    }
    return !error;    
}

bool isPositionValid(t_data *t_dataList, t_descriptor descript, int position){
    bool valid = false;
    if (position >= 0)
        if(position >= descript.indexBeg && position <= descript.indexEnd)
            valid = true;

    return valid;
}

bool isListNotFull(t_data *t_dataList, t_descriptor descript){
    bool valid = true;
    if (descript.indexBeg == 0 && descript.indexEnd == MAX_SIZE_LIST)
        valid = false;

    return valid;
}

bool isListEmpty(t_descriptor descript){
    bool isEmpty = false;
    if (descript.indexBeg == descript.indexEnd)
        isEmpty = true;
        
    return isEmpty;
}

bool shiftListRight(t_data *dataList, t_descriptor *descript, int fromWhere){
    int i, flag;
    
    if(descript->indexEnd < MAX_SIZE_LIST && isPositionValid(dataList, *descript, fromWhere)){ 
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

bool shiftListLeft(t_data *dataList, t_descriptor *descript, int fromWhere){
    int i, flag;
    
    if(descript->indexBeg > 0 && isPositionValid(dataList, *descript, fromWhere)){ 
        for (i = descript->indexBeg; i <= fromWhere; i ++){
            dataList[i-1] = dataList[i]; 
        }
        (descript->indexBeg) --;
        flag = true;
    }
    else{
        flag = false;
    }
    return flag;
}

void displayList(t_data *t_dataList, t_descriptor descriptor){
    int i;
    
    for (i = descriptor.indexBeg; i < descriptor.indexEnd; i ++)
        printf("%d\t%.2f\t%s\n", t_dataList[i].identifier, t_dataList[i].value, t_dataList[i].name);
    printf("\n");
}

void generateRandomList(t_data *t_dataList, t_descriptor *descript){
    int i;

    for (i = descript->indexBeg; i < descript->indexEnd; i ++)
        t_dataList[i].value = rand() % 10;
}