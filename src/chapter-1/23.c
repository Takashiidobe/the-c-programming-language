#include <stdio.h>

typedef enum state {
  IN_COMMENT,
  PRINT,
} state;

int chapter_1_23(void) {
  int c;
  int n;
  state s = PRINT;

  while ((c = getchar()) != EOF) {
    if (s == PRINT) {
      if (c == '/') {
        n = getchar();
        if (n == '*') {
          s = IN_COMMENT;
        } else {
          if (n != EOF) {
            ungetc(n, stdin);
          }
          putchar('/');
        }
      } else {
        putchar((char)c);
      }
    } else {
      if (c == '*') {
        n = getchar();
        if (n == '/') {
          s = PRINT;
        } else {
          if (n != EOF) {
            ungetc(n, stdin);
          }
        }
      }
    }
  }
  return 0;
}
