#include <assert.h>
#include <string.h>

#include "../includes/chapter-7.h"

int main(void) {
  assert(is_upper('A'));
  assert(!is_upper('a'));
  char upper[] = "UPPER";
  char mixed[] = "Mixed";
  assert(is_string_upper(upper, strlen(upper)));
  assert(!is_string_upper(mixed, strlen(mixed)));
  return 0;
}
