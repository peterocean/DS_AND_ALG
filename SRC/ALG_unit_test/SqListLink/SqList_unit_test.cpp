#include "../../ALG_src/SqListLink/SqList.h"
#include <stdio.h>
#include <stdlib.h>

 
void  SqList_delete_func_test(void)
{
	int pos_seed = 0;
	SqListNode_t List_head;
	SqListNodePtr L = &List_head;

	SqListNodePtr prior = NULL;
	SqListNodePtr next = NULL;

	SqList_Elem_type_t elem_array[10] = { 0,2,4,6,8,10,12,14,16,18 };

	
	if (SqList_create(L, elem_array, sizeof(elem_array)/sizeof(elem_array[0])) != SQLIST_STAT_SUCCESS){
		printf("SqList_delete():init fail.\n");
		return;
	}
	SqList_print(L);

	pos_seed = rand() % SqList_size(L);
	SqList_retrival(L, pos_seed - 1, &prior);
	next = prior->next->next;
	SqList_delete(L, pos_seed);
	if (prior->next != next)
		printf("SqList_delete():delete elem test fail.\n");
	SqList_print(L);

	if (SqList_delete(L, SqList_size(L)) == SQLIST_STAT_SUCCESS)
		printf("SqList delete(): over range test fail.\n");
	SqList_print(L);
	printf("SqList delte():test pass.\n");
}

int main(int argc, char *argv[])
{
	SqList_delete_func_test();

}