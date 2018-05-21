#include "Queue.h"
#include <stdlib.h>

QUEUE_STAT_t Queue_Init(QueuePtr Q)
{
	QueueNodePtr p = (QueueNodePtr)malloc(sizeof(QueueNode));
		if (p) {
			Q->front = p;
			Q->rear = p;
			return QUEUE_STAT_SUCCESS;
		}
		else {
			return QUEUE_STAT_FAIL;
		}
}

QUEUE_STAT_t Queue_EnQueue(QueuePtr Q, QueuElem_t elem)
{
	QueueNodePtr p = (QueueNodePtr)malloc(sizeof(QueueNode));
	
	if (p != NULL) {
		Q->rear->next = p;
		Q->rear = p;
		return QUEUE_STAT_SUCCESS;
	}
	return QUEUE_STAT_FAIL;
}

QUEUE_STAT_t Queue_DeQueue(QueuePtr Q, QueuElem_t *elem)
{
	QueueNodePtr p = NULL;

	if (Q->front != Q->rear) {
		p = Q->front->next;
		if (p != NULL) {

		}
	}
}