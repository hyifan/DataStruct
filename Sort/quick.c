/*
快速排序（Quick Sort）
快速排序的基本思想是：
通过一趟排序将待排记录分割成独立的两部分，其中一部分记录的关键字均比另一部分记录的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序的目的。
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int Partition(SqList *list, int low, int high) {
	int pivotkey; /* 定义中轴数 */

	/* 按照三数取中选取中轴数，并重新排列三个数的位置，使得arr[low]=pivotkey，low[min]=最小数，low[high]=最大数 */
	int min = low + (high - low) / 2;
	if (list->data[low] > list->data[high]) {
		swap(list, low, high);
	}
	if (list->data[min] > list->data[high]) {
		swap(list, high, min);
	}
	if (list->data[min] > list->data[low]) {
		swap(list, min, low);
	}

	pivotkey = list->data[low];
	while (low < high) {
		while (low < high && list->data[high] >= pivotkey) {
			high--;
		}
		swap(list, low, high);
		while (low < high && list->data[low] <= pivotkey) {
			low++;
		}
		swap(list, low, high);
	}
	return low; /* 返回中轴数所在位置 */
}


void QSort(SqList *list, int low, int high) {
	if ((high - low) > 1) {
		/* 三个数字以上情况 */
		int pivot = Partition(list, low, high);
		QSort(list, low, pivot - 1);
		QSort(list, pivot + 1, high);
	} else if ((high - low) == 1) {
		/* 两个数字 */
		if (list->data[low] > list->data[high]) {
			swap(list, low, high);
		}
	}
}


void QuickSort(SqList *list) {
	QSort(list, 0, list->length - 1);
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
	QuickSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}


/*


以下面数组arr为例，我们希望排序后arr[0]的值是最小。
7 9 8 10 3 5 4 6 1 2

初始化中轴数pivotkey，采用三数取中方式，三数为arr[low]、arr[high]、arr[min=low + (high - low) / 2]
循环体：{
	先比较arr[high]与pivotkey大小。
	若arr[high]>=pivotkey，high后退一步，一直后退到high与low相遇，或不满足条件。
	high跟low交换。
	再比较arr[low]与pivotkey大小。
	若arr[low]<=pivotkey，low前进一步，一直前进到high与low相遇，或不满足条件。
	high跟low交换。
}
若此时 low 跟 high 未相遇，继续上面的循环体。
经过这一轮排序，low 跟 high 都指向了 pivotkey，此时 pivotkey 所在位置的左边均比它小，右边均比它大。再分别对左右两边的序列进行同意的排序，递归，可得最终结果。


按照三数取中取得中轴数为pivotkey = 3，并重新排列三个数的位置，使得arr[low]=pivotkey，low[min]=最小数，low[high]=最大数
		7   9   8   10  3   5   4   6   1   2
	    3   9   8   10  2   5   4   6   1   7
	    low                                 high

high-1  3   9   8   10  2   5   4   6   1   7
	    low                             high

swap    1   9   8   10  2   5   4   6   3   7
	    low                             high

low+1   1   9   8   10  2   5   4   6   3   7
	        low                         high

swap    1   3   8   10  2   5   4   6   9   7
	        low                         high

high-4  1   3   8   10  2   5   4   6   9   7
	        low         high

swap    1   2   8   10  3   5   4   6   9   7
	        low         high

low+1   1   2   8   10  3   5   4   6   9   7
	                low high

swap    1   2   8   3   10  5   4   6   9   7
	                low high

high-1	1   2   8   3   10  5   4   6   9   7
	             low_high


*/