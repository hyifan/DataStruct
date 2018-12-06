/*
二叉链表
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	char data;
	struct Node *lchild, *rchild;
} Node;


typedef struct Node *BiTree;


/* 初始化 */
BiTree *InitTree() {
	BiTree tree = malloc(sizeof(BiTree));
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
	if (tree == NULL) {
		return;
	}
	ClearTree(tree->lchild);
	ClearTree(tree->rchild);
	free(tree);
	return 1;
}


/* 树深度 */
int TreeDepth(BiTree tree) {

	return 1;
}


/* 返回Tree的根结点 */
Node Root(BiTree tree) {
	Node *p;
	p->data = tree->data;
	p->lchild = tree->lchild;
	p->rchild = tree->rchild
	return p;
}

/* 插入c为树Tree中p结点的第i棵子树（0是左子树，1为右子树） */
int InsertChild(Node *p, int i, Node *c) {
	if (i == 0) {
		p->lchild = c;
	} else if (i == 1) {
		p->rchild = c;
	} else {
		return 0;
	}
	return 1;
}


/* 删除Tree中p结点的第i棵子树（0是左子树，1为右子树） */
int DeleteChild(Node *p, int i) {
	BiTree tree = InitTree();
	if (i == 0 && p->lchild != NULL) {
		tree->data = p->lchild->data;
		tree->lchild = p->lchild->lchild;
		tree->rchild = p->lchild->rchild;
		p->lchild = NULL;
	} else if (i == 1 && p->rchild != NULL) {
		tree->data = p->rchild->data;
		tree->lchild = p->rchild->lchild;
		tree->rchild = p->rchild->rchild;
		p->rchild = NULL;
	} else {
		return 0;
	}
	ClearTree(tree);
	free(tree);
	return 1;
}


int main(int argc, char *argv[]) {
	BiTree tree = InitTree();
	tree->data = 'A';
	Node root = Root(tree);

	/*
	  插入结点，使树结构为
		        A
		    B        C
		  D        E   F
	    G
	  H
	*/
	char data[7];
	data[0] = 'B';
	data[1] = 'C';
	data[2] = 'D';
	data[3] = 'E';
	data[4] = 'F';
	data[5] = 'G';
	data[6] = 'H';

	int i;
	for (i = 0; i < 7; i++) {
		Node *node = malloc(sizeof(Node));
		node->data = data[i];
		node->lchild = NULL;
		node->rchild = NULL;
		switch (i) {
		    case 0:
		    case 1:
		        InsertChild(root, i, node);
		        break;
		    case 2:
		        InsertChild(root->lchild, 0, node);
		        break;
		    case 3:
		        InsertChild(root->rchild, 0, node);
		        break;
		    case 4:
		        InsertChild(root->rchild, 1, node);
		        break;
		    case 5:
		        InsertChild(root->lchild->lchild, 0, node);
		        break;
		    case 6:
		        InsertChild(root->lchild->lchild->lchild, 0, node);
		        break;
		    default:;
		}
	}

	int depth1 = TreeDepth(tree);
	DeleteChild(root->lchild->lchild->lchild, 0);
	int depth2 = TreeDepth(tree);

	int isEmpty1 = TreeEmpty();
	ClearTree(tree);
	int isEmpty2 = TreeEmpty();

	printf("%d %d %d %d\n", depth1, depth2, isEmpty1, isEmpty2);

	free(tree);
}

