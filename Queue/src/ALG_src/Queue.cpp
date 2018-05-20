#include "Queue.h"
#include "stdio.h"

QUEUE_STAT_t Queue_Init(QueuePtr Q)
{
	Q->rear = 0;
	Q->front = 0;
	return QUEUE_STAT_SUCCESS;
}

BOOL Queue_IsEmpty(QueuePtr Q) {
	if (Q->rear == Q->front)
		return TRUE;
	else
		return FALSE;
}

QUEUE_STAT_t Queue_Front(QueuePtr Q, QueueElem_t *elem)
{
	if (!Queue_IsEmpty(Q)) {
		*elem = Q->QueueArray[Q->front];
		return QUEUE_STAT_SUCCESS;
	}
	return QUEUE_STAT_FAIL;
}


QUEUE_STAT_t Queue_EnterQueue(QueuePtr Q, QueueElem_t elem)
{
	if ((Q->rear + 1) % MAX_QUEUE_SIZE != Q->front) {
		Q->QueueArray[Q->rear] = elem;
		Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
		return QUEUE_STAT_SUCCESS;
	}
	return QUEUE_STAT_FAIL;
}
QUEUE_STAT_t Queue_dequeue(QueuePtr Q, QueueElem_t *elem)
{
	if (Q->rear != Q->front) {
		*elem = Q->QueueArray[Q->front];
		Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
		return QUEUE_STAT_SUCCESS;
	}
	return QUEUE_STAT_FAIL;
}

void Queue_Print(QueuePtr Q) {
	int index = 0;
	int rear = Q->rear;
	int front = Q->front;

	while (rear != front) {
		printf("Q[%d]:%d ,", front, Q->QueueArray[front]);
		if (++index % 5 == 0) {
			printf("\n");
		}
		front = (front + 1) % MAX_QUEUE_SIZE;
	}
	return;
}