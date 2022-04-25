#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int tData;

typedef struct tStackNode {
    tData data;
    struct tStackNode *prev;
}tStackNode;

tStackNode *stack_init(void);

bool stack_isEmpty(tStackNode *top);

bool stack_push(tStackNode **top, tData data);

bool stack_pop(tStackNode **top, tData *data);

tData stack_top(tStackNode *top);

tStackNode *stack_clear(tStackNode *top);

tData stack_inputNode();