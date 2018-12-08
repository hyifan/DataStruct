/*
队列（queue）
队列是只允许在一端进行插入操作、而在另一端进行删除操作的线性表。队列是一种先进先出（First In First Out）的线性表，简称FIFO。允许插入的一端称为队尾，允许删除的一端称为队头。
该demo实现队列的链式存储结构。
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


/* 用e返回L的队头元素 */
int GetTop(LinkList list, int *e) {
	if (list->next == NULL) {
		return 0;
	}
	*e = list->next->data;
	return 1;
}


/* 插入 */
int Push(LinkList list, int e) {
	int j;
	Node *p = list;
	for (j = 0; j < list->data; j++) {
		p = p->next;
	}
	Node *s = malloc(sizeof(Node));
	s->next = NULL;
	s->data = e;
	p->next = s;
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
	return 1;
}

