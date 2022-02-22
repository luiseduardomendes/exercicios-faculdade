#include "stack.h"

tStackNode *stack_init(void){
    return NULL;
}

bool stack_isEmpty(tStackNode *top){
    if(top == NULL)
        return true;
    else
        return false;
}

bool stack_push(tStackNode **top, tData data){
    tStackNode *newNode = NULL;

    newNode = malloc(sizeof(tStackNode));
    newNode->data = data;

    if(stack_isEmpty(*top))
        newNode->prev = NULL;
    
    else
        newNode->prev = *top;
        
    *top = newNode;
    return true;
}

bool stack_pop(tStackNode **top, tData *data){
    tStackNode *buffer = NULL;

    if (!stack_isEmpty(*top)){
        if(data != NULL)
            *data = (*top)->data;
        buffer = (*top);
        *top = (*top)->prev;
        free(buffer);
        return true;
    }
    else
        return false;
}

tData stack_top(tStackNode *top){
    if (!stack_isEmpty(top))
        return top->data;
    else
        return 0;
}

tStackNode *stack_clear(tStackNode *top){
    tStackNode *index = top, *buffer = top;

    while (index != NULL){
        buffer = index->prev; 
        free(index);
        index = buffer;
    }

    return NULL;
}

tData stack_inputNode(){
    tData data;

    printf("insert an integer value: ");
    scanf("%d", &data);
    return data;
}