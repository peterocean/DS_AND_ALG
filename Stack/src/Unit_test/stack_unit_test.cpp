#include <stdio.h>
#include <stdlib.h>
#include "stack_unit_test.h"

void Stack_Push_test(StackPtr S)
{
	int16_t index = 0;
	StackElem_t TopElem = 0;

	printf("Stack_Push() test start.\n");
	Stack_Init(S,20);

	for (index = 0; index < 10; index++) {
		if (Stack_Push(S, index) == STACK_STAT_SUCCESS) {
			if (Stack_Top(S, &TopElem) != STACK_STAT_SUCCESS) {
				printf("Stack_Push() test fail.\n");
				break;
			}
			if (TopElem != index) {
				printf("Stack_Push() test fail.\n");
				break;
			}
		}
		else {
			printf("Stack_Push() test fail.\n");
			break;
		}
	}
	Stack_Print(S);
	Stack_Destroy(S);
	printf("Stack Push() test ok.\n");
	return ;
}

void Stack_Pop_test(StackPtr S)
{
	int16_t index = 0;
	StackElem_t TopElem = 0;
	StackElem_t PopOutElem = 0;

	printf("Stack_Pop() test start.\n");

	Stack_Init(S, 20);
	for (index = 0; index < 10; index++) {
		Stack_Push(S, index);
	}
	while (!Stack_IsEmpty(S)) {
		Stack_Top(S, &TopElem);
		Stack_Pop(S, &PopOutElem);
		if (TopElem != PopOutElem) {
			printf("Stack_Pop() test fail.\n");
			break;
		}
	}
	Stack_Destroy(S);
	printf("Stack Pop() test ok.\n");
	return;
}

int main(int argc, char *arg[])
{
	StackPtr S = (StackPtr)malloc(sizeof(Stack_t));

	Stack_Push_test(S);
	Stack_Pop_test(S);
	free(S);
}