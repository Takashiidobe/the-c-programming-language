#include "../test_utils.h"
#include "chapter-3.h"

int main(void) {
  char buffer[128];

  expand("a-d", buffer);
  ASSERT_STR_EQ("abcd", buffer);

  expand("A-C0-3", buffer);
  ASSERT_STR_EQ("ABC0123", buffer);

  expand("-a-c", buffer);
  ASSERT_STR_EQ("-abc", buffer);

  expand("a-b-c", buffer);
  ASSERT_STR_EQ("abc", buffer);

  expand("z-a", buffer);
  ASSERT_STR_EQ("z-a", buffer);

  expand("xyz-", buffer);
  ASSERT_STR_EQ("xyz-", buffer);

  return 0;
}
