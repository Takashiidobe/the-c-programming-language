#include "chapter-3.h"
#include <string.h>

char *itoa_min_width(char *dst, long value, size_t min_width) {
  itob(dst, value, 10);
  size_t len = strlen(dst);

  if (len >= min_width) {
    return dst;
  }

  size_t pad = min_width - len;
  memmove(dst + pad, dst, len + 1);
  memset(dst, ' ', pad);
  return dst;
}
