#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "get_word.h"

int get_word(char *buf, int buf_size, FILE *fp)
{
    int len, ch;

    // 空白文字の読み飛ばし
    while ((ch = getc(fp)) != EOF && !isalnum(ch))
        ;
    if (ch == EOF) return EOF;

    // ここで，chには，単語の最初の文字が格納されている
    len = 0;
    do {
        buf[len] = ch;
        len++;
        if (len >= buf_size)  {
            fprintf(stderr, "word too long\n");
            exit(1);
        }
    } while ((ch = getc(fp)) != EOF && isalnum(ch));
    buf[len] = '\0';

    return len;
}