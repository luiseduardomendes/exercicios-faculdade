#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE_LIST 50
#define NULL_VALUE_ID -1

typedef struct Data{
    char name[10];
    int identifier;
    float value;
}Data;

void createList(Data *dataList, int *listBegin, int *listEnd);

bool insertElement(Data *dataList, int *listBegin, int *listEnd, int position, Data element);

bool isPositionValid(Data *dataList, int listBegin, int listEnd, int position);

bool isListNotFull(Data *dataList, int listBegin, int listEnd);

bool isListEmpty(int listBegin, int listEnd);

bool shiftListRight(Data *dataList, int *listBegin, int *listEnd, int fromWhere);

bool shiftListLeft(Data *dataList, int *listBegin, int *listEnd, int fromWhere);

void displayList(Data *dataList, int listBegin, int listEnd);

void generateRandomList(Data *dataList, int *listBegin, int *listEnd);