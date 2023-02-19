#include <stdio.h>
#include <string.h>

void lower(char* str, size_t len) {
  int diff = 'a' - 'A';
  for (int i = 0; i < len; i++) {
    char c = str[i];
    if (c >= 'A' && c <= 'Z') {
      str[i] = c + diff;
    }
  }
}

int main() {
  char buf[1024];
  char c;
  size_t i = 0;

  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      buf[i] = c;
      i++;
    } else {
      lower(buf, i);
      puts(buf);
      memset(buf, 0, i);
      i = 0;
    }
  }
}
