#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void reverse(char *str) {
  if (str) {
    char *end = &str[strlen(str) - 1];

    while (str < end) {
      swap(str, end);
      str++;
      end--;
    }
  }
}

int chapter_1_19(void) {
  const size_t buf_size = 1024;
  char c;
  char curr_str[buf_size];
  size_t index = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      reverse(curr_str);
      puts(curr_str);
      memset(curr_str, 0, 1024);
      index = 0;
    } else {
      curr_str[index++] = c;
    }
  }
  return 0;
}
