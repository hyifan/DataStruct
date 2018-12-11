/*
直接插入排序（Straight Insertion Sort）
直接插入排序的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的、记录数增1的有序表。
*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void InsertSort(SqList *list) {
	int i, j, num;
	for (i = 1; i < list->length; i++) {
		if (list->data[i] < list->data[i-1]) {
			num = list->data[i];
			for (j = i - 1; j >= 0 && list->data[j] > num; j--) {
				list->data[j+1] = list->data[j]; /* data[j]比num大，后移一位 */
			}
			list->data[j+1] = num;
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
	InsertSort(list);

	/* 输出排序后的结果 */
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}


/*


以下面数组arr为例，我们希望排序后arr[0]的值是最小。
先设置num为中间值。


7 9 8 10 3 5 4 6 1 2


i = 1
因为 9<7 为flase，不发生变化，得
7 9 8 10 3 5 4 6 1 2


i = 2
因为 8<9 为true，num = 8
j = 1，9后移
j = 0，7>8为false，7无需后移，此时arr[1] = num，得
7 8 9 10 3 5 4 6 1 2


i = 3
因为 10<9 为flase，不发生变化，得
7 8 9 10 3 5 4 6 1 2


i = 4
因为 3<10 为true，num = 3
j = 3，10后移
j = 2，9后移
j = 1，8后移
j = 0，7后移，此时arr[0] = num，得
3 7 8 9 10 5 4 6 1 2


i = 5
因为 5<10 为true，num = 5
j = 4，10后移
j = 3，9后移
j = 2，8后移
j = 1，7后移
j = 0，3>5为false，3无需后移，此时arr[1] = num，得
3 5 7 8 9 10 4 6 1 2


i = 6
因为 4<10 为true，num = 4
j = 5，10后移
j = 4，9后移
j = 3，8后移
j = 2，7后移
j = 1，5后移
j = 0，3>4为false，3无需后移，此时arr[1] = num，得
3 4 5 7 8 9 10 6 1 2


i = 7
因为 6<10 为true，num = 6
j = 6，10后移
j = 5，9后移
j = 4，8后移
j = 3，7后移
j = 2，5>6为false，5无需后移，此时arr[3] = num，得
3 4 5 6 7 8 9 10 1 2


i = 8
因为 1<10 为true，num = 1
j = 7，10后移
j = 6，9后移
j = 5，8后移
j = 4，7后移
j = 3，6后移
j = 2，5后移
j = 1，4后移
j = 0，3后移，此时arr[0] = num，得
1 3 4 5 6 7 8 9 10 2


i = 9
因为 2<10 为true，num = 2
j = 8，10后移
j = 7，9后移
j = 6，8后移
j = 5，7后移
j = 4，6后移
j = 3，5后移
j = 2，4后移
j = 1，3后移
j = 0，1>2为false，1无需后移，此时arr[1] = num，得
1 2 3 4 5 6 7 8 9 10


*/
