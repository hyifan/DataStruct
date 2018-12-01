/*
串的顺序存储结构
*/


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20 /*存储空间初始化分配量*/


typedef struct String
{
	*char data[] = malloc(sizeof(MAXSIZE));
	int length;
	int maxsize;
} String;


/* 生成一个其值等于字符串常量chars的串 */
String *InitString(char *chars) {
	String *S = malloc(sizeof(String));
	int i = 0;
	int j = 0;
	char *p = *chars;

	do {
		j++;
		S->maxsize = MAXSIZE * j;
		if (j != 1) {
			S->data = (char *)realloc(S->data, S->maxsize);
		}
		while (*p != '\0' && i < S->maxsize) {
			S->data[i] = *p;
			i++;
			*p = *(p + 1);
		}
	} while (i == S->maxsize && *p != '\0');

	S->length = i;
	return S;
}


/* 串S存在，由串S复制得串T */
int StrCopy(String *T, String *S) {
	T = S;
	return 1;
}


/* 串S存在，将串清空 */
int ClearString(String *S) {
    S->length = 0;
	return 1;
}


/* 若串S为空，返回true，否则返回false */
int StringEmpty(String *S) {
	return S->length == 0;
}


/* 若S>T，返回值>0，若S=T，返回0，若S<T，返回值<0 */
int StrCompare(S, T) {

}


/* 用T返回由S1和S2连接而成的新串 */
int Concat(String *T, String *S1, String *S2) {
	if (S1->length + S2->length < MAXSIZE) {
		return 0;
	}
	int i = 0;
	while (i < S1->length) {
		T->data[i] = S1->data[i];
		i++;
	}
	while (i < S1->length + S2->length) {
		T->data[i] = S2->data[i - S1->length];
		i++;
	}
	T->length = S1->length + S2->length;
	return 1;
}


/* 串S存在，用Sub返回串S的第pos个字符起长度为len的子串 */
int SubString(Sub, S, pos, len) {

}


/* 若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回-1 */
int Index(S, T, pos) {

}


/* 用V替换主串S中出现的所有与T相等的不重叠的子串 */
int Replace(S, T, V) {

}


/* 在串S的第pos个字符之前插入串T */
int StrInsert(S, pos, T) {

}


/* 从串S中删除第pos个字符起长度为len的子串 */
int StrDelete(S, pos, len) {

}


int main(int argc, char *argv[]) {
	char chars[] = "hello";
	String *string = InitString(&chars[0]);
	free(chars);

	String *T = malloc(sizeof(String));
	StrCopy(*T, *string);

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
	for (i = 0; i < list->length; i++) {
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

