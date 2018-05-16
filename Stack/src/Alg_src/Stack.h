#pragma once
#include "../DS_alg_type.h"

typedef unsigned int StackElem_t;
typedef struct {
	int16_t top;
	int16_t capacity;
	StackElem_t *elem_array;
}Stack_t;

typedef Stack_t *StackPtr;

typedef enum {
	STACK_STAT_SUCCESS = 0u,
	STACK_STAT_FAIL,
	STATCK_STAT_RANGE_OUT,
	STACK_STAT_FULL,
	STACK_STAT_EMPTY
}STACK_STAT_t;


STACK_STAT_t Stack_Init(StackPtr S, int16_t stack_size);
BOOL Stack_Full(StackPtr S);
void Stack_Destroy(StackPtr S);
STACK_STAT_t Stack_Push(StackPtr S, StackElem_t elem);
STACK_STAT_t Stack_Pop(StackPtr S, StackElem_t *elem);
STACK_STAT_t Stack_Top(StackPtr S, StackElem_t *elem);
BOOL Stack_IsEmpty(StackPtr S);

void Stack_Print(StackPtr S);




