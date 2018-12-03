/*
串的顺序存储结构
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 20 /*存储空间初始化分配量*/


typedef struct String {
    int length;
    int size;
    char *data;
} String;


/* 初始化 */
String *InitString() {
	String *S;
    S = malloc(sizeof(String));
    S->length = 0;
    S->size = MAXSIZE;
    S->data = malloc(MAXSIZE);
    return S;
}

/* 生成一个其值等于字符串常量str的串S */
int StrAssign(String *S, char *str) {
    int length = strlen(str);

    if (S->size < length) {
        int newsize = S->size + length;
        char *newdata = realloc(S->data, newsize);
        S->size = newsize;
        S->data = newdata;
    }

    memcpy(S->data, str, length);
    S->length += length;
	return 1;
}


/* 串S存在，由串S复制得串T */
int StrCopy(String *T, String *S) {
	if (T->size < S->length) {
		int newsize = S->length;
        char *newdata = realloc(T->data, newsize);
        T->size = newsize;
        T->data = newdata;
	}

	int i;
	for (i=0; i<S->length; i++) {
		T->*(data+i) = S->*(data+i);
	}
	return 1;
}


/* 串S存在，将串清空 */
int ClearString(String *S) {
    free(S->data);
    S->length = 0;
    S->size = MAXSIZE;
    S->data = malloc(MAXSIZE);
	return 1;
}


/* 若串S为空，返回true，否则返回false */
int StringEmpty(String *S) {
	return S->length == 0;
}


/* 若S>T，返回值>0，若S=T，返回0，若S<T，返回值<0 */
int StrCompare(String *S, String *T) {
	int length = S->length > T->length ? T->length : S->length;
	int i;
	for (int i = 0; i<length; i++) {
		if (S->*(data+i) > T->*(data+i)) {
			return 1;
		} else if (S->*(data+i) < T->*(data+i)) {
			return -1;
		}
	}
	if (S->length > T->length) {
		return 1;
	} else if (S->length == T->length) {
		return 0;
	} else {
		return -1;
	}
}


/* 用T返回由串S1和串S2连接而成的新串 */
int Concat(String *T, String *S1, String *S2) {
    int length = S1->length + S2->length;

    if (T->size < length) {
        int newsize = length;
        char *newdata = realloc(T->data, newsize);
        T->size = newsize;
        T->data = newdata;
    }

    int i, j;
	for (i=0; i<S1->length; i++) {
		T->*(data+i) = S1->*(data+i);
	}
	for (j=0; i<S2->length; j++) {
		T->*(data+i+j) = S2->*(data+j);
	}

    T->length = length;
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
	String *S1 = InitString();
	StrAssign(*S1, 'hello');

	String *T = InitString();
	StrCopy(*T, *S1);

	StrCompare(*T, *S1);

	int empty1 = StringEmpty(*T);
	ClearString(*T);
	int empty2 = StringEmpty(*T);

	String *S2 = InitString();
	StrAssign(*S2, ' world!');
	Concat(*T, *S1, *S2);



	free(*S1);
	free(*S2);
	free(*T);
}

