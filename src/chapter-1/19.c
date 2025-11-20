#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void reverse(char *s) {
  int length = strlen(s);
  for (int i = 0, j = length - 1; i < j; i++, j--) {
    swap(&s[i], &s[j]);
  }
}

int chapter_1_19(void) {
  const size_t buf_size = 1024;
  char curr_str[buf_size];
  size_t index = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      curr_str[index] = '\0';
      reverse(curr_str);
      puts(curr_str);
      memset(curr_str, 0, 1024);
      index = 0;
    } else {
      if (index < buf_size - 1) {
        curr_str[index++] = (char)c;
      }
    }
  }
  if (index > 0) {
    curr_str[index] = '\0';
    reverse(curr_str);
    puts(curr_str);
  }
  return 0;
}
