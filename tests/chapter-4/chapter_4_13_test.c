#include "../test_utils.h"
#include "chapter-4.h"

int main(void) {
  char even[] = "abcdef";
  recursive_reverse(even);
  ASSERT_STR_EQ("fedcba", even);

  char odd[] = "racecar";
  recursive_reverse(odd);
  ASSERT_STR_EQ("racecar", odd);

  char single[] = "x";
  recursive_reverse(single);
  ASSERT_STR_EQ("x", single);

  char empty[] = "";
  recursive_reverse(empty);
  ASSERT_STR_EQ("", empty);

  char with_spaces[] = "hello world!";
  recursive_reverse(with_spaces);
  ASSERT_STR_EQ("!dlrow olleh", with_spaces);

  return 0;
}
