#include "chapter-2.h"
#include <stdio.h>
#include <string.h>

void lower(char *str, size_t len) {
  int diff = 'a' - 'A';
  for (int i = 0; i < len; i++) {
    char c = str[i];
    str[i] = c >= 'A' && c <= 'Z' ? c + diff : c;
  }
}

int chapter_2_10(void) {
  char buf[1024];
  size_t i = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      if (i < sizeof(buf) - 1) {
        buf[i++] = (char)c;
      }
    } else {
      buf[i] = '\0';
      lower(buf, i);
      puts(buf);
      memset(buf, 0, i);
      i = 0;
    }
  }
  if (i > 0) {
    buf[i] = '\0';
    lower(buf, i);
    puts(buf);
  }
  return 0;
}
