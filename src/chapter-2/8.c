#include "chapter-2.h"
#include <limits.h>

unsigned int rightrot(unsigned int x, unsigned int n) {
  const unsigned int width = (unsigned int)(sizeof(unsigned int) * CHAR_BIT);
  if (width == 0) {
    return x;
  }

  unsigned int shift = n % width;
  if (shift == 0) {
    return x;
  }

  return (x >> shift) | (x << (width - shift));
}
