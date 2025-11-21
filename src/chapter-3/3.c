#include "chapter-3.h"
#include <ctype.h>

static int same_group(char a, char b) {
  return (islower(a) && islower(b)) || (isupper(a) && isupper(b)) ||
         (isdigit(a) && isdigit(b));
}

void expand(const char *s1, char *s2) {
  size_t out = 0;
  char prev = '\0';

  for (size_t i = 0; s1[i] != '\0'; ++i) {
    char curr = s1[i];

    if (curr == '-' && prev != '\0' && s1[i + 1] != '\0') {
      char end = s1[i + 1];
      if (prev < end && same_group(prev, end)) {
        for (char c = prev + 1; c <= end; ++c) {
          s2[out++] = c;
        }
        prev = end;
        ++i;
        continue;
      }
    }

    s2[out++] = curr;
    prev = curr;
  }

  s2[out] = '\0';
}
