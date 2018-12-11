/*
堆排序（Heap Sort）

堆是具有下列性质的完全二叉树：
每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；或者每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。

堆排序就是利用堆进行排序的方法。它的基本思想是：
将待排序的序列构造成一个大顶堆。此时，整个序列的最大值就是堆顶的根结点。将它移走（其实就是将其与堆数组的末尾元素交换，此时末尾元素就是最大值），然后将剩余的 n-1 个序列重新构造成一个堆，这样就会得到 n 个元素中的次大值。如此反复执行，便能得到一个有序序列。
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void HeapAdjust(SqList *list, int start, int end) {
	int dad = start;
	int son = dad * 2 + 1; // 左子节点
	while (son < end) {
		if (son + 1 < end && list->data[son] < list->data[son + 1]) {
		    // 先比较两个子节点的大小，选择最大的
			son++;
		}
		if (list->data[dad] > list->data[son]) {
		    // 如果父节点大于子节点代表跳出完毕，直接跳出函數
			return;
		} else {
		    // 否则交换父子內容再继续子节点和孙节点的比较
			swap(list, dad, son);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}


void HeapSort(SqList *list) {
	int i;
	for (i = list->length / 2 - 1; i >= 0; i--) {
		HeapAdjust(list, i, list->length);
	}
	for (i = list->length - 1; i > 0; i--) {
		// list->data[0] 为调整完的大顶堆的第一个元素，即最大值；i 为未排序序列的最后一个位置，存储新调整的大顶堆的第一个元素
		swap(list, 0, i);
		HeapAdjust(list, 0, i);
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
	HeapSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}


/*


以下面数组arr为例，我们希望排序后arr[0]的值是最小。
7 9 8 10 3 5 4 6 1 2


i = 10/2 - 1 = 4
HeapAdjust(list, 4)：arr[4] = 3，3>2，无需变换
	             7
	      9             8
	10         3   5         4
 6      1   2


i = 3
HeapAdjust(list, 3)：arr[3] = 10，6>1 10>6，无需变换
	             7
	      9             8
	10         3   5         4
 6      1   2


i = 2
HeapAdjust(list, 2)：arr[2] = 8，5>4 8>5，无需变换
	             7
	      9             8
	10         3   5         4
 6      1   2


i = 1
HeapAdjust(list, 1)：arr[1] = 9，9<10，9与10互换，继续 9 跟 6 1的对比，因为 6>1 9>6，无需交换
	             7
	      10            8
	 9         3   5         4
  6     1   2


i = 0
HeapAdjust(list, 0)：arr[0] = 7，8<10 7<10，7与10互换，继续 7 跟 9 3的对比并与9互换，因为 6>1 7>6，无需交换
	             10
	      9             8
	 7         3   5         4
  6     1   2


至此一颗大顶堆就完成了。

从 i = length - 1 开始，即将最后一个元素，跟大顶堆的第一个元素交换，因为此时大顶堆的第一个元素是最大的
接下来对 第一个元素开始的 end = length - 1 个元素继续使用HeapAdjust()，或得的第一个元素复制给 end，得到最终结果。

*/