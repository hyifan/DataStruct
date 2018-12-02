/*
栈（stack）
栈是限定仅在表尾进行插入和删除的线性表。我们把允许插入和删除的一端称为栈顶（top），另一端称为栈底（bottom），不含任何数据元素的栈称为空栈。栈又称为后进先出（Last In First Out）的线性表，简称LIFO结构。
该demo实现栈的链式存储结构。
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int data;
	struct Node *next;
} Node;


typedef struct Node *LinkList;


/* 初始化 */
LinkList InitList() {
	LinkList list = malloc(sizeof(LinkList));
	list->data = 0;
	list->next = NULL;
	return list;
}


/* 返回是否为空 */
int ListEmpty(LinkList list) {
	return list->data == 0;
}


/* 清空表 */
int ClearList(LinkList list) {
	int i;
	Node *s = malloc(sizeof(Node));
	for (i = list->data; i > 0; i--) {
		s = list->next;
		list->next = s->next;
		free(s);
	}
	list->data = 0;
	return 1;
}


/* 用e返回L的栈顶元素 */
int GetTop(LinkList list, int *e) {
	if (list->next == NULL) {
		return 0;
	}
	*e = list->next->data;
	return 1;
}


/* 插入 */
int Push(LinkList list, int e) {
	Node *p = list->next;
	Node *s = malloc(sizeof(Node));
	s->next = p;
	s->data = e;
	list->next = s;
	list->data++;
	return 1;
}


/* 删除 */
int Pop(LinkList list, int *e) {
	if (list->next == NULL) {
		return 0;
	}
	Node *p = list->next->next;
	Node *s = list->next;
	list->next = p;
	list->data--;
	*e = s->data;
	free(s);
	return 1;
}


int main(int argc, char *argv[]) {
	LinkList list = InitList();
	int i;

	printf("push：");
	for (i = 0; i < 10; i++) {
		Push(list, i);
		printf("%d ", i);
	}
	printf("\n");

	printf("pop：");
	for (i = 5; i >= 0; i--) {
		int elem;
		Pop(list, &elem);
		printf("%d ", elem);
	}
	printf("\n");

	printf("getTop：");
	int elem;
	GetTop(list, &elem);
	printf("%d ", elem);
	printf("\n");

	int isEmpty1 = ListEmpty(list);
	ClearList(list);
	int isEmpty2 = ListEmpty(list);
	printf("%d %d\n", isEmpty1, isEmpty2);

	free(list);
}

