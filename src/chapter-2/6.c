#include "chapter-2.h"
#include <limits.h>

static unsigned int bit_width(void) {
  return (unsigned int)(sizeof(unsigned int) * CHAR_BIT);
}

static unsigned int chunk_mask(int n, unsigned int width) {
  if (n <= 0) {
    return 0u;
  }
  if (n >= (int)width) {
    return ~0u;
  }
  return (1u << n) - 1u;
}

int setbits(int x, int p, int n, int y) {
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
  unsigned int block_mask = chunk_mask(n, width);
  unsigned int mask = block_mask << shift;
  unsigned int cleared = (unsigned int)x & ~mask;
  unsigned int y_bits = ((unsigned int)y & block_mask) << shift;

  return (int)(cleared | y_bits);
}
