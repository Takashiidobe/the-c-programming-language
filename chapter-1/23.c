#include <stdio.h>
#include <string.h>

typedef enum state {
  IN_COMMENT,
  PRINT,
} state;

int main() {
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
          ungetc(n, stdout);
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
          ungetc(n, stdout);
        }
      }
    }
  }
}
