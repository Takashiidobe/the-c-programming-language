#include <ctype.h>
#include <stdio.h>
#include <string.h>

int chapter_1_12(void) {
  // print input one word at a time
  char buf[1024] = {};
  size_t index = 0;
  int c;
  while ((c = getchar()) != EOF) {
    if (isspace(c)) {
      if (index > 0) {
        buf[index] = '\0';
        puts(buf);
        index = 0;
        memset(buf, 0, sizeof(buf));
      }
    } else {
      buf[index++] = (char)c;
    }
  }
  if (index > 0) {
    buf[index] = '\0';
    puts(buf);
  }
  return 0;
}
