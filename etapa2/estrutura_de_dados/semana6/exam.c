#include "stack.h"

bool stack_compare(tStackNode **top1, tStackNode **top2);
bool recursive_stackNodeCmp(tStackNode **top1, tStackNode **top2);

int main(){
    tStackNode *top1 = NULL, *top2 = NULL;
    int i = 0;

    top1 = stack_init();
    top2 = stack_init();

    do{
        printf("Insert elements in stack 1: \n");
        scanf("%d", &i);
        do{
            stack_push(&top1, i);
            scanf("%d", &i);
        } while (i != 0);

        printf("Insert elements in stack 2: \n");
        scanf("%d", &i);
        do{
            stack_push(&top2, i);
            scanf("%d", &i);
        } while (i != 0);
        
        printf("ans: %d\n", stack_compare(&top1, &top2));

        while (!stack_isEmpty(top1)){
            stack_pop(&top1, &i);
            printf("%d\t", i);
        }
        printf("\n");

        while (!stack_isEmpty(top2)){
            stack_pop(&top2, &i);
            printf("%d\t", i);
        }
        printf("\n");
    } while (1);
    return 0;
}


bool stack_compare(tStackNode **top1, tStackNode **top2){
    bool flag;

    //verify if the list is empty in the first execution
    if (!stack_isEmpty(*top1) && !stack_isEmpty(*top2)){
        // call the recursive function
        return recursive_stackNodeCmp(top1, top2);
    }
    else
        return false;
}

bool recursive_stackNodeCmp(tStackNode **top1, tStackNode **top2){
    tData buffer1, buffer2;
    bool flag;

    stack_pop(top1, &buffer1);
    stack_pop(top2, &buffer2); // get the top of both stacks

    if (buffer1 == buffer2) {
        if (!stack_isEmpty(*top1) && !stack_isEmpty(*top2)){
            // not reached the end of stacks
            flag = stack_compare(top1, top2);
            stack_push(top1, buffer1);
            stack_push(top2, buffer2); // insert the elements in the stack again
            return flag;
        }
        else if (stack_isEmpty(*top1) && stack_isEmpty(*top2)){
            //stop condition: both stacks ended without find different elements in same position
            stack_push(top1, buffer1);
            stack_push(top2, buffer2); // insert the elements in the stack again
            return true;
        }
        else{
            //stop condition: only one stack reached the end, so, they are different
            stack_push(top1, buffer1);
            stack_push(top2, buffer2); // insert the elements in the stack again
            return false;
        }
    }
    //stop condition: elements are different
    else{
        stack_push(top1, buffer1);
        stack_push(top2, buffer2); // insert the elements in the stack again
        return false;
    }
}
    