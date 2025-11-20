#include <assert.h>
#include <string.h>

#include "../includes/chapter-3.h"

int main(void) {
  char escaped[32];
  char unescaped[32];
  char original[] = "line1\nline2\t\\";
  escape(original, escaped);
  assert(strcmp(escaped, "line1\\nline2\\t\\\\") == 0);

  unescape(escaped, unescaped);
  assert(strcmp(unescaped, original) == 0);

  return 0;
}
