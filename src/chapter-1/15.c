#include <stdio.h>

double fahr_celsius(double t) { return (5.0 / 9) * (t - 32); }

int chapter_1_15(void) {
  for (int i = 0; i <= 300; i += 20) {
    printf("%3d F = %6.1f C\n", i, fahr_celsius(i));
  }
  return 0;
}
