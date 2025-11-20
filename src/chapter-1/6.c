#include <stdio.h>

int chapter_1_6(void) {
  char c = getchar();

  printf("Press a key.\n");
  printf("The expression getchar() != EOF evaluates to %d\n", c != EOF);
  return 0;
}
