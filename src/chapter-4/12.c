#include "chapter-4.h"
#include <limits.h>
#include <stddef.h>

static void recursive_itoa_digits(unsigned int value, char *dest,
                                  size_t *index) {
  if (value >= 10) {
    recursive_itoa_digits(value / 10, dest, index);
  }
  dest[(*index)++] = (char)('0' + (value % 10));
}

void recursive_itoa(int n, char *dest) {
  if (!dest) {
    return;
  }

  size_t index = 0;
  unsigned int magnitude;
  if (n < 0) {
    dest[index++] = '-';
    magnitude = (unsigned int)(-(long long)n);
  } else {
    magnitude = (unsigned int)n;
  }

  recursive_itoa_digits(magnitude, dest, &index);
  dest[index] = '\0';
}
