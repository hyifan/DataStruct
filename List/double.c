/*
循环双向链表（double linked list）
双向链表是在单链表的每个结点中，再设置一个指向其前驱结点的指针域。
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int data;
	struct Node *prior;
	struct Node *next;
} Node;


typedef struct Node *LinkList;


/* 初始化 */
LinkList InitList() {
	LinkList list = malloc(sizeof(*list));
	list->data = 0;
	list->prior = list;
	list->next = list;
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
		s->next->prior = list;
		free(s);
	}
	list->data = 0;
	return 1;
}


/* 获得第i个元素 */
int GetElem(LinkList list, int i, int *e) {
	int j;
	Node *p = list;

	if (i >= list->data) {
		return 0;
	}
	for (j = 0; j < i + 1; j++) {
		p = p->next;
	}
	*e = p->data;
	return 1;
}


/* 返回e的序号 */
int LocateElem(LinkList list, int e) {
	int i;
	Node *p = list->next;
	for (i = 0; i < list->data && p->data != e; i++) {
		p = p->next;
	}
	if (i == list->data) {
		return -1;
	}
	return i;
}

/* 插入 */
int ListInsert(LinkList list, int i, int e) {
	// p：要插入位置i的前一个结点
	// q：要插入位置i的后一个结点
	int j;
	Node *p = list;
	Node *s = malloc(sizeof(Node));
	if (i > list->data) {
		return 0;
	}
	for (j = 0; j < i; j++) {
		p = p->next;
	}
	Node *q = p->next;

	s->data = e;
	s->prior = p;
	s->next = q;

	p->next = s;
	q->prior = s;

	list->data++;
	return 1;
}


/* 删除 */
int ListDelete(LinkList list, int i, int *e) {
	int j;
	Node *p = list;
	Node *s = malloc(sizeof(Node));

	if (i >= list->data) {
		return 0;
	}
	for (j = 0; j < i; j++) {
		p = p->next;
	}
	Node *q = p->next->next;

	s = p->next;
	p->next = q;
	q->prior = q;
	list->data--;
	*e = s->data;
	free(s);
	return 1;
}


int main(int argc, char *argv[]) {
	LinkList list = InitList();
	int i;

	printf("insert：");
	for (i = 0; i < 10; i++) {
		ListInsert(list, i, i);
		printf("%d ", i);
	}
	printf("\n");

	printf("delete：");
	for (i = 5; i >= 0; i--) {
		int elem;
		ListDelete(list, i, &elem);
		printf("%d ", elem);
	}
	printf("\n");

	printf("get：");
	for (i = 0; i < list->data; i++) {
		int elem;
		GetElem(list, i, &elem);
		printf("%d ", elem);
	}
	printf("\n");

	int locate = LocateElem(list, 9);
	int isEmpty1 = ListEmpty(list);
	ClearList(list);
	int isEmpty2 = ListEmpty(list);
	printf("%d %d %d\n", locate, isEmpty1, isEmpty2);

	free(list);
}













