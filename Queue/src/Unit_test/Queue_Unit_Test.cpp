#include "Queue_Unit_Test.h"
#include <stdlib.h>
#include <stdio.h>

BOOL Queue_EnterQueue_Test(void)
{
	int16_t index = 0;
	QueuePtr Q = (QueuePtr)malloc(sizeof(Queue_t));

	printf("Queue_EnterQueue() test start:\n");

	if (Q == NULL)
		return FALSE;
	Queue_Init(Q);
	for (index = 0; index < MAX_QUEUE_SIZE; index++) {
		Queue_EnterQueue(Q, index);
	}
	printf("\n");
	Queue_Print(Q);
	printf("Queue_EnterQueue() OK.\n");
	free(Q);
	return TRUE;
}

BOOL Queue_dequeue_Test(void) 
{
	BOOL stat = TRUE;
	int16_t index = 0;
	QueueElem_t elem = 0;
	QueuePtr Q = (QueuePtr)malloc(sizeof(Queue_t));

	printf("Queue_dequeue() test start:\n");

	if (Q == NULL)
		return FALSE;
	Queue_Init(Q);
	for (index = 0; index < MAX_QUEUE_SIZE; index++) {
		Queue_EnterQueue(Q, index);
	}
	printf("Init Q:\n");
	Queue_Print(Q);
	
	while (Queue_IsEmpty(Q)){
		printf("Q[%d]:", Q->front);
		if (Queue_dequeue(Q, &elem) == QUEUE_STAT_SUCCESS) {
			printf("%d,", elem);
		}
		else{
			stat = FALSE;
			break;
		}
	}
	free(Q);
	printf("\n");
	if (!stat)
		printf("Queue_dequeu() test fail.\n");
	else
		printf("Queuue_dequeue() test pass.\n");
	return stat;
}

int main(int argc, char*arg[])
{
	Queue_EnterQueue_Test();
	Queue_dequeue_Test();
	
	return 0;
}