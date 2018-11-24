/*
顺序存储结构
线性表的顺序存储结构，指的是用一段地址连续的存储单元依次存储线性表的数据元素
*/


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20 /*存储空间初始化分配量*/


typedef struct SqList
{
	int data[MAXSIZE];
	int length;
} SqList;


/* 初始化 */
SqList *InitList() {
	SqList *list = malloc(sizeof(SqList));
	list->length = 0;
	return list;
}


/* 返回是否为空 */
int ListEmpty(SqList *list) {
	return list->length == 0;
}


/* 清空表 */
int ClearList(SqList *list) {
	list->length = 0;
	return 1;
}


/* 获得第i个元素 */
int GetElem(SqList *list, int i, int *e) {
	if (list->length == 0 || i < 0 || i > list->length - 1) {
		return 0;
	}
	*e = list->data[i];
	return 1;
}


/* 返回e的序号 */
int LocateElem(SqList *list, int e) {
	int i;
	for (i = 0; i < list->length && list->data[i] != e; i++) {
		;
	}
	if (i == list->length) {
		return -1;
	}
	return i;
}


/* 插入 */
int ListInsert(SqList *list, int i, int e) {
	int k;
	if (list->length == MAXSIZE || i < 0 || i > list->length) {
		return 0;
	}
	if (i != list->length) {
		for (k = list->length; k > i; k--) {
			list->data[k] = list->data[k - 1];
		}
	}
	list->data[i] = e;
	list->length++;
	return 1;
}


/* 删除 */
int ListDelete(SqList *list, int i, int *e) {
	int k;
	if (list->length == 0 || i < 0 || i > list->length - 1) {
		return 0;
	}
	*e = list->data[i];
	if (i != list->length - 1) {
		for (k = i; k < list->length - 1; k++) {
			list->data[k] = list->data[k + 1];
		}
	}
	list->length--;
	return 1;
}


int main(int argc, char *argv[]) {
	SqList *list = InitList();
	int i;

	printf("insert：");
	for (i = 0; i < 10; i++) {
		ListInsert(list, i, i);
		printf("%d ", i);
	}
	printf("\n");

	printf("delete：");
	for (i = 5; i >= 0; i--) {
		int elem;
		ListDelete(list, i, &elem);
		printf("%d ", elem);
	}
	printf("\n");

	printf("get：");
	for (i = 0; i < list->length; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}
	printf("\n");

	int locate = LocateElem(list, 9);
	int isEmpty1 = ListEmpty(list);
	ClearList(list);
	int isEmpty2 = ListEmpty(list);
	printf("%d %d %d\n", locate, isEmpty1, isEmpty2);

	free(list);
}

