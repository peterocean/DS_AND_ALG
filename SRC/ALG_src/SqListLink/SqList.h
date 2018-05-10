#pragma once

typedef  int SqList_Elem_type_t;
#include "../../DS_alg_type.h"

typedef struct SqListNode {
	SqList_Elem_type_t elem;
	struct SqListNode *next;
}SqListNode_t;

typedef SqListNode_t * SqListNodePtr;


typedef enum {
	SQLIST_STAT_SUCCESS = 0,
	SQLIST_STAT_FAIL,
	SQLIST_STAT_OVER_RANGE
}SQLIST_STAT_t;

SQLIST_STAT_t SqList_init(SqListNodePtr L);
SQLIST_STAT_t SqList_retrival(SqListNodePtr L, int16_t pos, SqListNodePtr *p);
SQLIST_STAT_t  SqList_insert(SqListNodePtr L, int16_t pos, SqList_Elem_type_t elem);
SQLIST_STAT_t SqList_delete(SqListNodePtr L, int16_t pos);
SQLIST_STAT_t SqList_create(SqListNodePtr L, SqList_Elem_type_t elem[], int16_t size);
void SqList_print(SqListNodePtr L);
SQLIST_STAT_t SqList_destroy(SqListNodePtr L);
int16_t SqList_size(SqListNodePtr L);




