#ifndef CHAPTER_3_H
#define CHAPTER_3_H

#include <stddef.h>

int binsearch(int x, int v[], int n);
char esc_char(char c);
char unesc_char(char c);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);
void expand(const char *s1, char *s2);
char *itoa(char *dst, long value);
char *itob(char *dst, long value, int base);
char *itoa_min_width(char *dst, long value, size_t min_width);

int chapter_3_2(void);

#endif
