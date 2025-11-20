#ifndef CHAPTER_2_H
#define CHAPTER_2_H

#include <stddef.h>

unsigned long long htoi(char *hexstr);
int is_hex_lowercase(char n);
int is_hex_uppercase(char n);
int is_hex_number(char n);
char *squeeze(char *s1, char *s2, size_t s1_len, size_t s2_len);
int any(char *s1, char *s2, size_t s1_len, size_t s2_len);
unsigned long long bitcount(unsigned long long value);
void lower(char *str, size_t len);

int chapter_2_1(void);
int chapter_2_2(void);
int chapter_2_3(void);
int chapter_2_4(void);
int chapter_2_5(void);
int chapter_2_9(void);
int chapter_2_10(void);

#endif
