/*
归并排序（Merging Sort）
归并排序就是利用归并的思想实现的排序方法。它的原理是假设初始序列含有 n 个记录，则可以看成是 n 个有序的子序列，每个子序列的长度为1，然后两两归并，得到【n/2】个长度为2或1的有序子序列；再两两归并，如此重复，直至得到一个长度为 n 的有序序列为止，这种排序方法称为2路归并排序。
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int min(int x, int y) {
	return x < y ? x : y;
}


void MergeSort(SqList *list) {
	int *copy = (int *)malloc(sizeof(int) * list->length);

	int i, j, start;
	for (i = 1; i < list->length; i += i) {
		for (start = 0; start < list->length; start += i * 2) {
			int low = start;
			int mid = min(start + i, list->length);
			int high = min(start + i * 2, list->length);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2) {
				copy[k++] = list->data[start1] < list->data[start2] ? list->data[start1++] : list->data[start2++];
			}
			while (start1 < end1) {
				copy[k++] = list->data[start1++];
			}
			while (start2 < end2) {
				copy[k++] = list->data[start2++];
			}
		}
		for (j = 0; j < list->length; j++) {
			list->data[j] = copy[j];
		}
	}
	free(copy);
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
	MergeSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}


/*


以下面数组arr为例，我们希望排序后arr[0]的值是最小。
7 9 8 10 3 5 4 6 1 2

第一步：
一一比较，若后一个数比前一个大，则交换位置

第二步：
两两比较，比较规则如下
先拿两边最小的数比较，得出排第一的元素，即较小的数；再那较小一边的第二个数与另一变第一个数比较，得出排第二的元素；剩下两个数再比较

第三步：
四四比较

第四步：
八八比较，规则跟第二步类似，具体做法大意如下（假设数组长度大于16，此时start1=0 end=8 start2=8 end2=16）
    1   2   3   4   6   7   8   9          5   10  11  12  13  14  15  16
    s1                                     s2
s1跟s2比较，较小的数排第一位，此时s1对应的数较小，copy[0] = 1，s1前进一步
    1   2   3   4   6   7   8   9          5   10  11  12  13  14  15  16
        s1                                 s2
s1跟s2比较，较小的数排第二位，copy[1] = 2，s1前进一步。以此类推，以下讨论s1前进到第五位，此时copy[2] = 3 copy[3] = 4
    1   2   3   4   6   7   8   9          5   10  11  12  13  14  15  16
                    s1                     s2
s1跟s2比较，copy[4] = 5，s2前进一位
    1   2   3   4   6   7   8   9          5   10  11  12  13  14  15  16
                    s1                         s2
s1跟s2比较，以此类推，s1前进到第九位，
    1   2   3   4   6   7   8   9          5   10  11  12  13  14  15  16
                                           s1  s2
此时start1==end1，s1停止前进，只需让s2前进至start2==end2即可。

下面讨论八八比较，数组长度等于10的情况（此时start1=0 end=8 start2=8 end2=10）：
    1   2   3   4   6   7   9   10         5   8
    s1                                     s2
s1跟s2比较，可一直前进到第五位
    1   2   3   4   6   7   9   10         5   8
                    s1                     s2
s2较小，s2前进一位
    1   2   3   4   6   7   9   10         5   8
                    s1                         s2
s1较小，以此类推前进两位
    1   2   3   4   6   7   9   10         5   8
                            s1                     s2
s2较小，前进一位，此时start2==end2，s2停止前进，只需让s1前进至start1==end1即可。


i = 1
start = 0，则 low = 0 mid = 1 high = 2，
copy[0] = 7 copy[1] = 9
start = 2，则 low = 2 mid = 3 high = 4
copy[2] = 8 copy[3] = 10
start = 4，则 low = 4 mid = 5 high = 6
copy[4] = 3 copy[5] = 5
start = 6，则 low = 5 mid = 6 high = 8
copy[6] = 4 copy[7] = 6
start = 8，则 low = 8 mid = 9 high = 9
copy[8] = 1 copy[9] = 2
copy：7 9 8 10 3 5 4 6 1 2

i = 2
start = 0，则 low = 0 mid = 2 high = 4
copy[0] = 7 copy[1] = 8 copy[2] = 9 copy[3] = 10
start = 4，则 low = 4 mid = 6 high = 8
copy[4] = 3 copy[5] = 4 copy[6] = 5 copy[7] = 6
start = 8，则 low = 8 mid = 9 high = 9
copy[8] = 1 copy[9] = 2

i = 4
start = 0，则 low = 0 mid = 4 high = 8
copy[0] = 3 copy[1] = 4 copy[2] = 5 copy[3] = 6 copy[4] = 7 copy[5] = 8 copy[6] = 9 copy[7] = 10

i = 8
start = 0，则 low = 0 mid = 8 high = 9
copy[0] = 1 copy[1] = 2 copy[2] = 3 copy[3] = 4 copy[4] = 5 copy[5] = 6 copy[6] = 7copy[7] = 8 copy[8] = 9 copy[9] = 10


*/

