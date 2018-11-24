/*
带头结点的单链表
单链表只包含一个指针域，结点由存放数据元素的数据域和存放后继结点地址的指针域组成。
头指针：是指链表指向第一个结点的指针，若链表有头结点，则是指向头结点的指针；无论链表是否为空，头指针均不为空；头指针是链表的必要元素。
头结点：头结点是为了操作的统一和方便而设立的，放在第一个元素的结点之前，其数据域一般无意义（也可存放链表的长度）；头结点不一定是链表的必要元素。
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
	LinkList list = malloc(sizeof(*list));
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
	//p：要插入位置i的前一个结点
	int j;
	Node *p = list;
	Node *s = malloc(sizeof(Node));
	if (i > list->data) {
		return 0;
	}
	for (j = 0; j < i; j++) {
		p = p->next;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
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
	s = p->next;
	p->next = s->next;
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













