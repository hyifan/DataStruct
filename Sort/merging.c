/*
归并排序（Merging Sort）
归并排序就是利用归并的思想实现的排序方法。它的原理是假设初始序列含有 n 个记录，则可以看成是 n 个有序的子序列，每个子序列的长度为1，然后两两归并，得到【n/2】个长度为2或1的有序子序列；再两两归并，如此重复，直至得到一个长度为 n 的有序序列为止，这种排序方法称为2路归并排序。
*/


#include <stdio.h>
#include <stdlib.h>


void MergeSort(SqList *list) {
	MSort(list->data, list->data, 1, list->length);
}


void MSort(int SR[], int TR1[], int s, int t) {
	int m;
	int TR2[MAXSIZE + 1];
	if (s == t) {
		TR1[s] = SR[s];
	} else {
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}


void Merge(int SR[], int TR[], int i, int m, int n) {
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j<= n; k++) {
		if (SR[i] < SR[j]) {
			TR[k] = SR[i++];
		} else {
			TR[k] = SR[j++];
		}
	}
	if (i <= m) {
		for (l = 0; l <= m - i; l++) {
			TR[k + 1] = SR[i + 1];
		}
	}
	if (j <= n) {
		for (l = 0; l <= n - j; l++) {
			TR[k + 1] = SR[j + 1];
		}
	}
}


void MergeSort2(SqList *L) {
	int *TR = (int *)malloc(L->length*sizeof(int));
	int k = 1;
	while (k < L->length) {
		MergePass(L->data, TR, k, L->length);
		k = 2 * k;
		MergePass(TR, L->data, k, L->length);
		k = 2 * k;
	}
}


void MergePass(int SR[], int TR[], int s, int n) {
	int i = 1;
	int j;
	while (i <= n - 2 * s + 1) {
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	if (i < n - s + 1) {
		Merge(SR, TR, i, i + s - 1, n);
	} else {
		for (j = i; j <= n; j++) {
			TR[j] = SR[j];
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
	MergeSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}
}