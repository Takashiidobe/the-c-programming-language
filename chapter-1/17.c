#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  // print input one word at a time if it is over 80 chars long
  char buf[1024] = {};
  size_t index = 0;
  char c;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      buf[index] = '\0';
      if (index > 79) {
        puts(buf);
      }
      index = 0;
      memset(buf, 0, sizeof(buf));
    } else {
      buf[index++] = c;
    }
  }
}
