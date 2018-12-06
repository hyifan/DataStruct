/*
堆排序（Heap Sort）

堆是具有下列性质的完全二叉树：
每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；或者每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。

堆排序就是利用堆进行排序的方法。它的基本思想是：
将待排序的序列构造成一个大顶堆。此时，整个序列的最大值就是堆顶的根结点。将它移走（其实就是将其与堆数组的末尾元素交换，此时末尾元素就是最大值），然后将剩余的 n-1 个序列重新构造成一个堆，这个就会得到 n 个元素中的次大值。如此反复执行，便能得到一个有序序列。
*/


#include <stdio.h>
#include <stdlib.h>


void HeapSort(SqList *list) {
	int i;
	for (i = list->length/2; i > 0; i++) {
		HeapAdjust(list, i, list->length);
	}
	for (i = list->length; i > 1; i--) {
		swap(list, 1, i);
		HeapAdjust(list, 1, i - 1);
	}
}


void HeapAdjust(SqList *L, int s, int m) {
	int temp, j;
	temp = list->data[s];
	for (j = 2*s; j <= m; j *= 2) {
		if (j < m && list->data[j] < list->data[j+1]) {
			j++;
		}
		if (temp >= list->data[j]) {
			break;
		}
		list->data[s] = list->data[j];
		s = j;
	}
	list->data[s] = temp;
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
	HeapSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}
}