#include "stack.h"
#include <stdio.h>
#include <string.h>

int brackets(const char* str);

int main(){
	char a[15];
	strcpy(a, "(())(()");
	printf("%s\n", a);
	
	brackets(a);
	return 0;
}

int brackets(const char* str){
	tStackNode *head  = NULL;
	int i = 0;

	head = stack_init();
	
	while (str[i] != '\0'){
		if (str[i] == '(')
			stack_push(&head, 1);
		else if (str[i] == ')' && !stack_isEmpty(head))
			stack_pop(&head, NULL);
		else {
			printf("NOT BALANCED\n");
			return 1;
		}
		i ++;
	}
	if (!stack_isEmpty(head)){
		printf("NOT BALANCED\n");
		return 1;
	}
		
	printf("BALANCED\n");
	return 0;
}