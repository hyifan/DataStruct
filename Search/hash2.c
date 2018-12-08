#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashNode {
	int key;
	int value;
	struct HashNode *next;
} HashNode;

typedef struct HashTable {
	HashNode **buckets;
	int size;
} HashTable;

#define INIT_BUCKET_SIZE 64

HashTable *hashtable_new()
{
	HashTable *ht;

	ht = malloc(sizeof(HashTable));

	ht->buckets = malloc(sizeof(HashNode *) * INIT_BUCKET_SIZE);
	memset(ht->buckets, 0, sizeof(HashNode *) * INIT_BUCKET_SIZE);
	ht->size = INIT_BUCKET_SIZE;

	return ht;
}

int hashfunc(HashTable *ht, int key)
// 哈希函数
{
	return key % ht->size;
}

int hashtable_insert(HashTable *ht, int key, int value)
{
	HashNode *node;
	int idx = hashfunc(ht, key);

	node = malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->next = ht->buckets[idx];
	ht->buckets[idx] = node;

	return 1;
}

int hashtable_find(HashTable *ht, int key, int *retval)
{
	int idx = hashfunc(ht, key);
	HashNode *node = ht->buckets[idx];

	while (node) {
		if (node->key == key) {
			*retval = node->value;
			return 1;
		}
		node = node->next;
	}

	return 0;
}

int main()
{
	int i;
	int value;
	HashTable *ht = hashtable_new();

	for (i = 0; i < 100; i++) {
		hashtable_insert(ht, i, i * 10);
	}

	for (i = 0; i < 100; i++) {
		if (hashtable_find(ht, i, &value)) {
			printf("%d\n", value);
		}
	}

	return 0;
}
