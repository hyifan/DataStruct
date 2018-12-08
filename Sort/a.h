/*
简单选择排序（Simple Selection Sort）
简单选择排序就是通过 n-i 次关键字间的比较，从 n-i+1 个记录中选出关键字最小的记录，并和第 i(1<=i<=n) 个记录交换。
*/


#include <stdio.h>
#include <stdlib.h>


void SelectSort(SqList *list) {
	int i, j, min;
	for (i = 1; i < list->length; i++) {
		min = i;
		for (j = i + 1; j <= list->length; j++) {
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
	SelectSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}

}