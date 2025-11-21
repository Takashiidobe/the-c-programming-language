#include "chapter-3.h"

static void reverse_range(char *start, char *end) {
  while (start < end) {
    char tmp = *start;
    *start++ = *end;
    *end-- = tmp;
  }
}

static unsigned long magnitude(long value) {
  if (value < 0) {
    return (unsigned long)(-(value + 1)) + 1u;
  }
  return (unsigned long)value;
}

static char digit_from(int value) {
  static const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
  return digits[value];
}

char *itob(char *dst, long value, int base) {
  if (base < 2 || base > 36) {
    dst[0] = '\0';
    return dst;
  }

  char *p = dst;
  unsigned long mag = magnitude(value);

  do {
    int digit = (int)(mag % (unsigned long)base);
    *p++ = digit_from(digit);
    mag /= (unsigned long)base;
  } while (mag > 0);

  if (value < 0) {
    *p++ = '-';
  }

  *p = '\0';
  reverse_range(dst, p - 1);
  return dst;
}
