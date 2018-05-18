#pragma once

#include "../DS_alg_type.h"

typedef unsigned int  StackElem_t;

typedef struct StackNode{
	StackElem_t elem;
	struct StackNode *next;
}StackNode_t;

typedef StackNode_t * StackNodePtr;

typedef struct {
	StackNodePtr top;
}Stack_t;

typedef enum {
	STACK_STAT_SUCCESS = 0u,
	STACK_STAT_FAIL,
	STACK_STAT_UNDERFLOW,
}STACK_STAT_t;

typedef Stack_t * StackPtr;

STACK_STAT_t Stack_Init(StackPtr S);
STACK_STAT_t Stack_Push(StackPtr S, StackElem_t elem);
BOOL Stack_IsEmpty(StackPtr S);
STACK_STAT_t Stack_Pop(StackPtr S, StackElem_t *elem);
STACK_STAT_t Stack_Top(StackPtr S, StackElem_t *elem);
void Stack_Destroy(StackPtr S);
void Stack_Print(StackPtr S);
