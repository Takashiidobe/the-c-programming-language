#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum state {
  IN_COMMENT,
  PRINT,
} state;

void error(char c) {
  printf("Unbalanced: %c\n", c);
  exit(EXIT_FAILURE);
}

int main() {
  char c;
  char n;
  state s = PRINT;

  char stack[1024];
  int curr_index = 0;

  while ((c = getchar()) != EOF) {
    if (s == PRINT) {
      if (c == '(' || c == '[' || c == '{') {
        stack[curr_index++] = c;
      } else if (c == ')') {
        if (stack[curr_index - 1] != '(') {
          error('(');
        } else {
          curr_index--;
        }
      } else if (c == ']') {
        if (stack[curr_index - 1] != '[') {
          error(']');
        } else {
          curr_index--;
        }
      } else if (c == '}') {
        if (stack[curr_index - 1] != '{') {
          error('}');
        } else {
          curr_index--;
        }
      }
      if (c == '/') {
        n = getchar();
        if (n == '*') {
          s = IN_COMMENT;
        } else {
          ungetc(n, stdout);
        }
      }
    } else {
      if (c == '*') {
        n = getchar();
        if (n == '/') {
          s = PRINT;
        }
      }
    }
  }
  return curr_index == 0;
}
