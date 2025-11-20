#include <ctype.h>
#include <stdio.h>
#include <string.h>

int chapter_1_12(void) {
  // print input one word at a time
  char buf[1024] = {};
  size_t index = 0;
  while (1) {
    char c = getchar();
    if (isspace(c)) {
      buf[index] = '\0';
      puts(buf);
      index = 0;
      memset(buf, 0, sizeof(buf));
    } else {
      buf[index++] = c;
    }
  }
  return 0;
}
