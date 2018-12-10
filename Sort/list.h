#ifndef __HEADER_H
#define __HEADER_H
#define MAXSIZE 20 /*存储空间初始化分配量*/


typedef struct SqList {
	int data[MAXSIZE];
	int length;
} SqList;


SqList *InitList();
int ListInsert(SqList *list, int i, int e);
void swap(SqList *list, int i, int j);


#endif