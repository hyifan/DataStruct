/*
二叉链表
*/


#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


/* 初始化 */
Node *InitTree(char val) {
	struct Node *node;
	node = malloc(sizeof(struct Node));
	node->data = val;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}


/* 清空树 */
void ClearTree(Node *root) {
	if (root == NULL) {
		return;
	}
	ClearTree(root->lchild);
	ClearTree(root->rchild);
	free(root);
}


/* 树深度 */
int TreeDepth(Node *root) {
    if (root == NULL) {
    	return 0;
    }
    int left = TreeDepth(root->lchild);
    int right = TreeDepth(root->rchild);
	return left > right ? left + 1 : right + 1;
}


/* 插入node为树Tree中root结点的第i棵子树（0是左子树，1为右子树） */
int InsertChild(Node *root, int i, Node *node) {
	if (i == 0) {
		root->lchild = node;
	} else if (i == 1) {
		root->rchild = node;
	} else {
		return 0;
	}
	return 1;
}


/* 删除Tree中root结点的第i棵子树（0是左子树，1为右子树） */
int DeleteChild(Node *root, int i) {
	Node *newroot;
	if (i == 0 && root->lchild != NULL) {
		newroot = InitTree(root->lchild->data);
		newroot->lchild = root->lchild->lchild;
		newroot->rchild = root->lchild->rchild;
		root->lchild = NULL;
	} else if (i == 1 && root->rchild != NULL) {
		newroot = InitTree(root->rchild->data);
		newroot->lchild = root->rchild->lchild;
		newroot->rchild = root->rchild->rchild;
		root->rchild = NULL;
	} else {
		return 0;
	}

	ClearTree(newroot);

	return 1;
}


int main(int argc, char *argv[]) {
	/*
	  插入结点，使树结构为
		        A
		    B        C
		  D        E   F
	    G
	  H
	*/
	char data[8] = "ABCDEFGH";
	Node *root = InitTree(data[0]);

	int i;
	for (i = 1; i < 8; i++) {
		switch (i) {
		    case 1:
		        InsertChild(root, 0, InitTree(data[i]));
		        break;
		    case 2:
		        InsertChild(root, 1, InitTree(data[i]));
		        break;
		    case 3:
		        InsertChild(root->lchild, 0, InitTree(data[i]));
		        break;
		    case 4:
		        InsertChild(root->rchild, 0, InitTree(data[i]));
		        break;
		    case 5:
		        InsertChild(root->rchild, 1, InitTree(data[i]));
		        break;
		    case 6:
		        InsertChild(root->lchild->lchild, 0, InitTree(data[i]));
		        break;
		    case 7:
		        InsertChild(root->lchild->lchild->lchild, 0, InitTree(data[i]));
		        break;
		    default:;
		}
	}

	int depth1 = TreeDepth(root);
	DeleteChild(root->lchild->lchild->lchild, 0);
	int depth2 = TreeDepth(root);
	printf("%d %d\n", depth1, depth2);

	printf("%s\n", "前序遍历：");
	PreOrderTraverse(root);
	printf("\n");

	printf("%s\n", "中序遍历：");
	InOrderTraverse(root);
	printf("\n");

	printf("%s\n", "后序遍历：");
    PostOrderTraverse(root);
	printf("\n");
	
	ClearTree(root);
	printf("%d\n", root == NULL);
}

