#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

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

QUEUE_STAT_t Queue_EnQueue(QueuePtr Q, QueueElem_t elem)
{
	QueueNodePtr p = (QueueNodePtr)malloc(sizeof(QueueNode));
	
	if (p != NULL) {
		p->elem = elem;
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
		return QUEUE_STAT_SUCCESS;
	}

	return QUEUE_STAT_FAIL;
}

QUEUE_STAT_t Queue_DeQueue(QueuePtr Q, QueueElem_t *elem)
{
	QueueNodePtr  p = NULL;

	if (Q->front->next != NULL) {
		p = Q->front->next;
		*elem = p->elem;
		Q->front->next = p->next;
		if (p == Q->rear) {
			Q->rear = Q->front;
		}
		free(p);
		return QUEUE_STAT_SUCCESS;
	}
	return QUEUE_STAT_FAIL;
}

void Queue_Destroy(QueuePtr Q)
{
	QueueNodePtr p = NULL;
	if (Q == NULL)
		return;

	while (Q->front != NULL) {
		p = Q->front;
		Q->front = Q->front->next;
		free(p);
	}
	return;
}

void Queue_Print(QueuePtr Q)
{
	U8_t index = 0;
	QueueNodePtr front = Q->front->next;
	while (front !=  NULL)
	{
		printf("%d, ", front->elem);
		if (++index % 10 == 0)
			printf("\n");
		front = front->next;
	}
	printf("\n");

}