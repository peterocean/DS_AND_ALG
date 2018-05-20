#pragma once

#include "../DS_alg_type.h"

typedef unsigned int QueueElem_t;
#define MAX_QUEUE_SIZE (10u)
typedef struct {
	int front;
	int rear;
   QueueElem_t	QueueArray[MAX_QUEUE_SIZE];
}Queue_t;

typedef Queue_t *QueuePtr;

typedef enum {
	QUEUE_STAT_SUCCESS = 0u,
	QUEUE_STAT_FAIL,
}QUEUE_STAT_t;

QUEUE_STAT_t Queue_Init(QueuePtr Q);
BOOL Queue_IsEmpty(QueuePtr Q);
QUEUE_STAT_t Queue_Front(QueuePtr Q, QueueElem_t *elem);
QUEUE_STAT_t Queue_EnterQueue(QueuePtr Q, QueueElem_t elem);
QUEUE_STAT_t Queue_dequeue(QueuePtr Q, QueueElem_t *elem);
void Queue_Print(QueuePtr Q);




