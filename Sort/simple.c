/*
简单选择排序（Simple Selection Sort）
简单选择排序就是通过 n-i 次关键字间的比较，从 n-i+1 个记录中选出关键字最小的记录，并和第 i(1<=i<=n) 个记录交换。
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void SelectSort(SqList *list) {
	int i, j, min;
	for (i = 1; i < list->length; i++) {
		min = i;
		for (j = i + 1; j < list->length; j++) {
			if (list->data[min] > list->data[j]) {
				min = j;
			}
		}
		if (i != min) {
			swap(list, i, min);
		}
	}
}


int main(int argc, char *argv[]) {
	SqList *list = InitList();
	int i;

	int arr[10];
	arr[0] = 7;
	arr[1] = 9;
	arr[2] = 8;
	arr[3] = 10;
	arr[4] = 3;
	arr[5] = 5;
	arr[6] = 4;
	arr[7] = 6;
	arr[8] = 1;
	arr[9] = 2;

	/* 按 arr 顺序插入 */
	for (i = 0; i < 10; i++) {
		ListInsert(list, i, arr[i]);
		printf("%d ", arr[i]);
	}
	printf("\n");

	/* 排序 12345... */
	SelectSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}
