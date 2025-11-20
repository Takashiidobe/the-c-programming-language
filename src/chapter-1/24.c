#include <stdio.h>
#include <stdlib.h>

typedef enum state {
  IN_COMMENT,
  PRINT,
} state;

void error(char c) {
  printf("Unbalanced: %c\n", c);
  exit(EXIT_FAILURE);
}

int chapter_1_24(void) {
  int c;
  int n;
  state s = PRINT;

  char stack[1024];
  int curr_index = 0;

  while ((c = getchar()) != EOF) {
    if (s == PRINT) {
      if (c == '(' || c == '[' || c == '{') {
        if (curr_index >= (int)(sizeof(stack))) {
          error((char)c);
        }
        stack[curr_index++] = (char)c;
      } else if (c == ')') {
        if (curr_index == 0 || stack[curr_index - 1] != '(') {
          error('(');
        } else {
          curr_index--;
        }
      } else if (c == ']') {
        if (curr_index == 0 || stack[curr_index - 1] != '[') {
          error(']');
        } else {
          curr_index--;
        }
      } else if (c == '}') {
        if (curr_index == 0 || stack[curr_index - 1] != '{') {
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
          if (n != EOF) {
            ungetc(n, stdin);
          }
        }
      }
    } else {
      if (c == '*') {
        n = getchar();
        if (n == '/') {
          s = PRINT;
        } else if (n != EOF) {
          ungetc(n, stdin);
        }
      }
    }
  }
  if (curr_index != 0) {
    error(stack[curr_index - 1]);
  }
  return 0;
}
