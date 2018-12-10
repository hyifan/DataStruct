/*
简单选择排序（Simple Selection Sort）
简单选择排序就是通过 n-i 次关键字间的比较，从 n-i+1 个记录中选出关键字最小的记录，并和第 i(1<=i<=n) 个记录交换。
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void SelectSort(SqList *list) {
	int i, j, min;
	for (i = 0; i < list->length; i++) {
		min = i;
		for (j = i + 1; j < list->length; j++) {
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
	SelectSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}


/*


以下面数组arr为例，我们希望排序后arr[0]的值是最小，我们从i=0开始，依次跟j=i+1至j=length的数对比，将较小的数对应的下标存至min，若i不等于min，交换i跟min的数据；
最多经过9次交换可完成排序


i = 0，min = 8
j       1   2   3   4   5   6   7   8   9   交换
9   2                                       2
8   1                               min -   7
7   6                                       6
6   4                                       4
5   5                                       5
4   3               min -   -   -           3
3   10                                      10
2   8                                       8
1   9                                       9
0   7   min -   -                           1


i = 1，min = 9
j       2   3   4   5   6   7   8   9   交换
9   2                               min 9
8   7                                   7
7   6                                   6
6   4                                   4
5   5                                   5
4   3           min -   -   -   -       3
3   10                                  10
2   8   min -                           8
1   9                                   2
0   1   -   -   -   -   -   -   -   -   1


i = 2，min = 4
j       3   4   5   6   7   8   9   交换
9   9                               9
8   7                               7
7   6                               6
6   4                               4
5   5                               5
4   3           min -   -   -   -   8
3   10                              10
2   8   min                         3
1   2   -   -   -   -   -   -   -   2
0   1   -   -   -   -   -   -   -   1


i = 3，min = 6
j       4   5   6   7   8   9   交换
9   9                           9
8   7                           7
7   6                           6
6   4           min -   -   -   10
5   5       min                 5
4   8   min                     8
3   10                          4
2   3   -   -   -   -   -   -   3
1   2   -   -   -   -   -   -   2
0   1   -   -   -   -   -   -   1


i = 4，min = 5
j       5   6   7   8   9   交换
9   9                       9
8   7                       7
7   6                       6
6   10                      10
5   5   min -   -   -   -   8
4   8                       5
3   4   -   -   -   -   -   4
2   3   -   -   -   -   -   3
1   2   -   -   -   -   -   2
0   1   -   -   -   -   -   1


i = 5，min = 7
j       6   7   8   9   交换
9   9                   9
8   7                   7
7   6       min -   -   8
6   10                  10
5   8   min             6
4   5   -   -   -   -   5
3   4   -   -   -   -   4
2   3   -   -   -   -   3
1   2   -   -   -   -   2
0   1   -   -   -   -   1


i = 6，min = 8
j       7   8   9   交换
9   9               9
8   7       min -   10
7   8   min         8
6   10              7
5   6   -   -   -   6
4   5   -   -   -   5
3   4   -   -   -   4
2   3   -   -   -   3
1   2   -   -   -   2
0   1   -   -   -   1


i = 7，min = 7，无需交换
j       8   9   交换
9   9           9
8   10          10
7   8   min -   8
6   7   -   -   7
5   6   -   -   6
4   5   -   -   5
3   4   -   -   4
2   3   -   -   3
1   2   -   -   2
0   1   -   -   1


i = 8，min = 9
j       9   交换
9   9   min 10
8   10      9
7   8   -   8
6   7   -   7
5   6   -   6
4   5   -   5
3   4   -   4
2   3   -   3
1   2   -   2
0   1   -   1


*/

