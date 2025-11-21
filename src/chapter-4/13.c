#include "chapter-4.h"
#include <stddef.h>
#include <string.h>

static void recursive_reverse_range(char *s, size_t left, size_t right) {
  if (left >= right) {
    return;
  }
  char tmp = s[left];
  s[left] = s[right];
  s[right] = tmp;
  recursive_reverse_range(s, left + 1, right - 1);
}

void recursive_reverse(char *s) {
  if (!s) {
    return;
  }
  size_t len = strlen(s);
  if (len <= 1) {
    return;
  }
  recursive_reverse_range(s, 0, len - 1);
}
