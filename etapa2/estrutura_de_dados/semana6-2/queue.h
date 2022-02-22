#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int tData;

typedef struct tQueueNode{
    tData data;
    struct tQueueNode *prev;
    struct tQueueNode *next;
} tQueueNode;

typedef struct tDescriptor{
    tQueueNode *first;
    tQueueNode *last;
} tDescriptor;

tDescriptor *queue_init(void);

bool queue_isEmpty(tDescriptor *descriptor);

bool queue_push(tDescriptor *descriptor, tData data);

bool queue_pop(tDescriptor *descriptor, tData *data);

tData queue_first(tDescriptor *descriptor);

tDescriptor *queue_clear(tDescriptor *descriptor);

tData queue_inputNode();