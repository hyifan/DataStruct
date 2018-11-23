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

/*
顺序存储结构
线性表的顺序存储结构，指的是用一段地址连续的存储单元依次存储线性表的数据元素
*/
/* 返回是否为空 */
int orderListEmpty(SqList *L) {
	return L->length == 0;
}
/* 清空表 */
int orderClearList(SqList *L) {
	L->length = 0;
	return 1;
}
/* 获得第i个元素 */
int orderGetElem(SqList *L, int i, int *e) {
	if (L->length == 0 || i < 0 || i > L->length - 1) {
		return 0;
	}
	*e = L->data[i];
	return 1;
}
/* 返回e的序号 */
int orderLocateElem(SqList *L, int e) {
	int i;
	for (i = 0; L->data[i] != e; i++)
		;
	return i - 1;
}
/* 插入 */
int orderListInsert(SqList *L, int i, int e) {
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
int orderListDelete(SqList *L, int i, int *e) {
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


/*
单链表
*/
/* 返回是否为空 */
int singleListEmpty(SqList *L) {
	
}
/* 清空表 */
int singleClearList(SqList *L) {
	
}
/* 获得第i个元素 */
int singleGetElem(SqList *L, int i, int *e) {
	
}
/* 返回e的序号 */
int singleLocateElem(SqList *L, int e) {
	
}
/* 插入 */
int singleListInsert(SqList *L, int i, int e) {
	
}
/* 删除 */
int singleListDelete(SqList *L, int i, int *e) {
	
}



int main(int argc, char *argv[]) {
	int type = atoi(argv[1]);
	SqList *L = InitList();
	int isEmpty;
	int p;
	int e;
	int i;

	switch (type) {
		case 1:
			isEmpty = orderListEmpty(L);
			orderClearList(L);
			orderListInsert(L, 1, 1);
			orderGetElem(L, 1, &p);
			orderLocateElem(L, 1);
			for (i = 0; i < 10; i++) {
				orderListInsert(L, i, i);
			}
			//orderListDelete(L, 1, &e);
			for (i = 0; i < L->length; i++) {
				int elem;
				orderGetElem(L, i+1, &elem);
				printf("%d ", elem);
			}
			printf("\n");
		    break;
		case 2:
		    isEmpty = orderListEmpty(L);
			orderClearList(L);
			orderListInsert(L, 1, 1);
			orderGetElem(L, 1, &p);
			orderLocateElem(L, 1);
			for (i = 0; i < 10; i++) {
				orderListInsert(L, i, i);
			}
			//orderListDelete(L, 1, &e);
			for (i = 0; i < L->length; i++) {
				int elem;
				orderGetElem(L, i+1, &elem);
				printf("%d ", elem);
			}
			printf("\n");
		    break;
		default:
		    break;
	}
	printf("%d %d %d\n", isEmpty, p, e);
	free(L);
}













