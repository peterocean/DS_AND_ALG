/********************************************************************************
*                  版权所有 (C), 1995-2016, 珠海科荟电器有限公司
*                              All Rights Reserved
* 模块名称:
* 创建日期:2018年4月29日
* 所属公司:
* 文件名称:SqList.h
* 创 建 人:阳永锋
* 版 本 号:1.0
* 功能描述:SqList.cpp 的头文件
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

/****************************************宏定义*****************************/
#define SQLIST_INIT_SIZE (100u)
/************************************枚举类型定义***************************/
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

/*********************************系统全局变量声明**************************/

/*********************************模块全局变量声明**************************/

/*********************************系统全局函数声明**************************/
	SQLIST_ERR_t  SqList_init(SqListPtr L);
	SQLIST_ERR_t SqList_retrival(SqListPtr L, int16_t pos, SqList_ElemType_t *elem);
	SQLIST_ERR_t SqList_insert(SqListPtr L, int16_t pos, SqList_ElemType_t elem);
	SQLIST_ERR_t SqList_delete(SqListPtr L, int16_t pos);

	void SqList_print(SqListPtr L);

/*********************************模块全局函数声明**************************/


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* _SQLISTH_H_ */

