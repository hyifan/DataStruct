/*
串的顺序存储结构
*/


#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 20 /*存储空间初始化分配量*/


typedef struct String {
    int length;
    int size;
    char *data;
} String;


/* 初始化 */
String *InitString() {
	String *S = malloc(sizeof(String));
    S->length = 0;
    S->size = MAXSIZE;
    S->data = malloc(sizeof(char) * MAXSIZE);
    return S;
}


/*---辅助函数start ---*/
/* 计算str长度 */
int strlength(char *str) {
	int i;
	for (i = 0; *(str+i) != '\0'; i++) {
		;
	}
	return i;
}


/* 将str的前length字符加在data后面 */
void memcopy(char *data, char*str, int length) {
	int i;
	for (i = 0; i < length; i++) {
		data[i] = str[i];
	}
}


/* 打印字符串 */
void printString(String *S) {
	int i;
	for (i = 0; i < S->length; i++) {
		printf("%c", S->data[i]);
	}
	printf(" ");
}
/*--- 辅助函数end ---*/


/* 生成一个其值等于字符串常量str的串S */
int StrAssign(String *S, char *str) {
    int length = strlength(str);

    if (S->size < length) {
        int newsize = S->size + length;
        char *newdata = realloc(S->data, newsize);
        S->size = newsize;
        S->data = newdata;
    }

    memcopy(S->data, str, length);
    S->length += length;
	return 1;
}


/* 串S存在，由串S复制得串T */
int StrCopy(String *T, String *S) {
	if (T->length > 0) {
		return 0;
	}
	if (T->size < S->length) {
		int newsize = S->length;
        char *newdata = realloc(T->data, newsize);
        T->size = newsize;
        T->data = newdata;
	}

	int i;
	for (i = 0; i < S->length; i++) {
		T->data[i] = S->data[i];
	}
	T->length = S->length;
	return 1;
}


/* 串S存在，将串清空 */
int ClearString(String *S) {
    S->length = 0;
    if (S->size > MAXSIZE) {
    	int newsize = MAXSIZE;
        char *newdata = realloc(S->data, newsize);
        S->size = newsize;
        S->data = newdata;
    }
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
		if (S->data[i] > T->data[i]) {
			return 1;
		} else if (S->data[i] < T->data[i]) {
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
		T->data[i] = S1->data[i];
	}
	for (j=0; j<S2->length; j++) {
		T->data[i+j] = S2->data[j];
	}

    T->length = length;
	return 1;
}


/* 串S存在，用Sub返回串S的第pos个字符起长度为length的子串 */
int SubString(String *Sub, String *S, int pos, int length) {
	if (S->length - pos < length || Sub->length > 0) {
		return 0;
	}
	if (Sub->size < length) {
        int newsize = length;
        char *newdata = realloc(Sub->data, newsize);
        Sub->size = newsize;
        Sub->data = newdata;
    }
	int i;
	for (i = 0; i < length; i++) {
		Sub->data[i] = S->data[pos+i];
	}
	Sub->length = length;
	return 1;
}


/* 若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回-1 */
int Index(String *S, String *T, int pos) {
	int i, j;

	for (i = 0; i < S->length; i++) {
		j = 0;
		if (S->data[i] == T->data[0]) {
			if (S->length - i < T->length) {
				return -1;
			}

			for (j = 1; j < T->length; j++) {
				if (S->data[j] != T->data[j]) {
					goto next;
				}
			}
			return i;
		}

 		next:;
	}

	return -1;
}


/* 在串S的第pos个字符之前插入串T */
int StrInsert(String *S, int pos, String *T) {
	if (pos >= S->length) {
		return 0;
	}
	if (S->size < S->length + T->length) {
		int newsize = S->length + T->length;
	    char *newdata = realloc(S->data, newsize);
	    S->size = newsize;
	    S->data = newdata;
	}
	int i;
	// 把pos之后的数据往后迁移
	for (i = S->length + T->length; i < pos + T->length; i--) {
	    S->data[i] = S->data[i - T->length];
	}
	// 将T的值填充到迁移出来的位置
	for (i = 0; i < T->length; i++) {
		S->data[pos + i] = T->data[i];
	}
	S->length += T->length;
	return 1;
}


/* 从串S中删除第pos个字符起长度为length的子串 */
int StrDelete(String *S, int pos, int length) {
	if (S->length - pos < length) {
		return 0;
	}
	int i;
	for (i = pos + length - 1; i < S->length; i++) {
		S->data[i - length] = S->data[i];
	}
	S->length -= - length;
	if (S->size > length && S->size > MAXSIZE) {
        int newsize = MAXSIZE;
        char *newdata = realloc(S->data, newsize);
        S->size = newsize;
        S->data = newdata;
    }
	return 1;
}


/* 用V替换主串S中出现的所有与T相等的不重叠的子串 */
int Replace(String *S, String *T, String *V) {
	int i = Index(S, T, 0);
	int j = 0;
	
	if (i < 0) {
		return 0;
	}

	int *a = malloc(sizeof(int) * S->length);
	while (i >= 0) {
		a[j] = i;
		i = Index(S, T, i + T->length);
		j++;
	}

    for (i = j; i > 0; i--) {
    	// 从S中删除第a[i]个字符起长度为T->length的子串T
    	StrDelete(S, a[i], T->length);
    	// 在串S的第a[i]个字符之前插入串V
    	StrInsert(S, a[i], V);
    }
    free(a);
	return 1;
}


int main(int argc, char *argv[]) {
	String *S1 = InitString();
	StrAssign(S1, "hello");

	String *T = InitString();
	StrCopy(T, S1);

	int compare = StrCompare(S1, T);

	printString(S1);
	printString(T);
	printf("%d ", compare);

	int isEmpty1 = StringEmpty(T);
	ClearString(T);
	int isEmpty2 = StringEmpty(T);

	printf("%d %d\n", isEmpty1, isEmpty2);

	String *S2 = InitString();
	StrAssign(S2, " world!");
	Concat(T, S1, S2);
	
	printString(S1);
	printString(S2);	
	printString(T);
	printf("\n");

	free(S1);
	free(S2);
	free(T);
	return 1;
}

