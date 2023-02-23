#include <stdio.h>

int main(void) {
  char c = getchar();

  printf("Press a key.\n");
  printf("The expression getchar() != EOF evaluates to %d\n", c != EOF);
}
