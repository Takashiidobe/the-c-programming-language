#include "../test_utils.h"
#include "chapter-4.h"

int main(void) {
  ASSERT_INT_EQ(7, strrindex("hello world", "o"));
  ASSERT_INT_EQ(2, strrindex("aaaa", "aa"));
  ASSERT_INT_EQ(-1, strrindex("abcdef", "gh"));
  ASSERT_INT_EQ(0, strrindex("pattern", "pattern"));
  ASSERT_INT_EQ(-1, strrindex("", "a"));
  ASSERT_INT_EQ(-1, strrindex("abc", ""));
  return 0;
}
