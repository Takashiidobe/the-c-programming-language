#include <stdio.h>

int chapter_1_5(void) {
  int lower = 0, upper = 300, step = 30;
  float celsius = upper;

  printf("C     F\n\n");
  celsius = (float)upper;
  while (celsius >= lower) {
    printf("%f, %d\n", celsius, lower);
    float fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius -= step;
  }
  return 0;
}
