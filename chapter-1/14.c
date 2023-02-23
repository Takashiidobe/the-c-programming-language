#include <stdio.h>
#include <ctype.h>

int main() {
  char c;
  static int occur[128];
  while ((c = getchar()) != EOF) {
    if (isalnum(c)) {
      occur[c]++;
    }
  }

  for (int i = 0; i < 128; i++) {
    if (occur[i]) {
      printf("%c: ", i);
      printf("%d\n", occur[i]);
    }
  }
}
