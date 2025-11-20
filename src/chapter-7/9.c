#include "chapter-7.h"
#include <stdio.h>
#include <string.h>

int is_upper(char c) { return (c >= 'A' && c <= 'Z'); }

int is_string_upper(char *str, size_t len) {
  for (int i = 0; i < len; i++) {
    char c = str[i];
    if (!is_upper(c)) {
      return 0;
    }
  }
  return 1;
}

int chapter_7_9(void) {
  char buf[1024];
  char c;
  size_t i = 0;

  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      buf[i] = c;
      i++;
    } else {
      int res = is_string_upper(buf, i);
      if (res) {
        printf("%s is all uppercase\n", buf);
      } else {
        printf("%s is not all uppercase\n", buf);
      }
      memset(buf, 0, i);
      i = 0;
    }
  }
  return 0;
}