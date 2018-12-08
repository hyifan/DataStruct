#ifndef __HEADER_H
#define __HEADER_H


typedef struct Node {
	char data;
	struct Node *lchild;
	struct Node *rchild;
} Node;


void PreOrderTraverse(Node *root);
void InOrderTraverse(Node *root);
void PostOrderTraverse(Node *root);


#endif