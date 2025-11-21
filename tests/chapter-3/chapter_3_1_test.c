#include "../test_utils.h"
#include "chapter-3.h"

int main(void) {
  int values[] = {1, 3, 5, 7, 9};
  ASSERT_INT_EQ(0, binsearch(1, values, 5));
  ASSERT_INT_EQ(2, binsearch(5, values, 5));
  ASSERT_INT_EQ(4, binsearch(9, values, 5));
  ASSERT_INT_EQ(-1, binsearch(2, values, 5));
  ASSERT_INT_EQ(-1, binsearch(10, values, 5));

  int dupes[] = {2, 2, 2, 3, 4};
  ASSERT_INT_EQ(0, binsearch(2, dupes, 5));
  ASSERT_INT_EQ(3, binsearch(3, dupes, 5));

  int single[] = {42};
  ASSERT_INT_EQ(0, binsearch(42, single, 1));
  ASSERT_INT_EQ(-1, binsearch(41, single, 1));

  return 0;
}
