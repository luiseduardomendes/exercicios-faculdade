#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE_LIST 50
#define NULL_VALUE_ID -1

typedef struct {
    int size;
    int indexBeg;
    int indexEnd;
}t_descriptor;

typedef struct {
    char name[10];
    int identifier;
    float value;
}t_data;

void createList(t_data *t_dataList, t_descriptor *descript);

bool insertElement(t_data *t_dataList, t_descriptor *descript, int position, t_data element);

bool isPositionValid(t_data *t_dataList, t_descriptor descript, int position);

bool isListNotFull(t_data *t_dataList, t_descriptor descript);

bool isListEmpty(t_descriptor descript);

bool shiftListRight(t_data *t_dataList, t_descriptor *descript, int fromWhere);

bool shiftListLeft(t_data *t_dataList, t_descriptor *descript, int fromWhere);

void displayList(t_data *t_dataList, t_descriptor descriptor);

void generateRandomList(t_data *t_dataList, t_descriptor *descript);