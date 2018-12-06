/*
直接插入排序（Straight Insertion Sort）
直接插入排序的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表。
*/


#include <stdio.h>
#include <stdlib.h>


void InsertSort(SqList *list) {
	int i, j;
	for (i = 2; i <= list->length; i++) {
		if (list->data[i] < list->data[i-1]) {
			list->data[0] = list->data[i];
			for (j = i - 1; list->data[j] > list->data[i]; j--) {
				list->data[j+1] = list->data[j];
			}
			list->data[j+1] = list->data[0];
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
	InsertSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}

}