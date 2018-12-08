/*
哈希表（）
*/


#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 12


typedef struct HashNode {
	int key;
	int value;
	struct HashNode *next;
} HashNode;


typedef struct HashTable {
	HashNode **buckets; /* 存储指针的数组 */
} HashTable;


/* 初始化哈希表 */
HashTable *InitHashTable() {
	HashTable *ht = malloc(sizeof(HashTable));
	ht->buckets = malloc(sizeof(HashNode *) * MAXSIZE);
	return ht;
}


/* 哈希函数 计算哈希地址 */
int hashfunc(int key) {
	return key % 11; /* 11为小于MAXSIZE的最大质数，可保存buckets长度足够 */
}


/* 采用链表法将 {key value} 插入 hash table */
int hashTableInsert(HashTable *ht, int key, int value) {
    int idx = hashfunc(key);

	HashNode *node = malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->next = ht->buckets[idx];
	ht->buckets[idx] = node;

	return 1;
}


/* 通过哈希函数寻找value */
int hashtableFind(HashTable *ht, int key, int *value) {
	int idx = hashfunc(key);
	HashNode *node = ht->buckets[idx];

	while (node) {
		if (node->key == key) {
			*value = node->value;
			return 1;
		}
		node = node->next;
	}

	return 0;
}


int main(int argc, char *argv[]) {
	/* 查找各元素在 [A, B, C, D, E, F, G, H, I, J, K, L, M, N] 中的位置，即key为A,B,...,N，对应的value为0,1,...,14 */
	int i;
	int value;
	char data[14] = "ABCDEFGHIJKLMN";

	HashTable *ht = InitHashTable();

	for (i = 0; i < 14; i++) {
		hashTableInsert(ht, data[i], i);
	}

	for (i = 0; i < 14; i++) {
		if (hashtableFind(ht, data[i], &value)) {
			printf("%d\n", value);
		}
	}

	return 1;
}