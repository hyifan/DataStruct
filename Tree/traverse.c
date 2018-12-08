/*
二叉树遍历
*/


#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/* 前序遍历 */
void PreOrderTraverse(Node *root) {
	if (root == NULL) {
		return;
	}
	printf("%c", root->data);
	PreOrderTraverse(root->lchild);
	PreOrderTraverse(root->rchild);
}


/* 中序遍历 */
void InOrderTraverse(Node *root) {
	if (root == NULL) {
		return;
	}
	InOrderTraverse(root->lchild);
	printf("%c", root->data);
	InOrderTraverse(root->rchild);
}


/* 后序遍历 */
void PostOrderTraverse(Node *root) {
	if (root == NULL) {
		return;
	}
	PostOrderTraverse(root->lchild);
	PostOrderTraverse(root->rchild);
	printf("%c", root->data);
}