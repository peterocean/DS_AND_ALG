#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../DS_alg_type.h"

SQLIST_STAT_t SqList_init(SqListNodePtr L)
{
	SQLIST_STAT_t stat = SQLIST_STAT_SUCCESS;

	if (L != NULL)
	{
		L->next = NULL;
		stat = SQLIST_STAT_SUCCESS;
	}
	else
	{
		stat = SQLIST_STAT_FAIL;
	}
	return stat;
}

SQLIST_STAT_t SqList_destroy(SqListNodePtr L)
{
	SqListNodePtr p = NULL;

	if (L == NULL)
		return SQLIST_STAT_SUCCESS;

	p = L->next;
	while (p != NULL) {
		L->next = p->next;
		free(p);
	}
	return SQLIST_STAT_SUCCESS;
}

SQLIST_STAT_t SqList_retrival(SqListNodePtr L, int16_t pos, SqListNodePtr *p)
{
	SqListNodePtr s = L;
	int16_t index = -1;

	while (s != NULL && index < pos )
	{
		s = s->next;
		index++;
	}
	if (s != NULL && index == pos)
	{
		*p = s;
		return SQLIST_STAT_SUCCESS;;
	}
	else
	{
		return SQLIST_STAT_SUCCESS;
	}
}


SQLIST_STAT_t  SqList_insert(SqListNodePtr L, int16_t pos, SqList_Elem_type_t elem)
{
	SqListNodePtr prev = NULL;
	SqListNodePtr p = NULL;

	if (SqList_retrival(L, pos - 1, &prev) != SQLIST_STAT_SUCCESS) {
		p = (SqListNodePtr)malloc(sizeof(SqListNode));
		if (p != NULL) {
			p->elem = elem;
			p->next = prev->next;
			prev->next = p;
			return SQLIST_STAT_SUCCESS;
		}
	}
	return SQLIST_STAT_FAIL;
}

SQLIST_STAT_t SqList_delete(SqListNodePtr L, int16_t pos)
{
	SqListNodePtr prev = NULL;
	SqListNodePtr p = NULL;

	if (SqList_retrival(L, pos - 1, &prev) == SQLIST_STAT_SUCCESS) {
		p = prev->next;
		if (p != NULL)
		{
			prev->next = p->next;
			free(p);
			return SQLIST_STAT_SUCCESS;
		}
	}
	return SQLIST_STAT_FAIL;
}

SQLIST_STAT_t SqList_create(SqListNodePtr L, SqList_Elem_type_t elem[], int16_t size)
{
	int16_t i = 0;
	SqListNodePtr p = NULL;
	SQLIST_STAT_t stat = SQLIST_STAT_SUCCESS;

	if (SqList_init(L) == SQLIST_STAT_SUCCESS) {
		for (i = size - 1; i >= 0; i--) {
			p = (SqListNodePtr)malloc(sizeof(SqListNode));
			if (p != NULL) {
				p->elem = elem[i];
				p->next = L->next;
				L->next = p;
			}
			else {
				stat =  SQLIST_STAT_FAIL;
				return stat;
			}
		}
	}
	return SQLIST_STAT_SUCCESS;
}

SQLIST_STAT_t SqList_merge(SqListNodePtr La, SqListNodePtr Lb,SqListNodePtr Lc)
{
	int16_t i=0, j=0, k=0;
	SqList_Elem_type_t La_elem,Lb_elem,Lc_elem ;
	

}

int16_t SqList_size(SqListNodePtr L)
{
	int16_t size = 0;
	SqListNodePtr p = L->next;

	if (L == NULL)
		return 0;
	while (p != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}

void SqList_print(SqListNodePtr L)
{
	int16_t index = 0;
	SqListNodePtr p = NULL;

	if (L == NULL){
		printf("list is not exist.\n");
		return;
	}
	if (L->next == NULL) {
		printf("List is empty.\n");
	}
	p = L->next;
	while (p != NULL) {
		printf("Elem[%d]:%3d ", index, p->elem);
		if (++index % 5 == 0)
			printf("\n");
		p = p->next;
	}
	printf("\n");
}