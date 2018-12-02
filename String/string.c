#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INIT_SIZE 32

typedef struct string {
    int length;
    int size;
    char *data;
} string;

string *string_new()
{
    string *s;

    s = malloc(sizeof(string));
    if (s == NULL) {
        return NULL;
    }

    s->length = 0;
    s->size = INIT_SIZE;
    s->data = malloc(INIT_SIZE);
    if (s->data == NULL) {
        free(s);
        return NULL;
    }

    return s;
}

int string_append(string *s, char *str)
{
    int remain = s->size - s->length;
    int length = strlen(str);

    if (remain < length) {
        int newsize = s->size + (length - remain);
        char *newbuf = realloc(s->data, newsize);
        if (newbuf == NULL) {
            return 0;
        }

        s->size = newsize;
        s->data = newbuf;
    }

    memcpy(s->data + s->length, str, length);
    s->length += length;

    return 1;
}
