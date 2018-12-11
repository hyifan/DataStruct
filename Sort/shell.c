/*
希尔排序（Shell Sort）
对直接插入排序进行改进，将原本有大量数据进行分组，分割成若干个子序列，在子序列内部进行直接插入排序，当整个序列都基本有序，再对全体数据进行直接插入排序。
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void ShellSort(SqList *list) {
	int i, j, num;
	int increment = list->length;
	do {
		increment = increment/3 + 1;
		for (i = increment; i < list->length; i++) {
			if (list->data[i] < list->data[i-increment]) {
				num = list->data[i];
				for (j = i - increment; j >= 0 && list->data[j] > num; j-=increment) {
					list->data[j+increment] = list->data[j]; /* data[j]比num大，后移一位 */
				}
				list->data[j+increment] = num;
			}
		}
	} while (increment > 1);
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
	ShellSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}


/*


以下面数组arr为例，我们希望排序后arr[0]的值是最小。
初始化步长 increment = length/3 + 1 = 10/3 + 1 = 4
数组：7 9 8 10 3 5 4 6 1 2

以步长4排列：
7  9  8  10
3  5  4  6
1  2
然后我们对每列进行排序：
1  2  4  6
3  5  8  10
7  9
即得 1 2 4 6 3 5 8 10 7 9


继续计算步长 increment = increment/3 + 1 = 2
以步长2排列：
1  2
4  6
3  5
8  10
7  9
然后我们对每列进行排序：
1  2
3  5
4  6
7  9
8  10
即得 1 2 3 5 4 6 7 9 8 10

最后以1步长进行排序（此时就是简单的插入排序了）


*/