#include <assert.h>
#include <math.h>
#include <string.h>

#include "../includes/chapter-1.h"

int main(void) {
  assert(fabs(fahr_celsius(32.0) - 0.0) < 0.0001);
  assert(fabs(fahr_celsius(212.0) - 100.0) < 0.0001);

  char data[] = "chapter";
  reverse(data);
  assert(strcmp(data, "retpahc") == 0);

  char a = 'x';
  char b = 'z';
  swap(&a, &b);
  assert(a == 'z' && b == 'x');

  return 0;
}
