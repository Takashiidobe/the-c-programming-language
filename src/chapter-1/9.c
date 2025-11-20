#include <stdio.h>
#include <string.h>

int chapter_1_9(void) {
  // print input one word at a time
  char buf[1024] = {};
  size_t index = 0;
  int prev_space = 0;
  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (prev_space) {
        continue;
      } else {
        buf[index++] = (char)c;
        prev_space = 1;
      }
    } else if (c == '\n') {
      buf[index] = '\0';
      puts(buf);
      index = 0;
      memset(buf, 0, sizeof(buf));
      prev_space = 0;
    } else {
      buf[index++] = (char)c;
      prev_space = 0;
    }
  }
  if (index > 0) {
    buf[index] = '\0';
    puts(buf);
  }
  return 0;
}
