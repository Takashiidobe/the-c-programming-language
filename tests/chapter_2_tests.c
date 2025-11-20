#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/chapter-2.h"

int main(void) {
  assert(htoi("0x2A") == 42);
  assert(htoi("ff") == 255);
  assert(htoi("0") == 0);

  char text[] = "TeStDaTa";
  lower(text, strlen(text));
  assert(strcmp(text, "testdata") == 0);

  char *squeezed = squeeze("kandr", "aeiou", strlen("kandr"), 5);
  assert(strcmp(squeezed, "kndr") == 0);
  free(squeezed);

  assert(any("hello", "world", strlen("hello"), strlen("world")) == 2);
  assert(any("abc", "xyz", 3, 3) == -1);

  assert(bitcount(0ULL) == 0ULL);
  assert(bitcount(0xF0ULL) == 4ULL);

  return 0;
}
