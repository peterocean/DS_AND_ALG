#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../DS_alg_type.h"

SQLIST_STAT_t SqList_init(SqListNodePtr L)
{
	SQLIST_STAT_t stat = SQLIST_STAT_SUCCESS;

	L = (SqListNodePtr)malloc(sizeof(SqListNode));
	if (L != NULL) {
		L->next = NULL;
		stat = SQLIST_STAT_SUCCESS;
	}
	else{
		stat = SQLIST_STAT_FAIL;
	}
	return stat;
}

SQLIST_STAT_t SqList_retrival(SqListNodePtr L, int16_t pos, SqListNodePtr *p)
{
	SqListNodePtr s = L;
	int16_t index = -1;

	while (s->next != NULL && index <= pos )
	{
		s = s->next;
		index++;
	}
	if (s != NULL && index > pos)
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

	if (SqList_retrival(L, pos, &prev) == SQLIST_STAT_SUCCESS) {
		p = prev->next;
		prev->next = p->next;
		free(p);
		return SQLIST_STAT_SUCCESS;
	}
	return SQLIST_STAT_FAIL;
}

SQLIST_STAT_t SqList_create(SqListNodePtr L, SqList_Elem_type_t elem[], int16_t size)
{
	int16_t i = 0;
	SqListNodePtr p = NULL;
	SqListNodePtr L = NULL;
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