#pragma once
#include "../DS_alg_type.h"

typedef unsigned int QueuElem_t;

typedef struct QueueNode{
	QueuElem_t elem;
	struct QueueNode *next;
}QueueNode_t;

typedef QueueNode_t * QueueNodePtr;


typedef struct {
	QueueNode *front;		
	QueueNode *rear;
}Queue_t;
