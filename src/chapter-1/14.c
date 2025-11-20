#include <ctype.h>
#include <stdio.h>

int chapter_1_14(void) {
  int c;
  static int occur[128];
  while ((c = getchar()) != EOF) {
    if (isalnum(c)) {
      occur[(unsigned char)c]++;
    }
  }

  for (int i = 0; i < 128; i++) {
    if (occur[i]) {
      printf("%c: ", i);
      printf("%d\n", occur[i]);
    }
  }
  return 0;
}
