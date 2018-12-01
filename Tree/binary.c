/*
二叉链表
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int data;
	struct Node *lchild, *rchild;
} Node;


typedef struct Node *BiTree;


/* 初始化 */
BiTree InitList() {
	BiTree tree = malloc(sizeof(*tree));
	tree->data = NULL;
	tree->lchild = NULL;
	tree->rchild = NULL;
	return tree;
}


/* 返回是否为空 */
int TreeEmpty(BiTree tree) {
	return tree->data == NULL;
}


/* 清空树 */
int ClearTree(BiTree tree) {
	// 后序遍历，从左到右先叶子后结点的方式访问所有结点并删除
	return 1;
}


/* 树深度 */
int TreeDepth(BiTree tree) {

	return 1;
}


/* 返回Tree的根结点 */
int Root(BiTree tree) {
	return tree->data;
}

/* 插入c为树Tree中p指结点的第i棵子树（1是左子树，2为右子树） */
int InsertChild(BiTree tree, *p, i, c) {
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


/* 删除Tree中p指结点的第i棵子树 */
int DeleteChild(BiTree tree, int *p, int i) {
	int j;
	Node *p = list;
	if (i >= list->data) {
		return 0;
	}
	for (j = 0; j < i; j++) {
		p = p->next;
	}
	Node *s = s = p->next;
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

