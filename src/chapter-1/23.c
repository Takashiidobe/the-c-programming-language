#include <stdio.h>

typedef enum state {
  IN_COMMENT,
  PRINT,
} state;

int chapter_1_23(void) {
  char c;
  char n;
  state s = PRINT;

  while ((c = getchar()) != EOF) {
    if (s == PRINT) {
      if (c == '/') {
        n = getchar();
        if (n == '*') {
          s = IN_COMMENT;
        } else {
          ungetc(n, stdin);
        }
      } else {
        putchar(c);
      }
    } else {
      if (c == '*') {
        n = getchar();
        if (n == '/') {
          s = PRINT;
        } else {
          ungetc(n, stdin);
        }
      }
    }
  }
  return 0;
}
