/*
希尔排序（Shell Sort）

*/


#include <stdio.h>
#include <stdlib.h>


void ShellSort(SqList *list) {
	int i, j;
	int increment = list->length;
	do {
		increment = increment/3 + 1;
		for (i = increment + 1; i <= list->length; i++) {
			if (list->data[i] < list->data[i-increment]) {
				list->data[0] = list->data[i];
				for (j = i - increment; j > 0 && list->data[0] < list->data[j]; j -= increment) {
					list->data[j+increment] = list->data[0];
				}
				list->data[j+increment] = list->data[0];
			}
		}
	} while (increment > 1);
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
	ShellSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}

}