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
	SqList *L = malloc(sizeof(SqList));
	L->length = 0;
	return L;
}


/* 返回是否为空 */
int ListEmpty(SqList *L) {
	return L->length == 0;
}


/* 清空表 */
int ClearList(SqList *L) {
	L->length = 0;
	return 1;
}


/* 获得第i个元素 */
int GetElem(SqList *L, int i, int *e) {
	if (L->length == 0 || i < 0 || i > L->length - 1) {
		return 0;
	}
	*e = L->data[i];
	return 1;
}


/* 返回e的序号 */
int LocateElem(SqList *L, int e) {
	int i;
	for (i = 0; L->data[i] != e; i++)
		;
	return i - 1;
}


/* 插入 */
int ListInsert(SqList *L, int i, int e) {
	int k;
	if (L->length == MAXSIZE || i < 0 || i > L->length) {
		return 0;
	}
	if (i != L->length) {
		for (k = L->length; k > i; k--) {
			L->data[k] = L->data[k - 1];
		}
	}
	L->data[i] = e;
	L->length++;
	return 1;
}


/* 删除 */
int ListDelete(SqList *L, int i, int *e) {
	int k;
	if (L->length == 0 || i < 0 || i > L->length - 1) {
		return 0;
	}
	*e = L->data[i];
	if (i != L->length - 1) {
		for (k = i; k < L->length - 1; k++) {
			L->data[k] = L->data[k + 1];
		}
	}
	L->length--;
	return 1;
}


int main(int argc, char *argv[]) {
	int type = atoi(argv[1]);
	SqList *L = InitList();
	int isEmpty;
	int p;
	int e;
	int i;

	isEmpty = ListEmpty(L);
	ClearList(L);
	ListInsert(L, 1, 1);
	GetElem(L, 1, &p);
	LocateElem(L, 1);
	for (i = 0; i < 10; i++) {
		ListInsert(L, i, i);
	}
	for (i = 0; i < L->length; i++) {
		int elem;
		GetElem(L, i+1, &elem);
		printf("%d ", elem);
	}
	printf("\n");
	ListDelete(L, 1, &e);
	printf("%d %d %d\n", isEmpty, p, e);
	free(L);
}













