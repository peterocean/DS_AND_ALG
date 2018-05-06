#pragma once

typedef unsigned int SqList_Elem_type_t;

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