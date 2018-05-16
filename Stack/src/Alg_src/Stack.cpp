#include "Stack.h"
#include "stdlib.h"
#include <stdio.h>

STACK_STAT_t Stack_Init(StackPtr S,int16_t stack_size)
{
	S->elem_array = (StackElem_t*)malloc(sizeof(StackElem_t)*stack_size);
	if (S->elem_array == NULL)
	{
		return STACK_STAT_FAIL;
	}
	S->top = -1;
	S->capacity = stack_size;
	return STACK_STAT_SUCCESS;
}

BOOL Stack_Full(StackPtr S)
{
	if (S->top == S->capacity - 1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void Stack_Destroy(StackPtr S)
{
	S->top = -1;
	free(S->elem_array);
	return;
	
}

STACK_STAT_t Stack_Push(StackPtr S, StackElem_t elem)
{
	if (S->top != S->capacity - 1) {
		S->top++;
		S->elem_array[S->top] = elem;
		return STACK_STAT_SUCCESS;
	}
	return STACK_STAT_FAIL;
}

STACK_STAT_t Stack_Pop(StackPtr S, StackElem_t *elem)
{
	if (S->top != -1) {
		*elem = S->elem_array[S->top];
		S->top--;
		return STACK_STAT_SUCCESS;
	}
	return STACK_STAT_FAIL;
}

STACK_STAT_t Stack_Top(StackPtr S, StackElem_t *elem)
{
	if (S->top != -1) {
		*elem = S->elem_array[S->top];
		return STACK_STAT_SUCCESS;
	}
	else {
		return STACK_STAT_EMPTY;
	}
}

BOOL Stack_IsEmpty(StackPtr S)
{
	if (S->top == -1) {
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Stack_Print(StackPtr S)
{
	int pos = S->top;

	if (pos == -1) {
		printf("Stack is empty.\n");
	}
	while (pos > -1){
		printf("%d ",S->elem_array[pos]);
		pos--;
	}
	printf("\n");
}