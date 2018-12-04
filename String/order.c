/*
串的顺序存储结构
*/


#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 20 /*存储空间初始化分配量*/


/* 辅助函数start */
int strlen(char *str) {
	// 计算str长度
	int i;
	for (i = 0; *(str+i) != '\0'; i++) {
		;
	}
	return i;
}


void memcpy(char *data, char*str, length) {
	// 将str的前length字符加在data后面
	int i;
	for (i = 0; i < length; i++) {
		*(data+i) = *(str+i);
	}
}


void get_next(String *T, int *next) {
	int i,j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			if (T[i] != T[j]) {
				next[i] = j;
			} else {
				next[i] = next[j];
			}
		} else {
			j = next[j]
		}
	}
}
/* 辅助函数end */


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
	if (T->length > 0) {
		return 0;
	}
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


/* 串S存在，用Sub返回串S的第pos个字符起长度为length的子串 */
int SubString(String *Sub, String *S, int pos, length) {
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
	for (i = 0; i < len; i++) {
		Sub->*(data+i) = S->*(data+pos+i);
	}
	Sub->length = length;
	return 1;
}


/* 若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回-1 */
/* 使用KMP模式匹配算法 */
int Index(String *S, String *T, int pos) {
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T, next);
	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if (j > T[0]) {
		return i-T[0];
	} else {
		return -1;
	}
}


/* 用V替换主串S中出现的所有与T相等的不重叠的子串 */
int Replace(String *S, String *T, String *V) {
	int a[];
	int i = 0;
	int j = 0;
	while (i = Index(S, T, i) >= 0) {
		a[j] = i;
		i = i + T->length;
		j++;
	}
	if (j == 0) {
		return 0;
	}

	int length;
	if (V->length - T->length > 0) {
		// 用长串替换短串，需判断内存是否足够
		length = (V->length - T->length) * j;
		if (S->size < S->length + length) {
	        int newsize = S->length + length;
	        char *newdata = realloc(S->data, newsize);
	        S->size = newsize;
	        S->data = newdata;
	    }
	    for (i = 0; i < j; i++) {

	    }
	} else {

	}
	return 1;
}


/* 在串S的第pos个字符之前插入串T */
int StrInsert(S, pos, T) {

}


/* 从串S中删除第pos个字符起长度为length的子串 */
int StrDelete(String *S, int pos, int length) {
	if (S->length - pos < length) {
		return 0;
	}
	int i;
	for (i = pos + length - 1; i > pos - 1; i--) {
		free(S->(data+i));
	}
	S->length = S->length - length;
	if (S->size > length && S->size > MAXSIZE) {
        int newsize = MAXSIZE;
        char *newdata = realloc(S->data, newsize);
        S->size = newsize;
        S->data = newdata;
    }
	return 1;
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

