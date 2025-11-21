#include "../test_utils.h"
#include "chapter-3.h"

int main(void) {
  char escaped[32];
  char unescaped[32];
  char original[] = "line1\nline2\t\\";

  escape(original, escaped);
  ASSERT_STR_EQ("line1\\nline2\\t\\\\", escaped);

  unescape(escaped, unescaped);
  ASSERT_STR_EQ(original, unescaped);

  return 0;
}
