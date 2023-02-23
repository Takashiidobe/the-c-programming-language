#include <stdio.h>

int main() {
  static const int MAX_STRING_LENGTH = 100;
  int i = 0;
  int lim = MAX_STRING_LENGTH;
  char c;
  char s[MAX_STRING_LENGTH];

  while (i < (lim - 1)) {
    c = getchar();

    if (c == EOF) {
      break;
    } else if (c == '\n') {
      break;
    }

    s[i++] = c;
  }

  s[i] = '\0';
  puts(s);
}
