#include <stdio.h>
#include <string.h>

int main() {
  // print input one word at a time
  char buf[1024] = {};
  size_t index = 0;
  int prev_space = 0;
  while (1) {
    char c = getchar();
    if (c == ' ') {
      if (prev_space) {
        continue;
      } else {
        buf[index++] = c;
        prev_space = 1;
      }
    } else if (c == '\n') {
      buf[index] = '\0';
      puts(buf);
      index = 0;
      memset(buf, 0, sizeof(buf));
      prev_space = 0;
    } else {
      buf[index++] = c;
      prev_space = 0;
    }
  }
}
