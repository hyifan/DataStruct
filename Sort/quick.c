/*
快速排序（Quick Sort）
快速排序的基本思想是：
通过一趟排序将待排记录分割成独立的两部分，其中一部分记录的关键字均比另一部分记录的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序的目的。
*/


#include <stdio.h>
#include <stdlib.h>
# MAX_LENGTH_INSERT_SORT 7

void QuickSort(SqList *L) {
	QSort(L, 1, L->length);
}


void QSort(SqList *L, int low, int high) {
	int pivot;
	if ((high - low) > MAX_LENGTH_INSERT_SORT) {
		while (low < high) {
			pivot = Partition(L, low, high);
			QSort(L, low, pivot - 1);
			low = pivot + 1;
		}
	} else {
		InsertSort(L);
	}
}


int Partition(SqList *L, int low, int high) {
	int pivotkey;

	int m = low + (high - low) / 2;
	if (L->data[low] > L->data[high]) {
		swap(L, low, high);
	}
	if (L->data[m] > L->data[high]) {
		swap(L, high, m);
	}
	if (L->data[m] > L->data[low]) {
		swap(L, m, low);
	}

	pivotkey = L->data[low];
	L->data[0] = pivotkey;
	while (low < high) {
		while (low < high && L->data[high] >= pivotkey) {
			high--;
		}
		L->data[low] = L->data[high];
		while (low < high && L->data[low] <= pivotkey) {
			low++;
		}
		L->data[hight] = L->data[low];
	}
	L->data[low] = L->data[0];
	return low;
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
	MergeSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}
}