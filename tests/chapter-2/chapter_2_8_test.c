#include <limits.h>

#include "../test_utils.h"
#include "chapter-2.h"

static unsigned int rotate_naive(unsigned int value, unsigned int n) {
  const unsigned int width =
      (unsigned int)(sizeof(unsigned int) * CHAR_BIT);
  if (width == 0) {
    return value;
  }

  n %= width;
  while (n-- > 0) {
    unsigned int lsb = value & 1u;
    value >>= 1;
    if (lsb) {
      value |= 1u << (width - 1);
    }
  }
  return value;
}

static unsigned int alternating_bits(void) {
  const unsigned int width =
      (unsigned int)(sizeof(unsigned int) * CHAR_BIT);
  unsigned int value = 0;

  for (unsigned int i = 0; i < width; ++i) {
    if ((i % 2) == 0) {
      value |= 1u << i;
    }
  }

  return value;
}

int main(void) {
  const unsigned int width =
      (unsigned int)(sizeof(unsigned int) * CHAR_BIT);
  const unsigned int msb = 1u << (width - 1);

  ASSERT_INT_EQ(msb, rightrot(1u, 1u));
  ASSERT_INT_EQ(1u, rightrot(1u, width));

  unsigned int pattern = alternating_bits();
  ASSERT_INT_EQ(rotate_naive(pattern, 1u), rightrot(pattern, 1u));
  ASSERT_INT_EQ(rotate_naive(pattern, width + 3u),
                rightrot(pattern, width + 3u));
  ASSERT_INT_EQ(rotate_naive(0u, 5u), rightrot(0u, 5u));

  return 0;
}
