/*
二叉树遍历
*/


#include <stdio.h>
#include <stdlib.h>


/* 前序遍历 */
void PreOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c\n", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}


/* 中序遍历 */
void InOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	InOrderTraverse(T->lchild);
	printf("%c\n", T->data);
	InOrderTraverse(T->rchild);
}


/* 后序遍历 */
void PostOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c\n", T->data);
}