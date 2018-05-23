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
typedef Queue_t *QueuePtr;

typedef enum {
	QUEUE_STAT_SUCCESS = 0,
	QUEUE_STAT_FAIL,
}QUEUE_STAT_t;

QUEUE_STAT_t Queue_Init(QueuePtr Q);
QUEUE_STAT_t Queue_EnQueue(QueuePtr Q, QueuElem_t elem);
QUEUE_STAT_t Queue_DeQueue(QueuePtr Q, QueuElem_t *elem);
void Queue_Print(QueuePtr Q);
void Queue_Destroy(QueuePtr Q);
BOOL Queue_IsEmpty(QueuePtr Q);
