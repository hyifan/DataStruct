/*
顺序存储结构
线性表的顺序存储结构，指的是用一段地址连续的存储单元依次存储线性表的数据元素
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


/* 初始化 */
SqList *InitList() {
	SqList *list = malloc(sizeof(SqList));
	list->length = 0;
	return list;
}


/* 插入：在线性表L中的第i个位置插入新元素e */
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


/* 交换 list->data[i] 和 list->data[j] 的位置 */
void swap(SqList *list, int i, int j) {
	int num = list->data[i];
	list->data[i] = list->data[j];
	list->data[j] = num;
}

