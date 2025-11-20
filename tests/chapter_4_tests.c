#include <assert.h>

#include "../includes/chapter-4.h"

int main(void) {
  assert(strrindex("hello world", "o") == 7);
  assert(strrindex("aaaa", "aa") == 2);
  assert(strrindex("abcdef", "gh") == -1);
  assert(strrindex("pattern", "pattern") == 0);
  return 0;
}
