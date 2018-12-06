/*
冒泡排序（Bubble Sort）
冒泡排序的基本思想是：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止。
*/


#include <stdio.h>
#include <stdlib.h>


void BubbleSort(SqList *list) {
	int i, j;
	int flag = 1;
	for (i = 0; i < list->length && flag; i++) {
		flag = 0;
		for (j = list->Length; j >= i; j--) {
			if (list->data[i] > list->data[j]) {
				swap(list, i, j); /* 交换 list->data[i] 与 list->data[j] 的值 */
				flag = 1;
			}
		}
	}
}


int main(int argc, char *argv[]) {
	SqList *list = InitList();
	int i;

	int arr[10];
	arr[0] = 2;
	arr[1] = 5;
	arr[2] = 6;
	arr[3] = 7;
	arr[4] = 1;
	arr[5] = 10;
	arr[6] = 8;
	arr[7] = 9;
	arr[8] = 3;
	arr[9] = 4;

	/* 插入 */
	for (i = 0; i < 10; i++) {
		ListInsert(list, i, arr[i]);
		printf("%d ", i);
	}
	printf("\n");

	/* 排序 */
	BubbleSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}

}