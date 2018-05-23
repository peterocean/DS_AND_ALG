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
			Q->front->next = p->next;
			free(p);
		}
		if (p == Q->rear)			
			Q->rear = Q->front;
	}
	return QUEUE_STAT_FAIL;
}

void Queue_Print(QueuePtr Q)
{
	U8_t  index = 0;
	QueueNodePtr p = Q->front->next;

	while (p != NULL) {
		printf("%d", p->elem);
		p = p->next;
		if (++index % 5 == 0)
			printf("\n");
	}
}

void Queue_Destroy(QueuePtr Q)
{
	QueueNodePtr p = Q->front;
	
	while (Q->front != NULL) {
		p = Q->front;
		Q->front->next = p->next;
		free(p);
	}
	return;
}

BOOL Queue_IsEmpty(QueuePtr Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}