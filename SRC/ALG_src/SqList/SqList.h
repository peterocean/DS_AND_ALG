/********************************************************************************
*                  ��Ȩ���� (C), 1995-2016, �麣�����������޹�˾
*                              All Rights Reserved
* ģ������:
* ��������:2018��4��29��
* ������˾:
* �ļ�����:SqList.h
* �� �� ��:������
* �� �� ��:1.0
* ��������:SqList.cpp ��ͷ�ļ�
********************************************************************************/

#ifndef _SQLISTH_H_
#define _SQLISTH_H_


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/***************************************includes****************************/
#include "../../DS_alg_type.h"

/****************************************�궨��*****************************/
#define SQLIST_INIT_SIZE (100u)
/************************************ö�����Ͷ���***************************/
	typedef enum {
		SQLIST_ERR_NONE = 0u,
		SQLIST_ERR_FAIL,
		SQLIST_ERR_OVER_LIMIT,
	}SQLIST_ERR_t;
/***************************************typedef*****************************/
	typedef int SqList_ElemType_t;
	
	typedef struct {
		SqList_ElemType_t *elem;
		int16_t length;
		int16_t size;
	}SqList_t;

	typedef SqList_t * SqListPtr;

/*********************************ϵͳȫ�ֱ�������**************************/

/*********************************ģ��ȫ�ֱ�������**************************/

/*********************************ϵͳȫ�ֺ�������**************************/
	SQLIST_ERR_t  SqList_init(SqListPtr L);
	SQLIST_ERR_t SqList_retrival(SqListPtr L, int16_t pos, SqList_ElemType_t *elem);
	SQLIST_ERR_t SqList_insert(SqListPtr L, int16_t pos, SqList_ElemType_t elem);
	SQLIST_ERR_t SqList_delete(SqListPtr L, int16_t pos);

	void SqList_print(SqListPtr L);

/*********************************ģ��ȫ�ֺ�������**************************/


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* _SQLISTH_H_ */

