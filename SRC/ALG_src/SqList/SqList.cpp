/*
******************************************************************************
*                  ��Ȩ���� (C), 1995-2016, �麣�����������޹�˾              
*								 All Rights Reserved                         
*@��    ��   : ������
*@�� �� ��   : SqList.cpp
*@�� �� ��   : 1.0
*@��������   : 2018��4��29��
*@��������   : 
******************************************************************************
*/

/************************************�궨��************************************/
#include "SqList.h"
#include <stdlib.h>
#include <stdio.h>

/***********************************���Ͷ���***********************************/

/***********************************ȫ�ֱ���***********************************/

/*********************************ģ��ȫ�ֱ���*********************************/

/*********************************�ֲ�ȫ�ֱ���*********************************/

/*********************************�ֲ���������*********************************/

SQLIST_ERR_t  SqList_init(SqListPtr L)
{
	if (L == NULL)
		return SQLIST_ERR_FAIL;

	L->size = SQLIST_INIT_SIZE;
	L->length = 0;
	L->elem = (SqList_ElemType_t *)malloc(L->size*sizeof(SqList_ElemType_t));

	if (L->elem != NULL)
		return SQLIST_ERR_NONE;
	else
		return SQLIST_ERR_OVER_LIMIT;
}

SQLIST_ERR_t SqList_retrival(SqListPtr L, int16_t pos, SqList_ElemType_t *elem)
{
	if (L != NULL)
	{
		if (pos >= 0 && pos < L->length)
		{
			*elem = L->elem[pos];
			return SQLIST_ERR_NONE;
		}
		else
		{
			return SQLIST_ERR_OVER_LIMIT;
		}
	}
	return SQLIST_ERR_OVER_LIMIT;
}


SQLIST_ERR_t SqList_locate(SqListPtr L, SqList_ElemType_t elem, int16_t *pos)
{
	int16_t index = 0;

	if (L == NULL || L->elem == NULL)
		return SQLIST_ERR_FAIL;
	
	for (index = 0; index < L->length; index++)
	{
		if (L->elem[index] == elem)
		{
			*pos = index;
			return SQLIST_ERR_NONE;
		}
	}
	return SQLIST_ERR_OVER_LIMIT;
}

SQLIST_ERR_t SqList_insert(SqListPtr L, int16_t pos,SqList_ElemType_t elem)
{
	int16_t index = 0;

	if (L == NULL || L->elem == NULL)
		return SQLIST_ERR_FAIL;
	
	if (L->length >= L->size)
		return SQLIST_ERR_FAIL;
	
	if (pos >= 0 && pos <= L->length)
	{
		for (index = L->length - 1; index >= pos; index--)
		{
			L->elem[index + 1] = L->elem[index];
		}
		L->elem[pos] = elem;
		L->length++;
		return SQLIST_ERR_NONE;
	}
	return SQLIST_ERR_OVER_LIMIT;
}

SQLIST_ERR_t SqList_delete(SqListPtr L, int16_t pos)
{
	int16_t index = 0;
	
	if (L == NULL || L->elem == NULL)
		return SQLIST_ERR_FAIL;
	if (pos >= 0 && pos < L->length && L->length != 0)
	{
		for (index = pos; index < L->length - 1; index++) {
			L->elem[index] = L->elem[index + 1];
		}
		L->length--;
		return SQLIST_ERR_NONE;
	}
	return SQLIST_ERR_OVER_LIMIT;
}

void SqList_print(SqListPtr L)
{
	int16_t  index = 0;

	if (L == NULL)
	{
		printf("SqList is empty.\n");
	}
	else if (L->elem == NULL || L->length == 0)
	{
		printf("SqList has no data.\n");
	}
	else
	{
		printf("List length:%d \n", L->length);
		for (index = 0; index < L->length; index++)
		{
			printf("List[%d]:%5d,", index, L->elem[index]);
			if ((index +1) % 5 == 0)
				printf("\n");
		}
		printf("\n");
		printf("\n");
	}
}
/***************** (C) COPYRIGHT 2016 �麣�����������޹�˾ *****END OF FILE****/
