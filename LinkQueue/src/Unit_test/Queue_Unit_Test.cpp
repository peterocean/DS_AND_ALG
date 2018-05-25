#include "Queue_Unit_Test.h"
#include <stdlib.h>
#include <stdio.h>

#define TEST_QUEUE_SIZE (100u)

BOOL Queue_EnterQueue_Test(void)
{
	U16_t index = 0;
	Queue_t Q ;

	printf("Queue_EnterQueue() test start:\n");

	Queue_Init(&Q);
	for (index = 0; index < 10; index++) {
		Queue_EnQueue(&Q, index);
	}
	printf("\n");
	Queue_Print(&Q);
	Queue_Destroy(&Q);
	printf("Queue_EnterQueue() OK.\n");
	return TRUE;
}

BOOL Queue_dequeue_Test(void) 
{
	int16_t index = 0;
	QueueElem_t elem = 0;
	Queue_t Q;
	U8_t  *p_TestArray = (U8_t*)malloc(TEST_QUEUE_SIZE);

	printf("Queue_dequeue() test start:\n");

	if (p_TestArray == NULL)
		printf("Queue_Deueue() test fail.\n");

	Queue_Init(&Q);
	/*创建测试序列*/
	for (index = 0; index < TEST_QUEUE_SIZE; index++) {
		p_TestArray[index] = rand() % 1000;
	}
	/*测试序列入队*/
	for (index = 0; index < TEST_QUEUE_SIZE; index++) {
		Queue_EnQueue(&Q, p_TestArray[index]);
	}
	printf("Init Q:\n");
	Queue_Print(&Q);
	
	/*出队测试*/
	index = 0;
	while (Queue_DeQueue(&Q,&elem) != QUEUE_STAT_FAIL)
	{
		printf("%d,", elem);
		if (elem != p_TestArray[index++]) {
			printf("Queue_dequeu() test fail.\n");
			return FALSE;
		}
		if (index % 10 == 0)
			printf("\n");
	}
	printf("\n");
	printf("Queuue_dequeue() test pass.\n");
	return TRUE;
}

int main(int argc, char*arg[])
{
	Queue_EnterQueue_Test();
	Queue_dequeue_Test();
	
	return 0;
}