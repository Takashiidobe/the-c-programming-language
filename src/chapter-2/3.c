#include "chapter-2.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_hex_lowercase(char n) { return n >= 'a' && n <= 'f'; }

int is_hex_uppercase(char n) { return n >= 'A' && n <= 'F'; }

int is_hex_number(char n) { return n >= '0' && n <= '9'; }

unsigned long long htoi(char *hexstr) {
  int i = 0;
  unsigned long long num = 0;

  if (hexstr[0] == '0' && tolower(hexstr[1]) == 'x') {
    i += 2;
  }

  char c;
  while ((c = hexstr[i]) != '\0') {
    if (is_hex_lowercase(c)) {
      num = num * 16 + 10 + c - 'a';
    } else if (is_hex_uppercase(c)) {
      num = num * 16 + 10 + c - 'A';
    } else if (is_hex_number(c)) {
      num = num * 16 + c - '0';
    } else {
      return 0;
    }
    i++;
  }
  return num;
}

int chapter_2_3(void) {
  const size_t buf_size = 1024;
  char c;
  char curr_str[buf_size];
  size_t index = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      curr_str[index] = '\0';
      printf("%s as hexadecimal is: %llu\n", curr_str, htoi(curr_str));
      memset(curr_str, 0, 1024);
      index = 0;
    } else {
      curr_str[index++] = c;
    }
  }
  return 0;
}