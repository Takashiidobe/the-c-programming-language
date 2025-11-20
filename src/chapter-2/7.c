#include "chapter-2.h"
#include <limits.h>

static unsigned int bit_width(void) {
  return (unsigned int)(sizeof(unsigned int) * CHAR_BIT);
}

static unsigned int block_mask(int n, unsigned int width) {
  if (n <= 0) {
    return 0u;
  }
  if (n >= (int)width) {
    return ~0u;
  }
  return (1u << n) - 1u;
}

int invert(int x, int p, int n) {
  unsigned int width = bit_width();
  if (n <= 0 || p < 0 || width == 0) {
    return x;
  }

  if (p >= (int)width) {
    p = (int)width - 1;
  }
  if (n > (int)width) {
    n = (int)width;
  }
  if (n > p + 1) {
    n = p + 1;
  }

  unsigned int shift = (unsigned int)(p + 1 - n);
  unsigned int mask = block_mask(n, width) << shift;

  return (int)((unsigned int)x ^ mask);
}
