#include "queue.h"

tDescriptor *queue_init(void){
    tDescriptor desc;
    
    return malloc(sizeof(tDescriptor));
}

bool queue_isEmpty(tDescriptor *descriptor){
    if(descriptor->first == NULL)
        return true;
    else
        return false;
}

bool queue_push(tDescriptor *descriptor, tData data){
    tQueueNode *newNode = NULL;

    newNode = malloc(sizeof(tQueueNode));
    newNode->data = data;

    if(queue_isEmpty(descriptor)){
        newNode->prev = NULL;
        newNode->next = NULL;
        descriptor->first = newNode;
        descriptor->last = newNode;
    }
    
    else{
        newNode->prev = descriptor->last;
        newNode->next = NULL;
        descriptor->last->next = newNode;
        descriptor->last = newNode;
    }

    return true;
}

bool queue_pop(tDescriptor *descriptor, tData *data){
    tQueueNode *buffer = NULL;

    if (!queue_isEmpty(descriptor)){
        if(data != NULL)
            *data = descriptor->first->data;
        buffer = descriptor->first;
        descriptor->first = descriptor->first->next;
        free(buffer);
        return true;
    }
    else
        return false;
}

tData queue_first(tDescriptor *descriptor){
    if (!queue_isEmpty(descriptor))
        return descriptor->first->data;
    else
        return 0;
}

tDescriptor *queue_clear(tDescriptor *descriptor){

    while (descriptor->first != NULL)
        queue_pop(descriptor, NULL);

    return descriptor;
}

tData queue_inputNode(){
    tData data;
    scanf("%d", &data);
    return data;
}