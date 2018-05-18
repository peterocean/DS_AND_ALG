#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
STACK_STAT_t Stack_Init(StackPtr S)
{
	S->top = NULL;
	return STACK_STAT_SUCCESS;
}

STACK_STAT_t Stack_Push(StackPtr S, StackElem_t elem)
{
	StackNodePtr NewNode = (StackNodePtr)malloc(sizeof(StackNode));
	if (NewNode != NULL) {
		NewNode->elem = elem;
		NewNode->next = S->top;
		S->top = NewNode;
		return STACK_STAT_SUCCESS;
	}
	return	STACK_STAT_FAIL;
}


BOOL Stack_IsEmpty(StackPtr S) 
{
	if (S == NULL) {
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

STACK_STAT_t Stack_Pop(StackPtr S, StackElem_t *elem)
{
	StackNodePtr p = NULL;
	if (S->top != NULL) {
		p = S->top;
		S->top = p->next;
		*elem = p->elem;
		free(p);
		return STACK_STAT_SUCCESS;
	}
	return STACK_STAT_UNDERFLOW;
}

STACK_STAT_t Stack_Top(StackPtr S, StackElem_t *elem)
{
	if (S->top != NULL) {
		*elem = S->top->elem;
		return STACK_STAT_SUCCESS;
	}
	return STACK_STAT_FAIL;
}

void Stack_Destroy(StackPtr S)
{
	StackNodePtr p = NULL;
	while (S->top != NULL){
		p = S->top;
		S->top = p->next;
		free(p);
	}
}

void Stack_Print(StackPtr S)
{
	U16_t index = 0;
	StackNodePtr p = S->top;

	while (p != NULL) {
		printf("elem:%d", p->elem);
		p = p->next;
		if (++index % 5 == 0)
			printf("\n");
	}
	printf("\n");
}