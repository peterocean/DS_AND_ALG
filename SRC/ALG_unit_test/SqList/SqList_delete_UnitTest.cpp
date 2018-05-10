#include "SqList_delete_UnitTest.h"

static void SqList_delete_TestList_create(SqListPtr L)
{
	int16_t index = 0;

	SqList_init(L);
	for (index = 0; index < 5; index++)
	{
		SqList_insert(L, L->length, index * 2);
	}
	printf("SqList create,origin SqList is:\n");
	SqList_print(L);
	printf("\n");
	return;
}


static SQLIST_UNITTEST_STAT_t SqList_delete_over_limit_test(SqListPtr L)
{
	if (SqList_delete(L, L->length) != SQLIST_ERR_OVER_LIMIT)
		printf("SqList delete: over limit test fail.\n");
	return SQLIST_UNITTEST_SUCCESS;
}

static SQLIST_UNITTEST_STAT_t SqList_delete_delete_test(SqListPtr L)
{
	int16_t index = 0;
	SqList_ElemType_t next_elem;

	while (L->length > 0)
	{
		next_elem = L->length > 1 ? L->elem[1] : L->elem[0];
		SqList_delete(L, 0);
		if (L->length > 0) {
			if (next_elem != L->elem[0]) {
				printf("SqList delete: delete error.\n");
				return SQlIST_UNITTEST_FAIL;
			}
				
		}
		SqList_print(L);
	}
	return SQLIST_UNITTEST_SUCCESS;
}

void SqList_delete_UnitTest(void)
{
	SqList_t L;

	SqList_delete_TestList_create(&L);
	SqList_delete_over_limit_test(&L);
	SqList_delete_delete_test(&L);

	return;
}